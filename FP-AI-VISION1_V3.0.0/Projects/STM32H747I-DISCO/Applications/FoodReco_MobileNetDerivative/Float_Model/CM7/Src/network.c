/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Apr 16 15:22:41 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "core_convert.h"

#include "layers.h"



/*
#define AI_TOOLS_VERSION_MAJOR 6
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0
#define AI_TOOLS_VERSION_EXTRA "RC6"

*/

/*
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 4
#define AI_TOOLS_API_VERSION_MICRO 0
*/

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_network
 
#undef AI_NETWORK_MODEL_SIGNATURE
#define AI_NETWORK_MODEL_SIGNATURE     "699704694b08d8ce0dea81c49f22f53a"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Fri Apr 16 15:22:41 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_2_output_array;   /* Array #0 */
AI_STATIC ai_array conv1_output_array;   /* Array #1 */
AI_STATIC ai_array conv_dw_1_output_array;   /* Array #2 */
AI_STATIC ai_array conv_pw_1_output_array;   /* Array #3 */
AI_STATIC ai_array conv_dw_2_output_array;   /* Array #4 */
AI_STATIC ai_array conv_pw_2_output_array;   /* Array #5 */
AI_STATIC ai_array conv_dw_3_output_array;   /* Array #6 */
AI_STATIC ai_array conv_pw_3_output_array;   /* Array #7 */
AI_STATIC ai_array conv_dw_4_output_array;   /* Array #8 */
AI_STATIC ai_array conv_pw_4_output_array;   /* Array #9 */
AI_STATIC ai_array conv_dw_5_output_array;   /* Array #10 */
AI_STATIC ai_array conv_pw_5_output_array;   /* Array #11 */
AI_STATIC ai_array conv_dw_6_output_array;   /* Array #12 */
AI_STATIC ai_array conv_pw_6_output_array;   /* Array #13 */
AI_STATIC ai_array conv_dw_7_output_array;   /* Array #14 */
AI_STATIC ai_array conv_pw_7_output_array;   /* Array #15 */
AI_STATIC ai_array conv_dw_8_output_array;   /* Array #16 */
AI_STATIC ai_array conv_pw_8_output_array;   /* Array #17 */
AI_STATIC ai_array conv_dw_9_output_array;   /* Array #18 */
AI_STATIC ai_array conv_pw_9_output_array;   /* Array #19 */
AI_STATIC ai_array conv_dw_10_output_array;   /* Array #20 */
AI_STATIC ai_array conv_pw_10_output_array;   /* Array #21 */
AI_STATIC ai_array conv_dw_11_output_array;   /* Array #22 */
AI_STATIC ai_array conv_pw_11_output_array;   /* Array #23 */
AI_STATIC ai_array conv_preds_output_array;   /* Array #24 */
AI_STATIC ai_array conv1_weights_array;   /* Array #25 */
AI_STATIC ai_array conv1_bias_array;   /* Array #26 */
AI_STATIC ai_array conv_dw_1_weights_array;   /* Array #27 */
AI_STATIC ai_array conv_dw_1_bias_array;   /* Array #28 */
AI_STATIC ai_array conv_pw_1_weights_array;   /* Array #29 */
AI_STATIC ai_array conv_pw_1_bias_array;   /* Array #30 */
AI_STATIC ai_array conv_dw_2_weights_array;   /* Array #31 */
AI_STATIC ai_array conv_dw_2_bias_array;   /* Array #32 */
AI_STATIC ai_array conv_pw_2_weights_array;   /* Array #33 */
AI_STATIC ai_array conv_pw_2_bias_array;   /* Array #34 */
AI_STATIC ai_array conv_dw_3_weights_array;   /* Array #35 */
AI_STATIC ai_array conv_dw_3_bias_array;   /* Array #36 */
AI_STATIC ai_array conv_pw_3_weights_array;   /* Array #37 */
AI_STATIC ai_array conv_pw_3_bias_array;   /* Array #38 */
AI_STATIC ai_array conv_dw_4_weights_array;   /* Array #39 */
AI_STATIC ai_array conv_dw_4_bias_array;   /* Array #40 */
AI_STATIC ai_array conv_pw_4_weights_array;   /* Array #41 */
AI_STATIC ai_array conv_pw_4_bias_array;   /* Array #42 */
AI_STATIC ai_array conv_dw_5_weights_array;   /* Array #43 */
AI_STATIC ai_array conv_dw_5_bias_array;   /* Array #44 */
AI_STATIC ai_array conv_pw_5_weights_array;   /* Array #45 */
AI_STATIC ai_array conv_pw_5_bias_array;   /* Array #46 */
AI_STATIC ai_array conv_dw_6_weights_array;   /* Array #47 */
AI_STATIC ai_array conv_dw_6_bias_array;   /* Array #48 */
AI_STATIC ai_array conv_pw_6_weights_array;   /* Array #49 */
AI_STATIC ai_array conv_pw_6_bias_array;   /* Array #50 */
AI_STATIC ai_array conv_dw_7_weights_array;   /* Array #51 */
AI_STATIC ai_array conv_dw_7_bias_array;   /* Array #52 */
AI_STATIC ai_array conv_pw_7_weights_array;   /* Array #53 */
AI_STATIC ai_array conv_pw_7_bias_array;   /* Array #54 */
AI_STATIC ai_array conv_dw_8_weights_array;   /* Array #55 */
AI_STATIC ai_array conv_dw_8_bias_array;   /* Array #56 */
AI_STATIC ai_array conv_pw_8_weights_array;   /* Array #57 */
AI_STATIC ai_array conv_pw_8_bias_array;   /* Array #58 */
AI_STATIC ai_array conv_dw_9_weights_array;   /* Array #59 */
AI_STATIC ai_array conv_dw_9_bias_array;   /* Array #60 */
AI_STATIC ai_array conv_pw_9_weights_array;   /* Array #61 */
AI_STATIC ai_array conv_pw_9_bias_array;   /* Array #62 */
AI_STATIC ai_array conv_dw_10_weights_array;   /* Array #63 */
AI_STATIC ai_array conv_dw_10_bias_array;   /* Array #64 */
AI_STATIC ai_array conv_pw_10_weights_array;   /* Array #65 */
AI_STATIC ai_array conv_pw_10_bias_array;   /* Array #66 */
AI_STATIC ai_array conv_dw_11_weights_array;   /* Array #67 */
AI_STATIC ai_array conv_dw_11_bias_array;   /* Array #68 */
AI_STATIC ai_array conv_pw_11_weights_array;   /* Array #69 */
AI_STATIC ai_array conv_pw_11_bias_array;   /* Array #70 */
AI_STATIC ai_array conv_preds_weights_array;   /* Array #71 */
AI_STATIC ai_array conv_preds_bias_array;   /* Array #72 */
AI_STATIC ai_array conv_pw_11_scratch0_array;   /* Array #73 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_2_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv1_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv_dw_1_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv_pw_1_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv_dw_2_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv_pw_2_output;   /* Tensor #5 */
AI_STATIC ai_tensor conv_dw_3_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv_pw_3_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv_dw_4_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv_pw_4_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv_dw_5_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv_pw_5_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv_dw_6_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv_pw_6_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv_dw_7_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv_pw_7_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv_dw_8_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv_pw_8_output;   /* Tensor #17 */
AI_STATIC ai_tensor conv_dw_9_output;   /* Tensor #18 */
AI_STATIC ai_tensor conv_pw_9_output;   /* Tensor #19 */
AI_STATIC ai_tensor conv_dw_10_output;   /* Tensor #20 */
AI_STATIC ai_tensor conv_pw_10_output;   /* Tensor #21 */
AI_STATIC ai_tensor conv_dw_11_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv_pw_11_output;   /* Tensor #23 */
AI_STATIC ai_tensor conv_preds_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv1_weights;   /* Tensor #25 */
AI_STATIC ai_tensor conv1_bias;   /* Tensor #26 */
AI_STATIC ai_tensor conv_dw_1_weights;   /* Tensor #27 */
AI_STATIC ai_tensor conv_dw_1_bias;   /* Tensor #28 */
AI_STATIC ai_tensor conv_pw_1_weights;   /* Tensor #29 */
AI_STATIC ai_tensor conv_pw_1_bias;   /* Tensor #30 */
AI_STATIC ai_tensor conv_dw_2_weights;   /* Tensor #31 */
AI_STATIC ai_tensor conv_dw_2_bias;   /* Tensor #32 */
AI_STATIC ai_tensor conv_pw_2_weights;   /* Tensor #33 */
AI_STATIC ai_tensor conv_pw_2_bias;   /* Tensor #34 */
AI_STATIC ai_tensor conv_dw_3_weights;   /* Tensor #35 */
AI_STATIC ai_tensor conv_dw_3_bias;   /* Tensor #36 */
AI_STATIC ai_tensor conv_pw_3_weights;   /* Tensor #37 */
AI_STATIC ai_tensor conv_pw_3_bias;   /* Tensor #38 */
AI_STATIC ai_tensor conv_dw_4_weights;   /* Tensor #39 */
AI_STATIC ai_tensor conv_dw_4_bias;   /* Tensor #40 */
AI_STATIC ai_tensor conv_pw_4_weights;   /* Tensor #41 */
AI_STATIC ai_tensor conv_pw_4_bias;   /* Tensor #42 */
AI_STATIC ai_tensor conv_dw_5_weights;   /* Tensor #43 */
AI_STATIC ai_tensor conv_dw_5_bias;   /* Tensor #44 */
AI_STATIC ai_tensor conv_pw_5_weights;   /* Tensor #45 */
AI_STATIC ai_tensor conv_pw_5_bias;   /* Tensor #46 */
AI_STATIC ai_tensor conv_dw_6_weights;   /* Tensor #47 */
AI_STATIC ai_tensor conv_dw_6_bias;   /* Tensor #48 */
AI_STATIC ai_tensor conv_pw_6_weights;   /* Tensor #49 */
AI_STATIC ai_tensor conv_pw_6_bias;   /* Tensor #50 */
AI_STATIC ai_tensor conv_dw_7_weights;   /* Tensor #51 */
AI_STATIC ai_tensor conv_dw_7_bias;   /* Tensor #52 */
AI_STATIC ai_tensor conv_pw_7_weights;   /* Tensor #53 */
AI_STATIC ai_tensor conv_pw_7_bias;   /* Tensor #54 */
AI_STATIC ai_tensor conv_dw_8_weights;   /* Tensor #55 */
AI_STATIC ai_tensor conv_dw_8_bias;   /* Tensor #56 */
AI_STATIC ai_tensor conv_pw_8_weights;   /* Tensor #57 */
AI_STATIC ai_tensor conv_pw_8_bias;   /* Tensor #58 */
AI_STATIC ai_tensor conv_dw_9_weights;   /* Tensor #59 */
AI_STATIC ai_tensor conv_dw_9_bias;   /* Tensor #60 */
AI_STATIC ai_tensor conv_pw_9_weights;   /* Tensor #61 */
AI_STATIC ai_tensor conv_pw_9_bias;   /* Tensor #62 */
AI_STATIC ai_tensor conv_dw_10_weights;   /* Tensor #63 */
AI_STATIC ai_tensor conv_dw_10_bias;   /* Tensor #64 */
AI_STATIC ai_tensor conv_pw_10_weights;   /* Tensor #65 */
AI_STATIC ai_tensor conv_pw_10_bias;   /* Tensor #66 */
AI_STATIC ai_tensor conv_dw_11_weights;   /* Tensor #67 */
AI_STATIC ai_tensor conv_dw_11_bias;   /* Tensor #68 */
AI_STATIC ai_tensor conv_pw_11_weights;   /* Tensor #69 */
AI_STATIC ai_tensor conv_pw_11_bias;   /* Tensor #70 */
AI_STATIC ai_tensor conv_preds_weights;   /* Tensor #71 */
AI_STATIC ai_tensor conv_preds_bias;   /* Tensor #72 */
AI_STATIC ai_tensor conv_pw_11_scratch0;   /* Tensor #73 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv1_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv_dw_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv_pw_1_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv_dw_2_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv_pw_2_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv_dw_3_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv_pw_3_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv_dw_4_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv_pw_4_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv_dw_5_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv_pw_5_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv_dw_6_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv_pw_6_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv_dw_7_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv_pw_7_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv_dw_8_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv_pw_8_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv_dw_9_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv_pw_9_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv_dw_10_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv_pw_10_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv_dw_11_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv_pw_11_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv_preds_chain;   /* Chain #23 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv1_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv_dw_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv_pw_1_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv_dw_2_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv_pw_2_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv_dw_3_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv_pw_3_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv_dw_4_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv_pw_4_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv_dw_5_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv_pw_5_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv_dw_6_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv_pw_6_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv_dw_7_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv_pw_7_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv_dw_8_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv_pw_8_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv_dw_9_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv_pw_9_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv_dw_10_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv_pw_10_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv_dw_11_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d_nl_pool conv_pw_11_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv_preds_layer; /* Layer #23 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_2_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 150528, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 100352, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 25088, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_1_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 50176, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12544, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_2_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 25088, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 25088, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_3_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 25088, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_4_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12544, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12544, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_5_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12544, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 3136, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_6_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_7_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_8_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_9_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_10_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6272, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_11_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv_preds_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 18, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 216, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 72, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_1_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_1_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 144, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_2_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 512, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_2_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 288, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_3_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1024, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_3_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 288, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_4_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2048, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_4_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_5_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4096, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_5_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 576, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 64, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_6_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 8192, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_6_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_7_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_7_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_8_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_8_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_9_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_9_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_10_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 16384, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_10_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 1152, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv_dw_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 128, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_11_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 32768, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_11_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 256, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv_preds_weights_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 4608, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv_preds_bias_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 18, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv_pw_11_scratch0_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 12544, AI_STATIC)

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_2_output, AI_STATIC,
  0, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 4, 4, 12, 2688),
  1, &input_2_output_array, NULL)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv1_output, AI_STATIC,
  1, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 112, 112), AI_STRIDE_INIT(4, 4, 4, 32, 3584),
  1, &conv1_output_array, NULL)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_1_output, AI_STATIC,
  2, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 4, 4, 32, 1792),
  1, &conv_dw_1_output_array, NULL)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_1_output, AI_STATIC,
  3, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 56, 56), AI_STRIDE_INIT(4, 4, 4, 64, 3584),
  1, &conv_pw_1_output_array, NULL)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_2_output, AI_STATIC,
  4, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 4, 4, 64, 1792),
  1, &conv_dw_2_output_array, NULL)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_2_output, AI_STATIC,
  5, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 28, 28), AI_STRIDE_INIT(4, 4, 4, 128, 3584),
  1, &conv_pw_2_output_array, NULL)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_3_output, AI_STATIC,
  6, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 28, 28), AI_STRIDE_INIT(4, 4, 4, 128, 3584),
  1, &conv_dw_3_output_array, NULL)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_3_output, AI_STATIC,
  7, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 28, 28), AI_STRIDE_INIT(4, 4, 4, 128, 3584),
  1, &conv_pw_3_output_array, NULL)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_4_output, AI_STATIC,
  8, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 4, 4, 128, 1792),
  1, &conv_dw_4_output_array, NULL)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_4_output, AI_STATIC,
  9, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 14, 14), AI_STRIDE_INIT(4, 4, 4, 256, 3584),
  1, &conv_pw_4_output_array, NULL)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_5_output, AI_STATIC,
  10, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 14, 14), AI_STRIDE_INIT(4, 4, 4, 256, 3584),
  1, &conv_dw_5_output_array, NULL)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_5_output, AI_STATIC,
  11, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 14, 14), AI_STRIDE_INIT(4, 4, 4, 256, 3584),
  1, &conv_pw_5_output_array, NULL)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_6_output, AI_STATIC,
  12, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 7, 7), AI_STRIDE_INIT(4, 4, 4, 256, 1792),
  1, &conv_dw_6_output_array, NULL)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_6_output, AI_STATIC,
  13, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_pw_6_output_array, NULL)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_7_output, AI_STATIC,
  14, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_dw_7_output_array, NULL)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_7_output, AI_STATIC,
  15, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_pw_7_output_array, NULL)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_8_output, AI_STATIC,
  16, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_dw_8_output_array, NULL)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_8_output, AI_STATIC,
  17, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_pw_8_output_array, NULL)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_9_output, AI_STATIC,
  18, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_dw_9_output_array, NULL)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_9_output, AI_STATIC,
  19, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_pw_9_output_array, NULL)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_10_output, AI_STATIC,
  20, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_dw_10_output_array, NULL)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_10_output, AI_STATIC,
  21, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_pw_10_output_array, NULL)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_11_output, AI_STATIC,
  22, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 7, 7), AI_STRIDE_INIT(4, 4, 4, 512, 3584),
  1, &conv_dw_11_output_array, NULL)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_11_output, AI_STATIC,
  23, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv_pw_11_output_array, NULL)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv_preds_output, AI_STATIC,
  24, 0x0,
  AI_SHAPE_INIT(4, 1, 18, 1, 1), AI_STRIDE_INIT(4, 4, 4, 72, 72),
  1, &conv_preds_output_array, NULL)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv1_weights, AI_STATIC,
  25, 0x0,
  AI_SHAPE_INIT(4, 3, 3, 3, 8), AI_STRIDE_INIT(4, 4, 12, 36, 108),
  1, &conv1_weights_array, NULL)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv1_bias, AI_STATIC,
  26, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv1_bias_array, NULL)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_1_weights, AI_STATIC,
  27, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_1_weights_array, NULL)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_1_bias, AI_STATIC,
  28, 0x0,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv_dw_1_bias_array, NULL)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_1_weights, AI_STATIC,
  29, 0x0,
  AI_SHAPE_INIT(4, 8, 1, 1, 16), AI_STRIDE_INIT(4, 4, 32, 32, 32),
  1, &conv_pw_1_weights_array, NULL)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_1_bias, AI_STATIC,
  30, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv_pw_1_bias_array, NULL)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_2_weights, AI_STATIC,
  31, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 16), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_2_weights_array, NULL)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_2_bias, AI_STATIC,
  32, 0x0,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv_dw_2_bias_array, NULL)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_2_weights, AI_STATIC,
  33, 0x0,
  AI_SHAPE_INIT(4, 16, 1, 1, 32), AI_STRIDE_INIT(4, 4, 64, 64, 64),
  1, &conv_pw_2_weights_array, NULL)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_2_bias, AI_STATIC,
  34, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv_pw_2_bias_array, NULL)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_3_weights, AI_STATIC,
  35, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 32), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_3_weights_array, NULL)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_3_bias, AI_STATIC,
  36, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv_dw_3_bias_array, NULL)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_3_weights, AI_STATIC,
  37, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &conv_pw_3_weights_array, NULL)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_3_bias, AI_STATIC,
  38, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv_pw_3_bias_array, NULL)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_4_weights, AI_STATIC,
  39, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 32), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_4_weights_array, NULL)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_4_bias, AI_STATIC,
  40, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv_dw_4_bias_array, NULL)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_4_weights, AI_STATIC,
  41, 0x0,
  AI_SHAPE_INIT(4, 32, 1, 1, 64), AI_STRIDE_INIT(4, 4, 128, 128, 128),
  1, &conv_pw_4_weights_array, NULL)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_4_bias, AI_STATIC,
  42, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv_pw_4_bias_array, NULL)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_5_weights, AI_STATIC,
  43, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 64), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_5_weights_array, NULL)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_5_bias, AI_STATIC,
  44, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv_dw_5_bias_array, NULL)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_5_weights, AI_STATIC,
  45, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 4, 256, 256, 256),
  1, &conv_pw_5_weights_array, NULL)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_5_bias, AI_STATIC,
  46, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv_pw_5_bias_array, NULL)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_6_weights, AI_STATIC,
  47, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 64), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_6_weights_array, NULL)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_6_bias, AI_STATIC,
  48, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv_dw_6_bias_array, NULL)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_6_weights, AI_STATIC,
  49, 0x0,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 4, 256, 256, 256),
  1, &conv_pw_6_weights_array, NULL)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_6_bias, AI_STATIC,
  50, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_pw_6_bias_array, NULL)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_7_weights, AI_STATIC,
  51, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 128), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_7_weights_array, NULL)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_7_bias, AI_STATIC,
  52, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_dw_7_bias_array, NULL)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_7_weights, AI_STATIC,
  53, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &conv_pw_7_weights_array, NULL)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_7_bias, AI_STATIC,
  54, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_pw_7_bias_array, NULL)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_8_weights, AI_STATIC,
  55, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 128), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_8_weights_array, NULL)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_8_bias, AI_STATIC,
  56, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_dw_8_bias_array, NULL)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_8_weights, AI_STATIC,
  57, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &conv_pw_8_weights_array, NULL)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_8_bias, AI_STATIC,
  58, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_pw_8_bias_array, NULL)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_9_weights, AI_STATIC,
  59, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 128), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_9_weights_array, NULL)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_9_bias, AI_STATIC,
  60, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_dw_9_bias_array, NULL)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_9_weights, AI_STATIC,
  61, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &conv_pw_9_weights_array, NULL)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_9_bias, AI_STATIC,
  62, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_pw_9_bias_array, NULL)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_10_weights, AI_STATIC,
  63, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 128), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_10_weights_array, NULL)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_10_bias, AI_STATIC,
  64, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_dw_10_bias_array, NULL)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_10_weights, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &conv_pw_10_weights_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_10_bias, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_pw_10_bias_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_11_weights, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 3, 3, 128), AI_STRIDE_INIT(4, 4, 4, 12, 36),
  1, &conv_dw_11_weights_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv_dw_11_bias, AI_STATIC,
  68, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv_dw_11_bias_array, NULL)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_11_weights, AI_STATIC,
  69, 0x0,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 4, 512, 512, 512),
  1, &conv_pw_11_weights_array, NULL)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_11_bias, AI_STATIC,
  70, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv_pw_11_bias_array, NULL)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv_preds_weights, AI_STATIC,
  71, 0x0,
  AI_SHAPE_INIT(4, 256, 1, 1, 18), AI_STRIDE_INIT(4, 4, 1024, 1024, 1024),
  1, &conv_preds_weights_array, NULL)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv_preds_bias, AI_STATIC,
  72, 0x0,
  AI_SHAPE_INIT(4, 1, 18, 1, 1), AI_STRIDE_INIT(4, 4, 4, 72, 72),
  1, &conv_preds_bias_array, NULL)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv_pw_11_scratch0, AI_STATIC,
  73, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 7, 7), AI_STRIDE_INIT(4, 4, 4, 1024, 7168),
  1, &conv_pw_11_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv1_weights, &conv1_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv1_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv1_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_1_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_1_weights, &conv_dw_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_1_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_1_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_1_layer, AI_STATIC, 
  .groups = 8, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_1_weights, &conv_pw_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_1_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_1_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_2_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_2_weights, &conv_dw_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_2_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_2_layer, AI_STATIC, 
  .groups = 16, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_2_weights, &conv_pw_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_2_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_3_weights, &conv_dw_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_3_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_3_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_3_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_3_weights, &conv_pw_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_3_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_3_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_4_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_4_weights, &conv_dw_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_4_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_4_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_4_weights, &conv_pw_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_4_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_5_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_5_weights, &conv_dw_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_5_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_5_layer, AI_STATIC, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_5_weights, &conv_pw_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_5_layer, 23,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_6_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_6_weights, &conv_dw_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_6_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_6_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_6_layer, AI_STATIC, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_6_weights, &conv_pw_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_6_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_6_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_7_weights, &conv_dw_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_7_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_7_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_7_weights, &conv_pw_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_7_layer, 31,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_8_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_8_weights, &conv_dw_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_8_layer, 32,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_8_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_8_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_8_weights, &conv_pw_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_8_layer, 35,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_8_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_9_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_9_weights, &conv_dw_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_9_layer, 36,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_9_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_9_weights, &conv_pw_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_9_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_10_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_10_weights, &conv_dw_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_10_layer, 40,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_10_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_10_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_10_weights, &conv_pw_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_10_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_pw_10_chain,
  &AI_NET_OBJ_INSTANCE, &conv_dw_11_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_dw_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_dw_11_weights, &conv_dw_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_dw_11_layer, 44,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_dw_11_chain,
  &AI_NET_OBJ_INSTANCE, &conv_pw_11_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_pw_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_dw_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_pw_11_weights, &conv_pw_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_11_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv_pw_11_layer, 48,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool,
  &conv_pw_11_chain,
  &AI_NET_OBJ_INSTANCE, &conv_preds_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_relu_array_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(7, 7), 
  .pool_stride = AI_SHAPE_2D_INIT(7, 7), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_f32, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv_preds_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_pw_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv_preds_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv_preds_weights, &conv_preds_bias, NULL),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conv_preds_layer, 52,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d,
  &conv_preds_chain,
  &AI_NET_OBJ_INSTANCE, &conv_preds_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = nl_func_sm_channel_f32, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 515272, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 403232, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_2_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &conv_preds_output),
  &conv1_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_2_output_array.data = AI_PTR(NULL);
    input_2_output_array.data_start = AI_PTR(NULL);
    conv1_output_array.data = AI_PTR(activations + 1824);
    conv1_output_array.data_start = AI_PTR(activations + 1824);
    conv_dw_1_output_array.data = AI_PTR(activations + 0);
    conv_dw_1_output_array.data_start = AI_PTR(activations + 0);
    conv_pw_1_output_array.data = AI_PTR(activations + 100352);
    conv_pw_1_output_array.data_start = AI_PTR(activations + 100352);
    conv_dw_2_output_array.data = AI_PTR(activations + 0);
    conv_dw_2_output_array.data_start = AI_PTR(activations + 0);
    conv_pw_2_output_array.data = AI_PTR(activations + 50176);
    conv_pw_2_output_array.data_start = AI_PTR(activations + 50176);
    conv_dw_3_output_array.data = AI_PTR(activations + 150528);
    conv_dw_3_output_array.data_start = AI_PTR(activations + 150528);
    conv_pw_3_output_array.data = AI_PTR(activations + 0);
    conv_pw_3_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_4_output_array.data = AI_PTR(activations + 100352);
    conv_dw_4_output_array.data_start = AI_PTR(activations + 100352);
    conv_pw_4_output_array.data = AI_PTR(activations + 0);
    conv_pw_4_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_5_output_array.data = AI_PTR(activations + 50176);
    conv_dw_5_output_array.data_start = AI_PTR(activations + 50176);
    conv_pw_5_output_array.data = AI_PTR(activations + 0);
    conv_pw_5_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_6_output_array.data = AI_PTR(activations + 50176);
    conv_dw_6_output_array.data_start = AI_PTR(activations + 50176);
    conv_pw_6_output_array.data = AI_PTR(activations + 0);
    conv_pw_6_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_7_output_array.data = AI_PTR(activations + 25088);
    conv_dw_7_output_array.data_start = AI_PTR(activations + 25088);
    conv_pw_7_output_array.data = AI_PTR(activations + 0);
    conv_pw_7_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_8_output_array.data = AI_PTR(activations + 25088);
    conv_dw_8_output_array.data_start = AI_PTR(activations + 25088);
    conv_pw_8_output_array.data = AI_PTR(activations + 0);
    conv_pw_8_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_9_output_array.data = AI_PTR(activations + 25088);
    conv_dw_9_output_array.data_start = AI_PTR(activations + 25088);
    conv_pw_9_output_array.data = AI_PTR(activations + 0);
    conv_pw_9_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_10_output_array.data = AI_PTR(activations + 25088);
    conv_dw_10_output_array.data_start = AI_PTR(activations + 25088);
    conv_pw_10_output_array.data = AI_PTR(activations + 0);
    conv_pw_10_output_array.data_start = AI_PTR(activations + 0);
    conv_dw_11_output_array.data = AI_PTR(activations + 25088);
    conv_dw_11_output_array.data_start = AI_PTR(activations + 25088);
    conv_pw_11_output_array.data = AI_PTR(activations + 0);
    conv_pw_11_output_array.data_start = AI_PTR(activations + 0);
    conv_preds_output_array.data = AI_PTR(NULL);
    conv_preds_output_array.data_start = AI_PTR(NULL);
    conv_pw_11_scratch0_array.data = AI_PTR(activations + 50176);
    conv_pw_11_scratch0_array.data_start = AI_PTR(activations + 50176);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    conv1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv1_weights_array.data = AI_PTR(weights + 0);
    conv1_weights_array.data_start = AI_PTR(weights + 0);
    conv1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv1_bias_array.data = AI_PTR(weights + 864);
    conv1_bias_array.data_start = AI_PTR(weights + 864);
    conv_dw_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_1_weights_array.data = AI_PTR(weights + 896);
    conv_dw_1_weights_array.data_start = AI_PTR(weights + 896);
    conv_dw_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_1_bias_array.data = AI_PTR(weights + 1184);
    conv_dw_1_bias_array.data_start = AI_PTR(weights + 1184);
    conv_pw_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_1_weights_array.data = AI_PTR(weights + 1216);
    conv_pw_1_weights_array.data_start = AI_PTR(weights + 1216);
    conv_pw_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_1_bias_array.data = AI_PTR(weights + 1728);
    conv_pw_1_bias_array.data_start = AI_PTR(weights + 1728);
    conv_dw_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_2_weights_array.data = AI_PTR(weights + 1792);
    conv_dw_2_weights_array.data_start = AI_PTR(weights + 1792);
    conv_dw_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_2_bias_array.data = AI_PTR(weights + 2368);
    conv_dw_2_bias_array.data_start = AI_PTR(weights + 2368);
    conv_pw_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_2_weights_array.data = AI_PTR(weights + 2432);
    conv_pw_2_weights_array.data_start = AI_PTR(weights + 2432);
    conv_pw_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_2_bias_array.data = AI_PTR(weights + 4480);
    conv_pw_2_bias_array.data_start = AI_PTR(weights + 4480);
    conv_dw_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_3_weights_array.data = AI_PTR(weights + 4608);
    conv_dw_3_weights_array.data_start = AI_PTR(weights + 4608);
    conv_dw_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_3_bias_array.data = AI_PTR(weights + 5760);
    conv_dw_3_bias_array.data_start = AI_PTR(weights + 5760);
    conv_pw_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_3_weights_array.data = AI_PTR(weights + 5888);
    conv_pw_3_weights_array.data_start = AI_PTR(weights + 5888);
    conv_pw_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_3_bias_array.data = AI_PTR(weights + 9984);
    conv_pw_3_bias_array.data_start = AI_PTR(weights + 9984);
    conv_dw_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_4_weights_array.data = AI_PTR(weights + 10112);
    conv_dw_4_weights_array.data_start = AI_PTR(weights + 10112);
    conv_dw_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_4_bias_array.data = AI_PTR(weights + 11264);
    conv_dw_4_bias_array.data_start = AI_PTR(weights + 11264);
    conv_pw_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_4_weights_array.data = AI_PTR(weights + 11392);
    conv_pw_4_weights_array.data_start = AI_PTR(weights + 11392);
    conv_pw_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_4_bias_array.data = AI_PTR(weights + 19584);
    conv_pw_4_bias_array.data_start = AI_PTR(weights + 19584);
    conv_dw_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_5_weights_array.data = AI_PTR(weights + 19840);
    conv_dw_5_weights_array.data_start = AI_PTR(weights + 19840);
    conv_dw_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_5_bias_array.data = AI_PTR(weights + 22144);
    conv_dw_5_bias_array.data_start = AI_PTR(weights + 22144);
    conv_pw_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_5_weights_array.data = AI_PTR(weights + 22400);
    conv_pw_5_weights_array.data_start = AI_PTR(weights + 22400);
    conv_pw_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_5_bias_array.data = AI_PTR(weights + 38784);
    conv_pw_5_bias_array.data_start = AI_PTR(weights + 38784);
    conv_dw_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_6_weights_array.data = AI_PTR(weights + 39040);
    conv_dw_6_weights_array.data_start = AI_PTR(weights + 39040);
    conv_dw_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_6_bias_array.data = AI_PTR(weights + 41344);
    conv_dw_6_bias_array.data_start = AI_PTR(weights + 41344);
    conv_pw_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_6_weights_array.data = AI_PTR(weights + 41600);
    conv_pw_6_weights_array.data_start = AI_PTR(weights + 41600);
    conv_pw_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_6_bias_array.data = AI_PTR(weights + 74368);
    conv_pw_6_bias_array.data_start = AI_PTR(weights + 74368);
    conv_dw_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_7_weights_array.data = AI_PTR(weights + 74880);
    conv_dw_7_weights_array.data_start = AI_PTR(weights + 74880);
    conv_dw_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_7_bias_array.data = AI_PTR(weights + 79488);
    conv_dw_7_bias_array.data_start = AI_PTR(weights + 79488);
    conv_pw_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_7_weights_array.data = AI_PTR(weights + 80000);
    conv_pw_7_weights_array.data_start = AI_PTR(weights + 80000);
    conv_pw_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_7_bias_array.data = AI_PTR(weights + 145536);
    conv_pw_7_bias_array.data_start = AI_PTR(weights + 145536);
    conv_dw_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_8_weights_array.data = AI_PTR(weights + 146048);
    conv_dw_8_weights_array.data_start = AI_PTR(weights + 146048);
    conv_dw_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_8_bias_array.data = AI_PTR(weights + 150656);
    conv_dw_8_bias_array.data_start = AI_PTR(weights + 150656);
    conv_pw_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_8_weights_array.data = AI_PTR(weights + 151168);
    conv_pw_8_weights_array.data_start = AI_PTR(weights + 151168);
    conv_pw_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_8_bias_array.data = AI_PTR(weights + 216704);
    conv_pw_8_bias_array.data_start = AI_PTR(weights + 216704);
    conv_dw_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_9_weights_array.data = AI_PTR(weights + 217216);
    conv_dw_9_weights_array.data_start = AI_PTR(weights + 217216);
    conv_dw_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_9_bias_array.data = AI_PTR(weights + 221824);
    conv_dw_9_bias_array.data_start = AI_PTR(weights + 221824);
    conv_pw_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_9_weights_array.data = AI_PTR(weights + 222336);
    conv_pw_9_weights_array.data_start = AI_PTR(weights + 222336);
    conv_pw_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_9_bias_array.data = AI_PTR(weights + 287872);
    conv_pw_9_bias_array.data_start = AI_PTR(weights + 287872);
    conv_dw_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_10_weights_array.data = AI_PTR(weights + 288384);
    conv_dw_10_weights_array.data_start = AI_PTR(weights + 288384);
    conv_dw_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_10_bias_array.data = AI_PTR(weights + 292992);
    conv_dw_10_bias_array.data_start = AI_PTR(weights + 292992);
    conv_pw_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_10_weights_array.data = AI_PTR(weights + 293504);
    conv_pw_10_weights_array.data_start = AI_PTR(weights + 293504);
    conv_pw_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_10_bias_array.data = AI_PTR(weights + 359040);
    conv_pw_10_bias_array.data_start = AI_PTR(weights + 359040);
    conv_dw_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_11_weights_array.data = AI_PTR(weights + 359552);
    conv_dw_11_weights_array.data_start = AI_PTR(weights + 359552);
    conv_dw_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_dw_11_bias_array.data = AI_PTR(weights + 364160);
    conv_dw_11_bias_array.data_start = AI_PTR(weights + 364160);
    conv_pw_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_11_weights_array.data = AI_PTR(weights + 364672);
    conv_pw_11_weights_array.data_start = AI_PTR(weights + 364672);
    conv_pw_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_pw_11_bias_array.data = AI_PTR(weights + 495744);
    conv_pw_11_bias_array.data_start = AI_PTR(weights + 495744);
    conv_preds_weights_array.format |= AI_FMT_FLAG_CONST;
    conv_preds_weights_array.data = AI_PTR(weights + 496768);
    conv_preds_weights_array.data_start = AI_PTR(weights + 496768);
    conv_preds_bias_array.format |= AI_FMT_FLAG_CONST;
    conv_preds_bias_array.data = AI_PTR(weights + 515200);
    conv_preds_bias_array.data_start = AI_PTR(weights + 515200);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_NETWORK_MODEL_NAME,
      .model_signature   = AI_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = AI_STRUCT_INIT,

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 12071056,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if (!ai_platform_api_get_network_report(network, &r)) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= network_configure_weights(net_ctx, &params->params);
  ok &= network_configure_activations(net_ctx, &params->activations);

  ok &= ai_platform_network_post_init(network);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}



#undef AI_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

