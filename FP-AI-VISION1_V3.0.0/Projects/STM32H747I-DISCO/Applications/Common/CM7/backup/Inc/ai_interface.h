/**
 ******************************************************************************
 * @file    ai_interface.h
 * @author  MCD Application Team
 * @brief   Header for ai_interface.c module
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
#ifndef __AI_IF_H
#define __AI_IF_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "network.h"
#include "network_data.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
/* Exported macros -----------------------------------------------------------*/
#define AI_NET_INPUT_SIZE AI_NETWORK_IN_1_SIZE
#define AI_NET_INPUT_SIZE_BYTES AI_NETWORK_IN_1_SIZE_BYTES

#define AI_NET_OUTPUT_SIZE AI_NETWORK_OUT_1_SIZE
#define AI_NET_OUTPUT_SIZE_BYTES AI_NETWORK_OUT_1_SIZE_BYTES

#define AI_ACTIVATION_SIZE_BYTES AI_NETWORK_DATA_ACTIVATIONS_SIZE
#define AI_WEIGHT_SIZE_BYTES      AI_NETWORK_DATA_WEIGHTS_SIZE

#define AI_NETWORK_IN_SHIFT   1
#define AI_NETWORK_OUT_SHIFT  7

#define AI_NETWORK_WIDTH   AI_NETWORK_IN_1_WIDTH
#define AI_NETWORK_HEIGHT  AI_NETWORK_IN_1_HEIGHT

/*********Quantization scheme******************/
#define AI_FXP_Q          (0x0) /*Fixed Point Qm,n*/
#define AI_UINT_Q         (0x1) /*Unsigned Integer Arithmetic*/
#define AI_SINT_Q         (0x2) /*Signed Integer Arithmetic*/

/* Exported functions ------------------------------------------------------- */
ai_u16 ai_get_input_height(void);
ai_u16 ai_get_input_width(void);
ai_u16 ai_get_input_channels(void);
ai_u16 ai_get_output_height(void);
ai_u16 ai_get_output_width(void);
ai_u16 ai_get_output_channels(void);
ai_size ai_get_input_quantized_format(void);
ai_float ai_get_output_fxp_scale(void);
ai_float ai_get_input_scale(void);
ai_i32  ai_get_input_zero_point(void);
ai_float ai_get_output_scale(void);
ai_i32 ai_get_output_zero_point(void);
uint32_t ai_get_input_quantization_scheme(void);
uint32_t ai_get_output_quantization_scheme(void);
ai_size ai_get_output_format(void);
ai_size ai_get_input_format(void);

ai_handle  ai_init(void*);
void ai_deinit(void);
void ai_run(void*, void*);

#ifdef __cplusplus
}
#endif

#endif /*__AI_IF_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
