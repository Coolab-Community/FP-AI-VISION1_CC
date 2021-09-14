/**
 ******************************************************************************
 * @file    stm32_fs.h
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

#ifndef STM32_FS_H
#define STM32_FS_H

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdio.h>
#include <string.h>

#include "ff_gen_drv.h"
#include "sd_diskio.h"

/* Modes for counting files and directories */
#define STM32FS_COUNT_FILES (0x1)
#define STM32FS_COUNT_DIRS (0x2)

/* Modes for appending to file or not */
#define STM32FS_CREATE_NEW_FILE (0x0)
#define STM32FS_APPEND_TO_FILE (0x1)

/*! bmp header structure  */
typedef struct bmp_read_settings {
  int32_t bmp_w;
  int32_t bmp_h;
  uint16_t bmp_bpp;
  uint32_t bmp_fmt;
  uint32_t bmp_row_bytes;
} bmp_read_settings_t;

/*! Error types */
typedef enum stm32fs_error
{
  STM32FS_ERROR_NONE = 0,
  STM32FS_ERROR_LINK_DRIVER_FAIL,
  STM32FS_ERROR_MOUNT_FS_FAIL,
  STM32FS_ERROR_FOPEN_FAIL,
  STM32FS_ERROR_FWRITE_FAIL,
  STM32FS_ERROR_FILE_NOT_SUPPORTED,
  STM32FS_ERROR_FREAD_FAIL,
  STM32FS_ERROR_FILE_READ_UNDERFLOW,
  STM32FS_ERROR_FILE_WRITE_UNDERFLOW,
  STM32FS_ERROR_DIR_NOT_FOUND,
  STM32FS_ERR_TOOMANY_DIRS
} stm32fs_err_t;

/* Functions prototypes */
stm32fs_err_t STM32Fs_Init(void);
stm32fs_err_t STM32Fs_DeInit(void);
stm32fs_err_t STM32Fs_WriteImageBMP(const char *path, uint8_t *buffer, const uint32_t width, const uint32_t height);
stm32fs_err_t STM32Fs_WriteImageBMP16(const char *path, uint8_t *buffer, const uint32_t width, const uint32_t height,  uint32_t swap_bytes);
stm32fs_err_t STM32Fs_WriteImageBMPGray(const char *path, uint8_t *buffer, const uint32_t width, const uint32_t height);
stm32fs_err_t STM32Fs_WriteImagePPM(const char *, uint8_t *, const uint32_t, const uint32_t);
stm32fs_err_t STM32Fs_GetImageInfoPPM(const char *path, uint32_t *width, uint32_t *height);
stm32fs_err_t STM32Fs_ReadImagePPM(const char *, uint8_t *, uint32_t *, uint32_t *);
stm32fs_err_t STM32Fs_GetNumberFiles(char *, uint32_t *, uint8_t);
stm32fs_err_t STM32Fs_OpenDir(char *, DIR *);
stm32fs_err_t STM32Fs_CreateDir(char *);
stm32fs_err_t STM32Fs_GetNextDir(DIR *, FILINFO *);
stm32fs_err_t STM32Fs_GetNextFile(DIR *, FILINFO *);
stm32fs_err_t STM32Fs_WriteTextToFile(char *, char *, int);
stm32fs_err_t STM32Fs_WriteRaw(const char *path, uint8_t *buffer, const size_t length);
stm32fs_err_t STM23Fs_GetImageInfoBMP(const char *path, uint32_t *width, uint32_t *height, uint32_t* bpp);
stm32fs_err_t STM23Fs_ReadImageBMP(const char *path, uint8_t *out_buffer);


#ifdef __cplusplus
} /*  extern "C" */
#endif

#endif  /* STM32_FS_H */
