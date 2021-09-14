/**
 ******************************************************************************
 * @file    fp_vision_display.h
 * @author  MCD Application Team
 * @brief   Library to manage LCD display through DMA2D
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
#ifndef __FP_VISION_DISPLAY_H
#define __FP_VISION_DISPLAY_H

#ifdef __cplusplus
extern "C"
{
#endif
  
#include "fp_vision_global.h"
#include "stm32h747i_discovery_lcd.h"
#include "stm32_lcd.h"
  
  
/* Exported types ------------------------------------------------------------*/
typedef struct
{
  uint8_t *lcd_frame_read_buff;
  uint8_t *lcd_frame_write_buff;
  volatile uint32_t lcd_sync;
  void*             AppCtxPtr;
} DisplayContext_TypeDef;  
  
/* Exported constants --------------------------------------------------------*/
extern DisplayContext_TypeDef Display_Context; 

/**************************/
/***LCD related defines****/
/**************************/
#define LCD_BRIGHTNESS_MIN 0
#define LCD_BRIGHTNESS_MAX 100
#define LCD_BRIGHTNESS_MID 50
#define LCD_BRIGHTNESS_STEP 10

#define ARGB8888_BYTE_PER_PIXEL 4
#define LCD_RES_WIDTH 800
#define LCD_RES_HEIGHT 480
#define LCD_BBP ARGB8888_BYTE_PER_PIXEL
#define LCD_FRAME_BUFFER_SIZE (LCD_RES_WIDTH * LCD_RES_HEIGHT * LCD_BBP)
  
/* Protoypes */
void DISPLAY_Init(DisplayContext_TypeDef*);
int DISPLAY_WelcomeScreen(DisplayContext_TypeDef* );
void DISPLAY_FoodLogo(DisplayContext_TypeDef* , const uint32_t , const uint32_t , const size_t );
void DISPLAY_DrawBBox(float x_center, float y_center, float width, float height);
void DISPLAY_Refresh(DisplayContext_TypeDef* );
void DISPLAY_Copy2LCDWriteBuffer(DisplayContext_TypeDef* , uint32_t *, uint16_t , uint16_t , uint16_t , uint16_t ,
                                 uint32_t , int );
void DISPLAY_CameraCaptureBuffer(DisplayContext_TypeDef* Display_Context_Ptr, uint16_t *cam_buffer);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __FP_VISION_DISPLAY_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
