/**
 ******************************************************************************
 * @file    fp_vision_ai.h
 * @author  MCD Application Team
 * @brief   Header for fp_vision_ai.c module
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
#ifndef __FP_VISION_AI_H
#define __FP_VISION_AI_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "fp_vision_global.h"
#include "ai_interface.h"
#include "img_preprocess.h"

#ifdef OBJECTDETECT
#include "objdetect_yololc_pp_if.h"
#endif

/* Private macros ------------------------------------------------------------*/
#define _MIN(x_, y_) \
  ( ((x_)<(y_)) ? (x_) : (y_) )

#define _MAX(x_, y_) \
    ( ((x_)>(y_)) ? (x_) : (y_) )

#define _CLAMP(x_, min_, max_, type_) \
      (type_) (_MIN(_MAX(x_, min_), max_))

#define _ROUND(v_, type_) \
        (type_) ( ((v_)<0) ? ((v_)-0.5f) : ((v_)+0.5f) )


/* Exported types ------------------------------------------------------------*/
typedef struct
{
  void* nn_output_buffer;
  void* nn_input_buffer;
  void* activation_buffer;
  uint8_t* lut;
  uint32_t nn_width;
  uint32_t nn_height;
  uint32_t nn_channels;
  float    nn_input_norm_scale;
  int32_t  nn_input_norm_zp;
  void*    AppCtxPtr;
#ifdef OBJECTDETECT
  yololc_pp_in_t  *pInput;
  yololc_pp_out_t output;
#endif
} AiContext_TypeDef;

#include "fp_vision_app.h"

/* Exported constants --------------------------------------------------------*/
extern AiContext_TypeDef Ai_Context;

/* Exported functions ------------------------------------------------------- */
void AI_Deinit(void);
void AI_Run(AiContext_TypeDef* );
void AI_Init(AiContext_TypeDef*);
void AI_PixelValueConversion_QuantizedNN(AiContext_TypeDef* , uint8_t *);
void AI_PixelValueConversion_FloatNN(AiContext_TypeDef* , uint8_t *, uint32_t );
void AI_Output_Dequantize(AiContext_TypeDef* );
void AI_Softmax(AiContext_TypeDef* Ai_Context_Ptr);
void AI_PixelValueConversion(AiContext_TypeDef* , void *);

#ifdef __cplusplus
}
#endif

#endif /*__FP_VISION_AI_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
