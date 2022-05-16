/**
 ******************************************************************************
 * @file    fp_vision_utils.c
 * @author  MCD Application Team
 * @brief   FP VISION utilities
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under Ultimate Liberty license
 * SLA0044, the "License"; You may not use this file except in compliance with
 * the License. You may obtain a copy of the License at:
 *                             www.st.com/SLA0044
 *
 ******************************************************************************
 */

/* Includes ------------------------------------------------------------------*/
#include "fp_vision_utils.h"

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
extern DMA2D_HandleTypeDef hlcd_dma2d;
UtilsContext_TypeDef UtilsContext;

/* Private function prototypes -----------------------------------------------*/
static uint32_t GetBytesPerPixel(uint32_t );
static void Utils_Context_Init(UtilsContext_TypeDef *);

/* Functions Definition ------------------------------------------------------*/
/**
 * @brief Helper function to get the bytes per pixels according to the DMA2D color mode
 *
 * @param dma2d_color DMA2D color mode
 * @return uint32_t bytes per pixels for the input mode, either 4,3,2 or 0 if unknown input mode
 */
static uint32_t GetBytesPerPixel(uint32_t dma2d_color)
{
  switch (dma2d_color)
  {
    case DMA2D_OUTPUT_ARGB8888:
      return 4;
    case DMA2D_OUTPUT_RGB888:
      return 3;
    case DMA2D_OUTPUT_RGB565:
    case DMA2D_OUTPUT_ARGB1555:
    case DMA2D_OUTPUT_ARGB4444:
      return 2;
    default:
      return 0;
  }
}

/**
 * @brief Initializes the utilities context structure
 * @param Utils_Context_Ptr Pointer to Utilities context
 */
static void Utils_Context_Init(UtilsContext_TypeDef *Utils_Context_Ptr)
{
  Utils_Context_Ptr->JoystickContext.joyState=JOY_NONE;
  Utils_Context_Ptr->JoystickContext.camContrast=0;/* Mid-level camera contrast. */
  Utils_Context_Ptr->JoystickContext.camBrightness=0;/* Mid-level camera brightness. */
  Utils_Context_Ptr->JoystickContext.lcdBrightness=LCD_BRIGHTNESS_MID;
  
  Utils_Context_Ptr->ExecTimingContext.tcapturestart1= 0;
  Utils_Context_Ptr->ExecTimingContext.tcapturestart2= 0;
  Utils_Context_Ptr->ExecTimingContext.tcapturestart= 0;
  Utils_Context_Ptr->ExecTimingContext.tcapturestop=0; 
}

/**
* @brief  UTILS Initialization
* @param  Utils_Context_Ptr  Pointer to Utilities context
* @retval None
*/
void UTILS_Init(UtilsContext_TypeDef *Utils_Context_Ptr)
{
  Utils_Context_Init(Utils_Context_Ptr);
  
  /*LEDs Init*/
  BSP_LED_Init(LED_GREEN);
  BSP_LED_Init(LED_ORANGE);
  BSP_LED_Init(LED_RED);
  BSP_LED_Init(LED_BLUE);
  
  /* Activate joystick. */
  BSP_JOY_Init(JOY1, JOY_MODE_GPIO,JOY_ALL);
  
  /* Configure the Wakeup push-button in GPIO Mode */
  BSP_PB_Init(BUTTON_WAKEUP, BUTTON_MODE_GPIO);
}

/**
* @brief  Get timestamp
* @param  Utils_Context_Ptr  Pointer to Utilities context
* @retval Time stamp
*/
uint32_t UTILS_GetTimeStamp(UtilsContext_TypeDef *Utils_Context_Ptr)
{
  return HAL_GetTick();
}

