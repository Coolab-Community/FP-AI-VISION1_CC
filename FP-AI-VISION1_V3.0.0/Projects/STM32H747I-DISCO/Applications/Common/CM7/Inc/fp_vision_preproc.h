/**
 ******************************************************************************
 * @file    fp_vision_preproc.h
 * @author  MCD Application Team
 * @brief   Header for fp_vision_preproc.c module
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FP_VISION_PREPROC_H
#define __FP_VISION_PREPROC_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "fp_vision_global.h"
#include "img_preprocess.h"
  
/* Exported types ------------------------------------------------------------*/
typedef struct
{
uint16_t x;
uint16_t y;
uint32_t rowStride;
}Dma2dCfg_TypeDef;

typedef struct
{
 Dma2dCfg_TypeDef Dma2dcfg;
 uint32_t red_blue_swap;
 Roi_TypeDef   Roi;
 Image_TypeDef Pfc_Src_Img;
 Image_TypeDef Pfc_Dst_Img;
 Image_TypeDef Resize_Src_Img;
 Image_TypeDef Resize_Dst_Img;
 void*    AppCtxPtr;
}PreprocContext_TypeDef;
  

/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
extern PreprocContext_TypeDef Preproc_Context;

/*******************/
/****PFC defines****/
/*******************/
/*The Pixel Format Conversion method, PIXEL_FMT_CONV, is configured in the preprocessor project's option:
* 1: HW_PFC : PFC performed by mean of HW engine like DMA2D
* 2: SW_PFC : PFC is performed by mean of SW routine and LUT
*/
#define HW_PFC 1
#define SW_PFC 2
  
/******************************/
/***Resizing related defines***/
/******************************/
/*Resizing algorithm*/
#define RESIZING_NEAREST_NEIGHBOR 1

/* Exported functions ------------------------------------------------------- */
void PREPROC_ImageResize(PreprocContext_TypeDef*);
void PREPROC_PixelFormatConversion(PreprocContext_TypeDef*);
void PREPROC_Pixel_RB_Swap(void *, void *, uint32_t );
void PREPROC_Init(PreprocContext_TypeDef * );
   
#ifdef __cplusplus
}
#endif

#endif /*__FP_VISION_PREPROC_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
