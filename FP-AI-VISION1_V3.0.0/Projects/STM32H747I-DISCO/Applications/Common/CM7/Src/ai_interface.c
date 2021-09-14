/**
 ******************************************************************************
 * @file    ai_interface.c
 * @author  MCD Application Team
 * @brief   Abstraction interface to AI generated code
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
#include "ai_interface.h"
#include <string.h>
#include "ai_datatypes_defines.h"

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static ai_handle network_handle;
static ai_network_report desc_report;
static ai_buffer ai_input[1];/*= AI_NETWORK_IN;*/
static ai_buffer ai_output[1];/*= AI_NETWORK_OUT;*/

/* Global variables ----------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Functions Definition ------------------------------------------------------*/

/**
 * @brief Returns value of the height for the first input tensor
 * @retval ai_u16 Height for the first input tensor
 */
ai_u16 ai_get_input_height(void) { return (AI_BUFFER_HEIGHT(&ai_input[0])); }

/**
 * @brief Returns value of the width for the first input tensor
 * @retval ai_u16 Width for the first input tensor
 */
ai_u16 ai_get_input_width(void) { return (AI_BUFFER_WIDTH(&ai_input[0])); }

/**
 * @brief Returns value of the channels for the first input tensor
 * @retval ai_u16 Channels for the first input tensor
 */
ai_u16 ai_get_input_channels(void) { return (AI_BUFFER_CHANNELS(&ai_input[0])); }

/**
 * @brief Returns value of the height for the first output tensor
 * @retval ai_u16 Height for the first output tensor
 */
ai_u16 ai_get_output_height(void) { return (AI_BUFFER_HEIGHT(&ai_output[0])); }

/**
 * @brief Returns value of the width for the first output tensor
 * @retval ai_u16 Width for the first output tensor
 */
ai_u16 ai_get_output_width(void) { return (AI_BUFFER_WIDTH(&ai_output[0])); }

/**
 * @brief Returns value of the channels for the first output tensor
 * @retval ai_u16 Channels for the first output tensor
 */
ai_u16 ai_get_output_channels(void) { return (AI_BUFFER_CHANNELS(&ai_output[0])); }

/**
 * @brief Returns the input format type
 * @retval ai_size Input format type: quantized (AI_BUFFER_FMT_TYPE_Q) or float (AI_BUFFER_FMT_TYPE_FLOAT)
 */
ai_size ai_get_input_format(void)
{
  ai_buffer_format fmt = AI_BUFFER_FORMAT(&ai_input[0]);
  return AI_BUFFER_FMT_GET_TYPE(fmt);
}

/**
 * @brief Returns the output format type
 * @retval ai_size Output format type: quantized (AI_BUFFER_FMT_TYPE_Q) or float (AI_BUFFER_FMT_TYPE_FLOAT)
 */
ai_size ai_get_output_format(void)
{
  ai_buffer_format fmt = AI_BUFFER_FORMAT(&ai_output[0]);
  return AI_BUFFER_FMT_GET_TYPE(fmt);
}

/**
 * @brief Returns value of the input quantized format
 * @retval ai_size Input quantized format
 */
ai_size ai_get_input_quantized_format(void)
{
  ai_buffer_format fmt = AI_BUFFER_FORMAT(&ai_input[0]);
  return (AI_BUFFER_FMT_GET_BITS(fmt) - AI_BUFFER_FMT_GET_SIGN(fmt) - AI_BUFFER_FMT_GET_FBITS(fmt));
}

/**
 * @brief Returns the quantization scheme used to quantize the input layer of the neural network
 * @retval ai_size Quantization scheme: AI_FXP_Q, AI_UINT_Q, AI_SINT_Q
 */
uint32_t ai_get_input_quantization_scheme(void)
{
  ai_float scale=ai_get_input_scale();
  
  ai_buffer_format fmt=AI_BUFFER_FORMAT(&ai_input[0]);
  ai_size sign = AI_BUFFER_FMT_GET_SIGN(fmt);  
  
  if(scale==0)
  {
    return AI_FXP_Q;
  }
  else
  {
    if(sign==0)
    {
      return AI_UINT_Q;
    }
    else
    {
      return AI_SINT_Q;
    }
  }
}