/**
 * @brief Performs a DMA transfer from an arbitrary address to an arbitrary address
 *
 * @param pSrc address of the source
 * @param pDst address of the destination
 * @param x x position in the destination
 * @param y y position in the destination
 * @param xsize width of the source
 * @param ysize height of the source
 * @param rowStride width of the destination
 * @param input_color_format input color format (e.g DMA2D_INPUT_RGB888)
 * @param output_color_format output color format (e.g DMA2D_OUTPUT_ARGB888)
 * @param pfc boolean flag for pixel format conversion (set to 1 if input and output format are different, else 0)
 * @param red_blue_swap boolean flag for red-blue channel swap, 0 if no swap, else 1
*/
void UTILS_Dma2d_Memcpy(uint32_t *pSrc, uint32_t *pDst, uint16_t x, uint16_t y, uint16_t xsize, uint16_t ysize,
                        uint32_t rowStride, uint32_t input_color_format, uint32_t output_color_format, int pfc,
                        int red_blue_swap)
{
  uint32_t bytepp = GetBytesPerPixel(output_color_format);

  uint32_t destination = (uint32_t)pDst + (y * rowStride + x) * bytepp;
  uint32_t source = (uint32_t)pSrc;

  HAL_DMA2D_DeInit(&hlcd_dma2d);

  /*##-1- Configure the DMA2D Mode, Color Mode and output offset #############*/
  hlcd_dma2d.Init.Mode = pfc ? DMA2D_M2M_PFC : DMA2D_M2M;
  hlcd_dma2d.Init.ColorMode = output_color_format;

  /* Output offset in pixels == nb of pixels to be added at end of line to come to the  */
  /* first pixel of the next line : on the output side of the DMA2D computation         */
  hlcd_dma2d.Init.OutputOffset = rowStride - xsize;

  /*##-2- DMA2D Callbacks Configuration ######################################*/
  hlcd_dma2d.XferCpltCallback = NULL;

  /*##-3- Foreground Configuration ###########################################*/
  hlcd_dma2d.LayerCfg[1].AlphaMode = DMA2D_REPLACE_ALPHA;
  hlcd_dma2d.LayerCfg[1].InputAlpha = 0xFF;
  hlcd_dma2d.LayerCfg[1].InputColorMode = input_color_format;
  hlcd_dma2d.LayerCfg[1].InputOffset = 0;
  hlcd_dma2d.LayerCfg[1].RedBlueSwap = red_blue_swap ? DMA2D_RB_SWAP : DMA2D_RB_REGULAR;

  /* DMA2D Initialization */
  if (HAL_DMA2D_Init(&hlcd_dma2d) == HAL_OK)
  {
    if (HAL_DMA2D_ConfigLayer(&hlcd_dma2d, 1) == HAL_OK)
    {
      if (HAL_DMA2D_Start(&hlcd_dma2d, source, destination, xsize, ysize) == HAL_OK)
      {
        /* Polling For DMA transfer */
        HAL_DMA2D_PollForTransfer(&hlcd_dma2d, 30);
      }
    }
  }
}

/**
 * @brief  Get the joystick's status
 * @param  Utils_Context_Ptr pointer to utilities context
 * @retval None
 */
void UTILS_Joystick_Check(UtilsContext_TypeDef *Utils_Context_Ptr)
{
  JoystickContext_TypeDef* Joystick_Ctx_Ptr=&Utils_Context_Ptr->JoystickContext;
  
  /* Get the joystick state. */
  Joystick_Ctx_Ptr->joyState = (JOYPin_TypeDef) BSP_JOY_GetState(JOY1, 0);

  switch (Joystick_Ctx_Ptr->joyState)
  {
    case JOY_UP:
      if (Joystick_Ctx_Ptr->lcdBrightness < LCD_BRIGHTNESS_MAX)
      {
        Joystick_Ctx_Ptr->lcdBrightness += LCD_BRIGHTNESS_STEP;
      }
      else
      {
        Joystick_Ctx_Ptr->joyState = JOY_NONE; /* Cancel LCD brightness change. */
      }
      break;

    case JOY_DOWN:
      if (Joystick_Ctx_Ptr->lcdBrightness > LCD_BRIGHTNESS_MIN)
      {
        Joystick_Ctx_Ptr->lcdBrightness -= LCD_BRIGHTNESS_STEP;
      }
      else
      {
        Joystick_Ctx_Ptr->joyState = JOY_NONE; /* Cancel LCD brightness change. */
      }
      break;

    case JOY_LEFT:
      if (Joystick_Ctx_Ptr->camContrast > CAMERA_CONTRAST_MIN)
      {
        Joystick_Ctx_Ptr->camContrast--;
      }
      else
      {
        Joystick_Ctx_Ptr->joyState = JOY_NONE; /* Cancel camera contrast change. */
      }
      break;

    case JOY_RIGHT:
      if (Joystick_Ctx_Ptr->camContrast < CAMERA_CONTRAST_MAX)
      {
        Joystick_Ctx_Ptr->camContrast++;
      }
      else
      {
        Joystick_Ctx_Ptr->joyState = JOY_NONE; /* Cancel camera contrast change. */
      }
      break;

    default:
      break;
  }

  if ((Joystick_Ctx_Ptr->joyState == JOY_UP) || (Joystick_Ctx_Ptr->joyState == JOY_DOWN) || (Joystick_Ctx_Ptr->joyState == JOY_LEFT) || (Joystick_Ctx_Ptr->joyState == JOY_RIGHT))
  {
    /* Execute the change. */
    BSP_CAMERA_SetBrightness(0, Joystick_Ctx_Ptr->camBrightness);
    BSP_CAMERA_SetContrast(0, Joystick_Ctx_Ptr->camContrast);
    BSP_LCD_SetBrightness(0, Joystick_Ctx_Ptr->lcdBrightness);
  }
  else if (Joystick_Ctx_Ptr->joyState == JOY_SEL)
  {
    Joystick_Ctx_Ptr->camContrast = 0;     /* Mid-level camera contrast. */
    Joystick_Ctx_Ptr->camBrightness = 0; /* Mid-level camera brightness. */
    Joystick_Ctx_Ptr->lcdBrightness = LCD_BRIGHTNESS_MID;       /* Mid-level LCD brightness. */
    
    /* Restore the default values. */
    BSP_CAMERA_SetBrightness(0, Joystick_Ctx_Ptr->camBrightness);
    BSP_CAMERA_SetContrast(0, Joystick_Ctx_Ptr->camContrast);
    BSP_LCD_SetBrightness(0, Joystick_Ctx_Ptr->lcdBrightness);
  }
}

