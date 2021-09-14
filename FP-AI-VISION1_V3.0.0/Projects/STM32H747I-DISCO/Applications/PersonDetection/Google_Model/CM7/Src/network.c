/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Apr 16 14:26:26 2021
  * @brief   Network topology generated using X-CUBE-AI from
  *          person_detect.tflite
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
#define AI_NETWORK_MODEL_SIGNATURE     "f591ef0be0505c280f128e06e437e310"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Fri Apr 16 14:26:26 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_output_array;   /* Array #0 */
AI_STATIC ai_array conv2d_0_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_1_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #3 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #5 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #6 */
AI_STATIC ai_array conv2d_6_output_array;   /* Array #7 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #9 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #10 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #11 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #12 */
AI_STATIC ai_array conv2d_12_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #14 */
AI_STATIC ai_array conv2d_14_output_array;   /* Array #15 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #17 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #18 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #19 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #20 */
AI_STATIC ai_array conv2d_20_output_array;   /* Array #21 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #23 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #24 */
AI_STATIC ai_array conv2d_24_output_array;   /* Array #25 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #26 */
AI_STATIC ai_array conv2d_26_output_array;   /* Array #27 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #28 */
AI_STATIC ai_array conv2d_0_weights_array;   /* Array #29 */
AI_STATIC ai_array conv2d_0_bias_array;   /* Array #30 */
AI_STATIC ai_array conv2d_1_weights_array;   /* Array #31 */
AI_STATIC ai_array conv2d_1_bias_array;   /* Array #32 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #33 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #34 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #35 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #36 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #37 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #38 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #39 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #40 */
AI_STATIC ai_array conv2d_6_weights_array;   /* Array #41 */
AI_STATIC ai_array conv2d_6_bias_array;   /* Array #42 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #43 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #44 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #45 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #46 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #47 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #48 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #49 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #50 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #51 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #52 */
AI_STATIC ai_array conv2d_12_weights_array;   /* Array #53 */
AI_STATIC ai_array conv2d_12_bias_array;   /* Array #54 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #55 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #56 */
AI_STATIC ai_array conv2d_14_weights_array;   /* Array #57 */
AI_STATIC ai_array conv2d_14_bias_array;   /* Array #58 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #59 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #60 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #61 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #62 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #63 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #64 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #65 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #66 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #67 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #68 */
AI_STATIC ai_array conv2d_20_weights_array;   /* Array #69 */
AI_STATIC ai_array conv2d_20_bias_array;   /* Array #70 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #71 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #72 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #73 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #74 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #75 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #76 */
AI_STATIC ai_array conv2d_24_weights_array;   /* Array #77 */
AI_STATIC ai_array conv2d_24_bias_array;   /* Array #78 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #79 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #80 */
AI_STATIC ai_array conv2d_26_weights_array;   /* Array #81 */
AI_STATIC ai_array conv2d_26_bias_array;   /* Array #82 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #83 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #84 */
AI_STATIC ai_array conv2d_0_scratch0_array;   /* Array #85 */
AI_STATIC ai_array conv2d_1_scratch0_array;   /* Array #86 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #87 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #88 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #89 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #90 */
AI_STATIC ai_array conv2d_6_scratch0_array;   /* Array #91 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #92 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #93 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #94 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #95 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #96 */
AI_STATIC ai_array conv2d_12_scratch0_array;   /* Array #97 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #98 */
AI_STATIC ai_array conv2d_14_scratch0_array;   /* Array #99 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #100 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #101 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #102 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #103 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #104 */
AI_STATIC ai_array conv2d_20_scratch0_array;   /* Array #105 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #106 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #107 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #108 */
AI_STATIC ai_array conv2d_24_scratch0_array;   /* Array #109 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #110 */
AI_STATIC ai_array conv2d_26_scratch0_array;   /* Array #111 */
AI_STATIC ai_array conv2d_26_scratch1_array;   /* Array #112 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #113 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_output;   /* Tensor #0 */
AI_STATIC ai_tensor conv2d_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_1_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_6_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #10 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_12_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_14_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #17 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_20_output;   /* Tensor #21 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_24_output;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_26_output;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #28 */
AI_STATIC ai_tensor conv2d_0_weights;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_0_bias;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_1_weights;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_1_bias;   /* Tensor #32 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #36 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_6_weights;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_6_bias;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #43 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #47 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_12_weights;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_12_bias;   /* Tensor #54 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_14_weights;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_14_bias;   /* Tensor #58 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #63 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #64 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #65 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #66 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_20_weights;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_20_bias;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_24_weights;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_24_bias;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_26_weights;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_26_bias;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_0_scratch0;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_1_scratch0;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_6_scratch0;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_12_scratch0;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_14_scratch0;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_20_scratch0;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_24_scratch0;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_26_scratch0;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_26_scratch1;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #113 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conv2d_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_1_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_6_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_12_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_14_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv2d_20_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_24_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_26_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #27 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_conv2d conv2d_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_1_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_6_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #9 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_12_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_14_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #16 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv2d_20_layer; /* Layer #20 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_24_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_26_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #27 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 9216, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 36864, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 18432, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_output_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 256, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 3, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 72, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 72, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 128, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 144, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 512, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 288, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 288, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 576, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 576, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 64, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 16384, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 1152, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 128, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 256, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 768, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 3, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_0_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 212, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_1_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 217, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 433, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 64, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 865, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_6_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 865, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1729, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1729, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_12_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 256, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_14_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_20_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3457, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_24_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6913, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_26_scratch1_array, AI_ARRAY_FORMAT_U8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007874015718698502f),
    AI_PACK_UINTQ_ZP(128)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528480902314186f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528479039669037f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528479039669037f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528479039669037f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528480902314186f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528480902314186f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528480902314186f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235213004052639f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02351861633360386f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528480902314186f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022288218140602112f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02342604659497738f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021722828969359398f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023528477177023888f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008967787027359009f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01627892255783081f),
    AI_PACK_UINTQ_ZP(113)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.024417636916041374f),
    AI_PACK_UINTQ_ZP(134)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_0_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019226486620027572f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.474043607711792f),
    AI_PACK_UINTQ_ZP(126)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_1_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011153523810207844f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012277676723897457f),
    AI_PACK_UINTQ_ZP(126)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00028887507505714893f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022977391257882118f),
    AI_PACK_UINTQ_ZP(152)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005406229756772518f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011306188069283962f),
    AI_PACK_UINTQ_ZP(117)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00026601742138154805f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022649727761745453f),
    AI_PACK_UINTQ_ZP(129)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005329136620275676f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012786287814378738f),
    AI_PACK_UINTQ_ZP(79)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_6_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00030084187164902687f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010893985629081726f),
    AI_PACK_UINTQ_ZP(162)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000256318919127807f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0056244744919240475f),
    AI_PACK_UINTQ_ZP(112)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013233533536549658f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018023746088147163f),
    AI_PACK_UINTQ_ZP(103)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004240713606122881f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004776209592819214f),
    AI_PACK_UINTQ_ZP(126)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011237693979637697f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0085530336946249f),
    AI_PACK_UINTQ_ZP(104)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00020123984722886235f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005623524077236652f),
    AI_PACK_UINTQ_ZP(95)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_12_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013231295451987535f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.015387296676635742f),
    AI_PACK_UINTQ_ZP(110)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003620396601036191f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00371667486615479f),
    AI_PACK_UINTQ_ZP(105)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_14_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.744771184865385e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011986683122813702f),
    AI_PACK_UINTQ_ZP(113)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002819423680193722f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0032304886262863874f),
    AI_PACK_UINTQ_ZP(125)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.600847311550751e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01630396768450737f),
    AI_PACK_UINTQ_ZP(109)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003834467497654259f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00393608957529068f),
    AI_PACK_UINTQ_ZP(135)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.261018567485735e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012122264131903648f),
    AI_PACK_UINTQ_ZP(108)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002852184697985649f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003951582591980696f),
    AI_PACK_UINTQ_ZP(126)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_20_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.297472570324317e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011124005541205406f),
    AI_PACK_UINTQ_ZP(128)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002617308928165585f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0037297201342880726f),
    AI_PACK_UINTQ_ZP(99)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.775463356869295e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009452849626541138f),
    AI_PACK_UINTQ_ZP(125)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021068716887384653f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004108153749257326f),
    AI_PACK_UINTQ_ZP(117)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_24_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.623780351830646e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.047541480511426926f),
    AI_PACK_UINTQ_ZP(120)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010327354539185762f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004574603866785765f),
    AI_PACK_UINTQ_ZP(146)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010763345926534384f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0017644957406446338f),
    AI_PACK_UINTQ_ZP(165)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.582362165208906e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_26_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008967787027359009f),
    AI_PACK_UINTQ_ZP(0)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 1, 96, 96), AI_STRIDE_INIT(4, 1, 1, 1, 96),
  1, &input_output_array, &input_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_0_output_array, &conv2d_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 48, 48), AI_STRIDE_INIT(4, 1, 1, 8, 384),
  1, &conv2d_1_output_array, &conv2d_1_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 48, 48), AI_STRIDE_INIT(4, 1, 1, 16, 768),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 24, 24), AI_STRIDE_INIT(4, 1, 1, 16, 384),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 24, 24), AI_STRIDE_INIT(4, 1, 1, 32, 768),
  1, &conv2d_6_output_array, &conv2d_6_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 12, 12), AI_STRIDE_INIT(4, 1, 1, 32, 384),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 12, 12), AI_STRIDE_INIT(4, 1, 1, 64, 768),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 6, 6), AI_STRIDE_INIT(4, 1, 1, 64, 384),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_12_output_array, &conv2d_12_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_14_output_array, &conv2d_14_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_20_output_array, &conv2d_20_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 6, 6), AI_STRIDE_INIT(4, 1, 1, 128, 768),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 3, 3), AI_STRIDE_INIT(4, 1, 1, 128, 384),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_24_output_array, &conv2d_24_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_26_output_array, &conv2d_26_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3, 3),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_weights, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 3, 8), AI_STRIDE_INIT(4, 1, 1, 3, 9),
  1, &conv2d_0_weights_array, &conv2d_0_weights_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_bias, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_0_bias_array, &conv2d_0_bias_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_weights, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 8, 3, 3, 1), AI_STRIDE_INIT(4, 1, 8, 24, 72),
  1, &conv2d_1_weights_array, &conv2d_1_weights_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_bias, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_1_bias_array, &conv2d_1_bias_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 16), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 32), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_weights, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 32), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_6_weights_array, &conv2d_6_weights_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_bias, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_6_bias_array, &conv2d_6_bias_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 32, 3, 3, 1), AI_STRIDE_INIT(4, 1, 32, 96, 288),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 64), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 64), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 64, 3, 3, 1), AI_STRIDE_INIT(4, 1, 64, 192, 576),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 4, 4, 256, 256),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_weights, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 64, 1, 1, 128), AI_STRIDE_INIT(4, 1, 64, 64, 64),
  1, &conv2d_12_weights_array, &conv2d_12_weights_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_bias, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_12_bias_array, &conv2d_12_bias_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_weights, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_14_weights_array, &conv2d_14_weights_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_bias, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_14_bias_array, &conv2d_14_bias_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  66, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_weights, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_20_weights_array, &conv2d_20_weights_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_bias, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_20_bias_array, &conv2d_20_bias_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 128), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 128, 3, 3, 1), AI_STRIDE_INIT(4, 1, 128, 384, 1152),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 4, 4, 512, 512),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_weights, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 128, 1, 1, 256), AI_STRIDE_INIT(4, 1, 128, 128, 128),
  1, &conv2d_24_weights_array, &conv2d_24_weights_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_bias, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_24_bias_array, &conv2d_24_bias_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 256, 3, 3, 1), AI_STRIDE_INIT(4, 1, 256, 768, 2304),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_weights, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 256), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_26_weights_array, &conv2d_26_weights_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_bias, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1024, 1024),
  1, &conv2d_26_bias_array, &conv2d_26_bias_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 256, 1, 1, 3), AI_STRIDE_INIT(4, 1, 256, 256, 256),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_0_scratch0, AI_STATIC,
  85, 0x0,
  AI_SHAPE_INIT(4, 1, 212, 1, 1), AI_STRIDE_INIT(4, 1, 1, 212, 212),
  1, &conv2d_0_scratch0_array, NULL)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_1_scratch0, AI_STATIC,
  86, 0x0,
  AI_SHAPE_INIT(4, 1, 217, 1, 1), AI_STRIDE_INIT(4, 1, 1, 217, 217),
  1, &conv2d_1_scratch0_array, NULL)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  87, 0x0,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 1, 1, 32, 32),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  88, 0x0,
  AI_SHAPE_INIT(4, 1, 433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 433, 433),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  89, 0x0,
  AI_SHAPE_INIT(4, 1, 64, 1, 1), AI_STRIDE_INIT(4, 1, 1, 64, 64),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  90, 0x0,
  AI_SHAPE_INIT(4, 1, 865, 1, 1), AI_STRIDE_INIT(4, 1, 1, 865, 865),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_6_scratch0, AI_STATIC,
  91, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &conv2d_6_scratch0_array, NULL)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  92, 0x0,
  AI_SHAPE_INIT(4, 1, 865, 1, 1), AI_STRIDE_INIT(4, 1, 1, 865, 865),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  93, 0x0,
  AI_SHAPE_INIT(4, 1, 128, 1, 1), AI_STRIDE_INIT(4, 1, 1, 128, 128),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  94, 0x0,
  AI_SHAPE_INIT(4, 1, 1729, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1729, 1729),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  95, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  96, 0x0,
  AI_SHAPE_INIT(4, 1, 1729, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1729, 1729),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_12_scratch0, AI_STATIC,
  97, 0x0,
  AI_SHAPE_INIT(4, 1, 256, 1, 1), AI_STRIDE_INIT(4, 1, 1, 256, 256),
  1, &conv2d_12_scratch0_array, NULL)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  98, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_14_scratch0, AI_STATIC,
  99, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_14_scratch0_array, NULL)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  100, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  101, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  102, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  103, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  104, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_20_scratch0, AI_STATIC,
  105, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_20_scratch0_array, NULL)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  106, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  107, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  108, 0x0,
  AI_SHAPE_INIT(4, 1, 3457, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3457, 3457),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_24_scratch0, AI_STATIC,
  109, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_24_scratch0_array, NULL)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  110, 0x0,
  AI_SHAPE_INIT(4, 1, 6913, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6913, 6913),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch0, AI_STATIC,
  111, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_26_scratch0_array, NULL)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_26_scratch1, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 1, 256, 3, 3), AI_STRIDE_INIT(4, 1, 1, 256, 768),
  1, &conv2d_26_scratch1_array, &conv2d_26_scratch1_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  113, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_28_scratch0_array, NULL)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_0_weights, &conv2d_0_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_0_layer, 0,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_0_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_1_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_1_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_1_weights, &conv2d_1_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_1_layer, 1,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_1_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC, 
  .groups = 8, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_3_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC, 
  .groups = 16, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_4_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_4_weights, &conv2d_4_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_4_layer, 4,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_4_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_5_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_5_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_4_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_5_weights, &conv2d_5_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_6_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_6_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_6_weights, &conv2d_6_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_6_layer, 6,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_6_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_6_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC, 
  .groups = 32, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_8_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_9_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_9_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_9_weights, &conv2d_9_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_10_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_11_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_11_weights, &conv2d_11_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_11_layer, 11,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_11_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_12_layer, AI_STATIC, 
  .groups = 64, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_12_weights, &conv2d_12_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_12_layer, 12,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_12_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_13_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_14_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_14_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_14_weights, &conv2d_14_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_14_layer, 14,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_14_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_14_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_15_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_16_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_17_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_17_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_17_weights, &conv2d_17_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_17_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_18_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_19_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_19_weights, &conv2d_19_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_19_layer, 19,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_19_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_20_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_20_weights, &conv2d_20_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_20_layer, 20,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_20_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_21_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_22_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_23_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_23_weights, &conv2d_23_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_23_layer, 23,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_23_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_24_layer, AI_STATIC, 
  .groups = 128, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 2, 2), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_24_weights, &conv2d_24_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_24_layer, 24,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_24_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_25_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_26_layer, AI_STATIC, 
  .groups = 256, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_26_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_26_weights, &conv2d_26_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_26_scratch0, &conv2d_26_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_26_layer, 27,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_UAUA,
  &conv2d_26_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(3, 3), 
  .pool_stride = AI_SHAPE_2D_INIT(2, 2), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_UINT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_26_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_UAUA,
  &conv2d_28_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 219180, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 38080, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &conv2d_28_output),
  &conv2d_0_layer, 0, NULL)



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
    input_output_array.data = AI_PTR(activations + 19616);
    input_output_array.data_start = AI_PTR(activations + 19616);
    conv2d_0_output_array.data = AI_PTR(activations + 1184);
    conv2d_0_output_array.data_start = AI_PTR(activations + 1184);
    conv2d_1_output_array.data = AI_PTR(activations + 19616);
    conv2d_1_output_array.data_start = AI_PTR(activations + 19616);
    conv2d_2_output_array.data = AI_PTR(activations + 400);
    conv2d_2_output_array.data_start = AI_PTR(activations + 400);
    conv2d_3_output_array.data = AI_PTR(activations + 0);
    conv2d_3_output_array.data_start = AI_PTR(activations + 0);
    conv2d_4_output_array.data = AI_PTR(activations + 9280);
    conv2d_4_output_array.data_start = AI_PTR(activations + 9280);
    conv2d_5_output_array.data = AI_PTR(activations + 7680);
    conv2d_5_output_array.data_start = AI_PTR(activations + 7680);
    conv2d_6_output_array.data = AI_PTR(activations + 6880);
    conv2d_6_output_array.data_start = AI_PTR(activations + 6880);
    conv2d_7_output_array.data = AI_PTR(activations + 868);
    conv2d_7_output_array.data_start = AI_PTR(activations + 868);
    conv2d_8_output_array.data = AI_PTR(activations + 5476);
    conv2d_8_output_array.data_start = AI_PTR(activations + 5476);
    conv2d_9_output_array.data = AI_PTR(activations + 14692);
    conv2d_9_output_array.data_start = AI_PTR(activations + 14692);
    conv2d_10_output_array.data = AI_PTR(activations + 256);
    conv2d_10_output_array.data_start = AI_PTR(activations + 256);
    conv2d_11_output_array.data = AI_PTR(activations + 11204);
    conv2d_11_output_array.data_start = AI_PTR(activations + 11204);
    conv2d_12_output_array.data = AI_PTR(activations + 256);
    conv2d_12_output_array.data_start = AI_PTR(activations + 256);
    conv2d_13_output_array.data = AI_PTR(activations + 8324);
    conv2d_13_output_array.data_start = AI_PTR(activations + 8324);
    conv2d_14_output_array.data = AI_PTR(activations + 512);
    conv2d_14_output_array.data_start = AI_PTR(activations + 512);
    conv2d_15_output_array.data = AI_PTR(activations + 8580);
    conv2d_15_output_array.data_start = AI_PTR(activations + 8580);
    conv2d_16_output_array.data = AI_PTR(activations + 512);
    conv2d_16_output_array.data_start = AI_PTR(activations + 512);
    conv2d_17_output_array.data = AI_PTR(activations + 8580);
    conv2d_17_output_array.data_start = AI_PTR(activations + 8580);
    conv2d_18_output_array.data = AI_PTR(activations + 512);
    conv2d_18_output_array.data_start = AI_PTR(activations + 512);
    conv2d_19_output_array.data = AI_PTR(activations + 8580);
    conv2d_19_output_array.data_start = AI_PTR(activations + 8580);
    conv2d_20_output_array.data = AI_PTR(activations + 512);
    conv2d_20_output_array.data_start = AI_PTR(activations + 512);
    conv2d_21_output_array.data = AI_PTR(activations + 8580);
    conv2d_21_output_array.data_start = AI_PTR(activations + 8580);
    conv2d_22_output_array.data = AI_PTR(activations + 512);
    conv2d_22_output_array.data_start = AI_PTR(activations + 512);
    conv2d_23_output_array.data = AI_PTR(activations + 8580);
    conv2d_23_output_array.data_start = AI_PTR(activations + 8580);
    conv2d_24_output_array.data = AI_PTR(activations + 512);
    conv2d_24_output_array.data_start = AI_PTR(activations + 512);
    conv2d_25_output_array.data = AI_PTR(activations + 9732);
    conv2d_25_output_array.data_start = AI_PTR(activations + 9732);
    conv2d_26_output_array.data = AI_PTR(activations + 3328);
    conv2d_26_output_array.data_start = AI_PTR(activations + 3328);
    conv2d_28_output_array.data = AI_PTR(NULL);
    conv2d_28_output_array.data_start = AI_PTR(NULL);
    conv2d_0_scratch0_array.data = AI_PTR(activations + 28832);
    conv2d_0_scratch0_array.data_start = AI_PTR(activations + 28832);
    conv2d_1_scratch0_array.data = AI_PTR(activations + 964);
    conv2d_1_scratch0_array.data_start = AI_PTR(activations + 964);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 38048);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 38048);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 37644);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 37644);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 9216);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 9216);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_6_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_6_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 9472);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 9472);
    conv2d_12_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_12_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 4864);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 4864);
    conv2d_14_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_14_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 5120);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 5120);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 5120);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 5120);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 5120);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 5120);
    conv2d_20_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_20_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 5120);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 5120);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 5120);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 5120);
    conv2d_24_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_24_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 2816);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 2816);
    conv2d_26_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_26_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_26_scratch1_array.data = AI_PTR(activations + 1024);
    conv2d_26_scratch1_array.data_start = AI_PTR(activations + 1024);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 0);
    
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
    
    conv2d_0_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_weights_array.data = AI_PTR(weights + 0);
    conv2d_0_weights_array.data_start = AI_PTR(weights + 0);
    conv2d_0_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_0_bias_array.data = AI_PTR(weights + 72);
    conv2d_0_bias_array.data_start = AI_PTR(weights + 72);
    conv2d_1_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_weights_array.data = AI_PTR(weights + 104);
    conv2d_1_weights_array.data_start = AI_PTR(weights + 104);
    conv2d_1_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_1_bias_array.data = AI_PTR(weights + 176);
    conv2d_1_bias_array.data_start = AI_PTR(weights + 176);
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 208);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 208);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 336);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 336);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 400);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 400);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 544);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 544);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 608);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 608);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 1120);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 1120);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 1248);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 1248);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 1536);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 1536);
    conv2d_6_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_weights_array.data = AI_PTR(weights + 1664);
    conv2d_6_weights_array.data_start = AI_PTR(weights + 1664);
    conv2d_6_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_6_bias_array.data = AI_PTR(weights + 2688);
    conv2d_6_bias_array.data_start = AI_PTR(weights + 2688);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 2816);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 2816);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 3104);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 3104);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 3232);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 3232);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 5280);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 5280);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 5536);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 5536);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 6112);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 6112);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 6368);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 6368);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 10464);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 10464);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 10720);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 10720);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 11296);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 11296);
    conv2d_12_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_weights_array.data = AI_PTR(weights + 11552);
    conv2d_12_weights_array.data_start = AI_PTR(weights + 11552);
    conv2d_12_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_12_bias_array.data = AI_PTR(weights + 19744);
    conv2d_12_bias_array.data_start = AI_PTR(weights + 19744);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 20256);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 20256);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 21408);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 21408);
    conv2d_14_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_weights_array.data = AI_PTR(weights + 21920);
    conv2d_14_weights_array.data_start = AI_PTR(weights + 21920);
    conv2d_14_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_14_bias_array.data = AI_PTR(weights + 38304);
    conv2d_14_bias_array.data_start = AI_PTR(weights + 38304);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 38816);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 38816);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 39968);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 39968);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 40480);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 40480);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 56864);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 56864);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 57376);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 57376);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 58528);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 58528);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 59040);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 59040);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 75424);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 75424);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 75936);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 75936);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 77088);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 77088);
    conv2d_20_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_weights_array.data = AI_PTR(weights + 77600);
    conv2d_20_weights_array.data_start = AI_PTR(weights + 77600);
    conv2d_20_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_20_bias_array.data = AI_PTR(weights + 93984);
    conv2d_20_bias_array.data_start = AI_PTR(weights + 93984);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 94496);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 94496);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 95648);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 95648);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 96160);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 96160);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 112544);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 112544);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 113056);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 113056);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 114208);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 114208);
    conv2d_24_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_weights_array.data = AI_PTR(weights + 114720);
    conv2d_24_weights_array.data_start = AI_PTR(weights + 114720);
    conv2d_24_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_24_bias_array.data = AI_PTR(weights + 147488);
    conv2d_24_bias_array.data_start = AI_PTR(weights + 147488);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 148512);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 148512);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 150816);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 150816);
    conv2d_26_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_weights_array.data = AI_PTR(weights + 151840);
    conv2d_26_weights_array.data_start = AI_PTR(weights + 151840);
    conv2d_26_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_26_bias_array.data = AI_PTR(weights + 217376);
    conv2d_26_bias_array.data_start = AI_PTR(weights + 217376);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 218400);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 218400);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 219168);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 219168);
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
      
      .n_macc            = 7163187,
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