/**
 * @brief Returns the quantization scheme used to quantize the output layer of the neural network
 * @retval ai_size Quantization scheme: AI_FXP_Q, AI_UINT_Q, AI_SINT_Q
 */
uint32_t ai_get_output_quantization_scheme(void)
{
  ai_float scale=ai_get_output_scale();
  
  ai_buffer_format fmt=AI_BUFFER_FORMAT(&ai_output[0]);
  ai_size sign = AI_BUFFER_FMT_GET_SIGN(fmt);  
  
  if(scale==0)
  {
    return AI_FXP_Q;
  }
  else
  {
    if(sign==0)
    {
      return AI_UINT_Q;
    }
    else
    {
      return AI_SINT_Q;
    }
  }
}

/**
 * @brief Returns value of the scale for the output quantized format
 * @retval ai_size Scale for output quantized format
 */
ai_float ai_get_output_fxp_scale(void)
{
  float scale;
  ai_buffer_format fmt_1;
  
  /* Retrieve format of the output tensor - index 0 */
  fmt_1 = AI_BUFFER_FORMAT(&ai_output[0]);
  
  /* Build the scale factor for conversion */
  scale = 1.0f / (0x1U << AI_BUFFER_FMT_GET_FBITS(fmt_1));
  
  return scale;
}

/**
 * @brief Returns value of the scale for the input quantized format
 * @retval ai_size Scale for input quantized format
 */
ai_float ai_get_input_scale(void)
{
  return AI_BUFFER_META_INFO_INTQ_GET_SCALE(ai_input[0].meta_info, 0);
}

/**
 * @brief Returns value of the zero point for the input quantized format
 * @retval ai_size Zero point for input quantized format
 */
ai_i32 ai_get_input_zero_point(void)
{
  return AI_BUFFER_META_INFO_INTQ_GET_ZEROPOINT(ai_input[0].meta_info, 0);
}

/**
 * @brief Returns value of the scale for the output quantized format
 * @retval ai_size Scale for output quantized format
 */
ai_float ai_get_output_scale(void)
{
  return AI_BUFFER_META_INFO_INTQ_GET_SCALE(ai_output[0].meta_info, 0);
}

/**
 * @brief Returns value of the zero point for the output quantized format
 * @retval ai_size Zero point for output quantized format
 */
ai_i32 ai_get_output_zero_point(void)
{
  return AI_BUFFER_META_INFO_INTQ_GET_ZEROPOINT(ai_output[0].meta_info, 0);
}


/**
 * @brief Initializes the generated C model for a neural network
 * @param  activation_buffer Pointer to the activation buffer (i.e. working buffer used during NN inference)
 * @retval ai_handle
 */
ai_handle ai_init(void* activation_buffer)
{
  network_handle = AI_HANDLE_NULL;

  /* Creating the network */
  ai_network_create(&network_handle, AI_NETWORK_DATA_CONFIG);

  /* Initialize param structure for the activation and weight buffers */
  const ai_network_params params = {AI_NETWORK_DATA_WEIGHTS(ai_network_data_weights_get()),
                                    AI_NETWORK_DATA_ACTIVATIONS((void*)(activation_buffer))};

  /* Initializing the network */
  ai_network_init(network_handle, &params);
  
  /*Retrieve network descriptor*/
  ai_network_get_info(network_handle, &desc_report);
  
  /*Copy descriptor info*/
  ai_input[0]= desc_report.inputs[0];
  ai_output[0]= desc_report.outputs[0];
  
  return desc_report.inputs->data;
}

/**
 * @brief De-initializes the generated C model for a neural network
 */
void ai_deinit(void) { ai_network_destroy(network_handle); }

/**
 * @brief  Run an inference of the generated C model for a neural network
 * @param  input   Pointer to the buffer containing the inference input data
 * @param  output  Pointer to the buffer for the inference output data
 */
void ai_run(void* input, void* output)
{
  ai_i32 nbatch;
  
  ai_input[0].data = AI_HANDLE_PTR(input);
  ai_output[0].data = AI_HANDLE_PTR(output);
  
  nbatch = ai_network_run(network_handle, &ai_input[0], &ai_output[0]);
  
  if (nbatch != 1) {
        while(1);
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