/**
 * @brief Performs Data Cache maintenance for coherency purpose
 * @param mem_addr Pointer to memory block address (aligned to 32-byte boundary)
 * @param mem_size Size of memory block (in number of bytes)
 * @param Maintenance_operation type of maintenance: CLEAN or INVALIDATE
 * @retval None
 */
void UTILS_DCache_Coherency_Maintenance(uint32_t *mem_addr, int32_t mem_size, DCache_Coherency_TypeDef Maintenance_operation)
{
  /*Check alignement on 32-bytes for the memory adress and check that the memory size is multiple of 32-bytes*/
  if(((uint32_t)mem_addr%32 != 0) || (mem_size%32 != 0))
    while(1);
  
  if(Maintenance_operation == INVALIDATE)
  {
    SCB_InvalidateDCache_by_Addr((void*)mem_addr, mem_size);
  }
  else if(Maintenance_operation == CLEAN)
  {
    SCB_CleanDCache_by_Addr((void *)mem_addr, mem_size);
  }
}

/**
 * @brief Bubble sorting algorithm on probabilities
 * @param prob pointer to probabilities buffer
 * @param classes pointer to classes buffer
 * @param size numer of values
 */
void UTILS_Bubblesort(float *prob, int *classes, int size)
{
  float p;
  int c;

  for (int i = 0; i < size; i++)
  {
    for (int ii = 0; ii < size - i - 1; ii++)
    {
      if (prob[ii] < prob[ii + 1])
      {
        p = prob[ii];
        prob[ii] = prob[ii + 1];
        prob[ii + 1] = p;
        c = classes[ii];
        classes[ii] = classes[ii + 1];
        classes[ii + 1] = c;
      }
    }
  }
}

/**
 * @brief Compute the execution timing  of the various operation
 * @param UtilsContext_Ptr pointer to utilities context
 */
void UTILS_Compute_ExecutionTiming(UtilsContext_TypeDef *UtilsContext_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=UtilsContext_Ptr->AppCtxPtr;
  
  UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_CAPTURE] = UtilsContext_Ptr->ExecTimingContext.tcapturestop - UtilsContext_Ptr->ExecTimingContext.tcapturestart;
  
#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT  
  UtilsContext_Ptr->ExecTimingContext.Tfps =UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_PFC] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_PVC] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_RESIZE] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_INFERENCE] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_CAPTURE];
#elif MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT 
  if((UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_PFC] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_INFERENCE]) > UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_CAPTURE])
    UtilsContext_Ptr->ExecTimingContext.Tfps = UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_PFC] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_PVC] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_RESIZE] + UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_INFERENCE];
  else
    UtilsContext_Ptr->ExecTimingContext.Tfps =  UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_CAPTURE];
#endif

  App_Cxt_Ptr->nn_inference_time=UtilsContext_Ptr->ExecTimingContext.operation_exec_time[FRAME_INFERENCE];
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
