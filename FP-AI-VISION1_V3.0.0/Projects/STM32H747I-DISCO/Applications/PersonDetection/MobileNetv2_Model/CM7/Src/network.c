/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Fri Apr 16 14:47:10 2021
  * @brief   Network topology generated using X-CUBE-AI from
  *          mobv2_128x128x3_adam02_respin01.best_val.035.h5.uint8.tflite
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
#define AI_NETWORK_MODEL_SIGNATURE     "465e8b22dc4453af931031f0637739ff"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Fri Apr 16 14:47:10 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array input_1_output_array;   /* Array #0 */
AI_STATIC ai_array conversion_0_output_array;   /* Array #1 */
AI_STATIC ai_array conv2d_2_output_array;   /* Array #2 */
AI_STATIC ai_array conv2d_3_output_array;   /* Array #3 */
AI_STATIC ai_array conv2d_4_output_array;   /* Array #4 */
AI_STATIC ai_array conv2d_5_output_array;   /* Array #5 */
AI_STATIC ai_array conv2d_7_output_array;   /* Array #6 */
AI_STATIC ai_array conv2d_8_output_array;   /* Array #7 */
AI_STATIC ai_array conv2d_9_output_array;   /* Array #8 */
AI_STATIC ai_array conv2d_10_output_array;   /* Array #9 */
AI_STATIC ai_array conv2d_11_output_array;   /* Array #10 */
AI_STATIC ai_array eltwise_12_output_array;   /* Array #11 */
AI_STATIC ai_array conv2d_13_output_array;   /* Array #12 */
AI_STATIC ai_array conv2d_15_output_array;   /* Array #13 */
AI_STATIC ai_array conv2d_16_output_array;   /* Array #14 */
AI_STATIC ai_array conv2d_17_output_array;   /* Array #15 */
AI_STATIC ai_array conv2d_18_output_array;   /* Array #16 */
AI_STATIC ai_array conv2d_19_output_array;   /* Array #17 */
AI_STATIC ai_array eltwise_20_output_array;   /* Array #18 */
AI_STATIC ai_array conv2d_21_output_array;   /* Array #19 */
AI_STATIC ai_array conv2d_22_output_array;   /* Array #20 */
AI_STATIC ai_array conv2d_23_output_array;   /* Array #21 */
AI_STATIC ai_array eltwise_24_output_array;   /* Array #22 */
AI_STATIC ai_array conv2d_25_output_array;   /* Array #23 */
AI_STATIC ai_array conv2d_27_output_array;   /* Array #24 */
AI_STATIC ai_array conv2d_28_output_array;   /* Array #25 */
AI_STATIC ai_array conv2d_29_output_array;   /* Array #26 */
AI_STATIC ai_array conv2d_30_output_array;   /* Array #27 */
AI_STATIC ai_array conv2d_31_output_array;   /* Array #28 */
AI_STATIC ai_array eltwise_32_output_array;   /* Array #29 */
AI_STATIC ai_array conv2d_33_output_array;   /* Array #30 */
AI_STATIC ai_array conv2d_34_output_array;   /* Array #31 */
AI_STATIC ai_array conv2d_35_output_array;   /* Array #32 */
AI_STATIC ai_array eltwise_36_output_array;   /* Array #33 */
AI_STATIC ai_array conv2d_37_output_array;   /* Array #34 */
AI_STATIC ai_array conv2d_38_output_array;   /* Array #35 */
AI_STATIC ai_array conv2d_39_output_array;   /* Array #36 */
AI_STATIC ai_array eltwise_40_output_array;   /* Array #37 */
AI_STATIC ai_array conv2d_41_output_array;   /* Array #38 */
AI_STATIC ai_array conv2d_42_output_array;   /* Array #39 */
AI_STATIC ai_array conv2d_43_output_array;   /* Array #40 */
AI_STATIC ai_array conv2d_44_output_array;   /* Array #41 */
AI_STATIC ai_array conv2d_45_output_array;   /* Array #42 */
AI_STATIC ai_array conv2d_46_output_array;   /* Array #43 */
AI_STATIC ai_array eltwise_47_output_array;   /* Array #44 */
AI_STATIC ai_array conv2d_48_output_array;   /* Array #45 */
AI_STATIC ai_array conv2d_49_output_array;   /* Array #46 */
AI_STATIC ai_array conv2d_50_output_array;   /* Array #47 */
AI_STATIC ai_array eltwise_51_output_array;   /* Array #48 */
AI_STATIC ai_array conv2d_52_output_array;   /* Array #49 */
AI_STATIC ai_array conv2d_54_output_array;   /* Array #50 */
AI_STATIC ai_array conv2d_55_output_array;   /* Array #51 */
AI_STATIC ai_array conv2d_56_output_array;   /* Array #52 */
AI_STATIC ai_array conv2d_57_output_array;   /* Array #53 */
AI_STATIC ai_array conv2d_58_output_array;   /* Array #54 */
AI_STATIC ai_array eltwise_59_output_array;   /* Array #55 */
AI_STATIC ai_array conv2d_60_output_array;   /* Array #56 */
AI_STATIC ai_array conv2d_61_output_array;   /* Array #57 */
AI_STATIC ai_array conv2d_62_output_array;   /* Array #58 */
AI_STATIC ai_array eltwise_63_output_array;   /* Array #59 */
AI_STATIC ai_array conv2d_64_output_array;   /* Array #60 */
AI_STATIC ai_array conv2d_65_output_array;   /* Array #61 */
AI_STATIC ai_array conv2d_66_output_array;   /* Array #62 */
AI_STATIC ai_array conv2d_67_output_array;   /* Array #63 */
AI_STATIC ai_array dense_69_output_array;   /* Array #64 */
AI_STATIC ai_array dense_69_fmt_output_array;   /* Array #65 */
AI_STATIC ai_array nl_70_output_array;   /* Array #66 */
AI_STATIC ai_array nl_70_fmt_output_array;   /* Array #67 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #68 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #69 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #70 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #71 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #72 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #73 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #74 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #75 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #76 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #77 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #78 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #79 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #80 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #81 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #82 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #83 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #84 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #85 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #86 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #87 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #88 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #89 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #90 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #91 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #92 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #93 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #94 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #95 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #96 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #97 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #98 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #99 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #100 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #101 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #102 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #103 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #104 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #105 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #106 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #107 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #108 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #109 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #110 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #111 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #112 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #113 */
AI_STATIC ai_array conv2d_31_weights_array;   /* Array #114 */
AI_STATIC ai_array conv2d_31_bias_array;   /* Array #115 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #116 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #117 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #118 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #119 */
AI_STATIC ai_array conv2d_35_weights_array;   /* Array #120 */
AI_STATIC ai_array conv2d_35_bias_array;   /* Array #121 */
AI_STATIC ai_array conv2d_37_weights_array;   /* Array #122 */
AI_STATIC ai_array conv2d_37_bias_array;   /* Array #123 */
AI_STATIC ai_array conv2d_38_weights_array;   /* Array #124 */
AI_STATIC ai_array conv2d_38_bias_array;   /* Array #125 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #126 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #127 */
AI_STATIC ai_array conv2d_41_weights_array;   /* Array #128 */
AI_STATIC ai_array conv2d_41_bias_array;   /* Array #129 */
AI_STATIC ai_array conv2d_42_weights_array;   /* Array #130 */
AI_STATIC ai_array conv2d_42_bias_array;   /* Array #131 */
AI_STATIC ai_array conv2d_43_weights_array;   /* Array #132 */
AI_STATIC ai_array conv2d_43_bias_array;   /* Array #133 */
AI_STATIC ai_array conv2d_44_weights_array;   /* Array #134 */
AI_STATIC ai_array conv2d_44_bias_array;   /* Array #135 */
AI_STATIC ai_array conv2d_45_weights_array;   /* Array #136 */
AI_STATIC ai_array conv2d_45_bias_array;   /* Array #137 */
AI_STATIC ai_array conv2d_46_weights_array;   /* Array #138 */
AI_STATIC ai_array conv2d_46_bias_array;   /* Array #139 */
AI_STATIC ai_array conv2d_48_weights_array;   /* Array #140 */
AI_STATIC ai_array conv2d_48_bias_array;   /* Array #141 */
AI_STATIC ai_array conv2d_49_weights_array;   /* Array #142 */
AI_STATIC ai_array conv2d_49_bias_array;   /* Array #143 */
AI_STATIC ai_array conv2d_50_weights_array;   /* Array #144 */
AI_STATIC ai_array conv2d_50_bias_array;   /* Array #145 */
AI_STATIC ai_array conv2d_52_weights_array;   /* Array #146 */
AI_STATIC ai_array conv2d_52_bias_array;   /* Array #147 */
AI_STATIC ai_array conv2d_54_weights_array;   /* Array #148 */
AI_STATIC ai_array conv2d_54_bias_array;   /* Array #149 */
AI_STATIC ai_array conv2d_55_weights_array;   /* Array #150 */
AI_STATIC ai_array conv2d_55_bias_array;   /* Array #151 */
AI_STATIC ai_array conv2d_56_weights_array;   /* Array #152 */
AI_STATIC ai_array conv2d_56_bias_array;   /* Array #153 */
AI_STATIC ai_array conv2d_57_weights_array;   /* Array #154 */
AI_STATIC ai_array conv2d_57_bias_array;   /* Array #155 */
AI_STATIC ai_array conv2d_58_weights_array;   /* Array #156 */
AI_STATIC ai_array conv2d_58_bias_array;   /* Array #157 */
AI_STATIC ai_array conv2d_60_weights_array;   /* Array #158 */
AI_STATIC ai_array conv2d_60_bias_array;   /* Array #159 */
AI_STATIC ai_array conv2d_61_weights_array;   /* Array #160 */
AI_STATIC ai_array conv2d_61_bias_array;   /* Array #161 */
AI_STATIC ai_array conv2d_62_weights_array;   /* Array #162 */
AI_STATIC ai_array conv2d_62_bias_array;   /* Array #163 */
AI_STATIC ai_array conv2d_64_weights_array;   /* Array #164 */
AI_STATIC ai_array conv2d_64_bias_array;   /* Array #165 */
AI_STATIC ai_array conv2d_65_weights_array;   /* Array #166 */
AI_STATIC ai_array conv2d_65_bias_array;   /* Array #167 */
AI_STATIC ai_array conv2d_66_weights_array;   /* Array #168 */
AI_STATIC ai_array conv2d_66_bias_array;   /* Array #169 */
AI_STATIC ai_array conv2d_67_weights_array;   /* Array #170 */
AI_STATIC ai_array conv2d_67_bias_array;   /* Array #171 */
AI_STATIC ai_array dense_69_weights_array;   /* Array #172 */
AI_STATIC ai_array dense_69_bias_array;   /* Array #173 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #174 */
AI_STATIC ai_array conv2d_2_scratch1_array;   /* Array #175 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #176 */
AI_STATIC ai_array conv2d_3_scratch1_array;   /* Array #177 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #178 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #179 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #180 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #181 */
AI_STATIC ai_array conv2d_7_scratch1_array;   /* Array #182 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #183 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #184 */
AI_STATIC ai_array conv2d_9_scratch1_array;   /* Array #185 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #186 */
AI_STATIC ai_array conv2d_10_scratch1_array;   /* Array #187 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #188 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #189 */
AI_STATIC ai_array conv2d_13_scratch1_array;   /* Array #190 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #191 */
AI_STATIC ai_array conv2d_15_scratch1_array;   /* Array #192 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #193 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #194 */
AI_STATIC ai_array conv2d_17_scratch1_array;   /* Array #195 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #196 */
AI_STATIC ai_array conv2d_18_scratch1_array;   /* Array #197 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #198 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #199 */
AI_STATIC ai_array conv2d_21_scratch1_array;   /* Array #200 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #201 */
AI_STATIC ai_array conv2d_22_scratch1_array;   /* Array #202 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #203 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #204 */
AI_STATIC ai_array conv2d_25_scratch1_array;   /* Array #205 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #206 */
AI_STATIC ai_array conv2d_27_scratch1_array;   /* Array #207 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #208 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #209 */
AI_STATIC ai_array conv2d_29_scratch1_array;   /* Array #210 */
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #211 */
AI_STATIC ai_array conv2d_30_scratch1_array;   /* Array #212 */
AI_STATIC ai_array conv2d_31_scratch0_array;   /* Array #213 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #214 */
AI_STATIC ai_array conv2d_33_scratch1_array;   /* Array #215 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #216 */
AI_STATIC ai_array conv2d_34_scratch1_array;   /* Array #217 */
AI_STATIC ai_array conv2d_35_scratch0_array;   /* Array #218 */
AI_STATIC ai_array conv2d_37_scratch0_array;   /* Array #219 */
AI_STATIC ai_array conv2d_37_scratch1_array;   /* Array #220 */
AI_STATIC ai_array conv2d_38_scratch0_array;   /* Array #221 */
AI_STATIC ai_array conv2d_38_scratch1_array;   /* Array #222 */
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #223 */
AI_STATIC ai_array conv2d_41_scratch0_array;   /* Array #224 */
AI_STATIC ai_array conv2d_41_scratch1_array;   /* Array #225 */
AI_STATIC ai_array conv2d_42_scratch0_array;   /* Array #226 */
AI_STATIC ai_array conv2d_42_scratch1_array;   /* Array #227 */
AI_STATIC ai_array conv2d_43_scratch0_array;   /* Array #228 */
AI_STATIC ai_array conv2d_44_scratch0_array;   /* Array #229 */
AI_STATIC ai_array conv2d_44_scratch1_array;   /* Array #230 */
AI_STATIC ai_array conv2d_45_scratch0_array;   /* Array #231 */
AI_STATIC ai_array conv2d_45_scratch1_array;   /* Array #232 */
AI_STATIC ai_array conv2d_46_scratch0_array;   /* Array #233 */
AI_STATIC ai_array conv2d_48_scratch0_array;   /* Array #234 */
AI_STATIC ai_array conv2d_48_scratch1_array;   /* Array #235 */
AI_STATIC ai_array conv2d_49_scratch0_array;   /* Array #236 */
AI_STATIC ai_array conv2d_49_scratch1_array;   /* Array #237 */
AI_STATIC ai_array conv2d_50_scratch0_array;   /* Array #238 */
AI_STATIC ai_array conv2d_52_scratch0_array;   /* Array #239 */
AI_STATIC ai_array conv2d_52_scratch1_array;   /* Array #240 */
AI_STATIC ai_array conv2d_54_scratch0_array;   /* Array #241 */
AI_STATIC ai_array conv2d_54_scratch1_array;   /* Array #242 */
AI_STATIC ai_array conv2d_55_scratch0_array;   /* Array #243 */
AI_STATIC ai_array conv2d_56_scratch0_array;   /* Array #244 */
AI_STATIC ai_array conv2d_56_scratch1_array;   /* Array #245 */
AI_STATIC ai_array conv2d_57_scratch0_array;   /* Array #246 */
AI_STATIC ai_array conv2d_57_scratch1_array;   /* Array #247 */
AI_STATIC ai_array conv2d_58_scratch0_array;   /* Array #248 */
AI_STATIC ai_array conv2d_60_scratch0_array;   /* Array #249 */
AI_STATIC ai_array conv2d_60_scratch1_array;   /* Array #250 */
AI_STATIC ai_array conv2d_61_scratch0_array;   /* Array #251 */
AI_STATIC ai_array conv2d_61_scratch1_array;   /* Array #252 */
AI_STATIC ai_array conv2d_62_scratch0_array;   /* Array #253 */
AI_STATIC ai_array conv2d_64_scratch0_array;   /* Array #254 */
AI_STATIC ai_array conv2d_64_scratch1_array;   /* Array #255 */
AI_STATIC ai_array conv2d_65_scratch0_array;   /* Array #256 */
AI_STATIC ai_array conv2d_65_scratch1_array;   /* Array #257 */
AI_STATIC ai_array conv2d_66_scratch0_array;   /* Array #258 */
AI_STATIC ai_array conv2d_67_scratch0_array;   /* Array #259 */
AI_STATIC ai_array conv2d_67_scratch1_array;   /* Array #260 */
AI_STATIC ai_array conv2d_67_scratch2_array;   /* Array #261 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor input_1_output;   /* Tensor #0 */
AI_STATIC ai_tensor conversion_0_output;   /* Tensor #1 */
AI_STATIC ai_tensor conv2d_2_output;   /* Tensor #2 */
AI_STATIC ai_tensor conv2d_3_output;   /* Tensor #3 */
AI_STATIC ai_tensor conv2d_4_output;   /* Tensor #4 */
AI_STATIC ai_tensor conv2d_5_output;   /* Tensor #5 */
AI_STATIC ai_tensor conv2d_7_output;   /* Tensor #6 */
AI_STATIC ai_tensor conv2d_8_output;   /* Tensor #7 */
AI_STATIC ai_tensor conv2d_9_output;   /* Tensor #8 */
AI_STATIC ai_tensor conv2d_10_output;   /* Tensor #9 */
AI_STATIC ai_tensor conv2d_11_output;   /* Tensor #10 */
AI_STATIC ai_tensor eltwise_12_output;   /* Tensor #11 */
AI_STATIC ai_tensor conv2d_13_output;   /* Tensor #12 */
AI_STATIC ai_tensor conv2d_15_output;   /* Tensor #13 */
AI_STATIC ai_tensor conv2d_16_output;   /* Tensor #14 */
AI_STATIC ai_tensor conv2d_17_output;   /* Tensor #15 */
AI_STATIC ai_tensor conv2d_18_output;   /* Tensor #16 */
AI_STATIC ai_tensor conv2d_19_output;   /* Tensor #17 */
AI_STATIC ai_tensor eltwise_20_output;   /* Tensor #18 */
AI_STATIC ai_tensor conv2d_21_output;   /* Tensor #19 */
AI_STATIC ai_tensor conv2d_22_output;   /* Tensor #20 */
AI_STATIC ai_tensor conv2d_23_output;   /* Tensor #21 */
AI_STATIC ai_tensor eltwise_24_output;   /* Tensor #22 */
AI_STATIC ai_tensor conv2d_25_output;   /* Tensor #23 */
AI_STATIC ai_tensor conv2d_27_output;   /* Tensor #24 */
AI_STATIC ai_tensor conv2d_28_output;   /* Tensor #25 */
AI_STATIC ai_tensor conv2d_29_output;   /* Tensor #26 */
AI_STATIC ai_tensor conv2d_30_output;   /* Tensor #27 */
AI_STATIC ai_tensor conv2d_31_output;   /* Tensor #28 */
AI_STATIC ai_tensor eltwise_32_output;   /* Tensor #29 */
AI_STATIC ai_tensor conv2d_33_output;   /* Tensor #30 */
AI_STATIC ai_tensor conv2d_34_output;   /* Tensor #31 */
AI_STATIC ai_tensor conv2d_35_output;   /* Tensor #32 */
AI_STATIC ai_tensor eltwise_36_output;   /* Tensor #33 */
AI_STATIC ai_tensor conv2d_37_output;   /* Tensor #34 */
AI_STATIC ai_tensor conv2d_38_output;   /* Tensor #35 */
AI_STATIC ai_tensor conv2d_39_output;   /* Tensor #36 */
AI_STATIC ai_tensor eltwise_40_output;   /* Tensor #37 */
AI_STATIC ai_tensor conv2d_41_output;   /* Tensor #38 */
AI_STATIC ai_tensor conv2d_42_output;   /* Tensor #39 */
AI_STATIC ai_tensor conv2d_43_output;   /* Tensor #40 */
AI_STATIC ai_tensor conv2d_44_output;   /* Tensor #41 */
AI_STATIC ai_tensor conv2d_45_output;   /* Tensor #42 */
AI_STATIC ai_tensor conv2d_46_output;   /* Tensor #43 */
AI_STATIC ai_tensor eltwise_47_output;   /* Tensor #44 */
AI_STATIC ai_tensor conv2d_48_output;   /* Tensor #45 */
AI_STATIC ai_tensor conv2d_49_output;   /* Tensor #46 */
AI_STATIC ai_tensor conv2d_50_output;   /* Tensor #47 */
AI_STATIC ai_tensor eltwise_51_output;   /* Tensor #48 */
AI_STATIC ai_tensor conv2d_52_output;   /* Tensor #49 */
AI_STATIC ai_tensor conv2d_54_output;   /* Tensor #50 */
AI_STATIC ai_tensor conv2d_55_output;   /* Tensor #51 */
AI_STATIC ai_tensor conv2d_56_output;   /* Tensor #52 */
AI_STATIC ai_tensor conv2d_57_output;   /* Tensor #53 */
AI_STATIC ai_tensor conv2d_58_output;   /* Tensor #54 */
AI_STATIC ai_tensor eltwise_59_output;   /* Tensor #55 */
AI_STATIC ai_tensor conv2d_60_output;   /* Tensor #56 */
AI_STATIC ai_tensor conv2d_61_output;   /* Tensor #57 */
AI_STATIC ai_tensor conv2d_62_output;   /* Tensor #58 */
AI_STATIC ai_tensor eltwise_63_output;   /* Tensor #59 */
AI_STATIC ai_tensor conv2d_64_output;   /* Tensor #60 */
AI_STATIC ai_tensor conv2d_65_output;   /* Tensor #61 */
AI_STATIC ai_tensor conv2d_66_output;   /* Tensor #62 */
AI_STATIC ai_tensor conv2d_67_output;   /* Tensor #63 */
AI_STATIC ai_tensor dense_69_output;   /* Tensor #64 */
AI_STATIC ai_tensor dense_69_fmt_output;   /* Tensor #65 */
AI_STATIC ai_tensor nl_70_output;   /* Tensor #66 */
AI_STATIC ai_tensor nl_70_fmt_output;   /* Tensor #67 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_31_weights;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_31_bias;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #116 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #118 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_35_weights;   /* Tensor #120 */
AI_STATIC ai_tensor conv2d_35_bias;   /* Tensor #121 */
AI_STATIC ai_tensor conv2d_37_weights;   /* Tensor #122 */
AI_STATIC ai_tensor conv2d_37_bias;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_38_weights;   /* Tensor #124 */
AI_STATIC ai_tensor conv2d_38_bias;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #126 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #127 */
AI_STATIC ai_tensor conv2d_41_weights;   /* Tensor #128 */
AI_STATIC ai_tensor conv2d_41_bias;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_42_weights;   /* Tensor #130 */
AI_STATIC ai_tensor conv2d_42_bias;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_43_weights;   /* Tensor #132 */
AI_STATIC ai_tensor conv2d_43_bias;   /* Tensor #133 */
AI_STATIC ai_tensor conv2d_44_weights;   /* Tensor #134 */
AI_STATIC ai_tensor conv2d_44_bias;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_45_weights;   /* Tensor #136 */
AI_STATIC ai_tensor conv2d_45_bias;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_46_weights;   /* Tensor #138 */
AI_STATIC ai_tensor conv2d_46_bias;   /* Tensor #139 */
AI_STATIC ai_tensor conv2d_48_weights;   /* Tensor #140 */
AI_STATIC ai_tensor conv2d_48_bias;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_49_weights;   /* Tensor #142 */
AI_STATIC ai_tensor conv2d_49_bias;   /* Tensor #143 */
AI_STATIC ai_tensor conv2d_50_weights;   /* Tensor #144 */
AI_STATIC ai_tensor conv2d_50_bias;   /* Tensor #145 */
AI_STATIC ai_tensor conv2d_52_weights;   /* Tensor #146 */
AI_STATIC ai_tensor conv2d_52_bias;   /* Tensor #147 */
AI_STATIC ai_tensor conv2d_54_weights;   /* Tensor #148 */
AI_STATIC ai_tensor conv2d_54_bias;   /* Tensor #149 */
AI_STATIC ai_tensor conv2d_55_weights;   /* Tensor #150 */
AI_STATIC ai_tensor conv2d_55_bias;   /* Tensor #151 */
AI_STATIC ai_tensor conv2d_56_weights;   /* Tensor #152 */
AI_STATIC ai_tensor conv2d_56_bias;   /* Tensor #153 */
AI_STATIC ai_tensor conv2d_57_weights;   /* Tensor #154 */
AI_STATIC ai_tensor conv2d_57_bias;   /* Tensor #155 */
AI_STATIC ai_tensor conv2d_58_weights;   /* Tensor #156 */
AI_STATIC ai_tensor conv2d_58_bias;   /* Tensor #157 */
AI_STATIC ai_tensor conv2d_60_weights;   /* Tensor #158 */
AI_STATIC ai_tensor conv2d_60_bias;   /* Tensor #159 */
AI_STATIC ai_tensor conv2d_61_weights;   /* Tensor #160 */
AI_STATIC ai_tensor conv2d_61_bias;   /* Tensor #161 */
AI_STATIC ai_tensor conv2d_62_weights;   /* Tensor #162 */
AI_STATIC ai_tensor conv2d_62_bias;   /* Tensor #163 */
AI_STATIC ai_tensor conv2d_64_weights;   /* Tensor #164 */
AI_STATIC ai_tensor conv2d_64_bias;   /* Tensor #165 */
AI_STATIC ai_tensor conv2d_65_weights;   /* Tensor #166 */
AI_STATIC ai_tensor conv2d_65_bias;   /* Tensor #167 */
AI_STATIC ai_tensor conv2d_66_weights;   /* Tensor #168 */
AI_STATIC ai_tensor conv2d_66_bias;   /* Tensor #169 */
AI_STATIC ai_tensor conv2d_67_weights;   /* Tensor #170 */
AI_STATIC ai_tensor conv2d_67_bias;   /* Tensor #171 */
AI_STATIC ai_tensor dense_69_weights;   /* Tensor #172 */
AI_STATIC ai_tensor dense_69_bias;   /* Tensor #173 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #174 */
AI_STATIC ai_tensor conv2d_2_scratch1;   /* Tensor #175 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #176 */
AI_STATIC ai_tensor conv2d_3_scratch1;   /* Tensor #177 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #178 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #179 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #180 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #181 */
AI_STATIC ai_tensor conv2d_7_scratch1;   /* Tensor #182 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #183 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #184 */
AI_STATIC ai_tensor conv2d_9_scratch1;   /* Tensor #185 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #186 */
AI_STATIC ai_tensor conv2d_10_scratch1;   /* Tensor #187 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #188 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #189 */
AI_STATIC ai_tensor conv2d_13_scratch1;   /* Tensor #190 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #191 */
AI_STATIC ai_tensor conv2d_15_scratch1;   /* Tensor #192 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #193 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #194 */
AI_STATIC ai_tensor conv2d_17_scratch1;   /* Tensor #195 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #196 */
AI_STATIC ai_tensor conv2d_18_scratch1;   /* Tensor #197 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #198 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #199 */
AI_STATIC ai_tensor conv2d_21_scratch1;   /* Tensor #200 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #201 */
AI_STATIC ai_tensor conv2d_22_scratch1;   /* Tensor #202 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #203 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #204 */
AI_STATIC ai_tensor conv2d_25_scratch1;   /* Tensor #205 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #206 */
AI_STATIC ai_tensor conv2d_27_scratch1;   /* Tensor #207 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #208 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #209 */
AI_STATIC ai_tensor conv2d_29_scratch1;   /* Tensor #210 */
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #211 */
AI_STATIC ai_tensor conv2d_30_scratch1;   /* Tensor #212 */
AI_STATIC ai_tensor conv2d_31_scratch0;   /* Tensor #213 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #214 */
AI_STATIC ai_tensor conv2d_33_scratch1;   /* Tensor #215 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #216 */
AI_STATIC ai_tensor conv2d_34_scratch1;   /* Tensor #217 */
AI_STATIC ai_tensor conv2d_35_scratch0;   /* Tensor #218 */
AI_STATIC ai_tensor conv2d_37_scratch0;   /* Tensor #219 */
AI_STATIC ai_tensor conv2d_37_scratch1;   /* Tensor #220 */
AI_STATIC ai_tensor conv2d_38_scratch0;   /* Tensor #221 */
AI_STATIC ai_tensor conv2d_38_scratch1;   /* Tensor #222 */
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #223 */
AI_STATIC ai_tensor conv2d_41_scratch0;   /* Tensor #224 */
AI_STATIC ai_tensor conv2d_41_scratch1;   /* Tensor #225 */
AI_STATIC ai_tensor conv2d_42_scratch0;   /* Tensor #226 */
AI_STATIC ai_tensor conv2d_42_scratch1;   /* Tensor #227 */
AI_STATIC ai_tensor conv2d_43_scratch0;   /* Tensor #228 */
AI_STATIC ai_tensor conv2d_44_scratch0;   /* Tensor #229 */
AI_STATIC ai_tensor conv2d_44_scratch1;   /* Tensor #230 */
AI_STATIC ai_tensor conv2d_45_scratch0;   /* Tensor #231 */
AI_STATIC ai_tensor conv2d_45_scratch1;   /* Tensor #232 */
AI_STATIC ai_tensor conv2d_46_scratch0;   /* Tensor #233 */
AI_STATIC ai_tensor conv2d_48_scratch0;   /* Tensor #234 */
AI_STATIC ai_tensor conv2d_48_scratch1;   /* Tensor #235 */
AI_STATIC ai_tensor conv2d_49_scratch0;   /* Tensor #236 */
AI_STATIC ai_tensor conv2d_49_scratch1;   /* Tensor #237 */
AI_STATIC ai_tensor conv2d_50_scratch0;   /* Tensor #238 */
AI_STATIC ai_tensor conv2d_52_scratch0;   /* Tensor #239 */
AI_STATIC ai_tensor conv2d_52_scratch1;   /* Tensor #240 */
AI_STATIC ai_tensor conv2d_54_scratch0;   /* Tensor #241 */
AI_STATIC ai_tensor conv2d_54_scratch1;   /* Tensor #242 */
AI_STATIC ai_tensor conv2d_55_scratch0;   /* Tensor #243 */
AI_STATIC ai_tensor conv2d_56_scratch0;   /* Tensor #244 */
AI_STATIC ai_tensor conv2d_56_scratch1;   /* Tensor #245 */
AI_STATIC ai_tensor conv2d_57_scratch0;   /* Tensor #246 */
AI_STATIC ai_tensor conv2d_57_scratch1;   /* Tensor #247 */
AI_STATIC ai_tensor conv2d_58_scratch0;   /* Tensor #248 */
AI_STATIC ai_tensor conv2d_60_scratch0;   /* Tensor #249 */
AI_STATIC ai_tensor conv2d_60_scratch1;   /* Tensor #250 */
AI_STATIC ai_tensor conv2d_61_scratch0;   /* Tensor #251 */
AI_STATIC ai_tensor conv2d_61_scratch1;   /* Tensor #252 */
AI_STATIC ai_tensor conv2d_62_scratch0;   /* Tensor #253 */
AI_STATIC ai_tensor conv2d_64_scratch0;   /* Tensor #254 */
AI_STATIC ai_tensor conv2d_64_scratch1;   /* Tensor #255 */
AI_STATIC ai_tensor conv2d_65_scratch0;   /* Tensor #256 */
AI_STATIC ai_tensor conv2d_65_scratch1;   /* Tensor #257 */
AI_STATIC ai_tensor conv2d_66_scratch0;   /* Tensor #258 */
AI_STATIC ai_tensor conv2d_67_scratch0;   /* Tensor #259 */
AI_STATIC ai_tensor conv2d_67_scratch1;   /* Tensor #260 */
AI_STATIC ai_tensor conv2d_67_scratch2;   /* Tensor #261 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain conversion_0_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain conv2d_2_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain conv2d_3_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain conv2d_4_chain;   /* Chain #3 */
AI_STATIC_CONST ai_tensor_chain conv2d_5_chain;   /* Chain #4 */
AI_STATIC_CONST ai_tensor_chain conv2d_7_chain;   /* Chain #5 */
AI_STATIC_CONST ai_tensor_chain conv2d_8_chain;   /* Chain #6 */
AI_STATIC_CONST ai_tensor_chain conv2d_9_chain;   /* Chain #7 */
AI_STATIC_CONST ai_tensor_chain conv2d_10_chain;   /* Chain #8 */
AI_STATIC_CONST ai_tensor_chain conv2d_11_chain;   /* Chain #9 */
AI_STATIC_CONST ai_tensor_chain eltwise_12_chain;   /* Chain #10 */
AI_STATIC_CONST ai_tensor_chain conv2d_13_chain;   /* Chain #11 */
AI_STATIC_CONST ai_tensor_chain conv2d_15_chain;   /* Chain #12 */
AI_STATIC_CONST ai_tensor_chain conv2d_16_chain;   /* Chain #13 */
AI_STATIC_CONST ai_tensor_chain conv2d_17_chain;   /* Chain #14 */
AI_STATIC_CONST ai_tensor_chain conv2d_18_chain;   /* Chain #15 */
AI_STATIC_CONST ai_tensor_chain conv2d_19_chain;   /* Chain #16 */
AI_STATIC_CONST ai_tensor_chain eltwise_20_chain;   /* Chain #17 */
AI_STATIC_CONST ai_tensor_chain conv2d_21_chain;   /* Chain #18 */
AI_STATIC_CONST ai_tensor_chain conv2d_22_chain;   /* Chain #19 */
AI_STATIC_CONST ai_tensor_chain conv2d_23_chain;   /* Chain #20 */
AI_STATIC_CONST ai_tensor_chain eltwise_24_chain;   /* Chain #21 */
AI_STATIC_CONST ai_tensor_chain conv2d_25_chain;   /* Chain #22 */
AI_STATIC_CONST ai_tensor_chain conv2d_27_chain;   /* Chain #23 */
AI_STATIC_CONST ai_tensor_chain conv2d_28_chain;   /* Chain #24 */
AI_STATIC_CONST ai_tensor_chain conv2d_29_chain;   /* Chain #25 */
AI_STATIC_CONST ai_tensor_chain conv2d_30_chain;   /* Chain #26 */
AI_STATIC_CONST ai_tensor_chain conv2d_31_chain;   /* Chain #27 */
AI_STATIC_CONST ai_tensor_chain eltwise_32_chain;   /* Chain #28 */
AI_STATIC_CONST ai_tensor_chain conv2d_33_chain;   /* Chain #29 */
AI_STATIC_CONST ai_tensor_chain conv2d_34_chain;   /* Chain #30 */
AI_STATIC_CONST ai_tensor_chain conv2d_35_chain;   /* Chain #31 */
AI_STATIC_CONST ai_tensor_chain eltwise_36_chain;   /* Chain #32 */
AI_STATIC_CONST ai_tensor_chain conv2d_37_chain;   /* Chain #33 */
AI_STATIC_CONST ai_tensor_chain conv2d_38_chain;   /* Chain #34 */
AI_STATIC_CONST ai_tensor_chain conv2d_39_chain;   /* Chain #35 */
AI_STATIC_CONST ai_tensor_chain eltwise_40_chain;   /* Chain #36 */
AI_STATIC_CONST ai_tensor_chain conv2d_41_chain;   /* Chain #37 */
AI_STATIC_CONST ai_tensor_chain conv2d_42_chain;   /* Chain #38 */
AI_STATIC_CONST ai_tensor_chain conv2d_43_chain;   /* Chain #39 */
AI_STATIC_CONST ai_tensor_chain conv2d_44_chain;   /* Chain #40 */
AI_STATIC_CONST ai_tensor_chain conv2d_45_chain;   /* Chain #41 */
AI_STATIC_CONST ai_tensor_chain conv2d_46_chain;   /* Chain #42 */
AI_STATIC_CONST ai_tensor_chain eltwise_47_chain;   /* Chain #43 */
AI_STATIC_CONST ai_tensor_chain conv2d_48_chain;   /* Chain #44 */
AI_STATIC_CONST ai_tensor_chain conv2d_49_chain;   /* Chain #45 */
AI_STATIC_CONST ai_tensor_chain conv2d_50_chain;   /* Chain #46 */
AI_STATIC_CONST ai_tensor_chain eltwise_51_chain;   /* Chain #47 */
AI_STATIC_CONST ai_tensor_chain conv2d_52_chain;   /* Chain #48 */
AI_STATIC_CONST ai_tensor_chain conv2d_54_chain;   /* Chain #49 */
AI_STATIC_CONST ai_tensor_chain conv2d_55_chain;   /* Chain #50 */
AI_STATIC_CONST ai_tensor_chain conv2d_56_chain;   /* Chain #51 */
AI_STATIC_CONST ai_tensor_chain conv2d_57_chain;   /* Chain #52 */
AI_STATIC_CONST ai_tensor_chain conv2d_58_chain;   /* Chain #53 */
AI_STATIC_CONST ai_tensor_chain eltwise_59_chain;   /* Chain #54 */
AI_STATIC_CONST ai_tensor_chain conv2d_60_chain;   /* Chain #55 */
AI_STATIC_CONST ai_tensor_chain conv2d_61_chain;   /* Chain #56 */
AI_STATIC_CONST ai_tensor_chain conv2d_62_chain;   /* Chain #57 */
AI_STATIC_CONST ai_tensor_chain eltwise_63_chain;   /* Chain #58 */
AI_STATIC_CONST ai_tensor_chain conv2d_64_chain;   /* Chain #59 */
AI_STATIC_CONST ai_tensor_chain conv2d_65_chain;   /* Chain #60 */
AI_STATIC_CONST ai_tensor_chain conv2d_66_chain;   /* Chain #61 */
AI_STATIC_CONST ai_tensor_chain conv2d_67_chain;   /* Chain #62 */
AI_STATIC_CONST ai_tensor_chain dense_69_chain;   /* Chain #63 */
AI_STATIC_CONST ai_tensor_chain dense_69_fmt_chain;   /* Chain #64 */
AI_STATIC_CONST ai_tensor_chain nl_70_chain;   /* Chain #65 */
AI_STATIC_CONST ai_tensor_chain nl_70_fmt_chain;   /* Chain #66 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_nl conversion_0_layer; /* Layer #0 */
AI_STATIC ai_layer_conv2d conv2d_2_layer; /* Layer #1 */
AI_STATIC ai_layer_conv2d conv2d_3_layer; /* Layer #2 */
AI_STATIC ai_layer_conv2d conv2d_4_layer; /* Layer #3 */
AI_STATIC ai_layer_conv2d conv2d_5_layer; /* Layer #4 */
AI_STATIC ai_layer_conv2d conv2d_7_layer; /* Layer #5 */
AI_STATIC ai_layer_conv2d conv2d_8_layer; /* Layer #6 */
AI_STATIC ai_layer_conv2d conv2d_9_layer; /* Layer #7 */
AI_STATIC ai_layer_conv2d conv2d_10_layer; /* Layer #8 */
AI_STATIC ai_layer_conv2d conv2d_11_layer; /* Layer #9 */
AI_STATIC ai_layer_eltwise_integer eltwise_12_layer; /* Layer #10 */
AI_STATIC ai_layer_conv2d conv2d_13_layer; /* Layer #11 */
AI_STATIC ai_layer_conv2d conv2d_15_layer; /* Layer #12 */
AI_STATIC ai_layer_conv2d conv2d_16_layer; /* Layer #13 */
AI_STATIC ai_layer_conv2d conv2d_17_layer; /* Layer #14 */
AI_STATIC ai_layer_conv2d conv2d_18_layer; /* Layer #15 */
AI_STATIC ai_layer_conv2d conv2d_19_layer; /* Layer #16 */
AI_STATIC ai_layer_eltwise_integer eltwise_20_layer; /* Layer #17 */
AI_STATIC ai_layer_conv2d conv2d_21_layer; /* Layer #18 */
AI_STATIC ai_layer_conv2d conv2d_22_layer; /* Layer #19 */
AI_STATIC ai_layer_conv2d conv2d_23_layer; /* Layer #20 */
AI_STATIC ai_layer_eltwise_integer eltwise_24_layer; /* Layer #21 */
AI_STATIC ai_layer_conv2d conv2d_25_layer; /* Layer #22 */
AI_STATIC ai_layer_conv2d conv2d_27_layer; /* Layer #23 */
AI_STATIC ai_layer_conv2d conv2d_28_layer; /* Layer #24 */
AI_STATIC ai_layer_conv2d conv2d_29_layer; /* Layer #25 */
AI_STATIC ai_layer_conv2d conv2d_30_layer; /* Layer #26 */
AI_STATIC ai_layer_conv2d conv2d_31_layer; /* Layer #27 */
AI_STATIC ai_layer_eltwise_integer eltwise_32_layer; /* Layer #28 */
AI_STATIC ai_layer_conv2d conv2d_33_layer; /* Layer #29 */
AI_STATIC ai_layer_conv2d conv2d_34_layer; /* Layer #30 */
AI_STATIC ai_layer_conv2d conv2d_35_layer; /* Layer #31 */
AI_STATIC ai_layer_eltwise_integer eltwise_36_layer; /* Layer #32 */
AI_STATIC ai_layer_conv2d conv2d_37_layer; /* Layer #33 */
AI_STATIC ai_layer_conv2d conv2d_38_layer; /* Layer #34 */
AI_STATIC ai_layer_conv2d conv2d_39_layer; /* Layer #35 */
AI_STATIC ai_layer_eltwise_integer eltwise_40_layer; /* Layer #36 */
AI_STATIC ai_layer_conv2d conv2d_41_layer; /* Layer #37 */
AI_STATIC ai_layer_conv2d conv2d_42_layer; /* Layer #38 */
AI_STATIC ai_layer_conv2d conv2d_43_layer; /* Layer #39 */
AI_STATIC ai_layer_conv2d conv2d_44_layer; /* Layer #40 */
AI_STATIC ai_layer_conv2d conv2d_45_layer; /* Layer #41 */
AI_STATIC ai_layer_conv2d conv2d_46_layer; /* Layer #42 */
AI_STATIC ai_layer_eltwise_integer eltwise_47_layer; /* Layer #43 */
AI_STATIC ai_layer_conv2d conv2d_48_layer; /* Layer #44 */
AI_STATIC ai_layer_conv2d conv2d_49_layer; /* Layer #45 */
AI_STATIC ai_layer_conv2d conv2d_50_layer; /* Layer #46 */
AI_STATIC ai_layer_eltwise_integer eltwise_51_layer; /* Layer #47 */
AI_STATIC ai_layer_conv2d conv2d_52_layer; /* Layer #48 */
AI_STATIC ai_layer_conv2d conv2d_54_layer; /* Layer #49 */
AI_STATIC ai_layer_conv2d conv2d_55_layer; /* Layer #50 */
AI_STATIC ai_layer_conv2d conv2d_56_layer; /* Layer #51 */
AI_STATIC ai_layer_conv2d conv2d_57_layer; /* Layer #52 */
AI_STATIC ai_layer_conv2d conv2d_58_layer; /* Layer #53 */
AI_STATIC ai_layer_eltwise_integer eltwise_59_layer; /* Layer #54 */
AI_STATIC ai_layer_conv2d conv2d_60_layer; /* Layer #55 */
AI_STATIC ai_layer_conv2d conv2d_61_layer; /* Layer #56 */
AI_STATIC ai_layer_conv2d conv2d_62_layer; /* Layer #57 */
AI_STATIC ai_layer_eltwise_integer eltwise_63_layer; /* Layer #58 */
AI_STATIC ai_layer_conv2d conv2d_64_layer; /* Layer #59 */
AI_STATIC ai_layer_conv2d conv2d_65_layer; /* Layer #60 */
AI_STATIC ai_layer_conv2d conv2d_66_layer; /* Layer #61 */
AI_STATIC ai_layer_conv2d_nl_pool conv2d_67_layer; /* Layer #62 */
AI_STATIC ai_layer_dense dense_69_layer; /* Layer #63 */
AI_STATIC ai_layer_nl dense_69_fmt_layer; /* Layer #64 */
AI_STATIC ai_layer_nl nl_70_layer; /* Layer #65 */
AI_STATIC ai_layer_nl nl_70_fmt_layer; /* Layer #66 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  input_1_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 49152, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 32768, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 196608, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 8192, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4096, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_40_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_59_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_63_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1792, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  nl_70_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 2, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  nl_70_fmt_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 2, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 112, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 143360, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1280, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2560, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 2, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 65536, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 196608, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 49152, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 24576, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9216, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12288, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3072, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1328, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5376, AI_STATIC)

/* Array#258 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2464, AI_STATIC)

/* Array#259 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13248, AI_STATIC)

/* Array#260 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20480, AI_STATIC)

/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 20480, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(input_1_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_UINTQ_ZP(127)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007843137718737125f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #2 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #3 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #4 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5705738067626953f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #5 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #6 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #7 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4759727716445923f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #8 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #9 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #10 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.8294548392295837f),
    AI_PACK_INTQ_ZP(-5)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.734648585319519f),
    AI_PACK_INTQ_ZP(-13)))

/* Int quant #12 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #13 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3818996548652649f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #15 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #16 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #17 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3572128713130951f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.498079776763916f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #19 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #20 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #21 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4580155909061432f),
    AI_PACK_INTQ_ZP(17)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.7089322805404663f),
    AI_PACK_INTQ_ZP(26)))

/* Int quant #23 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #24 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #25 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3693316876888275f),
    AI_PACK_INTQ_ZP(4)))

/* Int quant #26 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #27 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #28 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2706504762172699f),
    AI_PACK_INTQ_ZP(-10)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.37354767322540283f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #30 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #31 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #32 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.27479517459869385f),
    AI_PACK_INTQ_ZP(-2)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.37573742866516113f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #34 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #35 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #36 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2522790729999542f),
    AI_PACK_INTQ_ZP(29)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_40_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.4005011022090912f),
    AI_PACK_INTQ_ZP(3)))

/* Int quant #38 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #39 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #40 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.29278719425201416f),
    AI_PACK_INTQ_ZP(-12)))

/* Int quant #41 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #42 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #43 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3683943748474121f),
    AI_PACK_INTQ_ZP(41)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.41954195499420166f),
    AI_PACK_INTQ_ZP(17)))

/* Int quant #45 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #46 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #47 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.36761030554771423f),
    AI_PACK_INTQ_ZP(-36)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_51_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.5106605887413025f),
    AI_PACK_INTQ_ZP(-24)))

/* Int quant #49 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #50 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #51 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2469666600227356f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #52 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #53 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22917312383651733f),
    AI_PACK_INTQ_ZP(-8)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_59_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.26822325587272644f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #56 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #57 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.31024977564811707f),
    AI_PACK_INTQ_ZP(8)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_63_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3804317116737366f),
    AI_PACK_INTQ_ZP(15)))

/* Int quant #60 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #61 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #62 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18772302567958832f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023529410362243652f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.12574079632759094f),
    AI_PACK_INTQ_ZP(-4)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_70_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005260485224425793f, 0.0069735911674797535f, 0.002776878420263529f, 4.4848346192338795e-07f, 0.0029260986484587193f, 0.0034262039698660374f, 3.6950581261407933e-07f, 3.88419820751551e-08f, 1.696853502153317e-07f, 3.586215413520222e-08f, 4.8799854823755595e-08f, 0.01380513422191143f, 3.7750269576974915e-09f, 1.4805063841549782e-08f, 0.007876191288232803f, 0.025978844612836838f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.125871055293828e-05f, 5.469483585329726e-05f, 2.1779440430691466e-05f, 3.517517610518439e-09f, 2.2949794583837502e-05f, 2.687218875507824e-05f, 2.8980848831849926e-09f, 3.046430052666693e-10f, 1.3308655288923887e-09f, 2.812718113975876e-10f, 3.8274397540227767e-10f, 0.00010827556980075315f, 2.960805559060198e-11f, 1.1611815675660608e-10f, 6.177405157359317e-05f, 0.00020375565509311855f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007659640163183212f, 0.00660337321460247f, 0.009462639689445496f, 0.3139938414096832f, 0.010582462884485722f, 0.0035940653178840876f, 0.06294554471969604f, 0.336553156375885f, 0.6555811762809753f, 0.01133586186915636f, 0.33615633845329285f, 0.005226512439548969f, 0.3032977879047394f, 0.013527749106287956f, 0.0029834769666194916f, 0.00397384213283658f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018022683798335493f, 0.00015537349099759012f, 0.00022265035659074783f, 0.007388090714812279f, 0.00024899913114495575f, 8.456624345853925e-05f, 0.0014810716966167092f, 0.00791889801621437f, 0.015425439924001694f, 0.0002667261578608304f, 0.00790956150740385f, 0.0001229767658514902f, 0.007136418484151363f, 0.0003182999789714813f, 7.019945769570768e-05f, 9.350216714665294e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07725640386343002f, 0.042534708976745605f, 0.10697681456804276f, 0.03932856768369675f, 0.10597014427185059f, 0.038565974682569504f, 0.04650779068470001f, 0.06679973006248474f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001817797776311636f, 0.0010008167009800673f, 0.002517101587727666f, 0.0009253780590370297f, 0.0024934152606874704f, 0.0009074347326532006f, 0.0010943009983748198f, 0.0015717584174126387f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.060597856905048e-11f, 0.0016366151394322515f, 0.001680457149632275f, 0.003011456225067377f, 0.0015260743675753474f, 0.0016622040420770645f, 0.0029258772265166044f, 0.0033671879209578037f, 0.0017292576376348734f, 0.0025368360802531242f, 0.0014043712290003896f, 0.0007739955908618867f, 0.0004802174516953528f, 0.0007554384646937251f, 0.0012351248878985643f, 0.0018411282217130065f, 4.607964565472855e-10f, 0.0008042888366617262f, 0.002504422329366207f, 0.0006310109165497124f, 0.0011379275238141418f, 0.0005442864494398236f, 0.0006780467228963971f, 0.0018153355922549963f, 0.00043556600576266646f, 2.3618834318894777e-11f, 0.001439550775103271f, 0.0013558975188061595f, 0.00047238622209988534f, 0.0007794901030138135f, 0.0016320081194862723f, 0.0016000387258827686f, 1.0120701610105698e-08f, 0.0012087717186659575f, 0.0010118481004610658f, 0.0026543198619037867f, 0.0031844989862293005f, 0.0014326083473861217f, 0.004155407659709454f, 0.0005602948949672282f, 0.0005337328766472638f, 0.0007862251368351281f, 0.0010598598746582866f, 0.0008616609266027808f, 0.0011150139616802335f, 0.0006016513798385859f, 0.0008262929623015225f, 0.0021470729261636734f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(3.458018246749184e-11f, 0.0009338097297586501f, 0.0009588248212821782f, 0.0017182580195367336f, 0.0008707380620762706f, 0.0009484100737608969f, 0.001669428893364966f, 0.001921229180879891f, 0.0009866690961644053f, 0.0014474522322416306f, 0.0008012974285520613f, 0.0004416216106619686f, 0.00027399949613027275f, 0.0004310334043111652f, 0.0007047299295663834f, 0.0010504995007067919f, 2.6291838151060176e-10f, 0.0004589061427395791f, 0.0014289577957242727f, 0.00036003830609843135f, 0.0006492716493085027f, 0.00031055559520609677f, 0.00038687570486217737f, 0.0010357829742133617f, 0.00024852255592122674f, 1.34762877940231e-11f, 0.0008213699911721051f, 0.00077363959280774f, 0.0002695312141440809f, 0.0004447566461749375f, 0.0009311810717917979f, 0.0009129401878453791f, 5.774607458874925e-09f, 0.0006896934937685728f, 0.0005773340235464275f, 0.0015144853387027979f, 0.0018169917166233063f, 0.0008174087852239609f, 0.0023709668312221766f, 0.000319689599564299f, 0.00030453401268459857f, 0.0004485994577407837f, 0.0006047282950021327f, 0.0004916411708109081f, 0.0006361977430060506f, 0.00034328651963733137f, 0.0004714611277449876f, 0.0012250635772943497f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03571036830544472f, 0.021864935755729675f, 0.009196633473038673f, 0.0023634275421500206f, 0.018074890598654747f, 0.0024833406787365675f, 0.001824599108658731f, 0.0010051728459075093f, 0.006230616942048073f, 0.004600648768246174f, 0.007315531373023987f, 0.02218904159963131f, 0.016279181465506554f, 0.004803879652172327f, 0.004985907580703497f, 0.005297538824379444f, 0.0026093546766787767f, 0.010448922403156757f, 0.004445589147508144f, 0.002548537915572524f, 0.029089801013469696f, 0.0073247808031737804f, 0.01527130976319313f, 0.0031557742040604353f, 0.009713328443467617f, 0.008054112084209919f, 0.016630981117486954f, 0.007356366142630577f, 0.00970230158418417f, 0.022557498887181282f, 0.003744166111573577f, 0.00839558057487011f, 0.003999226726591587f, 0.007941392250359058f, 0.0030841263942420483f, 0.004364652559161186f, 0.0017928818706423044f, 0.002677737735211849f, 0.0018877177499234676f, 0.00968290213495493f, 0.010245798155665398f, 0.011381318792700768f, 0.007934152148663998f, 0.008565218187868595f, 0.036822885274887085f, 0.009918252006173134f, 0.011832613497972488f, 0.0095348646864295f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008402439998462796f, 0.0005144691094756126f, 0.00021639137412421405f, 5.561006037169136e-05f, 0.0004252915387041867f, 5.843154576723464e-05f, 4.293174424674362e-05f, 2.3651125957258046e-05f, 0.00014660276065114886f, 0.0001082505623344332f, 0.0001721301523502916f, 0.0005220951279625297f, 0.00038303955807350576f, 0.00011303246719762683f, 0.00011731547419913113f, 0.000124647980555892f, 6.139658216852695e-05f, 0.0002458569942973554f, 0.00010460209887241945f, 5.996559775667265e-05f, 0.0006844659219495952f, 0.00017234779079444706f, 0.00035932494211010635f, 7.425351213896647e-05f, 0.0002285489026689902f, 0.00018950852972920984f, 0.00039131721132434905f, 0.000173090971657075f, 0.00022828945657238364f, 0.0005307646933943033f, 8.809802966425195e-05f, 0.00019754307868424803f, 9.409945778315887e-05f, 0.0001868562976596877f, 7.256768003571779e-05f, 0.00010269771155435592f, 4.218545655021444e-05f, 6.300559471128508e-05f, 4.44168908870779e-05f, 0.00022783299209550023f, 0.0002410776069154963f, 0.00026779575273394585f, 0.0001866859383881092f, 0.00020153455261606723f, 0.0008664208580739796f, 0.00023337063612416387f, 0.0002784144307952374f, 0.00022434975835494697f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02513873763382435f, 0.02116377092897892f, 0.029144829139113426f, 0.026552584022283554f, 0.025743568316102028f, 0.027682870626449585f, 0.03597646951675415f, 0.03406302258372307f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005914997309446335f, 0.0004979710793122649f, 0.0006857606931589544f, 0.0006247666897252202f, 0.000605731038376689f, 0.0006513616535812616f, 0.0008465051651000977f, 0.0008014828781597316f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004727404157165438f, 0.0013478315668180585f, 5.280090253911851e-10f, 0.001237267628312111f, 0.0008931636111810803f, 0.0006152745918370783f, 0.0009582121856510639f, 0.0006433819071389735f, 0.0006551810656674206f, 0.0011164702009409666f, 0.0002702452184166759f, 0.002010724740102887f, 0.00023296591825783253f, 0.002326861023902893f, 0.0011406069388613105f, 0.0005277377786114812f, 0.009718821384012699f, 0.00465425243601203f, 0.00168511678930372f, 0.0006227759295143187f, 0.0008652406395412982f, 0.000857450591865927f, 0.001180061954073608f, 0.004095928277820349f, 0.0007966900593601167f, 0.0016299269627779722f, 0.001256183604709804f, 0.0013328288914635777f, 0.0015662022633478045f, 0.00032449091668240726f, 0.0006128254462964833f, 0.004961239639669657f, 0.0006955676362849772f, 0.0016347584314644337f, 0.0014362463261932135f, 0.0005629942752420902f, 0.0015559217426925898f, 0.0006998251774348319f, 0.0005884256097488105f, 0.0038957626093178988f, 0.0033404361456632614f, 1.0096146835225639e-10f, 0.0006626316462643445f, 0.0005781110958196223f, 0.002320872852578759f, 0.0009576286538504064f, 0.004300259053707123f, 0.0012050374643877149f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00022501156490761787f, 0.0006415311363525689f, 2.5131791092647404e-10f, 0.0005889057065360248f, 0.00042512157233431935f, 0.00029285394703038037f, 0.00045608289656229317f, 0.0003062322793994099f, 0.0003118483582511544f, 0.0005314094014465809f, 0.00012862937001045793f, 0.0009570502443239093f, 0.0001108854339690879f, 0.0011075225193053484f, 0.000542897847481072f, 0.00025118881603702903f, 0.004625894129276276f, 0.0022152974270284176f, 0.0008020697277970612f, 0.000296424375846982f, 0.0004118309880141169f, 0.00040812313091009855f, 0.0005616773851215839f, 0.0019495503511279821f, 0.0003792027710005641f, 0.000775800843257457f, 0.000597909209318459f, 0.0006343902787193656f, 0.0007454696460627019f, 0.00015444884775206447f, 0.00029168822220526636f, 0.0023614149540662766f, 0.0003310712636448443f, 0.0007781005115248263f, 0.0006836141692474484f, 0.0002679699391592294f, 0.0007405763608403504f, 0.0003330977342557162f, 0.0002800745714921504f, 0.0018542769830673933f, 0.0015899566933512688f, 4.8054910745110035e-11f, 0.00031539463088847697f, 0.0002751651336438954f, 0.0011046723229810596f, 0.00045580515870824456f, 0.0020468062721192837f, 0.0005735650192946196f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005797600373625755f, 0.0021302371751517057f, 0.0005142192239873111f, 0.010109822265803814f, 0.005834439769387245f, 0.00715501606464386f, 0.007096100598573685f, 0.004961465485394001f, 0.010488827712833881f, 0.004166458733379841f, 0.008618094958364964f, 0.006220382172614336f, 0.008415225893259048f, 0.004586110357195139f, 0.005431342404335737f, 0.012605681084096432f, 0.0043776012025773525f, 0.0018103265902027488f, 0.006201747339218855f, 0.0029419574420899153f, 0.0027641619089990854f, 0.008549628779292107f, 0.003756282851099968f, 0.006505055818706751f, 0.010236016474664211f, 0.006242702249437571f, 0.001817663200199604f, 0.007450859062373638f, 0.0052757104858756065f, 0.007937575690448284f, 0.0042030042968690395f, 0.0017410404980182648f, 0.008453267626464367f, 0.0038200034759938717f, 0.007774246856570244f, 0.006779293995350599f, 0.0022564388345927f, 0.007774836849421263f, 0.006994485855102539f, 0.002983097918331623f, 0.004870075732469559f, 0.1141076534986496f, 0.005652267951518297f, 0.012256788089871407f, 0.00401133531704545f, 0.00521874288097024f, 0.0013354893308132887f, 0.004338382743299007f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001364141353406012f, 5.0123227993026376e-05f, 1.2099276318622287e-05f, 0.00023787817917764187f, 0.0001372809347230941f, 0.00016835331916809082f, 0.00016696707461960614f, 0.00011674036795739084f, 0.00024679594207555056f, 9.803432476473972e-05f, 0.00020277871226426214f, 0.0001463619410060346f, 0.0001980053202714771f, 0.00010790848318720236f, 0.00012779628741554916f, 0.0002966042666230351f, 0.00010300238500349224f, 4.2595918785082176e-05f, 0.00014592346269637346f, 6.92225294187665e-05f, 6.503910844912753e-05f, 0.0002011677424889058f, 8.838313078740612e-05f, 0.0001530601439299062f, 0.00024084745382424444f, 0.00014688711962662637f, 4.276854815543629e-05f, 0.0001753143296809867f, 0.00012413437070790678f, 0.00018676648323889822f, 9.889421926345676e-05f, 4.0965660446090624e-05f, 0.00019890042312908918f, 8.98824364412576e-05f, 0.0001829234533943236f, 0.0001595127978362143f, 5.3092680900590494e-05f, 0.00018293733592145145f, 0.00016457613673992455f, 7.019053737167269e-05f, 0.00011459001689217985f, 0.0026848861016333103f, 0.0001329945371253416f, 0.0002883950073737651f, 9.438436245545745e-05f, 0.00012279395014047623f, 3.142327841487713e-05f, 0.0001020795971271582f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.02752063050866127f, 0.03368382900953293f, 0.028379317373037338f, 0.023698987439274788f, 0.04291602224111557f, 0.028201187029480934f, 0.06933259963989258f, 0.06589723378419876f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006475442787632346f, 0.0007925606914795935f, 0.0006677486817352474f, 0.0005576232215389609f, 0.0010097888298332691f, 0.0006635573809035122f, 0.0016313552623614669f, 0.0015505232149735093f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005252972478047013f, 0.0008952342323027551f, 0.0009629215928725898f, 0.000703522760886699f, 0.0008025758434087038f, 0.00046754005597904325f, 0.00010752582602435723f, 0.0002835899649653584f, 0.00039332197047770023f, 0.0006321471882984042f, 0.003193317912518978f, 0.0003851155925076455f, 0.0003168062830809504f, 0.000497852626722306f, 0.0003823499719146639f, 0.002828217577189207f, 0.002162026474252343f, 0.0004491989966481924f, 0.00038945049163885415f, 0.00029190999339334667f, 0.0006330256583169103f, 0.0027375686913728714f, 0.00033564367913641036f, 0.0002966600004583597f, 0.0004318963910918683f, 0.002639126032590866f, 0.0004780806484632194f, 0.001119848689995706f, 0.0009179424960166216f, 0.0003760086256079376f, 0.0007335197296924889f, 0.0003417384868953377f, 0.001612620777450502f, 0.0003285105631221086f, 0.0004056074540130794f, 0.0002872323093470186f, 0.0031648133881390095f, 0.001037121401168406f, 0.00048648586380295455f, 0.0011358909541741014f, 0.0020912548061460257f, 0.0009762371773831546f, 0.0016732030780985951f, 0.00043626668048091233f, 0.0006924531189724803f, 0.00015026966866571456f, 0.002088515553623438f, 0.000637624179944396f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003859088756144047f, 0.0006576825398951769f, 0.0007074089953675866f, 0.000516842002980411f, 0.000589611183386296f, 0.00034347764449194074f, 7.899369666120037e-05f, 0.00020833896996919066f, 0.00028895342256873846f, 0.00046440603910014033f, 0.0023459664080291986f, 0.000282924622297287f, 0.00023274129489436746f, 0.0003657467314042151f, 0.00028089285478927195f, 0.002077745972201228f, 0.0015883296728134155f, 0.0003300034150015563f, 0.00028610925073735416f, 0.0002144512691302225f, 0.0004650514165405184f, 0.0020111510530114174f, 0.00024658016627654433f, 0.00021794084750581533f, 0.0003172920842189342f, 0.0019388302462175488f, 0.0003512212715577334f, 0.0008226952631957829f, 0.0006743651465512812f, 0.0002762342046480626f, 0.0005388792487792671f, 0.00025105770328082144f, 0.0011847096029669046f, 0.00024133981787599623f, 0.000297978927846998f, 0.0002110148052452132f, 0.0023250256199389696f, 0.0007619197713211179f, 0.00035739614395424724f, 0.0008344806847162545f, 0.0015363374259322882f, 0.0007171912584453821f, 0.0012292162282392383f, 0.0003205027023795992f, 0.0005087096942588687f, 0.00011039539822377264f, 0.001534324954263866f, 0.0004684297018684447f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003284112084656954f, 0.0029000199865549803f, 0.002243722788989544f, 0.003776801284402609f, 0.0017291124677285552f, 0.005035871639847755f, 0.013957874849438667f, 0.007533281110227108f, 0.005866175517439842f, 0.004589749965816736f, 0.001545017003081739f, 0.005202453583478928f, 0.006841104477643967f, 0.0030588163062930107f, 0.005136930383741856f, 0.0012813020730391145f, 0.000989689608104527f, 0.00302331754937768f, 0.00573516171425581f, 0.008285801857709885f, 0.004724292550235987f, 0.0011717765592038631f, 0.006570706609636545f, 0.006062162574380636f, 0.004863792099058628f, 0.0010457874741405249f, 0.003921989351511002f, 0.002185709308832884f, 0.0035027649719268084f, 0.005681142210960388f, 0.0034013940021395683f, 0.005970672704279423f, 0.001937467255629599f, 0.005393072497099638f, 0.004357099067419767f, 0.005356975365430117f, 0.0009483005851507187f, 0.0033583275508135557f, 0.004585488233715296f, 0.0027201054617762566f, 0.001154850353486836f, 0.0029275771230459213f, 0.0015328923473134637f, 0.004807852208614349f, 0.0036361024249345064f, 0.015608754940330982f, 0.0016942227957770228f, 0.00384042807854712f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.727322372375056e-05f, 6.823576404713094e-05f, 5.2793478971580043e-05f, 8.886591240298003e-05f, 4.068500129505992e-05f, 0.00011849110160255805f, 0.0003284206031821668f, 0.00017725367797538638f, 0.00013802766625303775f, 0.0001079941212083213f, 3.635334360296838e-05f, 0.0001224106817971915f, 0.0001609671744517982f, 7.197215018095449e-05f, 0.00012086895003449172f, 3.0148285077302717e-05f, 2.3286815121537074e-05f, 7.113688479876146e-05f, 0.00013494498853106052f, 0.00019496004097163677f, 0.00011115982488263398f, 2.757121364993509e-05f, 0.0001546048588352278f, 0.00014263912453316152f, 0.00011444216943345964f, 2.4606764782220125e-05f, 9.22821054700762e-05f, 5.1428454753477126e-05f, 8.241800242103636e-05f, 0.00013367393694352359f, 8.003279799595475e-05f, 0.00014048641605768353f, 4.558746513794176e-05f, 0.00012689582945313305f, 0.00010251998173771426f, 0.00012604647781699896f, 2.2312955479719676e-05f, 7.901947537902743e-05f, 0.00010789384396048263f, 6.400248093996197e-05f, 2.717294955800753e-05f, 6.888416828587651e-05f, 3.6068056942895055e-05f, 0.00011312593414913863f, 8.555535168852657e-05f, 0.0003672648163046688f, 3.9864065911388025e-05f, 9.036301344167441e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04400711879134178f, 0.03545449674129486f, 0.04090019688010216f, 0.03794104605913162f, 0.026293834671378136f, 0.05248450115323067f, 0.03635132685303688f, 0.041251249611377716f, 0.02298159897327423f, 0.024387016892433167f, 0.036475419998168945f, 0.04121872037649155f, 0.03499476984143257f, 0.03829177841544151f, 0.02432839944958687f, 0.026607798412442207f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010354616679251194f, 0.0008342234650626779f, 0.0009623576188459992f, 0.0008927304879762232f, 0.0006186784594319761f, 0.001234929426573217f, 0.0008553253719583154f, 0.0009706176351755857f, 0.0005407435237430036f, 0.0005738121690228581f, 0.0008582451846450567f, 0.0009698522626422346f, 0.0008234063861891627f, 0.0009009830537252128f, 0.0005724329384975135f, 0.0006260658847168088f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000939406338147819f, 0.0019411076791584492f, 0.0009609362459741533f, 0.0016866147052496672f, 0.0007593725458718836f, 0.0005865561543032527f, 0.0013163341209292412f, 0.0011547778267413378f, 0.0008117347024381161f, 0.0005889179301448166f, 0.0013737954432144761f, 0.0004321954620536417f, 0.001255044131539762f, 0.0011465316638350487f, 0.0014581006253138185f, 0.0006710891029797494f, 0.0015145707875490189f, 0.0017638539429754019f, 0.0017178428824990988f, 0.0007981594535522163f, 0.0003910143568646163f, 0.000662915816064924f, 0.0004766024649143219f, 0.0009344736463390291f, 0.000300207466352731f, 0.001584194484166801f, 0.0011832676827907562f, 0.001127812429331243f, 0.002160646952688694f, 0.0011284956708550453f, 0.0013566367560997605f, 0.0011381236836314201f, 0.0008940068655647337f, 0.00042585580376908183f, 0.0008417022181674838f, 0.0007823019404895604f, 0.0007567250286228955f, 0.0013572595780715346f, 0.0006514503620564938f, 0.0011597787961363792f, 0.0013991141458973289f, 0.0005276185693219304f, 0.0010677068494260311f, 0.0005798517377115786f, 0.000796913169324398f, 0.0004705028550233692f, 0.0002917369711212814f, 0.0016859512543305755f, 0.00037712958874180913f, 0.0009461505687795579f, 0.00144874956458807f, 0.0007603189442306757f, 0.0008666066569276154f, 0.00038815371226519346f, 0.0009002895676530898f, 0.0009061527089215815f, 0.0008668299415148795f, 0.0011792898876592517f, 0.0027690075803548098f, 0.0008339289342984557f, 0.0007131621823646128f, 0.0009769991738721728f, 0.0010078964987769723f, 0.0011170378420501947f, 0.0005380025831982493f, 0.0022734906524419785f, 0.0007635451620444655f, 0.0005400034715421498f, 0.0008815383189357817f, 0.0005270605906844139f, 0.0008912108605727553f, 0.0009743202826939523f, 0.0006375380326062441f, 0.0003419950371608138f, 0.000857190927490592f, 0.0008201609016396105f, 0.0005266312509775162f, 0.0013807760551571846f, 0.0006687226123176515f, 0.0009804923320189118f, 0.0005240978207439184f, 0.0007546335691586137f, 0.000536902341991663f, 0.0015936759300529957f, 0.0018876359099522233f, 0.0007474729791283607f, 0.001244319137185812f, 0.0005276222946122289f, 0.001030663144774735f, 0.0011568196350708604f, 0.0036063881125301123f, 0.002744529629126191f, 0.0007452034042216837f, 0.0014416795456781983f, 0.0007790682138875127f, 0.0008390332222916186f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00035875895991921425f, 0.0007413083803839982f, 0.00036698122858069837f, 0.0006441175937652588f, 0.000290004099952057f, 0.00022400559100788087f, 0.0005027075530961156f, 0.0004410092660691589f, 0.00031000119633972645f, 0.0002249075478175655f, 0.0005246520158834755f, 0.00016505530220456421f, 0.00047930091386660933f, 0.0004378600569907576f, 0.0005568481283262372f, 0.00025628870935179293f, 0.0005784140666946769f, 0.0006736151990480721f, 0.0006560435867868364f, 0.00030481681460514665f, 0.0001493282470619306f, 0.00025316732353530824f, 0.00018201432249043137f, 0.00035687515628524125f, 0.00011464912677183747f, 0.0006050033261999488f, 0.0004518895293585956f, 0.00043071116670034826f, 0.0008251503459177911f, 0.00043097211164422333f, 0.0005180991138331592f, 0.00043464903137646616f, 0.0003414209058973938f, 0.000162634183652699f, 0.0003214457829017192f, 0.0002987608313560486f, 0.0002889930328819901f, 0.0005183369503356516f, 0.0002487886813469231f, 0.0004429191176313907f, 0.0005343211814761162f, 0.0002014973433688283f, 0.000407756888307631f, 0.00022144518152344972f, 0.0003043408505618572f, 0.00017968488100450486f, 0.00011141425056848675f, 0.0006438642158173025f, 0.00014402566011995077f, 0.0003613345616031438f, 0.0005532769719138741f, 0.0002903655404224992f, 0.0003309567691758275f, 0.00014823576202616096f, 0.00034382028388790786f, 0.0003460594161879271f, 0.00033104204339906573f, 0.0004503703967202455f, 0.001057483023032546f, 0.0003184771630913019f, 0.00027235638117417693f, 0.00037311564665287733f, 0.0003849153290502727f, 0.0004265963798388839f, 0.00020546300220303237f, 0.0008682453189976513f, 0.00029159762198105454f, 0.00020622713782358915f, 0.0003366591699887067f, 0.00020128425967413932f, 0.0003403531154617667f, 0.00037209258880466223f, 0.00024347555881831795f, 0.00013060779019724578f, 0.00032736093271523714f, 0.00031321917776949704f, 0.00020112028869334608f, 0.0005273179267533123f, 0.00025538494810462f, 0.00037444967892952263f, 0.00020015277550555766f, 0.0002881943073589355f, 0.00020504281565081328f, 0.0006086243083700538f, 0.0007208875031210482f, 0.0002854596823453903f, 0.00047520504449494183f, 0.00020149876945652068f, 0.0003936098946724087f, 0.0004417890158947557f, 0.0013772783568128943f, 0.0010481348726898432f, 0.0002845929120667279f, 0.0005505768931470811f, 0.000297525868518278f, 0.0003204265085514635f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008252883329987526f, 0.014130768366158009f, 0.00791927333921194f, 0.009005948901176453f, 0.006675529759377241f, 0.004861092660576105f, 0.008768301457166672f, 0.0127323092892766f, 0.005804060492664576f, 0.010403068736195564f, 0.0015726258279755712f, 0.024963324889540672f, 0.005083067808300257f, 0.018366849049925804f, 0.010428586974740028f, 0.010905479080975056f, 0.005371811334043741f, 0.007328418083488941f, 0.009050366468727589f, 0.006958785466849804f, 0.017164556309580803f, 0.012227560393512249f, 0.010402845218777657f, 0.006730237044394016f, 0.052193623036146164f, 0.004479651805013418f, 0.008247210644185543f, 0.006592834834009409f, 0.0016985605470836163f, 0.01172641757875681f, 0.007211682852357626f, 0.00961100123822689f, 0.004186548292636871f, 0.014913401566445827f, 0.010926119051873684f, 0.014450421556830406f, 0.00800994597375393f, 0.009954680688679218f, 0.007088284473866224f, 0.001708890893496573f, 0.00460696080699563f, 0.014316481538116932f, 0.01100041251629591f, 0.011149684898555279f, 0.005649765022099018f, 0.015052729286253452f, 0.019586464390158653f, 0.006465787999331951f, 0.018786581233143806f, 0.03430702164769173f, 0.005893533583730459f, 0.0059729632921516895f, 0.0095320800319314f, 0.011937301605939865f, 0.010199669748544693f, 0.0042493510991334915f, 0.004899912513792515f, 0.0046241567470133305f, 0.007921178825199604f, 0.007350956089794636f, 0.006792878266423941f, 0.0036851754412055016f, 0.003775996621698141f, 0.00430927611887455f, 0.006427083630114794f, 0.0031317712273448706f, 0.006160413380712271f, 0.010045282542705536f, 0.013989755883812904f, 0.020402973517775536f, 0.007678892929106951f, 0.006363030523061752f, 0.006483291741460562f, 0.015113906934857368f, 0.005822292994707823f, 0.00872022658586502f, 0.013218162581324577f, 0.006080371793359518f, 0.008096621371805668f, 0.004973232746124268f, 0.006855737883597612f, 0.013582486659288406f, 0.006390562746673822f, 0.02345125749707222f, 0.009570972062647343f, 0.005561930127441883f, 0.00755793834105134f, 0.008592238649725914f, 0.004250133875757456f, 0.004578456282615662f, 0.0011263969354331493f, 0.006780750118196011f, 0.007539020851254463f, 0.006115041207522154f, 0.004407096188515425f, 0.007879793643951416f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019418550073169172f, 0.00033248867839574814f, 0.00018633584841154516f, 0.0002119046839652583f, 0.00015707129205111414f, 0.00011437865032348782f, 0.00020631297957152128f, 0.00029958374216221273f, 0.0001365661300951615f, 0.00024477808619849384f, 3.700296292663552e-05f, 0.0005873723421245813f, 0.00011960159463342279f, 0.0004321611486375332f, 0.0002453785273246467f, 0.0002565995091572404f, 0.00012639556371141225f, 0.0001724333706079051f, 0.0002129498025169596f, 0.00016373612743336707f, 0.00040387193439528346f, 0.00028770731296390295f, 0.0002447728475090116f, 0.00015835852536838502f, 0.0012280852533876896f, 0.00010540357470745221f, 0.0001940520160133019f, 0.00015512552636209875f, 3.996613304479979e-05f, 0.00027591572143137455f, 0.00016968665295280516f, 0.00022614121553488076f, 9.850702190306038e-05f, 0.0003509035741444677f, 0.0002570851647760719f, 0.0003400099230930209f, 0.00018846931925509125f, 0.00023422778758686036f, 0.00016678316751495004f, 4.020919732283801e-05f, 0.00010839907918125391f, 0.00033685838570818305f, 0.0002588332281447947f, 0.00026234553661197424f, 0.0001329356455244124f, 0.00035418185871094465f, 0.00046085799112915993f, 0.00015213618462439626f, 0.00044203721336089075f, 0.0008072240743786097f, 0.0001386713847750798f, 0.0001405403163516894f, 0.00022428424563258886f, 0.000280877691693604f, 0.00023999223776627332f, 9.998473251471296e-05f, 0.00011529205949045718f, 0.00010880368790822104f, 0.00018638068286236376f, 0.00017296367150265723f, 0.00015983243065420538f, 8.671000978210941e-05f, 8.884698036126792e-05f, 0.00010139473306480795f, 0.0001512254966655746f, 7.368873775703833e-05f, 0.0001449508999940008f, 0.00023635959951207042f, 0.00032917072530835867f, 0.0004800699825864285f, 0.00018067983910441399f, 0.00014971836935728788f, 0.00015254804748110473f, 0.0003556213341653347f, 0.00013699513510800898f, 0.0002051818009931594f, 0.0003110156103502959f, 0.00014306757657323033f, 0.0001905087410705164f, 0.00011701723997248337f, 0.0001613114873180166f, 0.0003195879398845136f, 0.00015036619151942432f, 0.0005517943063750863f, 0.0002251993428217247f, 0.00013086895341984928f, 0.00017783384828362614f, 0.00020217032579239458f, 0.00010000315523939207f, 0.0001077283886843361f, 2.6503457775106654e-05f, 0.0001595470675965771f, 0.00017738873430062085f, 0.00014388332783710212f, 0.00010369638039264828f, 0.00018540691235102713f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01743347942829132f, 0.018166135996580124f, 0.024520834907889366f, 0.011454393155872822f, 0.016953537240624428f, 0.025572460144758224f, 0.015187254175543785f, 0.02534862421452999f, 0.012293191626667976f, 0.015295282006263733f, 0.015195265412330627f, 0.008687695488333702f, 0.012156287208199501f, 0.011262692511081696f, 0.01177342887967825f, 0.010509030893445015f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00041019951459020376f, 0.00042743849917314947f, 0.0005769608542323112f, 0.00026951514882966876f, 0.0003989067627117038f, 0.0006017049308866262f, 0.00035734716220758855f, 0.0005964382435195148f, 0.00028925156220793724f, 0.0003598890034481883f, 0.0003575356677174568f, 0.00020441637025214732f, 0.00028603029204532504f, 0.00026500452077016234f, 0.00027702187071554363f, 0.00024727132404223084f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00027738127391785383f, 0.0002956357493530959f, 0.000497598375659436f, 0.00044019398046657443f, 0.0006458577699959278f, 0.0005112338112667203f, 0.0004657255485653877f, 0.0010769766522571445f, 0.0009651528089307249f, 0.00025974216987378895f, 0.0015718520153313875f, 0.0006027150084264576f, 0.0008240503375418484f, 0.0005914181820116937f, 0.003522769780829549f, 0.0004063997766934335f, 0.0005512333591468632f, 0.00043117249151691794f, 0.0005277040763758123f, 0.0005461330292746425f, 0.0017559205880388618f, 0.00044130635797046125f, 0.0003554227587301284f, 0.0004492018779274076f, 0.0006839439738541842f, 0.0005904085119254887f, 0.0006357046077027917f, 0.0003473709512036294f, 0.000531175232026726f, 0.0016589133301749825f, 0.0007292075897566974f, 0.0005966081516817212f, 0.0005254191346466541f, 0.0005367245175875723f, 0.001179780694656074f, 0.0004629906907211989f, 0.0011913749622181058f, 0.0007709675119258463f, 0.0002204285265179351f, 0.0006846522446721792f, 0.0007407983066514134f, 0.0008894582861103117f, 0.0004215150256641209f, 0.000695082766469568f, 0.0019524545641615987f, 0.000769637175835669f, 0.0007571440073661506f, 0.0009219590574502945f, 0.0006001205183565617f, 0.00045570297515951097f, 0.0005926468293182552f, 0.0008006707648746669f, 0.0010569000151008368f, 0.0024287549313157797f, 0.0008130391361191869f, 0.0007883295184001327f, 0.0006580319604836404f, 0.00034044578205794096f, 0.0014285101788118482f, 0.0005234673735685647f, 0.0007444853545166552f, 0.0002585341571830213f, 0.0003612976288422942f, 0.0006056696292944252f, 0.0015064652543514967f, 0.0008784341043792665f, 0.0018920080037787557f, 0.0005928634200245142f, 0.0007161956746131182f, 0.001691223937086761f, 0.0007698907284066081f, 0.00060306116938591f, 0.0012401217827573419f, 0.0011837173951789737f, 0.0006032391102053225f, 0.0007429441902786493f, 0.0007975982734933496f, 0.0006654487806372344f, 0.001046988763846457f, 0.0007167435833252966f, 0.0004672864160966128f, 0.0006131869158707559f, 0.0019247059244662523f, 0.0005908753373660147f, 0.0007520176004618406f, 0.0006631247815676033f, 0.0005054411012679338f, 0.0005735810264013708f, 0.0006640534265898168f, 0.001158782746642828f, 0.0006277780048549175f, 0.000970575725659728f, 0.0012746694264933467f, 0.0007220609113574028f, 0.0010689927730709314f, 0.0007606727886013687f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00013815800775773823f, 0.00014725018991157413f, 0.00024784367997199297f, 0.00021925171313341707f, 0.0003216886834707111f, 0.0002546352334320545f, 0.00023196847178041935f, 0.0005364202661439776f, 0.0004807231016457081f, 0.0001293723180424422f, 0.0007829077076166868f, 0.00030020016129128635f, 0.00041044282261282206f, 0.00029457343043759465f, 0.0017546203453093767f, 0.00020241951278876513f, 0.00027455820236355066f, 0.0002147582999896258f, 0.00026283873012289405f, 0.00027201781631447375f, 0.0008745885570533574f, 0.00021980577730573714f, 0.0001770288945408538f, 0.00022373837418854237f, 0.0003406586474739015f, 0.00029407054535113275f, 0.00031663160189054906f, 0.0001730184449115768f, 0.0002645676431711763f, 0.0008262711926363409f, 0.00036320355138741434f, 0.0002971584617625922f, 0.00026170065393671393f, 0.0002673316339496523f, 0.0005876249051652849f, 0.00023060629609972239f, 0.0005933998036198318f, 0.0003840033314190805f, 0.00010979099170072004f, 0.00034101144410669804f, 0.00036897664540447295f, 0.00044302118476480246f, 0.00020994810620322824f, 0.0003462066815700382f, 0.0009724781266413629f, 0.00038334072451107204f, 0.0003771181218326092f, 0.0004592091718222946f, 0.00029890789301134646f, 0.0002269764372613281f, 0.0002951853966806084f, 0.0003987979143857956f, 0.0005264205392450094f, 0.001209713751450181f, 0.0004049583512824029f, 0.00039265098166652024f, 0.00032775240833871067f, 0.00016956916078925133f, 0.0007115120533853769f, 0.00026072849868796766f, 0.00037081309710629284f, 0.00012877064000349492f, 0.0001799550373107195f, 0.0003016717964783311f, 0.0007503398810513318f, 0.0004375302523840219f, 0.0009423709125258029f, 0.0002952932845801115f, 0.00035672259400598705f, 0.0008423644467256963f, 0.0003834670060314238f, 0.00030037257238291204f, 0.0006176795577630401f, 0.0005895856884308159f, 0.0003004611935466528f, 0.0003700454835779965f, 0.0003972675767727196f, 0.00033144658664241433f, 0.0005214839475229383f, 0.0003569954715203494f, 0.00023274590785149485f, 0.0003054160042665899f, 0.0009586571250110865f, 0.0002943030558526516f, 0.00037456475547514856f, 0.00033028903999365866f, 0.00025174999609589577f, 0.00028568910784088075f, 0.00033075158717110753f, 0.0005771662690676749f, 0.00031268352176994085f, 0.00048342414083890617f, 0.000634887081105262f, 0.0003596439491957426f, 0.0005324436933733523f, 0.0003788757312577218f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.025001492351293564f, 0.01387784443795681f, 0.006063015665858984f, 0.009632415138185024f, 0.020156169310212135f, 0.00946225505322218f, 0.008172770030796528f, 0.0029396505560725927f, 0.005106039345264435f, 0.012750278227031231f, 0.004874506965279579f, 0.012895061634480953f, 0.004011284559965134f, 0.008642041124403477f, 0.0011420731898397207f, 0.012115759775042534f, 0.011026729829609394f, 0.008516482077538967f, 0.005092373583465815f, 0.007745930925011635f, 0.009246488101780415f, 0.019746221601963043f, 0.010416539385914803f, 0.006513549946248531f, 0.006921745371073484f, 0.009621384553611279f, 0.00592201529070735f, 0.026553962379693985f, 0.014616956003010273f, 0.01132879313081503f, 0.006059156730771065f, 0.007844273000955582f, 0.01929096132516861f, 0.011632727459073067f, 0.0030198022723197937f, 0.006900803651660681f, 0.003164734225720167f, 0.015653491020202637f, 0.01120640616863966f, 0.009449785575270653f, 0.0103218462318182f, 0.002893327735364437f, 0.008060683496296406f, 0.009273825213313103f, 0.0021823367569595575f, 0.00398029712960124f, 0.009347640909254551f, 0.008457592688500881f, 0.013239321298897266f, 0.0053662750869989395f, 0.0024202007334679365f, 0.017687009647488594f, 0.004564796574413776f, 0.0032843262888491154f, 0.006373838055878878f, 0.0037206171546131372f, 0.005300115328282118f, 0.005661104805767536f, 0.0021509164944291115f, 0.00902102142572403f, 0.015113133005797863f, 0.03748058155179024f, 0.011600065976381302f, 0.006641482003033161f, 0.005016658455133438f, 0.004688308108597994f, 0.002190908882766962f, 0.011078447103500366f, 0.006658438593149185f, 0.002449924824759364f, 0.008163233287632465f, 0.007704409770667553f, 0.001702460809610784f, 0.007485763169825077f, 0.012958746403455734f, 0.012186795473098755f, 0.010214701294898987f, 0.005308420863002539f, 0.0049399142153561115f, 0.004936573561280966f, 0.009292840026319027f, 0.015427912585437298f, 0.0016626701690256596f, 0.02057425118982792f, 0.003963540308177471f, 0.004757623188197613f, 0.014798632822930813f, 0.006028840783983469f, 0.008665572851896286f, 0.004992806352674961f, 0.011766836978495121f, 0.007008465006947517f, 0.00765432370826602f, 0.009157850407063961f, 0.0013681866694241762f, 0.005895756185054779f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005882704281248152f, 0.00032653752714395523f, 0.00014265919162426144f, 0.00022664506104774773f, 0.0004742628079839051f, 0.0002226413052994758f, 0.00019230047473683953f, 6.916825077496469e-05f, 0.00012014210369670764f, 0.00030000656261108816f, 0.0001146942813647911f, 0.00030341322417370975f, 9.438316919840872e-05f, 0.00020334214786998928f, 2.687231062736828e-05f, 0.00028507670504041016f, 0.0002594524703454226f, 0.00020038781804032624f, 0.00011982055730186403f, 0.00018225720850750804f, 0.00021756443311460316f, 0.00046461698366329074f, 0.0002450950560159981f, 0.00015325999993365258f, 0.00016286459867842495f, 0.0002263855276396498f, 0.00013934154412709177f, 0.000624799111392349f, 0.00034392837551422417f, 0.0002665598294697702f, 0.00014256840222515166f, 0.0001845711376518011f, 0.0004539049696177244f, 0.00027371125179342926f, 7.105417171260342e-05f, 0.00016237185627687722f, 7.446433301083744e-05f, 0.00036831744364462793f, 0.0002636801509652287f, 0.00022234789503272623f, 0.0002428669686196372f, 6.807829777244478e-05f, 0.00018966314382851124f, 0.00021820765687152743f, 5.1349099521758035e-05f, 9.365405276184902e-05f, 0.00021994450071360916f, 0.00019900218467228115f, 0.0003115134604740888f, 0.0001262652949662879f, 5.694590072380379e-05f, 0.00041616492671892047f, 0.00010740698053268716f, 7.727826596237719e-05f, 0.0001499726640759036f, 8.754393638810143e-05f, 0.00012470860383473337f, 0.00013320246944203973f, 5.060980038251728e-05f, 0.00021225932869128883f, 0.00035560314427129924f, 0.0008818960632197559f, 0.00027294273604638875f, 0.00015627016546204686f, 0.00011803902452811599f, 0.00011031313624698669f, 5.155079998075962e-05f, 0.0002606693597044796f, 0.00015666914987377822f, 5.764529123553075e-05f, 0.00019207608420401812f, 0.00018128023657482117f, 4.005790106020868e-05f, 0.00017613561067264527f, 0.0003049116930924356f, 0.0002867481380235404f, 0.00024034592206589878f, 0.0001249040215043351f, 0.00011623327736742795f, 0.00011615467519732192f, 0.0002186550700571388f, 0.0003630097198765725f, 3.91216526622884e-05f, 0.00048410004819743335f, 9.325977589469403e-05f, 0.00011194407852599397f, 0.0003482031461317092f, 0.00014185508189257234f, 0.0002038958336925134f, 0.00011747780081350356f, 0.00027686674729920924f, 0.00016490506823174655f, 0.00018010173516813666f, 0.0002154788380721584f, 3.2192627259064466e-05f, 0.00013872368435841054f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009535538963973522f, 0.01870071142911911f, 0.032451972365379333f, 0.004952403716742992f, 0.018737653270363808f, 0.01946440525352955f, 0.008247149176895618f, 0.021825306117534637f, 0.014290683902800083f, 0.020941687747836113f, 0.011328273452818394f, 0.008481507189571857f, 0.013857763260602951f, 0.015935515984892845f, 0.010612240061163902f, 0.008693900890648365f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002243656199425459f, 0.0004400167381390929f, 0.0007635758374817669f, 0.0001165271460195072f, 0.0004408859822433442f, 0.00045798602513968945f, 0.0001940505753736943f, 0.0005135366227477789f, 0.0003362513962201774f, 0.0004927456029690802f, 0.00026654760586097836f, 0.00019956487813033164f, 0.00032606502645649016f, 0.0003749533207155764f, 0.00024969977675937116f, 0.00020456238416954875f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00043156000901944935f, 0.0012232967419549823f, 0.000951907248236239f, 0.0011199327418580651f, 0.00041298213182017207f, 0.0005788265261799097f, 0.00041510825394652784f, 0.0005553786177188158f, 0.0007154179620556533f, 0.0007790870149619877f, 0.0005931368214078248f, 0.00045571342343464494f, 0.0014475664356723428f, 0.0006982064223848283f, 0.001449221046641469f, 0.0013370277592912316f, 0.0009704654803499579f, 0.0005205021006986499f, 0.0011880446691066027f, 0.0004027543473057449f, 0.00034192699240520597f, 0.0006797596579417586f, 0.0006996279116719961f, 0.0004565490526147187f, 0.0008979389676824212f, 0.00047059182543307543f, 0.0005254006828181446f, 0.000567955372389406f, 4.25133912358433e-05f, 0.0005570699577219784f, 0.0014741105260327458f, 0.000848734809551388f, 0.0008398279314860702f, 0.0009831739589571953f, 0.0004760519659612328f, 0.0010291191283613443f, 0.001159896608442068f, 0.0006472120294347405f, 0.0007634415524080396f, 0.0016593545442447066f, 0.0004780683957505971f, 0.0011910187313333154f, 0.0010078983614221215f, 0.0014725694200024009f, 0.0005355803295969963f, 0.0007039278862066567f, 0.000556700280867517f, 0.0004308538627810776f, 0.001331957639195025f, 0.000647618027869612f, 0.0006566397496499121f, 0.0013053864240646362f, 0.00391246797516942f, 0.0010446617379784584f, 0.0007046759710647166f, 0.0005973274237476289f, 0.0019467492820695043f, 0.0003349161415826529f, 0.00048083302681334317f, 0.001341025810688734f, 0.001162764965556562f, 0.0011665564961731434f, 0.001274657086469233f, 0.000809922581538558f, 0.00046494154958054423f, 0.00025702090351842344f, 0.0012929302174597979f, 0.0024743620306253433f, 0.0009342528064735234f, 0.000766471610404551f, 0.0013507612748071551f, 0.0014613874955102801f, 0.0006556412554346025f, 0.0005162085290066898f, 0.00040994799928739667f, 0.0011606760090216994f, 0.0006317254737950861f, 0.0006632389267906547f, 0.0008365071844309568f, 0.0003032931999769062f, 0.0005184728070162237f, 0.0005966806784272194f, 0.0005800805520266294f, 0.0013781958259642124f, 0.0019069232512265444f, 0.0005973605439066887f, 0.0005358772468753159f, 0.0004776020650751889f, 0.00038954755291342735f, 0.0005733987782150507f, 0.00047693331725895405f, 0.0014322968199849129f, 0.0008929867180995643f, 0.0009161234484054148f, 0.000981761608272791f, 0.0006397711113095284f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00030594682903029025f, 0.000867234542965889f, 0.0006748377927578986f, 0.0007939564529806376f, 0.0002927763562183827f, 0.0004103488172404468f, 0.00029428364359773695f, 0.0003937258443329483f, 0.0005071829073131084f, 0.0005523199215531349f, 0.00042049383046105504f, 0.0003230699512641877f, 0.0010262265568599105f, 0.0004949810681864619f, 0.0010273995576426387f, 0.0009478621650487185f, 0.0006879942957311869f, 0.0003690007433760911f, 0.0008422432001680136f, 0.0002855255443137139f, 0.0002424030826659873f, 0.0004819035530090332f, 0.0004959888174198568f, 0.0003236623597331345f, 0.0006365778972394764f, 0.00033361773239448667f, 0.00037247349973767996f, 0.00040264189010486007f, 3.0139115551719442e-05f, 0.00039492486394010484f, 0.0010450445115566254f, 0.0006016955012455583f, 0.0005953811341896653f, 0.0006970037356950343f, 0.00033748860005289316f, 0.0007295757532119751f, 0.0008222881588153541f, 0.0004588295123539865f, 0.0005412283353507519f, 0.0011763699585571885f, 0.000338918121997267f, 0.0008443515980616212f, 0.0007145316922105849f, 0.0010439519537612796f, 0.000379690172849223f, 0.000499037210829556f, 0.0003946628130506724f, 0.00030544621404260397f, 0.0009442677837796509f, 0.00045911732013337314f, 0.000465513119706884f, 0.0009254305623471737f, 0.0027736749034374952f, 0.0007405944052152336f, 0.0004995675408281386f, 0.0004234646912664175f, 0.0013801134191453457f, 0.00023743286146782339f, 0.0003408780612517148f, 0.0009506964706815779f, 0.0008243216434493661f, 0.0008270095568150282f, 0.0009036455303430557f, 0.0005741802742704749f, 0.00032961208489723504f, 0.0001822104095481336f, 0.0009165999945253134f, 0.0017541551496833563f, 0.0006623219815082848f, 0.0005433764890767634f, 0.0009575982694514096f, 0.0010360247688367963f, 0.00046480525634251535f, 0.00036595689016394317f, 0.0002906253794208169f, 0.0008228406659327447f, 0.0004478505870793015f, 0.0004701914731413126f, 0.0005930269253440201f, 0.00021501434093806893f, 0.0003675621119327843f, 0.0004230061895214021f, 0.0004112378228455782f, 0.000977047486230731f, 0.0013518794439733028f, 0.0004234881780575961f, 0.00037990068085491657f, 0.00033858753158710897f, 0.0002761628420557827f, 0.00040650091250427067f, 0.0003381134301889688f, 0.0010154014453291893f, 0.0006330671021714807f, 0.0006494694971479475f, 0.0006960025057196617f, 0.0004535543848760426f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028412772808223963f, 0.001903946278616786f, 0.003640693612396717f, 0.0029636125545948744f, 0.006881505250930786f, 0.002269148360937834f, 0.004564609844237566f, 0.007818247191607952f, 0.00425620237365365f, 0.0031185997650027275f, 0.004267291631549597f, 0.005206159316003323f, 0.001565837417729199f, 0.002737827831879258f, 0.0018820115365087986f, 0.0027438891120254993f, 0.0038080064114183187f, 0.004307211842387915f, 0.0022149281576275826f, 0.0028056586161255836f, 0.006438671611249447f, 0.0025785653851926327f, 0.0025901012122631073f, 0.010159756988286972f, 0.003729152726009488f, 0.0032976476941257715f, 0.004624873865395784f, 0.004080887883901596f, 0.034805797040462494f, 0.003038439666852355f, 0.001160960178822279f, 0.0019552891608327627f, 0.004941434133797884f, 0.0018687424017116427f, 0.002824377501383424f, 0.0031679279636591673f, 0.0015262567903846502f, 0.002376970835030079f, 0.0037618824280798435f, 0.0012722588144242764f, 0.004397000186145306f, 0.0010784113546833396f, 0.0018469999777153134f, 0.0019380897283554077f, 0.004123602993786335f, 0.0028082451317459345f, 0.0039413389749825f, 0.0023677838034927845f, 0.0019627742003649473f, 0.0030781126115471125f, 0.004111109301447868f, 0.0027748432476073503f, 0.0011498423991724849f, 0.003434772603213787f, 0.0031754348892718554f, 0.001865101745352149f, 0.001069124904461205f, 0.0030446420423686504f, 0.002704616403207183f, 0.0019984531681984663f, 0.0025166599079966545f, 0.0022365970071405172f, 0.0010207687737420201f, 0.003037497866898775f, 0.0029893405735492706f, 0.008548727259039879f, 0.0015061856247484684f, 0.0012440880527719855f, 0.0017332261195406318f, 0.0021377301309257746f, 0.004645856097340584f, 0.002341233193874359f, 0.0027782961260527372f, 0.003232835326343775f, 0.0054466696456074715f, 0.0018977317959070206f, 0.0034174108877778053f, 0.002033486030995846f, 0.0031402711756527424f, 0.004009160678833723f, 0.003744116285815835f, 0.0024817155208438635f, 0.004478840623050928f, 0.0011092281201854348f, 0.002718705218285322f, 0.0031799341086298227f, 0.002331977942958474f, 0.0041340128518640995f, 0.0033460028935223818f, 0.0030101260636001825f, 0.007009993307292461f, 0.0028071068227291107f, 0.0014840620569884777f, 0.003251725807785988f, 0.0028439515735954046f, 0.0026174120139330626f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.685358675895259e-05f, 4.479873678064905e-05f, 8.566337783122435e-05f, 6.973206473048776e-05f, 0.00016191777831409127f, 5.339172639651224e-05f, 0.00010740258585428819f, 0.00018395876395516098f, 0.00010014593863161281f, 7.337881834246218e-05f, 0.00010040686174761504f, 0.00012249786232132465f, 3.684323382913135e-05f, 6.441948062274605e-05f, 4.4282624003244564e-05f, 6.456209666794166e-05f, 8.960015111370012e-05f, 0.00010134616604773328f, 5.211595635046251e-05f, 6.601549830520526e-05f, 0.00015149815590120852f, 6.067212962079793e-05f, 6.0943559219595045e-05f, 0.00023905311536509544f, 8.774477464612573e-05f, 7.759171421639621e-05f, 0.00010882056085392833f, 9.602089266991243e-05f, 0.0008189599611796439f, 7.149270095396787e-05f, 2.731670974753797e-05f, 4.60068040410988e-05f, 0.00011626903869910166f, 4.3970409024041146e-05f, 6.645594112342224e-05f, 7.453948637703434e-05f, 3.59119258064311e-05f, 5.592872548731975e-05f, 8.851488382788375e-05f, 2.9935501515865326e-05f, 0.0001034588276525028f, 2.537438558647409e-05f, 4.345882553025149e-05f, 4.5602111640619114e-05f, 9.702595707494766e-05f, 6.607635441469029e-05f, 9.273739124182612e-05f, 5.571256042458117e-05f, 4.618292223312892e-05f, 7.242617721203715e-05f, 9.67319865594618e-05f, 6.529042730107903e-05f, 2.705511542444583e-05f, 8.081817941274494e-05f, 7.471611752407625e-05f, 4.3884749175049365e-05f, 2.515588130336255e-05f, 7.163863483583555e-05f, 6.363803549902514e-05f, 4.702242949861102e-05f, 5.92155302001629e-05f, 5.26258118043188e-05f, 2.4018088879529387e-05f, 7.147053838707507e-05f, 7.033742440398782e-05f, 0.00020114652579650283f, 3.543966158758849e-05f, 2.9272659958223812e-05f, 4.07817933592014e-05f, 5.0299531721975654e-05f, 0.00010931426368188113f, 5.508783942786977e-05f, 6.537167791975662e-05f, 7.606671715620905e-05f, 0.000128156942082569f, 4.4652515498455614e-05f, 8.040967077249661e-05f, 4.784673001267947e-05f, 7.388873200397938e-05f, 9.433319792151451e-05f, 8.809685823507607e-05f, 5.83933069719933e-05f, 0.0001053844898706302f, 2.609948569443077e-05f, 6.396953540388495e-05f, 7.482198270736262e-05f, 5.487007001647726e-05f, 9.727089491207153e-05f, 7.872948481235653e-05f, 7.0826499722898e-05f, 0.00016494102601427585f, 6.604957161471248e-05f, 3.491910683806054e-05f, 7.65111981309019e-05f, 6.691650924040005e-05f, 6.158616452012211e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01803501695394516f, 0.013698127120733261f, 0.012965245172381401f, 0.022533699870109558f, 0.01611977443099022f, 0.019998127594590187f, 0.015358529053628445f, 0.014599607326090336f, 0.015486972406506538f, 0.0242043137550354f, 0.027252178639173508f, 0.013795093633234501f, 0.02594541385769844f, 0.020551642403006554f, 0.021359652280807495f, 0.02302379533648491f, 0.014006780460476875f, 0.021174054592847824f, 0.017198169603943825f, 0.015231679193675518f, 0.01479522418230772f, 0.014747705310583115f, 0.02077365666627884f, 0.017236821353435516f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0004243533476255834f, 0.0003223088860977441f, 0.0003050646046176553f, 0.0005302047356963158f, 0.00037928883102722466f, 0.00047054418246261775f, 0.00036137716961093247f, 0.000343520165188238f, 0.0003643993695732206f, 0.0005695133004337549f, 0.0006412277580238879f, 0.0003245904517825693f, 0.0006104803178459406f, 0.0004835680592805147f, 0.0005025800783187151f, 0.0005417363718152046f, 0.00032957131043076515f, 0.0004982130485586822f, 0.0004046628309879452f, 0.0003583924553822726f, 0.00034812293597497046f, 0.00034700482501648366f, 0.0004887919058091938f, 0.0004055722674820572f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000654194678645581f, 0.0006905957707203925f, 0.0007930658757686615f, 0.0006401765276677907f, 0.0006904182373546064f, 0.0005873278132639825f, 0.0006049918592907488f, 0.0010625077411532402f, 0.0009601550409570336f, 0.0006475445698015392f, 0.0005901875556446612f, 0.0005323144141584635f, 0.0009888836648315191f, 0.0020503439009189606f, 0.0003880052245222032f, 0.0002723453799262643f, 0.0004302236484363675f, 0.000405950122512877f, 0.0005770531133748591f, 0.0004775238048750907f, 0.0006079566082917154f, 0.0003789189213421196f, 0.0008207414648495615f, 0.001146787079051137f, 0.00044556870125234127f, 0.0007438768516294658f, 0.001139405183494091f, 0.0008216355927288532f, 0.0008251128601841629f, 0.0012637922773137689f, 0.0006273329490795732f, 0.0002979968849103898f, 9.42973856581375e-05f, 0.00039730474236421287f, 0.0008644217159599066f, 0.0007337905117310584f, 0.0009663102682679892f, 0.0002793403109535575f, 0.0007131005404517055f, 0.00032449793070554733f, 0.0003962778428103775f, 0.0006386997411027551f, 0.000543622940313071f, 0.0001992635807255283f, 0.000583407178055495f, 0.0011492742924019694f, 0.00034955324372276664f, 0.0007317556301131845f, 0.0009460542933084071f, 0.0005769282579421997f, 0.0005163725581951439f, 0.000521486159414053f, 0.0006680094520561397f, 0.0006362411077134311f, 0.0007674295920878649f, 0.00035797388409264386f, 0.0006433478556573391f, 0.000529297802131623f, 0.0006990571273490787f, 0.00016824125486891717f, 0.0004857403691858053f, 9.305170533480123e-05f, 0.0010212601628154516f, 0.0007446017698384821f, 0.0005286590312607586f, 0.0007503912784159184f, 0.0008105203160084784f, 0.0009549509268254042f, 0.0004152777255512774f, 0.0004658109101001173f, 0.0007554261828772724f, 0.0006779756513424218f, 0.000754118082113564f, 0.00038280096487142146f, 0.0009331749752163887f, 0.0019277927931398153f, 0.0007491252617910504f, 0.0009249658905901015f, 0.0003829676134046167f, 0.0007870223489589989f, 0.0003769797331187874f, 0.001040724222548306f, 0.0004780522140208632f, 0.0010103491367772222f, 0.002183877397328615f, 0.0009735096246004105f, 0.00023790595878381282f, 0.0006447024643421173f, 0.000755298649892211f, 0.0009185270173475146f, 0.00038314625271596014f, 0.0011795797618106008f, 0.0014595253160223365f, 0.0004634484357666224f, 0.0007838301826268435f, 0.0006702228565700352f, 0.0007731231162324548f, 0.0006762847187928855f, 0.001006330014206469f, 0.0005789881688542664f, 0.0003643557138275355f, 0.0004884469672106206f, 0.0008276785956695676f, 0.0006100568571127951f, 0.00020480148668866605f, 0.00037584107485599816f, 0.0005293741705827415f, 0.00029969075694680214f, 0.000875159865245223f, 0.0005139153799973428f, 0.0002847732394002378f, 0.0008774775778874755f, 0.0005085081211291254f, 0.0007499908097088337f, 0.0005090226768516004f, 0.0010052579455077648f, 0.00018732371972873807f, 0.0008545172167941928f, 0.0007450114353559911f, 0.0006392731447704136f, 0.0012613022699952126f, 0.0006881922599859536f, 0.0006402261788025498f, 0.0003912308893632144f, 0.0002984596649184823f, 0.0009127994999289513f, 0.0005491006304509938f, 0.0005358473281376064f, 0.00043301083496771753f, 0.0007059299969114363f, 0.0001596565853105858f, 0.0006312421173788607f, 0.0006448134663514793f, 0.000716532813385129f, 0.0006097860168665648f, 0.0005341264768503606f, 0.0007304956670850515f, 0.00041438540210947394f, 0.0004455774324014783f, 0.00023056537611410022f, 0.0006951797986403108f, 0.0005304915248416364f, 0.0006129093235358596f, 0.0003545630315784365f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002416148199699819f, 0.0002550588978920132f, 0.00029290435486473143f, 0.00023643748136237264f, 0.00025499332696199417f, 0.00021691877918783575f, 0.00022344266471918672f, 0.00039241777267307043f, 0.0003546156804077327f, 0.00023915873316582292f, 0.00021797497174702585f, 0.00019660058023873717f, 0.00036522606387734413f, 0.0007572569884359837f, 0.0001433026191079989f, 0.00010058577754534781f, 0.00015889522910583764f, 0.0001499302452430129f, 0.0002131240034941584f, 0.000176364672370255f, 0.00022453763813246042f, 0.00013994675828143954f, 0.0003031258238479495f, 0.0004235448141116649f, 0.00016456264711450785f, 0.0002747373073361814f, 0.000420818425482139f, 0.00030345606501214206f, 0.00030474032973870635f, 0.0004667585308197886f, 0.00023169393534772098f, 0.00011005969281541184f, 3.4827011404559016e-05f, 0.0001467372348997742f, 0.0003192583390045911f, 0.0002710120752453804f, 0.00035688900970853865f, 0.00010316922998754308f, 0.0002633706317283213f, 0.0001198473692056723f, 0.00014635796833317727f, 0.000235892046475783f, 0.00020077718363609165f, 7.359435403486714e-05f, 0.00021547076175920665f, 0.0004244634183123708f, 0.00012910108489450067f, 0.0002702605561353266f, 0.0003494078409858048f, 0.0002130778884747997f, 0.00019071274437010288f, 0.00019260136468801647f, 0.0002467170706950128f, 0.0002349840069655329f, 0.00028343606390990317f, 0.000132211105665192f, 0.00023760875046718866f, 0.00019548645650502294f, 0.00025818395079113543f, 6.213682354427874e-05f, 0.0001793993142200634f, 3.436694169067778e-05f, 0.0003771837509702891f, 0.0002750050334725529f, 0.00019525052630342543f, 0.00027714326279237866f, 0.0002993508242070675f, 0.0003526936343405396f, 0.0001533752219984308f, 0.00017203872266691178f, 0.0002790028229355812f, 0.00025039789034053683f, 0.00027851969934999943f, 0.00014138052938506007f, 0.0003446510818321258f, 0.0007119949441403151f, 0.00027667570975609124f, 0.000341619219398126f, 0.00014144206943456084f, 0.00029067229479551315f, 0.000139230556669645f, 0.0003843724261969328f, 0.00017655982810538262f, 0.0003731539472937584f, 0.0008065751171670854f, 0.0003595479647628963f, 8.786621037870646e-05f, 0.0002381090453127399f, 0.0002789557329379022f, 0.0003392411454115063f, 0.00014150804781820625f, 0.0004356561985332519f, 0.0005390489241108298f, 0.0001711661898298189f, 0.00028949332772754133f, 0.00024753453908488154f, 0.0002855388738680631f, 0.00024977338034659624f, 0.0003716695646289736f, 0.00021383867715485394f, 0.00013456810847856104f, 0.00018039894348476082f, 0.00030568792135454714f, 0.0002253133279737085f, 7.56396766519174e-05f, 0.00013881002087146044f, 0.00019551465811673552f, 0.00011068529420299456f, 0.0003232242597732693f, 0.000189805228728801f, 0.00010517577902646735f, 0.00032408026163466275f, 0.00018780816753860563f, 0.00027699535712599754f, 0.00018799820099957287f, 0.00037127360701560974f, 6.918458529980853e-05f, 0.00031560027855448425f, 0.00027515634428709745f, 0.00023610383505001664f, 0.0004658389079850167f, 0.00025417120195925236f, 0.00023645581677556038f, 0.00014449396985583007f, 0.00011023061233572662f, 0.0003371257917024195f, 0.00020280026365071535f, 0.0001979053922696039f, 0.00015992461703717709f, 0.00026072232867591083f, 5.896623770240694e-05f, 0.00023313771816901863f, 0.00023815005260985345f, 0.0002646382781676948f, 0.00022521329810842872f, 0.00019726983737200499f, 0.00026979518588632345f, 0.00015304566477425396f, 0.00016456586308777332f, 8.515510126017034e-05f, 0.0002567519259173423f, 0.00019592733588069677f, 0.00022636682842858136f, 0.00013095136091578752f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007770763710141182f, 0.008919628337025642f, 0.004849479533731937f, 0.027301130816340446f, 0.013620228506624699f, 0.018477261066436768f, 0.009074338711798191f, 0.004210214130580425f, 0.009400738403201103f, 0.00967712327837944f, 0.005498535931110382f, 0.018625475466251373f, 0.010957573540508747f, 0.003915627487003803f, 0.018362239003181458f, 0.01536187157034874f, 0.00935831293463707f, 0.013837833888828754f, 0.0052949730306863785f, 0.015049943700432777f, 0.015539630316197872f, 0.006935012526810169f, 0.006794325541704893f, 0.008113444782793522f, 0.016775790601968765f, 0.005326459184288979f, 0.008152475580573082f, 0.009000110439956188f, 0.004892074503004551f, 0.00267066340893507f, 0.018512634560465813f, 0.019462594762444496f, 0.05828304588794708f, 0.00923700537532568f, 0.004245599266141653f, 0.008297141641378403f, 0.009754595346748829f, 0.009123592637479305f, 0.005237848497927189f, 0.01346910372376442f, 0.018352020531892776f, 0.009600725956261158f, 0.00717298174276948f, 0.022023694589734077f, 0.0137593699619174f, 0.018270373344421387f, 0.015947889536619186f, 0.00529052596539259f, 0.009171167388558388f, 0.008859125897288322f, 0.01670762151479721f, 0.017597636207938194f, 0.018769746646285057f, 0.010013979859650135f, 0.014135521836578846f, 0.014967828057706356f, 0.007910394109785557f, 0.01435369998216629f, 0.011773094534873962f, 0.05666690692305565f, 0.019357072189450264f, 0.01928178407251835f, 0.009011701680719852f, 0.007682842202484608f, 0.03708641603589058f, 0.007997105829417706f, 0.01545277051627636f, 0.018818285316228867f, 0.025498535484075546f, 0.011259166523814201f, 0.006047595292329788f, 0.0038867758121341467f, 0.007042627781629562f, 0.01170051097869873f, 0.00794421136379242f, 0.004725260194391012f, 0.0063343290239572525f, 0.006589713040739298f, 0.00887949950993061f, 0.0032281726598739624f, 0.004947987850755453f, 0.013118650764226913f, 0.008770269341766834f, 0.010885296389460564f, 0.0029405204113572836f, 0.0023576116655021906f, 0.01866868883371353f, 0.008096067234873772f, 0.007051058113574982f, 0.006653226912021637f, 0.007982724346220493f, 0.0046515450812876225f, 0.0023928808514028788f, 0.007221516687422991f, 0.006211964413523674f, 0.0066942921839654446f, 0.007844026200473309f, 0.00492831552401185f, 0.0056281969882547855f, 0.005248949863016605f, 0.010155155323445797f, 0.008505788631737232f, 0.0105712516233325f, 0.009314699098467827f, 0.03587029129266739f, 0.025890875607728958f, 0.008819110691547394f, 0.01913628727197647f, 0.006513846572488546f, 0.00982305034995079f, 0.012350974604487419f, 0.003354080952703953f, 0.011816564947366714f, 0.007807916961610317f, 0.007124457508325577f, 0.013925482518970966f, 0.012836574576795101f, 0.01620127633213997f, 0.0025973489973694086f, 0.0077794515527784824f, 0.011701153591275215f, 0.008497064933180809f, 0.0029628209304064512f, 0.04161735251545906f, 0.014160282909870148f, 0.010621652938425541f, 0.006678535602986813f, 0.004078375641256571f, 0.012076321989297867f, 0.007784215267747641f, 0.04135670140385628f, 0.01801486872136593f, 0.017405590042471886f, 0.007682053837925196f, 0.006505606696009636f, 0.007928133010864258f, 0.006015673279762268f, 0.006989432033151388f, 0.01429414376616478f, 0.013372855260968208f, 0.008982719853520393f, 0.00928645208477974f, 0.015411416999995708f, 0.015715299174189568f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018284149700775743f, 0.00020987361494917423f, 0.00011410540173528716f, 0.0006423795712180436f, 0.00032047598506323993f, 0.0004347591020632535f, 0.00021351384930312634f, 9.906386549118906e-05f, 0.0002211938553955406f, 0.00022769701899960637f, 0.00012937732390128076f, 0.0004382464976515621f, 0.00025782527518458664f, 9.2132409918122e-05f, 0.00043205267866142094f, 0.00036145580816082656f, 0.00022019560856278986f, 0.00032559610554017127f, 0.0001245876046596095f, 0.0003541163168847561f, 0.0003656383778434247f, 0.00016317676636390388f, 0.00015986648213583976f, 0.00019090458226855844f, 0.00039472448406741023f, 0.00012532845721580088f, 0.00019182295363862067f, 0.00021176731388550252f, 0.00011510763579281047f, 6.283914262894541e-05f, 0.0004355914134066552f, 0.0004579434171319008f, 0.001371365855447948f, 0.0002173413085984066f, 9.989645332098007e-05f, 0.0001952268648892641f, 0.0002295198937645182f, 0.0002146727783838287f, 0.00012324350245762616f, 0.00031692010816186666f, 0.00043181225191801786f, 0.00022589943546336144f, 0.00016877603775355965f, 0.0005182045861147344f, 0.0003237498749513179f, 0.00042989113717339933f, 0.0003752444754354656f, 0.0001244829618372023f, 0.00021579218446277082f, 0.00020845003018621355f, 0.0003931205137632787f, 0.0004140620294492692f, 0.0004416411102283746f, 0.00023562305432278663f, 0.00033260052441619337f, 0.0003521842008922249f, 0.0001861269265646115f, 0.00033773411996662617f, 0.00027701398357748985f, 0.0013333390234038234f, 0.0004554605402518064f, 0.0004536890482995659f, 0.00021204004588071257f, 0.00018077276763506234f, 0.0008726215455681086f, 0.0001881671923911199f, 0.00036359461955726147f, 0.00044278320274315774f, 0.00059996556956321f, 0.00026492157485336065f, 0.00014229636872187257f, 9.145354852080345e-05f, 0.00016570888692513108f, 0.00027530614170245826f, 0.0001869226252892986f, 0.00011118259135400876f, 0.00014904304407536983f, 0.00015505206829402596f, 0.00020892939937766641f, 7.595700299134478e-05f, 0.00011642324534477666f, 0.00030867414898239076f, 0.00020635928376577795f, 0.00025612462195567787f, 6.918871804373339e-05f, 5.5473217798862606e-05f, 0.00043926326907239854f, 0.0001904957025544718f, 0.00016590725863352418f, 0.00015654652088414878f, 0.00018782881670631468f, 0.00010944811947410926f, 5.6303080782527104e-05f, 0.00016991804295685142f, 0.0001461638748878613f, 0.0001575127535033971f, 0.000184565331437625f, 0.00011596037074923515f, 0.00013242816203273833f, 0.00012350470933597535f, 0.00023894483456388116f, 0.00020013620087411255f, 0.0002487353340256959f, 0.0002191693929489702f, 0.0008440068922936916f, 0.0006091970717534423f, 0.00020750849216710776f, 0.0004502655938267708f, 0.0001532669848529622f, 0.00023113060160540044f, 0.000290611176751554f, 7.891955465311185e-05f, 0.00027803683769889176f, 0.00018371570331510156f, 0.00016763429448474199f, 0.00032765843207016587f, 0.0003020370495505631f, 0.0003812065115198493f, 6.111409311415628e-05f, 0.00018304592231288552f, 0.00027532127569429576f, 0.00019993094610981643f, 6.971343827899545e-05f, 0.0009792317869141698f, 0.00033318312489427626f, 0.0002499212569091469f, 0.000157142014359124f, 9.59617827902548e-05f, 0.00028414875851012766f, 0.00018315801571588963f, 0.0009730988531373441f, 0.0004238792753312737f, 0.0004095433105248958f, 0.00018075421394314617f, 0.00015307309513445944f, 0.0001865443045971915f, 0.00014154525706544518f, 0.00016445723304059356f, 0.0003363327996339649f, 0.0003146554226987064f, 0.00021135811402928084f, 0.000218504763324745f, 0.0003626215911936015f, 0.0003697717620525509f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003628865350037813f, 0.007500412408262491f, 0.015160814858973026f, 0.008162318728864193f, 0.0052437689155340195f, 0.010044211521744728f, 0.004964177496731281f, 0.027997678145766258f, 0.005216678604483604f, 0.008123137056827545f, 0.006685988511890173f, 0.00430110190063715f, 0.005413559731096029f, 0.0064776563085615635f, 0.0035529283341020346f, 0.004918596241623163f, 0.00555312167853117f, 0.007565546780824661f, 0.0038453449960798025f, 0.019151892513036728f, 0.006036499515175819f, 0.004654971417039633f, 0.010141790844500065f, 0.0043043941259384155f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.538506517652422e-05f, 0.0001764803018886596f, 0.00035672506783157587f, 0.00019205456192139536f, 0.0001233827933901921f, 0.00023633439559489489f, 0.00011680417810566723f, 0.0006587689276784658f, 0.00012274537584744394f, 0.0001911326398840174f, 0.00015731737948954105f, 0.00010120240040123463f, 0.00012737787619698793f, 0.00015241545042954385f, 8.359831554116681e-05f, 0.00011573168012546375f, 0.00013066169049125165f, 0.0001780128659447655f, 9.047870844369754e-05f, 0.00045063276775181293f, 0.0001420352782588452f, 0.00010952874436043203f, 0.00023863038222771138f, 0.00010127986024599522f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023506056459154934f, 0.0007588862208649516f, 0.0010403073392808437f, 0.0007639709510840476f, 0.0008667036890983582f, 0.0001648663601372391f, 0.0006244828109629452f, 0.0001863505895016715f, 0.0003813433286268264f, 0.0001510681031504646f, 0.0004472937434911728f, 0.00028852102695964277f, 0.0007455504965037107f, 0.0003348307218402624f, 0.0005588523345068097f, 0.00037079930189065635f, 0.00034023940679617226f, 0.0010170558234676719f, 0.00034876487916335464f, 0.0002781157963909209f, 0.0004425643419381231f, 0.00037866985076107085f, 0.0005596335977315903f, 0.0007637812523171306f, 0.000531388446688652f, 0.00038902548840269446f, 0.000465619406895712f, 0.0004236075037624687f, 0.0004153379122726619f, 0.00038240879075601697f, 0.00047594052739441395f, 0.0004819018067792058f, 0.0007148489821702242f, 0.0005808657733723521f, 0.0007505491957999766f, 0.0006664496031589806f, 0.0007143912371248007f, 0.0006259824731387198f, 0.0003090424579568207f, 0.00046831893268972635f, 0.0005327382823452353f, 0.0005003552651032805f, 0.0008618361898697913f, 0.00016652658814564347f, 0.0005279479082673788f, 0.00012001109280390665f, 0.00044023117516189814f, 0.0003395307285245508f, 0.0004869070544373244f, 0.00048455398064106703f, 0.000766462238971144f, 0.0006569268880411983f, 0.0005661780596710742f, 0.00015516550047323108f, 0.0005421282257884741f, 0.0006418303237296641f, 0.0004394509887788445f, 0.0005782778607681394f, 0.00043153707520104945f, 0.0006355877267196774f, 0.0006076178979128599f, 0.0002412148314760998f, 0.0006063374457880855f, 0.0005509160691872239f, 0.0005748166586272418f, 0.0004601626133080572f, 0.00045505131129175425f, 0.0006124486098997295f, 0.0008039374370127916f, 0.0007439421606250107f, 0.0007027516840025783f, 0.0011108873877674341f, 0.0005807458655908704f, 0.0003240286314394325f, 0.0006048693903721869f, 0.000739065115340054f, 0.00047115367488004267f, 0.00022427465592045337f, 0.00023846082331147045f, 0.00041022602817974985f, 0.0003563198260962963f, 0.000841837259940803f, 0.0003522022452671081f, 0.00022798361897002906f, 0.00041755614802241325f, 0.000630146125331521f, 0.000623756495770067f, 0.0006893842364661396f, 0.0006609975243918598f, 0.0003604880184866488f, 0.00045289075933396816f, 0.0008431024034507573f, 0.0004757782444357872f, 0.00042669285903684795f, 0.0015535596758127213f, 0.0007586163119412959f, 0.0005580002325586975f, 0.00019887665985152125f, 0.0007517575868405402f, 0.00043337364331819117f, 0.00038647212204523385f, 0.00043676773202605546f, 0.000550761295016855f, 0.00033200657344423234f, 0.0007249379996210337f, 0.0005995423998683691f, 0.0007043674704618752f, 0.000621921441052109f, 0.0003870141808874905f, 0.0006120040197856724f, 0.0003537189622875303f, 0.00031967650284059346f, 0.00044657994294539094f, 0.000813526741694659f, 0.0004864188958890736f, 0.0002842865651473403f, 0.0007092055748216808f, 0.00029053210164420307f, 0.0003859683929476887f, 0.00033929877099581063f, 0.0007309172651730478f, 0.0008668168447911739f, 0.00041500982479192317f, 0.0006599319749511778f, 0.0004633626085706055f, 0.0003564207290764898f, 0.0007325699552893639f, 0.0008042152621783316f, 0.0004150244640186429f, 0.0010283748852089047f, 0.0004909159033559263f, 0.00042538114939816296f, 0.0004715926479548216f, 0.0006402151193469763f, 0.0004656906530726701f, 0.00031363850575871766f, 0.0007814471027813852f, 0.0009410101920366287f, 0.001139155705459416f, 0.0006877121631987393f, 0.00043513596756383777f, 0.00021637577447108924f, 0.00042131319059990346f, 0.0005095335654914379f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.780632924754173e-05f, 0.0002834801853168756f, 0.000388604385079816f, 0.00028537955950014293f, 0.0003237551427446306f, 6.15854442003183e-05f, 0.00023327409871853888f, 6.961083272472024e-05f, 0.00014244990597944707f, 5.643113763653673e-05f, 0.00016708554176148027f, 0.00010777635907288641f, 0.0002784986572805792f, 0.00012507523933891207f, 0.00020875799236819148f, 0.00013851121184416115f, 0.00012709564180113375f, 0.0003799188416451216f, 0.0001302803138969466f, 0.00010388950613560155f, 0.00016531888104509562f, 0.0001414512371411547f, 0.00020904983102809638f, 0.00028530872077681124f, 0.0001984989212360233f, 0.00014531957276631147f, 0.00017393103917129338f, 0.0001582375989528373f, 0.00015514850383624434f, 0.00014284791541285813f, 0.0001777864817995578f, 0.00018001330317929387f, 0.00026703017647378147f, 0.00021698106138501316f, 0.00028036590083502233f, 0.00024895070237107575f, 0.00026685919146984816f, 0.0002338342892471701f, 0.00011544208973646164f, 0.00017493944324087352f, 0.00019900314509868622f, 0.00018690654542297125f, 0.0003219369100406766f, 6.220561772352085e-05f, 0.00019721371063496917f, 4.482986332732253e-05f, 0.00016444733773823828f, 0.0001268309133592993f, 0.00018188299145549536f, 0.00018100401211995631f, 0.00028631018358282745f, 0.00024539351579733193f, 0.0002114944945788011f, 5.7961711718235165e-05f, 0.00020251073874533176f, 0.00023975422664079815f, 0.00016415589198004454f, 0.0002160143485525623f, 0.00016119967040140182f, 0.00023742231132928282f, 0.00022697425447404385f, 9.010524081531912e-05f, 0.00022649594757240266f, 0.00020579341799020767f, 0.00021472142543643713f, 0.0001718926796456799f, 0.00016998335195239633f, 0.00022877875017002225f, 0.0003003089514095336f, 0.00027789786690846086f, 0.0002625112538225949f, 0.00041496939957141876f, 0.00021693627058994025f, 0.00012104013876523823f, 0.00022594755864702165f, 0.0002760760544333607f, 0.00017599835700821131f, 8.377727499464527e-05f, 8.907648589229211e-05f, 0.0001532389724161476f, 0.00013310243957675993f, 0.00031446636421605945f, 0.00013156433124095201f, 8.516274829162285e-05f, 0.00015597713354509324f, 0.00023538961249869317f, 0.0002330027928110212f, 0.0002575178805273026f, 0.00024691407452337444f, 0.00013465946540236473f, 0.00016917628818191588f, 0.0003149389522150159f, 0.00017772585852071643f, 0.00015939012519083917f, 0.0005803285748697817f, 0.00028337936964817345f, 0.00020843968377448618f, 7.428991375491023e-05f, 0.00028081730124540627f, 0.00016188572044484317f, 0.00014436576748266816f, 0.00016315357061102986f, 0.00020573560323100537f, 0.0001240202836925164f, 0.00027079888968728483f, 0.00022395767155103385f, 0.0002631148381624371f, 0.00023231731029227376f, 0.00014456824283115566f, 0.00022861268371343613f, 0.00013213089550845325f, 0.00011941441334784031f, 0.00016681889246683568f, 0.00030389102175831795f, 0.0001817006414057687f, 0.00010619458771543577f, 0.0002649220987223089f, 0.00010852758714463562f, 0.00014417759666685015f, 0.0001267442712560296f, 0.0002730324340518564f, 0.00032379740150645375f, 0.00015502594760619104f, 0.00024651605053804815f, 0.00017308801761828363f, 0.0001331401290372014f, 0.0002736498136073351f, 0.00030041273566894233f, 0.0001550314191263169f, 0.00038414704613387585f, 0.00018338049994781613f, 0.0001589001331012696f, 0.00017616234254091978f, 0.0002391508751315996f, 0.00017395765462424606f, 0.00011715893197106197f, 0.0002919077523984015f, 0.00035151216434314847f, 0.0004255289677530527f, 0.00025689328322187066f, 0.00016254403453785926f, 8.082667045528069e-05f, 0.00015738056390546262f, 0.00019033507851418108f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014569169841706753f, 0.010207078419625759f, 0.0037773754447698593f, 0.005221056751906872f, 0.003568024607375264f, 0.021252786740660667f, 0.01084427535533905f, 0.013820446096360683f, 0.005875210277736187f, 0.016120105981826782f, 0.004707337357103825f, 0.02068357542157173f, 0.019882438704371452f, 0.004506937228143215f, 0.007336767390370369f, 0.01764710247516632f, 0.029216591268777847f, 0.014859510585665703f, 0.023751284927129745f, 0.021955039352178574f, 0.024206288158893585f, 0.007411535829305649f, 0.012315942905843258f, 0.011210917495191097f, 0.005726974457502365f, 0.012836677953600883f, 0.013323872350156307f, 0.013565508648753166f, 0.018167704343795776f, 0.0065430933609604836f, 0.00840490311384201f, 0.007663619238883257f, 0.010070648044347763f, 0.005232520867139101f, 0.004137259442359209f, 0.0081876739859581f, 0.006826142314821482f, 0.016438396647572517f, 0.019438311457633972f, 0.017231211066246033f, 0.010614978149533272f, 0.009478947147727013f, 0.008997851051390171f, 0.014240371994674206f, 0.005271405912935734f, 0.007931199856102467f, 0.005713297985494137f, 0.012175007723271847f, 0.014446581713855267f, 0.01617259904742241f, 0.00808741245418787f, 0.011535324156284332f, 0.0068874964490532875f, 0.018600301817059517f, 0.0035701747983694077f, 0.008467195555567741f, 0.007105120457708836f, 0.01823943853378296f, 0.005428729113191366f, 0.006374526768922806f, 0.009602192789316177f, 0.009975905530154705f, 0.004092562478035688f, 0.005058232694864273f, 0.017005810514092445f, 0.012853565625846386f, 0.005265115760266781f, 0.004892564378678799f, 0.006380057893693447f, 0.0038961044047027826f, 0.007410638965666294f, 0.004593213554471731f, 0.012758273631334305f, 0.009232853539288044f, 0.0055731115862727165f, 0.002767599653452635f, 0.021776694804430008f, 0.006504530552774668f, 0.015330747701227665f, 0.00790778174996376f, 0.01103116013109684f, 0.009792930446565151f, 0.016497153788805008f, 0.010312735103070736f, 0.016231583431363106f, 0.007697708439081907f, 0.009594520553946495f, 0.006402936298400164f, 0.0021217770408838987f, 0.012162039056420326f, 0.017788920551538467f, 0.004527026321738958f, 0.0062927370890975f, 0.005699901841580868f, 0.01091885007917881f, 0.0025338574778288603f, 0.0105001674965024f, 0.01662973314523697f, 0.008111396804451942f, 0.008912362158298492f, 0.011376680806279182f, 0.013415585272014141f, 0.056082919239997864f, 0.030878014862537384f, 0.0069015114568173885f, 0.0034434092231094837f, 0.008506136015057564f, 0.008634507656097412f, 0.009006448090076447f, 0.010262572206556797f, 0.01058070920407772f, 0.009797985665500164f, 0.014658286236226559f, 0.00832708552479744f, 0.01011680718511343f, 0.013275912962853909f, 0.005987029056996107f, 0.009112955071032047f, 0.008542673662304878f, 0.027979036793112755f, 0.019385088235139847f, 0.009831232950091362f, 0.006235640496015549f, 0.018071046099066734f, 0.026223300024867058f, 0.020223524421453476f, 0.003644043579697609f, 0.005722150672227144f, 0.006657289806753397f, 0.004682144150137901f, 0.00915312860161066f, 0.008489015512168407f, 0.003211069153621793f, 0.0064776986837387085f, 0.011064814403653145f, 0.025172483175992966f, 0.006401213351637125f, 0.008981887251138687f, 0.018374085426330566f, 0.0056771570816636086f, 0.01105764415115118f, 0.01576227694749832f, 0.017777232453227043f, 0.00622217170894146f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003428040072321892f, 0.00024016655515879393f, 8.887942385626957e-05f, 0.00012284840340726078f, 8.395352051593363e-05f, 0.0005000655655749142f, 0.00025515942252241075f, 0.0003251869638916105f, 0.00013824024063069373f, 0.00037929663085378706f, 0.00011076088412664831f, 0.0004866723611485213f, 0.00046782210119999945f, 0.00010604558337945491f, 0.00017262982146348804f, 0.00041522594983689487f, 0.0006874492391943932f, 0.0003496355493552983f, 0.0005588537896983325f, 0.000516589148901403f, 0.0005695597501471639f, 0.00017438907525502145f, 0.0002897868980653584f, 0.0002637862926349044f, 0.00013475233572535217f, 0.00030203949427232146f, 0.0003135028819087893f, 0.00031918843160383403f, 0.0004274754028301686f, 0.00015395514492411166f, 0.00019776243425440043f, 0.000180320450454019f, 0.00023695643176324666f, 0.00012311813770793378f, 9.734728519106284e-05f, 0.00019265116134192795f, 0.00016061511996667832f, 0.0003867858031298965f, 0.0004573720507323742f, 0.0004054402816109359f, 0.0002497641835361719f, 0.0002230340614914894f, 0.00021171414118725806f, 0.0003350675688125193f, 0.00012403308937791735f, 0.00018661646754480898f, 0.0001344305492239073f, 0.0002864707785192877f, 0.0003399195848032832f, 0.00038053173921070993f, 0.00019029206305276603f, 0.0002714193833526224f, 0.00016205874271690845f, 0.00043765417649410665f, 8.400411752518266e-05f, 0.000199228132260032f, 0.00016717931430321187f, 0.0004291632794775069f, 0.0001277348055737093f, 0.000149988874909468f, 0.00022593395260628313f, 0.00023472719476558268f, 9.629558917367831e-05f, 0.00011901724064955488f, 0.0004001367196906358f, 0.00030243684886954725f, 0.00012388508184812963f, 0.00011511916090967134f, 0.00015011901268735528f, 9.167304961010814e-05f, 0.00017436797497794032f, 0.00010807561193360016f, 0.0003001946897711605f, 0.00021724362159147859f, 0.00013113203749526292f, 6.51199952699244e-05f, 0.0005123928422108293f, 0.00015304777480196208f, 0.0003607234684750438f, 0.00018606545927468687f, 0.00025955672026611865f, 0.00023042189422994852f, 0.00038816832238808274f, 0.0002426525898044929f, 0.0003819196135737002f, 0.0001811225520214066f, 0.00022575343609787524f, 0.00015065733168739825f, 4.992416506865993e-05f, 0.00028616562485694885f, 0.00041856284951791167f, 0.00010651826596586034f, 0.0001480643986724317f, 0.00013411534018814564f, 0.0002569141215644777f, 5.96201753069181e-05f, 0.0002470627659931779f, 0.0003912878455594182f, 0.00019085640087723732f, 0.00020970264449715614f, 0.0002676866133697331f, 0.0003156608436256647f, 0.0013195981737226248f, 0.0007265415624715388f, 0.00016238850366789848f, 8.102139690890908e-05f, 0.0002001443790504709f, 0.00020316489099059254f, 0.0002119164273608476f, 0.00024147229851223528f, 0.0002489578619133681f, 0.0002305408415850252f, 0.00034490085090510547f, 0.00019593142496887594f, 0.00023804252850823104f, 0.00031237443909049034f, 0.00014087127055972815f, 0.00021442247088998556f, 0.00020100409165024757f, 0.000658330274745822f, 0.0004561197420116514f, 0.00023132313799578696f, 0.00014672095130663365f, 0.00042520108399912715f, 0.0006170188426040113f, 0.0004758476570714265f, 8.574220555601642e-05f, 0.00013463884533848614f, 0.00015664211241528392f, 0.00011016809730790555f, 0.00021536773419938982f, 0.000199741538381204f, 7.55545697757043e-05f, 0.00015241643995977938f, 0.00026034857728518546f, 0.0005922937416471541f, 0.00015061679005157202f, 0.00021133852715138346f, 0.00043233143514953554f, 0.000133580164401792f, 0.00026017986238002777f, 0.00037087712553329766f, 0.00041828781832009554f, 0.00014640403969679028f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005982331000268459f, 0.00666272034868598f, 0.017689691856503487f, 0.006585512310266495f, 0.008149242959916592f, 0.008577118627727032f, 0.006963652092963457f, 0.038691043853759766f, 0.00530588161200285f, 0.009812149219214916f, 0.005441062618046999f, 0.003728121053427458f, 0.00915196817368269f, 0.013430507853627205f, 0.004916745238006115f, 0.004910340066999197f, 0.006700149737298489f, 0.004848523065447807f, 0.007107061799615622f, 0.026208410039544106f, 0.006435164716094732f, 0.004877438303083181f, 0.008429085835814476f, 0.005698179826140404f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00014076073421165347f, 0.0001567698927829042f, 0.0004162280529271811f, 0.0001549532316857949f, 0.000191746890777722f, 0.00020181456056889147f, 0.0001638506364542991f, 0.0009103775373660028f, 0.00012484427134040743f, 0.00023087410954758525f, 0.0001280249998671934f, 8.77204947755672e-05f, 0.0002153404348064214f, 0.00031601195223629475f, 0.00011568812624318525f, 0.00011553741205716506f, 0.0001576505892444402f, 0.00011408289719838649f, 0.0001672249927651137f, 0.0006166684906929731f, 0.00015141564654186368f, 0.00011476325744297355f, 0.0001983314286917448f, 0.00013407482765614986f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005835427436977625f, 0.00028332899091765285f, 0.0007533903117291629f, 0.0011294441064819694f, 0.001044846256263554f, 0.0014464783016592264f, 0.0006173718138597906f, 0.000614990247413516f, 0.0005290806875564158f, 0.0007991398451849818f, 0.0004095713666174561f, 0.0005671363323926926f, 0.0012536321301013231f, 0.00032942669349722564f, 0.00039782506064511836f, 0.0006319028907455504f, 0.00018774913041852415f, 0.0006110394606366754f, 0.0005251453258097172f, 0.0010172538459300995f, 0.0005393986357375979f, 0.0009466919000260532f, 0.0008840411901473999f, 0.0002954395313281566f, 0.00044648631592281163f, 0.0008952358039095998f, 0.0007655100780539215f, 0.0005135199171490967f, 0.0006104467902332544f, 0.0004968278808519244f, 0.00015565991634503007f, 0.0005530068301595747f, 0.00040252262260764837f, 0.0004453956207726151f, 0.0003244997060392052f, 0.0002916337689384818f, 0.0009714551852084696f, 0.0004705564642790705f, 0.0005708308308385313f, 0.0006057701539248228f, 0.0012334929779171944f, 0.00031170836882665753f, 0.0006190382991917431f, 0.0003027997736353427f, 0.0010596003849059343f, 0.001623203861527145f, 0.0008116440149024129f, 0.0006980348262004554f, 0.0008060663822107017f, 0.0005397400818765163f, 0.00035953952465206385f, 0.0010170702589675784f, 0.0005415404448285699f, 0.00040739704854786396f, 0.00043454417027533054f, 0.0002637373690959066f, 0.0004884660593234003f, 0.0007395823486149311f, 0.00025443595950491726f, 0.0009187788236886263f, 0.0007339130970649421f, 0.00048640050226822495f, 0.000485553260659799f, 0.0005895986105315387f, 0.0006902909372001886f, 0.0008376860059797764f, 0.0008121318533085287f, 0.0003551849804352969f, 0.0006113677518442273f, 0.0005125415045768023f, 0.000778182118665427f, 0.000298467930406332f, 0.000596473051700741f, 0.0004952165763825178f, 0.0002110772329615429f, 0.0006172737339511514f, 0.0005312132416293025f, 0.0004777119611389935f, 0.0004008856776636094f, 0.0013674255460500717f, 0.0006314364145509899f, 0.0004932520678266883f, 0.0009115136344917119f, 0.00048279028851538897f, 0.001112000667490065f, 0.00023405718093272299f, 0.000579975894652307f, 0.0005971510545350611f, 0.000361010868800804f, 0.00026948945014737546f, 0.00029044898110441864f, 0.0010813872795552015f, 0.00044641009299084544f, 0.0008254132117144763f, 0.0006594355800189078f, 0.0006454312242567539f, 0.0005479387473315f, 0.0005499967955984175f, 0.0010996871860697865f, 0.00044408527901396155f, 0.0011526776943355799f, 0.00048305914970114827f, 0.0010191032197326422f, 0.0009246006375178695f, 0.0009936051210388541f, 0.00043894984992221f, 0.00038560759276151657f, 0.0004840582550968975f, 0.00020910876628477126f, 0.0007815423305146396f, 0.0008191009401343763f, 0.00034576666075736284f, 0.0008692452684044838f, 0.0005294567090459168f, 0.0008932146010920405f, 0.0006255168118514121f, 0.0006600238266400993f, 0.0016735900426283479f, 0.0006292436155490577f, 0.00031638695509172976f, 0.0007264931919053197f, 0.0007040323689579964f, 0.00028016226133331656f, 0.0004774887638632208f, 0.0001705130998743698f, 0.0006853630766272545f, 0.000165662364452146f, 0.0008556713000871241f, 0.0005563818849623203f, 0.00041263768798671663f, 0.00041210491326637566f, 0.0005473679048009217f, 0.0005976079846732318f, 0.0007575172930955887f, 0.0005328389815986156f, 0.00028955971356481314f, 0.000653016846626997f, 0.0004290059441700578f, 0.0009435053216293454f, 0.0009574803407303989f, 0.0008024924318306148f, 0.0003252826863899827f, 0.00021554766863118857f, 0.0004534166364464909f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021925884357187897f, 0.00010645730799296871f, 0.00028307695174589753f, 0.0004243744187988341f, 0.0003925878554582596f, 0.0005434960476122797f, 0.00023196969414129853f, 0.00023107485321816057f, 0.00019879541650880128f, 0.00030026675085537136f, 0.0001538912911200896f, 0.00021309434669092298f, 0.00047103650285862386f, 0.00012377793609630316f, 0.00014947776799090207f, 0.00023742957273498178f, 7.054437446640804e-05f, 0.00022959039779379964f, 0.00019731675274670124f, 0.0003822203434538096f, 0.0002026722504524514f, 0.000355707568814978f, 0.0003321673721075058f, 0.00011100769188487902f, 0.0001677616237429902f, 0.00033637360320426524f, 0.0002876307989936322f, 0.00019294864614494145f, 0.00022936770983505994f, 0.00018667682888917625f, 5.848725777468644e-05f, 0.0002077853714581579f, 0.00015124281344469637f, 0.0001673517981544137f, 0.00012192668509669602f, 0.0001095777188311331f, 0.00036501206341199577f, 0.00017680568271316588f, 0.0002144825120922178f, 0.00022761052241548896f, 0.00046346947783604264f, 0.00011712050036294386f, 0.00023259586305357516f, 0.000113773210614454f, 0.00039813152397982776f, 0.0006098984740674496f, 0.0003049650404136628f, 0.0002622778119985014f, 0.00030286930268630385f, 0.00020280055468901992f, 0.0001350924576399848f, 0.00038215136737562716f, 0.00020347701502032578f, 0.00015307431749533862f, 0.00016327451157849282f, 9.909600339597091e-05f, 0.00018353498307988048f, 0.0002778887574095279f, 9.560111357131973e-05f, 0.0003452195960562676f, 0.0002757586189545691f, 0.00018275887123309076f, 0.000182440533535555f, 0.00022153426834847778f, 0.000259368127444759f, 0.0003147499810438603f, 0.0003051483363378793f, 0.00013345629849936813f, 0.00022971373982727528f, 0.00019258102111052722f, 0.0002923921565525234f, 0.00011214557162020355f, 0.00022411724785342813f, 0.00018607139645610005f, 7.930961874080822e-05f, 0.0002319328486919403f, 0.00019959670316893607f, 0.00017949426546692848f, 0.00015062774764373899f, 0.0005137929692864418f, 0.0002372542949160561f, 0.00018533326510805637f, 0.0003424898022785783f, 0.00018140238535124809f, 0.0004178202652838081f, 8.794404129730538e-05f, 0.00021791865583509207f, 0.00022437200823333114f, 0.00013564529945142567f, 0.0001012572756735608f, 0.00010913255391642451f, 0.0004063176747877151f, 0.00016773298557382077f, 0.00031013862462714314f, 0.00024777461658231914f, 0.00024251267313957214f, 0.00020588109327945858f, 0.000206654382054694f, 0.00041319362935610116f, 0.00016685946320649236f, 0.0004331041418481618f, 0.0001815034047467634f, 0.0003829152265097946f, 0.0003474070690572262f, 0.0003733346238732338f, 0.00016492989379912615f, 0.00014488720626104623f, 0.0001818788005039096f, 7.856998854549602e-05f, 0.00029365470982156694f, 0.000307766895275563f, 0.0001299174764426425f, 0.000326607987517491f, 0.0001989367010537535f, 0.00033561416785232723f, 0.0002350300783291459f, 0.00024799566017463803f, 0.000628830399364233f, 0.0002364303800277412f, 0.00011887842265423387f, 0.0002729706757236272f, 0.0002645313215907663f, 0.00010526744881644845f, 0.0001794104027794674f, 6.406815373338759e-05f, 0.00025751657085493207f, 6.224554817890748e-05f, 0.0003215077449567616f, 0.00020905349811073393f, 0.0001550434244563803f, 0.00015484323375858366f, 0.00020566661260090768f, 0.00022454369172919542f, 0.0002846276038326323f, 0.00020020754891447723f, 0.00010879842011490837f, 0.000245362869463861f, 0.00016119358770083636f, 0.00035451026633381844f, 0.0003597612085286528f, 0.00030152645194903016f, 0.0001222208811668679f, 8.098932448774576e-05f, 0.00017036560166161507f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003223513951525092f, 0.005364398472011089f, 0.00642582168802619f, 0.004531473387032747f, 0.009633838199079037f, 0.004379543010145426f, 0.007779758423566818f, 0.006985037587583065f, 0.007385300938040018f, 0.00428188918158412f, 0.01065430510789156f, 0.006668583955615759f, 0.005286168772727251f, 0.009965977631509304f, 0.015596738085150719f, 0.0059110852889716625f, 0.01789042167365551f, 0.012679841369390488f, 0.015414506196975708f, 0.009099990129470825f, 0.004877472296357155f, 0.009855508804321289f, 0.004765290766954422f, 0.015920346602797508f, 0.016728796064853668f, 0.0146328741684556f, 0.009142102673649788f, 0.009425316005945206f, 0.007310624234378338f, 0.008274335414171219f, 0.02797349914908409f, 0.00861399620771408f, 0.007266646716743708f, 0.007698267698287964f, 0.014322351664304733f, 0.016222447156906128f, 0.00270505016669631f, 0.00925531517714262f, 0.010886802338063717f, 0.015874357894062996f, 0.0068466258235275745f, 0.01193843875080347f, 0.0030561434105038643f, 0.00830394122749567f, 0.005479441024363041f, 0.004308190196752548f, 0.00959772989153862f, 0.004560805857181549f, 0.0070465425960719585f, 0.007203156594187021f, 0.009403245523571968f, 0.00824892707169056f, 0.010728368535637856f, 0.005773797631263733f, 0.00688487384468317f, 0.019189992919564247f, 0.006395245436578989f, 0.005482919048517942f, 0.014647303149104118f, 0.006723707541823387f, 0.002541564404964447f, 0.010621992871165276f, 0.010423026978969574f, 0.004637212958186865f, 0.004908833187073469f, 0.0033989569637924433f, 0.007449631113559008f, 0.009976105764508247f, 0.004605618305504322f, 0.00539243733510375f, 0.0047334409318864346f, 0.01569911278784275f, 0.005901175085455179f, 0.0099107027053833f, 0.023872854188084602f, 0.02959088794887066f, 0.006374569609761238f, 0.007960583083331585f, 0.02933008037507534f, 0.0022984417155385017f, 0.022127076983451843f, 0.013361423276364803f, 0.006743098609149456f, 0.0112611660733819f, 0.0066822892986238f, 0.01749037764966488f, 0.004111333750188351f, 0.00634831003844738f, 0.007862817496061325f, 0.018874067813158035f, 0.009029805660247803f, 0.00611332431435585f, 0.004900125786662102f, 0.004367876797914505f, 0.006260947789996862f, 0.00318129057995975f, 0.0043747639283537865f, 0.015510937198996544f, 0.01493098959326744f, 0.010049400851130486f, 0.014177573844790459f, 0.004140621516853571f, 0.005764603149145842f, 0.014185138046741486f, 0.00822214875370264f, 0.010141265578567982f, 0.01498823519796133f, 0.0070697772316634655f, 0.027750609442591667f, 0.0042922827415168285f, 0.005681085400283337f, 0.006062026135623455f, 0.004993744660168886f, 0.004381499718874693f, 0.010638498701155186f, 0.009167945943772793f, 0.009896470233798027f, 0.0032514436170458794f, 0.00743849016726017f, 0.011627416126430035f, 0.010542372241616249f, 0.006044985726475716f, 0.015575551427900791f, 0.00872048456221819f, 0.036982111632823944f, 0.008862648159265518f, 0.017641078680753708f, 0.0029955448117107153f, 0.00836143922060728f, 0.012656434439122677f, 0.00986893568187952f, 0.008782514370977879f, 0.004905096720904112f, 0.009514435194432735f, 0.010486636310815811f, 0.00682036392390728f, 0.009407316334545612f, 0.011522221378982067f, 0.002957176184281707f, 0.005002839490771294f, 0.005948212463408709f, 0.01896769553422928f, 0.01577766053378582f, 0.006878270767629147f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.58473906898871e-05f, 0.00012622114445548505f, 0.00015119581075850874f, 0.00010662290878826752f, 0.0002266785450046882f, 0.0001030480707413517f, 0.0001830531400628388f, 0.0001643538271309808f, 0.00017377178301103413f, 0.0001007503378787078f, 0.00025068953982554376f, 0.00015690785949118435f, 0.00012438044359441847f, 0.0002344935928704217f, 0.0003669820725917816f, 0.00013908436812926084f, 0.00042095110984519124f, 0.000298349215881899f, 0.00036269426345825195f, 0.0002141174190910533f, 0.00011476405779831111f, 0.00023189432977233082f, 0.00011212449317099527f, 0.00037459639133885503f, 0.00039361874223686755f, 0.00034430294181220233f, 0.0002151083026546985f, 0.0002217721485067159f, 0.00017201469745486975f, 0.00019469024846330285f, 0.0006582000060006976f, 0.00020268226217012852f, 0.0001709799253148958f, 0.00018113570695277303f, 0.0003369965124875307f, 0.00038170465268194675f, 6.364824366755784e-05f, 0.00021777213260065764f, 0.00025616007042117417f, 0.00037351431092247367f, 0.00016109707939904183f, 0.00028090443811379373f, 7.190925680333748e-05f, 0.0001953868631972f, 0.00012892803351860493f, 0.00010136917990166694f, 0.00022582894598599523f, 0.00010731308429967612f, 0.00016580100054852664f, 0.0001694860402494669f, 0.00022125283430796117f, 0.00019409241212997586f, 0.00025243221898563206f, 0.00013585406122729182f, 0.00016199702804442495f, 0.0004515292530413717f, 0.00015047636406961828f, 0.00012900985893793404f, 0.00034464243799448013f, 0.00015820488624740392f, 5.98015176365152e-05f, 0.0002499292604625225f, 0.0002452477056067437f, 0.00010911089339060709f, 0.00011550195631571114f, 7.997545617399737e-05f, 0.0001752854441292584f, 0.00023473190958611667f, 0.00010836749424925074f, 0.00012688088463619351f, 0.0001113750840886496f, 0.0003693909093271941f, 0.0001388511882396415f, 0.00023319301544688642f, 0.0005617142305709422f, 0.0006962561747059226f, 0.00014998987899161875f, 0.00018730784358922392f, 0.0006901195738464594f, 5.408098149928264e-05f, 0.0005206371424719691f, 0.00031438644509762526f, 0.00015866114699747413f, 0.00026496860664337873f, 0.0001572303444845602f, 0.00041153831989504397f, 9.67372689046897e-05f, 0.0001493720046710223f, 0.0001850074768299237f, 0.0004440957272890955f, 0.00021246602409519255f, 0.00014384293172042817f, 0.00011529707990121096f, 0.0001027735706884414f, 0.00014731641567777842f, 7.485389505745843e-05f, 0.00010293562081642449f, 0.00036496322718448937f, 0.000351317401509732f, 0.0002364565007155761f, 0.00033358996734023094f, 9.742638940224424e-05f, 0.0001356377179035917f, 0.0003337679663673043f, 0.0001934623287525028f, 0.00023861801309976727f, 0.0003526643558871001f, 0.00016634770145174116f, 0.0006529555539600551f, 0.00010099489009007812f, 0.00013367259816732258f, 0.00014263590855989605f, 0.000117499876068905f, 0.00010309411300113425f, 0.00025031762197613716f, 0.00021571638353634626f, 0.00023285813222173601f, 7.650455518160015e-05f, 0.0001750233059283346f, 0.00027358627994544804f, 0.0002480558177921921f, 0.00014223495963960886f, 0.0003664835821837187f, 0.00020518786914180964f, 0.000870167335961014f, 0.0002085329033434391f, 0.0004150842141825706f, 7.04834092175588e-05f, 0.00019673975475598127f, 0.00029779845499433577f, 0.00023221025185193866f, 0.00020664739713538438f, 0.00011541404091985896f, 0.00022386906493920833f, 0.0002467443991918117f, 0.0001604791614226997f, 0.0002213486295659095f, 0.0002711110864765942f, 6.958061567274854e-05f, 0.00011771386925829574f, 0.00013995794870425016f, 0.0004462987126316875f, 0.00037123908987268806f, 0.0001618416717974469f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.010072327218949795f, 0.004980730824172497f, 0.018507588654756546f, 0.009675494395196438f, 0.006775814574211836f, 0.00741297984495759f, 0.004412394482642412f, 0.021309129893779755f, 0.00467758160084486f, 0.006494673900306225f, 0.0060251024551689625f, 0.0038055621553212404f, 0.005347906611859798f, 0.008736690506339073f, 0.0040984670631587505f, 0.00489849504083395f, 0.005306367762386799f, 0.012958716601133347f, 0.005841991864144802f, 0.02403208613395691f, 0.004601746331900358f, 0.004707734100520611f, 0.006505964323878288f, 0.004280445631593466f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023699594021309167f, 0.00011719366739271209f, 0.0004354726697783917f, 0.00022765868925489485f, 0.0001594309287611395f, 0.0001744230539770797f, 0.0001038210466504097f, 0.0005013913032598794f, 0.00011006074782926589f, 0.0001528158609289676f, 0.00014176711556501687f, 8.954264194471762e-05f, 0.00012583310308400542f, 0.00020556918752845377f, 9.643452358432114e-05f, 0.00011525870650075376f, 0.00012485570914577693f, 0.00030491099460050464f, 0.0001374586281599477f, 0.0005654608830809593f, 0.00010827638470800593f, 0.0001107702191802673f, 0.00015308152069337666f, 0.00010071636643260717f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006198852206580341f, 0.0010320278815925121f, 0.0004002102359663695f, 0.0007939031347632408f, 0.00041820004116743803f, 0.0007559711229987442f, 0.0005623423494398594f, 0.0007782140746712685f, 0.0007468509138561785f, 0.000886112276930362f, 0.0003410378412809223f, 0.0012540074530988932f, 0.000671971298288554f, 0.0006192887667566538f, 0.0007519508362747729f, 0.0007301844307221472f, 0.0008860192610882223f, 0.0003922860196325928f, 0.0007499349303543568f, 0.0005282359197735786f, 0.0005579103017225862f, 0.0003394581435713917f, 0.0005469137104228139f, 0.0008093463256955147f, 0.0005302578210830688f, 0.0009770540054887533f, 0.0006173731526359916f, 0.0010324536124244332f, 0.0006497440044768155f, 0.0009684872347861528f, 0.0005799397476948798f, 0.00125438766553998f, 0.0008091209456324577f, 0.0007411343976855278f, 0.0008008591248653829f, 0.0006920581217855215f, 0.0011292621493339539f, 0.0008009717566892505f, 0.0004015379527118057f, 0.0008228023652918637f, 0.0004978229990229011f, 0.000863854365888983f, 0.0008857736829668283f, 0.0006496999994851649f, 0.0012996330624446273f, 0.0009658146882429719f, 0.0006460836157202721f, 0.0005693843122571707f, 0.0007150977035053074f, 0.0005215759738348424f, 0.0005150356446392834f, 0.0006879389402456582f, 0.0009466081974096596f, 0.0006290299352258444f, 0.0006375999073497951f, 0.0009207448456436396f, 0.0006483892793767154f, 0.0007840244215913117f, 0.0009277794160880148f, 0.0005291866837069392f, 0.00046959047904238105f, 0.0008216159767471254f, 0.0006239418871700764f, 0.0006410378846339881f, 0.0006945852073840797f, 0.0007213123026303947f, 0.0006270427256822586f, 0.00021604329231195152f, 0.0004716675030067563f, 0.0006944314227439463f, 0.0006967515219002962f, 0.0006447926280088723f, 0.0004966161213815212f, 0.0005261161713860929f, 0.0005818528588861227f, 0.0009254010510630906f, 0.00027226153179071844f, 0.0006615486927330494f, 0.0006844529416412115f, 0.0006705727428197861f, 0.00028034314163960516f, 0.0006022870074957609f, 0.0007565465639345348f, 0.00026086249272339046f, 0.0004441038763616234f, 0.001150644849985838f, 0.000566835340578109f, 0.0009031176450662315f, 0.0006849906058050692f, 0.0007131177117116749f, 0.0008344878442585468f, 0.0008189263171516359f, 0.0008964960579760373f, 0.0011521480046212673f, 0.0005290813278406858f, 0.0008166925399564207f, 0.0010505489772185683f, 0.0015996068250387907f, 0.0006569954566657543f, 0.0005685243522748351f, 0.0005701498012058437f, 0.0006895050755701959f, 0.0003745068097487092f, 0.000967219122685492f, 0.0005011633620597422f, 0.0008844969561323524f, 0.0009797693928703666f, 0.0007045354577712715f, 0.000412367022363469f, 0.000849782838486135f, 0.0005933455540798604f, 0.0007764726178720593f, 0.000696158385835588f, 0.0013163612456992269f, 0.0006586109520867467f, 0.001290567102842033f, 0.0007947749109007418f, 0.000685282691847533f, 0.0006810469785705209f, 0.0005535883828997612f, 0.0004315162368584424f, 0.0011108370963484049f, 0.000868228729814291f, 0.00032156798988580704f, 0.0009083804325200617f, 0.00053610053146258f, 0.000859577558003366f, 0.0007428404060192406f, 0.0006926358910277486f, 0.000818673288449645f, 0.0006036750273779035f, 0.0007703216397203505f, 0.0005670831305906177f, 0.00048040266847237945f, 0.0003246893757022917f, 0.0007596576469950378f, 0.0009898386197164655f, 0.0012942015891894698f, 0.0005126529722474515f, 0.0007058632909320295f, 0.0005501126870512962f, 0.000982300960458815f, 0.0007695378735661507f, 0.001069957739673555f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00024826472508721054f, 0.00041332829277962446f, 0.0001602846459718421f, 0.0003179590858053416f, 0.00016748957568779588f, 0.00030276726465672255f, 0.0002252187259728089f, 0.00031167559791356325f, 0.00029911461751908064f, 0.000354888936271891f, 0.0001365860371151939f, 0.0005022313562221825f, 0.0002691252448130399f, 0.00024802584084682167f, 0.0003011571243405342f, 0.0002924396831076592f, 0.0003548516833689064f, 0.00015711098967585713f, 0.00030034975497983396f, 0.00021155906142666936f, 0.00022344369790516794f, 0.0001359533634968102f, 0.00021903954620938748f, 0.00032414408633485436f, 0.00021236884640529752f, 0.00039131121593527496f, 0.0002472586347721517f, 0.00041349881212227046f, 0.00026022319798357785f, 0.0003878801944665611f, 0.00023226650955621153f, 0.0005023836274631321f, 0.00032405383535660803f, 0.0002968251355923712f, 0.00032074496266432106f, 0.00027717003831639886f, 0.0004522707313299179f, 0.000320790073601529f, 0.00016081638750620186f, 0.00032953324262052774f, 0.00019937865727115422f, 0.00034597463672980666f, 0.0003547533415257931f, 0.00026020556106232107f, 0.0005205044872127473f, 0.0003868098428938538f, 0.0002587572089396417f, 0.0002280390472151339f, 0.0002863974077627063f, 0.00020889175357297063f, 0.00020627235062420368f, 0.00027552031679078937f, 0.0003791176131926477f, 0.00025192718021571636f, 0.0002553594531491399f, 0.0003687593271024525f, 0.00025968061527237296f, 0.0003140026528853923f, 0.0003715766652021557f, 0.00021193985594436526f, 0.00018807149899657816f, 0.0003290580934844911f, 0.00024988941731862724f, 0.0002567363844718784f, 0.00027818215312436223f, 0.00028888636734336615f, 0.0002511313068680465f, 8.652557880850509e-05f, 0.00018890335923060775f, 0.0002781205403152853f, 0.00027904973831027746f, 0.0002582401502877474f, 0.0001988953008549288f, 0.00021071010269224644f, 0.00023303271154873073f, 0.00037062415503896773f, 0.00010904104419751093f, 0.00026495096972212195f, 0.00027412414783611894f, 0.0002685651124920696f, 0.0001122777393902652f, 0.00024121660680975765f, 0.0003029977378901094f, 0.00010447571548866108f, 0.00017786408716347069f, 0.0004608345334418118f, 0.00022701817215420306f, 0.0003616996109485626f, 0.0002743394870776683f, 0.00028560441569425166f, 0.00033421331318095326f, 0.0003279809025116265f, 0.00035904766991734505f, 0.00046143654617480934f, 0.000211897655390203f, 0.0003270862507633865f, 0.00042074601515196264f, 0.0006406442844308913f, 0.0002631274110171944f, 0.00022769463248550892f, 0.00022834562696516514f, 0.00027614753344096243f, 0.00014999038830865175f, 0.0003873723326250911f, 0.0002007164730457589f, 0.0003542420163284987f, 0.00039239870966412127f, 0.00028216722421348095f, 0.00016515344032086432f, 0.00034033897100016475f, 0.0002376355550950393f, 0.0003109781537204981f, 0.0002788121928460896f, 0.0005272041307762265f, 0.00026377441827207804f, 0.0005168735515326262f, 0.0003183082153555006f, 0.0002744564844761044f, 0.00027276005130261183f, 0.00022171276214066893f, 0.00017282272165175527f, 0.00044489148422144353f, 0.0003477265709079802f, 0.0001287883351324126f, 0.0003638073685579002f, 0.00021470885258167982f, 0.00034426175989210606f, 0.00029750840622000396f, 0.00027740144287236035f, 0.00032787956297397614f, 0.00024177251907531172f, 0.00030851465999148786f, 0.00022711741621606052f, 0.00019240179972257465f, 0.00013003844651393592f, 0.0003042437310796231f, 0.0003964314528275281f, 0.0005183291505090892f, 0.00020531807967927307f, 0.00028269903850741684f, 0.00022032074048183858f, 0.00039341262890957296f, 0.000308200775180012f, 0.0004285192408133298f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #128 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028250396717339754f, 0.0056869168765842915f, 0.007005753461271524f, 0.003642099443823099f, 0.006969965994358063f, 0.004136965144425631f, 0.009636256843805313f, 0.00254407268948853f, 0.006446775048971176f, 0.004692824091762304f, 0.011134333908557892f, 0.0031211725436151028f, 0.0032492862083017826f, 0.0100895119830966f, 0.009282251819968224f, 0.006025950890034437f, 0.005136617459356785f, 0.003195524448528886f, 0.003517095698043704f, 0.0033576616551727057f, 0.008399487473070621f, 0.007958214730024338f, 0.00947873666882515f, 0.004062847699970007f, 0.009202029556035995f, 0.0038624072913080454f, 0.004234390798956156f, 0.009883632883429527f, 0.007659715600311756f, 0.00377236888743937f, 0.0016415262361988425f, 0.004288159776479006f, 0.007579247932881117f, 0.0036403783597052097f, 0.001261034980416298f, 0.0033835743088275194f, 0.003351100254803896f, 0.0042546517215669155f, 0.005709102842956781f, 0.0052954633720219135f, 0.006174426060169935f, 0.004270972218364477f, 0.0073708645068109035f, 0.009473386220633984f, 0.005803169682621956f, 0.0023308293893933296f, 0.0026403809897601604f, 0.011266431771218777f, 0.005033955443650484f, 0.005933952517807484f, 0.002484662691131234f, 0.007744487840682268f, 0.0036811537574976683f, 0.00790394376963377f, 0.001689111115410924f, 0.006282126996666193f, 0.010470537468791008f, 0.006513714324682951f, 0.001560228643938899f, 0.007992013357579708f, 0.010982119478285313f, 0.0029766587540507317f, 0.006447929423302412f, 0.006371091119945049f, 0.0045362189412117004f, 0.0026523061096668243f, 0.003736944170668721f, 0.010923785157501698f, 0.006515961606055498f, 0.008036785759031773f, 0.006486421450972557f, 0.009821581654250622f, 0.0033364975824952126f, 0.005040232557803392f, 0.0052485172636806965f, 0.0027225292287766933f, 0.010754159651696682f, 0.0049294899217784405f, 0.006716074887663126f, 0.0045750257559120655f, 0.013779875822365284f, 0.007218263112008572f, 0.002596312202513218f, 0.014102133922278881f, 0.006646555848419666f, 0.004388843197375536f, 0.0037949213292449713f, 0.0032058274373412132f, 0.007718986365944147f, 0.007302121724933386f, 0.0014495298964902759f, 0.002923820400610566f, 0.0017910106107592583f, 0.006111636757850647f, 0.00805378332734108f, 0.006010026670992374f, 0.0024223087821155787f, 0.006930735893547535f, 0.0027835899963974953f, 0.008713731542229652f, 0.011031055822968483f, 0.004861041903495789f, 0.008814479224383831f, 0.0069365352392196655f, 0.0038279308937489986f, 0.006183237303048372f, 0.003048618556931615f, 0.006531295832246542f, 0.008608591742813587f, 0.0019193676998838782f, 0.009868187829852104f, 0.0035233055241405964f, 0.005332644097507f, 0.006280261091887951f, 0.008104458451271057f, 0.002106358762830496f, 0.004666607361286879f, 0.004720820114016533f, 0.009081980213522911f, 0.0025358516722917557f, 0.021702509373426437f, 0.0021010118070989847f, 0.00202858611010015f, 0.016779301688075066f, 0.005939546041190624f, 0.0039685433730483055f, 0.006664854474365711f, 0.005593590904027224f, 0.003258144948631525f, 0.004997808486223221f, 0.0036059028934687376f, 0.002999568823724985f, 0.007006960455328226f, 0.006356986705213785f, 0.011850902810692787f, 0.009300037287175655f, 0.004337679594755173f, 0.004903643857687712f, 0.003810095600783825f, 0.007353961002081633f, 0.011837554164230824f, 0.003431915305554867f, 0.005279048811644316f, 0.0018333600601181388f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #129 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(6.647152622463182e-05f, 0.00013380980817601085f, 0.00016484125808347017f, 8.569646161049604e-05f, 0.0001639991969568655f, 9.734035847941414e-05f, 0.00022673545754514635f, 5.986053656670265e-05f, 0.0001516888296464458f, 0.00011041939433198422f, 0.0002619843289721757f, 7.343935430981219e-05f, 7.645379810128361e-05f, 0.00023740027972962707f, 0.00021840592671651393f, 0.00014178708079271019f, 0.00012086158676538616f, 7.518881466239691e-05f, 8.275519212475047e-05f, 7.900380296632648e-05f, 0.00019763500313274562f, 0.00018725210975389928f, 0.00022302909928839654f, 9.559642057865858e-05f, 0.00021651833958458155f, 9.088017395697534e-05f, 9.963272896129638e-05f, 0.0002325560781173408f, 0.00018022859876509756f, 8.876162610249594e-05f, 3.8624148146482185e-05f, 0.00010089787974720821f, 0.00017833524907473475f, 8.56559636304155e-05f, 2.967141153931152e-05f, 7.961351366247982e-05f, 7.884942169766873e-05f, 0.00010010945698013529f, 0.00013433182903099805f, 0.0001245991443283856f, 0.00014528061728924513f, 0.00010049346747109666f, 0.0001734321122057736f, 0.00022290321066975594f, 0.00013654517533723265f, 5.484304710989818e-05f, 6.212661537574604e-05f, 0.0002650925307534635f, 0.00011844601249322295f, 0.00013962241064291447f, 5.846265412401408e-05f, 0.00018222324433736503f, 8.661538595333695e-05f, 0.00018597515008877963f, 3.9743790694046766e-05f, 0.00014781476056668907f, 0.00024636558373458683f, 0.00015326387074310333f, 3.671126250992529e-05f, 0.00018804737192112952f, 0.00025840281159617007f, 7.003903010627255e-05f, 0.00015171598352026194f, 0.0001499080244684592f, 0.00010673456563381478f, 6.240720540517941e-05f, 8.79280996741727e-05f, 0.00025703024584800005f, 0.0001533167524030432f, 0.00018910084327217191f, 0.00015262168017216027f, 0.00023109604080673307f, 7.850582915125415e-05f, 0.00011859370715683326f, 0.0001234945229953155f, 6.405950989574194e-05f, 0.0002530390629544854f, 0.00011598799756029621f, 0.00015802530106157064f, 0.00010764766921056435f, 0.0003242323873564601f, 0.00016984148533083498f, 6.108969682827592e-05f, 0.00033181492472067475f, 0.00015638954937458038f, 0.00010326690244255587f, 8.929226896725595e-05f, 7.543123501818627e-05f, 0.00018162321066483855f, 0.00017181463772431016f, 3.410658609936945e-05f, 6.87957726768218e-05f, 4.214142609271221e-05f, 0.00014380321954376996f, 0.00018950078811030835f, 0.0001414123980794102f, 5.699550092685968e-05f, 0.00016307613987009972f, 6.549623503815383e-05f, 0.0002050289767794311f, 0.0002595542464405298f, 0.00011437745706643909f, 0.00020739951287396252f, 0.00016321259317919612f, 9.00689628906548e-05f, 0.00014548793842550367f, 7.173220365075395e-05f, 0.00015367755258921534f, 0.00020255510753486305f, 4.5161592424847186e-05f, 0.00023219265858642757f, 8.29013079055585e-05f, 0.00012547397636808455f, 0.0001477708574384451f, 0.00019069314294029027f, 4.956138218403794e-05f, 0.00010980253136949614f, 0.00011107812315458432f, 0.00021369365276768804f, 5.966709795757197e-05f, 0.0005106473108753562f, 4.943557360093109e-05f, 4.773143882630393e-05f, 0.0003948071098420769f, 0.00013975403271615505f, 9.33774936129339e-05f, 0.0001568201114423573f, 0.00013161390961613506f, 7.666223245905712e-05f, 0.0001175954967038706f, 8.48447743919678e-05f, 7.057809125399217e-05f, 0.00016486966342199594f, 0.00014957615348976105f, 0.00027884478913620114f, 0.0002188244106946513f, 0.00010206305159954354f, 0.00011537985847098753f, 8.964930748334154e-05f, 0.00017303437925875187f, 0.0002785307005979121f, 8.075094956438988e-05f, 0.0001242129219463095f, 4.313788303988986e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #130 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.013172462582588196f, 0.01798301190137863f, 0.0126338517293334f, 0.010384848341345787f, 0.016067683696746826f, 0.01338777132332325f, 0.016077719628810883f, 0.010766744613647461f, 0.011583986692130566f, 0.014402726665139198f, 0.010874374769628048f, 0.013181935995817184f, 0.01030738279223442f, 0.014574402943253517f, 0.01177548710256815f, 0.0151557307690382f, 0.012700729072093964f, 0.013624305836856365f, 0.012015696614980698f, 0.01068850327283144f, 0.017437981441617012f, 0.019313694909214973f, 0.01220028754323721f, 0.011973647400736809f, 0.015468442812561989f, 0.025051413103938103f, 0.011259546503424644f, 0.012591333128511906f, 0.010266411118209362f, 0.015448089689016342f, 0.016958050429821014f, 0.013748406432569027f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #131 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00030994031112641096f, 0.0004231297061778605f, 0.0002972671063616872f, 0.00024434938677586615f, 0.0003780631523113698f, 0.00031500638579018414f, 0.0003782993007916957f, 0.0002533351653255522f, 0.0002725643862504512f, 0.00033888767939060926f, 0.0002558676351327449f, 0.0003101632173638791f, 0.0002425266575301066f, 0.0003429271455388516f, 0.00027707029948942363f, 0.0003566054510883987f, 0.00029884069226682186f, 0.0003205719112884253f, 0.0002827222924679518f, 0.00025149420253001153f, 0.00041030545253306627f, 0.0004544398980215192f, 0.00028706560260616243f, 0.00028173287864774466f, 0.0003639633650891483f, 0.0005894450005143881f, 0.00026493050972931087f, 0.00029626666218973696f, 0.00024156262225005776f, 0.00036348446155898273f, 0.0003990129625890404f, 0.0003234919277019799f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #132 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003476681013125926f, 0.002428143285214901f, 0.0008924121502786875f, 0.0004098130448255688f, 0.0007625100552104414f, 0.0012984469067305326f, 0.0005850413581356406f, 0.0007616131915710866f, 0.0004884653608314693f, 0.0010263764997944236f, 0.0020262091420590878f, 0.00046254979679360986f, 0.00047627813182771206f, 0.00039378157816827297f, 0.0007426770753227174f, 0.000539718137588352f, 0.0008651979733258486f, 0.0010655593359842896f, 0.0007460145279765129f, 0.0009710362064652145f, 0.0012879465939477086f, 0.0007399859605357051f, 0.0008595296530984342f, 0.00045580233563669026f, 0.0022886188235133886f, 0.0004524734686128795f, 0.0008467395091429353f, 0.0006803153082728386f, 0.0007602666737511754f, 0.0013184759300202131f, 0.00044799825991503894f, 0.0005260463804006577f, 0.0011247220681980252f, 0.0022806960623711348f, 0.0007672415813431144f, 0.0008346501272171736f, 0.001463065855205059f, 0.0005122792208567262f, 0.0005415319465100765f, 0.001256592571735382f, 0.0008638033759780228f, 0.0008372169686481357f, 0.0010867795208469033f, 0.0007124681142158806f, 0.0006366778397932649f, 0.0013085557147860527f, 0.0007989602163434029f, 0.0009603499202057719f, 0.0008494175272062421f, 0.0007217819802463055f, 0.001000574673525989f, 0.0008158692508004606f, 0.0005072226631455123f, 0.0008818441419862211f, 0.0007477847975678742f, 0.0007853444549255073f, 0.0006516544963233173f, 0.000914132222533226f, 0.0005790278082713485f, 0.0012152752606198192f, 0.0005854747141711414f, 0.0008147241314873099f, 0.0008858094806782901f, 0.0009268508874811232f, 0.000906626635696739f, 0.0011970442719757557f, 0.0008331948192790151f, 0.0006610556156374514f, 0.0011083325371146202f, 0.000714629830326885f, 0.0019548069685697556f, 0.0009618703043088317f, 0.0012409373885020614f, 0.0005666104261763394f, 0.00041134783532470465f, 0.0009915458504110575f, 0.0011273198761045933f, 0.0006040874868631363f, 0.001166986534371972f, 0.001097287517040968f, 0.001366394106298685f, 0.0004539367218967527f, 0.001396069535985589f, 0.00045351163134910166f, 0.000321503757731989f, 0.0010158427758142352f, 0.0008217472932301462f, 0.0002617169520817697f, 0.00027879467234015465f, 0.0008545519085600972f, 0.000303034670650959f, 0.0006143593927845359f, 0.0005017787916585803f, 0.0004966426058672369f, 0.0008343037916347384f, 0.0006911684758961201f, 0.0012179812183603644f, 0.0013908904511481524f, 0.0007229614420793951f, 0.000681859499309212f, 0.0005800718208774924f, 0.0003744751156773418f, 0.001425519585609436f, 0.00047514322795905173f, 0.0011578213889151812f, 0.0007372722611762583f, 0.0005305577651597559f, 0.00047632300993427634f, 0.0004591032338794321f, 0.00029660266591235995f, 0.000981622375547886f, 0.0006580488989129663f, 0.0007083832751959562f, 0.0007683290168642998f, 0.0006476989365182817f, 0.0003711016906891018f, 0.0007974138716235757f, 0.00029333322891034186f, 0.0006838300032541156f, 0.000687217281665653f, 0.0004415939038153738f, 0.000929471745621413f, 0.0005760325584560633f, 0.0003379984700586647f, 0.0009612484718672931f, 0.0008922331617213786f, 0.0007289411150850356f, 0.0008062249980866909f, 0.00044533167965710163f, 0.00017977609240915626f, 0.001149196526966989f, 0.0010771931847557425f, 0.00040680402889847755f, 0.0004741745360661298f, 0.0003790027694776654f, 0.0006591113051399589f, 0.0010669726179912686f, 0.0004474091692827642f, 0.0005121194990351796f, 0.0008159170392900705f, 0.0012479957658797503f, 0.0006486196652986109f, 0.00038308679359033704f, 0.0015079075237736106f, 0.0008081501582637429f, 0.0010093635646626353f, 0.00039505353197455406f, 0.0011228997027501464f, 0.0006172365392558277f, 0.0010182288242504f, 0.000550038821529597f, 0.0028070290572941303f, 0.0007768949144519866f, 0.000612518924754113f, 0.0009953138651326299f, 0.0003376472741365433f, 0.001286124810576439f, 0.0005419927183538675f, 0.0010654923971742392f, 0.001405619434081018f, 0.000984791899099946f, 0.0007061585201881826f, 0.0008029193268157542f, 0.0010230669286102057f, 0.0005232791882008314f, 0.0009193791192956269f, 0.0015574570279568434f, 0.0007265127496793866f, 0.0009820099221542478f, 0.0009042599122039974f, 0.0006741684046573937f, 0.0010596689535304904f, 0.0006241304217837751f, 0.0009323416743427515f, 0.0010385432979092002f, 0.000862808374222368f, 0.0009047736530192196f, 0.0008264035568572581f, 0.0011067109880968928f, 0.000822720117866993f, 0.001953744562342763f, 0.002001128625124693f, 0.000756175082642585f, 0.0007662040879949927f, 0.000478335190564394f, 0.0006711118039675057f, 0.0009336014045402408f, 0.0003082807525061071f, 0.0003951885737478733f, 0.0010276036337018013f, 0.0011928803287446499f, 0.00026644658646546304f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #133 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010179276432609186f, 0.0007109292782843113f, 0.0002612868556752801f, 0.00011998801346635446f, 0.00022325318423099816f, 0.0003801686398219317f, 0.00017129261686932296f, 0.00022299059492070228f, 0.00014301639748737216f, 0.0003005098842550069f, 0.0005932481144554913f, 0.00013542865053750575f, 0.00013944813690613955f, 0.00011529420589795336f, 0.00021744634432252496f, 0.0001580225653015077f, 0.0002533188962843269f, 0.00031198211945593357f, 0.0002184235054301098f, 0.00028430696693249047f, 0.00037709425669163465f, 0.0002166584163205698f, 0.00025165927945636213f, 0.00013345308252610266f, 0.0006700782687403262f, 0.00013247843889985234f, 0.0002479144895914942f, 0.000199187605176121f, 0.00022259633988142014f, 0.00038603285793215036f, 0.00013116815534885973f, 0.00015401963901240379f, 0.0003293042245786637f, 0.0006677585770376027f, 0.00022463851200882345f, 0.00024437488173134625f, 0.00042836694046854973f, 0.00014998880214989185f, 0.00015855362289585173f, 0.0003679142100736499f, 0.00025291056954301894f, 0.00024512640084140003f, 0.0003181951178703457f, 0.0002086015447275713f, 0.0001864111254690215f, 0.00038312835386022925f, 0.00023392532602883875f, 0.0002811781596392393f, 0.00024869857588782907f, 0.00021132851543370634f, 0.00029295546119101346f, 0.0002388760622125119f, 0.00014850830484647304f, 0.00025819268194027245f, 0.00021894181554671377f, 0.0002299387997481972f, 0.00019079609774053097f, 0.00026764621725305915f, 0.00016953192243818194f, 0.0003558170283213258f, 0.00017141949501819909f, 0.00023854078608565032f, 0.000259353662841022f, 0.0002713700814638287f, 0.00026544867432676256f, 0.00035047924029640853f, 0.0002439487725496292f, 0.00019354862160980701f, 0.00032450558501295745f, 0.0002092344657285139f, 0.0005723424255847931f, 0.00028162330272607505f, 0.000363330589607358f, 0.00016589627193752676f, 0.00012043737660860643f, 0.0002903119311667979f, 0.00033006482408382f, 0.00017686908540781587f, 0.00034167870762757957f, 0.00032127174199558794f, 0.0004000627086497843f, 0.00013290686183609068f, 0.00040875127888284624f, 0.00013278239930514246f, 9.413218504050747e-05f, 0.00029742575134150684f, 0.0002405970881227404f, 7.662737334612757e-05f, 8.162751328200102e-05f, 0.0002502018469385803f, 8.87246715137735e-05f, 0.0001798765588318929f, 0.00014691440446767956f, 0.0001454105949960649f, 0.00024427345488220453f, 0.000202365277800709f, 0.000356609292794019f, 0.0004072349111083895f, 0.00021167384693399072f, 0.00019963973318226635f, 0.000169837599969469f, 0.00010964152170345187f, 0.00041737387073226273f, 0.00013911585847381502f, 0.0003389952762518078f, 0.00021586388174910098f, 0.00015534051635768265f, 0.00013946127728559077f, 0.00013441954797599465f, 8.684146450832486e-05f, 0.0002874064666684717f, 0.00019266828894615173f, 0.0002074055519187823f, 0.0002249568933621049f, 0.00018963795446325094f, 0.0001086538250092417f, 0.00023347257229033858f, 8.588421042077243e-05f, 0.00020021667296532542f, 0.00020120841509196907f, 0.00012929303920827806f, 0.0002721374330576509f, 0.0001686549512669444f, 9.896162373479456e-05f, 0.00028144122916273773f, 0.0002612344396766275f, 0.000213424616958946f, 0.00023605235037393868f, 0.0001303874159930274f, 5.263613638817333e-05f, 0.0003364700241945684f, 0.00031538837356492877f, 0.00011910701141459867f, 0.00013883222709409893f, 0.00011096715752501041f, 0.0001929793506860733f, 0.0003123959177173674f, 0.0001309956714976579f, 0.00014994203229434788f, 0.00023889006115496159f, 0.00036539716529659927f, 0.00018990752869285643f, 0.00011216291022719815f, 0.0004414959985297173f, 0.00023661601881030947f, 0.0002955287345685065f, 0.00011566661851247773f, 0.0003287706640549004f, 0.00018071895465254784f, 0.0002981243596877903f, 0.000161044328706339f, 0.0008218621369451284f, 0.00022746488684788346f, 0.00017933770141098648f, 0.0002914151409640908f, 9.885879990179092e-05f, 0.0003765608707908541f, 0.00015868853370193392f, 0.0003119625325780362f, 0.000411547371186316f, 0.0002883344714064151f, 0.00020675417908933014f, 0.0002350845024921f, 0.0002995409013237804f, 0.00015320944658014923f, 0.0002691824338398874f, 0.00045600347220897675f, 0.00021271362493280321f, 0.0002875199425034225f, 0.00026475571212358773f, 0.0001973878825083375f, 0.0003102575137745589f, 0.0001827373926062137f, 0.0002729776897467673f, 0.00030407216399908066f, 0.00025261924020014703f, 0.0002649061498232186f, 0.00024196038430090994f, 0.00032403081422671676f, 0.0002408819127595052f, 0.0005720313638448715f, 0.000585904810577631f, 0.0002213983825640753f, 0.0002243347407784313f, 0.0001400504115736112f, 0.00019649293972179294f, 0.00027334652259014547f, 9.026065526995808e-05f, 0.0001157061560661532f, 0.0003008691710419953f, 0.00034926008083857596f, 7.801214815117419e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #134 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04646573215723038f, 0.004582144785672426f, 0.00243083736859262f, 0.007255790755152702f, 0.015124666504561901f, 0.0041822106577456f, 0.008052940480411053f, 0.0035526424180716276f, 0.010930723510682583f, 0.008788016624748707f, 0.003207603469491005f, 0.011194777674973011f, 0.01188067439943552f, 0.015048215165734291f, 0.00389867858029902f, 0.007347996346652508f, 0.017839597538113594f, 0.0023745473008602858f, 0.0073693362064659595f, 0.009543667547404766f, 0.013530099764466286f, 0.006323196459561586f, 0.005096402484923601f, 0.009877584874629974f, 0.003769922535866499f, 0.004969820845872164f, 0.008837603963911533f, 0.009995792992413044f, 0.0058767483569681644f, 0.002985664876177907f, 0.01296750083565712f, 0.007283296901732683f, 0.0024747548159211874f, 0.003432242898270488f, 0.009254539385437965f, 0.007715526502579451f, 0.002214427338913083f, 0.006321814842522144f, 0.009446532465517521f, 0.009524766355752945f, 0.014947500079870224f, 0.002287528943270445f, 0.0020423484966158867f, 0.004591684322804213f, 0.0112674031406641f, 0.0023435750044882298f, 0.006507633253931999f, 0.005899552721530199f, 0.015287946909666061f, 0.0030300794169306755f, 0.007693169638514519f, 0.011417465284466743f, 0.005481373053044081f, 0.007177296094596386f, 0.00925252865999937f, 0.006209937855601311f, 0.003610448446124792f, 0.011731370352208614f, 0.006954696495085955f, 0.01818998157978058f, 0.012518418952822685f, 0.003497883677482605f, 0.009563961997628212f, 0.006294654682278633f, 0.013099228031933308f, 0.003498421050608158f, 0.0015960660530254245f, 0.009299853816628456f, 0.011162679642438889f, 0.0054032825864851475f, 0.011142950505018234f, 0.005845959298312664f, 0.012300187721848488f, 0.008032132871448994f, 0.010379628278315067f, 0.006505659315735102f, 0.005278109572827816f, 0.002671911148354411f, 0.010568991303443909f, 0.011407336220145226f, 0.0018172895070165396f, 0.01656953990459442f, 0.0042990585789084435f, 0.013294105418026447f, 0.01249092910438776f, 0.005532499402761459f, 0.001690681790933013f, 0.023547649383544922f, 0.020099595189094543f, 0.003379178000614047f, 0.016328861936926842f, 0.005990861915051937f, 0.03887331113219261f, 0.007716393563896418f, 0.00685470923781395f, 0.01488849800080061f, 0.0015551230171695352f, 0.001624314347282052f, 0.008511215448379517f, 0.0038064264226704836f, 0.004531377460807562f, 0.008130110800266266f, 0.006558419670909643f, 0.0136398421600461f, 0.0069338977336883545f, 0.006345379166305065f, 0.014848222956061363f, 0.007857885211706161f, 0.01390016172081232f, 0.006116253789514303f, 0.01162746362388134f, 0.008902482688426971f, 0.004845192190259695f, 0.005554663948714733f, 0.014587899670004845f, 0.015022026374936104f, 0.014693568460643291f, 0.014268867671489716f, 0.010788045823574066f, 0.009600449353456497f, 0.010748816654086113f, 0.007161637768149376f, 0.012602412141859531f, 0.009464249014854431f, 0.006116647273302078f, 0.004688077140599489f, 0.011399517767131329f, 0.009541931562125683f, 0.008225610479712486f, 0.024225151166319847f, 0.002741855103522539f, 0.008058274164795876f, 0.012803792022168636f, 0.018518250435590744f, 0.015187172219157219f, 0.006097750272601843f, 0.003707049647346139f, 0.01720619574189186f, 0.013854235410690308f, 0.013250974006950855f, 0.005840314086526632f, 0.011793614365160465f, 0.01904376409947872f, 0.004325553774833679f, 0.00802521500736475f, 0.0058282543905079365f, 0.01299187820404768f, 0.011620393954217434f, 0.00481927115470171f, 0.011120614595711231f, 0.00666822912171483f, 0.0029447644483298063f, 0.007811694405972958f, 0.00976361334323883f, 0.00999950710684061f, 0.011647379957139492f, 0.006021255627274513f, 0.00731384614482522f, 0.007733691018074751f, 0.004050544463098049f, 0.0028574513271450996f, 0.005168789532035589f, 0.012485383078455925f, 0.006335848942399025f, 0.013565345667302608f, 0.012424363754689693f, 0.0015576767036691308f, 0.02160494588315487f, 0.003541407408192754f, 0.011252813041210175f, 0.008281040005385876f, 0.0016135789919644594f, 0.011415443383157253f, 0.009643233381211758f, 0.004831247963011265f, 0.001937869586981833f, 0.004647769033908844f, 0.01651715114712715f, 0.011960950680077076f, 0.012787592597305775f, 0.004187919199466705f, 0.005985588766634464f, 0.012876980938017368f, 0.011378560215234756f, 0.007049681153148413f, 0.009840987622737885f, 0.0050993082113564014f, 0.009442975744605064f, 0.009450768120586872f, 0.004039185121655464f, 0.0019550607539713383f, 0.014509055763483047f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #135 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001093311351723969f, 0.00010781517630675808f, 5.719617547583766e-05f, 0.00017072449554689229f, 0.00035587450838647783f, 9.840496204560623e-05f, 0.00018948095384985209f, 8.359158528037369e-05f, 0.00025719348923303187f, 0.00020677686552517116f, 7.547302084276453e-05f, 0.0002634065458551049f, 0.00027954528923146427f, 0.00035407565883360803f, 9.17336146812886e-05f, 0.0001728940405882895f, 0.00041975523345172405f, 5.58717038074974e-05f, 0.0001733961544232443f, 0.00022455689031630754f, 0.0003183553053531796f, 0.000148781095049344f, 0.00011991535575361922f, 0.00023241376038640738f, 8.870405872585252e-05f, 0.00011693696433212608f, 0.0002079436235362664f, 0.00023519514070358127f, 0.00013827643124386668f, 7.025094237178564e-05f, 0.0003051176609005779f, 0.0001713716919766739f, 5.822952516609803e-05f, 8.07586548035033e-05f, 0.00021775386994704604f, 0.00018154180725105107f, 5.210417293710634e-05f, 0.00014874858607072383f, 0.00022227135195862502f, 0.0002241121546830982f, 0.0003517058794386685f, 5.382421295507811e-05f, 4.805525895790197e-05f, 0.00010803963232319802f, 0.00026511537726037204f, 5.5142943892860785e-05f, 0.0001531207817606628f, 0.00013881300401408225f, 0.0003597164177335799f, 7.12959881639108e-05f, 0.0001810157555155456f, 0.000268646253971383f, 0.00012897347914986312f, 0.00016887755191419274f, 0.00021770656167063862f, 0.00014611618826165795f, 8.49517309688963e-05f, 0.0002760322531685233f, 0.00016363992472179234f, 0.0004279995628166944f, 0.0002945510495919734f, 8.230314415413886e-05f, 0.0002250344114145264f, 0.00014810952416155487f, 0.00030821713153272867f, 8.231578976847231e-05f, 3.755449506570585e-05f, 0.00021882008877582848f, 0.0002626513014547527f, 0.00012713606702163815f, 0.0002621870662551373f, 0.0001375519932480529f, 0.0002894161734730005f, 0.0001889913692139089f, 0.0002442265395075083f, 0.00015307434659916908f, 0.00012419081758707762f, 6.286850111791864e-05f, 0.00024868216132745147f, 0.0002684079227037728f, 4.275975516065955e-05f, 0.0003898715367540717f, 0.0001011543208733201f, 0.000312802498228848f, 0.0002939042169600725f, 0.00013017645687796175f, 3.978074892074801e-05f, 0.0005540623678825796f, 0.000472931656986475f, 7.951007137307897e-05f, 0.00038420851342380047f, 0.00014096146333031356f, 0.0009146661614067852f, 0.00018156220903620124f, 0.00016128727293107659f, 0.00035031759762205184f, 3.659112917375751e-05f, 3.821916106971912e-05f, 0.00020026389393024147f, 8.956297824624926e-05f, 0.00010662064596544951f, 0.00019129672728013247f, 0.00015431575593538582f, 0.0003209374553989619f, 0.00016315054381266236f, 0.00014930304314475507f, 0.00034936994779855013f, 0.00018489142530597746f, 0.0003270626475568861f, 0.00014391184959094971f, 0.0002735873858910054f, 0.0002094701922032982f, 0.00011400452785892412f, 0.0001306979829678312f, 0.00034324469743296504f, 0.0003534594434313476f, 0.0003457310376688838f, 0.00033573806285858154f, 0.0002538363914936781f, 0.00022589293075725436f, 0.0002529133344069123f, 0.00016850912652444094f, 0.0002965273451991379f, 0.00022268822067417204f, 0.00014392111916095018f, 0.00011030770110664889f, 0.00026822395739145577f, 0.00022451604309026152f, 0.00019354377582203597f, 0.0005700035835616291f, 6.451423541875556e-05f, 0.00018960644956678152f, 0.0003012657107319683f, 0.00043572354479692876f, 0.0003573452413547784f, 0.00014347648539114743f, 8.722469647182152e-05f, 0.00040485168574377894f, 0.00032598202233202755f, 0.0003117876185569912f, 0.00013741916336584836f, 0.00027749681612476707f, 0.0004480885691009462f, 0.00010177773947361857f, 0.0001888285914901644f, 0.0001371354010188952f, 0.00030569126829504967f, 0.0002734210283961147f, 0.0001133946207119152f, 0.0002616615383885801f, 0.00015689950669184327f, 6.928857328603044e-05f, 0.0001838045718614012f, 0.00022973208979237825f, 0.00023528252495452762f, 0.0002740560157690197f, 0.00014167660265229642f, 0.0001720904983812943f, 0.0001819691970013082f, 9.530693205306306e-05f, 6.723414844600484e-05f, 0.00012161857739556581f, 0.0002937737153843045f, 0.00014907879813108593f, 0.0003191846190020442f, 0.00029233796522021294f, 3.665121766971424e-05f, 0.00050835165893659f, 8.332723518833518e-05f, 0.0002647720684763044f, 0.00019484800577629358f, 3.796656528720632e-05f, 0.0002685986692085862f, 0.00022689961770083755f, 0.00011367642582627013f, 4.5596931158797815e-05f, 0.00010935927275568247f, 0.00038863884401507676f, 0.0002814341278281063f, 0.00030088453786447644f, 9.853927622316405e-05f, 0.00014083737914916128f, 0.0003029877843800932f, 0.0002677308220881969f, 0.0001658748515183106f, 0.00023155265080276877f, 0.0001199837279273197f, 0.00022218766389414668f, 0.0002223710180260241f, 9.503964975010604e-05f, 4.600143074640073e-05f, 0.0003413895610719919f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #136 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003690730081871152f, 0.004968177527189255f, 0.007212355732917786f, 0.005342187825590372f, 0.005209756083786488f, 0.005682012997567654f, 0.0059650312177836895f, 0.011835889890789986f, 0.01304980181157589f, 0.016638629138469696f, 0.004397036973387003f, 0.011936996132135391f, 0.003994263242930174f, 0.015262715518474579f, 0.005894103553146124f, 0.0035492051392793655f, 0.014458687976002693f, 0.004042016342282295f, 0.006899259053170681f, 0.005592874251306057f, 0.0056868745014071465f, 0.01874527707695961f, 0.011525574140250683f, 0.01286033634096384f, 0.012916923500597477f, 0.010777123272418976f, 0.014620362780988216f, 0.005454338155686855f, 0.0038014668971300125f, 0.004780635237693787f, 0.009742112830281258f, 0.004818909801542759f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #137 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.684070780873299e-05f, 0.00011689829989336431f, 0.00016970248543657362f, 0.0001256985415238887f, 0.00012258249626029283f, 0.00013369442604016513f, 0.00014035367348697037f, 0.0002784915268421173f, 0.00030705417157150805f, 0.00039149716030806303f, 0.00010345969349145889f, 0.0002808705030474812f, 9.3982664111536e-05f, 0.00035912272869609296f, 0.0001386847870890051f, 8.351071301149204e-05f, 0.00034020442399196327f, 9.51062684180215e-05f, 0.00016233550559263676f, 0.00013159704394638538f, 0.00013380881864577532f, 0.00044106534915044904f, 0.0002711899869609624f, 0.0003025961632374674f, 0.00030392760527320206f, 0.0002535793755669147f, 0.0003440085565671325f, 0.00012833737127948552f, 8.944627916207537e-05f, 0.00011248554073972628f, 0.00022922619245946407f, 0.00011338611511746421f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #138 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037256101495586336f, 0.00040797257679514587f, 0.00035199904232285917f, 0.0006092910771258175f, 0.00032756623113527894f, 0.0004560314991977066f, 0.0007617231458425522f, 0.0008681587059982121f, 0.0006286639836616814f, 0.00080724130384624f, 0.0005614032270386815f, 0.0007129980367608368f, 0.0007619911339133978f, 0.00048160424921661615f, 0.0007564249099232256f, 0.0003504278138279915f, 0.0008285306394100189f, 0.0006519039161503315f, 0.0009791196789592505f, 0.0010154268238693476f, 0.00033934894599951804f, 0.0003276606439612806f, 0.0007782716420479119f, 0.0007363749900832772f, 0.00021042331354692578f, 0.00043996571912430227f, 0.0007467764080502093f, 0.0006528684170916677f, 0.0007282909355126321f, 0.0006570947589352727f, 0.0007466854876838624f, 0.0011192455422133207f, 0.00034024682827293873f, 0.00032044784165918827f, 0.000485378026496619f, 0.0011458167573437095f, 0.0003413853992242366f, 0.0004859792534261942f, 0.0006409248453564942f, 0.0005744931986555457f, 0.00041365809738636017f, 0.0007284922758117318f, 0.0010539904469624162f, 0.00022723613074049354f, 0.0007369528175331652f, 0.0005152521189302206f, 0.0003250240406487137f, 0.0006867268239147961f, 0.0009916424751281738f, 0.001034857239574194f, 0.0009099564049392939f, 0.0007878689793869853f, 0.0003488830989226699f, 0.0012530433014035225f, 0.0007968381396494806f, 0.0007543288520537317f, 0.0006790942861698568f, 0.0002818755165208131f, 0.00048376823542639613f, 0.0006546374643221498f, 0.0005582150188274682f, 0.0008521283743903041f, 0.0006553201819770038f, 0.0008510153857059777f, 0.0006091897375881672f, 0.0004752160457428545f, 0.0006803415017202497f, 0.0007235264056362212f, 0.0005263481289148331f, 0.001167689566500485f, 0.00032506935531273484f, 0.00022654312488157302f, 0.0008431447204202414f, 0.000498273700941354f, 0.0001398655876982957f, 0.00026471729506738484f, 0.0002580764703452587f, 0.00037995330058038235f, 0.0007639853283762932f, 0.0003600390045903623f, 0.0006008609780110419f, 0.0005726691451855004f, 0.00038329348899424076f, 0.000640918908175081f, 0.0006936232675798237f, 0.0008042820263653994f, 0.0012473184615373611f, 9.022453014040366e-05f, 0.0007836008444428444f, 0.0008650937234051526f, 0.0010539473732933402f, 0.001105671632103622f, 0.0005415230989456177f, 0.0008762187790125608f, 0.0004872744611930102f, 0.0008622274617664516f, 0.0011239682789891958f, 0.0006397922406904399f, 0.0003478681610431522f, 0.0006929186056368053f, 0.0009117693407461047f, 0.00024197054153773934f, 0.0010359532898291945f, 0.0006123133352957666f, 0.000936219934374094f, 0.0003261957026552409f, 0.000844113586936146f, 0.00043364783050492406f, 0.0006772482302039862f, 0.0008223402546718717f, 0.0005351459258235991f, 0.0007539468933828175f, 0.0007290621288120747f, 0.000626667111646384f, 0.0007527089328505099f, 0.0010977315250784159f, 0.00027710801805369556f, 0.0010572840692475438f, 0.0006697738426737487f, 0.0012575609143823385f, 0.00039571226807311177f, 0.0006918571307323873f, 0.0007496452890336514f, 0.0008246837533079088f, 0.0007051935535855591f, 0.0007064981036819518f, 0.0003563675854820758f, 0.0013464714866131544f, 0.00024273885355796665f, 0.0012486280174925923f, 0.0008212582324631512f, 0.001095412764698267f, 0.0006937190191820264f, 0.0003965416981372982f, 0.0002767765836324543f, 0.00026253258693031967f, 0.0005269590765237808f, 0.0008760849013924599f, 0.0006943511543795466f, 0.0004997854703105986f, 0.00036575758713297546f, 0.0004415589792188257f, 0.0008068059105426073f, 0.0006762991542927921f, 0.00045712466817349195f, 0.0010754532413557172f, 0.000587964546866715f, 0.0008211047970689833f, 0.0009671402513049543f, 0.0006780597614124417f, 0.0012818521354347467f, 0.0004945563268847764f, 0.0010577701032161713f, 0.0009600405464880168f, 0.0012172431452199817f, 0.0009055708651430905f, 0.0009426811011508107f, 0.0009005782776512206f, 0.0006531085236929357f, 0.0003546075604390353f, 0.0006562755443155766f, 0.00016713257355149835f, 0.0008761276258155704f, 0.000612306350376457f, 0.0003396575921215117f, 0.0006693369359709322f, 0.0006206553080119193f, 0.0010607154108583927f, 0.0005932565545663238f, 0.0005631684325635433f, 0.0007273014634847641f, 0.0005059776594862342f, 0.00039878831012174487f, 0.0009497291757725179f, 0.0007453580037690699f, 0.0004350743838585913f, 0.00033762725070118904f, 0.0008000159868970513f, 0.0009232079610228539f, 0.000559718522708863f, 0.0006357920356094837f, 0.0007880476186983287f, 0.0008659468148835003f, 0.0005243672640062869f, 0.0009234372992068529f, 0.0003282118705101311f, 0.0004207515448797494f, 0.0009465645998716354f, 0.0006866701878607273f, 0.000584224471822381f, 0.0004989904700778425f, 0.0007754931575618684f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #139 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00015630497364327312f, 0.00017116160597652197f, 0.0001476783654652536f, 0.00025562316295690835f, 0.00013742777809966356f, 0.0001913243468152359f, 0.00031957481405697763f, 0.0003642289957497269f, 0.000263750902377069f, 0.000338671583449468f, 0.00023553220671601593f, 0.0002991326036863029f, 0.000319687242154032f, 0.00020205318287480623f, 0.00031735197990201414f, 0.00014701916370540857f, 0.00034760337439365685f, 0.00027350103482604027f, 0.00041078179492615163f, 0.0004260141577105969f, 0.0001423711219104007f, 0.00013746738841291517f, 0.0003265176201239228f, 0.0003089402162004262f, 8.828140562400222e-05f, 0.00018458407430443913f, 0.00031330404453910887f, 0.0002739056944847107f, 0.00030554860131815076f, 0.00027567881625145674f, 0.0003132658894173801f, 0.0004695704556070268f, 0.0001427478127880022f, 0.00013444131764117628f, 0.00020363644580356777f, 0.00048071821220219135f, 0.00014322549395728856f, 0.00020388868870213628f, 0.0002688948588911444f, 0.00024102399765979499f, 0.0001735469268169254f, 0.0003056330606341362f, 0.00044219320989213884f, 9.533509000902995e-05f, 0.00030918262200430036f, 0.00021616987942252308f, 0.00013636122457683086f, 0.00028811072115786374f, 0.0004160356184002012f, 0.0004341660242062062f, 0.0003817648976109922f, 0.0003305441059637815f, 0.00014637109416071326f, 0.0005257042357698083f, 0.00033430702751502395f, 0.00031647260766476393f, 0.00028490854310803115f, 0.00011825860565295443f, 0.00020296107686590403f, 0.00027464787126518786f, 0.0002341946237720549f, 0.0003575035952962935f, 0.00027493431116454303f, 0.00035703665344044566f, 0.00025558064226061106f, 0.00019937306933570653f, 0.00028543180087581277f, 0.0003035496920347214f, 0.000220825124415569f, 0.0004898947663605213f, 0.0001363802293781191f, 9.504434274276718e-05f, 0.00035373459104448557f, 0.0002090467169182375f, 5.867948129889555e-05f, 0.00011106001329608262f, 0.0001082739036064595f, 0.0001594063505763188f, 0.0003205238899681717f, 0.00015105147031135857f, 0.0002520863781683147f, 0.0002402587269898504f, 0.00016080770001281053f, 0.00026889238506555557f, 0.00029100404935888946f, 0.0003374300431460142f, 0.0005233024130575359f, 3.78529766749125e-05f, 0.00032875343458727f, 0.000362943101208657f, 0.0004421751364134252f, 0.0004638756508938968f, 0.00022719166008755565f, 0.0003676105407066643f, 0.00020443208632059395f, 0.0003617405891418457f, 0.00047155184438452125f, 0.0002684196806512773f, 0.000145945290569216f, 0.00029070841264910996f, 0.00038252549711614847f, 0.00010151679452974349f, 0.0004346258647274226f, 0.00025689112953841686f, 0.00039278354961425066f, 0.0001368527882732451f, 0.0003541410551406443f, 0.00018193345749750733f, 0.00028413403197191656f, 0.0003450062358751893f, 0.00022451617405749857f, 0.00031631236197426915f, 0.00030587214860133827f, 0.0002629131486173719f, 0.0003157929750159383f, 0.0004605444264598191f, 0.00011625843762885779f, 0.0004435750306583941f, 0.0002809982397593558f, 0.0005275995936244726f, 0.00016601789684500545f, 0.0002902630949392915f, 0.00031450766255147755f, 0.0003459894214756787f, 0.0002958582772407681f, 0.0002964056038763374f, 0.00014951115008443594f, 0.0005649012746289372f, 0.00010183913400396705f, 0.0005238518351688981f, 0.00034455227432772517f, 0.0004595716018229723f, 0.0002910442417487502f, 0.0001663658767938614f, 0.00011611938680289313f, 0.00011014343181159347f, 0.00022108144185040146f, 0.00036755437031388283f, 0.00029130943585187197f, 0.0002096809766953811f, 0.00015345065912697464f, 0.00018525251653045416f, 0.00033848892780952156f, 0.000283735862467438f, 0.00019178297952748835f, 0.0004511977604124695f, 0.00024667580146342516f, 0.00034448792575858533f, 0.0004057559126522392f, 0.0002844745176844299f, 0.0005377907655201852f, 0.00020748712995555252f, 0.000443778932094574f, 0.0004027772811241448f, 0.0005106845637783408f, 0.00037992498255334795f, 0.00039549428038299084f, 0.0003778303798753768f, 0.00027400642284192145f, 0.00014877274225000292f, 0.00027533512911759317f, 7.011912384768948e-05f, 0.0003675722982734442f, 0.00025688819005154073f, 0.0001425006048521027f, 0.0002808149147313088f, 0.00026039095246233046f, 0.000445014622528106f, 0.00024889601627364755f, 0.00023627278278581798f, 0.0003051334642805159f, 0.0002122788573615253f, 0.00016730843344703317f, 0.000398451229557395f, 0.00031270895851776004f, 0.00018253196321893483f, 0.00014164879394229501f, 0.0003356402739882469f, 0.0003873244859278202f, 0.00023482540564145893f, 0.0002667414373718202f, 0.00033061904832720757f, 0.00036330102011561394f, 0.00021999406453687698f, 0.00038742070319131017f, 0.00013769864744972438f, 0.00017652292444836348f, 0.0003971235710196197f, 0.0002880869433283806f, 0.00024510666844435036f, 0.0002093474322464317f, 0.00032535192440263927f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #140 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007618231698870659f, 0.011589384637773037f, 0.023752912878990173f, 0.01623985730111599f, 0.009045831859111786f, 0.008296688087284565f, 0.011647934094071388f, 0.0015234388411045074f, 0.008652498945593834f, 0.007044655736535788f, 0.003302300116047263f, 0.011403825134038925f, 0.004590226802974939f, 0.009951303713023663f, 0.009180577471852303f, 0.01015281118452549f, 0.002312983153387904f, 0.008953515440225601f, 0.010852807201445103f, 0.010645768605172634f, 0.01165072899311781f, 0.007164370268583298f, 0.006363022606819868f, 0.003536378964781761f, 0.010727358050644398f, 0.00873324740678072f, 0.013346961699426174f, 0.007541739847511053f, 0.005805592518299818f, 0.012518552131950855f, 0.00532165914773941f, 0.002620380138978362f, 0.007051118183881044f, 0.021681664511561394f, 0.00960680190473795f, 0.005960355047136545f, 0.01130923256278038f, 0.016628453508019447f, 0.0020621931180357933f, 0.005778087768703699f, 0.004727769177407026f, 0.007992205210030079f, 0.0036589885130524635f, 0.004672287032008171f, 0.005755233578383923f, 0.003843422047793865f, 0.013343129307031631f, 0.011154758743941784f, 0.005922842305153608f, 0.004477521404623985f, 0.004468136932700872f, 0.005019675940275192f, 0.007914621382951736f, 0.009582937695086002f, 0.009748014621436596f, 0.005147845484316349f, 0.007833804935216904f, 0.01294041145592928f, 0.0117493299767375f, 0.002098647179082036f, 0.002387288259342313f, 0.006783133372664452f, 0.008338875137269497f, 0.003251149319112301f, 0.008669130504131317f, 0.003647545585408807f, 0.010122058913111687f, 0.005269004497677088f, 0.016662782058119774f, 0.0028045105282217264f, 0.015702376142144203f, 0.02093132771551609f, 0.003146805800497532f, 0.009232815355062485f, 0.03185849264264107f, 0.008422279730439186f, 0.01212603971362114f, 0.005013073794543743f, 0.0018713405588641763f, 0.01139817200601101f, 0.009014472365379333f, 0.00548570929095149f, 0.008138459175825119f, 0.009625458158552647f, 0.012548932805657387f, 0.010939757339656353f, 0.004126798361539841f, 0.058889683336019516f, 0.011416153982281685f, 0.00686238007619977f, 0.0024650627747178078f, 0.003898145630955696f, 0.008149152621626854f, 0.0032250259537249804f, 0.007055176421999931f, 0.005825371481478214f, 0.007131657097488642f, 0.016273286193609238f, 0.019291743636131287f, 0.020103296265006065f, 0.006265801377594471f, 0.022014982998371124f, 0.01570671983063221f, 0.006351913791149855f, 0.004805660806596279f, 0.0217642430216074f, 0.011296373791992664f, 0.009873347356915474f, 0.0073683918453752995f, 0.0056610070168972015f, 0.004681659862399101f, 0.004727163352072239f, 0.007094788830727339f, 0.004230076912790537f, 0.010123562067747116f, 0.0037772932555526495f, 0.010975254699587822f, 0.0053270310163497925f, 0.0017858314095064998f, 0.007454865146428347f, 0.0055911727249622345f, 0.011155175045132637f, 0.004665003623813391f, 0.005641868803650141f, 0.00401867413893342f, 0.011092829518020153f, 0.008403327316045761f, 0.0023499452508985996f, 0.009629550389945507f, 0.005556261632591486f, 0.006229621823877096f, 0.0025879698805510998f, 0.004930376540869474f, 0.011786391958594322f, 0.01735997200012207f, 0.013594932854175568f, 0.009620810858905315f, 0.008372748270630836f, 0.002937306882813573f, 0.0021981801837682724f, 0.004472451750189066f, 0.005732639692723751f, 0.004070022143423557f, 0.0059585352428257465f, 0.023107705637812614f, 0.007475248537957668f, 0.004744389094412327f, 0.006417599506676197f, 0.004456276539713144f, 0.003483815584331751f, 0.004452405497431755f, 0.010031694546341896f, 0.002383030019700527f, 0.005346399266272783f, 0.007268144283443689f, 0.011350331827998161f, 0.010918798856437206f, 0.004831537138670683f, 0.007530389353632927f, 0.019809922203421593f, 0.006311879958957434f, 0.01091474387794733f, 0.007047602441161871f, 0.01253642700612545f, 0.006571915466338396f, 0.0042061409913003445f, 0.005875595845282078f, 0.013697044923901558f, 0.006307933945208788f, 0.0092961760237813f, 0.006478650029748678f, 0.016468694433569908f, 0.006957396864891052f, 0.008029218763113022f, 0.0030129598453640938f, 0.006422044243663549f, 0.01335715688765049f, 0.008107713423669338f, 0.003283458761870861f, 0.005131795536726713f, 0.0033887692261487246f, 0.005794959608465433f, 0.008752805180847645f, 0.00791368167847395f, 0.006790658924728632f, 0.015101787634193897f, 0.006425284314900637f, 0.004200566094368696f, 0.008687619119882584f, 0.0057027642615139484f, 0.0038884032983332872f, 0.002128919120877981f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #141 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017925251449923962f, 0.0002726913953665644f, 0.0005588920903392136f, 0.0003821142890956253f, 0.00021284310787450522f, 0.00019521619833540171f, 0.00027406905428506434f, 3.5845620004693046e-05f, 0.00020358822075650096f, 0.0001657566026551649f, 7.77011809987016e-05f, 0.0002683252969291061f, 0.00010800534073496237f, 0.00023414833412971348f, 0.00021601359185297042f, 0.00023888968280516565f, 5.442313340608962e-05f, 0.00021067095804028213f, 0.0002553601807449013f, 0.0002504886651877314f, 0.0002741347998380661f, 0.00016857341688591987f, 0.00014971818018238991f, 8.320892084157094e-05f, 0.0002524084411561489f, 0.00020548817701637745f, 0.0003140461631119251f, 0.00017745270451996475f, 0.00013660217518918216f, 0.0002945541637018323f, 0.0001252155052497983f, 6.165600643726066e-05f, 0.00016590867016930133f, 0.0005101567949168384f, 0.00022604240803048015f, 0.00014024364645592868f, 0.0002660995814949274f, 0.0003912577230948955f, 4.852219353779219e-05f, 0.000135955007863231f, 0.00011124162847409025f, 0.00018805189756676555f, 8.60938525875099e-05f, 0.00010993616888299584f, 0.00013541725638788193f, 9.043345926329494e-05f, 0.00031395599944517016f, 0.00026246492052450776f, 0.0001393610000377521f, 0.00010535344335949048f, 0.00010513263259781525f, 0.00011811002332251519f, 0.00018622638890519738f, 0.00022548089327756315f, 0.00022936506138648838f, 0.00012112577678635716f, 0.00018432483193464577f, 0.00030448028701357543f, 0.0002764548407867551f, 4.937993435305543e-05f, 5.617148781311698e-05f, 0.000159603136125952f, 0.0001962088281288743f, 7.649763574590907e-05f, 0.0002039795508608222f, 8.582460577599704e-05f, 0.00023816610337235034f, 0.0001239765842910856f, 0.00039206547080539167f, 6.598848267458379e-05f, 0.00036946768523193896f, 0.0004925018292851746f, 7.404248754028231e-05f, 0.00021724271937273443f, 0.0007496115867979825f, 0.00019817128486465663f, 0.0002853185869753361f, 0.00011795468162745237f, 4.4031541619915515e-05f, 0.00026819229242391884f, 0.00021210523846093565f, 0.00012907551717944443f, 0.0001914931635838002f, 0.00022648136655334383f, 0.0002952690119855106f, 0.00025740606361068785f, 9.710113954497501e-05f, 0.0013856396544724703f, 0.00026861540391109884f, 0.00016146777488756925f, 5.8001478464575484e-05f, 9.172107820631936e-05f, 0.00019174476619809866f, 7.588296284666285e-05f, 0.00016600415983702987f, 0.00013706755999010056f, 0.0001678036933299154f, 0.00038290084921754897f, 0.00045392339234240353f, 0.00047301873564720154f, 0.00014743061910849065f, 0.0005179996369406581f, 0.000369569897884503f, 0.000149456798681058f, 0.00011307437671348453f, 0.0005120998248457909f, 0.00026579704717732966f, 0.00023231406521517783f, 0.00017337393364869058f, 0.00013320017023943365f, 0.00011015670315828174f, 0.00011122737487312406f, 0.00016693621000740677f, 9.95312220766209e-05f, 0.00023820146452635527f, 8.88774884515442e-05f, 0.0002582412853371352f, 0.0001253419031854719f, 4.201956471661106e-05f, 0.00017540859698783606f, 0.00013155701162759215f, 0.0002624746994115412f, 0.00010976479097735137f, 0.00013274986122269183f, 9.455704275751486e-05f, 0.0002610077499412f, 0.00019772535597439855f, 5.529283225769177e-05f, 0.00022657765657640994f, 0.00013073557056486607f, 0.0001465793466195464f, 6.0893409681739286e-05f, 0.00011600886500673369f, 0.0002773268788587302f, 0.000408469932153821f, 0.00031988078262656927f, 0.00022637202346231788f, 0.00019700585107784718f, 6.91131062922068e-05f, 5.172188684809953e-05f, 0.00010523416131036356f, 0.00013488564582075924f, 9.576523007126525e-05f, 0.00014020083472132683f, 0.0005437107174657285f, 0.00017588819900993258f, 0.00011163268936797976f, 0.0001510023430455476f, 0.00010485357051948085f, 8.19721317384392e-05f, 0.00010476248280610889f, 0.00023603987938258797f, 5.607129423879087e-05f, 0.00012579762551467866f, 0.0001710151700535789f, 0.00026706664357334375f, 0.00025691292830742896f, 0.0001136832288466394f, 0.00017718563321977854f, 0.0004661158309318125f, 0.00014851482410449535f, 0.0002568174968473613f, 0.00016582594253122807f, 0.000294974772259593f, 0.00015463330782949924f, 9.896802657749504e-05f, 0.00013824932102579623f, 0.00032228342024609447f, 0.00014842198288533837f, 0.0002187335630878806f, 0.0001524388208054006f, 0.0003874987014569342f, 0.0001637034583836794f, 0.00018892280058935285f, 7.089317659847438e-05f, 0.00015110692766029388f, 0.0003142860368825495f, 0.00019076972967013717f, 7.72578569012694e-05f, 0.0001207481327583082f, 7.97357497503981e-05f, 0.00013635199866257608f, 0.00020594836678355932f, 0.0001862042845459655f, 0.000159780218382366f, 0.0003553361748345196f, 0.0001511831651441753f, 9.883684833766893e-05f, 0.000204414565814659f, 0.00013418268645182252f, 9.14918418857269e-05f, 5.009221422369592e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #142 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0059697893448174f, 0.005835286807268858f, 0.011313829571008682f, 0.007239905185997486f, 0.0061704800464212894f, 0.010564018972218037f, 0.006604022812098265f, 0.011156361550092697f, 0.0117685217410326f, 0.01768452674150467f, 0.006223450414836407f, 0.016769113019108772f, 0.004900576546788216f, 0.016219092532992363f, 0.0062348442152142525f, 0.004941313061863184f, 0.022746054455637932f, 0.005239889957010746f, 0.010936849750578403f, 0.005554543808102608f, 0.007398189976811409f, 0.020051470026373863f, 0.01937078684568405f, 0.012452458031475544f, 0.015420680865645409f, 0.013438692316412926f, 0.011980751529335976f, 0.007069358602166176f, 0.004832604434341192f, 0.00680190185084939f, 0.008671404793858528f, 0.009870250709354877f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #143 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00014046563592273742f, 0.00013730087084695697f, 0.0002662077604327351f, 0.00017035071505233645f, 0.00014518776151817292f, 0.0002485651639290154f, 0.0001553887705085799f, 0.0002625026390887797f, 0.0002769063867162913f, 0.0004161065153311938f, 0.00014643413305748254f, 0.0003945673815906048f, 0.00011530768824741244f, 0.0003816257230937481f, 0.00014670222299173474f, 0.00011626619379967451f, 0.0005352012813091278f, 0.00012329152377787977f, 0.00025733764050528407f, 0.00013069514534436166f, 0.00017407505947630852f, 0.00047179931425489485f, 0.0004557832144200802f, 0.0002929990296252072f, 0.00036283954977989197f, 0.00031620453228242695f, 0.00028190005104988813f, 0.00016633784980513155f, 0.00011370834545232356f, 0.00016004475764930248f, 0.0002040330582531169f, 0.0002322412037756294f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #144 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0010951749281957746f, 0.0009402601281180978f, 0.0009627725230529904f, 0.0011470778845250607f, 0.0007486167014576495f, 0.0006127007072791457f, 0.0006295593339018524f, 0.0006858223932795227f, 0.0011428443249315023f, 0.0006836042739450932f, 0.0006655561737716198f, 0.000573366298340261f, 0.0008165127946995199f, 0.0007896549068391323f, 0.001116502215154469f, 0.0004984792321920395f, 0.000546382216271013f, 0.00048291246639564633f, 0.000899489619769156f, 0.0008572460501454771f, 0.0006959609454497695f, 0.0004943214007653296f, 0.0011445924174040556f, 0.000859868829138577f, 0.0010720764985308051f, 0.0009473712998442352f, 0.0007885271916165948f, 0.0006921595777384937f, 0.0006967228255234659f, 0.0010598251828923821f, 0.0006721010431647301f, 0.0007900130585767329f, 0.0006920823361724615f, 0.0007839936879463494f, 0.0004185022844467312f, 0.0006684800027869642f, 0.0006911976379342377f, 0.0011205167975276709f, 0.000628619163762778f, 0.0008797817281447351f, 0.0007220028783194721f, 0.0005167862982489169f, 0.0009163516224361956f, 0.0014670301461592317f, 0.0006040303851477802f, 0.0005911656189709902f, 0.0006254060426726937f, 0.0006185538950376213f, 0.00013300533464644104f, 0.0007204464636743069f, 0.0005306744133122265f, 0.0005906093865633011f, 0.0006276426138356328f, 0.0005454808124341071f, 0.0012556752189993858f, 0.0006511125830002129f, 0.00046803237637504935f, 0.0006287485011853278f, 0.0009657343616709113f, 0.0008234211127273738f, 0.0012779984390363097f, 0.0009043922182172537f, 0.0011674363631755114f, 0.0005224551423452795f, 0.0003211980510968715f, 0.0007924896781332791f, 0.0005555810639634728f, 0.0010334826074540615f, 0.0010147739667445421f, 0.0008829740690998733f, 0.0008360461797565222f, 0.0007543120300397277f, 0.0009999811882153153f, 0.0005834740004502237f, 0.0004892025026492774f, 0.0006918939761817455f, 0.0008716544252820313f, 0.0012467665364965796f, 0.0003400288987904787f, 0.0007315430557355285f, 0.0009937577415257692f, 0.0006960452301427722f, 0.0011267683003097773f, 0.0011834045872092247f, 0.0005003041587769985f, 0.0009529474773444235f, 0.0005351873696781695f, 0.0008363879169337451f, 0.0005414183251559734f, 0.0006945690256543458f, 0.000556793122086674f, 0.0008171834633685648f, 0.000755010696593672f, 0.000928957830183208f, 0.0005662273615598679f, 0.0007526305271312594f, 0.0004242434515617788f, 0.0007394967251457274f, 0.0007745043258182704f, 0.0005746129900217056f, 0.0006423323065973818f, 0.0006314903730526567f, 0.0008474561618641019f, 0.0006516564171761274f, 0.0007188771851360798f, 0.0011271215043962002f, 0.0010582562536001205f, 0.0007841694168746471f, 0.0006899342406541109f, 0.0007736283005215228f, 0.0007908925763331354f, 0.0010253755608573556f, 0.0007784832851029932f, 0.0005653544794768095f, 0.0006305837305262685f, 0.0008783351513557136f, 0.0008074829238466918f, 0.0006754304049536586f, 0.000837386935018003f, 0.000877041311468929f, 0.0011386716505512595f, 0.0009562588529661298f, 0.0010139449732378125f, 0.0010034374427050352f, 0.000965651182923466f, 0.0008258342277258635f, 0.0007184106507338583f, 0.0008106348686851561f, 0.0005791755393147469f, 0.0008094495278783143f, 0.0011300173355266452f, 0.0005655406857840717f, 0.0016061622882261872f, 0.0006179173360578716f, 0.0007384105119854212f, 0.001976501429453492f, 0.0004732444940600544f, 0.0008090325864031911f, 0.0006965266657061875f, 0.0008065344300121069f, 0.00088176887948066f, 0.000539661617949605f, 0.0008849219302646816f, 0.0007218311075121164f, 0.0008322705398313701f, 0.0009325077407993376f, 0.0007475881720893085f, 0.0009160854970104992f, 0.0008270686957985163f, 0.0007472852012142539f, 0.0007084100507199764f, 0.0004436962481122464f, 0.0006653523887507617f, 0.0007082010270096362f, 0.0007270363275893033f, 0.0017395801842212677f, 0.0006230709841474891f, 0.0006185423699207604f, 0.0008162865415215492f, 0.00042561013833619654f, 0.0008191500674001873f, 0.0009043439058586955f, 0.0009623622754588723f, 0.000579887768253684f, 0.000857462699059397f, 0.0014619134599342942f, 0.0009184106602333486f, 0.0003867511113639921f, 0.0007960916846059263f, 0.00011570985952857882f, 0.0010686633177101612f, 0.000731462670955807f, 0.0012601064518094063f, 0.0009628666448406875f, 0.0004349246446508914f, 0.0006873218808323145f, 0.0007187736337073147f, 0.0005550244823098183f, 0.000516562897246331f, 0.0005714794970117509f, 0.0008214385597966611f, 0.001040009898133576f, 0.0009293596958741546f, 0.0004763045581057668f, 0.00015445674944203347f, 0.001169785624369979f, 0.0006739205564372241f, 0.0008838630747050047f, 0.0008811011211946607f, 0.0006298527587205172f, 0.0012341076508164406f, 0.0008721962221898139f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #145 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005592626985162497f, 0.0004801538016181439f, 0.000491649960167706f, 0.0005857674404978752f, 0.00038228905759751797f, 0.00031288209720514715f, 0.0003214911266695708f, 0.00035022245720028877f, 0.0005836055497638881f, 0.00034908976522274315f, 0.000339873309712857f, 0.00029279556474648416f, 0.00041696091648191214f, 0.000403245649067685f, 0.0005701537011191249f, 0.00025455368449911475f, 0.0002790158614516258f, 0.0002466043515596539f, 0.00045933391083963215f, 0.0004377617733553052f, 0.0003553998249117285f, 0.0002524304436519742f, 0.0005844982224516571f, 0.0004391011316329241f, 0.00054746720707044f, 0.00048378517385572195f, 0.0004026697715744376f, 0.0003534586285240948f, 0.0003557888849172741f, 0.0005412109312601388f, 0.00034321550629101694f, 0.0004034285375382751f, 0.0003534191637299955f, 0.0004003546782769263f, 0.00021371262846514583f, 0.00034136639442294836f, 0.0003529673849698156f, 0.0005722037749364972f, 0.0003210110298823565f, 0.00044926986447535455f, 0.0003686984127853066f, 0.0002639023878145963f, 0.00046794465743005276f, 0.000749154482036829f, 0.0003084545023739338f, 0.00030188498203642666f, 0.0003193702141288668f, 0.00031587108969688416f, 6.792058411519974e-05f, 0.00036790361627936363f, 0.00027099449653178453f, 0.00030160092865116894f, 0.0003205123357474804f, 0.0002785555552691221f, 0.0006412238581106067f, 0.000332497525960207f, 0.0002390056906733662f, 0.00032107706647366285f, 0.0004931624862365425f, 0.00042048870818689466f, 0.0006526234210468829f, 0.00046183745143935084f, 0.0005961637361906469f, 0.0002667972585186362f, 0.00016402319306507707f, 0.0004046932444907725f, 0.00028371336520649493f, 0.0005277588497847319f, 0.0005182050517760217f, 0.0004509000573307276f, 0.0004269358469173312f, 0.0003851974324788898f, 0.0005106509779579937f, 0.0002979571872856468f, 0.00024981642491184175f, 0.000353322975570336f, 0.00044511957094073296f, 0.0006366745219565928f, 0.000173639360582456f, 0.00037357021938078105f, 0.0005074728978797793f, 0.000355442869476974f, 0.0005753961740992963f, 0.0006043181056156754f, 0.0002554856182541698f, 0.00048663272173143923f, 0.000273299083346501f, 0.0004271103534847498f, 0.0002764810051303357f, 0.0003546890220604837f, 0.0002843323163688183f, 0.0004173033812548965f, 0.0003855542163364589f, 0.00047438216279260814f, 0.00028914998983964324f, 0.00038433875306509435f, 0.00021664441737812012f, 0.000377631833544001f, 0.0003955088322982192f, 0.0002934322110377252f, 0.0003280137898400426f, 0.0003224772517569363f, 0.00043276246287859976f, 0.0003327752638142556f, 0.00036710224230773747f, 0.0005755765596404672f, 0.0005404097610153258f, 0.0004004444053862244f, 0.00035232221125625074f, 0.00039506147732026875f, 0.00040387766784988344f, 0.0005236188881099224f, 0.0003975407453253865f, 0.00028870426467619836f, 0.0003220142680220306f, 0.00044853115105070174f, 0.00041234970558434725f, 0.0003449156938586384f, 0.0004276205145288259f, 0.00044787043589167297f, 0.0005814747419208288f, 0.0004883236833848059f, 0.000517781765665859f, 0.0005124159506522119f, 0.0004931199946440756f, 0.0004217209934722632f, 0.00036686399835161865f, 0.0004139592929277569f, 0.000295762118184939f, 0.0004133539623580873f, 0.0005770553252659738f, 0.0002887993468903005f, 0.0008202038006857038f, 0.0003155460290145129f, 0.0003770771436393261f, 0.001009321422316134f, 0.00024166730872821063f, 0.0004131410678382963f, 0.00035568870953284204f, 0.0004118653596378863f, 0.0004502846277318895f, 0.00027558390866033733f, 0.0004518947680480778f, 0.00036861069384031f, 0.0004250077763572335f, 0.0004761949530802667f, 0.0003817638207692653f, 0.00046780877164565027f, 0.00042235138243995607f, 0.0003816091048065573f, 0.00036175709101371467f, 0.00022657818044535816f, 0.00033976923441514373f, 0.00036165036726742983f, 0.0003712688048835844f, 0.0008883350528776646f, 0.00031817780109122396f, 0.0003158652107231319f, 0.0004168453742749989f, 0.0002173423272324726f, 0.00041830766713246703f, 0.000461812800494954f, 0.0004914404707960784f, 0.00029612582875415683f, 0.00043787239701487124f, 0.0007465415983460844f, 0.00046899612061679363f, 0.00019749854982364923f, 0.0004065326356794685f, 5.908846651436761e-05f, 0.0005457242368720472f, 0.0003735291538760066f, 0.0006434866809286177f, 0.0004916980396956205f, 0.00022209886810742319f, 0.0003509882080834359f, 0.0003670493606477976f, 0.00028342913719825447f, 0.0002637883007992059f, 0.00029183205333538353f, 0.0004194763023406267f, 0.0005310920532792807f, 0.00047458737390115857f, 0.0002432299661450088f, 7.887497486080974e-05f, 0.0005973633960820735f, 0.0003441446751821786f, 0.00045135404798202217f, 0.00044994361815042794f, 0.0003216409822925925f, 0.0006302101537585258f, 0.00044539623195305467f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #146 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006341134198009968f, 0.003895357483997941f, 0.0031817189883440733f, 0.003010697662830353f, 0.00400596484541893f, 0.00451664300635457f, 0.003427676623687148f, 0.006312995217740536f, 0.0036380779929459095f, 0.0023397556506097317f, 0.0025808566715568304f, 0.0041813659481704235f, 0.005018177442252636f, 0.0038728464860469103f, 0.0033387355506420135f, 0.004463801626116037f, 0.005042561329901218f, 0.0028523514047265053f, 0.002425603801384568f, 0.007072096690535545f, 0.005234713200479746f, 0.005403083749115467f, 0.0019484006334096193f, 0.0045348661951720715f, 0.004668030887842178f, 0.005144967697560787f, 0.006210486404597759f, 0.004423091653734446f, 0.005048464983701706f, 0.003225562162697315f, 0.003716155653819442f, 0.00467944098636508f, 0.004534701816737652f, 0.0031108770053833723f, 0.005869010929018259f, 0.0060990056954324245f, 0.004474716726690531f, 0.0037541287019848824f, 0.006435164716094732f, 0.0019796276465058327f, 0.0036878373939543962f, 0.003189133247360587f, 0.003261284902691841f, 0.004913292825222015f, 0.004298470914363861f, 0.005368891637772322f, 0.0041207908652722836f, 0.0066808052361011505f, 0.0171477310359478f, 0.0033431132324039936f, 0.005525003653019667f, 0.003144863061606884f, 0.0027323770336806774f, 0.004566085524857044f, 0.0021654253359884024f, 0.004131863359361887f, 0.006239378359168768f, 0.004520682152360678f, 0.0033033089712262154f, 0.0020601132418960333f, 0.0037785479798913f, 0.004501078277826309f, 0.004044295754283667f, 0.005538543686270714f, 0.0034712066408246756f, 0.0024675847962498665f, 0.0032922495156526566f, 0.005269316490739584f, 0.003736356273293495f, 0.002139875665307045f, 0.004702506586909294f, 0.002483186312019825f, 0.005898045841604471f, 0.0052856807596981525f, 0.004579376429319382f, 0.004088366869837046f, 0.004080061335116625f, 0.003910025116056204f, 0.006192494183778763f, 0.0037906127981841564f, 0.004202462267130613f, 0.0027091463562101126f, 0.004830105695873499f, 0.007400172296911478f, 0.0050208596512675285f, 0.003220226150006056f, 0.004602172877639532f, 0.00480758398771286f, 0.004764521028846502f, 0.005012716632336378f, 0.006987655069679022f, 0.004484419710934162f, 0.006039985455572605f, 0.00439533032476902f, 0.003135479986667633f, 0.002649566624313593f, 0.0031906275544315577f, 0.006786716170608997f, 0.0045267860405147076f, 0.003598239738494158f, 0.00469787186011672f, 0.003540844190865755f, 0.0031771883368492126f, 0.005077668000012636f, 0.005344687961041927f, 0.006315890699625015f, 0.0057686977088451385f, 0.003599881660193205f, 0.002164294943213463f, 0.00394135806709528f, 0.006703726015985012f, 0.005277590360492468f, 0.004950714763253927f, 0.004213270265609026f, 0.005818360950797796f, 0.003532709088176489f, 0.0037263697013258934f, 0.003977225162088871f, 0.004814455285668373f, 0.005689482670277357f, 0.005250294227153063f, 0.004405041225254536f, 0.006486348807811737f, 0.005239664111286402f, 0.0019492564024403691f, 0.00352726923301816f, 0.002124416409060359f, 0.003687466960400343f, 0.004148524720221758f, 0.004701405297964811f, 0.0034578561317175627f, 0.003677841741591692f, 0.002586313523352146f, 0.0027826845180243254f, 0.006289613898843527f, 0.001547197112813592f, 0.005027830600738525f, 0.0030019639525562525f, 0.0030628759413957596f, 0.004215076100081205f, 0.0033938507549464703f, 0.0032125560101121664f, 0.0035626764874905348f, 0.004675525240600109f, 0.0033400910906493664f, 0.005105713848024607f, 0.003117513842880726f, 0.005575211253017187f, 0.004642456769943237f, 0.003959086257964373f, 0.003937007859349251f, 0.0059266225434839725f, 0.002678483724594116f, 0.0037453253753483295f, 0.003291461616754532f, 0.0025397378485649824f, 0.005928975064307451f, 0.005236395169049501f, 0.0030728185083717108f, 0.003221337916329503f, 0.0056403931230306625f, 0.002163553610444069f, 0.002864109119400382f, 0.002165870973840356f, 0.0063600181601941586f, 0.004224756266921759f, 0.002791520208120346f, 0.005124804098159075f, 0.001860721968114376f, 0.008653737604618073f, 0.0037292377091944218f, 0.0027031167410314083f, 0.00491218501701951f, 0.0032513511832803488f, 0.0036848250310868025f, 0.004286583978682756f, 0.005088212434202433f, 0.004814418964087963f, 0.0030907317996025085f, 0.00526027986779809f, 0.0025510620325803757f, 0.0053445748053491116f, 0.004912731237709522f, 0.004736785311251879f, 0.02391255460679531f, 0.0058602225035429f, 0.0045690336264669895f, 0.0027314370963722467f, 0.0038791578263044357f, 0.003774113254621625f, 0.002932465635240078f, 0.005898320581763983f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #147 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00014920315879862756f, 9.165547089651227e-05f, 7.486397953471169e-05f, 7.083994569256902e-05f, 9.425800089957193e-05f, 0.00010627395386109129f, 8.065121801337227e-05f, 0.0001485410612076521f, 8.560183778172359e-05f, 5.50530749023892e-05f, 6.0726040828740224e-05f, 9.838508412940428e-05f, 0.00011807476403191686f, 9.112580301007256e-05f, 7.855848525650799e-05f, 0.00010503063094802201f, 0.00011864850239362568f, 6.711415335303172e-05f, 5.7073033531196415e-05f, 0.00016640227113384753f, 0.00012316972424741834f, 0.00012713138130493462f, 4.5844721171306446e-05f, 0.00010670273331925273f, 0.00010983602260239422f, 0.00012105806672479957f, 0.00014612909581046551f, 0.00010407274385215715f, 0.00011878741497639567f, 7.589557935716584e-05f, 8.743895887164399e-05f, 0.00011010449816239998f, 0.0001066988697857596f, 7.319710857700557e-05f, 0.00013809437223244458f, 0.00014350602577906102f, 0.00010528745769988745f, 8.83324391907081e-05f, 0.00015141564654186368f, 4.6579476475017145e-05f, 8.677264850120991e-05f, 7.503842789446935e-05f, 7.673611980862916e-05f, 0.0001156068901764229f, 0.00010114049655385315f, 0.00012632686411961913f, 9.695978951640427e-05f, 0.0001571954198880121f, 0.0004034760349895805f, 7.866149098845199e-05f, 0.00013000008766539395f, 7.399677997455001e-05f, 6.429122731788084e-05f, 0.00010743730672402307f, 5.095118467579596e-05f, 9.722031973069534e-05f, 0.0001468089030822739f, 0.00010636899241944775f, 7.772491517243907e-05f, 4.847325544687919e-05f, 8.890701428754255e-05f, 0.00010590772581053898f, 9.515989950159565e-05f, 0.00013031867274548858f, 8.167545456672087e-05f, 5.8060821174876764e-05f, 7.746469782432541e-05f, 0.0001239839184563607f, 8.791426807874814e-05f, 5.0350015953881666e-05f, 0.00011064721911679953f, 5.842791506438516e-05f, 0.00013877755554858595f, 0.00012436896213330328f, 0.00010775003465823829f, 9.619686898076907e-05f, 9.600144403520972e-05f, 9.200059139402583e-05f, 0.00014570575149264187f, 8.919089304981753e-05f, 9.88814645097591e-05f, 6.374462100211531e-05f, 0.00011364954843884334f, 0.00017412169836461544f, 0.00011813787568826228f, 7.57700254325755e-05f, 0.00010828642552951351f, 0.00011311962589388713f, 0.00011210637603653595f, 0.00011794627789640799f, 0.00016441541083622724f, 0.0001055157626979053f, 0.00014211730740498751f, 0.00010341953748138621f, 7.377599831670523e-05f, 6.234274769667536e-05f, 7.50735925976187e-05f, 0.00015968743537086993f, 0.00010651261254679412f, 8.466446888633072e-05f, 0.00011053816706407815f, 8.331398566951975e-05f, 7.475737220374867e-05f, 0.00011947454186156392f, 0.00012575736036524177f, 0.0001486091932747513f, 0.0001357340661343187f, 8.470309694530442e-05f, 5.092458741273731e-05f, 9.273783507524058e-05f, 0.00015773472841829062f, 0.0001241785939782858f, 0.00011648741201497614f, 9.913577378029004e-05f, 0.00013690261403098702f, 8.312256977660581e-05f, 8.767929102759808e-05f, 9.358177339890972e-05f, 0.0001132813049480319f, 0.00013387018407229334f, 0.0001235363306477666f, 0.00010364803165430203f, 0.00015261997759807855f, 0.00012328621232882142f, 4.58648573840037e-05f, 8.29945711302571e-05f, 4.9986269004875794e-05f, 8.676393190398812e-05f, 9.761234832694754e-05f, 0.00011062130215577781f, 8.136132237268612e-05f, 8.653745317133144e-05f, 6.085443601477891e-05f, 6.54749310342595e-05f, 0.00014799091150052845f, 3.640463910414837e-05f, 0.00011830189760075882f, 7.063445082167163e-05f, 7.206766895251349e-05f, 9.917826537275687e-05f, 7.985531556187198e-05f, 7.558955257991329e-05f, 8.382768282899633e-05f, 0.00011001236271113157f, 7.859038305468857e-05f, 0.00012013444938929752f, 7.335326517932117e-05f, 0.00013118144124746323f, 0.00010923427907982841f, 9.315497300121933e-05f, 9.263548417948186e-05f, 0.00013944994134362787f, 6.30231443210505e-05f, 8.812530722934753e-05f, 7.744615868432447e-05f, 5.975853855488822e-05f, 0.00013950529682915658f, 0.0001232093054568395f, 7.230161281768233e-05f, 7.57961897761561e-05f, 0.00013271514035295695f, 5.0907143304357305e-05f, 6.739080708939582e-05f, 5.0961669330717996e-05f, 0.0001496474869782105f, 9.940603194991127e-05f, 6.568282697116956e-05f, 0.00012058363063260913f, 4.378169251140207e-05f, 0.00020361735369078815f, 8.774676825851202e-05f, 6.360274710459635e-05f, 0.00011558082769624889f, 7.650237967027351e-05f, 8.670176612213254e-05f, 0.00010086080146720633f, 0.00011972264474024996f, 0.00011328044638503343f, 7.272310176631436e-05f, 0.00012377130042295903f, 6.002499139867723e-05f, 0.00012575469736475497f, 0.00011559367703739554f, 0.000111453773570247f, 0.0005626483471132815f, 0.0001378875895170495f, 0.0001075066757039167f, 6.426910840673372e-05f, 9.127430530497804e-05f, 8.880266977939755e-05f, 6.899919389979914e-05f, 0.00013878401659894735f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #148 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008965895511209965f, 0.008204582147300243f, 0.010273530147969723f, 0.006846801843494177f, 0.009052552282810211f, 0.009412206709384918f, 0.009548458270728588f, 0.006352034397423267f, 0.007465351838618517f, 0.006310808472335339f, 0.007917634211480618f, 0.007977260276675224f, 0.007499975152313709f, 0.010479760356247425f, 0.010662964545190334f, 0.008263560943305492f, 0.007555804215371609f, 0.008589653298258781f, 0.010893711820244789f, 0.008801378309726715f, 0.011199520900845528f, 0.011564848944544792f, 0.00815640389919281f, 0.009281450882554054f, 0.008149673230946064f, 0.009692324325442314f, 0.009861206635832787f, 0.009615229442715645f, 0.008510841988027096f, 0.01246398314833641f, 0.008507211692631245f, 0.010196579620242119f, 0.0082168560475111f, 0.009901531971991062f, 0.012352555058896542f, 0.009748768992722034f, 0.009820892475545406f, 0.006402493920177221f, 0.008114513009786606f, 0.011795044876635075f, 0.013360363431274891f, 0.008434848859906197f, 0.010416572913527489f, 0.010455777868628502f, 0.014170515350997448f, 0.007803507149219513f, 0.007152492646127939f, 0.010718505829572678f, 0.006735692266374826f, 0.00880138948559761f, 0.007592202629894018f, 0.00907802488654852f, 0.007507311180233955f, 0.008896472863852978f, 0.007951196283102036f, 0.006866092793643475f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #149 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021096225827932358f, 0.00019304899615235627f, 0.0002417301293462515f, 0.00016110122669488192f, 0.00021300122898537666f, 0.0002214636915596202f, 0.00022466960945166647f, 0.00014945963630452752f, 0.00017565533926244825f, 0.00014848962018731982f, 0.00018629728583618999f, 0.00018770025053527206f, 0.00017647001368459314f, 0.0002465826109983027f, 0.00025089329574257135f, 0.00019443672499619424f, 0.00017778362962417305f, 0.00020210949878674f, 0.0002563226444181055f, 0.00020709125965368003f, 0.00026351812994107604f, 0.0002721140917856246f, 0.00019191538740415126f, 0.0002183870819862932f, 0.00019175701891072094f, 0.0002280546905240044f, 0.00023202839656732976f, 0.00022624069242738187f, 0.00020025510457344353f, 0.0002932701900135726f, 0.00020016968483105302f, 0.00023991952184587717f, 0.00019333779346197844f, 0.00023297722509596497f, 0.0002906483714468777f, 0.00022938280017115176f, 0.00023107982997316867f, 0.00015064691251609474f, 0.00019092972797807306f, 0.00027753046015277505f, 0.00031436150311492383f, 0.00019846703798975796f, 0.00024509584181942046f, 0.0002460183168295771f, 0.0003334239008836448f, 0.00018361193360760808f, 0.00016829394735395908f, 0.00025220014504157007f, 0.0001584868732606992f, 0.00020709152158815414f, 0.00017864006804302335f, 0.00021360059326980263f, 0.0001766426139511168f, 0.00020932877669110894f, 0.00018708697461988777f, 0.00016155513003468513f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #150 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00045467278687283397f, 0.0014868713915348053f, 0.000896855432074517f, 0.0007213153294287622f, 0.0007529049762524664f, 0.0007046880200505257f, 0.0007658553658984601f, 0.0006109398673288524f, 0.0005132390069775283f, 0.0006179193733260036f, 0.0005973998340778053f, 0.00041975892963819206f, 0.000948432192672044f, 0.00037335618981160223f, 0.0005714854341931641f, 0.0006651892908848822f, 0.0008142410661093891f, 0.0011624011676758528f, 0.0007938907947391272f, 0.0011116788955405354f, 0.000898862024769187f, 0.0007959784124977887f, 0.00047423577052541077f, 0.00014833580644335598f, 0.00033384351991117f, 0.0008166428888216615f, 0.000797360553406179f, 0.00064545136410743f, 0.00026013670139946043f, 0.0005395314074121416f, 0.00038447280530817807f, 0.00036584975896403193f, 0.0006340316613204777f, 0.0005923411226831377f, 0.0007929432322271168f, 0.00030978559516370296f, 0.0013889388646930456f, 0.0004932954325340688f, 0.0005709738470613956f, 0.0008914009085856378f, 0.0006351170013658702f, 0.0005710517871193588f, 0.00060366524849087f, 0.0010498655028641224f, 0.0003367862373124808f, 0.0007836571894586086f, 0.0008116619428619742f, 0.00043725341674871743f, 0.0013157177018001676f, 0.0003368965699337423f, 0.0007480356725864112f, 0.0006661207298748195f, 0.00037485131178982556f, 0.0009947468061000109f, 0.000694393937010318f, 0.0005843592225573957f, 0.0005214559496380389f, 0.00038727634819224477f, 0.000665423518512398f, 0.0010067963739857078f, 0.0004782660980708897f, 0.0009994007414206862f, 0.0005715288571082056f, 0.0004324442707002163f, 0.00047593293129466474f, 0.0006688279681839049f, 0.0005946318269707263f, 0.00026755224098451436f, 0.001028912141919136f, 0.0005886885919608176f, 0.0004019147309008986f, 0.0006999337347224355f, 0.0007187484297901392f, 0.00045245635556057096f, 0.0008567007607780397f, 0.0007183663547039032f, 0.0010861611226573586f, 0.0005190260708332062f, 0.00038583175046369433f, 0.0005178400315344334f, 0.00045372528256848454f, 0.0009457870619371533f, 0.0009675968321971595f, 0.0006113101844675839f, 0.00040328194154426455f, 0.000834644481074065f, 0.0006575732841156423f, 0.000801033980678767f, 0.0005329998675733805f, 0.00037102311034686863f, 0.0015134215354919434f, 0.0011646662605926394f, 0.00038775464054197073f, 0.0004106800479348749f, 0.0017093356000259519f, 0.0012174677103757858f, 0.0006773080094717443f, 0.0008457843214273453f, 0.0002451794862281531f, 0.0009793948847800493f, 0.0013050743145868182f, 0.0005247089429758489f, 0.00039308101986534894f, 0.0007267629262059927f, 0.0010638028616085649f, 0.0010687672765925527f, 0.0005626088823191822f, 0.0007076406036503613f, 0.0009177766041830182f, 0.0009571625851094723f, 0.0009022111771628261f, 0.0006087009096518159f, 0.0004894827725365758f, 0.0008452929905615747f, 0.0007090913713909686f, 0.0004743495082948357f, 0.0002763089432846755f, 0.0006248037680052221f, 0.0010329653741791844f, 0.0013382488396018744f, 0.0007399973110295832f, 0.0004296502156648785f, 0.0006516927387565374f, 0.001127966563217342f, 0.0006058546132408082f, 0.0004121071833651513f, 0.0010517998598515987f, 0.0003134321596007794f, 0.0014437348581850529f, 0.0006351175834424794f, 0.0010816447902470827f, 0.0007012553978711367f, 0.0011595673859119415f, 0.0004190362524241209f, 0.0008580057183280587f, 0.0010270454222336411f, 0.0004730355285573751f, 0.0005186314810998738f, 0.0005438859225250781f, 0.00036349339643493295f, 0.0005270599504001439f, 0.0005674844142049551f, 0.0007894552545621991f, 0.0005341949290595949f, 0.0017730005783960223f, 0.0009180515189655125f, 0.000700532749760896f, 0.0011357087641954422f, 0.0004957188502885401f, 0.001307514263316989f, 0.0006278356886468828f, 0.0006063978653401136f, 0.0009950286475941539f, 0.0006629907293245196f, 0.0005811164737679064f, 0.0003653665480669588f, 0.0009375176741741598f, 0.0007794927805662155f, 0.0008366958936676383f, 0.0005055266083218157f, 0.0005711405538022518f, 0.0007626700680702925f, 0.0003910513478331268f, 0.0006979663739912212f, 0.0004605057183653116f, 0.0010848970850929618f, 0.0005799359641969204f, 0.0003189976268913597f, 0.000360247737262398f, 0.0008752997382543981f, 0.000990163767710328f, 0.000629168062005192f, 0.00019497999164741486f, 0.0004747505590785295f, 0.00044327578507363796f, 0.00036835993523709476f, 0.0005950673948973417f, 0.0011312742717564106f, 0.0005064115393906832f, 0.001074276864528656f, 0.0010415135184302926f, 0.000424238940468058f, 0.0010388426017016172f, 0.001368874334730208f, 0.0010802936740219593f, 0.0010502171935513616f, 0.0009844086598604918f, 0.0004816487489733845f, 0.0007807091460563242f, 0.0003864176105707884f, 0.00033560325391590595f, 0.0012319000670686364f, 0.0006761654512956738f, 0.0007563671097159386f, 0.0016479919431731105f, 0.0008646190399304032f, 0.0007451030542142689f, 0.0008271897095255554f, 0.0007474409649148583f, 0.000949178880546242f, 0.0005854627816006541f, 0.0011633324902504683f, 0.0008609804208390415f, 0.00048743662773631513f, 0.0009649971616454422f, 0.0008252564584836364f, 0.0004357935395091772f, 0.0015710802981629968f, 0.0006735500646755099f, 0.0006612985162064433f, 0.001207317691296339f, 0.0008608059724792838f, 0.0005787065019831061f, 0.0005161488079465926f, 0.0017065426800400019f, 0.0004128324508201331f, 0.00019471527775749564f, 0.0008426622953265905f, 0.0006342065171338618f, 0.0005741296918131411f, 0.0009115991997532547f, 0.0005661780014634132f, 0.0009414294036105275f, 0.0008685940993018448f, 0.000668450549710542f, 0.0007758924039080739f, 0.0005054173525422812f, 0.0009252559393644333f, 0.0006966937216930091f, 0.0006779830437153578f, 0.000265087146544829f, 0.0008610934019088745f, 0.00019157466886099428f, 0.001453727250918746f, 0.0005168924108147621f, 0.0007220899569801986f, 0.0004940679064020514f, 0.0005968303885310888f, 0.0007201979169622064f, 0.0007767613860778511f, 0.001700413879007101f, 0.0005863740225322545f, 0.0006242234958335757f, 0.0006332380580715835f, 0.0005277179297991097f, 0.000699614523909986f, 0.0010986982379108667f, 0.0003824658924713731f, 0.0006191233405843377f, 0.0013774808030575514f, 0.000878503022249788f, 0.0010365645866841078f, 0.0006989875691942871f, 0.00017037797078955919f, 0.0009749240707606077f, 0.0006430661887861788f, 0.0004237744433339685f, 0.000895089702680707f, 0.0008618021383881569f, 0.0006576261948794127f, 0.0006081885658204556f, 0.0008590670768171549f, 0.0009239049977622926f, 0.0010319789871573448f, 0.00045514325029216707f, 0.0007052208529785275f, 0.0008798473863862455f, 0.0007787021459080279f, 0.0008424185798503458f, 0.0005346387624740601f, 0.0003201791550964117f, 0.0008232262916862965f, 0.00039482058491557837f, 0.0010703493608161807f, 0.0004470423446036875f, 0.0005732118152081966f, 0.0014809268759563565f, 0.0009204715606756508f, 0.00040226508281193674f, 0.0007689229096285999f, 0.00027002315619029105f, 0.0009515176061540842f, 0.0005905583966523409f, 0.001101035508327186f, 0.0008447765721939504f, 0.0004300918080843985f, 0.0005183490575291216f, 0.00024584346101619303f, 0.0006008836789987981f, 0.0009031434892676771f, 0.0007133425096981227f, 0.0005529851769097149f, 0.0006278549553826451f, 0.0004326544876676053f, 0.0008264989010058343f, 0.0005908151506446302f, 0.0006012931698933244f, 0.0006282964022830129f, 0.0010948089184239507f, 0.000477769470307976f, 0.0008207609644159675f, 0.0005226186476647854f, 0.0009926881175488234f, 0.0005300685297697783f, 0.0005792389856651425f, 0.0006246104021556675f, 0.0007382386829704046f, 0.0005911748739890754f, 0.0003303584235254675f, 0.0011561696883291006f, 0.0005487992311827838f, 0.0011367325205355883f, 0.0003642586525529623f, 0.00037566106766462326f, 0.00047065550461411476f, 0.0010921010980382562f, 0.0006398387486115098f, 0.0005719482433050871f, 0.0005325319361872971f, 0.0012424855958670378f, 0.00042673476855270565f, 0.0006249855505302548f, 0.0004526073462329805f, 0.0005269848625175655f, 0.0008849173900671303f, 0.0005349815473891795f, 0.0004352741816546768f, 0.0005787014961242676f, 0.0011143627343699336f, 0.001228479901328683f, 0.0007001645280979574f, 0.0005670823738910258f, 0.001098520471714437f, 0.0017004668479785323f, 0.001305063720792532f, 0.0003809678601101041f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #151 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011228901712456718f, 0.00036720765638165176f, 0.0002214933920186013f, 0.00017814083548728377f, 0.00018594242283143103f, 0.00017403444508090615f, 0.0001891407446237281f, 0.00015088178042788059f, 0.00012675292964559048f, 0.0001526054838905111f, 0.00014753783761989325f, 0.00010366646165493876f, 0.00023423113452736288f, 9.220653009833768e-05f, 0.0001411378470947966f, 0.00016427958325948566f, 0.00020109039905946702f, 0.00028707433375529945f, 0.00019606456044130027f, 0.00027454763767309487f, 0.00022198895749170333f, 0.0001965801347978413f, 0.00011712042760336772f, 3.663399911602028e-05f, 8.244821947300807e-05f, 0.0002016835642280057f, 0.0001969214790733531f, 0.0001594049681443721f, 6.42450904706493e-05f, 0.0001332462707068771f, 9.495196718489751e-05f, 9.03526961337775e-05f, 0.00015658467600587755f, 0.00014628851204179227f, 0.00019583053654059768f, 7.650671614101157e-05f, 0.0003430215874686837f, 0.00012182752834632993f, 0.00014101150736678392f, 0.00022014630667399615f, 0.00015685272228438407f, 0.00014103075955063105f, 0.00014908518642187119f, 0.0002592817763797939f, 8.317497122334316e-05f, 0.00019353719835635275f, 0.00020045343262609094f, 0.00010798701259773225f, 0.00032493841717951f, 8.320221968460828e-05f, 0.00018473986710887402f, 0.00016450960538350046f, 9.257577767129987e-05f, 0.00024566930369473994f, 0.00017149215273093432f, 0.00014431725139729679f, 0.00012878223787993193f, 9.564434731146321e-05f, 0.00016433742712251842f, 0.0002486451412551105f, 0.00011811577860498801f, 0.00024681867216713727f, 0.0001411485718563199f, 0.0001067993143806234f, 0.00011753956641769037f, 0.000165178207680583f, 0.00014685423229821026f, 6.607648538192734e-05f, 0.0002541069989092648f, 0.00014538645336870104f, 9.92595378193073e-05f, 0.00017286029469687492f, 0.0001775068958522752f, 0.00011174163228133693f, 0.0002115765237249434f, 0.00017741254123393446f, 0.0002682455815374851f, 0.0001281821314478293f, 9.528757800580934e-05f, 0.0001278892159461975f, 0.00011205501505173743f, 0.00023357786994893104f, 0.00023896415950730443f, 0.00015097323921509087f, 9.959719318430871e-05f, 0.00020612936350516975f, 0.0001623986754566431f, 0.00019782868912443519f, 0.00013163319090381265f, 9.163033973891288e-05f, 0.0003737646620720625f, 0.00028763373848050833f, 9.576246520737186e-05f, 0.00010142428072867915f, 0.00042214890709146857f, 0.0003006739425472915f, 0.0001672724902164191f, 0.00020888053404632956f, 6.055115954950452e-05f, 0.00024187788949348032f, 0.0003223098465241492f, 0.0001295856200158596f, 9.707790741231292e-05f, 0.0001794862182578072f, 0.00026272382820025086f, 0.0002639498852659017f, 0.0001389456301694736f, 0.00017476364155299962f, 0.0002266602241434157f, 0.00023638724815100431f, 0.00022281607380136847f, 0.0001503288367530331f, 0.00012088592484360561f, 0.0002087591856252402f, 0.00017512192425783724f, 0.00011714851279975846f, 6.823909643571824e-05f, 0.00015430570056196302f, 0.0002551079960539937f, 0.00033050283673219383f, 0.00018275466572958976f, 0.00010610927711240947f, 0.00016094637976493686f, 0.00027857013628818095f, 0.0001496258919360116f, 0.00010177673539146781f, 0.0002597594866529107f, 7.74072905187495e-05f, 0.00035655437386594713f, 0.00015685286780353636f, 0.00026713020633906126f, 0.0001731867087073624f, 0.0002863744739443064f, 0.00010348798241466284f, 0.00021189880499150604f, 0.0002536459651309997f, 0.00011682400509016588f, 0.00012808469182346016f, 0.00013432168634608388f, 8.977075049187988e-05f, 0.00013016624143347144f, 0.0001401497283950448f, 0.00019496912136673927f, 0.00013192833284847438f, 0.0004378720186650753f, 0.00022672812337987125f, 0.0001730082294670865f, 0.00028048219974152744f, 0.00012242603406775743f, 0.00032291244133375585f, 0.00015505448391195387f, 0.00014976006059441715f, 0.000245738890953362f, 0.0001637366076465696f, 0.00014351640129461884f, 9.023335587698966e-05f, 0.00023153561051003635f, 0.0001925087271956727f, 0.00020663598843384534f, 0.00012484821490943432f, 0.00014105267473496497f, 0.0001883540826383978f, 9.657664486439899e-05f, 0.00017237442079931498f, 0.00011372956214472651f, 0.0002679334138520062f, 0.00014322485367301852f, 7.878177711972967e-05f, 8.896918006939813e-05f, 0.00021616985031869262f, 0.0002445374266244471f, 0.0001553835318190977f, 4.815355714526959e-05f, 0.00011724756041076034f, 0.00010947434202535078f, 9.097262227442116e-05f, 0.00014696180005557835f, 0.00027938702260144055f, 0.00012506677012424916f, 0.00026531057665124536f, 0.0002572191006038338f, 0.00010477287287358195f, 0.0002565594913903624f, 0.0003380663110874593f, 0.0002667965309228748f, 0.0002593686222098768f, 0.00024311611196026206f, 0.00011895118223037571f, 0.0001928091369336471f, 9.543226769892499e-05f, 8.288281242130324e-05f, 0.00030423825955949724f, 0.00016699032858014107f, 0.0001867974642664194f, 0.0004069990536663681f, 0.00021353208285290748f, 0.0001840156182879582f, 0.00020428828429430723f, 0.00018459299462847412f, 0.00023441553639713675f, 0.00014458979421760887f, 0.000287304341327399f, 0.00021263345843181014f, 0.00012038059503538534f, 0.00023832212900742888f, 0.00020381083595566452f, 0.00010762647434603423f, 0.00038800446782261133f, 0.00016634441271889955f, 0.00016331869119312614f, 0.00029816722963005304f, 0.00021259037021081895f, 0.0001429212134098634f, 0.00012747154687531292f, 0.000421459146309644f, 0.00010195585491601378f, 4.808818266610615e-05f, 0.0002081094862660393f, 0.00015662786609027535f, 0.00014179089339450002f, 0.00022513461590278894f, 0.00013982708333060145f, 0.00023250166850630194f, 0.00021451378415804356f, 0.0001650850026635453f, 0.0001916195615194738f, 0.00012482123565860093f, 0.00022850737150292844f, 0.0001720601285342127f, 0.0001674392115091905f, 6.546768418047577e-05f, 0.00021266135445330292f, 4.7312554670497775e-05f, 0.00035902217496186495f, 0.00012765519204549491f, 0.0001783321495167911f, 0.00012201830395497382f, 0.00014739720791112632f, 0.00017786487296689302f, 0.00019183415861334652f, 0.00041994554339908063f, 0.00014481483958661556f, 0.00015416239330079406f, 0.0001563886908115819f, 0.00013032872811891139f, 0.00017278146697208285f, 0.0002713418216444552f, 9.445632167626172e-05f, 0.00015290282317437232f, 0.0003401918220333755f, 0.00021696095063816756f, 0.00025599688524380326f, 0.0001726266200421378f, 4.207767779007554e-05f, 0.00024077374837361276f, 0.00015881590661592782f, 0.00010465816012583673f, 0.00022105731477495283f, 0.00021283639944158494f, 0.00016241174307651818f, 0.00015020229329820722f, 0.0002121609286405146f, 0.00022817372519057244f, 0.00025486439699307084f, 0.00011240520689170808f, 0.00017416603805031627f, 0.00021729296713601798f, 0.00019231346959713846f, 0.0002080492995446548f, 0.00013203795242588967f, 7.90735793998465e-05f, 0.00020330944971647114f, 9.75075236056e-05f, 0.00026434060418978333f, 0.00011040455137845129f, 0.00014156420365907252f, 0.00036573957186192274f, 0.0002273257850902155f, 9.934606350725517e-05f, 0.00018989831733051687f, 6.66867199470289e-05f, 0.00023499313101638108f, 0.0001458482292946428f, 0.00027191906701773405f, 0.0002086316526401788f, 0.00010621833644108847f, 0.00012801492994185537f, 6.071513780625537e-05f, 0.00014839823415968567f, 0.00022304632875602692f, 0.00017617181583773345f, 0.0001365688949590549f, 0.00015505924238823354f, 0.00010685123561415821f, 0.00020411767764016986f, 0.00014591164654120803f, 0.00014849936997052282f, 0.00015516826533712447f, 0.0002703813079278916f, 0.00011799312778748572f, 0.00020270059758331627f, 0.00012906937627121806f, 0.0002451608597766608f, 0.00013090924767311662f, 0.00014305271906778216f, 0.00015425794117618352f, 0.0001823203347157687f, 0.0001460004859836772f, 8.158751734299585e-05f, 0.00028553535230457783f, 0.00013553511234931648f, 0.0002807350247167051f, 8.99597434909083e-05f, 9.27757573663257e-05f, 0.00011623621685430408f, 0.0002697125601116568f, 0.00015801884001120925f, 0.00014125215238891542f, 0.00013151763414498419f, 0.00030685251113027334f, 0.00010538926289882511f, 0.00015435059322044253f, 0.00011177892156410962f, 0.00013014768774155527f, 0.0002185450866818428f, 0.00013212260091677308f, 0.0001074982137652114f, 0.000142919976497069f, 0.0002752104483079165f, 0.00030339357908815145f, 0.00017291729454882443f, 0.00014005044067744166f, 0.00027129793306812644f, 0.0004199586110189557f, 0.0003223072271794081f, 9.408636105945334e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004979890771210194f, 0.006859437096863985f, 0.006233252119272947f, 0.011830460280179977f, 0.005668355617672205f, 0.006306423805654049f, 0.004642136860638857f, 0.007721958216279745f, 0.008328023366630077f, 0.007695943117141724f, 0.01025486271828413f, 0.008856924250721931f, 0.002231213729828596f, 0.011541472747921944f, 0.006861304398626089f, 0.006645331624895334f, 0.010823494754731655f, 0.0042138178832829f, 0.0068522244691848755f, 0.010360096581280231f, 0.004415364004671574f, 0.007107377517968416f, 0.00932226236909628f, 0.012747331522405148f, 0.012476210482418537f, 0.0116600152105093f, 0.007254427764564753f, 0.005552612245082855f, 0.014336829073727131f, 0.007685441989451647f, 0.009042498655617237f, 0.00872727856040001f, 0.005506882909685373f, 0.01678961142897606f, 0.00902355182915926f, 0.015509488992393017f, 0.012208781205117702f, 0.00867921207100153f, 0.009656994603574276f, 0.006069239228963852f, 0.011026371270418167f, 0.012070998549461365f, 0.008338771760463715f, 0.008236292749643326f, 0.01886601932346821f, 0.013186495751142502f, 0.00758405914530158f, 0.006926119327545166f, 0.002595342928543687f, 0.008302821777760983f, 0.006612719967961311f, 0.002962186699733138f, 0.009599878452718258f, 0.005863924045115709f, 0.007683910429477692f, 0.007188583258539438f, 0.007003564387559891f, 0.008014475926756859f, 0.004975136835128069f, 0.01212028507143259f, 0.013952641747891903f, 0.007300639990717173f, 0.014155286364257336f, 0.010814571753144264f, 0.02220636047422886f, 0.0036111262161284685f, 0.012541305273771286f, 0.010220198892056942f, 0.0037522963248193264f, 0.012245641089975834f, 0.013724825344979763f, 0.004853968974202871f, 0.00371822202578187f, 0.014360742643475533f, 0.0068412767723202705f, 0.007611582521349192f, 0.007874485105276108f, 0.004666213411837816f, 0.010056923143565655f, 0.007135108113288879f, 0.01759498007595539f, 0.01205484475940466f, 0.009392153471708298f, 0.00563545897603035f, 0.010695398785173893f, 0.0036278781481087208f, 0.00308099202811718f, 0.0061722113750875f, 0.008885824121534824f, 0.014232131652534008f, 0.009059671312570572f, 0.00897036399692297f, 0.005416227504611015f, 0.01717454008758068f, 0.012814617715775967f, 0.010562358424067497f, 0.007728989236056805f, 0.014269229955971241f, 0.015678485855460167f, 0.0038761107716709375f, 0.003966439515352249f, 0.01148887351155281f, 0.008513440378010273f, 0.005869459826499224f, 0.007266267202794552f, 0.005728260148316622f, 0.007364653050899506f, 0.012966970913112164f, 0.008765698410570621f, 0.004331561736762524f, 0.010980243794620037f, 0.007652745116502047f, 0.006481953430920839f, 0.0021567170042544603f, 0.007710040546953678f, 0.020529428496956825f, 0.020284421741962433f, 0.004589001182466745f, 0.00724581116810441f, 0.008751939050853252f, 0.007345497142523527f, 0.008887900039553642f, 0.00570731982588768f, 0.0033285566605627537f, 0.006008276250213385f, 0.011242520995438099f, 0.012621158733963966f, 0.018707187846302986f, 0.002960739890113473f, 0.009343806654214859f, 0.005935845896601677f, 0.006304773967713118f, 0.0029261198360472918f, 0.013356488198041916f, 0.008417267352342606f, 0.013637000694870949f, 0.020199213176965714f, 0.006948129739612341f, 0.007278528064489365f, 0.010433631017804146f, 0.009238806553184986f, 0.009818106889724731f, 0.003182760439813137f, 0.00836717989295721f, 0.005388641729950905f, 0.004794043023139238f, 0.007904843427240849f, 0.008216310292482376f, 0.012159683741629124f, 0.00376322609372437f, 0.0071470895782113075f, 0.004259047098457813f, 0.005091664846986532f, 0.004455641843378544f, 0.011045383289456367f, 0.012488079257309437f, 0.010472504422068596f, 0.0081154964864254f, 0.008980310522019863f, 0.006806050427258015f, 0.008174842223525047f, 0.005545787513256073f, 0.011329316534101963f, 0.004530126228928566f, 0.007798483595252037f, 0.007983890362083912f, 0.009098188951611519f, 0.012984763830900192f, 0.008894704282283783f, 0.006278620567172766f, 0.0047916085459291935f, 0.00854183454066515f, 0.016230028122663498f, 0.007731279358267784f, 0.010343612171709538f, 0.013448875397443771f, 0.006960760802030563f, 0.002145281294360757f, 0.014450492337346077f, 0.013033316470682621f, 0.0049692243337631226f, 0.012589488178491592f, 0.0028529991395771503f, 0.009766200557351112f, 0.015955081209540367f, 0.007203312590718269f, 0.007298105861991644f, 0.0045988187193870544f, 0.004791723098605871f, 0.012943079695105553f, 0.113630510866642f, 0.009375585243105888f, 0.009409033693373203f, 0.009805548936128616f, 0.00609485013410449f, 0.006420380901545286f, 0.004771870095282793f, 0.005166368559002876f, 0.01046324148774147f, 0.00828064139932394f, 0.007688324432820082f, 0.007198819424957037f, 0.005160284694284201f, 0.008810846135020256f, 0.003479463281109929f, 0.006165343336760998f, 0.008402922190725803f, 0.002319982508197427f, 0.008462304249405861f, 0.005659005604684353f, 0.003017303766682744f, 0.011419207789003849f, 0.005262221675366163f, 0.011652640998363495f, 0.008784815669059753f, 0.008608823642134666f, 0.015202282927930355f, 0.0031761834397912025f, 0.011183785274624825f, 0.006769199389964342f, 0.007577314507216215f, 0.007844698615372181f, 0.010628779418766499f, 0.007532638031989336f, 0.004718372132629156f, 0.005415219813585281f, 0.007814018987119198f, 0.006273219361901283f, 0.004901600535959005f, 0.007674484513700008f, 0.012158341705799103f, 0.0035075314808636904f, 0.0148842204362154f, 0.002365324879065156f, 0.010172029957175255f, 0.006220533978193998f, 0.009189235977828503f, 0.006987948436290026f, 0.002371677430346608f, 0.008233406580984592f, 0.01426646113395691f, 0.008311711251735687f, 0.007094640284776688f, 0.0043134531006217f, 0.006057419814169407f, 0.013694800436496735f, 0.00529281422495842f, 0.009675033390522003f, 0.009255737997591496f, 0.01158191729336977f, 0.004529342986643314f, 0.0024899840354919434f, 0.01029400248080492f, 0.014285964891314507f, 0.006227016448974609f, 0.007906123995780945f, 0.016946803778409958f, 0.0017061906401067972f, 0.005716543644666672f, 0.010798565112054348f, 0.005876006092876196f, 0.008117812685668468f, 0.004826066549867392f, 0.0018191575072705746f, 0.008718947879970074f, 0.018808841705322266f, 0.008015943691134453f, 0.005558901000767946f, 0.01225235965102911f, 0.009040956385433674f, 0.01575542986392975f, 0.007480116561055183f, 0.008164296858012676f, 0.008189021609723568f, 0.008912943303585052f, 0.0064856186509132385f, 0.01713731698691845f, 0.013119448907673359f, 0.0084249721840024f, 0.006270324345678091f, 0.01337815634906292f, 0.011774118058383465f, 0.006826851982623339f, 0.015360417775809765f, 0.006868188735097647f, 0.008116134442389011f, 0.010677514597773552f, 0.01071988046169281f, 0.006334729492664337f, 0.01495136134326458f, 0.010587138123810291f, 0.009518241509795189f, 0.013677060604095459f, 0.007666345220059156f, 0.007744187489151955f, 0.008112888783216476f, 0.004915955942124128f, 0.007146183867007494f, 0.01287860982120037f, 0.009613340720534325f, 0.00463388254866004f, 0.007214841432869434f, 0.006004882510751486f, 0.0075862472876906395f, 0.006515628658235073f, 0.004265997093170881f, 0.007362246513366699f, 0.004742339253425598f, 0.00700352992862463f, 0.0057104541920125484f, 0.01074787974357605f, 0.005670052487403154f, 0.013567160815000534f, 0.008862537331879139f, 0.008610188029706478f, 0.014800225384533405f, 0.006303692236542702f, 0.011806569993495941f, 0.007419021800160408f, 0.004713417962193489f, 0.01586339809000492f, 0.011755636893212795f, 0.011475395411252975f, 0.006175345275551081f, 0.016571827232837677f, 0.011355673894286156f, 0.008856101892888546f, 0.009249786846339703f, 0.005836443975567818f, 0.007439358625560999f, 0.009290612302720547f, 0.006885095965117216f, 0.008440885692834854f, 0.003722695168107748f, 0.01287402119487524f, 0.01665825955569744f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #153 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011717390589183196f, 0.00016139852232299745f, 0.0001466647518100217f, 0.0002783637901302427f, 0.0001333730760961771f, 0.0001483864471083507f, 0.00010922674846369773f, 0.00018169313261751086f, 0.00019595350022427738f, 0.00018108102085534483f, 0.00024129089433699846f, 0.00020839822536800057f, 5.249914829619229e-05f, 0.0002715640584938228f, 0.0001614424545550719f, 0.00015636075113434345f, 0.0002546704781707376f, 9.914865950122476e-05f, 0.00016122881788760424f, 0.00024376699002459645f, 0.0001038909176713787f, 0.00016723241424188018f, 0.0002193473483202979f, 0.00029993720818310976f, 0.00029355791048146784f, 0.00027435331139713526f, 0.00017069242312572896f, 0.00013064969971310347f, 0.0003373371728230268f, 0.00018083392933476716f, 0.00021276467305142432f, 0.00020534773648250848f, 0.0001295737165492028f, 0.0003950496902689338f, 0.0002123188751284033f, 0.00036492914659902453f, 0.0002872654586099088f, 0.0002042167616309598f, 0.00022722341236658394f, 0.0001428056275472045f, 0.00025944403023459017f, 0.0002840234956238419f, 0.00019620639795903116f, 0.00019379513105377555f, 0.00044390634866431355f, 0.0003102704940829426f, 0.0001784484484232962f, 0.00016296750982291996f, 6.106689397711307e-05f, 0.00019536050967872143f, 0.00015559341409243643f, 6.969851528992876e-05f, 0.00022587949933949858f, 0.00013797468272969127f, 0.00018079789879266173f, 0.00016914313891902566f, 0.00016478975885547698f, 0.00018857591203413904f, 0.00011706204531947151f, 0.00028518319595605135f, 0.0003282974648755044f, 0.000171779771335423f, 0.0003330655745230615f, 0.00025446052313782275f, 0.0005225025815889239f, 8.496767986798659e-05f, 0.0002950895286630839f, 0.00024047527404036373f, 8.828932914184406e-05f, 0.000288132723653689f, 0.00032293706317432225f, 0.00011421103408792987f, 8.748757682042196e-05f, 0.0003378998371772468f, 0.0001609712198842317f, 0.00017909606685861945f, 0.00018528201326262206f, 0.00010979326179949567f, 0.00023663349566049874f, 0.0001678848930168897f, 0.00041399954352527857f, 0.00028364339959807694f, 0.0002209918457083404f, 0.0001325990306213498f, 0.0002516564563848078f, 8.536184031981975e-05f, 7.249393092934042e-05f, 0.00014522850688081235f, 0.00020907822181470692f, 0.00033487367909401655f, 0.0002131687360815704f, 0.00021106739586684853f, 0.0001274406531592831f, 0.00040410683141089976f, 0.0003015204274561256f, 0.000248526077484712f, 0.00018185857334174216f, 0.00033574659028090537f, 0.00036890554474666715f, 9.120260801864788e-05f, 9.3327987997327e-05f, 0.00027032644720748067f, 0.00020031625172123313f, 0.00013810493692290038f, 0.0001709709904389456f, 0.00013478258915711194f, 0.00017328595276921988f, 0.0003051052044611424f, 0.00020625173056032509f, 0.00010191910405410454f, 0.00025835869018919766f, 0.00018006459868047386f, 0.00015251655713655055f, 5.074628279544413e-05f, 0.00018141271721106023f, 0.00048304538358934224f, 0.0004772805259563029f, 0.00010797649883897975f, 0.00017048967129085213f, 0.00020592797955032438f, 0.00017283523629885167f, 0.00020912705804221332f, 0.00013428987585939467f, 7.831898255972192e-05f, 0.0001413712016073987f, 0.0002645299246069044f, 0.0002969684428535402f, 0.0004401691257953644f, 6.9664471084252e-05f, 0.00021985427883919328f, 0.00013966696860734373f, 0.0001483476225985214f, 6.884987669764087e-05f, 0.0003142703208141029f, 0.00019805335614364594f, 0.0003208706039004028f, 0.0004752756212837994f, 0.00016348541248589754f, 0.00017125948215834796f, 0.00024549721274524927f, 0.00021738368377555162f, 0.0002310142881469801f, 7.488848495995626e-05f, 0.00019687482563313097f, 0.00012679157953243703f, 0.00011280101170996204f, 0.0001859963231254369f, 0.00019332495867274702f, 0.00028611021116375923f, 8.854649786371738e-05f, 0.00016816682182252407f, 0.0001002128774416633f, 0.00011980388080701232f, 0.00010483863297849894f, 0.0002598913852125406f, 0.0002938371617347002f, 0.0002464118879288435f, 0.00019095286552328616f, 0.00021130143431946635f, 0.00016014237189665437f, 0.0001923492382047698f, 0.00013048911932855844f, 0.00026657216949388385f, 0.00010659120744094253f, 0.00018349372840020806f, 0.00018785624706652015f, 0.0002140750439139083f, 0.00030552386306226254f, 0.0002092871582135558f, 0.00014773225120734423f, 0.00011274373537162319f, 0.00020098434470128268f, 0.0003818830300588161f, 0.0001819124590838328f, 0.00024337910872418433f, 0.00031644414411857724f, 0.00016378260625060648f, 5.0477206968935207e-05f, 0.00034001158201135695f, 0.0003066662757191807f, 0.00011692292900988832f, 0.00029622326837852597f, 6.712938920827582e-05f, 0.0002297929604537785f, 0.000375413685105741f, 0.00016948970733210444f, 0.00017172013758681715f, 0.00010820750321727246f, 0.00011274642747594044f, 0.0003045430639758706f, 0.0026736592408269644f, 0.0002206020144512877f, 0.00022138902568258345f, 0.0002307187969563529f, 0.0001434082369087264f, 0.00015106778300832957f, 0.00011227929644519463f, 0.00012156161392340437f, 0.000246193929342553f, 0.00019483861979097128f, 0.00018090175581164658f, 0.00016938398766797036f, 0.00012141846673330292f, 0.0002073140349239111f, 8.186972263501957e-05f, 0.00014506690786220133f, 0.00019771582446992397f, 5.458782470668666e-05f, 0.00019911304116249084f, 0.00013315308024175465f, 7.099538197508082e-05f, 0.0002686872612684965f, 0.00012381697888486087f, 0.0002741797943599522f, 0.00020670154481194913f, 0.0002025605645030737f, 0.00035770077374763787f, 7.473373261746019e-05f, 0.00026314790011383593f, 0.0001592752814758569f, 0.00017828975978773087f, 0.00018458114936947823f, 0.00025008892407640815f, 0.00017723854398354888f, 0.00011102051939815283f, 0.00012741693353746086f, 0.00018385927251074463f, 0.0001476051693316549f, 0.000115331778943073f, 0.0001805761130526662f, 0.0002860786335077137f, 8.253015403170139e-05f, 0.00035021695657633245f, 5.565470564761199e-05f, 0.00023934188357088715f, 0.00014636550622526556f, 0.00021621731866616756f, 0.0001644223229959607f, 5.580417564488016e-05f, 0.00019372721726540476f, 0.0003356814559083432f, 0.00019556967890821397f, 0.00016693271754775196f, 0.00010149301670026034f, 0.00014252752589527518f, 0.0003222305967938155f, 0.00012453680392354727f, 0.00022764784807804972f, 0.00021778207155875862f, 0.0002725156955420971f, 0.0001065727774403058f, 5.8587862440617755e-05f, 0.0002422118268441409f, 0.000336140365106985f, 0.0001465180394006893f, 0.00018602644558995962f, 0.0003987483214586973f, 4.014566366095096e-05f, 0.00013450691767502576f, 0.00025408389046788216f, 0.00013825896894559264f, 0.0001910073624458164f, 0.00011355450988048688f, 4.2803705582628027e-05f, 0.00020515172218438238f, 0.0004425609949976206f, 0.00018861044372897595f, 0.00013079767813906074f, 0.00028829081566073f, 0.00021272839512676f, 0.0003707160067278892f, 0.00017600275168661028f, 0.0001921011134982109f, 0.00019268286996521056f, 0.0002097163232974708f, 0.00015260279178619385f, 0.00040323100984096527f, 0.00030869292095303535f, 0.00019823464390356094f, 0.00014753705181647092f, 0.00031478016171604395f, 0.00027703808154910803f, 0.00016063181101344526f, 0.0003614216111600399f, 0.00016160444647539407f, 0.0001909678685478866f, 0.0002512356441002339f, 0.0002522324793972075f, 0.0001490524591645226f, 0.0003517967415973544f, 0.0002491091436240822f, 0.00022395863197743893f, 0.000321813189657405f, 0.00018038459529634565f, 0.00018221618665847927f, 0.00019089150009676814f, 0.00011566955072339624f, 0.0001681455032667145f, 0.00030302611412480474f, 0.00022619625087827444f, 0.00010903253132710233f, 0.00016976098413579166f, 0.00014129135524854064f, 0.00017849993309937418f, 0.00015330890892073512f, 0.00010037640458904207f, 0.0001732293312670663f, 0.00011158445704495534f, 0.0001647889439482242f, 0.00013436362496577203f, 0.0002528913028072566f, 0.00013341300655156374f, 0.00031922731432132423f, 0.00020853029855061322f, 0.00020259266602806747f, 0.00034824060276150703f, 0.000148322171298787f, 0.0002778016496449709f, 0.00017456522618886083f, 0.000110903951281216f, 0.00037325642188079655f, 0.0002766032121144235f, 0.00027000930276699364f, 0.00014530224143527448f, 0.0003899253497365862f, 0.0002671923430170864f, 0.00020837887132074684f, 0.00021764205303043127f, 0.00013732809748034924f, 0.00017504373681731522f, 0.000218602639506571f, 0.00016200226673390716f, 0.00019860907923430204f, 8.759283082326874e-05f, 0.00030291813891381025f, 0.00039195906720124185f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #154 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012153648771345615f, 0.00823470950126648f, 0.004597831051796675f, 0.011198684573173523f, 0.008210670202970505f, 0.009442979469895363f, 0.011006820946931839f, 0.00835710484534502f, 0.004176723305135965f, 0.01396034937351942f, 0.005269933957606554f, 0.0050437794998288155f, 0.006669235415756702f, 0.00548681290820241f, 0.0039448500610888f, 0.005132939200848341f, 0.01083989255130291f, 0.0037077695596963167f, 0.011308291926980019f, 0.0049752467311918736f, 0.0065085627138614655f, 0.006077533587813377f, 0.012245479971170425f, 0.009913896210491657f, 0.008837223052978516f, 0.006703123915940523f, 0.005194175057113171f, 0.002997403033077717f, 0.00649096816778183f, 0.003666980192065239f, 0.005659124348312616f, 0.0038350361865013838f, 0.006221747025847435f, 0.004751529544591904f, 0.010362659581005573f, 0.005477121565490961f, 0.005333566572517157f, 0.004540473222732544f, 0.00766016636043787f, 0.0038517990615218878f, 0.006742304656654596f, 0.004688422195613384f, 0.005473145749419928f, 0.005115084815770388f, 0.003841568250209093f, 0.005903585813939571f, 0.008996945805847645f, 0.00381682557053864f, 0.0033727202098816633f, 0.004864687565714121f, 0.0043309759348630905f, 0.006875947583466768f, 0.005007075145840645f, 0.010637400671839714f, 0.005833221133798361f, 0.005370978266000748f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #155 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00028596821357496083f, 0.00019375787815079093f, 0.00010818426380865276f, 0.0002634984557516873f, 0.0001931922452058643f, 0.00022218775120563805f, 0.00025898401509039104f, 0.00019663776038214564f, 9.827584290178493e-05f, 0.0003284788108430803f, 0.0001239984412677586f, 0.00011867716966662556f, 0.00015692318265791982f, 0.00012910147779621184f, 9.282000246457756e-05f, 0.00012077503924956545f, 0.00025505630765110254f, 8.724163490114734e-05f, 0.0002660774625837803f, 0.00011706462828442454f, 0.00015314265328925103f, 0.00014300079783424735f, 0.00028812894015572965f, 0.00023326814698521048f, 0.0002079346595564857f, 0.00015772056940477341f, 0.00012221588985994458f, 7.052713044686243e-05f, 0.00015272866585291922f, 8.628188516013324e-05f, 0.0001331558742094785f, 9.023614984471351e-05f, 0.00014639405708294362f, 0.00011180069850524887f, 0.0002438272931613028f, 0.00012887344928458333f, 0.00012549568782560527f, 0.00010683466825867072f, 0.00018023920711129904f, 9.063056495506316e-05f, 0.0001586424623383209f, 0.00011031582107534632f, 0.0001287799095734954f, 0.00012035494000883773f, 9.03898398973979e-05f, 0.00013890789705328643f, 0.00021169285173527896f, 8.980766142485663e-05f, 7.935812755022198e-05f, 0.00011446324060671031f, 0.00010190531611442566f, 0.00016178700025193393f, 0.00011781353532569483f, 0.0002502917777746916f, 0.00013725226745009422f, 0.00012637596228159964f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #156 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006707966676913202f, 0.0005506190937012434f, 0.0006039665313437581f, 0.00020894463523291051f, 0.0006489387014880776f, 0.0004072333103977144f, 0.00026035460177809f, 0.0006707865977659822f, 0.000684884435031563f, 0.0008513384964317083f, 0.0002844294358510524f, 0.00042221954208798707f, 0.0004525505646597594f, 0.00019663549028337002f, 0.0002691456757020205f, 0.0006139235920272768f, 0.0007372527616098523f, 0.0007033760193735361f, 0.0006715105264447629f, 0.0009853747906163335f, 0.0006800233968533576f, 0.0007440081681124866f, 0.0005549597553908825f, 0.001029378967359662f, 0.0005817777127958834f, 0.0028104986995458603f, 0.000473106192657724f, 0.000818021537270397f, 0.00045703863725066185f, 0.00014555917005054653f, 0.00026170225464738905f, 0.0007069678395055234f, 0.0008586969925090671f, 0.0002300168271176517f, 0.00039981212466955185f, 0.0004226237942930311f, 0.0009638623450882733f, 0.0007937775226309896f, 0.0003609968989621848f, 0.0009033243404701352f, 0.00081347965169698f, 0.0007541034137830138f, 0.0007103629759512842f, 0.0005888984305784106f, 0.0004846818628720939f, 0.00040810450445860624f, 0.0003812359645962715f, 0.0008275670697912574f, 0.0005738790496252477f, 0.00036348734283819795f, 0.00027101783780381083f, 0.0004133339098189026f, 0.0004687596228905022f, 0.00041753737605176866f, 0.0006308014271780849f, 0.00044106063432991505f, 0.00019078940385952592f, 0.0005427250289358199f, 0.0004799278103746474f, 0.0006412935326807201f, 0.0006457014242187142f, 0.0004432958085089922f, 0.0006875860854052007f, 0.0006441973964683712f, 0.0008381330408155918f, 0.0004900690983049572f, 0.0004013636789750308f, 0.0007176632061600685f, 0.0007418650784529746f, 0.0003455029218457639f, 0.0003505441709421575f, 0.0003515608550515026f, 0.0005782867083325982f, 0.0006050259689800441f, 0.0006588070536963642f, 0.0007130314479582012f, 0.0008078668615780771f, 0.0009598657488822937f, 0.000265156792011112f, 0.0006469950312748551f, 0.000636652868706733f, 0.0007672059000469744f, 0.0009446050389669836f, 0.0007729092612862587f, 0.0008447204018011689f, 0.0005073311040177941f, 0.0005209872615523636f, 0.0007937048794701695f, 0.0007722668233327568f, 0.0005467397277243435f, 0.0005716599407605827f, 0.0005443972768262029f, 0.0005165785551071167f, 0.0006160364719107747f, 0.000744046235922724f, 0.0008177462150342762f, 0.000312917836708948f, 0.0004316974082030356f, 0.00034804121241904795f, 0.000525512034073472f, 0.00025401375023648143f, 0.0004839635221287608f, 0.00036430166801437736f, 0.0003260296944063157f, 0.00033470793277956545f, 0.0006196788745000958f, 0.0007860264740884304f, 0.000619817990809679f, 0.0009267132845707238f, 0.0005186842172406614f, 0.0005560328718274832f, 0.0007290340145118535f, 0.0008871401660144329f, 0.0011706886580213904f, 0.0005933725624345243f, 0.00041118706576526165f, 0.0005686332588084042f, 0.0006245642434805632f, 0.0008853455656208098f, 0.00039944055606611073f, 0.0007425789954140782f, 0.0008461587713100016f, 0.00039702982758171856f, 0.0006643221131525934f, 0.0003709891461767256f, 0.0005896080401726067f, 0.00038250329089351f, 0.00027498582494445145f, 0.0006463017198257148f, 0.0005687788361683488f, 0.0010730058420449495f, 0.0004083077365066856f, 0.0007864550570957363f, 0.00033815886126831174f, 0.0006595896556973457f, 0.0005670586251653731f, 0.00034100364428013563f, 0.00041984437848441303f, 0.0002129544736817479f, 0.0006147861131466925f, 0.0004684605519287288f, 0.0004009812546428293f, 0.0006630556890740991f, 0.0007723103044554591f, 0.0004260969872120768f, 0.0006216010078787804f, 0.0005358958733268082f, 0.0008145602187141776f, 0.0004040478088427335f, 0.000845692993607372f, 0.0006362617132253945f, 0.0005092278006486595f, 0.0006901524029672146f, 0.0008415179909206927f, 0.00017202424351125956f, 0.0006954065756872296f, 0.0009399386472068727f, 0.0006912049720995128f, 0.00017763669893611223f, 0.0005536901880986989f, 0.0004762659373227507f, 0.0005324712838046253f, 0.0004697951953858137f, 0.0004468330880627036f, 0.0010166093707084656f, 0.0013774113031104207f, 0.0009231804870069027f, 0.0016626681899651885f, 0.0003415254468563944f, 0.00046633175224997103f, 0.0008678697049617767f, 0.0006176771130412817f, 0.0008622435852885246f, 0.0007904065423645079f, 0.0006451326189562678f, 0.0008713242132216692f, 0.0008096834062598646f, 0.00032768031815066934f, 0.0005389020661823452f, 0.0004928905982524157f, 0.0006783994613215327f, 0.0005577414995059371f, 0.0007087117410264909f, 0.0007934084860607982f, 0.0009328347514383495f, 0.0006156014860607684f, 0.0008076388039626181f, 0.0005770947900600731f, 0.0006601983914151788f, 0.0006636267644353211f, 0.0010251441271975636f, 0.001333944615907967f, 0.0006443500751629472f, 0.0009780575055629015f, 0.0010893673170357943f, 0.0003902394091710448f, 0.0011614514514803886f, 0.0005817022756673396f, 0.0006872356752865016f, 0.00031610330916009843f, 0.00022019387688487768f, 0.0007621779222972691f, 0.0007890361011959612f, 0.0005075506051070988f, 0.0005554622039198875f, 0.000702009885571897f, 0.0008288648095913231f, 0.000364094041287899f, 0.0007831183029338717f, 0.00041506681009195745f, 0.0007279561250470579f, 0.0010035621235147119f, 0.0003398005501367152f, 0.0009505798807367682f, 0.00046672814642079175f, 0.0006535642896778882f, 0.0002140892029274255f, 0.0001938658533617854f, 0.0004672269569709897f, 0.0005313589354045689f, 0.0005878140218555927f, 0.00020710518583655357f, 0.0005444030975922942f, 0.0005277564632706344f, 0.00037127695395611227f, 0.00034453970147296786f, 0.0005897074588574469f, 0.0008045283029787242f, 0.0007726988405920565f, 0.0006729164742864668f, 0.0010105473920702934f, 0.0006786917219869792f, 0.0007279274286702275f, 0.0006682886742055416f, 0.0006267172866500914f, 0.0005706519004888833f, 0.0007788809598423541f, 0.0003870004729833454f, 0.000732327695004642f, 0.0002475746441632509f, 0.00022616818023379892f, 0.0006320461397990584f, 0.0008854478946886957f, 0.0009605176164768636f, 0.0006834081141278148f, 0.0009730456513352692f, 0.0008614497492089868f, 0.0009400941198691726f, 0.0005020039388909936f, 0.0006515548448078334f, 0.0006797478417865932f, 0.0006059573497623205f, 0.0009016119292937219f, 0.0007495153113268316f, 0.0009650317369960248f, 0.000770782062318176f, 0.000319272861815989f, 0.0007560904487036169f, 0.0008561615250073373f, 0.0006506512872874737f, 0.0004893888253718615f, 0.0006409225170500576f, 0.0003912388638127595f, 0.0005234246491454542f, 0.000740068790037185f, 0.00044680206337943673f, 0.0009237066260538995f, 0.0010685346787795424f, 0.0006354713696055114f, 0.0007043012301437557f, 0.0003828841436188668f, 0.0005362657830119133f, 0.0011638073483482003f, 0.00031589894206263125f, 0.0010352605022490025f, 0.000502933282405138f, 0.0011268004309386015f, 0.0005178901483304799f, 0.0010892223799601197f, 0.0007380319875665009f, 0.0007153261685743928f, 0.0008223731420002878f, 0.0007977171917445958f, 0.0004000076442025602f, 0.0009355783113278449f, 0.0002096617827191949f, 0.0006839021225459874f, 0.0007399132591672242f, 0.0013006337685510516f, 0.0007404722855426371f, 0.0005064487340860069f, 0.0013893262948840857f, 0.0007383585907518864f, 0.0004567268770188093f, 0.000772050698287785f, 0.0008396474295295775f, 0.0006351449992507696f, 0.0006610583513975143f, 0.0006753443740308285f, 0.0003363934811204672f, 0.0005086057353764772f, 0.0005152120720595121f, 0.0005649146623909473f, 0.0006772346096113324f, 0.0009133605053648353f, 0.00033556637936271727f, 0.001127826515585184f, 0.0004896172322332859f, 0.0009747723233886063f, 0.0007091846200637519f, 0.000922405335586518f, 0.0003942899638786912f, 0.0008478978998027742f, 0.0006001400761306286f, 0.0015707490965723991f, 0.0006457213894464076f, 0.0006828135228715837f, 0.0009687832207418978f, 0.0005758902989327908f, 0.00021611303964164108f, 0.0005253790877759457f, 0.0005937533569522202f, 0.0009406300960108638f, 0.0002634759293869138f, 0.00051430071471259f, 0.0006431748624891043f, 0.0006350672920234501f, 0.00047742141759954393f, 0.0004809507227037102f, 0.0006463155732490122f, 0.0005996795953251421f, 0.00029454639297910035f, 0.0006255260086618364f, 0.0007091692532412708f, 0.0005619747098535299f, 0.0006957378354854882f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #157 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017992327047977597f, 0.00014768884284421802f, 0.0001619978720555082f, 5.604380930890329e-05f, 0.00017406044935341924f, 0.0001092294478439726f, 6.983315688557923e-05f, 0.0001799205638235435f, 0.00018370193720329553f, 0.0002283487847307697f, 7.629059109603986e-05f, 0.00011324910155963153f, 0.00012138458259869367f, 5.274221257423051e-05f, 7.219112740131095e-05f, 0.00016466858505737036f, 0.00019774833344854414f, 0.0001886618119897321f, 0.00018011474458035082f, 0.00026430044090375304f, 0.00018239808559883386f, 0.0001995602942770347f, 0.0001488531124778092f, 0.00027610338293015957f, 0.0001560463133500889f, 0.0007538411300629377f, 0.00012689808499999344f, 0.0002194123953813687f, 0.00012258838978596032f, 3.904235563823022e-05f, 7.019463373580948e-05f, 0.00018962522153742611f, 0.00023032250464893878f, 6.169586413307115e-05f, 0.00010723891318775713f, 0.00011335752787999809f, 0.00025853028637357056f, 0.00021290959557518363f, 9.68277599895373e-05f, 0.00024229258997365832f, 0.00021819416724611074f, 0.00020226807100698352f, 0.00019053586584050208f, 0.00015795625222381204f, 0.00013000295439269394f, 0.00010946312249870971f, 0.00010225635196547955f, 0.0002219727321062237f, 0.00015392770001199096f, 9.749575838213786e-05f, 7.269328489201143e-05f, 0.00011086576705565676f, 0.00012573222920764238f, 0.0001119932348956354f, 0.00016919561312533915f, 0.00011830271978396922f, 5.117415639688261e-05f, 0.00014557148097082973f, 0.0001287277991650626f, 0.00017200983711518347f, 0.0001731921365717426f, 0.00011890224413946271f, 0.0001844265789259225f, 0.0001727887283777818f, 0.00022480677580460906f, 0.0001314479304710403f, 0.00010765507613541558f, 0.0001924939570017159f, 0.00019898546452168375f, 9.26719221752137e-05f, 9.402410069014877e-05f, 9.429679630557075e-05f, 0.00015510994126088917f, 0.00016228204185608774f, 0.00017670736997388303f, 0.00019125161634292454f, 0.00021668868430424482f, 0.0002574583049863577f, 7.112121966201812e-05f, 0.00017353911243844777f, 0.00017076510994229466f, 0.0002057824603980407f, 0.00025336502585560083f, 0.000207312245038338f, 0.00022657365479972214f, 0.00013607800065074116f, 0.00013974089233670384f, 0.00021289011056069285f, 0.00020713992125820369f, 0.00014664830814581364f, 0.0001533324975753203f, 0.00014602001465391368f, 0.00013855838915333152f, 0.0001652353093959391f, 0.000199570509721525f, 0.00021933855896349996f, 8.393183816224337e-05f, 0.00011579128477023914f, 9.335274808108807e-05f, 0.0001409545511705801f, 6.813239451730624e-05f, 0.00012981027248315513f, 9.771418262971565e-05f, 8.744874503463507e-05f, 8.97764548426494e-05f, 0.00016621228132862598f, 0.00021083057799842209f, 0.0001662495924392715f, 0.00024856606614775956f, 0.00013912316353525966f, 0.0001491409493610263f, 0.00019554387836251408f, 0.00023795162269379944f, 0.00031400591251440346f, 0.000159156319568865f, 0.00011028993321815506f, 0.00015252066077664495f, 0.00016752265219110996f, 0.00023747027444187552f, 0.00010713924712035805f, 0.00019917695317417383f, 0.0002269594551762566f, 0.00010649263276718557f, 0.00017818664491642267f, 9.950791718438268e-05f, 0.00015814659127499908f, 0.00010259627742925659f, 7.375759014394134e-05f, 0.00017335315351374447f, 0.00015255971811711788f, 0.00028780513093806803f, 0.00010951763397315517f, 0.00021094553812872618f, 9.070207306649536e-05f, 0.00017691728135105222f, 0.00015209830598905683f, 9.146511001745239e-05f, 0.00011261202598689124f, 5.7119341363431886e-05f, 0.00016489993140567094f, 0.00012565201905090362f, 0.00010755249968497083f, 0.0001778469595592469f, 0.0002071515773423016f, 0.00011428911966504529f, 0.00016672784113325179f, 0.0001437397295376286f, 0.00021848399774171412f, 0.0001083750175894238f, 0.00022683452698402107f, 0.00017066019063349813f, 0.00013658673560712487f, 0.00018511492817196995f, 0.00022571469889953732f, 4.614090357790701e-05f, 0.00018652422295417637f, 0.000252113415626809f, 0.0001853972498793155f, 4.764629193232395e-05f, 0.00014851258310955018f, 0.00012774560309480876f, 0.00014282118354458362f, 0.00012600999616552144f, 0.00011985102901235223f, 0.0002726782695390284f, 0.0003694537444971502f, 0.00024761847453191876f, 0.0004459662886802107f, 9.160507033811882e-05f, 0.00012508101644925773f, 0.00023278284061234444f, 0.00016567535931244493f, 0.00023127377789933234f, 0.00021200541232246906f, 0.0001730395742924884f, 0.00023370941926259547f, 0.00021717592608183622f, 8.789147977950051e-05f, 0.00014454606571234763f, 0.00013220471737440675f, 0.00018196251767221838f, 0.00014959924737922847f, 0.0001900929637486115f, 0.00021281061344780028f, 0.00025020798784680665f, 0.00016511863213963807f, 0.00021662750805262476f, 0.00015479025023523718f, 0.00017708056839182973f, 0.0001780001330189407f, 0.0002749674895312637f, 0.00035779495374299586f, 0.00017282967746723443f, 0.0002623377658892423f, 0.000292193639324978f, 0.00010467128595337272f, 0.0003115283034276217f, 0.00015602607163600624f, 0.0001843325881054625f, 8.478626114083454e-05f, 5.90611198276747e-05f, 0.00020443384710233659f, 0.0002116378309438005f, 0.00013613687769975513f, 0.0001489878777647391f, 0.00018829538021236658f, 0.00022232081391848624f, 9.765849245013669e-05f, 0.0002100505371345207f, 0.00011133056977996603f, 0.00019525476091075689f, 0.0002691787085495889f, 9.114240674534813e-05f, 0.0002549676282797009f, 0.0001251873472938314f, 0.0001753011456457898f, 5.742370194639079e-05f, 5.1999330025864765e-05f, 0.000125321137602441f, 0.0001425228256266564f, 0.00015766538854222745f, 5.5550426623085514e-05f, 0.0001460215717088431f, 0.00014155656390357763f, 9.958511509466916e-05f, 9.241356019629166e-05f, 0.00015817325038369745f, 0.0002157932030968368f, 0.00020725579815916717f, 0.00018049184291157871f, 0.00027105232584290206f, 0.0001820409088395536f, 0.00019524706294760108f, 0.00017925056454259902f, 0.0001681001449469477f, 0.00015306210843846202f, 0.00020891398889943957f, 0.0001038025293382816f, 0.00019642732513602823f, 6.640527863055468e-05f, 6.066356581868604e-05f, 0.00016952947771642357f, 0.00023749771935399622f, 0.00025763316079974174f, 0.0001833059504861012f, 0.00026099345996044576f, 0.00023106085427571088f, 0.00025215509231202304f, 0.0001346491335425526f, 0.00017476215725764632f, 0.00018232417642138898f, 0.00016253185458481312f, 0.00024183328787330538f, 0.00020103743008803576f, 0.00025884396745823324f, 0.00020674167899414897f, 8.563640585634857e-05f, 0.00020280103490222245f, 0.00022964243544265628f, 0.0001745198096614331f, 0.00013126546400599182f, 0.0001719103311188519f, 0.00010493936133570969f, 0.00014039466623216867f, 0.00019850366516038775f, 0.0001198427053168416f, 0.00024775959900580347f, 0.0002866058493964374f, 0.00017044819833245128f, 0.00018890996580012143f, 0.00010269843187415972f, 0.00014383895904757082f, 0.0003121602057944983f, 8.473144407616928e-05f, 0.0002776809560600668f, 0.00013489840785041451f, 0.0003022340824827552f, 0.0001389101817039773f, 0.00029215478571131825f, 0.00019795734260696918f, 0.00019186711870133877f, 0.000220579604501836f, 0.00021396629745140672f, 0.00010729135101428255f, 0.0002509438490960747f, 5.6236167438328266e-05f, 0.00018343846022617072f, 0.00019846194481942803f, 0.0003488602233119309f, 0.00019861188775394112f, 0.000135841328301467f, 0.0003726496361196041f, 0.00019804494513664395f, 0.00012250477448105812f, 0.00020708194642793387f, 0.00022521296341437846f, 0.00017036065401043743f, 0.00017731121624819934f, 0.0001811430702218786f, 9.02285537449643e-05f, 0.0001364198833471164f, 0.00013819185551255941f, 0.00015152324340306222f, 0.00018165007350035012f, 0.00024498451966792345f, 9.000670979730785e-05f, 0.00030250928830355406f, 0.00013132672756910324f, 0.0002614566183183342f, 0.00019021981279365718f, 0.00024741055676713586f, 0.0001057577392202802f, 0.00022742593137081712f, 0.00016097152547445148f, 0.00042131144437007606f, 0.00017319749167654663f, 0.0001831464614951983f, 0.00025985020329244435f, 0.00015446716861333698f, 5.796654295409098e-05f, 0.00014091888442635536f, 0.0001592584594618529f, 0.0002522988652344793f, 7.067037222441286e-05f, 0.0001379474124405533f, 0.00017251445387955755f, 0.0001703398156678304f, 0.00012805552978534251f, 0.00012900217552669346f, 0.0001733568642521277f, 0.0001608480088179931f, 7.900419586803764e-05f, 0.00016778062854427844f, 0.00019021568004973233f, 0.00015073468966875225f, 0.00018661306239664555f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #158 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.014718477614223957f, 0.009082102216780186f, 0.002472669119015336f, 0.008816313929855824f, 0.004974487237632275f, 0.008458024822175503f, 0.014800868928432465f, 0.008205841295421124f, 0.005582149606198072f, 0.007701155263930559f, 0.008925123140215874f, 0.005065805744379759f, 0.006714832503348589f, 0.010083473287522793f, 0.013220839202404022f, 0.008706217631697655f, 0.004484556615352631f, 0.0045581697486341f, 0.003753810888156295f, 0.0031035635620355606f, 0.004702170379459858f, 0.025410467758774757f, 0.006235421169549227f, 0.006980435457080603f, 0.00160604203119874f, 0.002300787949934602f, 0.007116961758583784f, 0.0059362612664699554f, 0.017863817512989044f, 0.01395876333117485f, 0.009099792689085007f, 0.003965344745665789f, 0.0009266858687624335f, 0.006921845953911543f, 0.006263078190386295f, 0.007548659574240446f, 0.006919499486684799f, 0.005567276384681463f, 0.006888643838465214f, 0.00949980691075325f, 0.03258439898490906f, 0.005340977571904659f, 0.014466540887951851f, 0.007514826487749815f, 0.012395515106618404f, 0.007717471569776535f, 0.011005486361682415f, 0.006248371675610542f, 0.0029935629572719336f, 0.00985568854957819f, 0.015238991007208824f, 0.007130023557692766f, 0.00668718758970499f, 0.011045744642615318f, 0.003578583709895611f, 0.008792601525783539f, 0.08542195707559586f, 0.009977876208722591f, 0.009757730178534985f, 0.003913360647857189f, 0.0017619531136006117f, 0.015163472853600979f, 0.011106480844318867f, 0.0027586331125348806f, 0.005530195776373148f, 0.009750534780323505f, 0.003744987305253744f, 0.007922946475446224f, 0.0067137377336621284f, 0.009387457743287086f, 0.00984906405210495f, 0.009427610784769058f, 0.0039631882682442665f, 0.00385085167363286f, 0.008469327352941036f, 0.009782781824469566f, 0.007629127707332373f, 0.005609817337244749f, 0.011118010617792606f, 0.01168971136212349f, 0.009542013518512249f, 0.010832519270479679f, 0.0058616832830011845f, 0.0065995934419333935f, 0.004097485914826393f, 0.004938152153044939f, 0.013836179859936237f, 0.0014167842455208302f, 0.004248652141541243f, 0.007809940259903669f, 0.004320725332945585f, 0.004822439514100552f, 0.006731411442160606f, 0.0027846223674714565f, 0.017134634777903557f, 0.006168029271066189f, 0.0022014384157955647f, 0.012774665839970112f, 0.01559942401945591f, 0.0027541345916688442f, 0.013441943563520908f, 0.003272387897595763f, 0.010140122845768929f, 0.017387419939041138f, 0.021222125738859177f, 0.004337654449045658f, 0.0073629338294267654f, 0.00576222687959671f, 0.0055817971006035805f, 0.012543301098048687f, 0.005907118786126375f, 0.00555759109556675f, 0.005095524713397026f, 0.0033089034259319305f, 0.006000942084938288f, 0.010860400274395943f, 0.00659581832587719f, 0.003804973792284727f, 0.011058371514081955f, 0.00487761152908206f, 0.010924178175628185f, 0.002453657565638423f, 0.0028449755627661943f, 0.007564530707895756f, 0.0041561434045434f, 0.007000259589403868f, 0.003630734048783779f, 0.011854262091219425f, 0.011547171510756016f, 0.011075963266193867f, 0.009819689206779003f, 0.010179780423641205f, 0.010925150476396084f, 0.03600768372416496f, 0.004414468538016081f, 0.006140343379229307f, 0.005978025961667299f, 0.007570879068225622f, 0.025835413485765457f, 0.003377709072083235f, 0.008944668807089329f, 0.015884950757026672f, 0.0063117677345871925f, 0.005009124521166086f, 0.013549067080020905f, 0.007127884775400162f, 0.013576405122876167f, 0.007494873367249966f, 0.007914000190794468f, 0.0035739897284656763f, 0.006851291283965111f, 0.01580018363893032f, 0.003839428536593914f, 0.00693245604634285f, 0.005888841114938259f, 0.00992953684180975f, 0.00796834472566843f, 0.007294708397239447f, 0.005884127225726843f, 0.011628902517259121f, 0.005351813044399023f, 0.007636208552867174f, 0.015025096014142036f, 0.011577834375202656f, 0.004860406741499901f, 0.0031391133088618517f, 0.011320501565933228f, 0.005338148679584265f, 0.009902561083436012f, 0.005631165578961372f, 0.004703179933130741f, 0.011956552974879742f, 0.0014619092689827085f, 0.005210291128605604f, 0.003948490135371685f, 0.006813710555434227f, 0.008526066318154335f, 0.004410182125866413f, 0.008000938221812248f, 0.0076928772032260895f, 0.007924874313175678f, 0.010342422872781754f, 0.010347173549234867f, 0.0037020889576524496f, 0.006705625914037228f, 0.0024887933395802975f, 0.006257233675569296f, 0.007473754230886698f, 0.004171282984316349f, 0.011132728308439255f, 0.006369979586452246f, 0.003963239956647158f, 0.0032841742504388094f, 0.004099762532860041f, 0.009887823835015297f, 0.005660173948854208f, 0.007442318834364414f, 0.006814331281930208f, 0.013061811216175556f, 0.02366066165268421f, 0.02108977735042572f, 0.00871701817959547f, 0.009088224731385708f, 0.006474550813436508f, 0.012104340828955173f, 0.0043332017958164215f, 0.002617616206407547f, 0.010451827198266983f, 0.007145488169044256f, 0.00845811702311039f, 0.0031068818643689156f, 0.003253245260566473f, 0.007260259706526995f, 0.0041855392046272755f, 0.011763746850192547f, 0.004655533470213413f, 0.012019640766084194f, 0.01827384904026985f, 0.007338033057749271f, 0.010758535005152225f, 0.00799061544239521f, 0.009576762095093727f, 0.010875837877392769f, 0.015563607215881348f, 0.008714930154383183f, 0.013692904263734818f, 0.009847617708146572f, 0.005408316385000944f, 0.005873569753021002f, 0.0026843391824513674f, 0.0022384095937013626f, 0.010036864317953587f, 0.010291745886206627f, 0.0055123320780694485f, 0.012038150802254677f, 0.003303728299215436f, 0.007120804861187935f, 0.004683328326791525f, 0.00507340719923377f, 0.011895527131855488f, 0.016329636797308922f, 0.004477228503674269f, 0.0027073691599071026f, 0.006841557566076517f, 0.007392783183604479f, 0.007375792600214481f, 0.0075581748969852924f, 0.007085955236107111f, 0.004937874618917704f, 0.00915143359452486f, 0.01336606778204441f, 0.0032950411550700665f, 0.01765071041882038f, 0.005869068671017885f, 0.004416035022586584f, 0.013426355086266994f, 0.006339547224342823f, 0.0022115313913673162f, 0.004841516725718975f, 0.00917300395667553f, 0.011685634031891823f, 0.01042600441724062f, 0.01654159463942051f, 0.0076518855057656765f, 0.007115102373063564f, 0.013687709346413612f, 0.005972899496555328f, 0.0029734198469668627f, 0.004689348395913839f, 0.006240758579224348f, 0.009030172601342201f, 0.005822116043418646f, 0.0028150652069598436f, 0.03330216556787491f, 0.007961862720549107f, 0.005070510786026716f, 0.0086961779743433f, 0.011578986421227455f, 0.011004673317074776f, 0.002752395113930106f, 0.006228860467672348f, 0.007720948662608862f, 0.003603504505008459f, 0.005412035621702671f, 0.005617580376565456f, 0.014877778477966785f, 0.008081541396677494f, 0.006470074877142906f, 0.005347739905118942f, 0.004305453039705753f, 0.0019960799254477024f, 0.004295009188354015f, 0.009955668821930885f, 0.011438257060945034f, 0.0031635407358407974f, 0.005286716390401125f, 0.00738140381872654f, 0.010920730419456959f, 0.013186117634177208f, 0.0031218735966831446f, 0.003959335386753082f, 0.016492338851094246f, 0.011247645132243633f, 0.007810256443917751f, 0.0057683405466377735f, 0.010242798365652561f, 0.00446974067017436f, 0.007298790384083986f, 0.005150840617716312f, 0.0056829918175935745f, 0.006353443954139948f, 0.005300342570990324f, 0.006973684765398502f, 0.006565513554960489f, 0.0058860452845692635f, 0.013982994481921196f, 0.0022789135109633207f, 0.005987567827105522f, 0.006898736115545034f, 0.007355178706347942f, 0.009578824043273926f, 0.012094911187887192f, 0.005402708891779184f, 0.017886625602841377f, 0.003968427423387766f, 0.0048444876447319984f, 0.004832132253795862f, 0.0113536287099123f, 0.007649353705346584f, 0.003162445966154337f, 0.006576844956725836f, 0.008815719746053219f, 0.010933471843600273f, 0.0061096916906535625f, 0.0046532335691154f, 0.013532407581806183f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #159 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003463171306066215f, 0.00021369653404690325f, 5.818045246996917e-05f, 0.00020744268840644509f, 0.00011704675853252411f, 0.00019901235646102577f, 0.00034825573675334454f, 0.00019307862385176122f, 0.00013134469918441027f, 0.00018120364984497428f, 0.00021000290871597826f, 0.00011919542885152623f, 0.00015799606626387686f, 0.0002372581948293373f, 0.0003110785619355738f, 0.00020485218556132168f, 0.00010551897867117077f, 0.0001072510567610152f, 8.832496678223833e-05f, 7.302502490347251e-05f, 0.0001106393028749153f, 0.0005978933768346906f, 0.0001467157999286428f, 0.0001642455463297665f, 3.778922473429702e-05f, 5.413618782768026e-05f, 0.00016745792527217418f, 0.00013967673294246197f, 0.00042032511555589736f, 0.00032844149973243475f, 0.00021411277703009546f, 9.330223110737279e-05f, 2.180437331844587e-05f, 0.00016286697064060718f, 0.00014736654702574015f, 0.00017761552589945495f, 0.00016281176067423075f, 0.00013099474017508328f, 0.00016208573651965708f, 0.00022352486848831177f, 0.0007666917517781258f, 0.0001256700634257868f, 0.00034038920421153307f, 0.00017681944882497191f, 0.00029165917658247054f, 0.00018158757302444428f, 0.0002589526120573282f, 0.0001470205170335248f, 7.04367776052095e-05f, 0.00023189856437966228f, 0.00035856448812410235f, 0.0001677652617217973f, 0.00015734559565316886f, 0.000259899883531034f, 8.420197264058515e-05f, 0.00020688473887275904f, 0.002009928459301591f, 0.00023477355716750026f, 0.0002295936574228108f, 9.207907714881003e-05f, 4.145772254560143e-05f, 0.0003567876119632274f, 0.000261328968917951f, 6.490901432698593e-05f, 0.0001301222509937361f, 0.00022942434588912874f, 8.811734733171761e-05f, 0.00018642227223608643f, 0.00015797030937392265f, 0.00022088136756792665f, 0.000231742684263736f, 0.00022182613611221313f, 9.325148857897148e-05f, 9.060827869689092e-05f, 0.00019927829271182418f, 0.00023018311185296625f, 0.000179508890141733f, 0.00013199570821598172f, 0.0002616002457216382f, 0.0002750520361587405f, 0.00022451796394307166f, 0.00025488281971774995f, 0.0001379219611408189f, 0.00015528454969171435f, 9.641143697081134e-05f, 0.00011619181896094233f, 0.0003255571937188506f, 3.3336102205794305e-05f, 9.99682888505049e-05f, 0.00018376330262981355f, 0.00010166412539547309f, 0.00011346917017363012f, 0.00015838615945540369f, 6.552052946062759e-05f, 0.0004031678836327046f, 0.00014513010683003813f, 5.179855361348018e-05f, 0.0003005803737323731f, 0.00036704528611153364f, 6.48031709715724e-05f, 0.00031628101714886725f, 7.699736306676641e-05f, 0.00023859113571234047f, 0.00040911577525548637f, 0.0004993441398255527f, 0.00010206246224697679f, 0.00017324549844488502f, 0.0001355818094452843f, 0.0001313364045927301f, 0.0002951365022454411f, 0.0001389910321449861f, 0.00013076685718260705f, 0.00011989469930995256f, 7.785655179759488e-05f, 0.00014119864499662071f, 0.0002555388491600752f, 0.0001551957248011604f, 8.952879579737782e-05f, 0.00026019697543233633f, 0.0001147673319792375f, 0.0002570395008660853f, 5.773311931989156e-05f, 6.694059993606061e-05f, 0.0001779889571480453f, 9.779161337064579e-05f, 0.00016471199342049658f, 8.542904106434435e-05f, 0.0002789238060358912f, 0.00027169816894456744f, 0.00026061091921292245f, 0.00023105151194613427f, 0.00023952424817252904f, 0.0002570623764768243f, 0.0008472396293655038f, 0.00010386984649812803f, 0.00014447867579292506f, 0.0001406594383297488f, 0.0001781383325578645f, 0.0006078921142034233f, 7.94755105744116e-05f, 0.00021046279289294034f, 0.00037376355612650514f, 0.000148512190207839f, 0.00011786175309680402f, 0.00031880158348940313f, 0.0001677149411989376f, 0.00031944483635015786f, 0.00017634996038395911f, 0.0001862117787823081f, 8.409388101426885e-05f, 0.00016120685904752463f, 0.0003717690415214747f, 9.033949754666537e-05f, 0.00016311662329826504f, 0.00013856096484232694f, 0.00023363616492133588f, 0.00018749047012533993f, 0.00017164020391646773f, 0.00013845005014445633f, 0.0002736212336458266f, 0.00012592501298058778f, 0.00017967549501918256f, 0.0003535316791385412f, 0.0002724196237977594f, 0.00011436251224949956f, 7.386149081867188e-05f, 0.0002663647464942187f, 0.00012560350296553224f, 0.00023300143948290497f, 0.0001324980112258345f, 0.00011066305887652561f, 0.0002813306637108326f, 3.4397864510538056e-05f, 0.00012259508366696537f, 9.290565503761172e-05f, 0.0001603225973667577f, 0.00020061332907062024f, 0.00010376899444963783f, 0.0001882573706097901f, 0.0001810088724596426f, 0.00018646763055585325f, 0.00024335112539120018f, 0.0002434629132039845f, 8.710797555977479e-05f, 0.00015777943190187216f, 5.8559842727845535e-05f, 0.00014722903142683208f, 0.00017585304158274084f, 9.81478369794786e-05f, 0.0002619465522002429f, 0.00014988187467679381f, 9.325270366389304e-05f, 7.727468619123101e-05f, 9.646500257076696e-05f, 0.00023265468189492822f, 0.00013318056880962104f, 0.00017511338228359818f, 0.00016033720748964697f, 0.0003073367406614125f, 0.0005567214684560895f, 0.0004962300881743431f, 0.00020510632020886987f, 0.00021384058345574886f, 0.000152342370711267f, 0.0002848080184776336f, 0.00010195768845733255f, 6.159097392810509e-05f, 0.0002459253591950983f, 0.0001681291323620826f, 0.0001990145246963948f, 7.310310320463032e-05f, 7.6546952186618e-05f, 0.00017082964768633246f, 9.84832804533653e-05f, 0.0002767940459307283f, 0.000109541964775417f, 0.00028281507547944784f, 0.00042997291893698275f, 0.0001726596092339605f, 0.0002531420032028109f, 0.00018801448459271342f, 0.00022533557785209268f, 0.0002559020649641752f, 0.000366202526492998f, 0.00020505717839114368f, 0.0003221859806217253f, 0.0002317086618859321f, 0.00012725450505968183f, 0.0001382016489515081f, 6.316092185443267e-05f, 5.2668463467853144e-05f, 0.0002361615188419819f, 0.00024215872690547258f, 0.00012970193347427994f, 0.00028325061430223286f, 7.773478864692152e-05f, 0.00016754835087340325f, 0.00011019596422556788f, 0.00011937428644159809f, 0.0002798947680275887f, 0.00038422676152549684f, 0.00010534655302762985f, 6.37028060737066e-05f, 0.00016097782645374537f, 0.00017394784663338214f, 0.00017354806186631322f, 0.00017783940711524338f, 0.0001667283650022f, 0.00011618528515100479f, 0.00021532784739974886f, 0.0003144957299809903f, 7.753038516966626e-05f, 0.00041531084571033716f, 0.00013809574011247605f, 0.00010390670649940148f, 0.0003159142506774515f, 0.00014916581858415157f, 5.203603359404951e-05f, 0.00011391804582672194f, 0.00021583538909908384f, 0.0002749561099335551f, 0.00024531775852665305f, 0.00038921399391256273f, 0.00018004437151830643f, 0.0001674141822149977f, 0.00032206374453380704f, 0.00014053881750442088f, 6.996282172622159e-05f, 0.0001103376125684008f, 0.00014684138295706362f, 0.00021247465338092297f, 0.00013699097326025367f, 6.623683293582872e-05f, 0.0007835803553462029f, 0.0001873379515018314f, 0.00011930613982258365f, 0.00020461594976950437f, 0.0002724467485677451f, 0.00025893349084071815f, 6.4762236434035e-05f, 0.00014656141865998507f, 0.00018166938389185816f, 8.47883420647122e-05f, 0.00012734202027786523f, 0.00013217836385592818f, 0.0003500653838273138f, 0.00019015392172150314f, 0.0001522370585007593f, 0.00012582917406689376f, 0.0001013047804008238f, 4.696658652392216e-05f, 0.00010105904220836237f, 0.0002342510415473953f, 0.0002691354602575302f, 7.44362550904043e-05f, 0.00012439332203939557f, 0.0001736800913931802f, 0.0002569583593867719f, 0.00031026158831082284f, 7.345584890572354e-05f, 9.316083742305636e-05f, 0.00038805505027994514f, 0.0002646504726726562f, 0.00018377073865849525f, 0.00013572566967923194f, 0.0002410070301266387f, 0.00010517037298996001f, 0.00017173624655697495f, 0.00012119625171180815f, 0.00013371746172197163f, 0.00014949280011933297f, 0.00012471394438762218f, 0.00016408669762313366f, 0.00015448268095497042f, 0.00013849519018549472f, 0.00032901164377108216f, 5.362149386201054e-05f, 0.00014088394527789205f, 0.0001623232092242688f, 0.00017306303197983652f, 0.00022538409393746406f, 0.0002845861599780619f, 0.00012712256284430623f, 0.0004208617901895195f, 9.337476512882859e-05f, 0.0001139879459515214f, 0.0001136972350650467f, 0.00026714420528151095f, 0.0001799847959773615f, 7.441049820045009e-05f, 0.00015474930114578456f, 0.00020742870401591063f, 0.00025725815794430673f, 0.00014375745377037674f, 0.00010948785347864032f, 0.0003184095839969814f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #160 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.023592209443449974f, 0.010109439492225647f, 0.008095826953649521f, 0.015822093933820724f, 0.011558431200683117f, 0.013620799407362938f, 0.01276425365358591f, 0.019612031057476997f, 0.007698344998061657f, 0.024302847683429718f, 0.008594636805355549f, 0.00785648263990879f, 0.011932176537811756f, 0.011035526171326637f, 0.006748788990080357f, 0.008822321891784668f, 0.01199327502399683f, 0.007464707363396883f, 0.012975221499800682f, 0.007193101570010185f, 0.007251453120261431f, 0.005887445528060198f, 0.02450515702366829f, 0.01640463061630726f, 0.016258826479315758f, 0.010155786760151386f, 0.00788020621985197f, 0.00816960446536541f, 0.00866277888417244f, 0.005487822461873293f, 0.00576770631596446f, 0.008611893281340599f, 0.009729334153234959f, 0.008370382711291313f, 0.008275431580841541f, 0.010084912180900574f, 0.01326436921954155f, 0.00823181215673685f, 0.013480076566338539f, 0.009735566563904285f, 0.006671794690191746f, 0.008727781474590302f, 0.005875228438526392f, 0.0065468307584524155f, 0.0077423108741641045f, 0.00839571375399828f, 0.022769374772906303f, 0.009943380951881409f, 0.004976531956344843f, 0.008086168207228184f, 0.007532829884439707f, 0.008168719708919525f, 0.006543779745697975f, 0.009424489922821522f, 0.007167961448431015f, 0.00986019428819418f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #161 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005551108042709529f, 0.0002378691715421155f, 0.00019049005641136318f, 0.00037228455767035484f, 0.0002719631011132151f, 0.0003204894019290805f, 0.00030033537768758833f, 0.0004614595673047006f, 0.00018113752594217658f, 0.0005718317115679383f, 0.00020222675811965019f, 0.00018485842156223953f, 0.00028075711452402174f, 0.0002596594567876309f, 0.00015879503916949034f, 0.00020758404571097344f, 0.0002821946982294321f, 0.0001756401761667803f, 0.00030529932701028883f, 0.0001692494552116841f, 0.00017062242841348052f, 0.00013852813572157174f, 0.0005765919340774417f, 0.0003859913267660886f, 0.00038256062543950975f, 0.00023895969206932932f, 0.00018541661847848445f, 0.00019222599803470075f, 0.00020383008813951164f, 0.00012912524107377976f, 0.00013571073941420764f, 0.00020263278565835208f, 0.00022892552078701556f, 0.00019695019000209868f, 0.00019471603445708752f, 0.0002372920571360737f, 0.00031210281304083765f, 0.00019368970242794603f, 0.00031717828824184835f, 0.0002290721604367718f, 0.00015698341303505003f, 0.00020535956718958914f, 0.00013824067718815058f, 0.00015404308214783669f, 0.00018217202159576118f, 0.00019754620734602213f, 0.0005357500049285591f, 0.00023396190954372287f, 0.0001170948744402267f, 0.00019026278459932655f, 0.00017724305507726967f, 0.00019220517424400896f, 0.00015397129755001515f, 0.0002217527071479708f, 0.000168657919857651f, 0.00023200457508210093f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #162 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00039940979331731796f, 0.0006611027056351304f, 0.0004764907353091985f, 0.00033085799077525735f, 0.0007929305429570377f, 0.00042777491034939885f, 0.0005055459914728999f, 0.0006114671705290675f, 0.0006771525950171053f, 0.0009984300704672933f, 0.0006070322706364095f, 0.0006926233763806522f, 0.0007299231947399676f, 0.0005114984815008938f, 0.000842756184283644f, 0.00041535269701853395f, 0.0008559470879845321f, 0.0005664518685080111f, 0.00044131011236459017f, 0.0010155632626265287f, 0.0006541697075590491f, 0.0005768135888502002f, 0.0006358964019455016f, 0.0006357123493216932f, 0.0011558991391211748f, 0.000503589806612581f, 0.0004946334520354867f, 0.0005733949947170913f, 0.0008742862264625728f, 0.0006505196215584874f, 0.0005167975905351341f, 0.0010235400404781103f, 0.0005383480456657708f, 0.0005435391794890165f, 0.001153938821516931f, 0.0004812346596736461f, 0.0006011732039041817f, 0.0007816802244633436f, 0.00046326156007125974f, 0.0006442387239076197f, 0.0004862076020799577f, 0.000720328651368618f, 0.0007366158533841372f, 0.0005834270268678665f, 0.001004108926281333f, 0.0005414259503595531f, 0.0005567133193835616f, 0.0008341362699866295f, 0.0008129109628498554f, 0.00042829549056477845f, 0.0007007970125414431f, 0.0007454566657543182f, 0.0007811464602127671f, 0.0004061217186972499f, 0.0007217207457870245f, 0.0003738646919373423f, 0.0008930782787501812f, 0.0006528677185997367f, 0.000516061089001596f, 0.0004596262297127396f, 0.0005893009365536273f, 0.0003066628996748477f, 0.0006841473514214158f, 0.00046155121526680887f, 0.0006121969781816006f, 0.0004061245999764651f, 0.001037105917930603f, 0.0006970475660637021f, 0.0005129497149027884f, 0.0007852102280594409f, 0.000940713391173631f, 0.0007714754319749773f, 0.0004946092958562076f, 0.0005093401996418834f, 0.0008017554064281285f, 0.0008465369464829564f, 0.0005158531712368131f, 0.0006971218390390277f, 0.0013133295578882098f, 0.0005393396131694317f, 0.0008179041906259954f, 0.0005182356690056622f, 0.0012277808273211122f, 0.0008274132269434631f, 0.0005434965714812279f, 0.0006868866039440036f, 0.0006535492721013725f, 0.0005177013808861375f, 0.0008470178581774235f, 0.000741336087230593f, 0.0005815302720293403f, 0.0005110272322781384f, 0.00037367892218753695f, 0.0008095133816823363f, 0.0006308223819360137f, 0.00046945986105129123f, 0.0004680048441514373f, 0.0003705971175804734f, 0.0006428666529245675f, 0.0005441480898298323f, 0.0004664210428018123f, 0.0007861865451559424f, 0.0006102357292547822f, 0.0006841978174634278f, 0.00047944128164090216f, 0.0007224256405606866f, 0.0005393766332417727f, 0.00047645607264712453f, 0.00035185087472200394f, 0.0007179263629950583f, 0.0003422127047087997f, 0.0004668994224630296f, 0.0006431873771362007f, 0.0005894382484257221f, 0.0011043214472010732f, 0.001168195391073823f, 0.0005067346501164138f, 0.0007322077872231603f, 0.0007189096650108695f, 0.0005817039054818451f, 0.0006685621337965131f, 0.0005156440893188119f, 0.0008878069347701967f, 0.0005527908797375858f, 0.0007256412645801902f, 0.00038215311360545456f, 0.0005807136767543852f, 0.0009478245046921074f, 0.0005144015303812921f, 0.00037556307506747544f, 0.0004924767999909818f, 0.0006111429538577795f, 0.0005126938340254128f, 0.0006800494738854468f, 0.0007598716183565557f, 0.000667050713673234f, 0.0007893057190813124f, 0.0007080926443450153f, 0.0006742217228747904f, 0.0005479539977386594f, 0.0005783774540759623f, 0.0004799652670044452f, 0.0004124389961361885f, 0.0004030653217341751f, 0.0007451652782037854f, 0.0007880018092691898f, 0.0008554061059840024f, 0.0008616741397418082f, 0.0008199014700949192f, 0.0005891857435926795f, 0.0005078676040284336f, 0.0006951054092496634f, 0.0005192432436160743f, 0.00048614369006827474f, 0.0006444827886298299f, 0.0006327645387500525f, 0.0005238489247858524f, 0.000920963182579726f, 0.0007547350251115859f, 0.0005761759821325541f, 0.0007133631152100861f, 0.0011077208910137415f, 0.0006401363643817604f, 0.0006837767432443798f, 0.0007179015665315092f, 0.0005468838498927653f, 0.00039250103873200715f, 0.0005400943919084966f, 0.000866605609189719f, 0.000769752194173634f, 0.00042305976967327297f, 0.0008554282248951495f, 0.000674543553031981f, 0.0008753542206250131f, 0.00043526742956601083f, 0.0009908572537824512f, 0.0005690990947186947f, 0.0005738392937928438f, 0.0005732143181376159f, 0.0005230185925029218f, 0.0007759525906294584f, 0.000556440616492182f, 0.00043905890197493136f, 0.0007748377975076437f, 0.000571863551158458f, 0.0006686478736810386f, 0.0005214766133576632f, 0.00040529589750804007f, 0.0003545137878973037f, 0.0006283899419941008f, 0.0006594135193154216f, 0.0008548508048988879f, 0.0005161958979442716f, 0.0008026304421946406f, 0.00045075954403728247f, 0.0006987183587625623f, 0.0005561483558267355f, 0.0007061242358759046f, 0.0006432848749682307f, 0.0006116701406426728f, 0.0005105652962811291f, 0.0005750843556597829f, 0.0004880722553934902f, 0.0007853444549255073f, 0.000560413405764848f, 0.0010704403975978494f, 0.0005822962266393006f, 0.0005658596637658775f, 0.0005843601538799703f, 0.0006429743953049183f, 0.0006038781139068305f, 0.0006599694024771452f, 0.0008058780804276466f, 0.0005507167661562562f, 0.0004443212819751352f, 0.000765708857215941f, 0.0006278017535805702f, 0.0008104379521682858f, 0.0004980447120033205f, 0.0006011917721480131f, 0.0007276834221556783f, 0.00047733038081787527f, 0.0011585280299186707f, 0.0008289238321594894f, 0.0005003918777219951f, 0.0005103726289235055f, 0.0004902434884570539f, 0.0005644307821057737f, 0.0007313365349546075f, 0.0008518669055774808f, 0.0008042543195188046f, 0.0012126071378588676f, 0.0005927723250351846f, 0.00041083546238951385f, 0.0006538104498758912f, 0.0006414411473087966f, 0.0007468491094186902f, 0.0006433218950405717f, 0.0009743248810991645f, 0.0007744072936475277f, 0.00039675054722465575f, 0.0006056019337847829f, 0.0006187012768350542f, 0.0009951366810128093f, 0.0006407459150068462f, 0.0006781641859561205f, 0.0009081621537916362f, 0.0005362095544114709f, 0.0010273167863488197f, 0.000571907963603735f, 0.0005836832569912076f, 0.0005213830736465752f, 0.0008115408127196133f, 0.0005056250956840813f, 0.0005270897527225316f, 0.0006073336699046195f, 0.0006663335370831192f, 0.0005729395197704434f, 0.000624396197963506f, 0.000736454501748085f, 0.00045227023656480014f, 0.000660228542983532f, 0.0009424940799362957f, 0.0005313212750479579f, 0.0007543871179223061f, 0.00045442834380082786f, 0.00048276918823830783f, 0.0006479041185230017f, 0.0002742632641457021f, 0.0006996134179644287f, 0.000770149752497673f, 0.0008027612348087132f, 0.000614650547504425f, 0.0004989983863197267f, 0.00044814663124270737f, 0.00072383665246889f, 0.0004930749419145286f, 0.0005069029866717756f, 0.0010062403744086623f, 0.0006626179092563689f, 0.0006407345063053071f, 0.00044242857256904244f, 0.0005963517469353974f, 0.000582907407078892f, 0.0010355524718761444f, 0.0006130817928351462f, 0.0007406451040878892f, 0.0006983527564443648f, 0.0005390274454839528f, 0.0008819241775199771f, 0.0008657189318910241f, 0.0005961634451523423f, 0.0005347043043002486f, 0.00036906354944221675f, 0.00046792885405011475f, 0.0005526799941435456f, 0.0008917755330912769f, 0.0007417469169013202f, 0.000575430691242218f, 0.0004324035544414073f, 0.0008253883570432663f, 0.00040611057193018496f, 0.0006390728522092104f, 0.00039196404395624995f, 0.000720697978977114f, 0.0003718544903676957f, 0.0005637434078380466f, 0.0006123040220700204f, 0.0007553187315352261f, 0.0007047503022477031f, 0.0007193372584879398f, 0.0005903988494537771f, 0.000639332109130919f, 0.000454506283858791f, 0.0008057543891482055f, 0.0006229676073417068f, 0.000568680465221405f, 0.0009126109653152525f, 0.00042989032226614654f, 0.0004944812972098589f, 0.0005564677994698286f, 0.0006691523594781756f, 0.0005904258578084409f, 0.00038738505099900067f, 0.0008067555609159172f, 0.0009694985928945243f, 0.0004612176853697747f, 0.0007347070495598018f, 0.0005753912846557796f, 0.0005857999203726649f, 0.0009894442046061158f, 0.0005025968421250582f, 0.0006062593893148005f, 0.0011563447769731283f, 0.00043265611748211086f, 0.0005008834996260703f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #163 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001519481447758153f, 0.0002515044470783323f, 0.0001812721893656999f, 0.00012586887169163674f, 0.00030165593489073217f, 0.0001627391466172412f, 0.00019232572230976075f, 0.00023262150352820754f, 0.0002576103142928332f, 0.0003798344696406275f, 0.00023093432537280023f, 0.0002634958946146071f, 0.0002776859328150749f, 0.00019459024770185351f, 0.00032061117235571146f, 0.00015801333938725293f, 0.0003256294294260442f, 0.00021549625671468675f, 0.00016788835637271404f, 0.0003863524761982262f, 0.0002488669124431908f, 0.00021943818137515336f, 0.00024191515694838017f, 0.00024184513313230127f, 0.0004397406883072108f, 0.00019158153736498207f, 0.00018817425007000566f, 0.00021813763305544853f, 0.00033260619966313243f, 0.0002474782813806087f, 0.00019660619727801532f, 0.0003893871034961194f, 0.00020480467355810106f, 0.00020677954307757318f, 0.00043899493175558746f, 0.00018307693244423717f, 0.00022870535030961037f, 0.00029737595468759537f, 0.00017623939493205398f, 0.0002450888277962804f, 0.00018496878328733146f, 0.00027403587591834366f, 0.00028023202321492136f, 0.00022195414931047708f, 0.0003819948760792613f, 0.00020597560796886683f, 0.00021179139730520546f, 0.000317331898258999f, 0.00030925709870643914f, 0.00016293718363158405f, 0.00026660540606826544f, 0.00028359534917399287f, 0.00029717289726249874f, 0.00015450158389285207f, 0.0002745654492173344f, 0.00014222998288460076f, 0.00033975529368035495f, 0.00024837159435264766f, 0.0001963260001502931f, 0.00017485639546066523f, 0.00022418877051677555f, 0.00011666429054457694f, 0.0002602713357191533f, 0.0001755887205945328f, 0.00023289913951884955f, 0.0001545026752864942f, 0.00039454796933569014f, 0.00026517899823375046f, 0.00019514233281370252f, 0.00029871886363253f, 0.0003578772011678666f, 0.0002934937074314803f, 0.00018816506781149656f, 0.00019376917043700814f, 0.00030501317814923823f, 0.0003220495127607137f, 0.00019624691049102694f, 0.00026520725805312395f, 0.0004996322095394135f, 0.00020518188830465078f, 0.00031115670572035015f, 0.00019715327653102577f, 0.0004670867638196796f, 0.0003147742245346308f, 0.00020676333224400878f, 0.00026131345657631755f, 0.0002486308803781867f, 0.00019695001537911594f, 0.0003222324594389647f, 0.0002820277586579323f, 0.00022123256349004805f, 0.00019441096810624003f, 0.0001421593187842518f, 0.00030796456849202514f, 0.0002399848453933373f, 0.000178597416379489f, 0.00017804389062803239f, 0.00014098690007813275f, 0.00024456685059703887f, 0.00020701119501609355f, 0.00017744135402608663f, 0.0002990902867168188f, 0.0002321530191693455f, 0.00026029054424725473f, 0.0001823946658987552f, 0.00027483361191116273f, 0.00020519597455859184f, 0.000181259005330503f, 0.00013385522470343858f, 0.0002731219574343413f, 0.00013018856407143176f, 0.00017762334027793258f, 0.00024468888295814395f, 0.00022424099734053016f, 0.00042011888581328094f, 0.00044441857608035207f, 0.00019277792307548225f, 0.00027855506050400436f, 0.0002734960289672017f, 0.0002212986146332696f, 0.0002543422451708466f, 0.00019616736972238868f, 0.0003377499233465642f, 0.00021029918571002781f, 0.0002760569623205811f, 0.00014538316463585943f, 0.00022092189465183765f, 0.00036058248952031136f, 0.0001956946507561952f, 0.00014287610247265548f, 0.0001873537985375151f, 0.0002324981614947319f, 0.00019504499505273998f, 0.00025871238904073834f, 0.0002890792675316334f, 0.0002537672407925129f, 0.0003002769371960312f, 0.00026938089285977185f, 0.0002564953174442053f, 0.0002084590814774856f, 0.0002200331218773499f, 0.0001825940125854686f, 0.00015690487634856254f, 0.00015333882765844464f, 0.0002834844926837832f, 0.00029978089150972664f, 0.0003254236071370542f, 0.00032780817127786577f, 0.0003119165194220841f, 0.0002241449401481077f, 0.00019320893625263125f, 0.00026444013928994536f, 0.0001975366030819714f, 0.0001849444815889001f, 0.0002451816981192678f, 0.00024072368978522718f, 0.00019928874098695815f, 0.00035036361077800393f, 0.0002871251490432769f, 0.00021919561550021172f, 0.0002713859430514276f, 0.00042141214362345636f, 0.00024352817854378372f, 0.00026013035676442087f, 0.00027311252779327333f, 0.00020805196254514158f, 0.0001493198360549286f, 0.00020546904124785215f, 0.00032968426239676774f, 0.00029283814365044236f, 0.00016094534657895565f, 0.0003254320181440562f, 0.00025661775725893676f, 0.0003330125182401389f, 0.00016558953211642802f, 0.0003769535105675459f, 0.0002165033365599811f, 0.00021830666810274124f, 0.00021806890435982496f, 0.000198972862563096f, 0.00029519698000513017f, 0.00021168765670154244f, 0.00016703193250577897f, 0.00029477287898771465f, 0.00021755503257736564f, 0.0002543748414609581f, 0.00019838624575641006f, 0.00015418740804307163f, 0.0001348682853858918f, 0.000239059460000135f, 0.00025086180539801717f, 0.0003252123424317688f, 0.0001963772956514731f, 0.00030534606776200235f, 0.0001714832178549841f, 0.0002658146258909255f, 0.00021157646551728249f, 0.0002686320513021201f, 0.00024472596123814583f, 0.00023269871599040926f, 0.00019423522462602705f, 0.00021878033294342458f, 0.0001856781600508839f, 0.00029876994085498154f, 0.00021319903316907585f, 0.0004072294686920941f, 0.00022152395104058087f, 0.00021527096396312118f, 0.00022230912873055786f, 0.0002446078578941524f, 0.00022973438899498433f, 0.00025107330293394625f, 0.0003065815835725516f, 0.00020951012265868485f, 0.00016903391224332154f, 0.0002912999188993126f, 0.0002388356951996684f, 0.00030831628828309476f, 0.00018947200442198664f, 0.00022871240798849612f, 0.00027683385997079313f, 0.00018159161845687777f, 0.000440740812337026f, 0.00031534890877082944f, 0.00019036493904422969f, 0.00019416192662902176f, 0.00018650417041499168f, 0.0002147273626178503f, 0.0002782235969789326f, 0.00032407717662863433f, 0.00030596385477110744f, 0.0004613142227753997f, 0.0002255093859275803f, 0.00015629483095835894f, 0.000248730240855366f, 0.00024402455892413855f, 0.00028412509709596634f, 0.0002447400474920869f, 0.00037066408549435437f, 0.00029460908262990415f, 0.00015093649562913924f, 0.0002303901856066659f, 0.00023537359084002674f, 0.0003785815497394651f, 0.00024376006331294775f, 0.0002579951542429626f, 0.00034549369593150914f, 0.00020399111963342875f, 0.00039082387229427695f, 0.00021757192735094577f, 0.00022205161803867668f, 0.00019835065177176148f, 0.00030873584910295904f, 0.000192355815670453f, 0.00020052165200468153f, 0.00023104899446479976f, 0.00025349442148581147f, 0.00021796436340082437f, 0.00023754010908305645f, 0.0002801706432364881f, 0.00017205794574692845f, 0.0002511718776077032f, 0.0003585546219255775f, 0.0002021314576268196f, 0.0002869927848223597f, 0.00017287895025219768f, 0.00018366071162745357f, 0.00024648327962495387f, 0.00010433843999635428f, 0.0002661551407072693f, 0.000292989396257326f, 0.00030539583531208336f, 0.00023383255756925792f, 0.00018983481277246028f, 0.0001704891910776496f, 0.00027537040296010673f, 0.00018758134683594108f, 0.0001928419660544023f, 0.00038280573789961636f, 0.00025208087754435837f, 0.0002437557268422097f, 0.0001683138543739915f, 0.00022687111049890518f, 0.00022175646154209971f, 0.0003939569869544357f, 0.00023323575442191213f, 0.00028176489286124706f, 0.0002656755386851728f, 0.00020506313012447208f, 0.0003355119260959327f, 0.0003293469490017742f, 0.00022679948597215116f, 0.00020341847266536206f, 0.00014040348469279706f, 0.00017801497597247362f, 0.00021025699970778078f, 0.00033925968455150723f, 0.00028218404622748494f, 0.00021891208598390222f, 0.0001645000302232802f, 0.00031400390435010195f, 0.00015449733473360538f, 0.0002431235770927742f, 0.0001491155562689528f, 0.0002741763601079583f, 0.0001414652360836044f, 0.00021446586470119655f, 0.00023293987032957375f, 0.0002873472112696618f, 0.0002681093756109476f, 0.0002736586902756244f, 0.00022460643958766013f, 0.00024322220997419208f, 0.0001729086070554331f, 0.00030653452267870307f, 0.00023699663870502263f, 0.00021634408039972186f, 0.0003471861418802291f, 0.00016354391118511558f, 0.0001881163625512272f, 0.0002116980031132698f, 0.0002545667812228203f, 0.00022461671323981136f, 0.00014737356104888022f, 0.00030691540450789034f, 0.0003688280121423304f, 0.00017546182789374143f, 0.0002795058535411954f, 0.000218897097511217f, 0.0002228568628197536f, 0.00037641596281901f, 0.0001912037841975689f, 0.00023064030392561108f, 0.0004399102181196213f, 0.00016459610196761787f, 0.00019055196025874466f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #164 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.01368484366685152f, 0.006010957062244415f, 0.005464513786137104f, 0.006217706948518753f, 0.010547678917646408f, 0.006851105019450188f, 0.007838449440896511f, 0.00740690715610981f, 0.007312052883207798f, 0.004927963018417358f, 0.0075355274602770805f, 0.005440115462988615f, 0.0048447055742144585f, 0.006149726919829845f, 0.0036667792592197657f, 0.0067718299105763435f, 0.007981909438967705f, 0.0031737221870571375f, 0.010963380336761475f, 0.006021946668624878f, 0.0066654011607170105f, 0.005818886682391167f, 0.0032863363157957792f, 0.007805660832673311f, 0.0036885153967887163f, 0.007788435090333223f, 0.003509982256218791f, 0.004301860928535461f, 0.004746260121464729f, 0.005226326175034046f, 0.00513311056420207f, 0.005686627700924873f, 0.009045083075761795f, 0.00500819506123662f, 0.0033845058642327785f, 0.008466476574540138f, 0.005643410142511129f, 0.0033787384163588285f, 0.004303267225623131f, 0.008661012165248394f, 0.005175107624381781f, 0.0049612391740083694f, 0.004277584608644247f, 0.008428046479821205f, 0.011155164800584316f, 0.0077005429193377495f, 0.006741959135979414f, 0.004912917502224445f, 0.004002545028924942f, 0.006097751669585705f, 0.003587996121495962f, 0.004941544961184263f, 0.0054037910886108875f, 0.005831269081681967f, 0.004889924544841051f, 0.00612069433555007f, 0.005111955106258392f, 0.003429424948990345f, 0.004069767892360687f, 0.004396277014166117f, 0.006151131819933653f, 0.005915326997637749f, 0.004415792878717184f, 0.007545824162662029f, 0.005804162006825209f, 0.01037528645247221f, 0.004985104314982891f, 0.0036846238654106855f, 0.006212695501744747f, 0.00757027929648757f, 0.005846135783940554f, 0.004548165015876293f, 0.004689556080847979f, 0.009527074173092842f, 0.005763574969023466f, 0.0028726193122565746f, 0.0066434470936656f, 0.0033384989947080612f, 0.0025462645571678877f, 0.003300923854112625f, 0.004340563900768757f, 0.004779458977282047f, 0.004186959471553564f, 0.004307246301323175f, 0.004202832467854023f, 0.005025481805205345f, 0.00709757674485445f, 0.004843973089009523f, 0.004501823801547289f, 0.010181032121181488f, 0.0048829237930476665f, 0.007796620484441519f, 0.0076700919307768345f, 0.00413529621437192f, 0.003984971437603235f, 0.005195935256779194f, 0.006592877674847841f, 0.004100949503481388f, 0.007820185273885727f, 0.008582242764532566f, 0.006317854858934879f, 0.002792695537209511f, 0.006884800735861063f, 0.004537359811365604f, 0.007047256920486689f, 0.005213077180087566f, 0.007075743284076452f, 0.00538603775203228f, 0.006301431450992823f, 0.0042894743382930756f, 0.005179184954613447f, 0.004090602044016123f, 0.0066046081483364105f, 0.004892147611826658f, 0.002756391419097781f, 0.005036262795329094f, 0.003971270751208067f, 0.00475611025467515f, 0.002871329430490732f, 0.0048520686104893684f, 0.004284589551389217f, 0.007474205456674099f, 0.005683975759893656f, 0.005673884879797697f, 0.0029806005768477917f, 0.004424938466399908f, 0.008309408091008663f, 0.005730744451284409f, 0.00823301076889038f, 0.004432336427271366f, 0.007964986376464367f, 0.00393322529271245f, 0.004706054925918579f, 0.004793764092028141f, 0.006652424111962318f, 0.004280115012079477f, 0.005383247509598732f, 0.005317327566444874f, 0.006814562249928713f, 0.005272240377962589f, 0.004051237367093563f, 0.0038257273845374584f, 0.006790383253246546f, 0.0032613538205623627f, 0.003383722621947527f, 0.010900534689426422f, 0.004231681581586599f, 0.005688708275556564f, 0.0054356553591787815f, 0.004951233509927988f, 0.007867425680160522f, 0.006244857795536518f, 0.007503420114517212f, 0.0057648117654025555f, 0.005365964025259018f, 0.006346189416944981f, 0.004837571643292904f, 0.002942710416391492f, 0.0037530658300966024f, 0.009466618299484253f, 0.002046218141913414f, 0.0058089811354875565f, 0.006099403835833073f, 0.006091998424381018f, 0.0050264582969248295f, 0.005572247318923473f, 0.008082058280706406f, 0.00506036588922143f, 0.0030645502265542746f, 0.005115251988172531f, 0.0105433976277709f, 0.004098700359463692f, 0.004342059604823589f, 0.0028652658220380545f, 0.0036626949440687895f, 0.0043295142240822315f, 0.004054153338074684f, 0.004579982720315456f, 0.007015829440206289f, 0.006597898434847593f, 0.004532182589173317f, 0.003628819016739726f, 0.0045942761935293674f, 0.004972023423761129f, 0.006530548445880413f, 0.00547889294102788f, 0.0064809685572981834f, 0.006200261879712343f, 0.005694223567843437f, 0.0054550920613110065f, 0.0033940093126147985f, 0.005392551422119141f, 0.0052527072839438915f, 0.0061162374913692474f, 0.010551980696618557f, 0.005739174783229828f, 0.010890698060393333f, 0.004884149879217148f, 0.0026293033733963966f, 0.0049372087232768536f, 0.009115212596952915f, 0.007215986028313637f, 0.004723012913018465f, 0.004560107830911875f, 0.008195455186069012f, 0.0028413727413862944f, 0.007733440026640892f, 0.004437391180545092f, 0.008456544950604439f, 0.004929068963974714f, 0.0048095909878611565f, 0.01334763877093792f, 0.004877119790762663f, 0.005651188548654318f, 0.004662306979298592f, 0.004982182290405035f, 0.0035762744955718517f, 0.005732803139835596f, 0.03733915835618973f, 0.00467041926458478f, 0.006148859858512878f, 0.008227796293795109f, 0.004904306959360838f, 0.003097879234701395f, 0.007141367066651583f, 0.00537105230614543f, 0.00699956901371479f, 0.006659569218754768f, 0.00497198011726141f, 0.003953089006245136f, 0.0034831000957638025f, 0.004711666144430637f, 0.008848610334098339f, 0.007067341823130846f, 0.008933712728321552f, 0.007695084437727928f, 0.00605206610634923f, 0.004673328250646591f, 0.0064551932737231255f, 0.006624752655625343f, 0.008077120408415794f, 0.007327419240027666f, 0.00465681916102767f, 0.002834696788340807f, 0.005035792477428913f, 0.0038467354606837034f, 0.006810258142650127f, 0.005403543822467327f, 0.00471825897693634f, 0.00474664568901062f, 0.007097253575921059f, 0.004695550072938204f, 0.0054297237657010555f, 0.006959031336009502f, 0.006247736047953367f, 0.0037025760393589735f, 0.0055649857968091965f, 0.005438852123916149f, 0.007523348554968834f, 0.005465773865580559f, 0.01250566728413105f, 0.005141035187989473f, 0.0037699202075600624f, 0.006023639813065529f, 0.004852198995649815f, 0.0077672796323895454f, 0.006724670995026827f, 0.0069379061460494995f, 0.008090203627943993f, 0.004983305931091309f, 0.005958022549748421f, 0.002648966619744897f, 0.006445708684623241f, 0.010113835334777832f, 0.009293186478316784f, 0.00497620040550828f, 0.0073124319314956665f, 0.004480914678424597f, 0.00487553933635354f, 0.0066960700787603855f, 0.004635585471987724f, 0.007912704721093178f, 0.0054087890312075615f, 0.003780371742323041f, 0.0031738600227981806f, 0.004992043599486351f, 0.004791684914380312f, 0.0100700119510293f, 0.009634020738303661f, 0.0017431231681257486f, 0.004086846951395273f, 0.004678047727793455f, 0.005977364722639322f, 0.006470606662333012f, 0.006276483181864023f, 0.008929945528507233f, 0.004803614225238562f, 0.005035633686929941f, 0.0073921713046729565f, 0.007406873162835836f, 0.006560810841619968f, 0.010025461204349995f, 0.0057074581272900105f, 0.010169516317546368f, 0.004151566419750452f, 0.019475748762488365f, 0.006185505539178848f, 0.007782378699630499f, 0.008818430826067924f, 0.004877385217696428f, 0.006317088380455971f, 0.008109702728688717f, 0.0045410702005028725f, 0.00642006378620863f, 0.0059703076258301735f, 0.008272425271570683f, 0.005480807274580002f, 0.004167759791016579f, 0.005885335151106119f, 0.005447797477245331f, 0.005454789847135544f, 0.004255947656929493f, 0.005727987736463547f, 0.004591257777065039f, 0.0052100010216236115f, 0.0034618517383933067f, 0.006470667663961649f, 0.005062388721853495f, 0.005046418868005276f, 0.006883950904011726f, 0.004413760267198086f, 0.004789846483618021f, 0.0038896112237125635f, 0.003824613755568862f, 0.005823819432407618f, 0.0056990268640220165f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #165 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00032199634006246924f, 0.00014143428415991366f, 0.00012857679394073784f, 0.0001462989894207567f, 0.0002481806732248515f, 0.0001612024789210409f, 0.00018443410226609558f, 0.00017428016872145236f, 0.00017204831237904727f, 0.00011595207615755498f, 0.0001773065305314958f, 0.00012800272088497877f, 0.0001139930755016394f, 0.00014469945745076984f, 8.627716306364164e-05f, 0.00015933717077132314f, 0.0001878096372820437f, 7.467581599485129e-05f, 0.00025796188856475055f, 0.00014169287169352174f, 0.00015683297533541918f, 0.00013691498315893114f, 7.732555968686938e-05f, 0.00018366261792834848f, 8.67885974003002e-05f, 0.00018325730343349278f, 8.258781599579379e-05f, 0.00010122025560121983f, 0.00011167670891154557f, 0.00012297238572500646f, 0.00012077907740604132f, 0.0001338030124315992f, 0.00021282548550516367f, 0.0001178398888441734f, 7.963543612277135e-05f, 0.00019921122293453664f, 0.00013278612459544092f, 7.949973223730922e-05f, 0.00010125334665644914f, 0.00020378852786961943f, 0.0001217672397615388f, 0.00011673504195641726f, 0.00010064904927276075f, 0.00019830698147416115f, 0.00026247446658089757f, 0.0001811892434488982f, 0.00015863434236962348f, 0.00011559806443983689f, 9.417752880835906e-05f, 0.0001434765144949779f, 8.442343823844567e-05f, 0.00011627165076788515f, 0.00012714802869595587f, 0.00013720632705371827f, 0.00011505705333547667f, 0.00014401634689420462f, 0.00012028130004182458f, 8.069235627772287e-05f, 9.575924923410639e-05f, 0.00010344181646360084f, 0.0001447325194021687f, 0.00013918416516389698f, 0.00010390100942458957f, 0.0001775488053681329f, 0.00013656851660925895f, 0.00024412438506260514f, 0.00011729657126124948f, 8.669703674968332e-05f, 0.00014618107525166124f, 0.00017812421720009297f, 0.00013755614054389298f, 0.00010701565042836592f, 0.00011034249473595992f, 0.00022416646243073046f, 0.00013561353262048215f, 6.759104144293815e-05f, 0.0001563164114486426f, 7.855291914893314e-05f, 5.991210855427198e-05f, 7.766879571136087e-05f, 0.00010213091445621103f, 0.00011245786299696192f, 9.851669892668724e-05f, 0.00010134697367902845f, 9.889018110698089e-05f, 0.00011824662942672148f, 0.00016700181004125625f, 0.0001139758387580514f, 0.00010592526814434677f, 0.00023955370124895126f, 0.00011489232565509155f, 0.00018344989803154022f, 0.0001804727507987991f, 9.730109013617039e-05f, 9.376403613714501e-05f, 0.00012225730461068451f, 0.0001551265304442495f, 9.64929349720478e-05f, 0.00018400436965748668f, 0.00020193512318655849f, 0.0001486554101575166f, 6.571048288606107e-05f, 0.000161995310918428f, 0.0001067614066414535f, 0.0001658178080106154f, 0.00012266064004506916f, 0.00016648808377794921f, 0.00012673030141741037f, 0.00014826898404862732f, 0.0001009288098430261f, 0.00012186318053863943f, 9.624945960240439e-05f, 0.00015540255117230117f, 0.00011510936019476503f, 6.485627091024071e-05f, 0.00011850030568893999f, 9.3441667559091e-05f, 0.00011190847726538777f, 6.756069342372939e-05f, 0.00011416632332839072f, 0.00010081387154059485f, 0.00017586366448085755f, 0.00013374061381909996f, 0.0001335031702183187f, 7.013177673798054e-05f, 0.00010411620314698666f, 0.00019551548757590353f, 0.0001348410442005843f, 0.0001937179040396586f, 0.00010429027315694839f, 0.0001874114532256499f, 9.254647738998756e-05f, 0.00011073070345446467f, 0.00011279444879619405f, 0.00015652763249818236f, 0.00010070858843391761f, 0.00012666464317589998f, 0.00012511359818745404f, 0.00016034264990594238f, 0.00012405271991156042f, 9.532323747407645e-05f, 9.001711441669613e-05f, 0.00015977372822817415f, 7.67377350712195e-05f, 7.961700612213463e-05f, 0.0002564831811469048f, 9.95689770206809e-05f, 0.00013385196507442743f, 0.0001278977724723518f, 0.00011649961379589513f, 0.00018511590315029025f, 0.00014693783305119723f, 0.00017655106785241514f, 0.00013564263645093888f, 0.00012625797535292804f, 0.00014932210615370423f, 0.00011382521915948018f, 6.924024637555704e-05f, 8.830743172438815e-05f, 0.00022274396906141192f, 4.814631029148586e-05f, 0.00013668190513271838f, 0.00014351538266055286f, 0.0001433411380276084f, 0.00011826960690086707f, 0.0001311117084696889f, 0.00019016608712263405f, 0.00011906743748113513f, 7.210706826299429e-05f, 0.00012035886902594939f, 0.00024807994486764073f, 9.644000965636224e-05f, 0.00010216610826319084f, 6.741801917087287e-05f, 8.61810622154735e-05f, 0.00010187092266278341f, 9.539184247842059e-05f, 0.0001077643028111197f, 0.00016507833788637072f, 0.00015524467744398862f, 0.00010663959255907685f, 8.538398105883971e-05f, 0.0001081006193999201f, 0.00011698879097821191f, 0.00015365995932370424f, 0.00012891512596979737f, 0.00015249337593559176f, 0.00014588852354791015f, 0.000133981739054434f, 0.0001283551100641489f, 7.985904085217044e-05f, 0.00012688356218859553f, 0.00012359311222098768f, 0.00014391147124115378f, 0.00024828189634718f, 0.0001350394159089774f, 0.0002562517183832824f, 0.00011492117482703179f, 6.186596147017553e-05f, 0.00011616962001426145f, 0.00021447559993248433f, 0.00016978790517896414f, 0.00011112971697002649f, 0.0001072966551873833f, 0.00019283423898741603f, 6.685582775389776e-05f, 0.00018196330347564071f, 0.00010440920596010983f, 0.0001989775337278843f, 0.0001159780949819833f, 0.00011316684685880318f, 0.00031406208290718496f, 0.00011475576320663095f, 0.0001329691440332681f, 0.00010970134462695569f, 0.00011722782073775306f, 8.414763578912243e-05f, 0.00013488948752637953f, 0.0008785684476606548f, 0.00010989222209900618f, 0.00014467905566561967f, 0.00019359521684236825f, 0.00011539545812411234f, 7.28912782506086e-05f, 0.000168032172950916f, 0.00012637770851142704f, 0.0001646957389311865f, 0.00015669575077481568f, 0.00011698777234414592f, 9.301386307924986e-05f, 8.195529517251998e-05f, 0.00011086273298133165f, 0.00020820260397158563f, 0.00016629039600957185f, 0.00021020500571466982f, 0.00018106080824509263f, 0.00014240156451705843f, 0.0001099606670322828f, 0.00015188691031653434f, 0.00015587653615511954f, 0.00019004989007953554f, 0.00017240986926481128f, 0.00010957221820717677f, 6.669874710496515e-05f, 0.00011848923895740882f, 9.051142114913091e-05f, 0.00016024136857595295f, 0.00012714220792986453f, 0.00011101786367362365f, 0.00011168578203069046f, 0.0001669941993895918f, 0.00011048353189835325f, 0.00012775820505339652f, 0.00016374191909562796f, 0.00014700555766467005f, 8.711943519301713e-05f, 0.0001309408398810774f, 0.00012797299132216722f, 0.0001770199742168188f, 0.00012860645074397326f, 0.0002942509890999645f, 0.00012096553837182f, 8.870400779414922e-05f, 0.00014173270028550178f, 0.0001141693937825039f, 0.00018275952606927603f, 0.00015822755813132972f, 0.0001632448547752574f, 0.00019035773584619164f, 0.000117254261567723f, 0.0001401887711836025f, 6.232862506294623e-05f, 0.0001516637421445921f, 0.00023797260655555874f, 0.00021866321912966669f, 0.00011708706733770669f, 0.00017205721815116704f, 0.00010543328971834853f, 0.00011471857578726485f, 0.00015755459025967866f, 0.00010907260002568364f, 0.00018618129251990467f, 0.0001272656227229163f, 8.8949927885551e-05f, 7.467906107194722e-05f, 0.00011745985102606937f, 0.00011274553253315389f, 0.00023694145784247667f, 0.0002266828523715958f, 4.101466402062215e-05f, 9.616110764909536e-05f, 0.00011007171269739047f, 0.00014064388233236969f, 0.0001522495731478557f, 0.000147681959788315f, 0.00021011636999901384f, 0.00011302621715003625f, 0.00011848549911519513f, 0.00017393344023730606f, 0.0001742793683661148f, 0.00015437202819157392f, 0.00023589321062900126f, 0.00013429313548840582f, 0.00023928274458739907f, 9.768391464604065e-05f, 0.0004582529072649777f, 0.00014554131485056132f, 0.00018311479652766138f, 0.00020749249961227179f, 0.00011476200597826391f, 0.00014863738033454865f, 0.00019081654318142682f, 0.00010684871085686609f, 0.00015106033242773265f, 0.0001404778304276988f, 0.00019464529759716243f, 0.0001289601786993444f, 9.806493471842259e-05f, 0.00013847847003489733f, 0.00012818347022403032f, 0.00012834799417760223f, 0.00010013994324253872f, 0.00013477618631441146f, 0.00010802959877764806f, 0.00012258825881872326f, 8.145533502101898e-05f, 0.0001522510137874633f, 0.0001191150295198895f, 0.00011873926996486261f, 0.00016197531658690423f, 0.00010385318455519155f, 0.00011270226968917996f, 9.152026905212551e-05f, 8.999091369332746e-05f, 0.0001370310492347926f, 0.0001340947492280975f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #166 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.005368983838707209f, 0.0034504211507737637f, 0.0033464282751083374f, 0.003846823936328292f, 0.004000466782599688f, 0.0037762699648737907f, 0.003814064199104905f, 0.004977495409548283f, 0.0037186257541179657f, 0.0033239617478102446f, 0.005147984251379967f, 0.0042587220668792725f, 0.004872355610132217f, 0.0053335861302912235f, 0.004409026354551315f, 0.0021132517140358686f, 0.0043565030209720135f, 0.004096532240509987f, 0.0034792176447808743f, 0.0045470972545444965f, 0.004810894839465618f, 0.003025526413694024f, 0.003566065803170204f, 0.005925334524363279f, 0.004919613711535931f, 0.0035607432946562767f, 0.004275529179722071f, 0.003537646494805813f, 0.002959814388304949f, 0.005109422840178013f, 0.006451099179685116f, 0.004045834764838219f, 0.002977553755044937f, 0.003649328602477908f, 0.004334231372922659f, 0.004501537419855595f, 0.0029709956143051386f, 0.004644548054784536f, 0.005642996169626713f, 0.0038131913170218468f, 0.00570576312020421f, 0.004920213483273983f, 0.0030049029737710953f, 0.00482654944062233f, 0.006057023536413908f, 0.004388372413814068f, 0.005358176771551371f, 0.003320242278277874f, 0.004309916868805885f, 0.0032449462451040745f, 0.006851118989288807f, 0.004894888028502464f, 0.0051498860120773315f, 0.005134576931595802f, 0.004782090894877911f, 0.004204858560115099f, 0.0049840351566672325f, 0.003189162351191044f, 0.006098635029047728f, 0.0034144918899983168f, 0.004926353693008423f, 0.0031506617087870836f, 0.004765200894325972f, 0.004573809914290905f, 0.004331093747168779f, 0.003161282744258642f, 0.004192767199128866f, 0.006179343909025192f, 0.002083125524222851f, 0.006462152116000652f, 0.0024577868171036243f, 0.004330955911427736f, 0.00445042597129941f, 0.004483084660023451f, 0.0034017309080809355f, 0.004764524754136801f, 0.0031421317253261805f, 0.006017343606799841f, 0.0031917968299239874f, 0.005040525924414396f, 0.0038317320868372917f, 0.003352746134623885f, 0.004166996106505394f, 0.00475342757999897f, 0.0058268229477107525f, 0.0024782801046967506f, 0.006516147404909134f, 0.00398028502240777f, 0.0030478211119771004f, 0.00303981127217412f, 0.0035041612572968006f, 0.004175351932644844f, 0.0043505276553332806f, 0.004998967982828617f, 0.00385140348225832f, 0.004264079034328461f, 0.0043782140128314495f, 0.004524856805801392f, 0.006100750993937254f, 0.004096150863915682f, 0.0035872303415089846f, 0.004439873620867729f, 0.0034238859079778194f, 0.0044124536216259f, 0.004023625515401363f, 0.004539921414107084f, 0.004113416653126478f, 0.0040305680595338345f, 0.00560425128787756f, 0.005078281741589308f, 0.007550182286649942f, 0.005639578681439161f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #167 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012632903235498816f, 8.118637924781069e-05f, 7.873948925407603e-05f, 9.051350934896618e-05f, 9.412863437319174e-05f, 8.885341230779886e-05f, 8.974268712336197e-05f, 0.00011711753904819489f, 8.749707922106609e-05f, 7.821086910553277e-05f, 0.00012112904369132593f, 0.00010020523041021079f, 0.00011464366252766922f, 0.00012549615348689258f, 0.00010374179692007601f, 4.97235705552157e-05f, 0.00010250595369143412f, 9.63889979175292e-05f, 8.186394552467391e-05f, 0.00010699052654672414f, 0.0001131975295720622f, 7.118885696399957e-05f, 8.39074346004054e-05f, 0.0001394196442561224f, 0.00011575561802601442f, 8.378219354199246e-05f, 0.00010060068598249927f, 8.323874499183148e-05f, 6.964269414311275e-05f, 0.00012022171722492203f, 0.00015179057663772255f, 9.519611194264144e-05f, 7.0060086727608e-05f, 8.586655894760042e-05f, 0.00010198191739618778f, 0.00010591853060759604f, 6.990577821852639e-05f, 0.00010928348638117313f, 0.00013277638936415315f, 8.972214709501714e-05f, 0.00013425324868876487f, 0.00011576973338378593f, 7.070360152283683e-05f, 0.00011356587492628023f, 0.0001425181981176138f, 0.00010325582115910947f, 0.00012607475218828768f, 7.812334661139175e-05f, 0.00010140980884898454f, 7.635168003616855e-05f, 0.00016120279906317592f, 0.00011517383973114192f, 0.00012117379083065316f, 0.00012081357999704778f, 0.00011251978867221624f, 9.893785318126902e-05f, 0.00011727141827577725f, 7.50391191104427e-05f, 0.000143497294629924f, 8.034098573261872e-05f, 0.00011591420479817316f, 7.413321873173118e-05f, 0.00011212237586732954f, 0.00010761906014522538f, 0.00010190808825427666f, 7.438312604790553e-05f, 9.865334868663922e-05f, 0.0001453963341191411f, 4.9014717660611495e-05f, 0.0001520506339147687f, 5.7830278819892555e-05f, 0.00010190485045313835f, 0.0001047159094014205f, 0.00010548434511292726f, 8.004072878975421e-05f, 0.00011210647062398493f, 7.393251144094393e-05f, 0.000141584561788477f, 7.510110299335793e-05f, 0.00011860061204060912f, 9.015840623760596e-05f, 7.888814434409142e-05f, 9.804697037907317e-05f, 0.00011184535833308473f, 0.00013710171333514154f, 5.8312474720878527e-05f, 0.00015332111797761172f, 9.365376899950206e-05f, 7.171343895606697e-05f, 7.152496982598677e-05f, 8.24508533696644e-05f, 9.824357402976602e-05f, 0.00010236536036245525f, 0.00011762278154492378f, 9.062125900527462e-05f, 0.00010033127182396129f, 0.00010301680595148355f, 0.00010646721784723923f, 0.00014354709128383547f, 9.638001938583329e-05f, 8.440542296739295e-05f, 0.0001044676173478365f, 8.056202204898e-05f, 0.00010382244363427162f, 9.467354539083317e-05f, 0.0001068216806743294f, 9.678627247922122e-05f, 9.48368979152292e-05f, 0.00013186474097892642f, 0.00011948898463742808f, 0.0001776513527147472f, 0.0001326959754806012f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #168 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0034220090601593256f, 0.0025091730058193207f, 0.003093788167461753f, 0.003490419825538993f, 0.003153333207592368f, 0.0038445580285042524f, 0.0024273886810988188f, 0.0030214020516723394f, 0.002567105693742633f, 0.0034274987410753965f, 0.003913694527000189f, 0.0032410388812422752f, 0.0033655313309282064f, 0.0025183220859616995f, 0.0028919989708811045f, 0.0031033458653837442f, 0.002834775485098362f, 0.002615390345454216f, 0.003763989545404911f, 0.0029469758737832308f, 0.0038776849396526814f, 0.0035189904738217592f, 0.002173058222979307f, 0.003576316637918353f, 0.002535221166908741f, 0.0022473353892564774f, 0.0023817403707653284f, 0.0035403550136834383f, 0.0032905959524214268f, 0.004285216331481934f, 0.002941956976428628f, 0.0018457140540704131f, 0.0032401164062321186f, 0.002087218454107642f, 0.003915578592568636f, 0.003025017911568284f, 0.003825346939265728f, 0.0034304028376936913f, 0.0017980319680646062f, 0.003572349203750491f, 0.003974136430770159f, 0.0038555492646992207f, 0.0018034579697996378f, 0.0034238523803651333f, 0.0018850475316867232f, 0.006538050714880228f, 0.00235958956182003f, 0.0027788220904767513f, 0.002487281570211053f, 0.0029289517551660538f, 0.0031972823198884726f, 0.004240034148097038f, 0.0022274390794336796f, 0.002702821046113968f, 0.003662164555862546f, 0.0024030152708292007f, 0.002574600512161851f, 0.0030700264032930136f, 0.0027932783123105764f, 0.0025967133697122335f, 0.004029248375445604f, 0.004818959627300501f, 0.0035520850215107203f, 0.0028888380620628595f, 0.0030751649755984545f, 0.003970372024923563f, 0.002946484135463834f, 0.003476616693660617f, 0.004240121226757765f, 0.004783222451806068f, 0.0031879746820777655f, 0.002945234999060631f, 0.0037810096982866526f, 0.0022439013700932264f, 0.002476178342476487f, 0.003150934586301446f, 0.004781818948686123f, 0.004037307109683752f, 0.002438749885186553f, 0.002150271087884903f, 0.0030192360281944275f, 0.00269770878367126f, 0.0020424136891961098f, 0.0024012080393731594f, 0.003113061422482133f, 0.002247242256999016f, 0.002743213204666972f, 0.0023700979072600603f, 0.003497286466881633f, 0.002417101990431547f, 0.004466028418391943f, 0.002803293988108635f, 0.0026645560283213854f, 0.0033910300116986036f, 0.0030196416191756725f, 0.005012040492147207f, 0.002367463195696473f, 0.0024357549846172333f, 0.003210861701518297f, 0.0024829241447150707f, 0.0022251582704484463f, 0.003695000195875764f, 0.0023749966640025377f, 0.002803805749863386f, 0.0027088355273008347f, 0.003731830045580864f, 0.0019216550281271338f, 0.00325772981159389f, 0.0019582328386604786f, 0.0025710801128298044f, 0.0032439040951430798f, 0.0025154175236821175f, 0.0024804985150694847f, 0.002856717212125659f, 0.0033491256181150675f, 0.0029606919270008802f, 0.0037308146711438894f, 0.0033205689396709204f, 0.004794022999703884f, 0.0028229213785380125f, 0.002330018673092127f, 0.0024680360220372677f, 0.0035295162815600634f, 0.003800384933128953f, 0.00305097340606153f, 0.0023899145890027285f, 0.004529615398496389f, 0.0030522344168275595f, 0.0028919349424540997f, 0.003765189554542303f, 0.002961191348731518f, 0.0017688178922981024f, 0.003715490223839879f, 0.003022042801603675f, 0.0033774874173104763f, 0.0024369736202061176f, 0.004082060419023037f, 0.004518815316259861f, 0.002250667428597808f, 0.003355868626385927f, 0.0028739289846271276f, 0.0045111458748579025f, 0.0030796348582953215f, 0.002372650196775794f, 0.004143663682043552f, 0.004737294744700193f, 0.00281916419044137f, 0.0021380269899964333f, 0.0031818668358027935f, 0.0037472674157470465f, 0.0021455397363752127f, 0.0038870726712048054f, 0.002429170301184058f, 0.002360195154324174f, 0.002858248073607683f, 0.002353822346776724f, 0.004943445324897766f, 0.003020704025402665f, 0.0029693341348320246f, 0.0029827638063579798f, 0.002659836784005165f, 0.00263776071369648f, 0.003561643650755286f, 0.005050120875239372f, 0.002710435539484024f, 0.002917935373261571f, 0.002943272003903985f, 0.0025464892387390137f, 0.004134220536798239f, 0.004777322523295879f, 0.003058189060539007f, 0.0030360748060047626f, 0.0027567401994019747f, 0.003644987940788269f, 0.002697177231311798f, 0.0035186265595257282f, 0.0026089318562299013f, 0.0037064242642372847f, 0.0024824582505971193f, 0.003479837905615568f, 0.002381659345701337f, 0.002220907947048545f, 0.0039263940416276455f, 0.002995686838403344f, 0.002912268741056323f, 0.0021573244594037533f, 0.003634953172877431f, 0.003802509978413582f, 0.00272063328884542f, 0.002502770395949483f, 0.0028880315367132425f, 0.0025325200986117125f, 0.0030164436902850866f, 0.0017697230214253068f, 0.002238437533378601f, 0.0017090350156649947f, 0.0024433229118585587f, 0.0022464042995125055f, 0.00420188857242465f, 0.0027729535941034555f, 0.00307204807177186f, 0.00280929496511817f, 0.0034345416352152824f, 0.0036730794236063957f, 0.0034854512196034193f, 0.0024955598637461662f, 0.002848322968930006f, 0.0031677361112087965f, 0.0020755932200700045f, 0.0025663997512310743f, 0.0019178291549906135f, 0.002537273336201906f, 0.003085597651079297f, 0.0033559217117726803f, 0.004122358281165361f, 0.002827439922839403f, 0.0025219586677849293f, 0.0029494892805814743f, 0.0032289023511111736f, 0.0027873716317117214f, 0.002809631871059537f, 0.003261904465034604f, 0.003871137974783778f, 0.003042301395907998f, 0.0024758814834058285f, 0.003535505384206772f, 0.003672020509839058f, 0.0027806491125375032f, 0.0025367485359311104f, 0.00232642306946218f, 0.0025738596450537443f, 0.003871721914038062f, 0.003997025545686483f, 0.0025823567993938923f, 0.00267418404109776f, 0.0030259275808930397f, 0.0022484445944428444f, 0.002556698862463236f, 0.003657564288005233f, 0.0026191945653408766f, 0.002859701868146658f, 0.003482724539935589f, 0.003829273395240307f, 0.004123077727854252f, 0.004286817274987698f, 0.00273498403839767f, 0.003517800709232688f, 0.0034776763059198856f, 0.0027142821345478296f, 0.0023610491771250963f, 0.0038757335860282183f, 0.00268762931227684f, 0.002288728253915906f, 0.0030627050437033176f, 0.002666035434231162f, 0.0023876307532191277f, 0.0030380079988390207f, 0.0049846176989376545f, 0.002701414283365011f, 0.003708411706611514f, 0.0020971910562366247f, 0.002930806716904044f, 0.003956553991883993f, 0.0017161888536065817f, 0.0028547749388962984f, 0.0037172080483287573f, 0.003363880096003413f, 0.003632861189544201f, 0.0033509659115225077f, 0.002169990446418524f, 0.003430101554840803f, 0.0031754712108522654f, 0.00372620252892375f, 0.0022453651763498783f, 0.0039056807290762663f, 0.003283897414803505f, 0.0030903785955160856f, 0.003940899390727282f, 0.002570922952145338f, 0.003254982642829418f, 0.0017888962756842375f, 0.0026397337205708027f, 0.0024893067311495543f, 0.0029904316179454327f, 0.0033449940383434296f, 0.002193017862737179f, 0.0032816671300679445f, 0.002277164487168193f, 0.0033273438457399607f, 0.0027156479191035032f, 0.0027932538650929928f, 0.0026281133759766817f, 0.0024246959947049618f, 0.002877495251595974f, 0.0030100413132458925f, 0.0037956563755869865f, 0.0026737507432699203f, 0.0029877671040594578f, 0.002698882482945919f, 0.002982040634378791f, 0.0024328711442649364f, 0.0019919867627322674f, 0.00284849526360631f, 0.002477681962773204f, 0.0035161778796464205f, 0.0033600933384150267f, 0.0026005811523646116f, 0.0019372731912881136f, 0.003189011476933956f, 0.003531651571393013f, 0.00251618679612875f, 0.0019204734126105905f, 0.003009556094184518f, 0.0026348030660301447f, 0.002250103047117591f, 0.0036963012535125017f, 0.003955172840505838f, 0.0027842866256833076f, 0.002573176985606551f, 0.004073712043464184f, 0.0032604977022856474f, 0.002753833308815956f, 0.003479118924587965f, 0.00278643099591136f, 0.002983942162245512f, 0.003199036931619048f, 0.003954240120947361f, 0.0027243574149906635f, 0.00342189590446651f, 0.002859613625332713f, 0.0034099232871085405f, 0.0028664697892963886f, 0.003963747061789036f, 0.003921022638678551f, 0.0037179605569690466f, 0.002918872283771634f, 0.002379405777901411f, 0.0041029308922588825f, 0.0028831446543335915f, 0.0031237176153808832f, 0.003270804649218917f, 0.0023372007999569178f, 0.0035733722615987062f, 0.0020720898173749447f, 0.002679529134184122f, 0.00257231667637825f, 0.0034975209273397923f, 0.0022800678852945566f, 0.0034453803673386574f, 0.0035381915513426065f, 0.0036861635744571686f, 0.005309212952852249f, 0.002921785693615675f, 0.003624396398663521f, 0.0035943060647696257f, 0.0028596355114132166f, 0.002056985395029187f, 0.002788264537230134f, 0.004030339885503054f, 0.003410784527659416f, 0.0017206615302711725f, 0.0033302330411970615f, 0.0022065811790525913f, 0.0022719264961779118f, 0.0020950771868228912f, 0.0028414009138941765f, 0.0018286670092493296f, 0.002857788233086467f, 0.002604607492685318f, 0.0027249755803495646f, 0.0024690020363777876f, 0.003489634720608592f, 0.0022261873818933964f, 0.0026188816409558058f, 0.002795322798192501f, 0.0031732222996652126f, 0.002850254764780402f, 0.0023579387925565243f, 0.003478432772681117f, 0.0028605139814317226f, 0.003087845863774419f, 0.002511735074222088f, 0.00233826064504683f, 0.002684076316654682f, 0.002456513000652194f, 0.002312239957973361f, 0.0031915034633129835f, 0.0025565086398273706f, 0.0024939822033047676f, 0.0029281561728566885f, 0.0017611111979931593f, 0.003756312420591712f, 0.003775171469897032f, 0.0029635962564498186f, 0.0030063886661082506f, 0.0022566821426153183f, 0.003920599352568388f, 0.002985934028401971f, 0.003548194421455264f, 0.0028810312505811453f, 0.0033629252575337887f, 0.0022590793669223785f, 0.0029626262839883566f, 0.003429582342505455f, 0.0029363047797232866f, 0.003427558345720172f, 0.003203271422535181f, 0.002128437627106905f, 0.0016265988815575838f, 0.0028322585858404636f, 0.0028751171194016933f, 0.0020617078989744186f, 0.00286393822170794f, 0.0032982751727104187f, 0.0025773923844099045f, 0.0029374612495303154f, 0.003389923134818673f, 0.0017178341513499618f, 0.0032307221554219723f, 0.0022122554946690798f, 0.0028981934301555157f, 0.0027696597389876842f, 0.0037074931897222996f, 0.003723332891240716f, 0.0038516141939908266f, 0.0024581379257142544f, 0.0034446401987224817f, 0.0036760021466761827f, 0.0032441020011901855f, 0.0031676923390477896f, 0.002225958975031972f, 0.0026569582987576723f, 0.0032781607005745173f, 0.002552788471803069f, 0.0031400518491864204f, 0.0026077276561409235f, 0.0036417481023818254f, 0.0032321116887032986f, 0.003450353629887104f, 0.00212491350248456f, 0.003654739586636424f, 0.003898381954059005f, 0.0024092390667647123f, 0.004016800783574581f, 0.0034348031040281057f, 0.0024051477666944265f, 0.002450693165883422f, 0.0024346266873180866f, 0.0027168993838131428f, 0.0024400209076702595f, 0.003069049445912242f, 0.00236290181055665f, 0.001731431228108704f, 0.003822097321972251f, 0.0026720045134425163f, 0.0037050822284072638f, 0.0016501850914210081f, 0.003002490382641554f, 0.003679468994960189f, 0.0033935264218598604f, 0.0034779703710228205f, 0.0028996216133236885f, 0.002287238370627165f, 0.003249258268624544f, 0.0027330350130796432f, 0.0029258974827826023f, 0.002445709891617298f, 0.0036331552546471357f, 0.003529281122609973f, 0.0018724258989095688f, 0.003979239147156477f, 0.0031211015302687883f, 0.0024802095722407103f, 0.003400862915441394f, 0.0028340143617242575f, 0.003247824963182211f, 0.0028523379005491734f, 0.0036877652164548635f, 0.003540951758623123f, 0.0032287840731441975f, 0.004151406232267618f, 0.003071397077292204f, 0.005417639389634132f, 0.0038817657623440027f, 0.0030326105188578367f, 0.0020512468181550503f, 0.0022383779287338257f, 0.002080787206068635f, 0.002833485836163163f, 0.002846592804417014f, 0.0027585213538259268f, 0.0020642138551920652f, 0.004038565326482058f, 0.0028315659146755934f, 0.0032277866266667843f, 0.0022370561491698027f, 0.0019469005055725574f, 0.0038450132124125957f, 0.002455132082104683f, 0.0017342416103929281f, 0.002871078671887517f, 0.0029884474352002144f, 0.004040821455419064f, 0.0020754060242325068f, 0.0023751952685415745f, 0.002103238133713603f, 0.003551183035597205f, 0.00382606009952724f, 0.0024568147491663694f, 0.0028470123652368784f, 0.0030256176833063364f, 0.0028306578751653433f, 0.004366294480860233f, 0.003367839613929391f, 0.002213637111708522f, 0.002841245150193572f, 0.004175994545221329f, 0.0024557237047702074f, 0.0017527113668620586f, 0.002413463080301881f, 0.00438811257481575f, 0.0024679074995219707f, 0.002281734487041831f, 0.002753602573648095f, 0.002070474671199918f, 0.003048169892281294f, 0.0025027417577803135f, 0.0026334431022405624f, 0.003068509977310896f, 0.003179639345034957f, 0.0032771730329841375f, 0.002459562150761485f, 0.0019781924784183502f, 0.003187402617186308f, 0.0024203932844102383f, 0.0026582248974591494f, 0.0036975699476897717f, 0.003064509481191635f, 0.002691472414880991f, 0.0021059142891317606f, 0.002818918786942959f, 0.0026834048330783844f, 0.0031053603161126375f, 0.0017848018324002624f, 0.0022955206222832203f, 0.0024620569311082363f, 0.0023296496365219355f, 0.0024532622192054987f, 0.002314559416845441f, 0.003297043265774846f, 0.002326564397662878f, 0.0030118844006210566f, 0.00250632013194263f, 0.003935507033020258f, 0.00293396576307714f, 0.001963801681995392f, 0.0031868803780525923f, 0.002737752627581358f, 0.002960703568533063f, 0.0034201713278889656f, 0.0032358020544052124f, 0.004189637023955584f, 0.002699551172554493f, 0.002723280806094408f, 0.003465106012299657f, 0.002058908576145768f, 0.0031518174801021814f, 0.003411758691072464f, 0.0023094655480235815f, 0.003963956609368324f, 0.0024320080410689116f, 0.0044587417505681515f, 0.003450358984991908f, 0.0038381298072636127f, 0.004546911455690861f, 0.003936499357223511f, 0.0025142321828752756f, 0.0019053044961765409f, 0.0028326832689344883f, 0.003261677687987685f, 0.0033951804507523775f, 0.0019494628068059683f, 0.0034760471899062395f, 0.002401502802968025f, 0.0033248045947402716f, 0.003749622730538249f, 0.0025685059372335672f, 0.003830042202025652f, 0.0035537343937903643f, 0.002010553842410445f, 0.0028865989297628403f, 0.002591337077319622f, 0.002404002472758293f, 0.0021118244621902704f, 0.0021737925708293915f, 0.003726240014657378f, 0.0033623487688601017f, 0.0027342175599187613f, 0.0025108119007200003f, 0.003167365677654743f, 0.0030297075863927603f, 0.0038760032039135695f, 0.0035417675971984863f, 0.0035798433236777782f, 0.002966916421428323f, 0.0021587701048702f, 0.0028844184707850218f, 0.002384487772360444f, 0.0035775953438133f, 0.0031350539065897465f, 0.0031246617436408997f, 0.0027772337198257446f, 0.0026265857741236687f, 0.002549863653257489f, 0.002875917823985219f, 0.002992982044816017f, 0.0029373206198215485f, 0.0023520952090620995f, 0.003124768612906337f, 0.003467107890173793f, 0.0027278061024844646f, 0.0034202830865979195f, 0.002465746598318219f, 0.0035775022115558386f, 0.0021512038074433804f, 0.004448389168828726f, 0.0027031395584344864f, 0.003164361696690321f, 0.003981543239206076f, 0.0030205450020730495f, 0.002854647347703576f, 0.004120151046663523f, 0.003120430978015065f, 0.0038048664573580027f, 0.0036920306738466024f, 0.003729982301592827f, 0.0030080247670412064f, 0.004697092808783054f, 0.0031127319671213627f, 0.0023065349087119102f, 0.003226520726457238f, 0.0024335396010428667f, 0.0033420741092413664f, 0.0030385502614080906f, 0.0021314783953130245f, 0.0034913269337266684f, 0.002601026790216565f, 0.003306327387690544f, 0.002752734813839197f, 0.0021674938034266233f, 0.002504874486476183f, 0.0020742355845868587f, 0.002665082924067974f, 0.0032574424985796213f, 0.0022949313279241323f, 0.0022155430633574724f, 0.003019812051206827f, 0.0034140395000576973f, 0.002690020715817809f, 0.004275183659046888f, 0.0026930030435323715f, 0.0034126127138733864f, 0.0028112605214118958f, 0.0024160402826964855f, 0.0026007986161857843f, 0.002820714609697461f, 0.0027624042704701424f, 0.005960539914667606f, 0.005030455067753792f, 0.0027427265886217356f, 0.002909368136897683f, 0.004072748124599457f, 0.0031589127611368895f, 0.0026544646825641394f, 0.0036614397540688515f, 0.0019452146952971816f, 0.0033175379503518343f, 0.003023584373295307f, 0.0028084067162126303f, 0.0030353404581546783f, 0.0026294649578630924f, 0.003897528164088726f, 0.0027866840828210115f, 0.002434849739074707f, 0.001821752986870706f, 0.001806852756999433f, 0.0038248419295996428f, 0.004051231313496828f, 0.0027501739095896482f, 0.0032252324745059013f, 0.0031031423714011908f, 0.0031852195970714092f, 0.0022467130329459906f, 0.00263425474986434f, 0.0033665781375020742f, 0.003755179699510336f, 0.0026704655028879642f, 0.003049161983653903f, 0.002789141144603491f, 0.003572426037862897f, 0.002629196271300316f, 0.0028134682215750217f, 0.0030808092560619116f, 0.002868159208446741f, 0.0030691702850162983f, 0.00344622484408319f, 0.0021186312660574913f, 0.004232129547744989f, 0.002989786211401224f, 0.0027714192401617765f, 0.003911297302693129f, 0.00207802327349782f, 0.0039353440515697f, 0.0024325023405253887f, 0.0032451669685542583f, 0.0031344029121100903f, 0.0021040919236838818f, 0.003171483986079693f, 0.004945829976350069f, 0.0030660778284072876f, 0.002258873078972101f, 0.0034282568376511335f, 0.0022586483974009752f, 0.004289478994905949f, 0.003257494419813156f, 0.002478182315826416f, 0.0020666862837970257f, 0.004711974412202835f, 0.00248979520983994f, 0.0026107223238795996f, 0.002564182272180915f, 0.0038555311039090157f, 0.0031477941665798426f, 0.0029640421271324158f, 0.0032202701549977064f, 0.0022485805675387383f, 0.004148290492594242f, 0.0028868482913821936f, 0.002278917236253619f, 0.003086696146056056f, 0.0024147971998900175f, 0.0028866552747786045f, 0.00269078416749835f, 0.002706880448386073f, 0.0033351124729961157f, 0.0028356239199638367f, 0.00219691707752645f, 0.00440934207290411f, 0.002600656356662512f, 0.0038052250165492296f, 0.0020545953884720802f, 0.0028364125173538923f, 0.0023958489764481783f, 0.0035384625662118196f, 0.00340882851742208f, 0.0022012023255228996f, 0.0028296993114054203f, 0.00377520639449358f, 0.0034353495575487614f, 0.00229556648992002f, 0.004853596445173025f, 0.002851577475667f, 0.004091400653123856f, 0.0024586953222751617f, 0.0028901295736432076f, 0.0026993004139512777f, 0.0028201164677739143f, 0.0022497468162328005f, 0.0031864619813859463f, 0.002809506841003895f, 0.002473328961059451f, 0.0035124081186950207f, 0.002794512314721942f, 0.0026940328534692526f, 0.0033870881889015436f, 0.002547219395637512f, 0.0033041969873011112f, 0.004816475789994001f, 0.0028030136600136757f, 0.002849157201126218f, 0.003984422888606787f, 0.0028694102074950933f, 0.002654435345903039f, 0.002574536018073559f, 0.0017461562529206276f, 0.0024541092570871115f, 0.0030629930552095175f, 0.0019859413150697947f, 0.003159738378599286f, 0.0032974889036267996f, 0.003986086696386337f, 0.003809300484135747f, 0.0021650928538292646f, 0.0039329021237790585f, 0.0022724031005054712f, 0.004099973011761904f, 0.004023459739983082f, 0.002337144687771797f, 0.0030354890041053295f, 0.0025705278385430574f, 0.002706376602873206f, 0.003346055280417204f, 0.0024329142179340124f, 0.004286063835024834f, 0.0022309264168143272f, 0.0027634284924715757f, 0.0036293300800025463f, 0.0023664331529289484f, 0.0032315081916749477f, 0.00257180817425251f, 0.002947614062577486f, 0.0021823886781930923f, 0.0037871019449084997f, 0.0029464284889400005f, 0.0028932320419698954f, 0.0031520072370767593f, 0.0019413343397900462f, 0.0026259548030793667f, 0.002959417412057519f, 0.0036649599205702543f, 0.002915308577939868f, 0.004049811977893114f, 0.003786833258345723f, 0.003853993955999613f, 0.0031261718831956387f, 0.003945863805711269f, 0.002597454935312271f, 0.0034463407937437296f, 0.0018152588745579123f, 0.003471051575616002f, 0.0024754302576184273f, 0.0030429204925894737f, 0.004199074115604162f, 0.004406937398016453f, 0.002486551646143198f, 0.0041876486502587795f, 0.002366074360907078f, 0.0034554447047412395f, 0.0028499108739197254f, 0.0017972541972994804f, 0.00309113715775311f, 0.0032254140824079514f, 0.003466053633019328f, 0.002846337156370282f, 0.0029169360641390085f, 0.0035360800102353096f, 0.003901895834133029f, 0.003918230067938566f, 0.00334925320930779f, 0.0029709942173212767f, 0.00310520944185555f, 0.004720157012343407f, 0.003217371879145503f, 0.003689745208248496f, 0.002060272265225649f, 0.00252712145447731f, 0.002939756726846099f, 0.003420935943722725f, 0.0030953523237258196f, 0.0034769298508763313f, 0.0022787507623434067f, 0.0042355721816420555f, 0.0020187795162200928f, 0.004807058721780777f, 0.003934107255190611f, 0.003703947179019451f, 0.0034451258834451437f, 0.002584977075457573f, 0.002992979483678937f, 0.004430653061717749f, 0.0036149562802165747f, 0.004110322333872318f, 0.002441970631480217f, 0.0034893047995865345f, 0.00228126416914165f, 0.0026620037388056517f, 0.004047737922519445f, 0.003290498862043023f, 0.003987977281212807f, 0.003553898073732853f, 0.002935195341706276f, 0.0024837986566126347f, 0.0022420247551053762f, 0.0034417242277413607f, 0.003413493512198329f, 0.003149711061269045f, 0.0036045366432517767f, 0.0026838937774300575f, 0.002610720694065094f, 0.00203081127256155f, 0.0027741428930312395f, 0.0024971356615424156f, 0.0028749858029186726f, 0.003281261771917343f, 0.0031853029504418373f, 0.004183782264590263f, 0.0035857409238815308f, 0.003330177627503872f, 0.0025870036333799362f, 0.0030077514238655567f, 0.003960492089390755f, 0.004165962338447571f, 0.0025401294697076082f, 0.00268352753482759f, 0.0035911754239350557f, 0.003047506557777524f, 0.0019106712425127625f, 0.002713073045015335f, 0.003584797028452158f, 0.0019339363789185882f, 0.00336951925419271f, 0.003007735824212432f, 0.0026136280503124f, 0.003244823543354869f, 0.0026367127429693937f, 0.004078828729689121f, 0.0018910428043454885f, 0.002787852194160223f, 0.0024465376045554876f, 0.0028085969388484955f, 0.0024149511009454727f, 0.0034765794407576323f, 0.002741926582530141f, 0.0016266658203676343f, 0.002290119882673025f, 0.002289078664034605f, 0.0037863634061068296f, 0.004638275597244501f, 0.003401557682082057f, 0.0019671746995300055f, 0.0019852244295179844f, 0.002766170771792531f, 0.0029225279577076435f, 0.0027928552590310574f, 0.004025333561003208f, 0.0029959639068692923f, 0.002470830688253045f, 0.0023877571802586317f, 0.002106389030814171f, 0.003046636702492833f, 0.0034905055072158575f, 0.00231364369392395f, 0.0034741624258458614f, 0.0030809424351900816f, 0.0026710156816989183f, 0.0025681450497359037f, 0.0017830979777500033f, 0.0024282720405608416f, 0.0031070199329406023f, 0.0025484056677669287f, 0.0046503618359565735f, 0.002568900352343917f, 0.0029534082859754562f, 0.0021550722885876894f, 0.0023958776146173477f, 0.003567854641005397f, 0.0039693997241556644f, 0.0037613529711961746f, 0.002349652349948883f, 0.0025901002809405327f, 0.004202075768262148f, 0.0027887027245014906f, 0.0031658115331083536f, 0.002361807506531477f, 0.002662054495885968f, 0.002534084254875779f, 0.002647177781909704f, 0.0030109884683042765f, 0.0031912594567984343f, 0.0030441079288721085f, 0.003640655428171158f, 0.0025402202736586332f, 0.002520979382097721f, 0.0030576325953006744f, 0.0016773550305515528f, 0.0030979595612734556f, 0.002300949301570654f, 0.0030611585825681686f, 0.0017797865439206362f, 0.003023571567609906f, 0.003910106141120195f, 0.0023597555700689554f, 0.002976519986987114f, 0.003958958201110363f, 0.00248161144554615f, 0.00309985619969666f, 0.0022873696871101856f, 0.0030785375274717808f, 0.0029023943934589624f, 0.0024104025214910507f, 0.003958634566515684f, 0.004180065356194973f, 0.002780822105705738f, 0.003046823665499687f, 0.0032114952336996794f, 0.003515862626954913f, 0.002662166953086853f, 0.0029462266247719526f, 0.0031775147654116154f, 0.0024190417025238276f, 0.002981066470965743f, 0.00425448315218091f, 0.0040903897024691105f, 0.0029251135420054197f, 0.003599888877943158f, 0.00302665657363832f, 0.002548949560150504f, 0.004301606211811304f, 0.0020968082826584578f, 0.00397445447742939f, 0.003994555212557316f, 0.002687177387997508f, 0.0034568910486996174f, 0.002855564234778285f, 0.0028573013842105865f, 0.0026460483204573393f, 0.0026217515114694834f, 0.0036171716637909412f, 0.0030895511154085398f, 0.0018630663398653269f, 0.003695103107020259f, 0.0015791318146511912f, 0.003968787379562855f, 0.0037513896822929382f, 0.0020878224167972803f, 0.004515807144343853f, 0.002130854409188032f, 0.0024411308113485575f, 0.0021125669591128826f, 0.004193626344203949f, 0.0033469803165644407f, 0.0025400067679584026f, 0.00257497513666749f, 0.0036473905202001333f, 0.00214380887337029f, 0.001812317525036633f, 0.004364568740129471f, 0.0023384015075862408f, 0.0033714345190674067f, 0.002158078132197261f, 0.0030702068470418453f, 0.0032532946206629276f, 0.0017622768646106124f, 0.0030117768328636885f, 0.0027071209624409676f, 0.0029410289134830236f, 0.004380215425044298f, 0.0024339447263628244f, 0.002898081438615918f, 0.0032751045655459166f, 0.0026396235916763544f, 0.003361651673913002f, 0.0023735049180686474f, 0.0017911059549078345f, 0.0025379108265042305f, 0.003645528107881546f, 0.0025659415405243635f, 0.0029817146714776754f, 0.003495557466521859f, 0.002417091280221939f, 0.0021579512394964695f, 0.0030433100182563066f, 0.0027271537110209465f, 0.0034782136790454388f, 0.001802756218239665f, 0.001961825881153345f, 0.0019821689929813147f, 0.002631353447213769f, 0.0032307321671396494f, 0.0023898493964225054f, 0.0025687178131192923f, 0.0028043335769325495f, 0.0027716965414583683f, 0.002349232556298375f, 0.00192278774920851f, 0.0025678493548184633f, 0.00256891967728734f, 0.0032129359897226095f, 0.0034551117569208145f, 0.0030351842287927866f, 0.0031426907517015934f, 0.00306876003742218f, 0.003265306819230318f, 0.0029323732014745474f, 0.00465164752677083f, 0.002213532105088234f, 0.00232874252833426f, 0.0020612566731870174f, 0.0027377011720091105f, 0.0025193423498421907f, 0.003589245490729809f, 0.00407346710562706f, 0.0032316800206899643f, 0.0023256191052496433f, 0.0029070477467030287f, 0.0032442801166325808f, 0.002945201937109232f, 0.002978904638439417f, 0.0026320689357817173f, 0.003301398130133748f, 0.0023709097877144814f, 0.00399735476821661f, 0.0024671361315995455f, 0.0038233480881899595f, 0.001571562490426004f, 0.0031159997452050447f, 0.0029532911721616983f, 0.00254780612885952f, 0.0019183940021321177f, 0.004588784649968147f, 0.004017295781522989f, 0.004476276692003012f, 0.002758261514827609f, 0.0026802578940987587f, 0.00200938549824059f, 0.00336838117800653f, 0.0022085418459028006f, 0.0036335529293864965f, 0.004170025698840618f, 0.0032993846107274294f, 0.0029075199272483587f, 0.0023090096656233072f, 0.002341975923627615f, 0.005249182227998972f, 0.0020991559140384197f, 0.005552598275244236f, 0.0039002136327326298f, 0.004359689075499773f, 0.0017895862692967057f, 0.003269343404099345f, 0.002167714526876807f, 0.004752865992486477f, 0.003106270916759968f, 0.0036707480903714895f, 0.0016811297973617911f, 0.003002162091434002f, 0.003596732160076499f, 0.002494867192581296f, 0.0028119217604398727f, 0.003351325634866953f, 0.0038125619757920504f, 0.0029205400496721268f, 0.0038524309638887644f, 0.0032499388325959444f, 0.002848744625225663f, 0.004548561293631792f, 0.002360086888074875f, 0.002675853669643402f, 0.002679909812286496f, 0.002589630661532283f, 0.004940326791256666f, 0.005419902037829161f, 0.0037238975055515766f, 0.0036569535732269287f, 0.0028288601897656918f, 0.0029879710637032986f, 0.003629249520599842f, 0.003112621372565627f, 0.0028999787755310535f, 0.002781149698421359f, 0.00252163247205317f, 0.003750809235498309f, 0.0037966424133628607f, 0.0026024652179330587f, 0.0022717728279531f, 0.00300705898553133f, 0.002949182642623782f, 0.0027308843564242125f, 0.002907298970967531f, 0.002260618843138218f, 0.0024671838618814945f, 0.0032419038470834494f, 0.004245635587722063f, 0.004153544083237648f, 0.003373144194483757f, 0.0036053282674402f, 0.003342435695230961f, 0.003315231529995799f, 0.0029096980579197407f, 0.003913437016308308f, 0.0025445104110985994f, 0.0032059510704129934f, 0.004589640069752932f, 0.004353465046733618f, 0.003321731463074684f, 0.0033273412846028805f, 0.003942627459764481f, 0.0029071280732750893f, 0.003022565273568034f, 0.003489074297249317f, 0.002194928703829646f, 0.0028755648527294397f, 0.002062635961920023f, 0.0027269639540463686f, 0.0027329795993864536f, 0.0039439075626432896f, 0.0020843055099248886f, 0.0032967773731797934f, 0.0040863496251404285f, 0.0025232986081391573f, 0.0029242290183901787f, 0.003184952074661851f, 0.0035179108381271362f, 0.002213378669694066f, 0.003048740094527602f, 0.003031103638932109f, 0.0033057820983231068f, 0.0026314074639230967f, 0.0029041932430118322f, 0.0035408930853009224f, 0.002750176005065441f, 0.002697244519367814f, 0.0021871381904929876f, 0.003239198587834835f, 0.004155514296144247f, 0.0022605613339692354f, 0.0033553873654454947f, 0.005439117085188627f, 0.0026754126884043217f, 0.0027726853732019663f, 0.002686886815354228f, 0.003935335669666529f, 0.0025693904608488083f, 0.0038728811778128147f, 0.0025462035555392504f, 0.0021230336278676987f, 0.0030110699590295553f, 0.00388662819750607f, 0.0029520513489842415f, 0.0018375491490587592f, 0.002471835585311055f, 0.004623593296855688f, 0.004710382781922817f, 0.0030808127485215664f, 0.0029506650753319263f, 0.003275034949183464f, 0.0018701255321502686f, 0.00311843678355217f, 0.0029642151203006506f, 0.0027784781996160746f, 0.002289223251864314f, 0.0027494803071022034f, 0.0033016710076481104f, 0.0031795816030353308f, 0.003022098448127508f, 0.002377726836130023f, 0.0014794134767726064f, 0.002128327265381813f, 0.005354715045541525f, 0.003054086584597826f, 0.004251914098858833f, 0.0021827183663845062f, 0.002896042773500085f, 0.0020647807978093624f, 0.00296790967695415f, 0.0022760522551834583f, 0.002778067719191313f, 0.0027695379685610533f, 0.0037976831663399935f, 0.002598279155790806f, 0.002921557053923607f, 0.0022570022847503424f, 0.003520683152601123f, 0.0022607778664678335f, 0.0026683779433369637f, 0.0021568655502051115f, 0.003138540545478463f, 0.0037901951000094414f, 0.0028688115999102592f, 0.0033042861614376307f, 0.0030304917600005865f, 0.002860682550817728f, 0.0032707268837839365f, 0.003339615650475025f, 0.002441826742142439f, 0.003679810557514429f, 0.003020139876753092f, 0.003770367242395878f, 0.0032090418972074986f, 0.0028736202511936426f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #169 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006423898739740252f, 0.0004710295470431447f, 0.0005807752604596317f, 0.0006552321719937027f, 0.0005919532268308103f, 0.0007217120728455484f, 0.00045567675260826945f, 0.0005671867402270436f, 0.0004819048335775733f, 0.0006434204406104982f, 0.0007346905767917633f, 0.00060841761296615f, 0.0006317876977846026f, 0.00047274705138988793f, 0.0005428948206827044f, 0.0005825694533996284f, 0.000532152655068785f, 0.0004909689887426794f, 0.0007065875106491148f, 0.000553215213585645f, 0.0007279307465068996f, 0.0006605955422855914f, 0.0004079330537933856f, 0.0006713569746352732f, 0.00047591939801350236f, 0.00042187661165371537f, 0.00044710750808008015f, 0.0006646061665378511f, 0.000617720652371645f, 0.0008044337737374008f, 0.0005522730643860996f, 0.0003464830224402249f, 0.0006082444451749325f, 0.00039181896136142313f, 0.0007350442465394735f, 0.0005678654997609556f, 0.0007181057007983327f, 0.0006439656135626137f, 0.00033753199386410415f, 0.0006706122076138854f, 0.0007460369379259646f, 0.0007237753598019481f, 0.0003385505988262594f, 0.0006427359185181558f, 0.00035386683885008097f, 0.0012273426400497556f, 0.0004429492983035743f, 0.000521648908033967f, 0.000466920027974993f, 0.000549831660464406f, 0.0006002035224810243f, 0.0007959520444273949f, 0.0004181416006758809f, 0.0005073817446827888f, 0.0006874726386740804f, 0.0004511013103183359f, 0.0004833118000533432f, 0.0005763146327808499f, 0.0005243626656010747f, 0.0004874628793913871f, 0.0007563827093690634f, 0.0009046297054737806f, 0.0006668081623502076f, 0.0005423013935796916f, 0.0005772792501375079f, 0.0007453302387148142f, 0.0005531228962354362f, 0.0006526409997604787f, 0.0007959684007801116f, 0.000897920981515199f, 0.0005984562449157238f, 0.0005528884357772768f, 0.000709782587364316f, 0.0004212319618090987f, 0.0004648356989491731f, 0.0005915029905736446f, 0.0008976575336419046f, 0.0007578955264762044f, 0.00045780951040796936f, 0.00040365540189668536f, 0.0005667801015079021f, 0.0005064220749773085f, 0.0003834080707747489f, 0.00045076204696670175f, 0.000584393332246691f, 0.0004218591202516109f, 0.0005149642820470035f, 0.00044492195593193173f, 0.0006565211806446314f, 0.00045374571345746517f, 0.0008383763488382101f, 0.0005262428312562406f, 0.0005001985118724406f, 0.0006365744047798216f, 0.000566856237128377f, 0.0009408753830939531f, 0.00044442736543715f, 0.0004572472826112062f, 0.0006027526687830687f, 0.00046610203571617603f, 0.0004177134542260319f, 0.0006936365971341729f, 0.00044584154966287315f, 0.0005263388738967478f, 0.0005085107986815274f, 0.0007005504448898137f, 0.00036073889350518584f, 0.0006115508731454611f, 0.0003676053893286735f, 0.0004826509393751621f, 0.0006089555099606514f, 0.000472201791126281f, 0.00046564667718485f, 0.0005362716037780046f, 0.000628707988653332f, 0.0005557900294661522f, 0.0007003598148003221f, 0.0006233472377061844f, 0.0008999485289677978f, 0.0005299273179844022f, 0.00043739815009757876f, 0.0004633071948774159f, 0.0006625714595429599f, 0.0007134197512641549f, 0.0005727379466407001f, 0.00044864200754091144f, 0.0008503131102770567f, 0.0005729746771976352f, 0.0005428827716968954f, 0.00070681277429685f, 0.0005558838020078838f, 0.00033204784267582f, 0.0006974830757826567f, 0.0005673069972544909f, 0.0006340321851894259f, 0.00045747606782242656f, 0.000766296754591167f, 0.0008482856792397797f, 0.0004225021111778915f, 0.0006299738306552172f, 0.0005395026528276503f, 0.000846845970954746f, 0.0005781183717772365f, 0.0004454010631889105f, 0.0007778611034154892f, 0.0008892993209883571f, 0.0005292220157571137f, 0.00040135689778253436f, 0.0005973096704110503f, 0.0007034483714960515f, 0.00040276721119880676f, 0.0007296930416487157f, 0.0004560111847240478f, 0.0004430629778653383f, 0.0005365589749999344f, 0.0004418666649144143f, 0.0009279985097236931f, 0.0005670557147823274f, 0.0005574123933911324f, 0.0005599334253929555f, 0.0004993125912733376f, 0.0004951684386469424f, 0.000668602529913187f, 0.0009480239823460579f, 0.0005088111502118409f, 0.0005477636586874723f, 0.0005525199230760336f, 0.00047803466441109776f, 0.0007760883891023695f, 0.0008968134643509984f, 0.0005740924971178174f, 0.0005699411267414689f, 0.0005175035912543535f, 0.0006842481670901179f, 0.0005063222488388419f, 0.000660527206491679f, 0.0004897565813735127f, 0.0006957812001928687f, 0.00046601457870565355f, 0.0006532457191497087f, 0.0004470922867767513f, 0.00041691557271406054f, 0.0007370745879597962f, 0.000562359404284507f, 0.0005466999136842787f, 0.00040497948066331446f, 0.0006823643925599754f, 0.0007138187065720558f, 0.000510725483763963f, 0.0004698276170529425f, 0.0005421499954536557f, 0.0004754123219754547f, 0.0005662559415213764f, 0.0003322177508380264f, 0.00042020625551231205f, 0.00032082523102872074f, 0.0004586679569911212f, 0.00042170181404799223f, 0.0007887912215664983f, 0.0005205472116358578f, 0.0005766941467300057f, 0.0005273693241178989f, 0.0006447425694204867f, 0.0006895216065458953f, 0.0006542994524352252f, 0.00046847405610606074f, 0.0005346958059817553f, 0.0005946570308879018f, 0.0003896366397384554f, 0.0004817723238375038f, 0.000360020698281005f, 0.0004763046163134277f, 0.0005792377050966024f, 0.0006299837841652334f, 0.0007738615968264639f, 0.0005307755782268941f, 0.0004734297108370811f, 0.0005536870448850095f, 0.000606139306910336f, 0.0005232538096606731f, 0.0005274325958453119f, 0.000612334581092f, 0.0007267017499543726f, 0.0005711099947802722f, 0.00046477996511384845f, 0.0006636957405135036f, 0.0006893228273838758f, 0.0005219918675720692f, 0.00047620609984733164f, 0.0004367231740616262f, 0.00048317271284759045f, 0.0007268113549798727f, 0.0007503337110392749f, 0.0004847678355872631f, 0.0005020059179514647f, 0.0005680362810380757f, 0.00042208482045680285f, 0.00047995123895816505f, 0.0006866090116091073f, 0.0004916831385344267f, 0.0005368319107219577f, 0.0006537875742651522f, 0.0007188427844084799f, 0.0007739966385997832f, 0.000804734299890697f, 0.0005134194507263601f, 0.0006603721994906664f, 0.00065283989533782f, 0.0005095332744531333f, 0.000443223281763494f, 0.0007275644456967711f, 0.0005045299185439944f, 0.0004296469851396978f, 0.0005749402334913611f, 0.0005004762206226587f, 0.0004482132790144533f, 0.0005703040515072644f, 0.0009357274975627661f, 0.0005071176565252244f, 0.0006961542530916631f, 0.0003936910361517221f, 0.0005501799168996513f, 0.0007427362725138664f, 0.0003221681690774858f, 0.0005359069909900427f, 0.0006978055462241173f, 0.0006314777419902384f, 0.0006819716654717922f, 0.0006290534511208534f, 0.00040735717630013824f, 0.0006439090357162058f, 0.0005961090791970491f, 0.0006994940340518951f, 0.00042150673107244074f, 0.0007331861997954547f, 0.0006164631340652704f, 0.0005801352090202272f, 0.0007397975423373282f, 0.000482621428091079f, 0.0006110352114774287f, 0.00033581702155061066f, 0.0004955388139933348f, 0.00046730018220841885f, 0.0005613728426396847f, 0.000627932429779321f, 0.00041167993913404644f, 0.0006160445045679808f, 0.0004274762177374214f, 0.0006246190750971437f, 0.0005097896209917963f, 0.0005243580671958625f, 0.0004933574236929417f, 0.0004551712772808969f, 0.0005401720991358161f, 0.0005650540697388351f, 0.0007125320844352245f, 0.0005019246018491685f, 0.0005608726642094553f, 0.000506642390973866f, 0.0005597976851277053f, 0.00045670592226088047f, 0.0003739417879842222f, 0.0005347281694412231f, 0.0004651179478969425f, 0.0006600675405934453f, 0.0006307669100351632f, 0.0004881889617536217f, 0.00036367078428156674f, 0.0005986508913338184f, 0.000662972335703671f, 0.00047234620433300734f, 0.0003605170932132751f, 0.0005649629747495055f, 0.0004946131957694888f, 0.0004223961441311985f, 0.0006938808364793658f, 0.0007424770155921578f, 0.0005226747016422451f, 0.00048304456868208945f, 0.0007647295715287328f, 0.0006120704929344356f, 0.0005169578944332898f, 0.0006531107355840504f, 0.0005230772658251226f, 0.0005601546727120876f, 0.0006005329196341336f, 0.0007423019269481301f, 0.0005114246159791946f, 0.0006423686281777918f, 0.0005368153215385973f, 0.000640121113974601f, 0.0005381024093367159f, 0.000744086573831737f, 0.0007360662566497922f, 0.0006979468162171543f, 0.0005479395622387528f, 0.00044666926260106266f, 0.0007702145958319306f, 0.0005412326427176595f, 0.0005863936967216432f, 0.0006140053737908602f, 0.0004387464141473174f, 0.0006708042346872389f, 0.0003889789804816246f, 0.000503009301610291f, 0.00048288307152688503f, 0.000656565185636282f, 0.00042802124517038465f, 0.0006467772182077169f, 0.0006642000516876578f, 0.0006919777952134609f, 0.0009966614888980985f, 0.0005484864232130349f, 0.0006803826545365155f, 0.0006747340084984899f, 0.0005368194542825222f, 0.00038614351069554687f, 0.0005234214477241039f, 0.0007565876003354788f, 0.0006402828148566186f, 0.0003230077854823321f, 0.0006251613958738744f, 0.0004142260877415538f, 0.0004264929157216102f, 0.00039329423452727497f, 0.000533396378159523f, 0.00034328291076235473f, 0.0005364726530387998f, 0.0004889448173344135f, 0.0005115406820550561f, 0.0004634885408449918f, 0.0006550847901962698f, 0.0004179066454526037f, 0.000491624407004565f, 0.0005247464287094772f, 0.0005956868990324438f, 0.0005350584397092462f, 0.000442639400716871f, 0.0006529819220304489f, 0.0005369843565858901f, 0.000579659768845886f, 0.0004715105169452727f, 0.00043894536793231964f, 0.000503862916957587f, 0.00046114405267871916f, 0.0004340606683399528f, 0.00059911870630458f, 0.00047991552855819464f, 0.000468177895527333f, 0.000549682357814163f, 0.0003306011203676462f, 0.0007051463471725583f, 0.0007086865953169763f, 0.0005563352606259286f, 0.0005643683834932745f, 0.0004236311942804605f, 0.0007359867449849844f, 0.0005605285987257957f, 0.0006660777726210654f, 0.0005408358993008733f, 0.0006312985206022859f, 0.00042408122681081295f, 0.0005561531870625913f, 0.0006438115960918367f, 0.000551211996935308f, 0.0006434316164813936f, 0.0006013278034515679f, 0.000399556738557294f, 0.0003053500549867749f, 0.0005316801252774894f, 0.0005397257045842707f, 0.00038703004247508943f, 0.0005376271437853575f, 0.0006191622233018279f, 0.00048383590183220804f, 0.0005514291115105152f, 0.0006363666034303606f, 0.00032247701892629266f, 0.0006064809276722372f, 0.00041529128793627024f, 0.0005440576351247728f, 0.000519928929861635f, 0.0006959818420000374f, 0.000698955322150141f, 0.0007230366463772953f, 0.0004614490899257362f, 0.0006466382765211165f, 0.0006900702719576657f, 0.0006089926464483142f, 0.0005946487654000521f, 0.00041786374640651047f, 0.0004987722495570779f, 0.0006153862341307104f, 0.0004792171821463853f, 0.0005894600180909038f, 0.0004895305028185248f, 0.0006836399552412331f, 0.0006067418144084513f, 0.000647710810881108f, 0.000398895179387182f, 0.0006860787980258465f, 0.0007318160496652126f, 0.000452269654488191f, 0.0007540460210293531f, 0.0006447916384786367f, 0.0004515016044024378f, 0.00046005152398720384f, 0.0004570354940369725f, 0.000510024547111243f, 0.00045804810361005366f, 0.0005761312204413116f, 0.000443571072537452f, 0.0003250295121688396f, 0.0007174956845119596f, 0.0005015967763029039f, 0.0006955292192287743f, 0.00030977773712947965f, 0.0005636365967802703f, 0.0006907210336066782f, 0.000637043034657836f, 0.0006528951344080269f, 0.0005443257396109402f, 0.0004293672973290086f, 0.0006099605816416442f, 0.0005130536155775189f, 0.0005492583150044084f, 0.0004591160686686635f, 0.0006820269045419991f, 0.0006625273381359875f, 0.0003514974669087678f, 0.0007469948031939566f, 0.0005859025986865163f, 0.0004655924567487091f, 0.0006384202861227095f, 0.0005320097552612424f, 0.0006096915458329022f, 0.0005354494787752628f, 0.000692278437782079f, 0.0006647181580774486f, 0.000606117129791528f, 0.0007793145487084985f, 0.0005765719688497484f, 0.0010170156601816416f, 0.0007286968175321817f, 0.0005692908307537436f, 0.0003850662615150213f, 0.00042019507964141667f, 0.0003906116762664169f, 0.0005319105111993849f, 0.0005343710072338581f, 0.0005178379942663014f, 0.0003875004767905921f, 0.0007581316749565303f, 0.0005315501475706697f, 0.0006059298757463694f, 0.00041994694038294256f, 0.00036547804484143853f, 0.0007217975216917694f, 0.00046088482486084104f, 0.0003255570773035288f, 0.0005389675498008728f, 0.0005610003718174994f, 0.0007585552521049976f, 0.00038960151141509414f, 0.0004458788316696882f, 0.00039482623105868697f, 0.0006666388362646103f, 0.0007182395784184337f, 0.00046120068873278797f, 0.000534449762199074f, 0.0005679781315848231f, 0.0005313796573318541f, 0.0008196540293283761f, 0.0006322210538201034f, 0.00041555066127330065f, 0.0005333671579137444f, 0.0007839303580112755f, 0.00046099588507786393f, 0.0003290242748335004f, 0.0004530625883489847f, 0.0008237497531808913f, 0.00046328306780196726f, 0.00042833411134779453f, 0.0005169145879335701f, 0.00038867577677592635f, 0.0005722116911783814f, 0.0004698222619481385f, 0.0004943578969687223f, 0.0005760299973189831f, 0.000596891506575048f, 0.000615200842730701f, 0.00046171643771231174f, 0.0003713522746693343f, 0.0005983488517813385f, 0.00045436355867423117f, 0.0004990100278519094f, 0.0006941190222278237f, 0.0005752790020778775f, 0.0005052513442933559f, 0.00039532859227620065f, 0.0005291759734973311f, 0.0005037368973717093f, 0.0005829476285725832f, 0.0003350483893882483f, 0.0004309220821596682f, 0.0004621847765520215f, 0.00043732888298109174f, 0.00046053380356170237f, 0.000434496090747416f, 0.0006189309642650187f, 0.00043674971675500274f, 0.0005654000560753047f, 0.00047049400745891035f, 0.000738785311114043f, 0.0005507729365490377f, 0.00036865079891867936f, 0.0005982508300803602f, 0.0005139391869306564f, 0.0005557922413572669f, 0.000642044935375452f, 0.0006074345437809825f, 0.0007864913204684854f, 0.0005067678866907954f, 0.0005112225189805031f, 0.0006504801567643881f, 0.00038650454371236265f, 0.0005916687077842653f, 0.0006404656451195478f, 0.0004335398552939296f, 0.0007441259222105145f, 0.00045654390123672783f, 0.0008370084688067436f, 0.0006477118004113436f, 0.0007205053116194904f, 0.0008535599918104708f, 0.0007389715756289661f, 0.00047197926323860884f, 0.00035766951623372734f, 0.0005317598697729409f, 0.0006122920312918723f, 0.0006373535725288093f, 0.00036595904384739697f, 0.0006525340722873807f, 0.0004508173733484f, 0.0006241423543542624f, 0.0007038905168883502f, 0.0004821676993742585f, 0.0007189871394075453f, 0.0006671177688986063f, 0.0003774272627197206f, 0.0005418810760602355f, 0.00048645364586263895f, 0.0004512866144068539f, 0.00039643808850087225f, 0.00040807091863825917f, 0.0006995010771788657f, 0.0006311903125606477f, 0.0005132756195962429f, 0.00047133720363490283f, 0.0005945874727331102f, 0.0005687458906322718f, 0.000727615028154105f, 0.0006648713024333119f, 0.000672019028570503f, 0.00055695854825899f, 0.00040525084477849305f, 0.000541471759788692f, 0.00044762325705960393f, 0.0006715970230288804f, 0.0005885218270123005f, 0.0005865709390491247f, 0.0005213507101871073f, 0.000493070634547621f, 0.0004786681092809886f, 0.0005398759967647493f, 0.0005618516588583589f, 0.0005514026852324605f, 0.0004415424191392958f, 0.0005865910206921399f, 0.0006508560036309063f, 0.0005120720015838742f, 0.0006420658901333809f, 0.0004628774186130613f, 0.0006715795607306063f, 0.00040383049054071307f, 0.0008350650896318257f, 0.000507441523950547f, 0.0005940235569141805f, 0.0007474273443222046f, 0.0005670258542522788f, 0.0005358830094337463f, 0.000773447216488421f, 0.0005857767537236214f, 0.0007142610265873373f, 0.0006930791423656046f, 0.0007002035854384303f, 0.0005646754871122539f, 0.0008817524649202824f, 0.00058433145750314f, 0.00043298970558680594f, 0.0006056922138668597f, 0.0004568314179778099f, 0.0006273842882364988f, 0.000570405856706202f, 0.0004001275810878724f, 0.0006554024294018745f, 0.00048827260616235435f, 0.0006206737598404288f, 0.0005167517228983343f, 0.000406888488214463f, 0.0004702226142399013f, 0.0003893817774951458f, 0.0005002974066883326f, 0.0006114969728514552f, 0.00043081145850010216f, 0.0004159084346611053f, 0.0005668882513418794f, 0.0006408938206732273f, 0.0005049788160249591f, 0.0008025504066608846f, 0.0005055386573076248f, 0.0006406260072253644f, 0.0005277383024804294f, 0.000453546381322667f, 0.0004882297944277525f, 0.000529513054061681f, 0.0005185668705962598f, 0.0011189306387677789f, 0.0009443322196602821f, 0.0005148729542270303f, 0.0005461553810164332f, 0.0007645486039109528f, 0.0005930006736889482f, 0.0004983041435480118f, 0.0006873365491628647f, 0.00036516159889288247f, 0.0006227782578207552f, 0.0005675964057445526f, 0.0005272026173770428f, 0.0005698032910004258f, 0.0004936110926792026f, 0.0007316558039747179f, 0.000523124763276428f, 0.00045707737444899976f, 0.00034198499633930624f, 0.00033918785629794f, 0.0007180108805187047f, 0.0007605093996971846f, 0.0005162709858268499f, 0.0006054504192434251f, 0.0005825312691740692f, 0.0005979390698485076f, 0.0004217597597744316f, 0.0004945102846249938f, 0.0006319842068478465f, 0.0007049337145872414f, 0.0005013078916817904f, 0.0005723978974856436f, 0.0005235860007815063f, 0.0006706266431137919f, 0.0004935606848448515f, 0.0005281527410261333f, 0.0005783388623967767f, 0.0005384195246733725f, 0.0005761539214290679f, 0.0006469357758760452f, 0.0003977158630732447f, 0.0007944681565277278f, 0.0005612517124973238f, 0.000520259200129658f, 0.0007342405733652413f, 0.00039009281317703426f, 0.0007387546938844025f, 0.00045663671335205436f, 0.000609192589763552f, 0.0005883995909243822f, 0.0003949865058530122f, 0.0005953605868853629f, 0.0009284461848437786f, 0.0005755734164267778f, 0.00042404248961247504f, 0.0006435627583414316f, 0.00042400031816214323f, 0.0008052339544519782f, 0.0006115066935308278f, 0.00046521189506165683f, 0.0003879645955748856f, 0.0008845460833981633f, 0.000467391888378188f, 0.0004900926724076271f, 0.00048135605175048113f, 0.0007237719837576151f, 0.000590913463383913f, 0.0005564189632423222f, 0.000604518863838166f, 0.0004221103445161134f, 0.000778729619923979f, 0.0005419278750196099f, 0.00042780523654073477f, 0.0005794439348392189f, 0.0004533130268100649f, 0.0005418916698545218f, 0.000505122123286128f, 0.000508143799379468f, 0.0006260774098336697f, 0.0005323119112290442f, 0.00041241192957386374f, 0.0008277350571006536f, 0.0004882030771113932f, 0.0007143283728510141f, 0.0003856948751490563f, 0.0005324599333107471f, 0.00044975601485930383f, 0.0006642509251832962f, 0.0006399155827239156f, 0.00041321635944768786f, 0.0005311997374519706f, 0.0007086931727826595f, 0.0006448942003771663f, 0.0004309306968934834f, 0.0009111317922361195f, 0.000535306753590703f, 0.0007680500857532024f, 0.00046155371819622815f, 0.0005425438866950572f, 0.0005067208549007773f, 0.000529400771483779f, 0.0004223292926326394f, 0.0005981723079457879f, 0.0005274091381579638f, 0.0004643007996492088f, 0.0006593598518520594f, 0.0005245943320915103f, 0.0005057320231571794f, 0.0006358344689942896f, 0.000478171743452549f, 0.0006202738732099533f, 0.0009041634039022028f, 0.0005261902115307748f, 0.0005348523845896125f, 0.000747967918869108f, 0.0005386543925851583f, 0.000498298613820225f, 0.0004832996928598732f, 0.00032779373577795923f, 0.00046069282689131796f, 0.0005749943084083498f, 0.0003728069132193923f, 0.0005931556224822998f, 0.0006190146086737514f, 0.0007482802611775696f, 0.0007150933961383998f, 0.00040643778629601f, 0.000738296308554709f, 0.0004265823808964342f, 0.0007696593529544771f, 0.0007552960305474699f, 0.00043873587856069207f, 0.0005698311724700034f, 0.00048254727153107524f, 0.0005080492119304836f, 0.0006281316163949668f, 0.00045671401312574744f, 0.0008045928552746773f, 0.0004187962622381747f, 0.000518759130500257f, 0.0006813087966293097f, 0.00044423399958759546f, 0.0006066284840926528f, 0.00048278761096298695f, 0.0005533350049518049f, 0.00040968460962176323f, 0.0007109262514859438f, 0.0005531124770641327f, 0.0005431262543424964f, 0.0005917043308727443f, 0.0003644331591203809f, 0.0004929521819576621f, 0.0005555507959797978f, 0.0006879973807372153f, 0.0005472705233842134f, 0.0007602429832331836f, 0.0007108757854439318f, 0.0007234833901748061f, 0.0005868544685654342f, 0.0007407295051962137f, 0.0004876021121162921f, 0.0006469575455412269f, 0.0003407658950891346f, 0.0006515962886624038f, 0.0004646952438633889f, 0.0005712262354791164f, 0.0007882628706283867f, 0.0008272835984826088f, 0.0004667830071412027f, 0.0007861180929467082f, 0.0004441666242200881f, 0.0006486665224656463f, 0.0005349938874132931f, 0.0003373860090505332f, 0.0005802776431664824f, 0.0006054844707250595f, 0.0006506580975838006f, 0.0005343230441212654f, 0.0005475760553963482f, 0.0006638036575168371f, 0.000732475717086345f, 0.0007355419802479446f, 0.0006287319702096283f, 0.0005577240372076631f, 0.0005829193396493793f, 0.0008860821835696697f, 0.0006039747968316078f, 0.0006926501519046724f, 0.0003867605410050601f, 0.00047439889749512076f, 0.0005518600228242576f, 0.0006421884172596037f, 0.0005810689181089401f, 0.0006526997894980013f, 0.00042777397902682424f, 0.0007951144361868501f, 0.00037897139554843307f, 0.0009023955790325999f, 0.0007385225035250187f, 0.000695316179189831f, 0.000646729429718107f, 0.00048525971942581236f, 0.0005618511931970716f, 0.0008317356114275753f, 0.000678610522300005f, 0.0007716021500527859f, 0.00045841411338187754f, 0.0006550228572450578f, 0.0004282458103261888f, 0.0004997194046154618f, 0.0007598536321893334f, 0.0006177023751661181f, 0.000748635153286159f, 0.0006671485025435686f, 0.0005510037299245596f, 0.00046626621042378247f, 0.00042087965994141996f, 0.0006460908916778862f, 0.0006407913169823587f, 0.0005912733031436801f, 0.0006766545120626688f, 0.000503828632645309f, 0.0004900923813693225f, 0.00038123002741485834f, 0.0005207704962231219f, 0.000468769867438823f, 0.0005397010245360434f, 0.000615968368947506f, 0.0005979547277092934f, 0.0007853922434151173f, 0.0006731261382810771f, 0.0006251510349102318f, 0.00048564013559371233f, 0.0005646242061629891f, 0.0007434755680151284f, 0.0007820470491424203f, 0.0004768407961819321f, 0.0005037598893977702f, 0.0006741463439539075f, 0.0005720871267840266f, 0.00035867697442881763f, 0.0005093062645755708f, 0.0006729489541612566f, 0.00036304438253864646f, 0.0006325363647192717f, 0.0005646212957799435f, 0.0004906381946057081f, 0.0006091280956752598f, 0.0004949716967530549f, 0.0007656900561414659f, 0.00035499228397384286f, 0.000523344031535089f, 0.000459271454019472f, 0.0005272382986731827f, 0.00045334192691370845f, 0.0006526340148411691f, 0.0005147227784618735f, 0.00030536262784153223f, 0.00042990822112187743f, 0.00042971275979653f, 0.0007107876008376479f, 0.0008707111119292676f, 0.0006385506712831557f, 0.00036928398185409606f, 0.00037267233710736036f, 0.0005192739190533757f, 0.0005486257723532617f, 0.0005242832121439278f, 0.0007556477794423699f, 0.0005624113837257028f, 0.000463831820525229f, 0.00044823699863627553f, 0.00039541770820505917f, 0.0005719238542951643f, 0.0006552482373081148f, 0.00043432420352473855f, 0.0006521802861243486f, 0.0005783638334833086f, 0.0005014111520722508f, 0.00048209994565695524f, 0.0003347285382915288f, 0.0004558425862342119f, 0.0005832591559737921f, 0.00047839441685937345f, 0.0008729799883440137f, 0.00048224173951894045f, 0.0005544227315112948f, 0.0004045566893182695f, 0.00044976139906793833f, 0.0006697684875689447f, 0.0007451476994901896f, 0.0007060925709083676f, 0.0004410838591866195f, 0.00048622145550325513f, 0.00078882637899369f, 0.0005235036951489747f, 0.0005942957359366119f, 0.00044336565770208836f, 0.0004997289506718516f, 0.0004757059505209327f, 0.0004969362053088844f, 0.0005652318941429257f, 0.0005990728968754411f, 0.000571449170820415f, 0.000683434831444174f, 0.0004768578219227493f, 0.00047324589104391634f, 0.0005739880143664777f, 0.00031487815431319177f, 0.0005815583281219006f, 0.00043194115278311074f, 0.0005746499518863857f, 0.00033410690957680345f, 0.0005675940192304552f, 0.0007340169395320117f, 0.0004429804685059935f, 0.000558761355932802f, 0.0007431876147165895f, 0.00046585561358369887f, 0.0005819143843837082f, 0.00042939194827340543f, 0.0005779123748652637f, 0.0005448462325148284f, 0.00045248804963193834f, 0.0007431268459185958f, 0.0007846945081837475f, 0.0005220243474468589f, 0.0005719589535146952f, 0.0006028715870343149f, 0.0006600083434022963f, 0.0004997500218451023f, 0.000553074583876878f, 0.0005964926676824689f, 0.00045410983148030937f, 0.0005596147966571152f, 0.0007986644632183015f, 0.0007678603287786245f, 0.0005491111660376191f, 0.0006757820374332368f, 0.0005681731272488832f, 0.00047849651309661567f, 0.0008075105142779648f, 0.00039361920789815485f, 0.0007460966007784009f, 0.0007498699706047773f, 0.0005044450517743826f, 0.0006489380612038076f, 0.0005360551294870675f, 0.0005363812670111656f, 0.0004967242130078375f, 0.0004921631189063191f, 0.0006790264160372317f, 0.0005799799109809101f, 0.00034974043956026435f, 0.0006936559220775962f, 0.0002964393934234977f, 0.0007450327975675464f, 0.0007042222423478961f, 0.00039193234988488257f, 0.0008477210067212582f, 0.00040001043817028403f, 0.0004582564579322934f, 0.00039657746674492955f, 0.000787240220233798f, 0.0006283052498474717f, 0.00047681774594821036f, 0.00048338211490772665f, 0.0006846991600468755f, 0.0004024422960355878f, 0.0003402137372177094f, 0.0008193300454877317f, 0.00043897179421037436f, 0.0006328959134407341f, 0.00040512095438316464f, 0.0005763485096395016f, 0.0006107183289714158f, 0.0003308199520688504f, 0.0005653798580169678f, 0.0005081889103166759f, 0.0005520988488569856f, 0.0008222673204727471f, 0.00045690746628679335f, 0.000544036622159183f, 0.0006148125394247472f, 0.0004955181502737105f, 0.0006310594035312533f, 0.00044556151260621846f, 0.0003362318384461105f, 0.0004764242912642658f, 0.0006843495648354292f, 0.00048168632201850414f, 0.0005597365088760853f, 0.0006561966147273779f, 0.0004537436761893332f, 0.00040509714744985104f, 0.0005712993443012238f, 0.0005119495326653123f, 0.0006529407692141831f, 0.00033841884578578174f, 0.00036827989970333874f, 0.00037209875881671906f, 0.0004939656355418265f, 0.0006064827903173864f, 0.00044862975482828915f, 0.0004822074843104929f, 0.0005264380015432835f, 0.0005203112377785146f, 0.0004410050460137427f, 0.00036095152609050274f, 0.00048204444465227425f, 0.00048224537749774754f, 0.0006031420780345798f, 0.0006486040074378252f, 0.0005697739543393254f, 0.0005899554234929383f, 0.0005760769126936793f, 0.0006129732937552035f, 0.0005504739820025861f, 0.0008732213755138218f, 0.00041553095798008144f, 0.0004371585964690894f, 0.00038694535032846034f, 0.0005139295244589448f, 0.00047293855459429324f, 0.0006737840012647212f, 0.0007646835874766111f, 0.0006066607311367989f, 0.0004365722415968776f, 0.0005457198130898178f, 0.0006090260576456785f, 0.000552882207557559f, 0.0005592089728452265f, 0.0004940999206155539f, 0.0006197484326548874f, 0.00044507437269203365f, 0.000750395527575165f, 0.00046313824714161456f, 0.0007177304942160845f, 0.00029501845710910857f, 0.000584944908041507f, 0.0005544007290154696f, 0.00047828187234699726f, 0.0003601267235353589f, 0.0008614205289632082f, 0.000754138920456171f, 0.000840300228446722f, 0.0005177892162464559f, 0.0005031461478210986f, 0.00037720793625339866f, 0.0006323226843960583f, 0.0004145941638853401f, 0.0006821015267632902f, 0.0007828098605386913f, 0.0006193704903125763f, 0.000545808463357389f, 0.0004334542900323868f, 0.0004396428121253848f, 0.0009853923693299294f, 0.0003940598980989307f, 0.0010423505445942283f, 0.0007321598823182285f, 0.0008184140315279365f, 0.0003359465626999736f, 0.000613731041084975f, 0.0004069299320690334f, 0.0008922223933041096f, 0.000583118584472686f, 0.000689083943143487f, 0.0003155867743771523f, 0.000563574954867363f, 0.0006751894252374768f, 0.00046834402019158006f, 0.0005278624594211578f, 0.000629120972007513f, 0.0007157056825235486f, 0.0005482526030391455f, 0.0007231900235638022f, 0.0006100883474573493f, 0.0005347749684005976f, 0.0008538697147741914f, 0.0004430426633916795f, 0.0005023193662054837f, 0.0005030807806178927f, 0.0004861333000008017f, 0.0009274131152778864f, 0.001017440459690988f, 0.0006990613183006644f, 0.0006864944007247686f, 0.0005310421693138778f, 0.0005609109648503363f, 0.0006812937208451331f, 0.0005843106773681939f, 0.0005443927948363125f, 0.0005220858147367835f, 0.0004733684763778001f, 0.0007041132776066661f, 0.0007127171847969294f, 0.0004885426606051624f, 0.00042646407382562757f, 0.0005644942284561694f, 0.0005536294775083661f, 0.0005126498872414231f, 0.0005457669612951577f, 0.00042437019874341786f, 0.00046314721112139523f, 0.0006085800123400986f, 0.0007970035658217967f, 0.0007797158905304968f, 0.0006332168122753501f, 0.0006768031162209809f, 0.0006274521583691239f, 0.0006223453092388809f, 0.0005462173139676452f, 0.0007346422644332051f, 0.000477663183119148f, 0.0006018308340571821f, 0.0008615811238996685f, 0.0008172456291504204f, 0.000623565458226949f, 0.0006246185512281954f, 0.000740121933631599f, 0.0005457348888739944f, 0.00056740507716313f, 0.0006549796089529991f, 0.0004120386438444257f, 0.0005398097564466298f, 0.00038720425800420344f, 0.0005119139095768332f, 0.0005130431964062154f, 0.0007403622730635107f, 0.00039127212949097157f, 0.000618881022091955f, 0.000767101941164583f, 0.0004736812552437186f, 0.000548945099581033f, 0.0005978888366371393f, 0.0006603928632102907f, 0.00041550214518792927f, 0.0005723187350668013f, 0.0005690079415217042f, 0.000620571430772543f, 0.0004939757636748254f, 0.0005451839533634484f, 0.000664707156829536f, 0.0005162713350728154f, 0.0005063348799012601f, 0.00041057620546780527f, 0.0006080721504986286f, 0.000780085742007941f, 0.0004243594012223184f, 0.0006298834923654795f, 0.0010210474720224738f, 0.0005022365367040038f, 0.0005204968620091677f, 0.0005043905111961067f, 0.0007387531222775578f, 0.00048233376583084464f, 0.0007270289934240282f, 0.000477981026051566f, 0.0003985422954428941f, 0.0005652471445500851f, 0.0007296096300706267f, 0.0005541680147871375f, 0.00034495029831305146f, 0.00046402044245041907f, 0.000867954920977354f, 0.0008842473034746945f, 0.0005783395026810467f, 0.0005539077683351934f, 0.0006147994427010417f, 0.0003510656242724508f, 0.000585402362048626f, 0.0005564514431171119f, 0.000521584355738014f, 0.00042973991367034614f, 0.0005161407752893865f, 0.0006197996553964913f, 0.0005968806799501181f, 0.0005673174746334553f, 0.00044635406811721623f, 0.0002777199842967093f, 0.0003995360457338393f, 0.001005203346721828f, 0.0005733223515562713f, 0.0007981821545399725f, 0.00040974648436531425f, 0.000543653906788677f, 0.00038760690949857235f, 0.0005571449873968959f, 0.0004272674268577248f, 0.0005215072887949646f, 0.000519906054250896f, 0.0007129125879146159f, 0.0004877568280790001f, 0.0005484435241669416f, 0.00042369129369035363f, 0.000660913297906518f, 0.00042440005927346647f, 0.00050091597950086f, 0.00040489333332516253f, 0.0005891763139516115f, 0.0007115068729035556f, 0.0005385419935919344f, 0.0006202905788086355f, 0.0005688930978067219f, 0.0005370159633457661f, 0.0006139907636679709f, 0.000626922759693116f, 0.0004583871050272137f, 0.0006907851784490049f, 0.0005669497768394649f, 0.000707784725818783f, 0.0006024110480211675f, 0.0005394446779973805f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #170 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007047539111226797f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #171 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.6582444004598074e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #172 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #173 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #174 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #175 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #176 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #177 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #178 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #179 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #180 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #181 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #182 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #183 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #184 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #185 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #186 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #187 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #188 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #189 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #190 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #191 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #192 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #193 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #194 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #195 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #196 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #197 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #198 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #199 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #200 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #201 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #202 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #203 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #204 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #205 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #206 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #207 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_scratch2_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  input_1_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 128, 128), AI_STRIDE_INIT(4, 1, 1, 3, 384),
  1, &input_1_output_array, &input_1_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 128, 128), AI_STRIDE_INIT(4, 1, 1, 3, 384),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 64, 64), AI_STRIDE_INIT(4, 1, 1, 8, 512),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 64, 64), AI_STRIDE_INIT(4, 1, 1, 48, 3072),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 32, 32), AI_STRIDE_INIT(4, 1, 1, 8, 256),
  1, &eltwise_12_output_array, &eltwise_12_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 1, 1, 48, 768),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &eltwise_20_output_array, &eltwise_20_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 16, 16), AI_STRIDE_INIT(4, 1, 1, 16, 256),
  1, &eltwise_24_output_array, &eltwise_24_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 8, 8), AI_STRIDE_INIT(4, 1, 1, 96, 768),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_29_output_array, &conv2d_29_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_30_output_array, &conv2d_30_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_31_output_array, &conv2d_31_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &eltwise_32_output_array, &eltwise_32_output_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_34_output_array, &conv2d_34_output_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_output, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_35_output_array, &conv2d_35_output_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_36_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &eltwise_36_output_array, &eltwise_36_output_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_37_output_array, &conv2d_37_output_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_38_output_array, &conv2d_38_output_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_40_output, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 8, 8), AI_STRIDE_INIT(4, 1, 1, 24, 192),
  1, &eltwise_40_output_array, &eltwise_40_output_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_41_output_array, &conv2d_41_output_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_42_output_array, &conv2d_42_output_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &conv2d_43_output_array, &conv2d_43_output_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_output, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_44_output_array, &conv2d_44_output_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_45_output_array, &conv2d_45_output_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_output, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &conv2d_46_output_array, &conv2d_46_output_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_output, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &eltwise_47_output_array, &eltwise_47_output_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_48_output_array, &conv2d_48_output_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_49_output_array, &conv2d_49_output_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_output, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &conv2d_50_output_array, &conv2d_50_output_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_51_output, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 8, 8), AI_STRIDE_INIT(4, 1, 1, 32, 256),
  1, &eltwise_51_output_array, &eltwise_51_output_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_output, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_52_output_array, &conv2d_52_output_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_output, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 4, 4), AI_STRIDE_INIT(4, 1, 1, 192, 768),
  1, &conv2d_54_output_array, &conv2d_54_output_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_output, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &conv2d_55_output_array, &conv2d_55_output_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_output, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_56_output_array, &conv2d_56_output_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_output, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_57_output_array, &conv2d_57_output_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_output, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &conv2d_58_output_array, &conv2d_58_output_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_59_output, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &eltwise_59_output_array, &eltwise_59_output_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_output, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_60_output_array, &conv2d_60_output_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_output, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_61_output_array, &conv2d_61_output_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_output, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &conv2d_62_output_array, &conv2d_62_output_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_63_output, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 4, 4), AI_STRIDE_INIT(4, 1, 1, 56, 224),
  1, &eltwise_63_output_array, &eltwise_63_output_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_output, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_64_output_array, &conv2d_64_output_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_output, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_65_output_array, &conv2d_65_output_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_output, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 4, 4), AI_STRIDE_INIT(4, 1, 1, 112, 448),
  1, &conv2d_66_output_array, &conv2d_66_output_intq)

/* Tensor #63 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_output, AI_STATIC,
  63, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1280, 1280),
  1, &conv2d_67_output_array, &conv2d_67_output_intq)

/* Tensor #64 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_output, AI_STATIC,
  64, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &dense_69_output_array, &dense_69_output_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_fmt_output, AI_STATIC,
  65, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &dense_69_fmt_output_array, NULL)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  nl_70_output, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &nl_70_output_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  nl_70_fmt_output, AI_STATIC,
  67, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2, 2),
  1, &nl_70_fmt_output_array, &nl_70_fmt_output_intq)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 8), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  88, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  90, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  92, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  94, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  95, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  100, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  104, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  106, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  110, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_29_weights_array, &conv2d_29_weights_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_29_bias_array, &conv2d_29_bias_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_30_weights_array, &conv2d_30_weights_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_30_bias_array, &conv2d_30_bias_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  114, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_31_weights_array, &conv2d_31_weights_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_31_bias_array, &conv2d_31_bias_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  116, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  118, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_34_weights_array, &conv2d_34_weights_intq)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_34_bias_array, &conv2d_34_bias_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_weights, AI_STATIC,
  120, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_35_weights_array, &conv2d_35_weights_intq)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_bias, AI_STATIC,
  121, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_35_bias_array, &conv2d_35_bias_intq)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  122, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_37_weights_array, &conv2d_37_weights_intq)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_37_bias_array, &conv2d_37_bias_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  124, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_38_weights_array, &conv2d_38_weights_intq)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  125, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_38_bias_array, &conv2d_38_bias_intq)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  126, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_39_weights_array, &conv2d_39_weights_intq)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  128, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_41_weights_array, &conv2d_41_weights_intq)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  129, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_41_bias_array, &conv2d_41_bias_intq)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  130, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_42_weights_array, &conv2d_42_weights_intq)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  131, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_42_bias_array, &conv2d_42_bias_intq)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  132, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 32), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_43_weights_array, &conv2d_43_weights_intq)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  133, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_43_bias_array, &conv2d_43_bias_intq)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_weights, AI_STATIC,
  134, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_44_weights_array, &conv2d_44_weights_intq)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_bias, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_44_bias_array, &conv2d_44_bias_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_weights, AI_STATIC,
  136, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_45_weights_array, &conv2d_45_weights_intq)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_bias, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_45_bias_array, &conv2d_45_bias_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_weights, AI_STATIC,
  138, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_46_weights_array, &conv2d_46_weights_intq)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_bias, AI_STATIC,
  139, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_46_bias_array, &conv2d_46_bias_intq)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  140, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_48_weights_array, &conv2d_48_weights_intq)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_48_bias_array, &conv2d_48_bias_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  142, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_49_weights_array, &conv2d_49_weights_intq)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  143, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_49_bias_array, &conv2d_49_bias_intq)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_weights, AI_STATIC,
  144, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_50_weights_array, &conv2d_50_weights_intq)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_bias, AI_STATIC,
  145, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_50_bias_array, &conv2d_50_bias_intq)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_weights, AI_STATIC,
  146, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_52_weights_array, &conv2d_52_weights_intq)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_bias, AI_STATIC,
  147, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_52_bias_array, &conv2d_52_bias_intq)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_weights, AI_STATIC,
  148, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_54_weights_array, &conv2d_54_weights_intq)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_bias, AI_STATIC,
  149, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_54_bias_array, &conv2d_54_bias_intq)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_weights, AI_STATIC,
  150, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 56), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_55_weights_array, &conv2d_55_weights_intq)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_bias, AI_STATIC,
  151, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_55_bias_array, &conv2d_55_bias_intq)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_weights, AI_STATIC,
  152, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_56_weights_array, &conv2d_56_weights_intq)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_bias, AI_STATIC,
  153, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_56_bias_array, &conv2d_56_bias_intq)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_weights, AI_STATIC,
  154, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_57_weights_array, &conv2d_57_weights_intq)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_bias, AI_STATIC,
  155, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_57_bias_array, &conv2d_57_bias_intq)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_weights, AI_STATIC,
  156, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_58_weights_array, &conv2d_58_weights_intq)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_bias, AI_STATIC,
  157, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_58_bias_array, &conv2d_58_bias_intq)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_weights, AI_STATIC,
  158, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_60_weights_array, &conv2d_60_weights_intq)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_bias, AI_STATIC,
  159, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_60_bias_array, &conv2d_60_bias_intq)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_weights, AI_STATIC,
  160, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_61_weights_array, &conv2d_61_weights_intq)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_bias, AI_STATIC,
  161, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_61_bias_array, &conv2d_61_bias_intq)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_weights, AI_STATIC,
  162, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_62_weights_array, &conv2d_62_weights_intq)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_bias, AI_STATIC,
  163, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_62_bias_array, &conv2d_62_bias_intq)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_weights, AI_STATIC,
  164, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_64_weights_array, &conv2d_64_weights_intq)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_bias, AI_STATIC,
  165, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_64_bias_array, &conv2d_64_bias_intq)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_weights, AI_STATIC,
  166, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_65_weights_array, &conv2d_65_weights_intq)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_bias, AI_STATIC,
  167, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_65_bias_array, &conv2d_65_bias_intq)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_weights, AI_STATIC,
  168, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 112), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_66_weights_array, &conv2d_66_weights_intq)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_bias, AI_STATIC,
  169, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &conv2d_66_bias_array, &conv2d_66_bias_intq)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_weights, AI_STATIC,
  170, 0x1,
  AI_SHAPE_INIT(4, 112, 1, 1, 1280), AI_STRIDE_INIT(4, 1, 112, 112, 112),
  1, &conv2d_67_weights_array, &conv2d_67_weights_intq)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_bias, AI_STATIC,
  171, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &conv2d_67_bias_array, &conv2d_67_bias_intq)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_weights, AI_STATIC,
  172, 0x1,
  AI_SHAPE_INIT(4, 1280, 2, 1, 1), AI_STRIDE_INIT(4, 1, 1280, 2560, 2560),
  1, &dense_69_weights_array, &dense_69_weights_intq)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_bias, AI_STATIC,
  173, 0x1,
  AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &dense_69_bias_array, &dense_69_bias_intq)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  174, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  175, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  176, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  177, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 64, 64), AI_STRIDE_INIT(4, 1, 1, 16, 1024),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_intq)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  178, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 1, 1, 144, 144),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  179, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  180, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 64, 64), AI_STRIDE_INIT(4, 1, 1, 48, 3072),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  181, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch1, AI_STATIC,
  182, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_7_scratch1_array, &conv2d_7_scratch1_intq)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  183, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch1, AI_STATIC,
  185, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_9_scratch1_array, &conv2d_9_scratch1_intq)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch1, AI_STATIC,
  187, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_10_scratch1_array, &conv2d_10_scratch1_intq)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  188, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  189, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch1, AI_STATIC,
  190, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 32, 32), AI_STRIDE_INIT(4, 1, 1, 48, 1536),
  1, &conv2d_13_scratch1_array, &conv2d_13_scratch1_intq)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  191, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch1, AI_STATIC,
  192, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 16, 16), AI_STRIDE_INIT(4, 1, 1, 48, 768),
  1, &conv2d_15_scratch1_array, &conv2d_15_scratch1_intq)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  193, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch1, AI_STATIC,
  195, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_17_scratch1_array, &conv2d_17_scratch1_intq)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch1, AI_STATIC,
  197, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_18_scratch1_array, &conv2d_18_scratch1_intq)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  198, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  199, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch1, AI_STATIC,
  200, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_21_scratch1_array, &conv2d_21_scratch1_intq)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch1, AI_STATIC,
  202, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_22_scratch1_array, &conv2d_22_scratch1_intq)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  203, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch1, AI_STATIC,
  205, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 16, 16), AI_STRIDE_INIT(4, 1, 1, 96, 1536),
  1, &conv2d_25_scratch1_array, &conv2d_25_scratch1_intq)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch1, AI_STATIC,
  207, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 8, 8), AI_STRIDE_INIT(4, 1, 1, 96, 768),
  1, &conv2d_27_scratch1_array, &conv2d_27_scratch1_intq)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  208, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  209, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch1, AI_STATIC,
  210, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_29_scratch1_array, &conv2d_29_scratch1_intq)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  211, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch1, AI_STATIC,
  212, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_30_scratch1_array, &conv2d_30_scratch1_intq)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  213, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch1, AI_STATIC,
  215, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_33_scratch1_array, &conv2d_33_scratch1_intq)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch1, AI_STATIC,
  217, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_34_scratch1_array, &conv2d_34_scratch1_intq)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_scratch0, AI_STATIC,
  218, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_35_scratch0_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  219, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch1, AI_STATIC,
  220, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_37_scratch1_array, &conv2d_37_scratch1_intq)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch1, AI_STATIC,
  222, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_38_scratch1_array, &conv2d_38_scratch1_intq)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  223, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  224, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch1, AI_STATIC,
  225, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_41_scratch1_array, &conv2d_41_scratch1_intq)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch1, AI_STATIC,
  227, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 8, 8), AI_STRIDE_INIT(4, 1, 1, 144, 1152),
  1, &conv2d_42_scratch1_array, &conv2d_42_scratch1_intq)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  228, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch0, AI_STATIC,
  229, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_44_scratch0_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch1, AI_STATIC,
  230, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_44_scratch1_array, &conv2d_44_scratch1_intq)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch0, AI_STATIC,
  231, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_45_scratch0_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch1, AI_STATIC,
  232, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_45_scratch1_array, &conv2d_45_scratch1_intq)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_scratch0, AI_STATIC,
  233, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_46_scratch0_array, NULL)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch1, AI_STATIC,
  235, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_48_scratch1_array, &conv2d_48_scratch1_intq)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch1, AI_STATIC,
  237, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_49_scratch1_array, &conv2d_49_scratch1_intq)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_scratch0, AI_STATIC,
  238, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_50_scratch0_array, NULL)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch0, AI_STATIC,
  239, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_52_scratch0_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch1, AI_STATIC,
  240, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 8, 8), AI_STRIDE_INIT(4, 1, 1, 192, 1536),
  1, &conv2d_52_scratch1_array, &conv2d_52_scratch1_intq)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch0, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_54_scratch0_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch1, AI_STATIC,
  242, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 4, 4), AI_STRIDE_INIT(4, 1, 1, 192, 768),
  1, &conv2d_54_scratch1_array, &conv2d_54_scratch1_intq)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_scratch0, AI_STATIC,
  243, 0x0,
  AI_SHAPE_INIT(4, 1, 1328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1328, 1328),
  1, &conv2d_55_scratch0_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  244, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch1, AI_STATIC,
  245, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_56_scratch1_array, &conv2d_56_scratch1_intq)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch0, AI_STATIC,
  246, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_57_scratch0_array, NULL)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch1, AI_STATIC,
  247, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_57_scratch1_array, &conv2d_57_scratch1_intq)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_scratch0, AI_STATIC,
  248, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_58_scratch0_array, NULL)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch0, AI_STATIC,
  249, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_60_scratch0_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch1, AI_STATIC,
  250, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_60_scratch1_array, &conv2d_60_scratch1_intq)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch0, AI_STATIC,
  251, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_61_scratch0_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch1, AI_STATIC,
  252, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_61_scratch1_array, &conv2d_61_scratch1_intq)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_scratch0, AI_STATIC,
  253, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_62_scratch0_array, NULL)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch0, AI_STATIC,
  254, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_64_scratch0_array, NULL)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch1, AI_STATIC,
  255, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_64_scratch1_array, &conv2d_64_scratch1_intq)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch0, AI_STATIC,
  256, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_65_scratch0_array, NULL)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch1, AI_STATIC,
  257, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 4, 4), AI_STRIDE_INIT(4, 1, 1, 336, 1344),
  1, &conv2d_65_scratch1_array, &conv2d_65_scratch1_intq)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_scratch0, AI_STATIC,
  258, 0x0,
  AI_SHAPE_INIT(4, 1, 2464, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2464, 2464),
  1, &conv2d_66_scratch0_array, NULL)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch0, AI_STATIC,
  259, 0x0,
  AI_SHAPE_INIT(4, 1, 13248, 1, 1), AI_STRIDE_INIT(4, 1, 1, 13248, 13248),
  1, &conv2d_67_scratch0_array, NULL)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch1, AI_STATIC,
  260, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 4, 4), AI_STRIDE_INIT(4, 1, 1, 1280, 5120),
  1, &conv2d_67_scratch1_array, &conv2d_67_scratch1_intq)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch2, AI_STATIC,
  261, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 4, 4), AI_STRIDE_INIT(4, 1, 1, 1280, 5120),
  1, &conv2d_67_scratch2_array, &conv2d_67_scratch2_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &input_1_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  conversion_0_layer, 0,
  NL_TYPE, 0x0, NULL,
  nl, node_convert_integer,
  &conversion_0_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_2_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_2_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conversion_0_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_2_weights, &conv2d_2_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_2_scratch0, &conv2d_2_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_2_layer, 2,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_2_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_3_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_3_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_2_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_3_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_3_weights, &conv2d_3_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_3_scratch0, &conv2d_3_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_3_layer, 3,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_3_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_4_layer, AI_STATIC, 
  .groups = 16, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
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
  conv2d, forward_conv2d_integer_SSSA_ch,
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
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_5_scratch0, &conv2d_5_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_5_layer, 5,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_5_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_7_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_7_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_5_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_7_weights, &conv2d_7_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_7_scratch0, &conv2d_7_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_7_layer, 7,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_7_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_8_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_8_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_7_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_output, &conv2d_8_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_8_weights, &conv2d_8_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_8_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_8_layer, 8,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
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
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_9_scratch0, &conv2d_9_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_9_layer, 9,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_9_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_10_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_10_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_9_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_10_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_10_weights, &conv2d_10_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_10_scratch0, &conv2d_10_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_10_layer, 10,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_10_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_11_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
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
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_11_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_12_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_12_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_8_output, &conv2d_11_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_12_layer, 12,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_12_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_13_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_13_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_12_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_13_weights, &conv2d_13_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_13_scratch0, &conv2d_13_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_13_layer, 13,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_13_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_15_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_15_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_13_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_15_weights, &conv2d_15_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_15_scratch0, &conv2d_15_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 15,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_15_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC, 
  .groups = 48, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_16_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &conv2d_16_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_16_weights, &conv2d_16_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_16_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_16_layer, 16,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
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
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_17_scratch0, &conv2d_17_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_17_layer, 17,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_17_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_18_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_18_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_17_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_18_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_18_weights, &conv2d_18_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_18_scratch0, &conv2d_18_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_18_layer, 18,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_18_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_19_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
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
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_19_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_20_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_20_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_16_output, &conv2d_19_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_20_output, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_20_layer, 20,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_20_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_21_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_21_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_20_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_21_weights, &conv2d_21_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_21_scratch0, &conv2d_21_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_21_layer, 21,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_21_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_22_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_22_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_21_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_22_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_22_weights, &conv2d_22_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_22_scratch0, &conv2d_22_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_22_layer, 22,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_22_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_23_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
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
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_23_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_24_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_24_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_20_output, &conv2d_23_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_24_layer, 24,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_24_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_25_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_25_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_24_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_25_weights, &conv2d_25_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_25_scratch0, &conv2d_25_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_25_layer, 25,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_25_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_27_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_27_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_25_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_27_weights, &conv2d_27_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_27_scratch0, &conv2d_27_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_27_layer, 27,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_27_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_28_layer, AI_STATIC, 
  .groups = 96, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_28_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_27_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_28_output, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_28_weights, &conv2d_28_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_28_layer, 28,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_28_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_29_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_29_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_28_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_29_weights, &conv2d_29_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_29_scratch0, &conv2d_29_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_29_layer, 29,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_29_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_30_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_30_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_29_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_30_weights, &conv2d_30_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_30_scratch0, &conv2d_30_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_30_layer, 30,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_30_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_31_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_31_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_30_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_31_weights, &conv2d_31_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_31_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_31_layer, 31,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_31_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_32_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_32_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_28_output, &conv2d_31_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_32_output, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_32_layer, 32,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_32_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_33_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_33_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_32_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_33_weights, &conv2d_33_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_33_scratch0, &conv2d_33_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_33_layer, 33,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_33_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_34_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_34_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_33_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_34_weights, &conv2d_34_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_34_scratch0, &conv2d_34_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_34_layer, 34,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_34_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_35_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_35_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_34_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_35_weights, &conv2d_35_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_35_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_35_layer, 35,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_35_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_36_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_36_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_32_output, &conv2d_35_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_36_output, &eltwise_36_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_36_layer, 36,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_36_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_37_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_37_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_36_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_37_weights, &conv2d_37_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_37_scratch0, &conv2d_37_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_37_layer, 37,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_37_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_38_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_38_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_37_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_38_weights, &conv2d_38_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_38_scratch0, &conv2d_38_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_38_layer, 38,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_38_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_39_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_39_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_38_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_39_weights, &conv2d_39_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_39_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_39_layer, 39,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_39_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_40_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_40_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_36_output, &conv2d_39_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_40_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_40_layer, 40,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_40_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_41_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_41_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_40_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_41_weights, &conv2d_41_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_41_scratch0, &conv2d_41_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_41_layer, 41,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_41_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_42_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_42_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_41_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_42_weights, &conv2d_42_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_42_scratch0, &conv2d_42_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_42_layer, 42,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_42_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_43_layer, AI_STATIC, 
  .groups = 144, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_43_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_42_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_43_output, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_43_weights, &conv2d_43_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_43_layer, 43,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_43_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_44_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_44_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_43_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_44_weights, &conv2d_44_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_44_scratch0, &conv2d_44_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_44_layer, 44,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_44_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_45_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_45_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_44_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_45_weights, &conv2d_45_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_45_scratch0, &conv2d_45_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_45_layer, 45,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_45_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_46_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_46_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_45_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_46_weights, &conv2d_46_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_46_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_46_layer, 46,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_46_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_47_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_47_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_43_output, &conv2d_46_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_47_output, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_47_layer, 47,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_47_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_48_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_48_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_47_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_48_weights, &conv2d_48_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_48_scratch0, &conv2d_48_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_48_layer, 48,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_48_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_49_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_49_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_48_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_49_weights, &conv2d_49_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_49_scratch0, &conv2d_49_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_49_layer, 49,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_49_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_50_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_50_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_49_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_50_weights, &conv2d_50_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_50_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_50_layer, 50,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_50_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_51_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_51_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_47_output, &conv2d_50_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_51_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_51_layer, 51,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_51_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_52_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_52_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_51_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_52_weights, &conv2d_52_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_52_scratch0, &conv2d_52_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_52_layer, 52,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_52_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_54_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_54_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_52_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_54_weights, &conv2d_54_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_54_scratch0, &conv2d_54_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_54_layer, 54,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_54_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_55_layer, AI_STATIC, 
  .groups = 192, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(2, 2), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_55_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_54_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_55_output, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_55_weights, &conv2d_55_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_55_layer, 55,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_55_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_56_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_56_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_55_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_56_weights, &conv2d_56_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_56_scratch0, &conv2d_56_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_56_layer, 56,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_56_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_57_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_56_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_57_weights, &conv2d_57_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_57_scratch0, &conv2d_57_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_57_layer, 57,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_57_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_58_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_58_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_58_weights, &conv2d_58_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_58_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_58_layer, 58,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_58_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_59_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_59_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_55_output, &conv2d_58_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_59_output, &eltwise_59_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_59_layer, 59,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_59_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_60_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_60_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_59_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_60_weights, &conv2d_60_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_60_scratch0, &conv2d_60_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_60_layer, 60,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_60_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_61_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_61_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_60_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_61_weights, &conv2d_61_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_61_scratch0, &conv2d_61_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_61_layer, 61,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_61_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_62_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_62_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_62_weights, &conv2d_62_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_62_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_62_layer, 62,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_62_chain,
  &AI_NET_OBJ_INSTANCE, &eltwise_63_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  eltwise_63_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &eltwise_59_output, &conv2d_62_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_63_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  eltwise_63_layer, 63,
  ELTWISE_INTEGER_TYPE, 0x0, NULL,
  eltwise_integer, forward_eltwise_integer_INT8,
  &eltwise_63_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_64_layer, AI_STATIC, 
  .operation = ai_sum, 
  .buffer_operation = ai_sum_buffer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_64_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &eltwise_63_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_64_weights, &conv2d_64_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_64_scratch0, &conv2d_64_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_64_layer, 64,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_64_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_65_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_65_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_64_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_65_weights, &conv2d_65_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &conv2d_65_scratch0, &conv2d_65_scratch1)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_65_layer, 65,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_65_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_66_layer, AI_STATIC, 
  .groups = 336, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 1, 1, 1, 1), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_66_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_65_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_66_weights, &conv2d_66_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_66_layer, 66,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_66_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_67_layer, AI_STATIC, 
  .groups = 1, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  conv2d_67_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_66_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_67_weights, &conv2d_67_bias, NULL),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 3, &conv2d_67_scratch0, &conv2d_67_scratch1, &conv2d_67_scratch2)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_67_layer, 68,
  OPTIMIZED_CONV2D_TYPE, 0x0, NULL,
  conv2d_nl_pool, forward_conv2d_nl_pool_integer_SSSA_ch,
  &conv2d_67_chain,
  &AI_NET_OBJ_INSTANCE, &dense_69_layer, AI_STATIC, 
  .groups = 1, 
  .nl_params = NULL, 
  .nl_func = NULL, 
  .filter_stride = AI_SHAPE_2D_INIT(1, 1), 
  .dilation = AI_SHAPE_2D_INIT(1, 1), 
  .filter_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_size = AI_SHAPE_2D_INIT(4, 4), 
  .pool_stride = AI_SHAPE_2D_INIT(4, 4), 
  .pool_pad = AI_SHAPE_INIT(4, 0, 0, 0, 0), 
  .pool_func = pool_func_ap_array_integer_INT8, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_69_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_67_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_69_weights, &dense_69_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_69_layer, 69,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_69_chain,
  &AI_NET_OBJ_INSTANCE, &dense_69_fmt_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_69_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_69_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_69_fmt_layer, 69,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_69_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_70_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_69_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_70_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_70_layer, 70,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_70_chain,
  &AI_NET_OBJ_INSTANCE, &nl_70_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_70_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_70_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_70_fmt_layer, 70,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_70_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_70_fmt_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 412776, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 201824, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &input_1_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_70_fmt_output),
  &conversion_0_layer, 0, NULL)



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
    input_1_output_array.data = AI_PTR(activations + 135184);
    input_1_output_array.data_start = AI_PTR(activations + 135184);
    conversion_0_output_array.data = AI_PTR(activations + 86032);
    conversion_0_output_array.data_start = AI_PTR(activations + 86032);
    conv2d_2_output_array.data = AI_PTR(activations + 135184);
    conv2d_2_output_array.data_start = AI_PTR(activations + 135184);
    conv2d_3_output_array.data = AI_PTR(activations + 69648);
    conv2d_3_output_array.data_start = AI_PTR(activations + 69648);
    conv2d_4_output_array.data = AI_PTR(activations + 168544);
    conv2d_4_output_array.data_start = AI_PTR(activations + 168544);
    conv2d_5_output_array.data = AI_PTR(activations + 1584);
    conv2d_5_output_array.data_start = AI_PTR(activations + 1584);
    conv2d_7_output_array.data = AI_PTR(activations + 0);
    conv2d_7_output_array.data_start = AI_PTR(activations + 0);
    conv2d_8_output_array.data = AI_PTR(activations + 49424);
    conv2d_8_output_array.data_start = AI_PTR(activations + 49424);
    conv2d_9_output_array.data = AI_PTR(activations + 106768);
    conv2d_9_output_array.data_start = AI_PTR(activations + 106768);
    conv2d_10_output_array.data = AI_PTR(activations + 57616);
    conv2d_10_output_array.data_start = AI_PTR(activations + 57616);
    conv2d_11_output_array.data = AI_PTR(activations + 272);
    conv2d_11_output_array.data_start = AI_PTR(activations + 272);
    eltwise_12_output_array.data = AI_PTR(activations + 8464);
    eltwise_12_output_array.data_start = AI_PTR(activations + 8464);
    conv2d_13_output_array.data = AI_PTR(activations + 65808);
    conv2d_13_output_array.data_start = AI_PTR(activations + 65808);
    conv2d_15_output_array.data = AI_PTR(activations + 14068);
    conv2d_15_output_array.data_start = AI_PTR(activations + 14068);
    conv2d_16_output_array.data = AI_PTR(activations + 352);
    conv2d_16_output_array.data_start = AI_PTR(activations + 352);
    conv2d_17_output_array.data = AI_PTR(activations + 30048);
    conv2d_17_output_array.data_start = AI_PTR(activations + 30048);
    conv2d_18_output_array.data = AI_PTR(activations + 79200);
    conv2d_18_output_array.data_start = AI_PTR(activations + 79200);
    conv2d_19_output_array.data = AI_PTR(activations + 4992);
    conv2d_19_output_array.data_start = AI_PTR(activations + 4992);
    eltwise_20_output_array.data = AI_PTR(activations + 9088);
    eltwise_20_output_array.data_start = AI_PTR(activations + 9088);
    conv2d_21_output_array.data = AI_PTR(activations + 37760);
    conv2d_21_output_array.data_start = AI_PTR(activations + 37760);
    conv2d_22_output_array.data = AI_PTR(activations + 62336);
    conv2d_22_output_array.data_start = AI_PTR(activations + 62336);
    conv2d_23_output_array.data = AI_PTR(activations + 544);
    conv2d_23_output_array.data_start = AI_PTR(activations + 544);
    eltwise_24_output_array.data = AI_PTR(activations + 4640);
    eltwise_24_output_array.data_start = AI_PTR(activations + 4640);
    conv2d_25_output_array.data = AI_PTR(activations + 33312);
    conv2d_25_output_array.data_start = AI_PTR(activations + 33312);
    conv2d_27_output_array.data = AI_PTR(activations + 9700);
    conv2d_27_output_array.data_start = AI_PTR(activations + 9700);
    conv2d_28_output_array.data = AI_PTR(activations + 624);
    conv2d_28_output_array.data_start = AI_PTR(activations + 624);
    conv2d_29_output_array.data = AI_PTR(activations + 12912);
    conv2d_29_output_array.data_start = AI_PTR(activations + 12912);
    conv2d_30_output_array.data = AI_PTR(activations + 31344);
    conv2d_30_output_array.data_start = AI_PTR(activations + 31344);
    conv2d_31_output_array.data = AI_PTR(activations + 2976);
    conv2d_31_output_array.data_start = AI_PTR(activations + 2976);
    eltwise_32_output_array.data = AI_PTR(activations + 4512);
    eltwise_32_output_array.data_start = AI_PTR(activations + 4512);
    conv2d_33_output_array.data = AI_PTR(activations + 15264);
    conv2d_33_output_array.data_start = AI_PTR(activations + 15264);
    conv2d_34_output_array.data = AI_PTR(activations + 33696);
    conv2d_34_output_array.data_start = AI_PTR(activations + 33696);
    conv2d_35_output_array.data = AI_PTR(activations + 816);
    conv2d_35_output_array.data_start = AI_PTR(activations + 816);
    eltwise_36_output_array.data = AI_PTR(activations + 2352);
    eltwise_36_output_array.data_start = AI_PTR(activations + 2352);
    conv2d_37_output_array.data = AI_PTR(activations + 13104);
    conv2d_37_output_array.data_start = AI_PTR(activations + 13104);
    conv2d_38_output_array.data = AI_PTR(activations + 31536);
    conv2d_38_output_array.data_start = AI_PTR(activations + 31536);
    conv2d_39_output_array.data = AI_PTR(activations + 816);
    conv2d_39_output_array.data_start = AI_PTR(activations + 816);
    eltwise_40_output_array.data = AI_PTR(activations + 3888);
    eltwise_40_output_array.data_start = AI_PTR(activations + 3888);
    conv2d_41_output_array.data = AI_PTR(activations + 14640);
    conv2d_41_output_array.data_start = AI_PTR(activations + 14640);
    conv2d_42_output_array.data = AI_PTR(activations + 23856);
    conv2d_42_output_array.data_start = AI_PTR(activations + 23856);
    conv2d_43_output_array.data = AI_PTR(activations + 896);
    conv2d_43_output_array.data_start = AI_PTR(activations + 896);
    conv2d_44_output_array.data = AI_PTR(activations + 17280);
    conv2d_44_output_array.data_start = AI_PTR(activations + 17280);
    conv2d_45_output_array.data = AI_PTR(activations + 41856);
    conv2d_45_output_array.data_start = AI_PTR(activations + 41856);
    conv2d_46_output_array.data = AI_PTR(activations + 4032);
    conv2d_46_output_array.data_start = AI_PTR(activations + 4032);
    eltwise_47_output_array.data = AI_PTR(activations + 6080);
    eltwise_47_output_array.data_start = AI_PTR(activations + 6080);
    conv2d_48_output_array.data = AI_PTR(activations + 20416);
    conv2d_48_output_array.data_start = AI_PTR(activations + 20416);
    conv2d_49_output_array.data = AI_PTR(activations + 44992);
    conv2d_49_output_array.data_start = AI_PTR(activations + 44992);
    conv2d_50_output_array.data = AI_PTR(activations + 1088);
    conv2d_50_output_array.data_start = AI_PTR(activations + 1088);
    eltwise_51_output_array.data = AI_PTR(activations + 3136);
    eltwise_51_output_array.data_start = AI_PTR(activations + 3136);
    conv2d_52_output_array.data = AI_PTR(activations + 17472);
    conv2d_52_output_array.data_start = AI_PTR(activations + 17472);
    conv2d_54_output_array.data = AI_PTR(activations + 10180);
    conv2d_54_output_array.data_start = AI_PTR(activations + 10180);
    conv2d_55_output_array.data = AI_PTR(activations + 1328);
    conv2d_55_output_array.data_start = AI_PTR(activations + 1328);
    conv2d_56_output_array.data = AI_PTR(activations + 11184);
    conv2d_56_output_array.data_start = AI_PTR(activations + 11184);
    conv2d_57_output_array.data = AI_PTR(activations + 28996);
    conv2d_57_output_array.data_start = AI_PTR(activations + 28996);
    conv2d_58_output_array.data = AI_PTR(activations + 0);
    conv2d_58_output_array.data_start = AI_PTR(activations + 0);
    eltwise_59_output_array.data = AI_PTR(activations + 2224);
    eltwise_59_output_array.data_start = AI_PTR(activations + 2224);
    conv2d_60_output_array.data = AI_PTR(activations + 12080);
    conv2d_60_output_array.data_start = AI_PTR(activations + 12080);
    conv2d_61_output_array.data = AI_PTR(activations + 29892);
    conv2d_61_output_array.data_start = AI_PTR(activations + 29892);
    conv2d_62_output_array.data = AI_PTR(activations + 3120);
    conv2d_62_output_array.data_start = AI_PTR(activations + 3120);
    eltwise_63_output_array.data = AI_PTR(activations + 0);
    eltwise_63_output_array.data_start = AI_PTR(activations + 0);
    conv2d_64_output_array.data = AI_PTR(activations + 9856);
    conv2d_64_output_array.data_start = AI_PTR(activations + 9856);
    conv2d_65_output_array.data = AI_PTR(activations + 27668);
    conv2d_65_output_array.data_start = AI_PTR(activations + 27668);
    conv2d_66_output_array.data = AI_PTR(activations + 2464);
    conv2d_66_output_array.data_start = AI_PTR(activations + 2464);
    conv2d_67_output_array.data = AI_PTR(activations + 0);
    conv2d_67_output_array.data_start = AI_PTR(activations + 0);
    dense_69_output_array.data = AI_PTR(activations + 1280);
    dense_69_output_array.data_start = AI_PTR(activations + 1280);
    dense_69_fmt_output_array.data = AI_PTR(activations + 0);
    dense_69_fmt_output_array.data_start = AI_PTR(activations + 0);
    nl_70_output_array.data = AI_PTR(activations + 8);
    nl_70_output_array.data_start = AI_PTR(activations + 8);
    nl_70_fmt_output_array.data = AI_PTR(NULL);
    nl_70_fmt_output_array.data_start = AI_PTR(NULL);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 84836);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 84836);
    conv2d_2_scratch1_array.data = AI_PTR(activations + 135184);
    conv2d_2_scratch1_array.data_start = AI_PTR(activations + 135184);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 200720);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 200720);
    conv2d_3_scratch1_array.data = AI_PTR(activations + 69648);
    conv2d_3_scratch1_array.data_start = AI_PTR(activations + 69648);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 69504);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 69504);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 201312);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 201312);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 1584);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 1584);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 200044);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 200044);
    conv2d_7_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_7_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 49152);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 49152);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch1_array.data = AI_PTR(activations + 57616);
    conv2d_9_scratch1_array.data_start = AI_PTR(activations + 57616);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch1_array.data = AI_PTR(activations + 57616);
    conv2d_10_scratch1_array.data_start = AI_PTR(activations + 57616);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch1_array.data = AI_PTR(activations + 16656);
    conv2d_13_scratch1_array.data_start = AI_PTR(activations + 16656);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_15_scratch1_array.data = AI_PTR(activations + 1780);
    conv2d_15_scratch1_array.data_start = AI_PTR(activations + 1780);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 4448);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 4448);
    conv2d_17_scratch1_array.data = AI_PTR(activations + 5472);
    conv2d_17_scratch1_array.data_start = AI_PTR(activations + 5472);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 4448);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 4448);
    conv2d_18_scratch1_array.data = AI_PTR(activations + 54624);
    conv2d_18_scratch1_array.data_start = AI_PTR(activations + 54624);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 4448);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 4448);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch1_array.data = AI_PTR(activations + 13184);
    conv2d_21_scratch1_array.data_start = AI_PTR(activations + 13184);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_22_scratch1_array.data = AI_PTR(activations + 13184);
    conv2d_22_scratch1_array.data_start = AI_PTR(activations + 13184);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch1_array.data = AI_PTR(activations + 8736);
    conv2d_25_scratch1_array.data_start = AI_PTR(activations + 8736);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_27_scratch1_array.data = AI_PTR(activations + 3556);
    conv2d_27_scratch1_array.data_start = AI_PTR(activations + 3556);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data = AI_PTR(activations + 2160);
    conv2d_29_scratch0_array.data_start = AI_PTR(activations + 2160);
    conv2d_29_scratch1_array.data = AI_PTR(activations + 3696);
    conv2d_29_scratch1_array.data_start = AI_PTR(activations + 3696);
    conv2d_30_scratch0_array.data = AI_PTR(activations + 2160);
    conv2d_30_scratch0_array.data_start = AI_PTR(activations + 2160);
    conv2d_30_scratch1_array.data = AI_PTR(activations + 22128);
    conv2d_30_scratch1_array.data_start = AI_PTR(activations + 22128);
    conv2d_31_scratch0_array.data = AI_PTR(activations + 2160);
    conv2d_31_scratch0_array.data_start = AI_PTR(activations + 2160);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_33_scratch1_array.data = AI_PTR(activations + 6048);
    conv2d_33_scratch1_array.data_start = AI_PTR(activations + 6048);
    conv2d_34_scratch0_array.data = AI_PTR(activations + 6048);
    conv2d_34_scratch0_array.data_start = AI_PTR(activations + 6048);
    conv2d_34_scratch1_array.data = AI_PTR(activations + 24480);
    conv2d_34_scratch1_array.data_start = AI_PTR(activations + 24480);
    conv2d_35_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_35_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_37_scratch1_array.data = AI_PTR(activations + 3888);
    conv2d_37_scratch1_array.data_start = AI_PTR(activations + 3888);
    conv2d_38_scratch0_array.data = AI_PTR(activations + 3888);
    conv2d_38_scratch0_array.data_start = AI_PTR(activations + 3888);
    conv2d_38_scratch1_array.data = AI_PTR(activations + 22320);
    conv2d_38_scratch1_array.data_start = AI_PTR(activations + 22320);
    conv2d_39_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_39_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_41_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_41_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_41_scratch1_array.data = AI_PTR(activations + 5424);
    conv2d_41_scratch1_array.data_start = AI_PTR(activations + 5424);
    conv2d_42_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_42_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_42_scratch1_array.data = AI_PTR(activations + 5332);
    conv2d_42_scratch1_array.data_start = AI_PTR(activations + 5332);
    conv2d_43_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_43_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_44_scratch0_array.data = AI_PTR(activations + 2944);
    conv2d_44_scratch0_array.data_start = AI_PTR(activations + 2944);
    conv2d_44_scratch1_array.data = AI_PTR(activations + 4992);
    conv2d_44_scratch1_array.data_start = AI_PTR(activations + 4992);
    conv2d_45_scratch0_array.data = AI_PTR(activations + 2944);
    conv2d_45_scratch0_array.data_start = AI_PTR(activations + 2944);
    conv2d_45_scratch1_array.data = AI_PTR(activations + 29568);
    conv2d_45_scratch1_array.data_start = AI_PTR(activations + 29568);
    conv2d_46_scratch0_array.data = AI_PTR(activations + 2944);
    conv2d_46_scratch0_array.data_start = AI_PTR(activations + 2944);
    conv2d_48_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_48_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_48_scratch1_array.data = AI_PTR(activations + 8128);
    conv2d_48_scratch1_array.data_start = AI_PTR(activations + 8128);
    conv2d_49_scratch0_array.data = AI_PTR(activations + 8128);
    conv2d_49_scratch0_array.data_start = AI_PTR(activations + 8128);
    conv2d_49_scratch1_array.data = AI_PTR(activations + 32704);
    conv2d_49_scratch1_array.data_start = AI_PTR(activations + 32704);
    conv2d_50_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_50_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_52_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_52_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_52_scratch1_array.data = AI_PTR(activations + 5184);
    conv2d_52_scratch1_array.data_start = AI_PTR(activations + 5184);
    conv2d_54_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_54_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_54_scratch1_array.data = AI_PTR(activations + 7108);
    conv2d_54_scratch1_array.data_start = AI_PTR(activations + 7108);
    conv2d_55_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_55_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_56_scratch0_array.data = AI_PTR(activations + 2224);
    conv2d_56_scratch0_array.data_start = AI_PTR(activations + 2224);
    conv2d_56_scratch1_array.data = AI_PTR(activations + 5808);
    conv2d_56_scratch1_array.data_start = AI_PTR(activations + 5808);
    conv2d_57_scratch0_array.data = AI_PTR(activations + 16560);
    conv2d_57_scratch0_array.data_start = AI_PTR(activations + 16560);
    conv2d_57_scratch1_array.data = AI_PTR(activations + 2224);
    conv2d_57_scratch1_array.data_start = AI_PTR(activations + 2224);
    conv2d_58_scratch0_array.data = AI_PTR(activations + 2224);
    conv2d_58_scratch0_array.data_start = AI_PTR(activations + 2224);
    conv2d_60_scratch0_array.data = AI_PTR(activations + 3120);
    conv2d_60_scratch0_array.data_start = AI_PTR(activations + 3120);
    conv2d_60_scratch1_array.data = AI_PTR(activations + 6704);
    conv2d_60_scratch1_array.data_start = AI_PTR(activations + 6704);
    conv2d_61_scratch0_array.data = AI_PTR(activations + 17456);
    conv2d_61_scratch0_array.data_start = AI_PTR(activations + 17456);
    conv2d_61_scratch1_array.data = AI_PTR(activations + 3120);
    conv2d_61_scratch1_array.data_start = AI_PTR(activations + 3120);
    conv2d_62_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_62_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_64_scratch0_array.data = AI_PTR(activations + 896);
    conv2d_64_scratch0_array.data_start = AI_PTR(activations + 896);
    conv2d_64_scratch1_array.data = AI_PTR(activations + 4480);
    conv2d_64_scratch1_array.data_start = AI_PTR(activations + 4480);
    conv2d_65_scratch0_array.data = AI_PTR(activations + 15232);
    conv2d_65_scratch0_array.data_start = AI_PTR(activations + 15232);
    conv2d_65_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_65_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_66_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_66_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_67_scratch0_array.data = AI_PTR(activations + 4256);
    conv2d_67_scratch0_array.data_start = AI_PTR(activations + 4256);
    conv2d_67_scratch1_array.data = AI_PTR(activations + 17504);
    conv2d_67_scratch1_array.data_start = AI_PTR(activations + 17504);
    conv2d_67_scratch2_array.data = AI_PTR(activations + 37984);
    conv2d_67_scratch2_array.data_start = AI_PTR(activations + 37984);
    
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
    
    conv2d_2_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_weights_array.data = AI_PTR(weights + 0);
    conv2d_2_weights_array.data_start = AI_PTR(weights + 0);
    conv2d_2_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_2_bias_array.data = AI_PTR(weights + 432);
    conv2d_2_bias_array.data_start = AI_PTR(weights + 432);
    conv2d_3_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_weights_array.data = AI_PTR(weights + 496);
    conv2d_3_weights_array.data_start = AI_PTR(weights + 496);
    conv2d_3_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_3_bias_array.data = AI_PTR(weights + 640);
    conv2d_3_bias_array.data_start = AI_PTR(weights + 640);
    conv2d_4_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_weights_array.data = AI_PTR(weights + 704);
    conv2d_4_weights_array.data_start = AI_PTR(weights + 704);
    conv2d_4_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_4_bias_array.data = AI_PTR(weights + 832);
    conv2d_4_bias_array.data_start = AI_PTR(weights + 832);
    conv2d_5_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_weights_array.data = AI_PTR(weights + 864);
    conv2d_5_weights_array.data_start = AI_PTR(weights + 864);
    conv2d_5_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_5_bias_array.data = AI_PTR(weights + 1248);
    conv2d_5_bias_array.data_start = AI_PTR(weights + 1248);
    conv2d_7_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_weights_array.data = AI_PTR(weights + 1440);
    conv2d_7_weights_array.data_start = AI_PTR(weights + 1440);
    conv2d_7_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_7_bias_array.data = AI_PTR(weights + 1872);
    conv2d_7_bias_array.data_start = AI_PTR(weights + 1872);
    conv2d_8_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_weights_array.data = AI_PTR(weights + 2064);
    conv2d_8_weights_array.data_start = AI_PTR(weights + 2064);
    conv2d_8_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_8_bias_array.data = AI_PTR(weights + 2448);
    conv2d_8_bias_array.data_start = AI_PTR(weights + 2448);
    conv2d_9_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_weights_array.data = AI_PTR(weights + 2480);
    conv2d_9_weights_array.data_start = AI_PTR(weights + 2480);
    conv2d_9_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_9_bias_array.data = AI_PTR(weights + 2864);
    conv2d_9_bias_array.data_start = AI_PTR(weights + 2864);
    conv2d_10_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_weights_array.data = AI_PTR(weights + 3056);
    conv2d_10_weights_array.data_start = AI_PTR(weights + 3056);
    conv2d_10_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_10_bias_array.data = AI_PTR(weights + 3488);
    conv2d_10_bias_array.data_start = AI_PTR(weights + 3488);
    conv2d_11_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_weights_array.data = AI_PTR(weights + 3680);
    conv2d_11_weights_array.data_start = AI_PTR(weights + 3680);
    conv2d_11_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_11_bias_array.data = AI_PTR(weights + 4064);
    conv2d_11_bias_array.data_start = AI_PTR(weights + 4064);
    conv2d_13_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_weights_array.data = AI_PTR(weights + 4096);
    conv2d_13_weights_array.data_start = AI_PTR(weights + 4096);
    conv2d_13_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_13_bias_array.data = AI_PTR(weights + 4480);
    conv2d_13_bias_array.data_start = AI_PTR(weights + 4480);
    conv2d_15_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_weights_array.data = AI_PTR(weights + 4672);
    conv2d_15_weights_array.data_start = AI_PTR(weights + 4672);
    conv2d_15_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_15_bias_array.data = AI_PTR(weights + 5104);
    conv2d_15_bias_array.data_start = AI_PTR(weights + 5104);
    conv2d_16_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_weights_array.data = AI_PTR(weights + 5296);
    conv2d_16_weights_array.data_start = AI_PTR(weights + 5296);
    conv2d_16_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_16_bias_array.data = AI_PTR(weights + 6064);
    conv2d_16_bias_array.data_start = AI_PTR(weights + 6064);
    conv2d_17_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_weights_array.data = AI_PTR(weights + 6128);
    conv2d_17_weights_array.data_start = AI_PTR(weights + 6128);
    conv2d_17_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_17_bias_array.data = AI_PTR(weights + 7664);
    conv2d_17_bias_array.data_start = AI_PTR(weights + 7664);
    conv2d_18_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_weights_array.data = AI_PTR(weights + 8048);
    conv2d_18_weights_array.data_start = AI_PTR(weights + 8048);
    conv2d_18_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_18_bias_array.data = AI_PTR(weights + 8912);
    conv2d_18_bias_array.data_start = AI_PTR(weights + 8912);
    conv2d_19_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_weights_array.data = AI_PTR(weights + 9296);
    conv2d_19_weights_array.data_start = AI_PTR(weights + 9296);
    conv2d_19_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_19_bias_array.data = AI_PTR(weights + 10832);
    conv2d_19_bias_array.data_start = AI_PTR(weights + 10832);
    conv2d_21_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_weights_array.data = AI_PTR(weights + 10896);
    conv2d_21_weights_array.data_start = AI_PTR(weights + 10896);
    conv2d_21_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_21_bias_array.data = AI_PTR(weights + 12432);
    conv2d_21_bias_array.data_start = AI_PTR(weights + 12432);
    conv2d_22_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_weights_array.data = AI_PTR(weights + 12816);
    conv2d_22_weights_array.data_start = AI_PTR(weights + 12816);
    conv2d_22_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_22_bias_array.data = AI_PTR(weights + 13680);
    conv2d_22_bias_array.data_start = AI_PTR(weights + 13680);
    conv2d_23_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_weights_array.data = AI_PTR(weights + 14064);
    conv2d_23_weights_array.data_start = AI_PTR(weights + 14064);
    conv2d_23_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_23_bias_array.data = AI_PTR(weights + 15600);
    conv2d_23_bias_array.data_start = AI_PTR(weights + 15600);
    conv2d_25_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_weights_array.data = AI_PTR(weights + 15664);
    conv2d_25_weights_array.data_start = AI_PTR(weights + 15664);
    conv2d_25_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_25_bias_array.data = AI_PTR(weights + 17200);
    conv2d_25_bias_array.data_start = AI_PTR(weights + 17200);
    conv2d_27_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_weights_array.data = AI_PTR(weights + 17584);
    conv2d_27_weights_array.data_start = AI_PTR(weights + 17584);
    conv2d_27_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_27_bias_array.data = AI_PTR(weights + 18448);
    conv2d_27_bias_array.data_start = AI_PTR(weights + 18448);
    conv2d_28_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_weights_array.data = AI_PTR(weights + 18832);
    conv2d_28_weights_array.data_start = AI_PTR(weights + 18832);
    conv2d_28_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_28_bias_array.data = AI_PTR(weights + 21136);
    conv2d_28_bias_array.data_start = AI_PTR(weights + 21136);
    conv2d_29_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_weights_array.data = AI_PTR(weights + 21232);
    conv2d_29_weights_array.data_start = AI_PTR(weights + 21232);
    conv2d_29_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_29_bias_array.data = AI_PTR(weights + 24688);
    conv2d_29_bias_array.data_start = AI_PTR(weights + 24688);
    conv2d_30_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_weights_array.data = AI_PTR(weights + 25264);
    conv2d_30_weights_array.data_start = AI_PTR(weights + 25264);
    conv2d_30_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_30_bias_array.data = AI_PTR(weights + 26560);
    conv2d_30_bias_array.data_start = AI_PTR(weights + 26560);
    conv2d_31_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_weights_array.data = AI_PTR(weights + 27136);
    conv2d_31_weights_array.data_start = AI_PTR(weights + 27136);
    conv2d_31_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_31_bias_array.data = AI_PTR(weights + 30592);
    conv2d_31_bias_array.data_start = AI_PTR(weights + 30592);
    conv2d_33_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_weights_array.data = AI_PTR(weights + 30688);
    conv2d_33_weights_array.data_start = AI_PTR(weights + 30688);
    conv2d_33_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_33_bias_array.data = AI_PTR(weights + 34144);
    conv2d_33_bias_array.data_start = AI_PTR(weights + 34144);
    conv2d_34_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_weights_array.data = AI_PTR(weights + 34720);
    conv2d_34_weights_array.data_start = AI_PTR(weights + 34720);
    conv2d_34_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_34_bias_array.data = AI_PTR(weights + 36016);
    conv2d_34_bias_array.data_start = AI_PTR(weights + 36016);
    conv2d_35_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_weights_array.data = AI_PTR(weights + 36592);
    conv2d_35_weights_array.data_start = AI_PTR(weights + 36592);
    conv2d_35_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_35_bias_array.data = AI_PTR(weights + 40048);
    conv2d_35_bias_array.data_start = AI_PTR(weights + 40048);
    conv2d_37_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_weights_array.data = AI_PTR(weights + 40144);
    conv2d_37_weights_array.data_start = AI_PTR(weights + 40144);
    conv2d_37_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_37_bias_array.data = AI_PTR(weights + 43600);
    conv2d_37_bias_array.data_start = AI_PTR(weights + 43600);
    conv2d_38_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_weights_array.data = AI_PTR(weights + 44176);
    conv2d_38_weights_array.data_start = AI_PTR(weights + 44176);
    conv2d_38_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_38_bias_array.data = AI_PTR(weights + 45472);
    conv2d_38_bias_array.data_start = AI_PTR(weights + 45472);
    conv2d_39_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_weights_array.data = AI_PTR(weights + 46048);
    conv2d_39_weights_array.data_start = AI_PTR(weights + 46048);
    conv2d_39_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_39_bias_array.data = AI_PTR(weights + 49504);
    conv2d_39_bias_array.data_start = AI_PTR(weights + 49504);
    conv2d_41_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_weights_array.data = AI_PTR(weights + 49600);
    conv2d_41_weights_array.data_start = AI_PTR(weights + 49600);
    conv2d_41_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_41_bias_array.data = AI_PTR(weights + 53056);
    conv2d_41_bias_array.data_start = AI_PTR(weights + 53056);
    conv2d_42_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_weights_array.data = AI_PTR(weights + 53632);
    conv2d_42_weights_array.data_start = AI_PTR(weights + 53632);
    conv2d_42_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_42_bias_array.data = AI_PTR(weights + 54928);
    conv2d_42_bias_array.data_start = AI_PTR(weights + 54928);
    conv2d_43_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_weights_array.data = AI_PTR(weights + 55504);
    conv2d_43_weights_array.data_start = AI_PTR(weights + 55504);
    conv2d_43_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_43_bias_array.data = AI_PTR(weights + 60112);
    conv2d_43_bias_array.data_start = AI_PTR(weights + 60112);
    conv2d_44_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_weights_array.data = AI_PTR(weights + 60240);
    conv2d_44_weights_array.data_start = AI_PTR(weights + 60240);
    conv2d_44_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_44_bias_array.data = AI_PTR(weights + 66384);
    conv2d_44_bias_array.data_start = AI_PTR(weights + 66384);
    conv2d_45_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_weights_array.data = AI_PTR(weights + 67152);
    conv2d_45_weights_array.data_start = AI_PTR(weights + 67152);
    conv2d_45_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_45_bias_array.data = AI_PTR(weights + 68880);
    conv2d_45_bias_array.data_start = AI_PTR(weights + 68880);
    conv2d_46_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_weights_array.data = AI_PTR(weights + 69648);
    conv2d_46_weights_array.data_start = AI_PTR(weights + 69648);
    conv2d_46_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_46_bias_array.data = AI_PTR(weights + 75792);
    conv2d_46_bias_array.data_start = AI_PTR(weights + 75792);
    conv2d_48_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_weights_array.data = AI_PTR(weights + 75920);
    conv2d_48_weights_array.data_start = AI_PTR(weights + 75920);
    conv2d_48_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_48_bias_array.data = AI_PTR(weights + 82064);
    conv2d_48_bias_array.data_start = AI_PTR(weights + 82064);
    conv2d_49_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_weights_array.data = AI_PTR(weights + 82832);
    conv2d_49_weights_array.data_start = AI_PTR(weights + 82832);
    conv2d_49_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_49_bias_array.data = AI_PTR(weights + 84560);
    conv2d_49_bias_array.data_start = AI_PTR(weights + 84560);
    conv2d_50_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_weights_array.data = AI_PTR(weights + 85328);
    conv2d_50_weights_array.data_start = AI_PTR(weights + 85328);
    conv2d_50_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_50_bias_array.data = AI_PTR(weights + 91472);
    conv2d_50_bias_array.data_start = AI_PTR(weights + 91472);
    conv2d_52_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_weights_array.data = AI_PTR(weights + 91600);
    conv2d_52_weights_array.data_start = AI_PTR(weights + 91600);
    conv2d_52_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_52_bias_array.data = AI_PTR(weights + 97744);
    conv2d_52_bias_array.data_start = AI_PTR(weights + 97744);
    conv2d_54_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_weights_array.data = AI_PTR(weights + 98512);
    conv2d_54_weights_array.data_start = AI_PTR(weights + 98512);
    conv2d_54_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_54_bias_array.data = AI_PTR(weights + 100240);
    conv2d_54_bias_array.data_start = AI_PTR(weights + 100240);
    conv2d_55_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_weights_array.data = AI_PTR(weights + 101008);
    conv2d_55_weights_array.data_start = AI_PTR(weights + 101008);
    conv2d_55_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_55_bias_array.data = AI_PTR(weights + 111760);
    conv2d_55_bias_array.data_start = AI_PTR(weights + 111760);
    conv2d_56_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_weights_array.data = AI_PTR(weights + 111984);
    conv2d_56_weights_array.data_start = AI_PTR(weights + 111984);
    conv2d_56_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_56_bias_array.data = AI_PTR(weights + 130800);
    conv2d_56_bias_array.data_start = AI_PTR(weights + 130800);
    conv2d_57_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_weights_array.data = AI_PTR(weights + 132144);
    conv2d_57_weights_array.data_start = AI_PTR(weights + 132144);
    conv2d_57_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_57_bias_array.data = AI_PTR(weights + 135168);
    conv2d_57_bias_array.data_start = AI_PTR(weights + 135168);
    conv2d_58_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_58_weights_array.data = AI_PTR(weights + 136512);
    conv2d_58_weights_array.data_start = AI_PTR(weights + 136512);
    conv2d_58_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_58_bias_array.data = AI_PTR(weights + 155328);
    conv2d_58_bias_array.data_start = AI_PTR(weights + 155328);
    conv2d_60_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_weights_array.data = AI_PTR(weights + 155552);
    conv2d_60_weights_array.data_start = AI_PTR(weights + 155552);
    conv2d_60_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_60_bias_array.data = AI_PTR(weights + 174368);
    conv2d_60_bias_array.data_start = AI_PTR(weights + 174368);
    conv2d_61_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_weights_array.data = AI_PTR(weights + 175712);
    conv2d_61_weights_array.data_start = AI_PTR(weights + 175712);
    conv2d_61_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_61_bias_array.data = AI_PTR(weights + 178736);
    conv2d_61_bias_array.data_start = AI_PTR(weights + 178736);
    conv2d_62_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_62_weights_array.data = AI_PTR(weights + 180080);
    conv2d_62_weights_array.data_start = AI_PTR(weights + 180080);
    conv2d_62_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_62_bias_array.data = AI_PTR(weights + 198896);
    conv2d_62_bias_array.data_start = AI_PTR(weights + 198896);
    conv2d_64_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_weights_array.data = AI_PTR(weights + 199120);
    conv2d_64_weights_array.data_start = AI_PTR(weights + 199120);
    conv2d_64_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_64_bias_array.data = AI_PTR(weights + 217936);
    conv2d_64_bias_array.data_start = AI_PTR(weights + 217936);
    conv2d_65_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_weights_array.data = AI_PTR(weights + 219280);
    conv2d_65_weights_array.data_start = AI_PTR(weights + 219280);
    conv2d_65_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_65_bias_array.data = AI_PTR(weights + 222304);
    conv2d_65_bias_array.data_start = AI_PTR(weights + 222304);
    conv2d_66_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_weights_array.data = AI_PTR(weights + 223648);
    conv2d_66_weights_array.data_start = AI_PTR(weights + 223648);
    conv2d_66_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_66_bias_array.data = AI_PTR(weights + 261280);
    conv2d_66_bias_array.data_start = AI_PTR(weights + 261280);
    conv2d_67_weights_array.format |= AI_FMT_FLAG_CONST;
    conv2d_67_weights_array.data = AI_PTR(weights + 261728);
    conv2d_67_weights_array.data_start = AI_PTR(weights + 261728);
    conv2d_67_bias_array.format |= AI_FMT_FLAG_CONST;
    conv2d_67_bias_array.data = AI_PTR(weights + 405088);
    conv2d_67_bias_array.data_start = AI_PTR(weights + 405088);
    dense_69_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_69_weights_array.data = AI_PTR(weights + 410208);
    dense_69_weights_array.data_start = AI_PTR(weights + 410208);
    dense_69_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_69_bias_array.data = AI_PTR(weights + 412768);
    dense_69_bias_array.data_start = AI_PTR(weights + 412768);
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
      
      .n_macc            = 19095976,
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

