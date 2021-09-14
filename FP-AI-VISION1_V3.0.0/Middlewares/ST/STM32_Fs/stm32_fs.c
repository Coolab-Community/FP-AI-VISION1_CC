/**
 ******************************************************************************
 * @file    stm32_fs.c
 * @author  MCD Application Team
 * @brief   File and image manipulation library built on top of FatFs
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * Portions of this file is part of the OpenMV project.
 *
 * Copyright (c) 2013-2019 Ibrahim Abdelkader <iabdalkader@openmv.io>
 * Copyright (c) 2013-2019 Kwabena W. Agyeman <kwagyeman@openmv.io>
 *
 * This software component is licensed under MIT License, the "License";
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *                        opensource.org/licenses/MIT
 *
 ******************************************************************************
 */

#include "stm32_fs.h"

/** @addtogroup Middlewares
  * @{
  */

/** @addtogroup STM32_Fs
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
#define IM_SWAP16(x)   __REV16(x)

#define IM_SET_GS_PIXEL(pixels, x, y, w, p)   do {                             \
  ((uint8_t *)pixels)[((y) * (w)) + (x)] = (p);                                \
} while(0)

#define IM_SET_RGB565_PIXEL(pixels, x, y, w, p)   do {                         \
  ((uint16_t *)pixels)[((y) * (w)) + (x)] = (p);                               \
} while(0)

#define IM_SET_RGB888_PIXEL(pixels, x, y, w, r, g, b)   do {                   \
  ((uint8_t *)(pixels))[(3 * (y) * (w)) + (3 * (x)) + 0] = (r);                \
  ((uint8_t *)(pixels))[(3 * (y) * (w)) + (3 * (x)) + 1] = (g);                \
  ((uint8_t *)(pixels))[(3 * (y) * (w)) + (3 * (x)) + 2] = (b);                \
} while(0)

#define IM_GET_RGB565_PIXEL(img, w, x, y)   ((uint16_t *)img)[(y * w) + x]

/*! Helper macro for wrapping FatFS f_read */
#define F_READ_SAFE(fp, buff, nbr_elem)   do {                                 \
  UINT bytes;                                                                  \
  f_read((fp), (buff), (UINT)(nbr_elem), &bytes);                              \
  if (nbr_elem != bytes) return STM32FS_ERROR_FREAD_FAIL;                      \
} while(0)

/* Private variables ---------------------------------------------------------*/
/* File system */
FATFS SDFatFS;  /* File system object for SD card logical drive */
FIL MyFile;     /* File object */
char SDPath[4]; /* SD card logical drive path */

/* Private function prototypes -----------------------------------------------*/
static void STM32Fs_GetDimsFromString(char *string, uint32_t *width, uint32_t *height);

static stm32fs_err_t GetImageInfoBMP(FIL *File, uint32_t* width, uint32_t* height, uint32_t* bpp, bmp_read_settings_t *rs);

static stm32fs_err_t ReadImageBMP(FIL *File, uint8_t *pixels, uint32_t width, uint32_t height,  bmp_read_settings_t *rs);

/**
 * @brief Initialize STM32Fs Library by linking FatFS Driver and mounting file system
 *
 * @warning The BSP_SD_Init() must be called before this function
 * @return stm32fs_err_t - Error message, can be one of NONE, LINK_DRIVER_FAIL, MOUNT_FS_FAIL
 */
stm32fs_err_t STM32Fs_Init(void)
{
  stm32fs_err_t ret = STM32FS_ERROR_NONE;
  if (FATFS_LinkDriver(&SD_Driver, SDPath) != 0)
  {
    ret = STM32FS_ERROR_LINK_DRIVER_FAIL;
  }

  if (f_mount(&SDFatFS, (TCHAR const *)SDPath, 0) != FR_OK)
  {
    return STM32FS_ERROR_MOUNT_FS_FAIL;
  }

  return ret;
}

/**
 * @brief Deinitialize STM32Fs library by unlinking driver
 *
 * @return stm32fs_err_t Error message, one of NONE or LINK_DRIVER_FAIL
 */
stm32fs_err_t STM32Fs_DeInit(void)
{
  f_mount(0, "", 0);
  stm32fs_err_t ret = STM32FS_ERROR_NONE;
  if (FATFS_UnLinkDriver(SDPath) != 0)
  {
    ret = STM32FS_ERROR_LINK_DRIVER_FAIL;
  }
  return ret;
}

/**
 * @brief Writes an RGB image to file system in PPM (P6) format
 *
 * @param path[in] null-terminated string correspondig to the path of the file to be written
 * @param buffer[in] buffer containing image data to be written in RGB888 format
 * @param width[in] width of the image
 * @param height[in] height of the image
 * @return stm32fs_err_t Error type, can be one of NONE, FOPEN_FAIL, FWRITE_FAIL
 */
stm32fs_err_t STM32Fs_WriteImagePPM(const char *path, uint8_t *buffer, const uint32_t width, const uint32_t height)
{
  FIL File;
  /* Mount */
  uint32_t byteswritten; /* File write/read counts */

  /* Fopen */
  if (f_open(&File, path, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  /* Header data */
  char header[32];
  sprintf(header, "P6\n%d %d\n255\n", (unsigned int)width, (unsigned int)height);

  /* Write header to a new file */
  FRESULT res = f_write(&File, (uint8_t *)header, strlen(header), (void *)&byteswritten);

  /* Append image data to the file */
  uint32_t buffer_size = width * height * 3;

  uint8_t *ptr = buffer;

  __disable_irq();
  res = f_write(&File, ptr, buffer_size, (void *)&byteswritten);
  __enable_irq();

  f_close(&File);

  if (res != 0)
  {
    return STM32FS_ERROR_FWRITE_FAIL;
  }

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Reads the images informations (widht and height) from a PPM image
 *
 * @param path[in] Absolute path to the image file
 * @param width[out] width of the image
 * @param height[out] height of the image
 *
 * @return Error type, one of FOPEN_FAIL, FILE_NOT_SUPPORTED or NONE
 */
stm32fs_err_t STM32Fs_GetImageInfoPPM(const char *path, uint32_t *width, uint32_t *height)
{
  static FIL File;

  /* Fopen */
  if (f_open(&File, path, FA_OPEN_EXISTING | FA_READ) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  char line_buffer[128];

  f_gets(line_buffer, 128, &File);
  if (line_buffer[0] != 'P' || line_buffer[1] != '6')
  {
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  /* ignore comments if any */
  do
  {
    f_gets(line_buffer, 128, &File);
  } while (line_buffer[0] == '#');

  STM32Fs_GetDimsFromString(line_buffer, width, height);

  f_close(&File);

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Reads an image from SDCard. The image should be in the PPM (P6) format
 *
 * @param path[in]          Path to the image to read
 * @param out_buffer[out]   Pointer to the image data to be written
 * @param width[out]        Width of the image
 * @param height[out]       Height of the image
 * @return stm32fs_err_t    Error message, one of NONE, FOPEN_FAIL, FILE_NOT_SUPPORTED
 */
stm32fs_err_t STM32Fs_ReadImagePPM(const char *path, uint8_t *out_buffer, uint32_t *width, uint32_t *height)
{
  FIL File;
  uint32_t bytesread; /* File read counts */

  /* Fopen */
  if (f_open(&File, path, FA_OPEN_EXISTING | FA_READ) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  char line_buffer[128];

  f_gets(line_buffer, 128, &File);
  if (line_buffer[0] != 'P' || line_buffer[1] != '6')
  {
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  /* ignore comments if any */
  do
  {
    f_gets(line_buffer, 128, &File);
  } while (line_buffer[0] == '#');

  STM32Fs_GetDimsFromString(line_buffer, width, height);

  /* Get dynamic (should be 255) */
  f_gets(line_buffer, 128, &File);

  if (line_buffer[0] != '2' || line_buffer[1] != '5' || line_buffer[2] != '5')
  {
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  uint32_t buffer_size = (*width) * (*height) * 3;

  if (f_read(&File, out_buffer, buffer_size, (unsigned int *)&bytesread) != FR_OK)
  {
    return STM32FS_ERROR_FREAD_FAIL;
  }
  if (bytesread < buffer_size)
  {
    return STM32FS_ERROR_FILE_READ_UNDERFLOW;
  }

  f_close(&File);

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Utility function when working with PPM P6 format.
 *        Gets dimensions of image from header data
 *
 * @param string[in] String data from the header
 * @param width[out] Width of the image
 * @param height[out] Height of the image
 */
static void STM32Fs_GetDimsFromString(char *string, uint32_t *width, uint32_t *height)
{
  char dim_str[2][8];              /* holds widht/height as string */
  uint32_t dim_int[2];             /* holds widht/height as unsigned integer */
  char separator[2] = {' ', '\n'}; /* string is in the form char-char-space-char-char-\n */

  char *src = string;
  for (uint32_t i = 0; i < 2; i++)
  { /* for width, height */

    /* Copy source string into dim_str[i] until separator */
    char *dst = dim_str[i];
    while (*src != separator[i])
    {
      *dst = *src;
      src++;
      dst++;
    }

    /* Go through each char to build the number */
    uint32_t base = 1;
    dim_int[i] = 0;
    while (dst-- != dim_str[i])
    {
      dim_int[i] += (*dst - '0') * base;
      base *= 10;
    }
    src++; /* Increment src pointer to skip the first separator */
  }

  *width = dim_int[0];
  *height = dim_int[1];
}

/**
 * @brief Get number of files in a directory
 *
 * @param path[in]              Path to the directory
 * @param nbr[out]              Number of files/directories in this directory
 * @param mode[in]              STM32FS_COUNT_DIRS and STM32FS_COUNT_FILES flags can be use
 *                              with bitwise OR to choose either to count files, directories or both
 * @return stm32fs_err_t        Error status, can be one of NONE or DIR_NOT_FOUND
 */
stm32fs_err_t STM32Fs_GetNumberFiles(char *path, uint32_t *nbr, uint8_t mode)
{
  FRESULT res;
  DIR dir;
  static FILINFO fno;

  uint32_t dir_counter = 0;
  uint32_t file_counter = 0;

  res = f_opendir(&dir, path); /* Open the directory */
  if (res == FR_OK)
  {
    for (;;)
    {
      res = f_readdir(&dir, &fno);                  /* Read a directory item */
      if (res != FR_OK || fno.fname[0] == 0) break; /* Break on error or end of dir */
      if (fno.fattrib & AM_DIR)
      { /* It is a directory */
        dir_counter++;
      }
      else
      { /* It is a file */
        file_counter++;
      }
    } /* End for */

    f_closedir(&dir);
  }
  else
  {
    return STM32FS_ERROR_DIR_NOT_FOUND;
  }

  *nbr = 0;
  if (mode & STM32FS_COUNT_DIRS)
  {
    *nbr += dir_counter;
  }
  if (mode & STM32FS_COUNT_FILES)
  {
    *nbr += file_counter;
  }
  return STM32FS_ERROR_NONE;
}

/**
 * @brief Open a directory
 *
 * @param path[in] path in the filesystem
 * @param dir[out] pointer to the open directory
 * @return stm32fs_err_t Error code, one of NONE or DIR_NOT_FOUND
 */
stm32fs_err_t STM32Fs_OpenDir(char *path, DIR *dir)
{
  FRESULT res;
  res = f_opendir(dir, path);
  if (res != FR_OK)
  {
    return STM32FS_ERROR_DIR_NOT_FOUND;
  }

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Create a directory
 *
 * @param path[in] path in the filesystem
 * @return stm32fs_err_t Error code
 */
stm32fs_err_t STM32Fs_CreateDir(char *path)
{
  FRESULT res;
  res = f_mkdir(path);
  if ((res != FR_OK) && (res != FR_EXIST))
  {
    while(1);
  }

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Iterates over the directories inside a directory in a filesystem.
 * returns DIR_NOT_FOUND when there are no more directories.
 *
 * @param dir[in] pointer to an opened directory. This directory will be searched for directories
 * @param fno[out] pointer to FILEINFO struct containing the information about the next directory inside dir
 * @return stm32fs_err_t Error code, DIR_NOT_FOUND when all directories have been listed or NONE
 */
stm32fs_err_t STM32Fs_GetNextDir(DIR *dir, FILINFO *fno)
{
  FRESULT res;

  res = f_readdir(dir, fno);                                                  /* Read a directory item */
  if (res != FR_OK || fno->fname[0] == 0) return STM32FS_ERROR_DIR_NOT_FOUND; /* Break on error or end of dir */
  if (fno->fattrib & AM_DIR)
  { /* It is a directory */
    return STM32FS_ERROR_NONE;
  }
  return STM32FS_ERROR_DIR_NOT_FOUND; /* Break on error or end of dir */
}

/**
 * @brief Iterates over the files inside a directory in a filesystem.
 * returns DIR_NOT_FOUND when there are no more files.
 *
 * @param dir[in] pointer to an opened directory. This directory will be searched for directories
 * @param fno[out] pointer to FILEINFO struct containing the information about the next file inside dir
 * @return stm32fs_err_t Error code, DIR_NOT_FOUND when all directories have been listed or NONE
 */
stm32fs_err_t STM32Fs_GetNextFile(DIR *dir, FILINFO *fno)
{
  FRESULT res;

  res = f_readdir(dir, fno);                                                  /* Read a directory item */
  if (res != FR_OK || fno->fname[0] == 0) return STM32FS_ERROR_DIR_NOT_FOUND; /* Break on error or end of dir */
  if (!(fno->fattrib & AM_DIR))
  { /* It is a file */
    return STM32FS_ERROR_NONE;
  }
  return STM32FS_ERROR_DIR_NOT_FOUND; /* Break on error or end of dir */
}

/**
 * @brief Writes a raw buffer in a file on the filesystem
 *
 * @param path[in] path where to write the file
 * @param buffer[in] pointer to the data
 * @param length[in] lenght of the data in bytes
 * @return stm32fs_err_t Error code, one of FOPEN_FAIL, FILE_WRITE_UNDERFLOW, NONE
 */
stm32fs_err_t STM32Fs_WriteRaw(const char *path, uint8_t *buffer, const size_t length)
{
  FIL File;
  int byteswritten;

  if (f_open(&File, path, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  __disable_irq();
  f_write(&File, buffer, length, (void *)&byteswritten);
  __enable_irq();

  f_close(&File);

  if (byteswritten != length)
  {
    return STM32FS_ERROR_FILE_WRITE_UNDERFLOW;
  }

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Write an image as Bitmap to filesystem
 *
 * @param path[in] path in the filesystem
 * @param buffer[in] pointer to the RGB888 image data
 * @param width[in] width of the image in pixels
 * @param height[in] height of the image in pixels
 * @return stm32fs_err_t error code
 */
stm32fs_err_t STM32Fs_WriteImageBMP(const char *path, uint8_t *buffer, const uint32_t width, const uint32_t height)
{
  FIL File;
  int byteswritten;

  if (f_open(&File, path, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  static unsigned char header[54] = {66, 77, 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0, 40,
                                     0,  0,  0, 0, 0, 0, 0, 0, 0, 0, 0,  1, 0, 24}; /* rest is zeroes */
  unsigned int pixelBytesPerRow = width * 3;
  unsigned int paddingBytesPerRow = (4 - (pixelBytesPerRow % 4)) % 4;
  unsigned int *sizeOfFileEntry = (unsigned int *)&header[2];
  *sizeOfFileEntry = 54 + (pixelBytesPerRow + paddingBytesPerRow) * height;
  unsigned int *widthEntry = (unsigned int *)&header[18];
  *widthEntry = width;
  unsigned int *heightEntry = (unsigned int *)&header[22];
  *heightEntry = -height; /* '-' required so to avoid having to rotate the image when opening .bmp file*/
  static unsigned char zeroes[3] = {0, 0, 0}; /* for padding */

  __disable_irq();
  f_write(&File, header, 54, (void *)&byteswritten);

  if (width % 4 == 0)
  {
    f_write(&File, buffer, width * height * 3, (void *)&byteswritten);
  }
  else
  { /* Padding is necessary when row is not a multiple of 4*/
    for (int row = 0; row < height; row++)
    {
      f_write(&File, buffer + 3 * width * row, pixelBytesPerRow, (void *)&byteswritten);
      f_write(&File, zeroes, paddingBytesPerRow, (void *)&byteswritten);
    }
  }
  __enable_irq();

  f_close(&File);

  return STM32FS_ERROR_NONE;
}

void write_byte(FIL *, uint8_t );
void write_byte(FIL *fp, uint8_t value)
{ 
  UINT bytes;
  FRESULT res = f_write(fp, &value, sizeof(value), &bytes);
  if (res != FR_OK) while(1);
  if (bytes != sizeof(value)) while(1);
}

void write_word(FIL *, uint16_t );
void write_word(FIL *fp, uint16_t value)
{
  UINT bytes;
  FRESULT res = f_write(fp, &value, sizeof(value), &bytes);
  if (res != FR_OK) while(1);
  if (bytes != sizeof(value)) while(1);
}

void write_long(FIL *, uint32_t );
void write_long(FIL *fp, uint32_t value)
{ 
  UINT bytes;
  FRESULT res = f_write(fp, &value, sizeof(value), &bytes);
  if (res != FR_OK) while(1);
  if (bytes != sizeof(value)) while(1);
}

void write_data(FIL *fp, const void *data, UINT size);
void write_data(FIL *fp, const void *data, UINT size)
{
  UINT bytes;
  FRESULT res = f_write(fp, data, size, &bytes);
  if (res != FR_OK) while(1);
  if (bytes != size) while(1);
}

/**
 * @brief Write an image as Bitmap to filesystem
 *
 * @param path[in] path in the filesystem
 * @param buffer[in] pointer to the RGB565 image data
 * @param width[in] width of the image in pixels
 * @param height[in] height of the image in pixels
 * @param swap_bytes[in] indicates if pixel's bytes from rgb565 source buffer must be swapped or not
 * @return stm32fs_err_t error code
 */
stm32fs_err_t STM32Fs_WriteImageBMP16(const char *path, uint8_t *buffer, const uint32_t width, const uint32_t height,  uint32_t swap_bytes)
{
  /* OpenMV (https://github.com/openmv/openmv/blob/master/src/omv/img/bmp.c) */
  FIL File;
  int byteswritten;
  
  if (f_open(&File, path, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }
  
  const int row_bytes = (((width * 16) + 31) / 32) * 4;
  const int data_size = (row_bytes * height);
  const int waste = (row_bytes / sizeof(uint16_t)) - width;
  // File Header (14 bytes)
  write_byte(&File, 'B');
  write_byte(&File, 'M');
  write_long(&File, 14 + 40 + 12 + data_size);
  write_word(&File, 0);
  write_word(&File, 0);
  write_long(&File, 14 + 40 + 12);
  // Info Header (40 bytes)
  write_long(&File, 40);
  write_long(&File, width);
  write_long(&File, -height); // store the image flipped (correctly)
  write_word(&File, 1);
  write_word(&File, 16);
  write_long(&File, 3);
  write_long(&File, data_size);
  write_long(&File, 0);
  write_long(&File, 0);
  write_long(&File, 0);
  write_long(&File, 0);
  // Bit Masks (12 bytes)
  write_long(&File, 0x1F << 11);
  write_long(&File, 0x3F << 5);
  write_long(&File, 0x1F);
  
  if(swap_bytes == 1)
  {
    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++) 
      {
        write_word(&File, IM_SWAP16(IM_GET_RGB565_PIXEL(buffer, width, (j), (i))));
      }
      for (int j = 0; j < waste; j++) 
      {
        write_word(&File, 0);
      }
    }
  }
  else  if(swap_bytes == 0)
  {
    if(waste == 0)
    {
      f_write(&File, buffer, width * height * 2, (void *)&byteswritten);
    }
    else
    {
      for (int i = 0; i < height; i++)
      {
        for (int j = 0; j < width; j++) 
        {
          write_word(&File, IM_GET_RGB565_PIXEL(buffer, width, (j), (i)));
        }
        for (int j = 0; j < waste; j++) 
        {
          write_word(&File, 0);
        }
      }
    }
  }
  
  f_close(&File);
  
  return STM32FS_ERROR_NONE;
}

/**
 * @brief Write an image as Bitmap to filesystem
 *
 * @param path[in] path in the filesystem
 * @param buffer[in] pointer to the 8-bit grayscale image data
 * @param width[in] width of the image in pixels
 * @param height[in] height of the image in pixels
 * @return stm32fs_err_t error code
 */
stm32fs_err_t STM32Fs_WriteImageBMPGray(const char *path, uint8_t *buffer, const uint32_t width, const uint32_t height)
{
  /* OpenMV (https://github.com/openmv/openmv/blob/master/src/omv/img/bmp.c) */
  FIL File;

  if (f_open(&File, path, FA_CREATE_ALWAYS | FA_WRITE) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  const int row_bytes = (((width * 8) + 31) / 32) * 4;
  const int data_size = (row_bytes * height);
  const int waste = (row_bytes / sizeof(uint8_t)) - width;
  // File Header (14 bytes)
  write_byte(&File, 'B');
  write_byte(&File, 'M');
  write_long(&File, 14 + 40 + 1024 + data_size);
  write_word(&File, 0);
  write_word(&File, 0);
  write_long(&File, 14 + 40 + 1024);
  // Info Header (40 bytes)
  write_long(&File, 40);
  write_long(&File, width);
  write_long(&File, -height); // store the image flipped (correctly)
  write_word(&File, 1);
  write_word(&File, 8);
  write_long(&File, 0);
  write_long(&File, data_size);
  write_long(&File, 0);
  write_long(&File, 0);
  write_long(&File, 0);
  write_long(&File, 0);
  // Color Table (1024 bytes)
  for (int i = 0; i < 256; i++) {
      write_long(&File, ((i) << 16) | ((i) << 8) | i);
  }

  if (width == row_bytes) { /* (width % 4) == 0 */
      write_data(&File, buffer, width * height);
  } else {
      for (int i = 0; i < height; i++) {
          write_data(&File, buffer + (i * width), width);
          for (int j = 0; j < waste; j++) {
              write_byte(&File, 0);
          }
      }
  }

  f_close(&File);

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Writes a text file to filesystem
 *
 * @param path[in] path in the filesystem
 * @param content[in] pointer to a null-terminated string
 * @param append_to_file[in] flag to choose bewteen erasing an existing file or appending to it. Either
 * STM32FS_CREATE_NEW_FILE or STM32FS_APPEND_TO_FILE
 * @return stm32fs_err_t
 */
stm32fs_err_t STM32Fs_WriteTextToFile(char *path, char *content, int append_to_file)
{
  FIL File;
  uint32_t byteswritten; /* File write/read counts */

  /* Open the file */
  BYTE flags = FA_WRITE;
  if (append_to_file == STM32FS_APPEND_TO_FILE)
  {
    flags |= FA_OPEN_APPEND;
  }
  else
  {
    flags |= FA_CREATE_ALWAYS;
  }

  if (f_open(&File, path, flags) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  FRESULT res = f_write(&File, (uint8_t *)content, strlen(content), (void *)&byteswritten);
  if (res != FR_OK)
  {
    return STM32FS_ERROR_FWRITE_FAIL;
  }

  if (byteswritten != strlen(content))
  {
    return STM32FS_ERROR_FILE_WRITE_UNDERFLOW;
  }

  f_close(&File);

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Reads image infos from a BMP file
 *
 * @param File[in] FIL pointer to the beginning of the file
 * @param width[in,out] pointer to the variable containing image width
 * @param height[in,out] pointer to the variable containing image height
 * @param bpp[in,out] pointer to the variable containing image number of bytes per pixel
 * @param rs[in,out] pointer to the bmp setting structure
 * @return stm32fs_err_t
 */
static stm32fs_err_t GetImageInfoBMP(FIL *File, uint32_t* width, uint32_t* height, uint32_t* bpp, bmp_read_settings_t *rs)
{
  char header[2];

  uint32_t ignore_32;
  uint16_t ignore_16;
  uint32_t tmp_32;
  uint16_t tmp_16;
  uint32_t expect;

  F_READ_SAFE(File, header, 2);
  if (header[0] != 'B' || header[1] != 'M')
  {
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  uint32_t file_size;
  F_READ_SAFE(File, &file_size, sizeof(file_size));

  F_READ_SAFE(File, &ignore_16, sizeof(ignore_16));
  F_READ_SAFE(File, &ignore_16, sizeof(ignore_16));

  uint32_t header_size;
  F_READ_SAFE(File, &header_size, sizeof(header_size));

  if (file_size <= header_size){
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  uint32_t data_size = file_size - header_size;
  if (data_size % 4) {
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  uint32_t header_type;
  F_READ_SAFE(File, &header_type, sizeof(header_type));

  if ((header_type != 40) // BITMAPINFOHEADER
      && (header_type != 52) // BITMAPV2INFOHEADER
      && (header_type != 56) // BITMAPV3INFOHEADER
      && (header_type != 108) // BITMAPV4HEADER
      && (header_type != 124)) {
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  F_READ_SAFE(File, &rs->bmp_w, sizeof(rs->bmp_w));
  F_READ_SAFE(File, &rs->bmp_h, sizeof(rs->bmp_w));

  if ((rs->bmp_w == 0) || (rs->bmp_h == 0)){
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  *width = abs(rs->bmp_w);
  *height = abs(rs->bmp_h);

  F_READ_SAFE(File, &tmp_16, sizeof(tmp_16));
  if (tmp_16 != 1){
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  F_READ_SAFE(File, &rs->bmp_bpp, sizeof(rs->bmp_bpp));

  if ((rs->bmp_bpp != 8) && (rs->bmp_bpp != 16) && (rs->bmp_bpp != 24)){
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  *bpp = (rs->bmp_bpp == 8)  ? 1 :
         (rs->bmp_bpp == 16) ? 2 :
                               3;

  F_READ_SAFE(File, &rs->bmp_fmt, sizeof(rs->bmp_fmt));

  if ((rs->bmp_fmt != 0) && (rs->bmp_fmt != 3)){
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));


  if (tmp_32 != data_size){
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
  F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
  F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
  F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));

  if (rs->bmp_bpp == 8) {
    if (rs->bmp_fmt != 0) return STM32FS_ERROR_FILE_NOT_SUPPORTED;
    if (header_type >= 52) { // Skip past the remaining BITMAPV2INFOHEADER bytes.
      for (int i = 0; i < 3; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 56) { // Skip past the remaining BITMAPV3INFOHEADER bytes.
      for (int i = 0; i < 1; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 108) { // Skip past the remaining BITMAPV4HEADER bytes.
      for (int i = 0; i < 13; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 124) { // Skip past the remaining BITMAPV5HEADER bytes.
      for (int i = 0; i < 4; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    // Color Table (1024 bytes)
    for (int i = 0; i < 256; i++) {

      expect = ((i) << 16) | ((i) << 8) | i;
      F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));

      if( tmp_32 != expect ) {
        return STM32FS_ERROR_FILE_NOT_SUPPORTED;
      }

    }
  } else if (rs->bmp_bpp == 16) {
    if (rs->bmp_fmt != 3) return STM32FS_ERROR_FILE_NOT_SUPPORTED;
    // Bit Masks (12 bytes)
    expect = 0x1F << 11;
    F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));
    if( tmp_32 != expect ) {
      return STM32FS_ERROR_FILE_NOT_SUPPORTED;
    }

    expect = 0x3F << 5;
    F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));
    if( tmp_32 != expect ) {
      return STM32FS_ERROR_FILE_NOT_SUPPORTED;
    }

    expect = 0x1F;
    F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));
    if( tmp_32 != expect ) {
      return STM32FS_ERROR_FILE_NOT_SUPPORTED;
    }

    if (header_type >= 56) { // Skip past the remaining BITMAPV3INFOHEADER bytes.
      for (int i = 0; i < 1; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 108) { // Skip past the remaining BITMAPV4HEADER bytes.
      for (int i = 0; i < 13; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 124) { // Skip past the remaining BITMAPV5HEADER bytes.
      for (int i = 0; i < 4; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
  } else if (rs->bmp_bpp == 24) {
    if (rs->bmp_fmt == 3) {
      // Bit Masks (12 bytes)
      expect = 0xFF << 16;
      F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));
      if( tmp_32 != expect ) {
        return STM32FS_ERROR_FILE_NOT_SUPPORTED;
      }

      expect = 0xFF << 8;
      F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));
      if( tmp_32 != expect ) {
        return STM32FS_ERROR_FILE_NOT_SUPPORTED;
      }

      expect = 0xFF;
      F_READ_SAFE(File, &tmp_32, sizeof(tmp_32));
      if( tmp_32 != expect ) {
        return STM32FS_ERROR_FILE_NOT_SUPPORTED;
      }


    } else if (header_type >= 52) { // Skip past the remaining BITMAPV2INFOHEADER bytes.
      for (int i = 0; i < 3; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 56) { // Skip past the remaining BITMAPV3INFOHEADER bytes.
      for (int i = 0; i < 1; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 108) { // Skip past the remaining BITMAPV4HEADER bytes.
      for (int i = 0; i < 13; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
    if (header_type >= 124) { // Skip past the remaining BITMAPV5HEADER bytes.
      for (int i = 0; i < 4; i++) F_READ_SAFE(File, &ignore_32, sizeof(ignore_32));
    }
  }

  rs->bmp_row_bytes = ((( (*width) * rs->bmp_bpp) + 31) / 32) * 4;

  if (data_size != (rs->bmp_row_bytes * (*height))) {
    return STM32FS_ERROR_FILE_NOT_SUPPORTED;
  }

  return STM32FS_ERROR_NONE;
}


/**
 * @brief Reads pixel data from a BMP file
 *
 * @param File[in] FIL pointer to the beginning of data section of the file
 * @warning Should be called on the same FIL pointer after calling STM32Fs_GetImageInfoBMP
 * @param width[in] image width
 * @param height[out] image height
 * @param rs[in,out] pointer to the bmp setting structure (read from STM32Fs_GetImageInfoBMP)
 * @return stm32fs_err_t
 */
static stm32fs_err_t ReadImageBMP(FIL *File, uint8_t *pixels, uint32_t width,
                                  uint32_t height, bmp_read_settings_t *rs)
{
  /* 8-bit grayscale */
  if (rs->bmp_bpp == 8) {
    if ((rs->bmp_h < 0) && (rs->bmp_w >= 0) && (width == rs->bmp_row_bytes)) {

      F_READ_SAFE(File, pixels, height * width);

    } else {
      for (int i = 0; i < height; i++) {
        for (int j = 0; j < rs->bmp_row_bytes; j++) {

          uint8_t pixel;
          F_READ_SAFE(File, &pixel, sizeof(pixel));

          if (j < width) {
            int x = (rs->bmp_w < 0) ? (width - j - 1) : j; // horizontal flip (BMP file perspective)
            int y = (rs->bmp_h < 0) ? i : (height - i - 1); // vertical flip (BMP file perspective)
            IM_SET_GS_PIXEL(pixels, x, y, width, pixel);
          }
        }
      }
    }
    /* 16-bit RGB565 */
  } else if (rs->bmp_bpp == 16) {

    /* If height is negative and there is no padding we can read the whole
     * buffer */
    if ((rs->bmp_h < 0) && (rs->bmp_w >= 0) &&
        ((width * 2) == rs->bmp_row_bytes)) {
      F_READ_SAFE(File, pixels, 2 * width * height);
    }

    else { /* For a positive height we read pixel per pixel */

      for (int i = 0; i < height; i++) {
        for (int j = 0, jj = rs->bmp_row_bytes / 2; j < jj; j++) {
          uint16_t pixel;

          F_READ_SAFE(File, &pixel, sizeof(pixel));

          /* pixel = IM_SWAP16(pixel); */

          if (j < width) {
            int x = (rs->bmp_w < 0) ? (width - j - 1) : j; // vertical flip
            int y = height - i - 1;
            IM_SET_RGB565_PIXEL(pixels, x, y, width, pixel);
          }
        }
      }

    } /* endif positive height */

  } else if (rs->bmp_bpp == 24) {
    for (int i = 0; i < height; i++) {
      for (int j = 0, jj = rs->bmp_row_bytes / 3; j < jj; j++) {

        uint8_t b, g, r;

        F_READ_SAFE(File, &b, sizeof(b));
        F_READ_SAFE(File, &g, sizeof(g));
        F_READ_SAFE(File, &r, sizeof(r));

        if (j < width) {
          int x = (rs->bmp_h < 0) ? (width - j - 1) : j; // vertical flip
          int y = (rs->bmp_w < 0) ? (height - i - 1) : i; // horizontal flip
          IM_SET_RGB888_PIXEL(pixels, x, y, width, r, g, b);
        }
      }
      for (int j = 0, jj = rs->bmp_row_bytes % 3; j < jj; j++) {
        uint8_t ignore;
        F_READ_SAFE(File, &ignore, sizeof(ignore));
      }
    }
  }

  return STM32FS_ERROR_NONE;
}

/**
 * @brief Reads image metadata (width, height, bpp) from a BMP file
 *
 * @param path[in] Path to the file in filesystem
 * @param width[out] image width
 * @param height[out] image height
 * @param bpp[out] bytes per pixel (1 if Mono8, 2 if RGB565, 3 if RGB888)
 * @return stm32fs_err_t
 */
stm32fs_err_t STM23Fs_GetImageInfoBMP(const char *path, uint32_t *width, uint32_t *height, uint32_t* bpp){

  static FIL File;
  stm32fs_err_t err;

  /* Open the file */
  if (f_open(&File, path, FA_OPEN_EXISTING | FA_READ) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  bmp_read_settings_t rs;

  err = GetImageInfoBMP(&File, width, height, bpp, &rs);

  f_close(&File);
  return err;
}


/**
 * @brief Reads pixel values from a BMP file
 *
 * @param path[in] Path to the file in filesystem
 * @param out_buffer[out] pixel buffer
 * @warning In order to know the size of out_buffer, it's recommended to call STM32Fs_GetImageInfoBMP beforehand
 * @return stm32fs_err_t
 */
stm32fs_err_t STM23Fs_ReadImageBMP(const char *path, uint8_t *out_buffer){

  static FIL File;
  stm32fs_err_t err;

  /* Open the file */
  if (f_open(&File, path, FA_OPEN_EXISTING | FA_READ) != FR_OK)
  {
    return STM32FS_ERROR_FOPEN_FAIL;
  }

  bmp_read_settings_t rs;

  uint32_t width, height, bpp;

  err = GetImageInfoBMP(&File, &width, &height, &bpp, &rs);

  if( err != STM32FS_ERROR_NONE ){
    f_close(&File);
    return err;
  }

  err = ReadImageBMP(&File, out_buffer , width, height, &rs);

  f_close(&File);

  return err;
}


/**
  * @}
  */

/**
  * @}
  */
