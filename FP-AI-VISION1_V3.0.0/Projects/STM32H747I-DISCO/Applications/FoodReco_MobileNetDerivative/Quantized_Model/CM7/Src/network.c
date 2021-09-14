/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Wed Jun 30 16:16:27 2021
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
#define AI_NETWORK_MODEL_SIGNATURE     "569d2a75a1bef2bb50a4b213ec34253e"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Wed Jun 30 16:16:27 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array sequential_3_input_output_array;   /* Array #0 */
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
AI_STATIC ai_array dense_70_output_array;   /* Array #65 */
AI_STATIC ai_array dense_70_fmt_output_array;   /* Array #66 */
AI_STATIC ai_array nl_71_output_array;   /* Array #67 */
AI_STATIC ai_array nl_71_fmt_output_array;   /* Array #68 */
AI_STATIC ai_array conv2d_2_weights_array;   /* Array #69 */
AI_STATIC ai_array conv2d_2_bias_array;   /* Array #70 */
AI_STATIC ai_array conv2d_3_weights_array;   /* Array #71 */
AI_STATIC ai_array conv2d_3_bias_array;   /* Array #72 */
AI_STATIC ai_array conv2d_4_weights_array;   /* Array #73 */
AI_STATIC ai_array conv2d_4_bias_array;   /* Array #74 */
AI_STATIC ai_array conv2d_5_weights_array;   /* Array #75 */
AI_STATIC ai_array conv2d_5_bias_array;   /* Array #76 */
AI_STATIC ai_array conv2d_7_weights_array;   /* Array #77 */
AI_STATIC ai_array conv2d_7_bias_array;   /* Array #78 */
AI_STATIC ai_array conv2d_8_weights_array;   /* Array #79 */
AI_STATIC ai_array conv2d_8_bias_array;   /* Array #80 */
AI_STATIC ai_array conv2d_9_weights_array;   /* Array #81 */
AI_STATIC ai_array conv2d_9_bias_array;   /* Array #82 */
AI_STATIC ai_array conv2d_10_weights_array;   /* Array #83 */
AI_STATIC ai_array conv2d_10_bias_array;   /* Array #84 */
AI_STATIC ai_array conv2d_11_weights_array;   /* Array #85 */
AI_STATIC ai_array conv2d_11_bias_array;   /* Array #86 */
AI_STATIC ai_array conv2d_13_weights_array;   /* Array #87 */
AI_STATIC ai_array conv2d_13_bias_array;   /* Array #88 */
AI_STATIC ai_array conv2d_15_weights_array;   /* Array #89 */
AI_STATIC ai_array conv2d_15_bias_array;   /* Array #90 */
AI_STATIC ai_array conv2d_16_weights_array;   /* Array #91 */
AI_STATIC ai_array conv2d_16_bias_array;   /* Array #92 */
AI_STATIC ai_array conv2d_17_weights_array;   /* Array #93 */
AI_STATIC ai_array conv2d_17_bias_array;   /* Array #94 */
AI_STATIC ai_array conv2d_18_weights_array;   /* Array #95 */
AI_STATIC ai_array conv2d_18_bias_array;   /* Array #96 */
AI_STATIC ai_array conv2d_19_weights_array;   /* Array #97 */
AI_STATIC ai_array conv2d_19_bias_array;   /* Array #98 */
AI_STATIC ai_array conv2d_21_weights_array;   /* Array #99 */
AI_STATIC ai_array conv2d_21_bias_array;   /* Array #100 */
AI_STATIC ai_array conv2d_22_weights_array;   /* Array #101 */
AI_STATIC ai_array conv2d_22_bias_array;   /* Array #102 */
AI_STATIC ai_array conv2d_23_weights_array;   /* Array #103 */
AI_STATIC ai_array conv2d_23_bias_array;   /* Array #104 */
AI_STATIC ai_array conv2d_25_weights_array;   /* Array #105 */
AI_STATIC ai_array conv2d_25_bias_array;   /* Array #106 */
AI_STATIC ai_array conv2d_27_weights_array;   /* Array #107 */
AI_STATIC ai_array conv2d_27_bias_array;   /* Array #108 */
AI_STATIC ai_array conv2d_28_weights_array;   /* Array #109 */
AI_STATIC ai_array conv2d_28_bias_array;   /* Array #110 */
AI_STATIC ai_array conv2d_29_weights_array;   /* Array #111 */
AI_STATIC ai_array conv2d_29_bias_array;   /* Array #112 */
AI_STATIC ai_array conv2d_30_weights_array;   /* Array #113 */
AI_STATIC ai_array conv2d_30_bias_array;   /* Array #114 */
AI_STATIC ai_array conv2d_31_weights_array;   /* Array #115 */
AI_STATIC ai_array conv2d_31_bias_array;   /* Array #116 */
AI_STATIC ai_array conv2d_33_weights_array;   /* Array #117 */
AI_STATIC ai_array conv2d_33_bias_array;   /* Array #118 */
AI_STATIC ai_array conv2d_34_weights_array;   /* Array #119 */
AI_STATIC ai_array conv2d_34_bias_array;   /* Array #120 */
AI_STATIC ai_array conv2d_35_weights_array;   /* Array #121 */
AI_STATIC ai_array conv2d_35_bias_array;   /* Array #122 */
AI_STATIC ai_array conv2d_37_weights_array;   /* Array #123 */
AI_STATIC ai_array conv2d_37_bias_array;   /* Array #124 */
AI_STATIC ai_array conv2d_38_weights_array;   /* Array #125 */
AI_STATIC ai_array conv2d_38_bias_array;   /* Array #126 */
AI_STATIC ai_array conv2d_39_weights_array;   /* Array #127 */
AI_STATIC ai_array conv2d_39_bias_array;   /* Array #128 */
AI_STATIC ai_array conv2d_41_weights_array;   /* Array #129 */
AI_STATIC ai_array conv2d_41_bias_array;   /* Array #130 */
AI_STATIC ai_array conv2d_42_weights_array;   /* Array #131 */
AI_STATIC ai_array conv2d_42_bias_array;   /* Array #132 */
AI_STATIC ai_array conv2d_43_weights_array;   /* Array #133 */
AI_STATIC ai_array conv2d_43_bias_array;   /* Array #134 */
AI_STATIC ai_array conv2d_44_weights_array;   /* Array #135 */
AI_STATIC ai_array conv2d_44_bias_array;   /* Array #136 */
AI_STATIC ai_array conv2d_45_weights_array;   /* Array #137 */
AI_STATIC ai_array conv2d_45_bias_array;   /* Array #138 */
AI_STATIC ai_array conv2d_46_weights_array;   /* Array #139 */
AI_STATIC ai_array conv2d_46_bias_array;   /* Array #140 */
AI_STATIC ai_array conv2d_48_weights_array;   /* Array #141 */
AI_STATIC ai_array conv2d_48_bias_array;   /* Array #142 */
AI_STATIC ai_array conv2d_49_weights_array;   /* Array #143 */
AI_STATIC ai_array conv2d_49_bias_array;   /* Array #144 */
AI_STATIC ai_array conv2d_50_weights_array;   /* Array #145 */
AI_STATIC ai_array conv2d_50_bias_array;   /* Array #146 */
AI_STATIC ai_array conv2d_52_weights_array;   /* Array #147 */
AI_STATIC ai_array conv2d_52_bias_array;   /* Array #148 */
AI_STATIC ai_array conv2d_54_weights_array;   /* Array #149 */
AI_STATIC ai_array conv2d_54_bias_array;   /* Array #150 */
AI_STATIC ai_array conv2d_55_weights_array;   /* Array #151 */
AI_STATIC ai_array conv2d_55_bias_array;   /* Array #152 */
AI_STATIC ai_array conv2d_56_weights_array;   /* Array #153 */
AI_STATIC ai_array conv2d_56_bias_array;   /* Array #154 */
AI_STATIC ai_array conv2d_57_weights_array;   /* Array #155 */
AI_STATIC ai_array conv2d_57_bias_array;   /* Array #156 */
AI_STATIC ai_array conv2d_58_weights_array;   /* Array #157 */
AI_STATIC ai_array conv2d_58_bias_array;   /* Array #158 */
AI_STATIC ai_array conv2d_60_weights_array;   /* Array #159 */
AI_STATIC ai_array conv2d_60_bias_array;   /* Array #160 */
AI_STATIC ai_array conv2d_61_weights_array;   /* Array #161 */
AI_STATIC ai_array conv2d_61_bias_array;   /* Array #162 */
AI_STATIC ai_array conv2d_62_weights_array;   /* Array #163 */
AI_STATIC ai_array conv2d_62_bias_array;   /* Array #164 */
AI_STATIC ai_array conv2d_64_weights_array;   /* Array #165 */
AI_STATIC ai_array conv2d_64_bias_array;   /* Array #166 */
AI_STATIC ai_array conv2d_65_weights_array;   /* Array #167 */
AI_STATIC ai_array conv2d_65_bias_array;   /* Array #168 */
AI_STATIC ai_array conv2d_66_weights_array;   /* Array #169 */
AI_STATIC ai_array conv2d_66_bias_array;   /* Array #170 */
AI_STATIC ai_array conv2d_67_weights_array;   /* Array #171 */
AI_STATIC ai_array conv2d_67_bias_array;   /* Array #172 */
AI_STATIC ai_array dense_69_weights_array;   /* Array #173 */
AI_STATIC ai_array dense_69_bias_array;   /* Array #174 */
AI_STATIC ai_array dense_70_weights_array;   /* Array #175 */
AI_STATIC ai_array dense_70_bias_array;   /* Array #176 */
AI_STATIC ai_array conv2d_2_scratch0_array;   /* Array #177 */
AI_STATIC ai_array conv2d_2_scratch1_array;   /* Array #178 */
AI_STATIC ai_array conv2d_3_scratch0_array;   /* Array #179 */
AI_STATIC ai_array conv2d_3_scratch1_array;   /* Array #180 */
AI_STATIC ai_array conv2d_4_scratch0_array;   /* Array #181 */
AI_STATIC ai_array conv2d_5_scratch0_array;   /* Array #182 */
AI_STATIC ai_array conv2d_5_scratch1_array;   /* Array #183 */
AI_STATIC ai_array conv2d_7_scratch0_array;   /* Array #184 */
AI_STATIC ai_array conv2d_7_scratch1_array;   /* Array #185 */
AI_STATIC ai_array conv2d_8_scratch0_array;   /* Array #186 */
AI_STATIC ai_array conv2d_9_scratch0_array;   /* Array #187 */
AI_STATIC ai_array conv2d_9_scratch1_array;   /* Array #188 */
AI_STATIC ai_array conv2d_10_scratch0_array;   /* Array #189 */
AI_STATIC ai_array conv2d_10_scratch1_array;   /* Array #190 */
AI_STATIC ai_array conv2d_11_scratch0_array;   /* Array #191 */
AI_STATIC ai_array conv2d_13_scratch0_array;   /* Array #192 */
AI_STATIC ai_array conv2d_13_scratch1_array;   /* Array #193 */
AI_STATIC ai_array conv2d_15_scratch0_array;   /* Array #194 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #195 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #196 */
AI_STATIC ai_array conv2d_17_scratch1_array;   /* Array #197 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #198 */
AI_STATIC ai_array conv2d_18_scratch1_array;   /* Array #199 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #200 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #201 */
AI_STATIC ai_array conv2d_21_scratch1_array;   /* Array #202 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #203 */
AI_STATIC ai_array conv2d_22_scratch1_array;   /* Array #204 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #205 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #206 */
AI_STATIC ai_array conv2d_25_scratch1_array;   /* Array #207 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #208 */
AI_STATIC ai_array conv2d_27_scratch1_array;   /* Array #209 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #210 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #211 */
AI_STATIC ai_array conv2d_29_scratch1_array;   /* Array #212 */
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #213 */
AI_STATIC ai_array conv2d_30_scratch1_array;   /* Array #214 */
AI_STATIC ai_array conv2d_31_scratch0_array;   /* Array #215 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #216 */
AI_STATIC ai_array conv2d_33_scratch1_array;   /* Array #217 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #218 */
AI_STATIC ai_array conv2d_34_scratch1_array;   /* Array #219 */
AI_STATIC ai_array conv2d_35_scratch0_array;   /* Array #220 */
AI_STATIC ai_array conv2d_37_scratch0_array;   /* Array #221 */
AI_STATIC ai_array conv2d_37_scratch1_array;   /* Array #222 */
AI_STATIC ai_array conv2d_38_scratch0_array;   /* Array #223 */
AI_STATIC ai_array conv2d_38_scratch1_array;   /* Array #224 */
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #225 */
AI_STATIC ai_array conv2d_41_scratch0_array;   /* Array #226 */
AI_STATIC ai_array conv2d_41_scratch1_array;   /* Array #227 */
AI_STATIC ai_array conv2d_42_scratch0_array;   /* Array #228 */
AI_STATIC ai_array conv2d_42_scratch1_array;   /* Array #229 */
AI_STATIC ai_array conv2d_43_scratch0_array;   /* Array #230 */
AI_STATIC ai_array conv2d_44_scratch0_array;   /* Array #231 */
AI_STATIC ai_array conv2d_44_scratch1_array;   /* Array #232 */
AI_STATIC ai_array conv2d_45_scratch0_array;   /* Array #233 */
AI_STATIC ai_array conv2d_45_scratch1_array;   /* Array #234 */
AI_STATIC ai_array conv2d_46_scratch0_array;   /* Array #235 */
AI_STATIC ai_array conv2d_48_scratch0_array;   /* Array #236 */
AI_STATIC ai_array conv2d_48_scratch1_array;   /* Array #237 */
AI_STATIC ai_array conv2d_49_scratch0_array;   /* Array #238 */
AI_STATIC ai_array conv2d_49_scratch1_array;   /* Array #239 */
AI_STATIC ai_array conv2d_50_scratch0_array;   /* Array #240 */
AI_STATIC ai_array conv2d_52_scratch0_array;   /* Array #241 */
AI_STATIC ai_array conv2d_52_scratch1_array;   /* Array #242 */
AI_STATIC ai_array conv2d_54_scratch0_array;   /* Array #243 */
AI_STATIC ai_array conv2d_54_scratch1_array;   /* Array #244 */
AI_STATIC ai_array conv2d_55_scratch0_array;   /* Array #245 */
AI_STATIC ai_array conv2d_56_scratch0_array;   /* Array #246 */
AI_STATIC ai_array conv2d_56_scratch1_array;   /* Array #247 */
AI_STATIC ai_array conv2d_57_scratch0_array;   /* Array #248 */
AI_STATIC ai_array conv2d_58_scratch0_array;   /* Array #249 */
AI_STATIC ai_array conv2d_60_scratch0_array;   /* Array #250 */
AI_STATIC ai_array conv2d_60_scratch1_array;   /* Array #251 */
AI_STATIC ai_array conv2d_61_scratch0_array;   /* Array #252 */
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
AI_STATIC ai_tensor sequential_3_input_output;   /* Tensor #0 */
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
AI_STATIC ai_tensor dense_70_output;   /* Tensor #65 */
AI_STATIC ai_tensor dense_70_fmt_output;   /* Tensor #66 */
AI_STATIC ai_tensor nl_71_output;   /* Tensor #67 */
AI_STATIC ai_tensor nl_71_fmt_output;   /* Tensor #68 */
AI_STATIC ai_tensor conv2d_2_weights;   /* Tensor #69 */
AI_STATIC ai_tensor conv2d_2_bias;   /* Tensor #70 */
AI_STATIC ai_tensor conv2d_3_weights;   /* Tensor #71 */
AI_STATIC ai_tensor conv2d_3_bias;   /* Tensor #72 */
AI_STATIC ai_tensor conv2d_4_weights;   /* Tensor #73 */
AI_STATIC ai_tensor conv2d_4_bias;   /* Tensor #74 */
AI_STATIC ai_tensor conv2d_5_weights;   /* Tensor #75 */
AI_STATIC ai_tensor conv2d_5_bias;   /* Tensor #76 */
AI_STATIC ai_tensor conv2d_7_weights;   /* Tensor #77 */
AI_STATIC ai_tensor conv2d_7_bias;   /* Tensor #78 */
AI_STATIC ai_tensor conv2d_8_weights;   /* Tensor #79 */
AI_STATIC ai_tensor conv2d_8_bias;   /* Tensor #80 */
AI_STATIC ai_tensor conv2d_9_weights;   /* Tensor #81 */
AI_STATIC ai_tensor conv2d_9_bias;   /* Tensor #82 */
AI_STATIC ai_tensor conv2d_10_weights;   /* Tensor #83 */
AI_STATIC ai_tensor conv2d_10_bias;   /* Tensor #84 */
AI_STATIC ai_tensor conv2d_11_weights;   /* Tensor #85 */
AI_STATIC ai_tensor conv2d_11_bias;   /* Tensor #86 */
AI_STATIC ai_tensor conv2d_13_weights;   /* Tensor #87 */
AI_STATIC ai_tensor conv2d_13_bias;   /* Tensor #88 */
AI_STATIC ai_tensor conv2d_15_weights;   /* Tensor #89 */
AI_STATIC ai_tensor conv2d_15_bias;   /* Tensor #90 */
AI_STATIC ai_tensor conv2d_16_weights;   /* Tensor #91 */
AI_STATIC ai_tensor conv2d_16_bias;   /* Tensor #92 */
AI_STATIC ai_tensor conv2d_17_weights;   /* Tensor #93 */
AI_STATIC ai_tensor conv2d_17_bias;   /* Tensor #94 */
AI_STATIC ai_tensor conv2d_18_weights;   /* Tensor #95 */
AI_STATIC ai_tensor conv2d_18_bias;   /* Tensor #96 */
AI_STATIC ai_tensor conv2d_19_weights;   /* Tensor #97 */
AI_STATIC ai_tensor conv2d_19_bias;   /* Tensor #98 */
AI_STATIC ai_tensor conv2d_21_weights;   /* Tensor #99 */
AI_STATIC ai_tensor conv2d_21_bias;   /* Tensor #100 */
AI_STATIC ai_tensor conv2d_22_weights;   /* Tensor #101 */
AI_STATIC ai_tensor conv2d_22_bias;   /* Tensor #102 */
AI_STATIC ai_tensor conv2d_23_weights;   /* Tensor #103 */
AI_STATIC ai_tensor conv2d_23_bias;   /* Tensor #104 */
AI_STATIC ai_tensor conv2d_25_weights;   /* Tensor #105 */
AI_STATIC ai_tensor conv2d_25_bias;   /* Tensor #106 */
AI_STATIC ai_tensor conv2d_27_weights;   /* Tensor #107 */
AI_STATIC ai_tensor conv2d_27_bias;   /* Tensor #108 */
AI_STATIC ai_tensor conv2d_28_weights;   /* Tensor #109 */
AI_STATIC ai_tensor conv2d_28_bias;   /* Tensor #110 */
AI_STATIC ai_tensor conv2d_29_weights;   /* Tensor #111 */
AI_STATIC ai_tensor conv2d_29_bias;   /* Tensor #112 */
AI_STATIC ai_tensor conv2d_30_weights;   /* Tensor #113 */
AI_STATIC ai_tensor conv2d_30_bias;   /* Tensor #114 */
AI_STATIC ai_tensor conv2d_31_weights;   /* Tensor #115 */
AI_STATIC ai_tensor conv2d_31_bias;   /* Tensor #116 */
AI_STATIC ai_tensor conv2d_33_weights;   /* Tensor #117 */
AI_STATIC ai_tensor conv2d_33_bias;   /* Tensor #118 */
AI_STATIC ai_tensor conv2d_34_weights;   /* Tensor #119 */
AI_STATIC ai_tensor conv2d_34_bias;   /* Tensor #120 */
AI_STATIC ai_tensor conv2d_35_weights;   /* Tensor #121 */
AI_STATIC ai_tensor conv2d_35_bias;   /* Tensor #122 */
AI_STATIC ai_tensor conv2d_37_weights;   /* Tensor #123 */
AI_STATIC ai_tensor conv2d_37_bias;   /* Tensor #124 */
AI_STATIC ai_tensor conv2d_38_weights;   /* Tensor #125 */
AI_STATIC ai_tensor conv2d_38_bias;   /* Tensor #126 */
AI_STATIC ai_tensor conv2d_39_weights;   /* Tensor #127 */
AI_STATIC ai_tensor conv2d_39_bias;   /* Tensor #128 */
AI_STATIC ai_tensor conv2d_41_weights;   /* Tensor #129 */
AI_STATIC ai_tensor conv2d_41_bias;   /* Tensor #130 */
AI_STATIC ai_tensor conv2d_42_weights;   /* Tensor #131 */
AI_STATIC ai_tensor conv2d_42_bias;   /* Tensor #132 */
AI_STATIC ai_tensor conv2d_43_weights;   /* Tensor #133 */
AI_STATIC ai_tensor conv2d_43_bias;   /* Tensor #134 */
AI_STATIC ai_tensor conv2d_44_weights;   /* Tensor #135 */
AI_STATIC ai_tensor conv2d_44_bias;   /* Tensor #136 */
AI_STATIC ai_tensor conv2d_45_weights;   /* Tensor #137 */
AI_STATIC ai_tensor conv2d_45_bias;   /* Tensor #138 */
AI_STATIC ai_tensor conv2d_46_weights;   /* Tensor #139 */
AI_STATIC ai_tensor conv2d_46_bias;   /* Tensor #140 */
AI_STATIC ai_tensor conv2d_48_weights;   /* Tensor #141 */
AI_STATIC ai_tensor conv2d_48_bias;   /* Tensor #142 */
AI_STATIC ai_tensor conv2d_49_weights;   /* Tensor #143 */
AI_STATIC ai_tensor conv2d_49_bias;   /* Tensor #144 */
AI_STATIC ai_tensor conv2d_50_weights;   /* Tensor #145 */
AI_STATIC ai_tensor conv2d_50_bias;   /* Tensor #146 */
AI_STATIC ai_tensor conv2d_52_weights;   /* Tensor #147 */
AI_STATIC ai_tensor conv2d_52_bias;   /* Tensor #148 */
AI_STATIC ai_tensor conv2d_54_weights;   /* Tensor #149 */
AI_STATIC ai_tensor conv2d_54_bias;   /* Tensor #150 */
AI_STATIC ai_tensor conv2d_55_weights;   /* Tensor #151 */
AI_STATIC ai_tensor conv2d_55_bias;   /* Tensor #152 */
AI_STATIC ai_tensor conv2d_56_weights;   /* Tensor #153 */
AI_STATIC ai_tensor conv2d_56_bias;   /* Tensor #154 */
AI_STATIC ai_tensor conv2d_57_weights;   /* Tensor #155 */
AI_STATIC ai_tensor conv2d_57_bias;   /* Tensor #156 */
AI_STATIC ai_tensor conv2d_58_weights;   /* Tensor #157 */
AI_STATIC ai_tensor conv2d_58_bias;   /* Tensor #158 */
AI_STATIC ai_tensor conv2d_60_weights;   /* Tensor #159 */
AI_STATIC ai_tensor conv2d_60_bias;   /* Tensor #160 */
AI_STATIC ai_tensor conv2d_61_weights;   /* Tensor #161 */
AI_STATIC ai_tensor conv2d_61_bias;   /* Tensor #162 */
AI_STATIC ai_tensor conv2d_62_weights;   /* Tensor #163 */
AI_STATIC ai_tensor conv2d_62_bias;   /* Tensor #164 */
AI_STATIC ai_tensor conv2d_64_weights;   /* Tensor #165 */
AI_STATIC ai_tensor conv2d_64_bias;   /* Tensor #166 */
AI_STATIC ai_tensor conv2d_65_weights;   /* Tensor #167 */
AI_STATIC ai_tensor conv2d_65_bias;   /* Tensor #168 */
AI_STATIC ai_tensor conv2d_66_weights;   /* Tensor #169 */
AI_STATIC ai_tensor conv2d_66_bias;   /* Tensor #170 */
AI_STATIC ai_tensor conv2d_67_weights;   /* Tensor #171 */
AI_STATIC ai_tensor conv2d_67_bias;   /* Tensor #172 */
AI_STATIC ai_tensor dense_69_weights;   /* Tensor #173 */
AI_STATIC ai_tensor dense_69_bias;   /* Tensor #174 */
AI_STATIC ai_tensor dense_70_weights;   /* Tensor #175 */
AI_STATIC ai_tensor dense_70_bias;   /* Tensor #176 */
AI_STATIC ai_tensor conv2d_2_scratch0;   /* Tensor #177 */
AI_STATIC ai_tensor conv2d_2_scratch1;   /* Tensor #178 */
AI_STATIC ai_tensor conv2d_3_scratch0;   /* Tensor #179 */
AI_STATIC ai_tensor conv2d_3_scratch1;   /* Tensor #180 */
AI_STATIC ai_tensor conv2d_4_scratch0;   /* Tensor #181 */
AI_STATIC ai_tensor conv2d_5_scratch0;   /* Tensor #182 */
AI_STATIC ai_tensor conv2d_5_scratch1;   /* Tensor #183 */
AI_STATIC ai_tensor conv2d_7_scratch0;   /* Tensor #184 */
AI_STATIC ai_tensor conv2d_7_scratch1;   /* Tensor #185 */
AI_STATIC ai_tensor conv2d_8_scratch0;   /* Tensor #186 */
AI_STATIC ai_tensor conv2d_9_scratch0;   /* Tensor #187 */
AI_STATIC ai_tensor conv2d_9_scratch1;   /* Tensor #188 */
AI_STATIC ai_tensor conv2d_10_scratch0;   /* Tensor #189 */
AI_STATIC ai_tensor conv2d_10_scratch1;   /* Tensor #190 */
AI_STATIC ai_tensor conv2d_11_scratch0;   /* Tensor #191 */
AI_STATIC ai_tensor conv2d_13_scratch0;   /* Tensor #192 */
AI_STATIC ai_tensor conv2d_13_scratch1;   /* Tensor #193 */
AI_STATIC ai_tensor conv2d_15_scratch0;   /* Tensor #194 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #195 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #196 */
AI_STATIC ai_tensor conv2d_17_scratch1;   /* Tensor #197 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #198 */
AI_STATIC ai_tensor conv2d_18_scratch1;   /* Tensor #199 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #200 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #201 */
AI_STATIC ai_tensor conv2d_21_scratch1;   /* Tensor #202 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #203 */
AI_STATIC ai_tensor conv2d_22_scratch1;   /* Tensor #204 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #205 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #206 */
AI_STATIC ai_tensor conv2d_25_scratch1;   /* Tensor #207 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #208 */
AI_STATIC ai_tensor conv2d_27_scratch1;   /* Tensor #209 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #210 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #211 */
AI_STATIC ai_tensor conv2d_29_scratch1;   /* Tensor #212 */
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #213 */
AI_STATIC ai_tensor conv2d_30_scratch1;   /* Tensor #214 */
AI_STATIC ai_tensor conv2d_31_scratch0;   /* Tensor #215 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #216 */
AI_STATIC ai_tensor conv2d_33_scratch1;   /* Tensor #217 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #218 */
AI_STATIC ai_tensor conv2d_34_scratch1;   /* Tensor #219 */
AI_STATIC ai_tensor conv2d_35_scratch0;   /* Tensor #220 */
AI_STATIC ai_tensor conv2d_37_scratch0;   /* Tensor #221 */
AI_STATIC ai_tensor conv2d_37_scratch1;   /* Tensor #222 */
AI_STATIC ai_tensor conv2d_38_scratch0;   /* Tensor #223 */
AI_STATIC ai_tensor conv2d_38_scratch1;   /* Tensor #224 */
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #225 */
AI_STATIC ai_tensor conv2d_41_scratch0;   /* Tensor #226 */
AI_STATIC ai_tensor conv2d_41_scratch1;   /* Tensor #227 */
AI_STATIC ai_tensor conv2d_42_scratch0;   /* Tensor #228 */
AI_STATIC ai_tensor conv2d_42_scratch1;   /* Tensor #229 */
AI_STATIC ai_tensor conv2d_43_scratch0;   /* Tensor #230 */
AI_STATIC ai_tensor conv2d_44_scratch0;   /* Tensor #231 */
AI_STATIC ai_tensor conv2d_44_scratch1;   /* Tensor #232 */
AI_STATIC ai_tensor conv2d_45_scratch0;   /* Tensor #233 */
AI_STATIC ai_tensor conv2d_45_scratch1;   /* Tensor #234 */
AI_STATIC ai_tensor conv2d_46_scratch0;   /* Tensor #235 */
AI_STATIC ai_tensor conv2d_48_scratch0;   /* Tensor #236 */
AI_STATIC ai_tensor conv2d_48_scratch1;   /* Tensor #237 */
AI_STATIC ai_tensor conv2d_49_scratch0;   /* Tensor #238 */
AI_STATIC ai_tensor conv2d_49_scratch1;   /* Tensor #239 */
AI_STATIC ai_tensor conv2d_50_scratch0;   /* Tensor #240 */
AI_STATIC ai_tensor conv2d_52_scratch0;   /* Tensor #241 */
AI_STATIC ai_tensor conv2d_52_scratch1;   /* Tensor #242 */
AI_STATIC ai_tensor conv2d_54_scratch0;   /* Tensor #243 */
AI_STATIC ai_tensor conv2d_54_scratch1;   /* Tensor #244 */
AI_STATIC ai_tensor conv2d_55_scratch0;   /* Tensor #245 */
AI_STATIC ai_tensor conv2d_56_scratch0;   /* Tensor #246 */
AI_STATIC ai_tensor conv2d_56_scratch1;   /* Tensor #247 */
AI_STATIC ai_tensor conv2d_57_scratch0;   /* Tensor #248 */
AI_STATIC ai_tensor conv2d_58_scratch0;   /* Tensor #249 */
AI_STATIC ai_tensor conv2d_60_scratch0;   /* Tensor #250 */
AI_STATIC ai_tensor conv2d_60_scratch1;   /* Tensor #251 */
AI_STATIC ai_tensor conv2d_61_scratch0;   /* Tensor #252 */
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
AI_STATIC_CONST ai_tensor_chain dense_70_chain;   /* Chain #64 */
AI_STATIC_CONST ai_tensor_chain dense_70_fmt_chain;   /* Chain #65 */
AI_STATIC_CONST ai_tensor_chain nl_71_chain;   /* Chain #66 */
AI_STATIC_CONST ai_tensor_chain nl_71_fmt_chain;   /* Chain #67 */


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
AI_STATIC ai_layer_dense dense_70_layer; /* Layer #64 */
AI_STATIC ai_layer_nl dense_70_fmt_layer; /* Layer #65 */
AI_STATIC ai_layer_nl nl_71_layer; /* Layer #66 */
AI_STATIC ai_layer_nl nl_71_fmt_layer; /* Layer #67 */




/**  Array declarations section  **********************************************/
/* Array#0 */
AI_ARRAY_OBJ_DECLARE(
  sequential_3_input_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 150528, AI_STATIC)

/* Array#1 */
AI_ARRAY_OBJ_DECLARE(
  conversion_0_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#2 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#3 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#4 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 100352, AI_STATIC)

/* Array#5 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 602112, AI_STATIC)

/* Array#6 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#7 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#8 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#9 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#10 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#11 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_12_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 25088, AI_STATIC)

/* Array#12 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#13 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#14 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#15 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#16 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#17 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#18 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_20_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#19 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#20 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#21 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#22 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_24_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12544, AI_STATIC)

/* Array#23 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#24 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#25 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#26 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#27 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#28 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#29 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_32_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#30 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#31 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#32 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#33 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_36_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#34 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#35 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#36 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#37 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_40_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4704, AI_STATIC)

/* Array#38 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#39 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#40 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#41 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#42 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#43 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#44 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_47_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#45 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#46 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#47 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#48 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_51_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6272, AI_STATIC)

/* Array#49 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#50 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9408, AI_STATIC)

/* Array#51 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#52 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#53 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#54 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#55 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_59_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#56 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#57 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#58 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#59 */
AI_ARRAY_OBJ_DECLARE(
  eltwise_63_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2744, AI_STATIC)

/* Array#60 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#61 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#62 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5488, AI_STATIC)

/* Array#63 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1280, AI_STATIC)

/* Array#64 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 100, AI_STATIC)

/* Array#65 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_output_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  nl_71_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 6, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  nl_71_fmt_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 6, AI_STATIC)

/* Array#69 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#70 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#71 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#72 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#73 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128, AI_STATIC)

/* Array#74 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#75 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#76 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#77 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#78 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#79 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#80 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#81 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#82 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#83 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#84 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#85 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#86 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 8, AI_STATIC)

/* Array#87 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 384, AI_STATIC)

/* Array#88 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#89 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 432, AI_STATIC)

/* Array#90 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 48, AI_STATIC)

/* Array#91 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 768, AI_STATIC)

/* Array#92 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#93 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#94 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#95 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#96 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#97 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#98 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#99 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#100 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#101 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#102 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#103 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#104 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 16, AI_STATIC)

/* Array#105 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#106 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#107 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 864, AI_STATIC)

/* Array#108 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 96, AI_STATIC)

/* Array#109 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2304, AI_STATIC)

/* Array#110 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#111 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#112 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#113 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#114 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#115 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#116 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#117 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#118 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#119 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#120 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#121 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#122 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#123 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#124 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#125 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#126 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#127 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#128 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 24, AI_STATIC)

/* Array#129 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3456, AI_STATIC)

/* Array#130 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#131 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1296, AI_STATIC)

/* Array#132 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 144, AI_STATIC)

/* Array#133 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 4608, AI_STATIC)

/* Array#134 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#135 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#136 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#137 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#138 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#139 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#140 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#141 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#142 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#143 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#144 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#145 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#146 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 32, AI_STATIC)

/* Array#147 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 6144, AI_STATIC)

/* Array#148 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#149 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1728, AI_STATIC)

/* Array#150 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 192, AI_STATIC)

/* Array#151 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 10752, AI_STATIC)

/* Array#152 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#153 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#154 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#155 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#156 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#157 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#158 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#159 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#160 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#161 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#162 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#163 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#164 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 56, AI_STATIC)

/* Array#165 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#166 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#167 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3024, AI_STATIC)

/* Array#168 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 336, AI_STATIC)

/* Array#169 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#170 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 112, AI_STATIC)

/* Array#171 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 143360, AI_STATIC)

/* Array#172 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 1280, AI_STATIC)

/* Array#173 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 128000, AI_STATIC)

/* Array#174 */
AI_ARRAY_OBJ_DECLARE(
  dense_69_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 100, AI_STATIC)

/* Array#175 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_weights_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 600, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 6, AI_STATIC)

/* Array#177 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1196, AI_STATIC)

/* Array#178 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_2_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#179 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 593, AI_STATIC)

/* Array#180 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_3_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 200704, AI_STATIC)

/* Array#181 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_4_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 144, AI_STATIC)

/* Array#182 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#183 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_5_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 602112, AI_STATIC)

/* Array#184 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#185 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_7_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#186 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_8_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#187 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#188 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_9_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#189 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#190 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_10_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#191 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_11_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 272, AI_STATIC)

/* Array#192 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 512, AI_STATIC)

/* Array#193 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_13_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 150528, AI_STATIC)

/* Array#194 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_15_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1777, AI_STATIC)

/* Array#195 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9408, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1328, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

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
  NULL, NULL, 16464, AI_STATIC)

/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

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
  NULL, NULL, 62720, AI_STATIC)

/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 62720, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(sequential_3_input_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006551326718181372f),
    AI_PACK_UINTQ_ZP(151)))

/* Int quant #1 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conversion_0_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006551326718181372f),
    AI_PACK_INTQ_ZP(23)))

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
    AI_PACK_INTQ_SCALE(0.23446328938007355f),
    AI_PACK_INTQ_ZP(6)))

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
    AI_PACK_INTQ_SCALE(0.17924721539020538f),
    AI_PACK_INTQ_ZP(9)))

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
    AI_PACK_INTQ_SCALE(0.3843798041343689f),
    AI_PACK_INTQ_ZP(-8)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3642950654029846f),
    AI_PACK_INTQ_ZP(-12)))

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
    AI_PACK_INTQ_SCALE(0.023157231509685516f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #14 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16940326988697052f),
    AI_PACK_INTQ_ZP(1)))

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
    AI_PACK_INTQ_SCALE(0.22618116438388824f),
    AI_PACK_INTQ_ZP(-15)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.29986411333084106f),
    AI_PACK_INTQ_ZP(-24)))

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
    AI_PACK_INTQ_SCALE(0.18562893569469452f),
    AI_PACK_INTQ_ZP(-16)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.32854679226875305f),
    AI_PACK_INTQ_ZP(-30)))

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
    AI_PACK_INTQ_SCALE(0.15627214312553406f),
    AI_PACK_INTQ_ZP(6)))

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
    AI_PACK_INTQ_SCALE(0.154734268784523f),
    AI_PACK_INTQ_ZP(-18)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17821279168128967f),
    AI_PACK_INTQ_ZP(-7)))

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
    AI_PACK_INTQ_SCALE(0.14167913794517517f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18875060975551605f),
    AI_PACK_INTQ_ZP(-4)))

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
    AI_PACK_INTQ_SCALE(0.13852053880691528f),
    AI_PACK_INTQ_ZP(-14)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_40_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.21644911170005798f),
    AI_PACK_INTQ_ZP(-5)))

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
    AI_PACK_INTQ_SCALE(0.15945583581924438f),
    AI_PACK_INTQ_ZP(16)))

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
    AI_PACK_INTQ_SCALE(0.13888220489025116f),
    AI_PACK_INTQ_ZP(14)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.19149065017700195f),
    AI_PACK_INTQ_ZP(23)))

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
    AI_PACK_INTQ_SCALE(0.15307757258415222f),
    AI_PACK_INTQ_ZP(2)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_51_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.2040451318025589f),
    AI_PACK_INTQ_ZP(10)))

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
    AI_PACK_INTQ_SCALE(0.13263091444969177f),
    AI_PACK_INTQ_ZP(1)))

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
    AI_PACK_INTQ_SCALE(0.023433895781636238f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #54 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.10278354585170746f),
    AI_PACK_INTQ_ZP(-6)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_59_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.1381102353334427f),
    AI_PACK_INTQ_ZP(-5)))

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
    AI_PACK_INTQ_SCALE(0.021250765770673752f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #58 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.17740891873836517f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_63_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.16265712678432465f),
    AI_PACK_INTQ_ZP(-6)))

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
    AI_PACK_INTQ_SCALE(0.09431306272745132f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.019747838377952576f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.04174427315592766f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.07757066935300827f),
    AI_PACK_INTQ_ZP(-20)))

/* Int quant #66 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(nl_71_fmt_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_U8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00390625f),
    AI_PACK_UINTQ_ZP(0)))

/* Int quant #67 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006357043515890837f, 0.01532160583883524f, 0.0066710710525512695f, 3.0066286171859247e-07f, 0.006800525821745396f, 2.177353479737576e-07f, 0.0034435198176652193f, 2.191698911246931e-08f, 0.003978225868195295f, 0.015115455724298954f, 0.004665786400437355f, 2.252451594131344e-07f, 0.010604714043438435f, 5.114083734270025e-08f, 0.0059135183691978455f, 0.015915120020508766f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.164706842857413e-05f, 0.00010037684842245653f, 4.3704367271857336e-05f, 1.9697405928553735e-09f, 4.4552467443281785e-05f, 1.4264553982457073e-09f, 2.255962317576632e-05f, 1.435853519415886e-10f, 2.6062656615977176e-05f, 9.902629244606942e-05f, 3.056709101656452e-05f, 1.4756545985150638e-09f, 6.947494694031775e-05f, 3.350403288138182e-10f, 3.874138928949833e-05f, 0.00010426514927530661f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #69 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011045568622648716f, 0.005878211464732885f, 0.010417761281132698f, 0.17514193058013916f, 0.011570106260478497f, 0.16459959745407104f, 0.010207368060946465f, 0.006787153426557779f, 0.006147226318717003f, 0.006388559006154537f, 0.016864372417330742f, 0.2920999825000763f, 0.009051661007106304f, 0.12335662543773651f, 0.00825369730591774f, 0.0041795154102146626f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #70 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00025989575078710914f, 0.000138310861075297f, 0.0002451238106004894f, 0.00412098690867424f, 0.0002722378121688962f, 0.0038729317020624876f, 0.0002401733654551208f, 0.0001596977235749364f, 0.00014464062405750155f, 0.0001503190433140844f, 0.00039680878398939967f, 0.006872940808534622f, 0.00021298025967553258f, 0.00290250894613564f, 0.00019420465105213225f, 9.834153752308339e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #71 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.05702180787920952f, 0.05349180847406387f, 0.0441674143075943f, 0.04513700306415558f, 0.07580568641424179f, 0.08323173969984055f, 0.07892855256795883f, 0.043226808309555054f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #72 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_4_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013416896108537912f, 0.001258630771189928f, 0.0010392332915216684f, 0.0010620472021400928f, 0.001783663290552795f, 0.001958393957465887f, 0.0018571424297988415f, 0.0010171013418585062f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #73 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.012586666271090508f, 0.0012817652896046638f, 0.0010751852532848716f, 0.00045756148756481707f, 0.0008011475438252091f, 0.011962365359067917f, 0.0019281662534922361f, 0.0006156168528832495f, 0.0032777816522866488f, 0.0007591744652017951f, 0.000571438402403146f, 0.005666924640536308f, 0.001921502174809575f, 0.008752254769206047f, 0.0006182172219268978f, 0.009968981146812439f, 0.0014177780831232667f, 0.0007319658761844039f, 0.0005927677848376334f, 0.0010337074054405093f, 0.0009172080317512155f, 0.001038186950609088f, 0.01270560547709465f, 0.007066643331199884f, 0.0009092944674193859f, 0.001657048356719315f, 0.0012901548761874437f, 0.0013737675035372376f, 0.0023969600442796946f, 0.000373286398826167f, 0.00852396059781313f, 0.0015631259884685278f, 0.0007974047330208123f, 0.0005579154239967465f, 0.0036649471148848534f, 0.0023517082445323467f, 0.0022366587072610855f, 0.0010011778213083744f, 0.0014174997340887785f, 0.0011027466971427202f, 0.010991305112838745f, 0.0019479920156300068f, 0.00034554509329609573f, 0.0015640342608094215f, 0.0009620565688237548f, 0.008597319014370441f, 0.005953194573521614f, 0.010136542841792107f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #74 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.002951111178845167f, 0.0003005269099958241f, 0.0002520914713386446f, 0.0001072813684004359f, 0.00018783968698699027f, 0.002804735442623496f, 0.0004520842048805207f, 0.00014433955948334187f, 0.0007685194723308086f, 0.0001779985468601808f, 0.0001339813316008076f, 0.001328685786575079f, 0.00045052170753479004f, 0.002052082447335124f, 0.00014494924107566476f, 0.002337360056117177f, 0.00033241690834984183f, 0.00017161913274321705f, 0.00013898228644393384f, 0.00024236644094344229f, 0.00021505160839296877f, 0.00024341672542504966f, 0.002978998003527522f, 0.0016568684950470924f, 0.00021319616644177586f, 0.00038851701538078487f, 0.00030249395058490336f, 0.00032209805794991553f, 0.0005619991570711136f, 8.752195572014898e-05f, 0.0019985558465123177f, 0.0003664956602733582f, 0.0001869621337391436f, 0.0001308106875512749f, 0.0008592955418862402f, 0.0005513892392627895f, 0.0005244143540039659f, 0.00023473944747820497f, 0.00033235165756195784f, 0.00025855362764559686f, 0.00257705757394433f, 0.0004567326104734093f, 8.101764251478016e-05f, 0.00036670861300081015f, 0.00022556695330422372f, 0.00201575574465096f, 0.0013958056224510074f, 0.0023766472004354f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #75 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006960022146813571f, 0.004673338029533625f, 0.005799285601824522f, 0.004585325717926025f, 0.005473228637129068f, 0.00115619704592973f, 0.004120686557143927f, 0.010039376094937325f, 0.001568538835272193f, 0.00394756393507123f, 0.0040725162252783775f, 0.0028358863200992346f, 0.007163539528846741f, 0.0012513885740190744f, 0.0033775523770600557f, 0.0005161665030755103f, 0.001948601333424449f, 0.004133909475058317f, 0.007741581182926893f, 0.0026559168472886086f, 0.005252061411738396f, 0.0036667142994701862f, 0.0005644145421683788f, 0.004182825330644846f, 0.004516607150435448f, 0.0049261474050581455f, 0.00824637059122324f, 0.004581396467983723f, 0.001819623401388526f, 0.007973470725119114f, 0.0004927467089146376f, 0.00237667141482234f, 0.004740975797176361f, 0.005115050356835127f, 0.0009502918110229075f, 0.001618427806533873f, 0.0015871014911681414f, 0.00458196084946394f, 0.009036456234753132f, 0.004105257801711559f, 0.0015166423982009292f, 0.002240625210106373f, 0.00394262233749032f, 0.0020661959424614906f, 0.0040962062776088715f, 0.0009301933459937572f, 0.001022531883791089f, 0.000568293733522296f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #76 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(1.637652349018026e-05f, 0.00010996089986292645f, 0.00013645377475768328f, 0.00010789001680677757f, 0.000128781859530136f, 2.72046363534173e-05f, 9.695733024273068e-05f, 0.00023622061416972429f, 3.6906796594848856e-05f, 9.288385626859963e-05f, 9.582391066942364e-05f, 6.672673771390691e-05f, 0.00016855387366376817f, 2.944443804153707e-05f, 7.947182166390121e-05f, 1.2145094842708204e-05f, 4.584944326779805e-05f, 9.726845746627077e-05f, 0.0001821548503357917f, 6.249215948628262e-05f, 0.00012357792002148926f, 8.627563511254266e-05f, 1.3280342500365805e-05f, 9.841941937338561e-05f, 0.00010627310985000804f, 0.0001159093517344445f, 0.0001940322545124218f, 0.00010779756848933175f, 4.28146704507526e-05f, 0.00018761107639875263f, 1.1594040188356303e-05f, 5.592168236034922e-05f, 0.00011155237734783441f, 0.00012035412510158494f, 2.2359807189786807e-05f, 3.8080655940575525e-05f, 3.734356505447067e-05f, 0.00010781084711197764f, 0.00021262250083964318f, 9.659430361352861e-05f, 3.5685705370269716e-05f, 5.272059570415877e-05f, 9.276758646592498e-05f, 4.861637717112899e-05f, 9.638132905820385e-05f, 2.1886902686674148e-05f, 2.4059574570856057e-05f, 1.3371617569646332e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #77 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.037059299647808075f, 0.03565175458788872f, 0.029089994728565216f, 0.02369472198188305f, 0.04832087457180023f, 0.027682261541485786f, 0.03448175638914108f, 0.02806408703327179f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #78 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_8_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.000871983531396836f, 0.0008388648275285959f, 0.0006844704621471465f, 0.0005575228715315461f, 0.0011369617423042655f, 0.0006513473344966769f, 0.0008113354560919106f, 0.000660331454128027f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #79 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001017079339362681f, 0.002131299115717411f, 0.0002862555265892297f, 0.0011835290351882577f, 0.0034716646187007427f, 0.0005405258270911872f, 0.0010831733234226704f, 0.0009075585403479636f, 0.0004938346100971103f, 0.0021115203853696585f, 0.0034805568866431713f, 0.002455348614603281f, 0.0023201906587928534f, 0.004251317121088505f, 0.0022003273479640484f, 0.0012369983596727252f, 0.000565946742426604f, 0.0007589730084873736f, 0.00027922142180614173f, 0.000594393233768642f, 0.0003193699521943927f, 0.0008273484418168664f, 0.0016218307428061962f, 0.0020829495042562485f, 0.0010379379382357001f, 0.0015886692563071847f, 0.0016789025394245982f, 0.001364257768727839f, 0.000891864241566509f, 0.0009115570574067533f, 0.0013238688698038459f, 0.0012424695305526257f, 0.0008924577268771827f, 0.0008691827533766627f, 0.0011589425848796964f, 0.0006054104887880385f, 0.001705998438410461f, 0.00033688341500237584f, 0.001857386203482747f, 0.0011845112312585115f, 0.0016652008052915335f, 0.002423427067697048f, 0.000781745882704854f, 0.0006461389129981399f, 0.001919467467814684f, 0.001695882878266275f, 0.002717105206102133f, 0.0016281019197776914f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #80 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001823086349759251f, 0.00038202942232601345f, 5.1310507842572406e-05f, 0.00021214428124949336f, 0.0006222862284630537f, 9.688775026006624e-05f, 0.00019415580027271062f, 0.00016267734463326633f, 8.851847815094516e-05f, 0.00037848413921892643f, 0.0006238801288418472f, 0.0004401144105941057f, 0.0004158877127338201f, 0.000762036768719554f, 0.00039440253749489784f, 0.00022172850731294602f, 0.00010144437692360952f, 0.0001360438036499545f, 5.004966078558937e-05f, 0.0001065433316398412f, 5.724617585656233e-05f, 0.0001482999068684876f, 0.0002907086454797536f, 0.00037336291279643774f, 0.00018604748765937984f, 0.00028476453735493124f, 0.00030093861278146505f, 0.00024453940568491817f, 0.00015986418293323368f, 0.00016339407011400908f, 0.00023729981330689043f, 0.00022270920453593135f, 0.00015997055743355304f, 0.00015579858154524118f, 0.00020773723372258246f, 0.00010851814295165241f, 0.0003057954600080848f, 6.038541323505342e-05f, 0.0003329313185531646f, 0.00021232034487184137f, 0.0002984825987368822f, 0.00043439253931865096f, 0.0001401257759425789f, 0.00011581859871512279f, 0.0003440591972321272f, 0.00030398229137063026f, 0.00048703353968448937f, 0.00029183272272348404f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #81 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.021313272416591644f, 0.006490278989076614f, 0.020576300099492073f, 0.007142683491110802f, 0.00422650994732976f, 0.02407088689506054f, 0.008956119418144226f, 0.0054772039875388145f, 0.005267311353236437f, 0.007645723409950733f, 0.0015962872421368957f, 0.008162637241184711f, 0.002049105940386653f, 0.005241465289145708f, 0.004957308527082205f, 0.012294958345592022f, 0.01115544606000185f, 0.008056494407355785f, 0.016579287126660347f, 0.013341553509235382f, 0.008352316915988922f, 0.005031525623053312f, 0.006723926402628422f, 0.004011381417512894f, 0.005998631473630667f, 0.003378578694537282f, 0.004221027251332998f, 0.006701176054775715f, 0.0038175228983163834f, 0.012925872579216957f, 0.007007913198322058f, 0.003603234188631177f, 0.008853822015225887f, 0.014881474897265434f, 0.006297164596617222f, 0.0077528818510472775f, 0.006758439354598522f, 0.010019076056778431f, 0.0036080246791243553f, 0.0041971635073423386f, 0.011049061082303524f, 0.006143603473901749f, 0.009119655005633831f, 0.009451356716454029f, 0.0047742086462676525f, 0.0049794199876487255f, 0.007149261888116598f, 0.0049676732160151005f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #82 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005014888010919094f, 0.00015271245501935482f, 0.0004841482441406697f, 0.00016806313942652196f, 9.94472939055413e-05f, 0.0005663738120347261f, 0.00021073222160339355f, 0.0001288753846893087f, 0.00012393674114719033f, 0.000179899376234971f, 3.75597010133788e-05f, 0.00019206205615773797f, 4.821425682166591e-05f, 0.00012332860205788165f, 0.00011664255725918338f, 0.0002892931515816599f, 0.0002624811022542417f, 0.0001895645837066695f, 0.0003901008749380708f, 0.0003139189211651683f, 0.00019652511400636286f, 0.0001183888380182907f, 0.00015821003762539476f, 9.438544657314196e-05f, 0.00014114427904132754f, 7.949597056722268e-05f, 9.931829117704183e-05f, 0.00015767473087180406f, 8.982406870927662e-05f, 0.00030413817148655653f, 0.00016489207337144762f, 8.47819828777574e-05f, 0.00020832523296121508f, 0.0003501523460727185f, 0.00014816857583355159f, 0.00018242075748275965f, 0.00015902210725471377f, 0.0002357429766561836f, 8.489470201311633e-05f, 9.875679097604007e-05f, 0.0002599779109004885f, 0.00014455537893809378f, 0.0002145801263395697f, 0.0002223848714493215f, 0.0001123343245126307f, 0.00011716282460838556f, 0.0001682179281488061f, 0.00011688643280649558f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #83 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03518914058804512f, 0.020869262516498566f, 0.019674159586429596f, 0.025971049442887306f, 0.021713411435484886f, 0.04816604405641556f, 0.06079145893454552f, 0.021404998376965523f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #84 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_11_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 8,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008279798203147948f, 0.0004910414572805166f, 0.0004629214236047119f, 0.0006110835238359869f, 0.0005109038320370018f, 0.0011333187576383352f, 0.0014303872594609857f, 0.000503647024743259f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #85 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009675036417320371f, 0.0010547698475420475f, 0.0012560243485495448f, 0.0007732954691164196f, 0.0008332763100042939f, 0.0017882840475067496f, 0.0006547698867507279f, 0.0008989589405246079f, 0.0007130282465368509f, 0.0011209365911781788f, 0.0005489272298291326f, 0.0007283931481651962f, 0.00065421819454059f, 0.0004280100401956588f, 0.00033523072488605976f, 0.0011892038164660335f, 0.0018630728591233492f, 0.0007714576204307377f, 0.0005209129303693771f, 0.00055219471687451f, 0.0005140864523127675f, 0.0007469253032468259f, 0.0008794002933427691f, 0.0011782123474404216f, 0.004436573013663292f, 0.00023296099971048534f, 0.0006771743064746261f, 0.0005812127492390573f, 0.0007766293128952384f, 0.0003676939522847533f, 0.0003406738687772304f, 0.0011129752965644002f, 0.0007032454595901072f, 0.001539119752123952f, 0.0006005014292895794f, 0.0003835334209725261f, 0.0012015877291560173f, 0.0008785350946709514f, 0.0009102326002903283f, 0.00043066134094260633f, 0.0019643986597657204f, 0.0006454393151216209f, 0.00046006511547602713f, 0.000385434104828164f, 0.00042754350579343736f, 0.0012780373217538f, 0.0005689083482138813f, 0.000866309623233974f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #86 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00035245681647211313f, 0.0003842474543489516f, 0.00045756346662528813f, 0.00028170773293823004f, 0.00030355845228768885f, 0.0006514630513265729f, 0.0002385294355917722f, 0.00032748631201684475f, 0.00025975267635658383f, 0.0004083516832906753f, 0.00019997148774564266f, 0.0002653500414453447f, 0.00023832845909055322f, 0.00015592195268254727f, 0.00012212290312163532f, 0.00043322108103893697f, 0.0006787082529626787f, 0.0002810381993185729f, 0.00018976601131726056f, 0.00020116180530749261f, 0.0001872791617643088f, 0.0002721011987887323f, 0.0003203611995559186f, 0.0004292169469408691f, 0.0016162216197699308f, 8.486654405714944e-05f, 0.0002466912555973977f, 0.00021173294226173311f, 0.00028292223578318954f, 0.00013394909910857677f, 0.0001241058052983135f, 0.0004054513992741704f, 0.0002561888541094959f, 0.0005606937338598073f, 0.000218759712879546f, 0.0001397193263983354f, 0.0004377324949018657f, 0.00032004600507207215f, 0.0003315932408440858f, 0.00015688780695199966f, 0.0007156207575462759f, 0.00023513035557698458f, 0.00016759945719968528f, 0.00014041173562873155f, 0.00015575198631267995f, 0.0004655826778616756f, 0.00020725050126202404f, 0.00031559233320876956f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #87 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0036985899787396193f, 0.002424426842480898f, 0.002129692118614912f, 0.004592704586684704f, 0.0035368611570447683f, 0.005474434234201908f, 0.004075004253536463f, 0.0033992091193795204f, 0.003120408859103918f, 0.002255009487271309f, 0.004713679198175669f, 0.003808041336014867f, 0.003989423159509897f, 0.008738668635487556f, 0.00801039393991232f, 0.0021633461583405733f, 0.0011027025757357478f, 0.003908209037035704f, 0.004193196073174477f, 0.004183213692158461f, 0.004007310606539249f, 0.0042038350366055965f, 0.0029793153516948223f, 0.0038374383002519608f, 0.002890408504754305f, 0.01395254023373127f, 0.004817186389118433f, 0.006230649538338184f, 0.0035423021763563156f, 0.006067323498427868f, 0.009881108067929745f, 0.0022567410487681627f, 0.003887324593961239f, 0.005827582441270351f, 0.004237550776451826f, 0.008753021247684956f, 0.001348186400718987f, 0.003215428441762924f, 0.005108474753797054f, 0.004579445812851191f, 0.00292237033136189f, 0.006353194825351238f, 0.006933968048542738f, 0.008057999424636364f, 0.004049874842166901f, 0.0023936040233820677f, 0.004114138428121805f, 0.0030662897042930126f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #88 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 48,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.70256480993703e-05f, 5.7045337598538026e-05f, 5.011040411773138e-05f, 0.00010806364298332483f, 8.322026405949146e-05f, 0.00012881022121291608f, 9.588245302438736e-05f, 7.998139335541055e-05f, 7.342138997046277e-05f, 5.305904778651893e-05f, 0.00011091009946539998f, 8.960097329691052e-05f, 9.38687808229588e-05f, 0.0002056157391052693f, 0.0001884798548417166f, 5.0902264774776995e-05f, 2.594594297988806e-05f, 9.195785969495773e-05f, 9.866344043985009e-05f, 9.842855797614902e-05f, 9.428966586710885e-05f, 9.891376976156607e-05f, 7.0101537858136e-05f, 9.029266948346049e-05f, 6.800961273256689e-05f, 0.0003282950783614069f, 0.00011334556620568037f, 0.00014660351735074073f, 8.334828453371301e-05f, 0.00014276056026574224f, 0.00023249666264746338f, 5.309978951117955e-05f, 9.146646334556863e-05f, 0.00013711958308704197f, 9.970708197215572e-05f, 0.00020595344540197402f, 3.172203287249431e-05f, 7.565713895019144e-05f, 0.00012019940913887694f, 0.00010775167174870148f, 6.876165571156889e-05f, 0.00014948693569749594f, 0.00016315218817908317f, 0.00018959998851642013f, 9.529117232887074e-05f, 5.632009560940787e-05f, 9.680326184025034e-05f, 7.214799552457407e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #89 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.03058595582842827f, 0.034607965499162674f, 0.02364785224199295f, 0.023167096078395844f, 0.030001888051629066f, 0.03777662292122841f, 0.0208623968064785f, 0.02253797836601734f, 0.02401794120669365f, 0.03276862949132919f, 0.02030215598642826f, 0.034247927367687225f, 0.022754158824682236f, 0.03173771873116493f, 0.02456587925553322f, 0.03313188627362251f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #90 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_16_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007082860684022307f, 0.0008014246704988182f, 0.0005476187798194587f, 0.0005364858079701662f, 0.0006947606452740729f, 0.000874802004545927f, 0.0004831153491977602f, 0.0005219171871431172f, 0.000556189042981714f, 0.0007588307489641011f, 0.00047014173469506204f, 0.0007930871797725558f, 0.00052692333701998f, 0.0007349576917476952f, 0.0005688777309842408f, 0.0007672427454963326f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #91 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003089656587690115f, 0.0004838291206397116f, 0.00017781129281502217f, 0.0008234467823058367f, 0.0009271578164771199f, 0.00024155127175617963f, 0.0009230637224391103f, 0.0007802360923960805f, 0.0008994857198558748f, 0.0011913056951016188f, 0.0012332546757534146f, 0.0015985437203198671f, 0.0004099662764929235f, 0.0003840753633994609f, 0.0016305451281368732f, 0.0007052040891721845f, 0.0005121762515045702f, 0.001372852479107678f, 0.0009585617808625102f, 0.0009515102137811482f, 0.0013089260319247842f, 0.0005252670962363482f, 0.0006777063244953752f, 0.000759103917516768f, 0.001322482479736209f, 0.00048058919492177665f, 0.0011758157052099705f, 0.0010295279789716005f, 0.001975556369870901f, 0.0011102553689852357f, 0.0006304102716967463f, 0.0006291887839324772f, 0.0007712783990427852f, 0.0005547546315938234f, 0.002830969402566552f, 0.0002710439439397305f, 0.0008400806691497564f, 0.000380087731173262f, 0.0004178679082542658f, 0.0020765711087733507f, 0.000860546831972897f, 0.0010031063575297594f, 0.0013326340122148395f, 0.00258429697714746f, 0.0016894987784326077f, 0.000931442657019943f, 0.0021500515285879374f, 0.0021338851656764746f, 0.001121513661928475f, 0.0010835917200893164f, 0.0015117806615307927f, 0.0015634124865755439f, 0.0024476510006934404f, 0.00046760126133449376f, 0.00034085693187080324f, 0.0020176435355097055f, 0.0008794533787295222f, 0.00034683311241678894f, 0.0007020310149528086f, 0.0010692768264561892f, 0.0008876799256540835f, 0.0008250043611042202f, 0.0011448680888861418f, 0.0004319168801885098f, 0.0019811303354799747f, 0.0010880857007578015f, 0.0010507915867492557f, 0.0007473832811228931f, 0.001093239989131689f, 0.001393558457493782f, 0.0005537429242394865f, 0.0015284065157175064f, 0.0008589014760218561f, 0.0006303146947175264f, 0.0007258474943228066f, 0.0011488529853522778f, 0.0018996319267898798f, 0.00042567975469864905f, 0.0006226044497452676f, 0.0007919808267615736f, 0.0011536559322848916f, 0.0006415877724066377f, 0.0005240989266894758f, 0.0010029847035184503f, 0.0010121166706085205f, 0.001722774119116366f, 0.0010400769533589482f, 0.0026861855294555426f, 0.002136422088369727f, 0.002156727947294712f, 0.0019091010326519608f, 0.0006342538399621844f, 0.001081110443919897f, 0.0011590488720685244f, 0.001030815183185041f, 0.0019351254450157285f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #92 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005233979318290949f, 8.196223643608391e-05f, 3.0121815143502317e-05f, 0.00013949457206763327f, 0.00015706356498412788f, 4.0919574530562386e-05f, 0.0001563700061524287f, 0.00013217455125413835f, 0.000152375825564377f, 0.00020181108266115189f, 0.00020891737949568778f, 0.00027079854044131935f, 6.944962660782039e-05f, 6.506362115032971e-05f, 0.0002762196818366647f, 0.00011946387530770153f, 8.67643320816569e-05f, 0.00023256569693330675f, 0.00016238349780905992f, 0.0001611889456398785f, 0.0002217363507952541f, 8.898196392692626e-05f, 0.00011480566899990663f, 0.00012859469279646873f, 0.00022403286129701883f, 8.14133818494156e-05f, 0.00019918702309951186f, 0.00017440540250390768f, 0.00033466570312157273f, 0.00018808088498190045f, 0.00010679355909815058f, 0.00010658663813956082f, 0.00013065707753412426f, 9.397725079907104e-05f, 0.00047957547940313816f, 4.591573087964207e-05f, 0.00014231241948436946f, 6.438810669351369e-05f, 7.078819180605933e-05f, 0.00035177794052287936f, 0.00014577944239135832f, 0.00016992949531413615f, 0.00022575256298296154f, 0.0004377883451525122f, 0.00028620660305023193f, 0.00015778942906763405f, 0.0003642257652245462f, 0.000361487123882398f, 0.00018998808809556067f, 0.0001835639850469306f, 0.0002561005821917206f, 0.00026484718546271324f, 0.0004146400897298008f, 7.921318319858983e-05f, 5.7742279750527814e-05f, 0.00034179541398771107f, 0.00014898227527737617f, 5.875466376892291e-05f, 0.0001189263493870385f, 0.00018113899568561465f, 0.0001503758830949664f, 0.00013975844194646925f, 0.00019394440460018814f, 7.316812843782827e-05f, 0.000335609947796911f, 0.00018432526849210262f, 0.0001780075253918767f, 0.00012660917127504945f, 0.00018519842706155032f, 0.00023607336333952844f, 9.380586561746895e-05f, 0.0002589170471765101f, 0.00014550071500707418f, 0.00010677737009245902f, 0.00012296093336772174f, 0.00019461945339571685f, 0.0003218038473278284f, 7.211154297692701e-05f, 0.00010547122656134889f, 0.00013416414731182158f, 0.0001954330800799653f, 0.0001086870688595809f, 8.87840724317357e-05f, 0.00016990888980217278f, 0.00017145587480627f, 0.0002918435784522444f, 0.00017619243590161204f, 0.00045504860463552177f, 0.0003619169001467526f, 0.0003653567691799253f, 0.0003234079631511122f, 0.00010744467726908624f, 0.000183143638423644f, 0.0001963466638699174f, 0.00017462346295360476f, 0.00032781658228486776f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #93 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009803944267332554f, 0.01291519682854414f, 0.031897518783807755f, 0.005656156223267317f, 0.012580139562487602f, 0.0459030345082283f, 0.005537259858101606f, 0.01848357729613781f, 0.00606822595000267f, 0.004457022063434124f, 0.0036431082990020514f, 0.007450487464666367f, 0.004780963994562626f, 0.009797133505344391f, 0.006215493194758892f, 0.005986850708723068f, 0.011866377666592598f, 0.003834829432889819f, 0.00493077514693141f, 0.007047567050904036f, 0.0036755301989614964f, 0.004853225313127041f, 0.004390568006783724f, 0.00345858046784997f, 0.012133501470088959f, 0.012351393699645996f, 0.009086386300623417f, 0.007222156040370464f, 0.010356844402849674f, 0.004816188011318445f, 0.009388292208313942f, 0.006251133978366852f, 0.004159989766776562f, 0.010921875014901161f, 0.005916273221373558f, 0.018330322578549385f, 0.00954001396894455f, 0.013055217452347279f, 0.021512454375624657f, 0.0047265710309147835f, 0.006139322649687529f, 0.007312970235943794f, 0.0023318331222981215f, 0.004009682685136795f, 0.010213040746748447f, 0.008822882547974586f, 0.006723823957145214f, 0.008753552101552486f, 0.008852128870785236f, 0.04047168791294098f, 0.005621174816042185f, 0.007166077848523855f, 0.004500928800553083f, 0.01041493657976389f, 0.03931128606200218f, 0.0044432212598621845f, 0.0038762527983635664f, 0.00691945618018508f, 0.009783928282558918f, 0.01572590135037899f, 0.006593460217118263f, 0.009324658662080765f, 0.00916373822838068f, 0.02391055040061474f, 0.0056819855235517025f, 0.01365065947175026f, 0.014199506491422653f, 0.02252023294568062f, 0.004842860624194145f, 0.00748564163222909f, 0.00828017108142376f, 0.005489542614668608f, 0.0053171152248978615f, 0.009957361966371536f, 0.010587932541966438f, 0.004984275437891483f, 0.0035739820450544357f, 0.028081713244318962f, 0.00369529752060771f, 0.005059247836470604f, 0.006747779436409473f, 0.006485774647444487f, 0.007378845475614071f, 0.0045148590579628944f, 0.009799870662391186f, 0.004148573148995638f, 0.0055725243873894215f, 0.0033723642118275166f, 0.003760840278118849f, 0.0027637567836791277f, 0.011647334322333336f, 0.008340022526681423f, 0.005748629104346037f, 0.007653054315596819f, 0.003688966855406761f, 0.007532397285103798f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #94 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.306810529262293e-05f, 0.00030388697632588446f, 0.0007505298708565533f, 0.00013308602501638234f, 0.000296003301627934f, 0.0010800714371725917f, 0.0001302884629694745f, 0.0004349077062215656f, 0.00014278179151006043f, 0.00010487111285328865f, 8.572019578423351e-05f, 0.00017530558397993445f, 0.00011249327508267015f, 0.0002305207890458405f, 0.00014624690811615437f, 0.00014086707960814238f, 0.0002792088780552149f, 9.023128222906962e-05f, 0.00011601824371609837f, 0.00016582511307206005f, 8.648306538816541e-05f, 0.00011419353540986776f, 0.00010330748773412779f, 8.137836266541854e-05f, 0.00028549417038448155f, 0.00029062104295007885f, 0.00021379733516369015f, 0.00016993308963719755f, 0.00024369046150241047f, 0.00011332207213854417f, 0.0002209009981015697f, 0.0001470855058869347f, 9.7882111731451e-05f, 0.00025698530953377485f, 0.00013920642959419638f, 0.00043130171252414584f, 0.00022447091760113835f, 0.00030718158814124763f, 0.0005061753909103572f, 0.0001112134414142929f, 0.00014445465058088303f, 0.00017206989286933094f, 5.486666123033501e-05f, 9.434547973796725e-05f, 0.0002403068501735106f, 0.00020759724429808557f, 0.00015820762200746685f, 0.00020596593094523996f, 0.0002082853898173198f, 0.0009522750042378902f, 0.00013226293958723545f, 0.0001686135947238654f, 0.00010590421152301133f, 0.0002450573374517262f, 0.0009249714785255492f, 0.00010454638686496764f, 9.120594768319279e-05f, 0.00016281074204016477f, 0.0002302100765518844f, 0.0003700212109833956f, 0.00015514023834839463f, 0.00021940373699180782f, 0.00021561737230513245f, 0.0005626011989079416f, 0.00013369378575589508f, 0.0003211919975001365f, 0.00033410603646188974f, 0.0005298878531903028f, 0.00011394966713851318f, 0.00017613274394534528f, 0.00019482756033539772f, 0.00012916570995002985f, 0.0001251085923286155f, 0.00023429087013937533f, 0.00024912782828323543f, 0.00011727707169484347f, 8.409369911532849e-05f, 0.0006607461837120354f, 8.694818097865209e-05f, 0.00011904112761840224f, 0.00015877129044383764f, 0.0001526064588688314f, 0.00017361989011988044f, 0.00010623197886161506f, 0.00023058519582264125f, 9.761349065229297e-05f, 0.0001311182277277112f, 7.934974564705044e-05f, 8.849036385072395e-05f, 6.502956966869533e-05f, 0.0002740549389272928f, 0.00019623582193162292f, 0.00013526187103707343f, 0.00018007187463808805f, 8.679922029841691e-05f, 0.00017723288328852504f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #95 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0072937654331326485f, 0.015578274615108967f, 0.014443621039390564f, 0.018552491441369057f, 0.012871013022959232f, 0.008878340944647789f, 0.015562742948532104f, 0.014512001536786556f, 0.006717166397720575f, 0.03727472200989723f, 0.014029487036168575f, 0.00808337889611721f, 0.03979111835360527f, 0.04100554436445236f, 0.007310185115784407f, 0.00801785010844469f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #96 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_19_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017161801224574447f, 0.00036654763971455395f, 0.0003398499102331698f, 0.0004365292261354625f, 0.0003028473583981395f, 0.00020890214364044368f, 0.00036618218291550875f, 0.0003414588572923094f, 0.00015805097064003348f, 0.0008770523127168417f, 0.0003301055694464594f, 0.00019019715546164662f, 0.000936261611059308f, 0.0009648363338783383f, 0.0001720043655950576f, 0.000188655307283625f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #97 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0009469864889979362f, 0.00040190585423260927f, 0.0002768736449070275f, 0.0008043725392781198f, 0.0006926886271685362f, 0.002606400055810809f, 0.002519493456929922f, 0.0004611859912984073f, 0.00018406134040560573f, 0.0007503776578232646f, 0.00048684480134397745f, 0.0005090698832646012f, 0.0007199725951068103f, 0.0009184730006381869f, 0.001215958734974265f, 0.0006517813890241086f, 0.0005323522491380572f, 0.0010769158834591508f, 0.0011048467131331563f, 0.000863334396854043f, 0.0003238104982301593f, 0.00044238127884455025f, 0.0007525631808675826f, 0.0007222248241305351f, 0.0018167879898101091f, 0.0012149227550253272f, 0.0009363478166051209f, 0.00069784140214324f, 0.0006148958345875144f, 0.0006955856224521995f, 0.0004893119912594557f, 0.0006329905008897185f, 0.0009085820056498051f, 0.0009253824828192592f, 0.0004357151628937572f, 0.0008728497195988894f, 0.000251333782216534f, 0.000680948025546968f, 0.0005412385798990726f, 0.0005078136455267668f, 0.0010354681871831417f, 0.0007054022280499339f, 0.0018287188140675426f, 0.0008908381569199264f, 0.0009381107520312071f, 0.0007919368799775839f, 0.0008691694238223135f, 0.00039815055788494647f, 0.00044365201028995216f, 0.0009215199388563633f, 0.0004026778042316437f, 0.0007733521633781493f, 0.0007269592024385929f, 0.0009910168591886759f, 0.000669422501232475f, 0.0005160824512131512f, 0.00028791383374482393f, 0.0022336107213050127f, 0.0008103222935460508f, 0.00040819516289047897f, 0.0008026926079764962f, 0.000216949891182594f, 0.0008707365486770868f, 0.0009197572944685817f, 0.0009932680986821651f, 0.001192737021483481f, 0.00044105935376137495f, 0.0009811361087486148f, 0.0005215351702645421f, 0.0006769164465367794f, 0.0005974716041237116f, 0.0002668497618287802f, 0.0003472985699772835f, 0.0004505559627432376f, 0.00040636988705955446f, 0.0008326173410750926f, 0.0011281464248895645f, 0.00024018484691623598f, 0.00048269133549183607f, 0.0011473681079223752f, 0.000758127891458571f, 0.0011659213341772556f, 0.0008203588658943772f, 0.0006402230355888605f, 0.00043015970732085407f, 0.0011703644413501024f, 0.0005316882161423564f, 0.0011569360503926873f, 0.001259123906493187f, 0.0005817892961204052f, 0.0005637442809529603f, 0.00033495426760055125f, 0.0008574388339184225f, 0.000558297208044678f, 0.0011523512657731771f, 0.0008923799614422023f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #98 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00028396726702339947f, 0.00012051714293193072f, 8.302446804009378e-05f, 0.00024120246234815568f, 0.00020771246636286378f, 0.0007815658464096487f, 0.0007555056945420802f, 0.00013829312229063362f, 5.5193391744978726e-05f, 0.0002250113320769742f, 0.00014598728739656508f, 0.00015265178808476776f, 0.0002158939460059628f, 0.00027541708550415933f, 0.00036462239222601056f, 0.00019544584210962057f, 0.00015963333135005087f, 0.0003229284193366766f, 0.00033130389056168497f, 0.0002588829956948757f, 9.709914593258873e-05f, 0.0001326542696915567f, 0.00022566669213119894f, 0.0002165693003917113f, 0.0005447895382530987f, 0.0003643117379397154f, 0.0002807771088555455f, 0.00020925758872181177f, 0.00018438519327901304f, 0.0002085811720462516f, 0.00014672710676677525f, 0.00018981113680638373f, 0.00027245114324614406f, 0.0002774889871943742f, 0.00013065534585621208f, 0.00026173630612902343f, 7.536598423030227e-05f, 0.0002041918778559193f, 0.0001622980198590085f, 0.00015227508265525103f, 0.0003104997449554503f, 0.000211524820770137f, 0.0005483671557158232f, 0.000267130380962044f, 0.00028130575083196163f, 0.0002374734467593953f, 0.00026063271798193455f, 0.0001193910647998564f, 0.00013303531159181148f, 0.00027633077115751803f, 0.00012074862024746835f, 0.00023190055799204856f, 0.00021798897068947554f, 0.00029717039433307946f, 0.00020073578343726695f, 0.0001547546125948429f, 8.633502875454724e-05f, 0.000669779721647501f, 0.00024298657081089914f, 0.0001224030856974423f, 0.00024069870414678007f, 6.505548662971705e-05f, 0.0002611026575323194f, 0.0002758022164925933f, 0.0002978454576805234f, 0.0003576590388547629f, 0.00013225787552073598f, 0.00029420750797726214f, 0.00015638968034181744f, 0.00020298294839449227f, 0.00017916029901243746f, 8.001866808626801e-05f, 0.00010414237476652488f, 0.00013510556891560555f, 0.00012185574450995773f, 0.00024967206991277635f, 0.00033829061430878937f, 7.202281267382205e-05f, 0.0001447418035240844f, 0.00034405451151542366f, 0.00022733534569852054f, 0.0003496179706417024f, 0.00024599619791842997f, 0.00019197991059627384f, 0.00012898945715278387f, 0.00035095028579235077f, 0.00015943421749398112f, 0.0003469235962256789f, 0.0003775660879909992f, 0.0001744577311910689f, 0.00016904667427297682f, 0.00010044076771009713f, 0.00025711514172144234f, 0.00016741329454816878f, 0.00034554878948256373f, 0.00026759272441267967f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #99 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008913255296647549f, 0.009076111018657684f, 0.027996959164738655f, 0.004297307226806879f, 0.007745213340967894f, 0.001347350305877626f, 0.002424537669867277f, 0.008013327606022358f, 0.049562081694602966f, 0.013798614963889122f, 0.0064476365223526955f, 0.016707736998796463f, 0.0030418874230235815f, 0.017399754375219345f, 0.013861012645065784f, 0.007627828046679497f, 0.007017872761934996f, 0.007483878172934055f, 0.005052539054304361f, 0.004830479621887207f, 0.0331023633480072f, 0.006041702348738909f, 0.008470739237964153f, 0.008126629516482353f, 0.0026251415256410837f, 0.0030793510377407074f, 0.008537319488823414f, 0.007548762019723654f, 0.008842552080750465f, 0.008198725059628487f, 0.004605553578585386f, 0.006547986995428801f, 0.008931712247431278f, 0.004161057993769646f, 0.008619271218776703f, 0.004043213091790676f, 0.02038709819316864f, 0.0067794737406075f, 0.0075254072435200214f, 0.008692288771271706f, 0.005278960335999727f, 0.004852297715842724f, 0.0035011915024369955f, 0.0038627726025879383f, 0.010858297348022461f, 0.008484113030135632f, 0.012075974605977535f, 0.008723953738808632f, 0.00801446195691824f, 0.010851806960999966f, 0.013688388280570507f, 0.016931774094700813f, 0.005926256533712149f, 0.0037179396022111177f, 0.005049888510257006f, 0.0050510442815721035f, 0.03593503683805466f, 0.0011278213933110237f, 0.0060269334353506565f, 0.004098203964531422f, 0.009907485917210579f, 0.038187358528375626f, 0.007787939161062241f, 0.01946951262652874f, 0.025632528588175774f, 0.007856636308133602f, 0.00767481280490756f, 0.003412816906347871f, 0.009507540613412857f, 0.006498794071376324f, 0.007328415755182505f, 0.022164655849337578f, 0.011605173349380493f, 0.012321148999035358f, 0.013945143669843674f, 0.0027987088542431593f, 0.02558094449341297f, 0.028798194602131844f, 0.01685517467558384f, 0.005540087353438139f, 0.008156810887157917f, 0.0034026680514216423f, 0.006487617734819651f, 0.011993545107543468f, 0.006234185770153999f, 0.006867400370538235f, 0.0075085959397256374f, 0.005739444866776466f, 0.006835005711764097f, 0.007300207391381264f, 0.01137095782905817f, 0.009235861711204052f, 0.01526570226997137f, 0.012578438967466354f, 0.0032561919651925564f, 0.010976516641676426f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #100 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002097236574627459f, 0.00021355555509217083f, 0.00065875198924914f, 0.00010111310984939337f, 0.0001822403137339279f, 3.1702362321084365e-05f, 5.704794602934271e-05f, 0.00018854888912755996f, 0.001166166621260345f, 0.0003246733103878796f, 0.00015170910046435893f, 0.0003931232204195112f, 7.15738206054084e-05f, 0.0004094059986528009f, 0.0003261414822191f, 0.0001794783165678382f, 0.00016512641741428524f, 0.0001760912564350292f, 0.00011888327571796253f, 0.00011365834507159889f, 0.0007788791554048657f, 0.00014215770352166146f, 0.00019931151473429054f, 0.000191214814549312f, 6.176803435664624e-05f, 7.245531742228195e-05f, 0.0002008781157201156f, 0.00017761792696546763f, 0.00020806005341000855f, 0.0001929111749632284f, 0.00010836596629815176f, 0.0001540702796773985f, 0.00021015794482082129f, 9.790725016500801e-05f, 0.0002028063900070265f, 9.513442637398839e-05f, 0.00047969643492251635f, 0.00015951703244354576f, 0.00017706840299069881f, 0.0002045244473265484f, 0.00012421084102243185f, 0.00011417171481298283f, 8.238097507273778e-05f, 9.088876686291769e-05f, 0.0002554893435444683f, 0.00019962619990110397f, 0.0002841405803337693f, 0.00020526950538624078f, 0.00018857557734008878f, 0.0002553366357460618f, 0.0003220797225367278f, 0.00039839468081481755f, 0.00013944132660981268f, 8.748093387112021e-05f, 0.00011882090620929375f, 0.00011884810373885557f, 0.0008455303031951189f, 2.653697447385639e-05f, 0.00014181020378600806f, 9.642833174439147e-05f, 0.00023311731638386846f, 0.0008985261083580554f, 0.00018324563279747963f, 0.0004581061948556453f, 0.0006031183293089271f, 0.00018486203043721616f, 0.00018058384011965245f, 8.03015791461803e-05f, 0.0002237068401882425f, 0.00015291280578821898f, 0.00017243331240024418f, 0.0005215213168412447f, 0.0002730629057623446f, 0.0002899093960877508f, 0.00032812103745527565f, 6.585197115782648e-05f, 0.0006019045831635594f, 0.0006776045775040984f, 0.00039659233880229294f, 0.0001303549943258986f, 0.00019192496256437153f, 8.00627822172828e-05f, 0.00015264983812812716f, 0.00028220107196830213f, 0.00014668672520201653f, 0.0001615858927834779f, 0.00017667285283096135f, 0.00013504576054401696f, 0.00016082366346381605f, 0.00017176958499476314f, 0.0002675519499462098f, 0.00021731440210714936f, 0.000359193014446646f, 0.00029596328386105597f, 7.661628478672355e-05f, 0.00025827097124420106f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #101 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.008623763918876648f, 0.017390834167599678f, 0.014214018359780312f, 0.020170066505670547f, 0.011906825006008148f, 0.011258340440690517f, 0.01836712844669819f, 0.01299535483121872f, 0.008956287056207657f, 0.02389718033373356f, 0.014291146770119667f, 0.010056533850729465f, 0.03289167955517769f, 0.03305592015385628f, 0.00937081128358841f, 0.009798754937946796f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #102 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_23_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00020291209511924535f, 0.00040919610182754695f, 0.0003344475117046386f, 0.00047458981862291694f, 0.00028016060241498053f, 0.00026490213349461555f, 0.0004321677261032164f, 0.0003057730500586331f, 0.00021073616517242044f, 0.0005622865865007043f, 0.00033626228105276823f, 0.00023662432795390487f, 0.0007739218999631703f, 0.0007777863647788763f, 0.00022048968821763992f, 0.00023055894416756928f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #103 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003877491399180144f, 0.0005373861640691757f, 0.0007076248293742537f, 0.0007557272911071777f, 0.0007210130570456386f, 0.000585082801990211f, 0.0005426799179986119f, 0.00032150305924005806f, 0.0005644370685331523f, 0.001251877867616713f, 0.0017042758408933878f, 0.0015657676849514246f, 0.001494923490099609f, 0.0019133043242618442f, 0.0017417293274775147f, 0.0015163309872150421f, 0.0006513543194159865f, 0.0013847900554537773f, 0.0018517757998779416f, 0.000566585804335773f, 0.0026469998992979527f, 0.0006773683708161116f, 0.0005954047082923353f, 0.0004516483750194311f, 0.0015758257359266281f, 0.0013393864501267672f, 0.0006596258608624339f, 0.0040030949749052525f, 0.000768077268730849f, 0.0004963150713592768f, 0.0003042957396246493f, 0.0014035683125257492f, 0.0014139608247205615f, 0.0009354523499496281f, 0.0007079730276018381f, 0.0017520054243505f, 0.0010094300378113985f, 0.000717880786396563f, 0.0009029034990817308f, 0.0005932605708949268f, 0.0009055561968125403f, 0.0013653584755957127f, 0.0009381172712892294f, 0.00101303996052593f, 0.0007599652744829655f, 0.0014239897718653083f, 0.0006993499118834734f, 0.001296043861657381f, 0.0017256299033761024f, 0.001153451157733798f, 0.002343696542084217f, 0.0009751885081641376f, 0.001523782848380506f, 0.0016116541810333729f, 0.0007227795431390405f, 0.002327661495655775f, 0.0012965406058356166f, 0.00037529884139075875f, 0.0013874223222956061f, 0.0014988593757152557f, 0.00036555834230966866f, 0.0016248784959316254f, 0.0016578782815486193f, 0.0016508345725014806f, 0.0008885126444511116f, 0.0013742317678406835f, 0.00024601584300398827f, 0.000789952406194061f, 0.0009429694036953151f, 0.0017081651603803039f, 0.0027190768159925938f, 0.0012665727408602834f, 0.00041648547630757093f, 0.0005900817341171205f, 0.0015149177052080631f, 0.0009366110316477716f, 0.0004705643223132938f, 0.0008578801644034684f, 0.0017119196709245443f, 0.0010572365717962384f, 0.000570253818295896f, 0.0005196640850044787f, 0.0003966032818425447f, 0.0002846985007636249f, 0.0006845660973340273f, 0.0011550172930583358f, 0.00043630690197460353f, 0.0010261849965900183f, 0.0007401155889965594f, 0.0006501161260530353f, 0.0008265187498182058f, 0.0007939190836623311f, 0.0004136417410336435f, 0.0017254985868930817f, 0.0022385925985872746f, 0.0003860875149257481f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #104 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012739373778458685f, 0.00017655649571679533f, 0.00023248787329066545f, 0.0002482917916495353f, 0.00023688652436248958f, 0.00019222707487642765f, 0.00017829574062488973f, 0.00010562880197539926f, 0.000185443990631029f, 0.0004113004542887211f, 0.0005599343567155302f, 0.0005144279566593468f, 0.0004911523428745568f, 0.0006286100251600146f, 0.000572239572647959f, 0.0004981856909580529f, 0.00021400037803687155f, 0.0004549683362711221f, 0.0006083949701860547f, 0.00018614994769450277f, 0.0008696633158251643f, 0.00022254721261560917f, 0.00019561831140890718f, 0.0001483876258134842f, 0.0005177324637770653f, 0.0004400511097628623f, 0.0002167179627576843f, 0.0013152039609849453f, 0.0002523493312764913f, 0.00016306272300425917f, 9.997539018513635e-05f, 0.0004611378535628319f, 0.0004645522858481854f, 0.00030733985477127135f, 0.00023260226589627564f, 0.0005756157333962619f, 0.0003316449874546379f, 0.0002358574274694547f, 0.00029664605972357094f, 0.00019491385319270194f, 0.00029751757392659783f, 0.00044858414912596345f, 0.0003082154144067317f, 0.0003328310267534107f, 0.0002496841480024159f, 0.0004678472760133445f, 0.00022976916807238013f, 0.0004258110420778394f, 0.0005669501842930913f, 0.00037896266439929605f, 0.0007700139540247619f, 0.00032039504731073976f, 0.0005006339633837342f, 0.0005295037990435958f, 0.00023746689839754254f, 0.0007647456950508058f, 0.00042597425635904074f, 0.00012330322351772338f, 0.00045583315659314394f, 0.0004924454260617495f, 0.00012010301725240424f, 0.0005338485934771597f, 0.0005446905852295458f, 0.0005423764232546091f, 0.0002919179678428918f, 0.000451499450718984f, 8.082771819317713e-05f, 0.0002595363184809685f, 0.0003098095767199993f, 0.0005612121894955635f, 0.0008933439385145903f, 0.00041612840141169727f, 0.00013683496217709035f, 0.00019386946223676205f, 0.0004977213684469461f, 0.0003077205619774759f, 0.0001546023995615542f, 0.00028185377595946193f, 0.0005624457262456417f, 0.000347351684467867f, 0.00018735506455413997f, 0.00017073396884370595f, 0.00013030273839831352f, 9.353677887702361e-05f, 0.00022491200070362538f, 0.0003794772201217711f, 0.00014334723528008908f, 0.0003371498023625463f, 0.0002431626053294167f, 0.00021359356469474733f, 0.0002715500886552036f, 0.00026083955890499055f, 0.00013590067101176828f, 0.0005669070524163544f, 0.0007354824338108301f, 0.00012684780813287944f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #105 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003427580464631319f, 0.0034825047478079796f, 0.005261993035674095f, 0.006499761249870062f, 0.0037627662532031536f, 0.002580120926722884f, 0.0038982585538178682f, 0.01010220032185316f, 0.003150882665067911f, 0.0031854240223765373f, 0.0011370577849447727f, 0.002968706889078021f, 0.001683729002252221f, 0.0012516621500253677f, 0.0019559829961508512f, 0.002017840975895524f, 0.0025212254840880632f, 0.0016442291671410203f, 0.0008527929312549531f, 0.0028121222276240587f, 0.0011168799828737974f, 0.003637525951489806f, 0.004639259073883295f, 0.005341663025319576f, 0.00242622010409832f, 0.0033481984864920378f, 0.003851809771731496f, 0.0017544630682095885f, 0.005717317573726177f, 0.004008904565125704f, 0.012676979415118694f, 0.0035662406589835882f, 0.0024283272214233875f, 0.002570509444922209f, 0.003459147410467267f, 0.0026475079357624054f, 0.002149471314623952f, 0.008514375425875187f, 0.0026881187222898006f, 0.005204375367611647f, 0.0027580237947404385f, 0.001632640021853149f, 0.0018596620066091418f, 0.0026972030755132437f, 0.003070991253480315f, 0.001770376693457365f, 0.004218481946736574f, 0.0034218584187328815f, 0.0010492912260815501f, 0.003164844587445259f, 0.0012814984656870365f, 0.0025039110332727432f, 0.0013871064875274897f, 0.0038857890758663416f, 0.001860030577518046f, 0.0008906005532480776f, 0.004104756750166416f, 0.007524179294705391f, 0.0025790666695684195f, 0.0011827033013105392f, 0.009829296730458736f, 0.0011031790636479855f, 0.00193737109657377f, 0.0045049055479466915f, 0.002011127071455121f, 0.0017198972636833787f, 0.011904893442988396f, 0.0015932003734633327f, 0.002409998793154955f, 0.001252204878255725f, 0.0017657466232776642f, 0.0038387428503483534f, 0.006656152196228504f, 0.004553286824375391f, 0.0069907233119010925f, 0.0037656822241842747f, 0.0033504643943160772f, 0.0028513348661363125f, 0.0010597659274935722f, 0.0039826612919569016f, 0.005108897108584642f, 0.006349899340420961f, 0.0036677478346973658f, 0.007010301575064659f, 0.002903161570429802f, 0.003115709638223052f, 0.006611818913370371f, 0.003127188654616475f, 0.0031851802486926317f, 0.0025176459457725286f, 0.0033607040531933308f, 0.0031908885575830936f, 0.010165806859731674f, 0.0007552822935394943f, 0.0013970687286928296f, 0.006021131295710802f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #106 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 96,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.064895519055426e-05f, 8.194128895411268e-05f, 0.0001238116092281416f, 0.00015293556498363614f, 8.853567851474509e-05f, 6.0708727687597275e-05f, 9.172373393084854e-05f, 0.00023769884137436748f, 7.41384137654677e-05f, 7.495115278288722e-05f, 2.6754301870823838e-05f, 6.985192885622382e-05f, 3.96171526517719e-05f, 2.9450875445036218e-05f, 4.602313128998503e-05f, 4.7478613851126283e-05f, 5.9322952438378707e-05f, 3.868774729198776e-05f, 2.0065715943928808e-05f, 6.616758037125692e-05f, 2.6279529265593737e-05f, 8.558885019738227e-05f, 0.00010915903840214014f, 0.00012568618694785982f, 5.708753451472148e-05f, 7.878114411141723e-05f, 9.063081961357966e-05f, 4.128148430027068e-05f, 0.00013452512212097645f, 9.432716615265235e-05f, 0.0002982818696182221f, 8.391154551645741e-05f, 5.713711288990453e-05f, 6.0482576373033226e-05f, 8.139170677168295e-05f, 6.229430437088013e-05f, 5.057579619460739e-05f, 0.00020033825421705842f, 6.324985588435084e-05f, 0.00012245589459780604f, 6.489468069048598e-05f, 3.8415058952523395e-05f, 4.375675416667946e-05f, 6.34636016911827e-05f, 7.225861918414012e-05f, 4.165592326899059e-05f, 9.925840276991948e-05f, 8.051432087086141e-05f, 2.468920501996763e-05f, 7.44669305277057e-05f, 3.0152905310387723e-05f, 5.891555338166654e-05f, 3.2637799449730664e-05f, 9.143033094005659e-05f, 4.3765427108155563e-05f, 2.0955307263648137e-05f, 9.658251656219363e-05f, 0.0001770395174389705f, 6.0683923948090523e-05f, 2.7828313250211067e-05f, 0.00023127757594920695f, 2.5957155230571516e-05f, 4.558520231512375e-05f, 0.00010599778033792973f, 4.732063825940713e-05f, 4.046817048219964e-05f, 0.0002801151422318071f, 3.748706876649521e-05f, 5.6705855968175456e-05f, 2.946364475064911e-05f, 4.154698035563342e-05f, 9.032335947267711e-05f, 0.00015661535144317895f, 0.00010713616211432964f, 0.0001644876174395904f, 8.860429079504684e-05f, 7.883445505285636e-05f, 6.709023000439629e-05f, 2.4935668989201076e-05f, 9.370967745780945e-05f, 0.00012020934809697792f, 0.0001494094030931592f, 8.629995136288926e-05f, 0.00016494827286805958f, 6.830968777649105e-05f, 7.331081724260002e-05f, 0.0001555722119519487f, 7.358090806519613e-05f, 7.494541932828724e-05f, 5.9238729591015726e-05f, 7.907539111329243e-05f, 7.507973350584507e-05f, 0.00023919546219985932f, 1.777134821168147e-05f, 3.2872205338208005e-05f, 0.00014167367771733552f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #107 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011890443973243237f, 0.02289516292512417f, 0.01516704447567463f, 0.03311833366751671f, 0.015446820296347141f, 0.017115486785769463f, 0.015509359538555145f, 0.020609302446246147f, 0.02088392898440361f, 0.017550624907016754f, 0.013206575997173786f, 0.02043810673058033f, 0.015926873311400414f, 0.0076985894702374935f, 0.018744170665740967f, 0.015834219753742218f, 0.01566913351416588f, 0.014729931950569153f, 0.011517188511788845f, 0.013870079070329666f, 0.012319034896790981f, 0.0126789016649127f, 0.021685028448700905f, 0.01489051803946495f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #108 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_28_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00027977515128441155f, 0.0005387097480706871f, 0.000356871634721756f, 0.0007792549440637231f, 0.0003634546010289341f, 0.0004027173563372344f, 0.00036492611980065703f, 0.0004849247634410858f, 0.0004913865705020726f, 0.0004129558801651001f, 0.0003107429656665772f, 0.0004808966477867216f, 0.0003747499722521752f, 0.00018114328850060701f, 0.0004410393303260207f, 0.00037256989162415266f, 0.0003686854906845838f, 0.00034658663207665086f, 0.00027099266299046576f, 0.00032635481329634786f, 0.00028985965764150023f, 0.0002983270969707519f, 0.0005102359573356807f, 0.0003503651241771877f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #109 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00035894778557121754f, 0.00037278133095242083f, 0.0004615637008100748f, 0.00036506226751953363f, 0.0007104468531906605f, 0.0004935978213325143f, 0.0005692528211511672f, 0.000820389308501035f, 0.0004198618116788566f, 0.0005712967249564826f, 0.0006737341172993183f, 0.0005030542961321771f, 0.0007589437300339341f, 0.0007904351223260164f, 0.0009742557303979993f, 0.001329103484749794f, 0.00048370222793892026f, 0.00046470918459817767f, 0.0008023908594623208f, 0.0003966577351093292f, 0.0005140611901879311f, 0.000793393817730248f, 0.0011408969294279814f, 0.0005313033470883965f, 0.0006134984432719648f, 0.0008818777860142291f, 0.0007580520468764007f, 0.00024066107289399952f, 0.0005537669057957828f, 0.0013056622119620442f, 0.00036893674405291677f, 0.0012250543804839253f, 0.0006364104337990284f, 0.0007944641401991248f, 0.00033556201378814876f, 0.0013610579771921039f, 0.0005581304430961609f, 0.0006196624599397182f, 0.0006413407390937209f, 0.00032190626370720565f, 0.00040099021862261f, 0.00031887422665022314f, 0.0010016096057370305f, 0.0011623470345512033f, 0.000715826521627605f, 0.0008885178249329329f, 0.0009817456593737006f, 0.00039277845644392073f, 0.0006234030006453395f, 0.00027070619398728013f, 0.0009901892626658082f, 0.0006815100205130875f, 0.0002935415832325816f, 0.00024581560865044594f, 0.0008268067613244057f, 0.0008098596590571105f, 0.0002988346095662564f, 0.0019179400987923145f, 0.0008019115193746984f, 0.0004117463540751487f, 0.0006084110937081277f, 0.0005714361905120313f, 0.0004735778202302754f, 0.0007344781770370901f, 0.0006678611971437931f, 0.0006020785076543689f, 0.0006525252829305828f, 0.0012753685005009174f, 0.0008960349950939417f, 0.0007147772121243179f, 0.0012832023203372955f, 0.0011982907308265567f, 0.0011602671584114432f, 0.0012870758073404431f, 0.0007012086571194232f, 0.0008942303247749805f, 0.0005475149373523891f, 0.003295160597190261f, 0.0008021998219192028f, 0.0003315419307909906f, 0.00039509503403678536f, 0.0008508012979291379f, 0.0003568014071788639f, 0.000491695071104914f, 0.0013514356687664986f, 0.0010098114144057035f, 0.0004624167922884226f, 0.0006768142338842154f, 0.0011919912649318576f, 0.0004045679816044867f, 0.0009948196820914745f, 0.0010588258737698197f, 0.0005729750264436007f, 0.0006236035260371864f, 0.0004699664132203907f, 0.00044501328375190496f, 0.0007117506465874612f, 0.0005231481627561152f, 0.0008421532111242414f, 0.0003218488418497145f, 0.000790699094068259f, 0.0007870739209465683f, 0.0006157177267596126f, 0.0010767674539238214f, 0.0010514078894630075f, 0.0005379840149544179f, 0.0001317197020398453f, 0.0002505614538677037f, 0.0009490631055086851f, 0.0006764827412553132f, 0.0006143467035144567f, 0.0008380270446650684f, 0.0005630398518405855f, 0.000170767743838951f, 0.0010824068449437618f, 0.00039156072307378054f, 0.0016550073632970452f, 0.0004912742879241705f, 0.0008764872327446938f, 0.0009179604239761829f, 0.00030887205502949655f, 0.0005658146110363305f, 0.0010197121882811189f, 0.0010374276898801327f, 0.0005721363122574985f, 0.0009051246452145278f, 0.0007752229575999081f, 0.0012616433668881655f, 0.0021775118075311184f, 0.00044949440052732825f, 0.0010760898003354669f, 0.0005270371329970658f, 0.0004983429098501801f, 0.0008841642993502319f, 0.0006239647627808154f, 0.0007149927550926805f, 0.0007461948553100228f, 0.0005855599883943796f, 0.0009407780016772449f, 0.0012474629329517484f, 0.0002027606824412942f, 0.0008184711914509535f, 0.001648007077164948f, 0.00047535155317746103f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #110 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.6093540479196236e-05f, 5.8255336625734344e-05f, 7.212955097202212e-05f, 5.704906288883649e-05f, 0.00011102305143140256f, 7.713559170952067e-05f, 8.895836072042584e-05f, 0.0001282039884245023f, 6.561270856764168e-05f, 8.927776070777327e-05f, 0.00010528587154112756f, 7.861337508074939e-05f, 0.00011860176164191216f, 0.00012352298654150218f, 0.00015224903472699225f, 0.00020770184346474707f, 7.558918150607497e-05f, 7.262110011652112e-05f, 0.00012539133604150265f, 6.198655319167301e-05f, 8.033344056457281e-05f, 0.0001239853590959683f, 0.00017829041462391615f, 8.302790956804529e-05f, 9.587271779309958e-05f, 0.00013781293819192797f, 0.00011846241977764294f, 3.760862091439776e-05f, 8.653834083816037e-05f, 0.00020403863163664937f, 5.765453533967957e-05f, 0.0001914418680826202f, 9.945322381099686e-05f, 0.00012415261880960315f, 5.243899431661703e-05f, 0.00021269544959068298f, 8.722024358576164e-05f, 9.683598182164133e-05f, 0.00010022368951467797f, 5.030498141422868e-05f, 6.266360287554562e-05f, 4.983116014045663e-05f, 0.00015652367437724024f, 0.00018164246284868568f, 0.00011186374467797577f, 0.00013885059161111712f, 0.0001534195034764707f, 6.138032767921686e-05f, 9.742052498040721e-05f, 4.2303836380597204e-05f, 0.00015473899838980287f, 0.00010650102922227234f, 4.587237344821915e-05f, 3.841413126792759e-05f, 0.00012920686276629567f, 0.00012655850150622427f, 4.6699526137672365e-05f, 0.00029972061747685075f, 0.00012531643733382225f, 6.434448732761666e-05f, 9.507770300842822e-05f, 8.929955947678536e-05f, 7.400702452287078e-05f, 0.00011477847874630243f, 0.00010436810407554731f, 9.408810001332313e-05f, 0.00010197152732871473f, 0.0001993045734707266f, 0.00014002530951984227f, 0.00011169976642122492f, 0.00020052878244314343f, 0.0001872594584710896f, 0.00018131743127014488f, 0.0002011340984608978f, 0.00010957937774946913f, 0.00013974329340271652f, 8.556133252568543e-05f, 0.0005149418138898909f, 0.00012536149006336927f, 5.181076630833559e-05f, 6.174235022626817e-05f, 0.00013295654207468033f, 5.575811883318238e-05f, 7.683824514970183e-05f, 0.00021119174198247492f, 0.00015780539251863956f, 7.226286106742918e-05f, 0.00010576721251709387f, 0.0001862750359578058f, 6.32227020105347e-05f, 0.00015546260692644864f, 0.00016546498227398843f, 8.954003715189174e-05f, 9.74518625298515e-05f, 7.344265759456903e-05f, 6.954318087082356e-05f, 0.00011122680007247254f, 8.175348193617538e-05f, 0.00013160509115550667f, 5.029600652051158e-05f, 0.0001235642412211746f, 0.00012299773516133428f, 9.621952631277964e-05f, 0.00016826875798869878f, 0.0001643057621549815f, 8.407191489823163e-05f, 2.0584120647981763e-05f, 3.915577690349892e-05f, 0.00014831213047727942f, 0.00010571540769888088f, 9.600527846487239e-05f, 0.0001309602812398225f, 8.798744238447398e-05f, 2.6686240744311363e-05f, 0.0001691500365268439f, 6.119003228377551e-05f, 0.00025863153859972954f, 7.677248504478484e-05f, 0.00013697054237127304f, 0.0001434516452718526f, 4.826809890801087e-05f, 8.842106035444885e-05f, 0.00015935261035338044f, 0.00016212105401791632f, 8.940896805142984e-05f, 0.00014144576562102884f, 0.00012114575656596571f, 0.0001971597084775567f, 0.00034028443042188883f, 7.024345541140065e-05f, 0.00016816286370158195f, 8.236122084781528e-05f, 7.787711365381256e-05f, 0.0001381702459184453f, 9.750830940902233e-05f, 0.00011173344682902098f, 0.00011660946620395407f, 9.150671394309029e-05f, 0.0001470173883717507f, 0.00019494369917083532f, 3.168584589730017e-05f, 0.0001279042480746284f, 0.00025753758382052183f, 7.428420940414071e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #111 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.022750690579414368f, 0.01814982481300831f, 0.011724267154932022f, 0.009609879925847054f, 0.010177450254559517f, 0.014987098053097725f, 0.008481817319989204f, 0.012490889988839626f, 0.013598918914794922f, 0.011882343329489231f, 0.00848937127739191f, 0.007659830152988434f, 0.006613228935748339f, 0.010400102473795414f, 0.023449426516890526f, 0.009854218922555447f, 0.011165733449161053f, 0.008535319939255714f, 0.022020872682332993f, 0.013544794172048569f, 0.006680045742541552f, 0.010245087556540966f, 0.006730666384100914f, 0.008395985700190067f, 0.010626206174492836f, 0.05287802591919899f, 0.020282529294490814f, 0.018406009301543236f, 0.010470111854374409f, 0.018281979486346245f, 0.015277708880603313f, 0.009221689775586128f, 0.009605229832231998f, 0.009336601011455059f, 0.026219196617603302f, 0.010866338387131691f, 0.018407152965664864f, 0.010575133375823498f, 0.01228866633027792f, 0.029338005930185318f, 0.008710241876542568f, 0.0447491891682148f, 0.00510551780462265f, 0.006845117546617985f, 0.012797670438885689f, 0.009624255821108818f, 0.012994004413485527f, 0.010499101132154465f, 0.009835722856223583f, 0.014325720258057117f, 0.00813195388764143f, 0.00905697327107191f, 0.0192377008497715f, 0.038172464817762375f, 0.010515207424759865f, 0.015343664214015007f, 0.009494349360466003f, 0.00752542819827795f, 0.020408784970641136f, 0.021764349192380905f, 0.014087260700762272f, 0.009952276013791561f, 0.007377510890364647f, 0.005943972151726484f, 0.011967944912612438f, 0.010377727448940277f, 0.010760325938463211f, 0.007737699430435896f, 0.010705394670367241f, 0.011250125244259834f, 0.00866241566836834f, 0.004170926287770271f, 0.022243304178118706f, 0.003430852899327874f, 0.008668088354170322f, 0.022826336324214935f, 0.007763253059238195f, 0.01438351720571518f, 0.007631022483110428f, 0.009977152571082115f, 0.01661878637969494f, 0.017552655190229416f, 0.022931117564439774f, 0.010432461276650429f, 0.012085399590432644f, 0.0067437621764838696f, 0.014225115068256855f, 0.00989025179296732f, 0.008904236368834972f, 0.01264758687466383f, 0.009569653309881687f, 0.00875308457762003f, 0.01705336757004261f, 0.009545932523906231f, 0.007780574262142181f, 0.01178471278399229f, 0.0077626085840165615f, 0.02707524225115776f, 0.002983034122735262f, 0.017292045056819916f, 0.009763519279658794f, 0.007696579676121473f, 0.015743404626846313f, 0.006560143548995256f, 0.007432897109538317f, 0.010576949454843998f, 0.031874705106019974f, 0.014043353497982025f, 0.013531191274523735f, 0.018463388085365295f, 0.007354381028562784f, 0.008354218676686287f, 0.007635052315890789f, 0.01974398083984852f, 0.027437401935458183f, 0.02228899672627449f, 0.004916988778859377f, 0.003311105305328965f, 0.009609706699848175f, 0.00574770150706172f, 0.013915177434682846f, 0.007139250170439482f, 0.0023404057137668133f, 0.01860753819346428f, 0.0046059750020504f, 0.006874379701912403f, 0.02717379294335842f, 0.006526498589664698f, 0.007137736771255732f, 0.018846485763788223f, 0.0024839078541845083f, 0.002597339916974306f, 0.013754231855273247f, 0.0066433255560696125f, 0.019692178815603256f, 0.00825970247387886f, 0.007148285862058401f, 0.008698507212102413f, 0.008350430987775326f, 0.0127602843567729f, 0.04211867228150368f, 0.011651551350951195f, 0.00669023348018527f, 0.01961510255932808f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #112 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005353103624656796f, 0.0004270547069609165f, 0.0002758651098702103f, 0.00022611483291257173f, 0.00023946941655594856f, 0.00035263760946691036f, 0.00019957218319177628f, 0.0002939032856374979f, 0.00031997455516830087f, 0.0002795845502987504f, 0.00019974992028437555f, 0.00018023130542133003f, 0.00015560539031866938f, 0.0002447082952130586f, 0.0005517512327060103f, 0.00023186397447716445f, 0.00026272315881215036f, 0.00020083105482626706f, 0.0005181381711736321f, 0.00031870105885900557f, 0.00015717755013611168f, 0.0002410608867648989f, 0.0001583686243975535f, 0.0001975526101887226f, 0.00025002838810905814f, 0.0012441888684406877f, 0.0004772359970957041f, 0.0004330825759097934f, 0.0002463555720169097f, 0.00043016421841457486f, 0.00035947549622505903f, 0.00021698094496969134f, 0.00022600541706196964f, 0.00021968473447486758f, 0.0006169222760945559f, 0.0002556785475462675f, 0.00043310949695296586f, 0.00024882666184566915f, 0.0002891451003961265f, 0.0006903060129843652f, 0.00020494687487371266f, 0.0010529221035540104f, 0.00012012983643217012f, 0.00016106158727779984f, 0.0003011216758750379f, 0.0002264530776301399f, 0.0003057412977796048f, 0.0002470376784913242f, 0.00023142877034842968f, 0.00033707579132169485f, 0.000191340091987513f, 0.00021310526062734425f, 0.0004526517877820879f, 0.0008981756400316954f, 0.0002474166394677013f, 0.00036102739977650344f, 0.00022339646238833666f, 0.00017706889775581658f, 0.00048020671238191426f, 0.0005121023277752101f, 0.00033146495115943253f, 0.00023417120974045247f, 0.00017358850163873285f, 0.00013985816622152925f, 0.0002815987099893391f, 0.00024418183602392673f, 0.00025318414554931223f, 0.00018206352251581848f, 0.0002518916444387287f, 0.00026470882585272193f, 0.0002038215461652726f, 9.813944052439183e-05f, 0.0005233718547970057f, 8.072594937402755e-05f, 0.0002039550308836624f, 0.0005370902945287526f, 0.00018266477854922414f, 0.0003384356969036162f, 0.0001795534772099927f, 0.00023475653142668307f, 0.0003910302766598761f, 0.00041300366865471005f, 0.0005395557382144034f, 0.0002454696805216372f, 0.00028436235152184963f, 0.00015867676120251417f, 0.00033470860216766596f, 0.00023271181271411479f, 0.00020951144688297063f, 0.00029759027529507875f, 0.00022516831813845783f, 0.00020595492969732732f, 0.0004012557037640363f, 0.00022461017942987382f, 0.000183072334039025f, 0.00027728735585696995f, 0.00018264961545355618f, 0.000637064513284713f, 7.018903852440417e-05f, 0.000406871666200459f, 0.0002297298633493483f, 0.00018109599477611482f, 0.0003704330592881888f, 0.0001543563266750425f, 0.00017489169840700924f, 0.0002488694153726101f, 0.0007499930798076093f, 0.00033043185248970985f, 0.0003183809749316424f, 0.0004344326735008508f, 0.00017304426000919193f, 0.00019656986114569008f, 0.00017964829748962075f, 0.0004645642766263336f, 0.0006455859402194619f, 0.0005244470085017383f, 0.00011569385242182761f, 7.790836389176548e-05f, 0.00022611074382439256f, 0.00013524004316423088f, 0.00032741593895480037f, 0.0001679823617450893f, 5.506837260327302e-05f, 0.00043782443390227854f, 0.0001083758834283799f, 0.00016175011114683002f, 0.0006393833900801837f, 0.0001535646733827889f, 0.00016794675320852548f, 0.0004434467409737408f, 5.844489351147786e-05f, 6.111388211138546e-05f, 0.00032362897763960063f, 0.00015631354472134262f, 0.00046334537910297513f, 0.0001943459501489997f, 0.00016819496522657573f, 0.00020467076683416963f, 0.00019648073066491634f, 0.0003002419834956527f, 0.000991027569398284f, 0.00027415415388531983f, 0.00015741726383566856f, 0.0004615318321157247f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #113 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0045663476921617985f, 0.008207128383219242f, 0.004874314647167921f, 0.006571772508323193f, 0.004303347785025835f, 0.011540507897734642f, 0.004229583311825991f, 0.006319655105471611f, 0.00790297333151102f, 0.0058362772688269615f, 0.00548142334446311f, 0.015899620950222015f, 0.004975026939064264f, 0.043720792979002f, 0.005702781956642866f, 0.011454337276518345f, 0.006737587973475456f, 0.005775805097073317f, 0.02477419748902321f, 0.0032862334046512842f, 0.0044581471011042595f, 0.013063528575003147f, 0.014272481203079224f, 0.005019041243940592f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #114 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_31_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001074434767360799f, 0.00019310890638735145f, 0.00011468975571915507f, 0.0001546299463370815f, 0.00010125524568138644f, 0.00027154135750606656f, 9.951960964826867e-05f, 0.00014869777078274637f, 0.00018595231813378632f, 0.00013732416846323758f, 0.00012897467240691185f, 0.000374108727555722f, 0.00011705946235451847f, 0.0010287245968356729f, 0.00013418310845736414f, 0.00026951381005346775f, 0.00015853148943278939f, 0.0001359012967441231f, 0.0005829223082400858f, 7.732314406894147e-05f, 0.00010489758278708905f, 0.0003073771367780864f, 0.0003358231042511761f, 0.00011809509305749089f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #115 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0011776804458349943f, 0.0004037426842842251f, 0.0005348827107809484f, 0.00027613886049948633f, 0.0006296328501775861f, 0.00043811791692860425f, 0.0007123667746782303f, 0.0003652131126727909f, 0.0007884754450060427f, 0.0011837392812594771f, 0.0005252769333310425f, 0.000830534438136965f, 0.0005328366532921791f, 0.000331339513650164f, 0.0005744522786699235f, 0.0005170211661607027f, 0.0008970506605692208f, 0.0014203331666067243f, 0.00045066827442497015f, 0.00029147809254936874f, 0.0005544549785554409f, 0.0006894746911711991f, 0.00017836310144048184f, 0.0003827442415058613f, 0.0005052023916505277f, 0.0005442531546577811f, 0.0002845748676918447f, 0.0002313867153134197f, 0.000509213306941092f, 0.0007763687754049897f, 0.000637274410109967f, 0.000381108489818871f, 0.00045849831076338887f, 0.0009187087998725474f, 0.0003578097384888679f, 0.0009492915123701096f, 0.0006455691182054579f, 0.0007622113334946334f, 0.0005817705532535911f, 0.0017781974747776985f, 0.0005853264592587948f, 0.001028162078000605f, 0.00015066047490108758f, 0.0004716584808193147f, 0.0005423548282124102f, 0.00030267098918557167f, 0.0004221014678478241f, 0.0007183443522080779f, 0.0008938902756199241f, 0.0008630540687590837f, 0.0007392840343527496f, 0.0004565161361824721f, 0.0008240386960096657f, 0.001122021465562284f, 0.0004640726838260889f, 0.00043375673703849316f, 0.0011729426914826035f, 0.0006178620387800038f, 0.000462418858660385f, 0.0007684617303311825f, 0.0004942418891005218f, 0.00047123373951762915f, 0.0003667633282020688f, 0.0011497909436002374f, 0.0010904662776738405f, 0.0005025615100748837f, 0.0015581214101985097f, 0.0003243310493417084f, 0.0008708321838639677f, 0.0004323418834246695f, 0.0007415488944388926f, 0.0008474373607896268f, 0.0003281614917796105f, 0.0008445996209047735f, 0.0005091553903184831f, 0.0005535787204280496f, 0.000386797240935266f, 0.0012204835657030344f, 0.0008182284072972834f, 0.0007653979118913412f, 0.0008500799885950983f, 0.0006194284069351852f, 0.0009763605194166303f, 0.0002951999776996672f, 0.00034159477218054235f, 0.0008987789624370635f, 0.0005170187796466053f, 0.0009180443012155592f, 0.0007158532971516252f, 0.0003618164628278464f, 0.0005476999212987721f, 0.0008890051394701004f, 0.0005712294369004667f, 0.0005022806581109762f, 0.0004484615637920797f, 0.0004141749523114413f, 0.0003206672554370016f, 0.0010232464410364628f, 0.0008595024701207876f, 0.0005295533919706941f, 0.00041762838372960687f, 0.0008569281199015677f, 0.00048152796807698905f, 0.001073247753083706f, 0.0006407828186638653f, 0.0008062729029916227f, 0.0008954264922067523f, 0.00035064120311290026f, 0.0008495295187458396f, 0.0002794390020426363f, 0.0010234462097287178f, 0.0007656392408534884f, 0.0007286456529982388f, 0.0012225417885929346f, 0.00026683276519179344f, 0.0004940031212754548f, 0.0005662672338075936f, 0.0010719976853579283f, 0.0009510234231129289f, 0.001205552602186799f, 0.0002675652503967285f, 0.0004552258469630033f, 0.00039507460314780474f, 0.00037583825178444386f, 0.0006451192311942577f, 0.0005840121884830296f, 0.0009418223635293543f, 0.001266044331714511f, 0.00044855475425720215f, 0.0003993696009274572f, 0.0009314647177234292f, 0.000434167159255594f, 0.0009280982776544988f, 0.00018364950665272772f, 0.0011531782802194357f, 0.0007919804193079472f, 0.0006724106497131288f, 0.0010724607855081558f, 0.000542767287697643f, 0.00021385951549746096f, 0.0006849173805676401f, 0.0006874674581922591f, 0.0007540310616604984f, 0.0011605002218857408f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #116 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00020987771858926862f, 7.195211219368502e-05f, 9.532293915981427e-05f, 4.921147774439305e-05f, 0.00011220862506888807f, 7.807821384631097e-05f, 0.00012695287296082824f, 6.508564547402784e-05f, 0.0001405164075549692f, 0.00021095748525112867f, 9.361106640426442e-05f, 0.0001480118662584573f, 9.495830454397947e-05f, 5.904893987462856e-05f, 0.00010237474634777755f, 9.213978773914278e-05f, 0.00015986590005923063f, 0.0002531215432099998f, 8.031485049286857e-05f, 5.19451241416391e-05f, 9.881096775643528e-05f, 0.00012287321442272514f, 3.1786585168447345e-05f, 6.820991984568536e-05f, 9.003352897707373e-05f, 9.699287329567596e-05f, 5.071488340036012e-05f, 4.123607141082175e-05f, 9.074832632904872e-05f, 0.00013835885329172015f, 0.00011357045150361955f, 6.79184086038731e-05f, 8.171026274794713e-05f, 0.00016372566460631788f, 6.376627425197512e-05f, 0.0001691758952802047f, 0.00011504867143230513f, 0.00013583581312559545f, 0.00010367895447416231f, 0.00031689752358943224f, 0.00010431266127852723f, 0.00018323163385502994f, 2.6849624191527255e-05f, 8.405557309743017e-05f, 9.665457037044689e-05f, 5.393984247348271e-05f, 7.522387750213966e-05f, 0.00012801814591512084f, 0.00015930268273223191f, 0.000153807268361561f, 0.0001317498681601137f, 8.135701500577852e-05f, 0.00014685423229821026f, 0.0001999585801968351f, 8.270368562079966e-05f, 7.73009960539639e-05f, 0.00020903338736388832f, 0.00011011091555701569f, 8.240895840572193e-05f, 0.00013694970402866602f, 8.808022539597005e-05f, 8.397988131036982e-05f, 6.536191358463839e-05f, 0.000204907453735359f, 0.00019433503621257842f, 8.956289093475789e-05f, 0.00027767717256210744f, 5.779994171462022e-05f, 0.00015519344015046954f, 7.704885501880199e-05f, 0.0001321534946328029f, 0.00015102417091839015f, 5.8482575695961714e-05f, 0.00015051846276037395f, 9.07380017451942e-05f, 9.865481115411967e-05f, 6.893221870996058e-05f, 0.00021750578889623284f, 0.00014581876166630536f, 0.00013640370161738247f, 0.00015149512910284102f, 0.00011039006494684145f, 0.00017399992793798447f, 5.260841135168448e-05f, 6.087655856390484e-05f, 0.00016017390589695424f, 9.213935845764354e-05f, 0.00016360724112018943f, 0.00012757421063724905f, 6.448032218031585e-05f, 9.760713146533817e-05f, 0.0001584320852998644f, 0.00010180038952967152f, 8.951283962232992e-05f, 7.992158498382196e-05f, 7.381127215921879e-05f, 5.714700819225982e-05f, 0.00018235560855828226f, 0.00015317433280870318f, 9.437318658456206e-05f, 7.442672358592972e-05f, 0.00015271555457729846f, 8.581444126321003e-05f, 0.0001912664738483727f, 0.00011419569636927918f, 0.00014368814299814403f, 0.00015957644791342318f, 6.248874706216156e-05f, 0.00015139702009037137f, 4.979960431228392e-05f, 0.00018239120254293084f, 0.0001364467025268823f, 0.00012985397188458592f, 0.00021787258447147906f, 4.755301051773131e-05f, 8.80376755958423e-05f, 0.00010091606236528605f, 0.00019104369857814163f, 0.00016948454140219837f, 0.00021484489843714982f, 4.7683548473287374e-05f, 8.112706564133987e-05f, 7.040734635666013e-05f, 6.697918433928862e-05f, 0.00011496849765535444f, 0.00010407844092696905f, 0.0001678447879385203f, 0.00022562529193237424f, 7.993819599505514e-05f, 7.117276982171461e-05f, 0.00016599892114754766f, 7.737414125585929e-05f, 0.00016539898933842778f, 3.2728690712247044e-05f, 0.00020551112538669258f, 0.00014114104851614684f, 0.00011983217700617388f, 0.00019112623704131693f, 9.672807209426537e-05f, 3.8112502807052806e-05f, 0.00012206103565404192f, 0.00012251549924258143f, 0.00013437798770610243f, 0.000206815981073305f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #117 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00836492795497179f, 0.014070060104131699f, 0.006453193258494139f, 0.021933328360319138f, 0.0166841521859169f, 0.028062421828508377f, 0.008386832661926746f, 0.019275560975074768f, 0.010123775340616703f, 0.006217370741069317f, 0.008774293586611748f, 0.007251087110489607f, 0.015034463256597519f, 0.01870102994143963f, 0.021892163902521133f, 0.006161137018352747f, 0.005358723923563957f, 0.0021640427876263857f, 0.008228235878050327f, 0.010322886519134045f, 0.013802813366055489f, 0.008033414371311665f, 0.020579570904374123f, 0.013792527839541435f, 0.013031220063567162f, 0.014343787916004658f, 0.026746679097414017f, 0.020637929439544678f, 0.029829882085323334f, 0.004185062367469072f, 0.004262350033968687f, 0.013466514647006989f, 0.008603716269135475f, 0.008451735600829124f, 0.01970864087343216f, 0.01044732891023159f, 0.008149852976202965f, 0.01321788877248764f, 0.010075517930090427f, 0.008557518944144249f, 0.011082424782216549f, 0.002310071839019656f, 0.04468061402440071f, 0.011451637372374535f, 0.01049340795725584f, 0.007151275407522917f, 0.009666996076703072f, 0.007098295260220766f, 0.004044700413942337f, 0.021494820713996887f, 0.00481556449085474f, 0.019170545041561127f, 0.0073554180562496185f, 0.007066435646265745f, 0.006508523132652044f, 0.020907815545797348f, 0.007669181562960148f, 0.0074005392380058765f, 0.010420876555144787f, 0.009681693278253078f, 0.00889077503234148f, 0.02011987939476967f, 0.014465357176959515f, 0.03379543125629425f, 0.007061134558171034f, 0.0020590471103787422f, 0.006515149027109146f, 0.01414902787655592f, 0.007612175308167934f, 0.010114718228578568f, 0.007715405430644751f, 0.004727990832179785f, 0.014546711929142475f, 0.018193120136857033f, 0.015656055882573128f, 0.00233462848700583f, 0.01059067901223898f, 0.010321969166398048f, 0.004620647523552179f, 0.007715365383774042f, 0.003233712399378419f, 0.012101231142878532f, 0.011327587068080902f, 0.01017846167087555f, 0.007241315208375454f, 0.00607293238863349f, 0.007047845050692558f, 0.0019458996830508113f, 0.007022223435342312f, 0.014023752883076668f, 0.0038240368012338877f, 0.006312617566436529f, 0.008644607849419117f, 0.010456718504428864f, 0.01502602081745863f, 0.02477206662297249f, 0.014487734995782375f, 0.008427819237112999f, 0.0059727830812335014f, 0.00748531986027956f, 0.012437677010893822f, 0.004001901019364595f, 0.023220138624310493f, 0.015648363158106804f, 0.01725899428129196f, 0.004064996261149645f, 0.008435430936515331f, 0.022911643609404564f, 0.007425266783684492f, 0.0196414552628994f, 0.004416623618453741f, 0.013792462646961212f, 0.008541003800928593f, 0.002686538267880678f, 0.012061862275004387f, 0.009832469746470451f, 0.024128425866365433f, 0.00830219965428114f, 0.009299734607338905f, 0.004522612318396568f, 0.014037083834409714f, 0.01172499731183052f, 0.009676622226834297f, 0.011098640970885754f, 0.01464095152914524f, 0.016577119007706642f, 0.0036611047107726336f, 0.003356741974130273f, 0.013529435731470585f, 0.004280958790332079f, 0.013838893733918667f, 0.01007607951760292f, 0.0058464002795517445f, 0.026658324524760246f, 0.008472923189401627f, 0.009741820394992828f, 0.0036106330808252096f, 0.007785445544868708f, 0.011846733279526234f, 0.015606565400958061f, 0.008525922894477844f, 0.006071580573916435f, 0.00598888611420989f, 0.0014929418684914708f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #118 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00019682184210978448f, 0.0003310602332931012f, 0.0001518398494226858f, 0.0005160783184692264f, 0.00039256829768419266f, 0.0006602922803722322f, 0.00019733724184334278f, 0.0004535426269285381f, 0.00023820648493710905f, 0.00014629107317887247f, 0.00020645397307816893f, 0.00017061381367966533f, 0.00035375208244659007f, 0.00044002424692735076f, 0.0005151097429916263f, 0.00014496792573481798f, 0.00012608763063326478f, 5.091865386930294e-05f, 0.00019360554870218039f, 0.00024289145949296653f, 0.00032477208878844976f, 0.0001890215207822621f, 0.0004842251946683973f, 0.00032453006133437157f, 0.00030661694472655654f, 0.00033750091097317636f, 0.0006293336628004909f, 0.00048559834249317646f, 0.0007018796168267727f, 9.847206092672423e-05f, 0.00010029059194494039f, 0.00031685916474089026f, 0.0002024403802352026f, 0.0001988643780350685f, 0.0004637327219825238f, 0.00024581950856372714f, 0.0001917612535180524f, 0.0003110091492999345f, 0.00023707101354375482f, 0.0002013533958233893f, 0.000260762928519398f, 5.435463390313089e-05f, 0.001051308587193489f, 0.00026945030549541116f, 0.00024690371355973184f, 0.00016826530918478966f, 0.00022745873138774186f, 0.0001670187193667516f, 9.516942373011261e-05f, 0.000505760486703366f, 0.00011330740380799398f, 0.0004510716535151005f, 0.0001730686635710299f, 0.0001662690774537623f, 0.00015314172196667641f, 0.000491948623675853f, 0.00018045133037958294f, 0.0001741303422022611f, 0.00024519709404557943f, 0.000227804557653144f, 0.00020919470989611f, 0.00047340893070213497f, 0.000340361351845786f, 0.0007951866136863828f, 0.00016614435298833996f, 4.844816794502549e-05f, 0.00015329763118643314f, 0.00033291830914095044f, 0.00017911000759340823f, 0.00023799337213858962f, 0.0001815389550756663f, 0.00011124684533569962f, 0.00034227556898258626f, 0.00042807342833839357f, 0.0003683778049889952f, 5.493243588716723e-05f, 0.0002491924387868494f, 0.00024286986445076764f, 0.00010872112034121528f, 0.00018153800920117646f, 7.608735177200288e-05f, 0.00028473485144786537f, 0.0002665314532350749f, 0.00023949322348926216f, 0.00017038389341905713f, 0.0001428925315849483f, 0.00016583164688199759f, 4.578587686410174e-05f, 0.0001652287901379168f, 0.00032997067319229245f, 8.997733675641939e-05f, 0.0001485321845393628f, 0.000203402538318187f, 0.0002460404357407242f, 0.00035355344880372286f, 0.0005828721914440393f, 0.0003408878983464092f, 0.0001983016263693571f, 0.00014053608174435794f, 0.00017612517694942653f, 0.0002926512388512492f, 9.416238026460633e-05f, 0.0005463561974465847f, 0.0003681967791635543f, 0.0004060939827468246f, 9.564697393216193e-05f, 0.00019848073134198785f, 0.0005390975275076926f, 0.00017471215687692165f, 0.0004621518892236054f, 0.00010392055992269889f, 0.0003245285479351878f, 0.00020096480147913098f, 6.321266846498474e-05f, 0.00028380853473208845f, 0.00023135222727432847f, 0.0005677276640199125f, 0.00019534588500391692f, 0.00021881729480810463f, 0.00010641440894687548f, 0.00033028432517312467f, 0.00027588228113017976f, 0.0002276852319482714f, 0.0002611445088405162f, 0.0003444929898250848f, 0.0003900498559232801f, 8.614364196546376e-05f, 7.89821642683819e-05f, 0.0003183396765962243f, 0.00010072844452224672f, 0.0003256210475228727f, 0.00023708422668278217f, 0.00013756236876361072f, 0.0006272547179833055f, 0.0001993628975469619f, 0.00022921930940356106f, 8.495607471559197e-05f, 0.00018318695947527885f, 0.0002787466801237315f, 0.00036721330252476037f, 0.00020060995302628726f, 0.0001428607210982591f, 0.00014091496996115893f, 3.5128043236909434e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #119 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009081311523914337f, 0.008582251146435738f, 0.005189378280192614f, 0.008091994561254978f, 0.00393270468339324f, 0.008352714590728283f, 0.0052671292796730995f, 0.0173746757209301f, 0.006067903712391853f, 0.007369948085397482f, 0.0068389298394322395f, 0.01290169544517994f, 0.00460804533213377f, 0.017129451036453247f, 0.006304414477199316f, 0.01058055181056261f, 0.00817660428583622f, 0.006401443853974342f, 0.0161251462996006f, 0.004500280134379864f, 0.0038471573498100042f, 0.015176872722804546f, 0.022200901061296463f, 0.005816007032990456f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #120 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_35_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00021367792214732617f, 0.00020193532691337168f, 0.00012210302520543337f, 0.000190399878192693f, 9.253423195332289e-05f, 0.0001965344708878547f, 0.0001239324628841132f, 0.00040881591849029064f, 0.00014277420996222645f, 0.00017341054626740515f, 0.00016091599536594003f, 0.0003035693080164492f, 0.00010842459596460685f, 0.00040304590947926044f, 0.00014833916793577373f, 0.0002489541657269001f, 0.0001923906966112554f, 0.0001506222179159522f, 0.00037941522896289825f, 0.00010588894656393677f, 9.052135283127427e-05f, 0.0003571028937585652f, 0.0005223741754889488f, 0.00013684722944162786f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #121 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00029393285512924194f, 0.00034228904405608773f, 0.0002549909695517272f, 0.0008397279307246208f, 0.0009536207071505487f, 0.0003294196503702551f, 0.0013333065435290337f, 0.0011024586856365204f, 0.0007289619534276426f, 0.0008881277753971517f, 0.0004475513123907149f, 0.00018886943871621042f, 0.0004166718863416463f, 0.0006632176227867603f, 0.0006031595985405147f, 0.0009344384889118373f, 0.0006157797761261463f, 0.0002771342115011066f, 0.00037244425038807094f, 0.0004887363174930215f, 0.0010241821873933077f, 0.00018466963956598192f, 0.00017261724860873073f, 0.0006631763535551727f, 0.0010491159046068788f, 0.0006004370516166091f, 0.0009917294373735785f, 0.0005267217638902366f, 0.0007339281728491187f, 0.0006926216883584857f, 0.0008856974309310317f, 0.0005285033257678151f, 0.0005576799158006907f, 0.0010188098531216383f, 0.0007282419828698039f, 0.00024109829973895103f, 0.0004584859998431057f, 0.0007359073497354984f, 0.00020907064026687294f, 0.000220539586734958f, 0.0009450422367081046f, 0.0010993600590154529f, 0.0007038641488179564f, 0.0011990608181804419f, 0.000846674432978034f, 0.0006677649798803031f, 0.0006330789183266461f, 0.0006612528814002872f, 0.0006404190789908171f, 0.000769194564782083f, 0.0013199648819863796f, 0.0007040327182039618f, 0.0010545006953179836f, 0.0012784498976543546f, 0.0006561818881891668f, 0.0008309229742735624f, 0.0004804053751286119f, 0.0003071170358452946f, 0.0009842771105468273f, 0.0006336889928206801f, 0.000496220774948597f, 0.0005182154127396643f, 0.001451390329748392f, 0.0006774036446586251f, 0.000906232395209372f, 0.0010184437269344926f, 0.0005231270333752036f, 0.0008196101989597082f, 0.0009150586556643248f, 0.0005648407386615872f, 0.0006971710827201605f, 0.00038360970211215317f, 0.00033240322954952717f, 0.0005048750317655504f, 9.37254008022137e-05f, 0.0012528625084087253f, 0.0011193976970389485f, 0.0002518193796277046f, 0.0006227511912584305f, 0.0005253161652944982f, 0.0004566200077533722f, 0.0007139265653677285f, 0.0011224212357774377f, 0.0003255452902521938f, 0.001005464349873364f, 0.0005062285927124321f, 0.0006124887731857598f, 0.000777331879362464f, 0.0010244682198390365f, 0.0007787150098010898f, 0.0005639722221530974f, 0.0010323543101549149f, 0.0006602515932172537f, 0.0005131205543875694f, 0.0004354700504336506f, 0.00040703697595745325f, 0.00023854275059420615f, 0.00098488200455904f, 0.0006347274174913764f, 0.0006112836999818683f, 0.0006317394436337054f, 0.0009110806277021766f, 0.0009340764372609556f, 0.0008142715669237077f, 0.0004129971785005182f, 0.000756645284127444f, 0.00034733457141555846f, 0.0004544506664387882f, 0.0004970405716449022f, 0.0009882670128718019f, 0.0009241259540431201f, 0.0008384489919990301f, 0.0004584909765981138f, 0.0004044844245072454f, 0.00046996521996334195f, 0.0007365642231889069f, 0.00036630197428166866f, 0.0008936840458773077f, 0.0006010879296809435f, 0.0011875252239406109f, 0.0002985980245284736f, 0.0006199152558110654f, 0.0004821215698029846f, 0.00020820491772610694f, 0.0005005451384931803f, 0.0005666133365593851f, 0.0014767460525035858f, 0.0009913303656503558f, 0.0006407680921256542f, 0.0006288741715252399f, 0.0003834421222563833f, 0.0007491419673897326f, 0.0006447980413213372f, 0.00031329694320447743f, 0.0007986676064319909f, 0.0003133982827421278f, 0.000685062725096941f, 0.0009385172743350267f, 0.0016685310984030366f, 0.0010281983995810151f, 0.0001943746319739148f, 0.0006403842126019299f, 0.00033383723348379135f, 0.0010637241648510098f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #122 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.548000626731664e-05f, 6.460726581281051e-05f, 4.812969928025268e-05f, 0.00015849915507715195f, 0.0001799964957172051f, 6.217815825948492e-05f, 0.00025166242267005146f, 0.00020808975386898965f, 0.0001375920110149309f, 0.0001676346582826227f, 8.447558502666652e-05f, 3.564922008081339e-05f, 7.864707004046068e-05f, 0.00012518273433670402f, 0.00011384674144210294f, 0.00017637583368923515f, 0.00011622880992945284f, 5.2309253078419715e-05f, 7.029908010736108e-05f, 9.224927634932101e-05f, 0.0001933150051627308f, 3.4856508136726916e-05f, 3.258161086705513e-05f, 0.0001251749345101416f, 0.0001980212691705674f, 0.000113332862383686f, 0.0001871895365184173f, 9.941905591404065e-05f, 0.00013852938718628138f, 0.000130732762045227f, 0.00016717592370696366f, 9.975532157113776e-05f, 0.00010526242112973705f, 0.00019230098405387253f, 0.00013745612523052841f, 4.550745143205859e-05f, 8.653951226733625e-05f, 0.00013890296395402402f, 3.946221113437787e-05f, 4.1626983147580177e-05f, 0.00017837730410974473f, 0.00020750488329213113f, 0.00013285478053148836f, 0.00022632346372120082f, 0.00015981031174305826f, 0.00012604104995261878f, 0.00011949403415201232f, 0.0001248118787771091f, 0.00012087949289707467f, 0.00014518594252876937f, 0.0002491441846359521f, 0.0001328866055700928f, 0.00019903764768969268f, 0.000241308196564205f, 0.00012385472655296326f, 0.00015683722449466586f, 9.067681094165891e-05f, 5.7968529290519655e-05f, 0.00018578290473669767f, 0.00011960918345721439f, 9.366197627969086e-05f, 9.781347762327641e-05f, 0.00027395080542191863f, 0.00012786034494638443f, 0.00017105191363953054f, 0.000192231877008453f, 9.87405437626876e-05f, 0.000154701920109801f, 0.0001727178751025349f, 0.00010661403211997822f, 0.00013159147056285292f, 7.240656850626692e-05f, 6.27413101028651e-05f, 9.529547241982073e-05f, 1.769072696333751e-05f, 0.00023647856141906232f, 0.0002112869988195598f, 4.7531062591588125e-05f, 0.00011754466686397791f, 9.915374539559707e-05f, 8.618730498710647e-05f, 0.00013475406740326434f, 0.0002118576958309859f, 6.144687358755618e-05f, 0.00018978200387209654f, 9.555095311952755e-05f, 0.00011560763232409954f, 0.00014672186807729304f, 0.00019336900732014328f, 0.00014698292943648994f, 0.00010645009751897305f, 0.0001948575081769377f, 0.00012462289305403829f, 9.685181430540979e-05f, 8.219523442676291e-05f, 7.68284808145836e-05f, 4.502508818404749e-05f, 0.00018589707906357944f, 0.00011980519047938287f, 0.00011538017133716494f, 0.00011924120190087706f, 0.00017196702538058162f, 0.00017630749789532274f, 0.0001536942581878975f, 7.79534675530158e-05f, 0.00014281725452747196f, 6.555960862897336e-05f, 8.577784319641069e-05f, 9.38167140702717e-05f, 0.00018653599545359612f, 0.00017442934040445834f, 0.00015825775335542858f, 8.654045086586848e-05f, 7.63466814532876e-05f, 8.870621968526393e-05f, 0.0001390269462717697f, 6.913972174515948e-05f, 0.0001686834148131311f, 0.00011345570965204388f, 0.00022414610430132598f, 5.636056084767915e-05f, 0.00011700938193826005f, 9.100074385059997e-05f, 3.929880404029973e-05f, 9.447820048080757e-05f, 0.00010694860975490883f, 0.0002787367266137153f, 0.00018711421580519527f, 0.00012094536941731349f, 0.0001187003799714148f, 7.237493264256045e-05f, 0.00014140100392978638f, 0.00012170601985417306f, 5.91349889873527e-05f, 0.00015074899420142174f, 5.915411747992039e-05f, 0.00012930600496474653f, 0.0001771457027643919f, 0.00031493627466261387f, 0.00019407307263463736f, 3.6688328691525385e-05f, 0.00012087290815543383f, 6.301198300207034e-05f, 0.00020077858061995357f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #123 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016126781702041626f, 0.012528028339147568f, 0.01951306313276291f, 0.004206305369734764f, 0.009113007225096226f, 0.020099470391869545f, 0.010268145240843296f, 0.003959461580961943f, 0.01320333406329155f, 0.004593660589307547f, 0.017443446442484856f, 0.020983925089240074f, 0.009291596710681915f, 0.017156001180410385f, 0.0025222396943718195f, 0.006421826314181089f, 0.01032828725874424f, 0.01598242111504078f, 0.025930071249604225f, 0.00848330557346344f, 0.006127724889665842f, 0.027263058349490166f, 0.01232046727091074f, 0.017057016491889954f, 0.003460547188296914f, 0.030332021415233612f, 0.011883332394063473f, 0.008765244856476784f, 0.005834826268255711f, 0.0126646114513278f, 0.0019319017883390188f, 0.01043375302106142f, 0.01614988222718239f, 0.008159435354173183f, 0.008172345347702503f, 0.032624855637550354f, 0.00534247187897563f, 0.005658915266394615f, 0.024607570841908455f, 0.012738848105072975f, 0.0026034489274024963f, 0.01318049244582653f, 0.006453590467572212f, 0.007058267947286367f, 0.006048867013305426f, 0.007886655628681183f, 0.01065436564385891f, 0.007794835139065981f, 0.005977540742605925f, 0.0057541378773748875f, 0.007162315305322409f, 0.007889796048402786f, 0.008091102354228497f, 0.006018890533596277f, 0.005146247800439596f, 0.006075557321310043f, 0.015744484961032867f, 0.028680870309472084f, 0.013038945384323597f, 0.004883232060819864f, 0.03328275308012962f, 0.010126727633178234f, 0.005141190718859434f, 0.015984145924448967f, 0.0017126090824604034f, 0.005935658700764179f, 0.01189173199236393f, 0.004305751994252205f, 0.025918759405612946f, 0.007981550879776478f, 0.007542959880083799f, 0.024153398349881172f, 0.008521012030541897f, 0.012745914049446583f, 0.014906722120940685f, 0.005401242058724165f, 0.006085771135985851f, 0.021371202543377876f, 0.01956220529973507f, 0.0034399523865431547f, 0.008167685009539127f, 0.014065604656934738f, 0.013262545689940453f, 0.014440231025218964f, 0.002578496001660824f, 0.009139467030763626f, 0.003944419790059328f, 0.00839013047516346f, 0.002965380437672138f, 0.008275258354842663f, 0.007460948079824448f, 0.0028564599342644215f, 0.035005293786525726f, 0.01629830338060856f, 0.013903333805501461f, 0.02536703273653984f, 0.01575733907520771f, 0.010761580429971218f, 0.008132241666316986f, 0.01847911812365055f, 0.01826734095811844f, 0.013710705563426018f, 0.006598546635359526f, 0.011805536225438118f, 0.011611723341047764f, 0.004691040143370628f, 0.008954551070928574f, 0.0070309326983988285f, 0.00916466023772955f, 0.0026619473937898874f, 0.005248077679425478f, 0.018088895827531815f, 0.0178472138941288f, 0.01335449144244194f, 0.011009430512785912f, 0.006521503906697035f, 0.013250540010631084f, 0.006386335473507643f, 0.008717643097043037f, 0.009818753227591515f, 0.018702050670981407f, 0.005311581771820784f, 0.014181283302605152f, 0.023833947256207466f, 0.023148393258452415f, 0.0054389359429478645f, 0.00448274239897728f, 0.011178247630596161f, 0.007845010608434677f, 0.015142453834414482f, 0.007768690586090088f, 0.00400765473023057f, 0.01578916795551777f, 0.011877202428877354f, 0.007444259710609913f, 0.015670863911509514f, 0.04201160743832588f, 0.010317418724298477f, 0.002561556175351143f, 0.002811175538226962f, 0.03805868327617645f, 0.010530238971114159f, 0.009477588348090649f, 0.005881123710423708f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #124 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00037945370422676206f, 0.0002947771572507918f, 0.00045913091162219644f, 9.897189011098817e-05f, 0.00021442370780277997f, 0.00047292871749959886f, 0.0002416034258203581f, 9.316380601376295e-05f, 0.0003106666845269501f, 0.00010808613296831027f, 0.0004104340332560241f, 0.0004937394405715168f, 0.00021862580615561455f, 0.00040367062320001423f, 5.934681757935323e-05f, 0.0001511018053861335f, 0.00024301852681674063f, 0.0003760569670703262f, 0.0006101193139329553f, 0.00019960719509981573f, 0.00014418175851460546f, 0.0006414837553165853f, 0.00028989335987716913f, 0.00040134156006388366f, 8.142463775584474e-05f, 0.0007136946078389883f, 0.0002796078333631158f, 0.0002062410640064627f, 0.00013729002967011184f, 0.00029799086041748524f, 4.545651245280169e-05f, 0.00024550006492063403f, 0.000379997247364372f, 0.00019198672089260072f, 0.00019229047757107764f, 0.0007676436798647046f, 0.00012570522085297853f, 0.0001331509556621313f, 0.0005790016730315983f, 0.0002997376141138375f, 6.125762593001127e-05f, 0.0003101292531937361f, 0.0001518491917522624f, 0.00016607689030934125f, 0.0001423262874595821f, 0.00018556836585048586f, 0.00025069096591323614f, 0.00018340788665227592f, 0.00014064801507629454f, 0.0001353914849460125f, 0.00016852507542353123f, 0.0001856422604760155f, 0.00019037887977901846f, 0.00014162095612846315f, 0.00012108818918932229f, 0.0001429542899131775f, 0.00037045846693217754f, 0.0006748440209776163f, 0.0003067987272515893f, 0.0001148995797848329f, 0.0007831235998310149f, 0.00023827595578040928f, 0.00012096919817849994f, 0.00037609756691381335f, 4.029668343719095e-05f, 0.00013966255937702954f, 0.00027980547747574747f, 0.00010131181625183672f, 0.0006098531885072589f, 0.00018780119717121124f, 0.00017748141544871032f, 0.0005683152703568339f, 0.00020049441081937402f, 0.00029990385519340634f, 0.00035074641346000135f, 0.00012708804570138454f, 0.00014319461479317397f, 0.0005028518498875201f, 0.00046028720680624247f, 8.094005897874013e-05f, 0.0001921808288898319f, 0.00033095540129579604f, 0.0003120599139947444f, 0.0003397701366338879f, 6.067049616831355e-05f, 0.0002150462823919952f, 9.280988160753623e-05f, 0.00019741483265534043f, 6.977366138016805e-05f, 0.00019471195992082357f, 0.00017555172962602228f, 6.721082172589377e-05f, 0.0008236540015786886f, 0.00038348950329236686f, 0.00032713726977817714f, 0.0005968713667243719f, 0.0003707609139382839f, 0.00025321365683339536f, 0.00019134687318000942f, 0.0004348027869127691f, 0.0004298198036849499f, 0.00032260484294965863f, 0.00015525992785114795f, 0.00027777731884270906f, 0.00027321703964844346f, 0.000110377419332508f, 0.00021069531794637442f, 0.00016543371020816267f, 0.00021563906921073794f, 6.263405521167442e-05f, 0.00012348417658358812f, 0.0004256210813764483f, 0.0004199344548396766f, 0.0003142233472317457f, 0.00025904542417265475f, 0.0001534471521154046f, 0.00031177743221633136f, 0.0001502667146269232f, 0.00020512101764325052f, 0.00023102949489839375f, 0.00044004825758747756f, 0.0001249783963430673f, 0.0003336772497277707f, 0.0005607987986877561f, 0.0005446680588647723f, 0.00012797497038263828f, 0.00010547629062784836f, 0.00026301760226488113f, 0.00018458848353475332f, 0.0003562930505722761f, 0.00018279271898791194f, 9.429775673197582e-05f, 0.00037150984280742705f, 0.0002794635947793722f, 0.00017515906074550003f, 0.00036872620694339275f, 0.000988508458249271f, 0.0002427627914585173f, 6.0271911934250966e-05f, 6.61453086649999e-05f, 0.0008954984368756413f, 0.000247770338319242f, 0.00022300207638181746f, 0.00013837938604410738f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #125 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007536327466368675f, 0.00801999494433403f, 0.0067336950451135635f, 0.005868542939424515f, 0.00482900720089674f, 0.008653054013848305f, 0.0057270098477602005f, 0.0243294145911932f, 0.007582750637084246f, 0.004557856824249029f, 0.008644452318549156f, 0.010195615701377392f, 0.0051389094442129135f, 0.01878167688846588f, 0.00564588513225317f, 0.011415651068091393f, 0.0064653619192540646f, 0.006628744304180145f, 0.020462773740291595f, 0.005341097246855497f, 0.006616700906306505f, 0.025069810450077057f, 0.028801048174500465f, 0.0077012283727526665f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #126 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_39_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 24,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017732536070980132f, 0.00018870577332563698f, 0.00015843988512642682f, 0.00013808337098453194f, 0.00011362370423739776f, 0.0002036012738244608f, 0.0001347531797364354f, 0.0005724568036384881f, 0.00017841767112258822f, 0.00010724369349190965f, 0.00020339888578746468f, 0.00023989684996195138f, 0.00012091551616322249f, 0.0004419218166731298f, 0.00013284436136018485f, 0.00026860355865210295f, 0.00015212617290671915f, 0.00015597045421600342f, 0.00048147703637368977f, 0.00012567287194542587f, 0.00015568708477076143f, 0.0005898778908886015f, 0.0006776717491447926f, 0.00018120538152288646f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #127 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008113232324831188f, 0.0010775492992252111f, 0.0005723476060666144f, 0.0005991226062178612f, 0.0005695565487258136f, 0.000216620959690772f, 0.0005635196575894952f, 0.0007562107057310641f, 0.0003600462223403156f, 0.0007292486843653023f, 0.0006705644773319364f, 0.0008619209984317422f, 0.000840610999148339f, 0.0011124180164188147f, 0.0008973948424682021f, 0.0006878897547721863f, 0.0010445098159834743f, 0.0004966605338267982f, 0.0008466296712867916f, 0.001007533399388194f, 0.0009211411233991385f, 0.0008542484138160944f, 0.0008827652782201767f, 0.0004457172763068229f, 0.0005492367199622095f, 0.0011834970209747553f, 0.0008028554148040712f, 0.00032605533488094807f, 0.0008094653603620827f, 0.0009527849615551531f, 0.0008204763289541006f, 0.0016063262009993196f, 0.001053839223459363f, 0.0007532924646511674f, 0.00043955587898381054f, 0.0010581195820122957f, 0.0007339760777540505f, 0.0008233463158831f, 0.0013385368511080742f, 0.0010147790890187025f, 0.0005099226837046444f, 0.0008318627951666713f, 0.0005092656356282532f, 0.0009151047561317682f, 0.000905409106053412f, 0.0011860650265589356f, 0.0017066756263375282f, 0.0005550682544708252f, 0.000514390179887414f, 0.0007766901981085539f, 0.0005007683648727834f, 0.0006554853171110153f, 0.000437646551290527f, 0.0010441462509334087f, 0.00060150126228109f, 0.0003157711762469262f, 0.0006524514174088836f, 0.001402502995915711f, 0.0007123181130737066f, 0.0008592941449023783f, 0.001589618856087327f, 0.0008488030289299786f, 0.000896283017937094f, 0.0009491632226854563f, 0.0007608009618707001f, 0.00026909320149570704f, 0.0009162002825178206f, 0.0009112415718846023f, 0.0008256774744950235f, 0.0018196996534243226f, 0.0007441292982548475f, 0.0010527452686801553f, 0.0005630338564515114f, 0.0005592163070105016f, 0.0006325563881546259f, 0.0008976782555691898f, 0.0012618321925401688f, 0.0007584310369566083f, 0.0008813321474008262f, 0.0007691272767260671f, 0.00038797224988229573f, 0.0002951848437078297f, 0.0010764754842966795f, 0.0008863614057190716f, 0.0007648871978744864f, 0.0006317524239420891f, 0.0009947698563337326f, 0.0007322739693336189f, 0.0015254851896315813f, 0.0009563984349370003f, 0.0006792198400944471f, 0.0008939726394601166f, 0.000677296775393188f, 0.0008244588389061391f, 0.0006576509913429618f, 0.0006155837909318507f, 0.0004802854382432997f, 0.0010785897029563785f, 0.0003330846084281802f, 0.0005879493546672165f, 0.0012911255471408367f, 0.0009774758946150541f, 0.0005699036410078406f, 0.0003486775967758149f, 0.0011401113588362932f, 0.0007246094755828381f, 0.0003114966384600848f, 0.0008546321769244969f, 0.0009993676794692874f, 0.0008321625646203756f, 0.0006647012196481228f, 0.0006660241633653641f, 0.0009249746799468994f, 0.0007223795400932431f, 0.0008455723291262984f, 0.00047298544086515903f, 0.0007365786004811525f, 0.0005878127412870526f, 0.0007805165369063616f, 0.0010107239941135049f, 0.00093432841822505f, 0.0003556467709131539f, 0.000744287041015923f, 0.00073562579927966f, 8.918435196392238e-05f, 0.0006522645708173513f, 0.000863214663695544f, 0.00040231048478744924f, 0.000933731731493026f, 0.0009674594621174037f, 0.0005159184220246971f, 0.0008207346545532346f, 0.0008078076643869281f, 0.0006354910437949002f, 0.0003875376423820853f, 0.0012079855659976602f, 0.0005167658091522753f, 0.0010282461298629642f, 0.00040580963832326233f, 0.0004213530628476292f, 0.0007244300213642418f, 0.0006180170457810163f, 0.0008321877103298903f, 0.0013572543393820524f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #128 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00017561019922140986f, 0.00023323459026869386f, 0.00012388413597363979f, 0.0001296795526286587f, 0.00012328001321293414f, 4.688741319114342e-05f, 0.00012197333126096055f, 0.00016368113574571908f, 7.793168333591893e-05f, 0.00015784523566253483f, 0.00014514308713842183f, 0.00018656202882993966f, 0.00018194950826000422f, 0.00024078189744614065f, 0.00019424031779635698f, 0.0001488931302446872f, 0.00022608322615269572f, 0.00010750172805273905f, 0.0001832522393669933f, 0.00021807971643283963f, 0.00019938017067033798f, 0.00018490130605641752f, 0.00019107376283500344f, 9.647510887589306e-05f, 0.00011888179869856685f, 0.00025616688071750104f, 0.00017377734184265137f, 7.057438779156655e-05f, 0.00017520805704407394f, 0.00020622945157811046f, 0.00017759136972017586f, 0.0003476878919173032f, 0.00022810256632510573f, 0.00016304948076140136f, 9.514147677691653e-05f, 0.00022902904311195016f, 0.00015886846813373268f, 0.00017821257642935961f, 0.00028972511063329875f, 0.00021964803454466164f, 0.00011037231161026284f, 0.00018005596939474344f, 0.00011023009574273601f, 0.00019807361240964383f, 0.00019597499340306967f, 0.0002567227347753942f, 0.00036940842983312905f, 0.0001201440318254754f, 0.00011133930092910305f, 0.0001681138965068385f, 0.0001083908646251075f, 0.00014187920896802098f, 9.472820966038853e-05f, 0.0002260045293951407f, 0.00013019441394135356f, 6.834838859504089e-05f, 0.00014122252468951046f, 0.0003035705303773284f, 0.0001541806268505752f, 0.00018599345639813691f, 0.00034407159546390176f, 0.00018372265913058072f, 0.00019399965822231025f, 0.00020544553990475833f, 0.00016467469686176628f, 5.824498293804936e-05f, 0.00019831073586829007f, 0.0001972374302567914f, 0.000178717149537988f, 0.000393872382119298f, 0.0001610661274753511f, 0.00022786577756050974f, 0.00012186817912152037f, 0.0001210418704431504f, 0.00013691626372747123f, 0.00019430165411904454f, 0.0002731224521994591f, 0.00016416172729805112f, 0.00019076355965808034f, 0.00016647692245896906f, 8.397625060752034e-05f, 6.389249756466597e-05f, 0.0002330021670786664f, 0.00019185214478056878f, 0.0001655591477174312f, 0.00013674225192517042f, 0.00021531704987864941f, 0.0001585000572958961f, 0.000330189912347123f, 0.00020701158791780472f, 0.00014701652980875224f, 0.00019349958165548742f, 0.00014660028682556003f, 0.00017845338152255863f, 0.00014234796981327236f, 0.00013324255996849388f, 0.00010395735444035381f, 0.00023345978115685284f, 7.209587056422606e-05f, 0.0001272611116291955f, 0.0002794629835989326f, 0.00021157378796488047f, 0.00012335513019934297f, 7.54709544708021e-05f, 0.00024677609326317906f, 0.00015684108075220138f, 6.742317054886371e-05f, 0.00018498436838854104f, 0.0002163122408092022f, 0.0001801208418328315f, 0.0001438739855075255f, 0.0001441603380953893f, 0.0002002099499804899f, 0.00015635840827599168f, 0.00018302338139619678f, 0.00010237727838102728f, 0.00015943178732413799f, 0.00012723154213745147f, 0.00016894210421014577f, 0.00021877030667383224f, 0.0002022345579462126f, 7.697942783124745e-05f, 0.00016110026626847684f, 0.00015922555758152157f, 1.9303874069009908e-05f, 0.00014118208491709083f, 0.00018684205133467913f, 8.707974484423175e-05f, 0.00020210540969856083f, 0.00020940574177075177f, 0.00011167008779011667f, 0.00017764729273039848f, 0.0001748492504702881f, 0.00013755146937910467f, 8.388217975152656e-05f, 0.00026146741583943367f, 0.000111853500129655f, 0.00022256295778788626f, 8.783713565208018e-05f, 9.120149479713291e-05f, 0.00015680224169045687f, 0.00013376923743635416f, 0.0001801262842491269f, 0.00029377650935202837f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #129 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003426330629736185f, 0.007337741553783417f, 0.0022055439185351133f, 0.0026277301367372274f, 0.007228709291666746f, 0.015240880660712719f, 0.006955714430660009f, 0.006173917092382908f, 0.011643859557807446f, 0.006982831284403801f, 0.006074688397347927f, 0.003766733920201659f, 0.004990074317902327f, 0.005277811083942652f, 0.007054149638861418f, 0.005762411281466484f, 0.001542849699035287f, 0.010752116329967976f, 0.003856804920360446f, 0.0071332729421556f, 0.006158594973385334f, 0.0034771414939314127f, 0.006197480484843254f, 0.013075181283056736f, 0.005466182250529528f, 0.008664114400744438f, 0.005146163981407881f, 0.009896794334053993f, 0.0017814460443332791f, 0.0025455690920352936f, 0.005569430999457836f, 0.006349945906549692f, 0.0053838882595300674f, 0.002945355139672756f, 0.009492723271250725f, 0.001093109487555921f, 0.0010434252908453345f, 0.008069499395787716f, 0.0012730779126286507f, 0.005828601308166981f, 0.0040078554302453995f, 0.006626976653933525f, 0.008721551857888699f, 0.0061093769036233425f, 0.0020343849901109934f, 0.005819076206535101f, 0.00542138097807765f, 0.008535653352737427f, 0.012956294231116772f, 0.001118965563364327f, 0.009922818280756474f, 0.007764161564409733f, 0.010837426409125328f, 0.0027795007918030024f, 0.016232743859291077f, 0.01150276605039835f, 0.00724836764857173f, 0.005395311396569014f, 0.006323385518044233f, 0.007527497131377459f, 0.0021865670569241047f, 0.0014485473511740565f, 0.008648972027003765f, 0.003656314918771386f, 0.004047153517603874f, 0.005967660807073116f, 0.00670055765658617f, 0.006631696596741676f, 0.00851911585777998f, 0.004774108994752169f, 0.0015924948966130614f, 0.0028983219526708126f, 0.00873593706637621f, 0.0053013963624835014f, 0.010617414489388466f, 0.001196523429825902f, 0.005802513565868139f, 0.005286060273647308f, 0.005615984555333853f, 0.006355565972626209f, 0.017565302550792694f, 0.007498355582356453f, 0.0055343834683299065f, 0.003420287510380149f, 0.0033085932955145836f, 0.0052682687528431416f, 0.003148025833070278f, 0.00329153286293149f, 0.002547656185925007f, 0.0031584491953253746f, 0.007370765320956707f, 0.005469569470733404f, 0.005436392035335302f, 0.0033551612868905067f, 0.00767058040946722f, 0.002362719038501382f, 0.01628144644200802f, 0.0032057410571724176f, 0.004986491985619068f, 0.0076394639909267426f, 0.003897417336702347f, 0.00537867471575737f, 0.010090957395732403f, 0.008696626871824265f, 0.00458892248570919f, 0.003630454186350107f, 0.005706906784325838f, 0.0037777479737997055f, 0.00611340394243598f, 0.004048344679176807f, 0.004349956288933754f, 0.004302138462662697f, 0.005606940481811762f, 0.0032223279122263193f, 0.008459373377263546f, 0.004654948133975267f, 0.009443769231438637f, 0.004814986605197191f, 0.007060248404741287f, 0.005659759975969791f, 0.001815018942579627f, 0.013575426302850246f, 0.0028571411967277527f, 0.01019025593996048f, 0.03785299137234688f, 0.0088358698412776f, 0.006351620424538851f, 0.010283669456839561f, 0.003025677753612399f, 0.00484709395095706f, 0.0070548756048083305f, 0.004576251842081547f, 0.0027336226776242256f, 0.008174475282430649f, 0.007338418159633875f, 0.0034900277387350798f, 0.009175753220915794f, 0.0028065366204828024f, 0.007334235589951277f, 0.020516490563750267f, 0.008887229487299919f, 0.006614875514060259f, 0.001453500590287149f, 0.002574482699856162f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #130 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 144,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.061954576987773e-05f, 0.00017265274072997272f, 5.189515286474489e-05f, 6.182894867379218e-05f, 0.00017008728173095733f, 0.00035860895877704024f, 0.00016366387717425823f, 0.00014526864106301218f, 0.0002739731571637094f, 0.0001643019204493612f, 0.00014293384447228163f, 8.862903632689267e-05f, 0.00011741351772798225f, 0.00012418378901202232f, 0.00016597998910583556f, 0.00013558614591602236f, 3.630234641605057e-05f, 0.0002529909834265709f, 9.074835543287918e-05f, 0.00016784171748440713f, 0.0001449081173632294f, 8.181509474525228e-05f, 0.00014582306903321296f, 0.0003076513239648193f, 0.00012861605500802398f, 0.00020386152027640492f, 0.00012108621012885123f, 0.00023286575742531568f, 4.191637708572671e-05f, 5.989574492559768e-05f, 0.0001310454390477389f, 0.00014941049448680133f, 0.00012667971896007657f, 6.930247764103115e-05f, 0.00022335820540320128f, 2.5720224584802054e-05f, 2.4551183742005378e-05f, 0.0001898705813800916f, 2.9954775527585298e-05f, 0.00013714356464333832f, 9.430248610442504e-05f, 0.00015592886484228075f, 0.0002052129857474938f, 0.0001437500468455255f, 4.786788485944271e-05f, 0.00013691943604499102f, 0.00012756191426888108f, 0.00020083891286049038f, 0.0003048539801966399f, 2.6328601961722597e-05f, 0.00023347808746621013f, 0.0001826861553126946f, 0.0002549982746131718f, 6.540001777466387e-05f, 0.0003819469129666686f, 0.00027065331232734025f, 0.0001705498289084062f, 0.00012694850738625973f, 0.00014878554793540388f, 0.0001771175884641707f, 5.144863825989887e-05f, 3.4083466744050384e-05f, 0.00020350523118395358f, 8.603093738202006e-05f, 9.522714390186593e-05f, 0.00014041554823052138f, 0.0001576601789565757f, 0.00015603992505930364f, 0.00020044979464728385f, 0.00011233198165427893f, 3.7470468669198453e-05f, 6.819581176387146e-05f, 0.00020555146329570562f, 0.00012473874085117131f, 0.0002498215180821717f, 2.8153492166893557e-05f, 0.00013652973575517535f, 0.0001243778970092535f, 0.000132140819914639f, 0.0001495427277404815f, 0.00041330125532113016f, 0.00017643190221861005f, 0.0001302207965636626f, 8.047735173022375e-05f, 7.784925401210785e-05f, 0.00012395926751196384f, 7.407119846902788e-05f, 7.744783215457574e-05f, 5.9944854001514614e-05f, 7.431645644828677e-05f, 0.00017342976934742182f, 0.00012869575584772974f, 0.00012791510380338877f, 7.894496957305819e-05f, 0.0001804842468118295f, 5.559339115279727e-05f, 0.0003830928762909025f, 7.542920502601191e-05f, 0.00011732922575902194f, 0.00017975209630094469f, 9.170393605018035e-05f, 0.00012655706086661667f, 0.000237434302107431f, 0.00020462651445996016f, 0.00010797465074574575f, 8.542245632270351e-05f, 0.00013428015518002212f, 8.888819138519466e-05f, 0.0001438447943655774f, 9.525517089059576e-05f, 0.00010235191439278424f, 0.00010122678941115737f, 0.00013192801270633936f, 7.58194801164791e-05f, 0.00019904407963622361f, 0.00010952819138765335f, 0.00022220633400138468f, 0.00011329380504321307f, 0.0001661235000938177f, 0.00013317081902641803f, 4.27063278038986e-05f, 0.0003194218152202666f, 6.722685066051781e-05f, 0.00023977072851266712f, 0.0008906586444936693f, 0.00020790281996596605f, 0.00014944990107323974f, 0.00024196869344450533f, 7.119242218323052e-05f, 0.00011404927499825135f, 0.00016599707305431366f, 0.00010767651838250458f, 6.432053487515077e-05f, 0.00019234059436712414f, 0.00017266866052523255f, 8.211829845095053e-05f, 0.00021590008691418916f, 6.603615474887192e-05f, 0.0001725702459225431f, 0.0004827409575227648f, 0.00020911128376610577f, 0.0001556441275170073f, 3.4200013033114374e-05f, 6.057606515241787e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #131 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.011674920096993446f, 0.00967758521437645f, 0.015152351930737495f, 0.011016469448804855f, 0.01176652405411005f, 0.01619415171444416f, 0.008486178703606129f, 0.01100312452763319f, 0.008744033984839916f, 0.01037510298192501f, 0.013144008815288544f, 0.01059738639742136f, 0.010575838387012482f, 0.012610395438969135f, 0.010502099059522152f, 0.012652534060180187f, 0.014006352983415127f, 0.012395715340971947f, 0.010893812403082848f, 0.02277071215212345f, 0.01010508369654417f, 0.013387504033744335f, 0.015813259407877922f, 0.010064502246677876f, 0.012258939445018768f, 0.011503418907523155f, 0.009467682801187038f, 0.010606971569359303f, 0.010264255106449127f, 0.012583581730723381f, 0.008025221526622772f, 0.013279394246637821f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #132 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_43_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0002747040125541389f, 0.00022770788928028196f, 0.0003565259394235909f, 0.000259211054071784f, 0.0002768593840301037f, 0.0003810388734564185f, 0.00019967480329796672f, 0.0002588970528449863f, 0.0002057419769698754f, 0.00024412007769569755f, 0.00030927080661058426f, 0.00024935026885941625f, 0.0002488432510290295f, 0.0002967151813209057f, 0.0002471082261763513f, 0.0002977066906169057f, 0.0003295612405054271f, 0.0002916638914030045f, 0.0002563250018283725f, 0.0005357814952731133f, 0.00023776668240316212f, 0.0003150000993628055f, 0.00037207669811323285f, 0.00023681182938162237f, 0.00028844564803875983f, 0.0002706686791498214f, 0.00022276901290751994f, 0.0002495757944416255f, 0.00024151189427357167f, 0.0002960842684842646f, 0.0001888287515612319f, 0.0003124563372693956f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #133 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00032341168844141066f, 0.0011865413980558515f, 0.00031805879552848637f, 0.0008569696801714599f, 0.0010884026996791363f, 0.0005688673700205982f, 0.0008494585636071861f, 0.0005880423123016953f, 0.0014194999821484089f, 0.0008934537181630731f, 0.0015005762688815594f, 0.0008270027465187013f, 0.0005817862693220377f, 0.0023835927713662386f, 0.0018034526146948338f, 0.00045473157661035657f, 0.0012256193440407515f, 0.000860156083945185f, 0.0018238837365061045f, 0.0010998439975082874f, 0.0008807090925984085f, 0.0005938247195445001f, 0.00045556086115539074f, 0.000861405220348388f, 0.0007413583807647228f, 0.0003781490959227085f, 0.0007626949809491634f, 0.0007613935740664601f, 0.000902740634046495f, 0.0013664724538102746f, 0.0009966593934223056f, 0.0005773658631369472f, 0.0009861013386398554f, 0.0009993897983804345f, 0.0012530501699075103f, 0.0019189204322174191f, 0.000491703802254051f, 0.0012835707748308778f, 0.0008920939289964736f, 0.0019229738973081112f, 0.00020619432325474918f, 0.0008181802113540471f, 0.001389644225127995f, 0.00037444414920173585f, 0.0003722052788361907f, 0.0005747010582126677f, 0.0007024090155027807f, 0.0007651346386410296f, 0.0008263441268354654f, 0.0008337268955074251f, 0.000501352536957711f, 0.0003271549358032644f, 0.0013295274693518877f, 0.0013445240911096334f, 0.0010767508065328002f, 0.0011076905066147447f, 0.0009372856584377587f, 0.0005134441307745874f, 0.0007680002017877996f, 0.0005117442342452705f, 0.0007940009818412364f, 0.00040789582999423146f, 0.0013508248375728726f, 0.00033558884751982987f, 0.0008354282472282648f, 0.001025501755066216f, 0.0005406698328442872f, 0.0004367642686702311f, 0.0005455253995023668f, 0.0009065046906471252f, 0.0012371288612484932f, 0.0002626857894938439f, 0.0011775476159527898f, 0.0005784829845651984f, 0.0006723963306285441f, 0.0004884321824647486f, 0.001138803898356855f, 0.000778655637986958f, 0.0013029094552621245f, 0.0003051734820473939f, 0.0006195916794240475f, 0.0010168574517592788f, 0.001022843411192298f, 0.0008496730006299913f, 0.0006060089217498899f, 0.0009372962522320449f, 0.000397734489524737f, 0.000381026096874848f, 0.0009999593021348119f, 0.0010798530420288444f, 0.0009866416221484542f, 0.0006766162696294487f, 0.0006114588468335569f, 0.00039862815174274147f, 0.0007683074800297618f, 0.00048203315236605704f, 0.000643390289042145f, 0.00031804980244487524f, 0.0013087191618978977f, 0.00039831263711676f, 0.0006941891624592245f, 0.0006983534549362957f, 0.0007145750569179654f, 0.0006280087400227785f, 0.0011540219420567155f, 0.0015654697781428695f, 0.0003846239414997399f, 0.00016849528765305877f, 0.0007325145998038352f, 0.0011674624402076006f, 0.0004144678823649883f, 0.0011905290884897113f, 0.00035709235817193985f, 0.0003865266917273402f, 0.0009499866282567382f, 0.0005531367496587336f, 0.001068085664883256f, 0.0005120820715092123f, 0.0007835535798221827f, 0.0009194154408760369f, 0.00022173108300194144f, 0.0003391610807739198f, 0.001141487853601575f, 0.0008704440551809967f, 0.0005368822021409869f, 0.0015807083109393716f, 0.0004956136108376086f, 0.0017418760107830167f, 0.0006078238948248327f, 0.0009586358210071921f, 0.00044055533362552524f, 0.0009647823753766716f, 0.00032291992101818323f, 0.0006823497242294252f, 0.0006670299335382879f, 0.0009310308960266411f, 0.0012299418449401855f, 0.0011178526328876615f, 0.0009425882599316537f, 0.001230547670274973f, 0.0008969102636910975f, 0.0009070640662685037f, 0.0012828489998355508f, 0.0005295726587064564f, 0.0006213458254933357f, 0.00047359123709611595f, 0.0014349691336974502f, 0.0011930068721994758f, 0.001028575235977769f, 0.0011111185885965824f, 0.0008787124534137547f, 0.00040993193397298455f, 0.0017185272881761193f, 0.0008498267270624638f, 0.0002563465968705714f, 0.00025566943804733455f, 0.0008692567935213447f, 0.0010591840837150812f, 0.0015341861872002482f, 0.000568760558962822f, 0.0009047134662978351f, 0.0007762688328512013f, 0.0008521358831785619f, 0.0006855885148979723f, 0.00035162732820026577f, 0.0003149861586280167f, 0.0008165589533746243f, 0.0013209863100200891f, 0.0002915158402174711f, 0.0003751031181309372f, 0.0003678590292111039f, 0.0003669419384095818f, 0.0010024365037679672f, 0.0005781264044344425f, 0.0008779867202974856f, 0.0010440903715789318f, 0.0009377953829243779f, 0.0009509588126093149f, 0.0012210238492116332f, 0.0007839326863177121f, 0.0005535164382308722f, 0.000994425150565803f, 0.0009899070719256997f, 0.0006925844354555011f, 0.000849821197334677f, 0.0010336096165701747f, 0.0009221091750077903f, 0.000737036345526576f, 0.0007869915571063757f, 0.0006954104756005108f, 0.0014408944407477975f, 0.0009405541350133717f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #134 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.156988117960282e-05f, 0.00018920094589702785f, 5.0716331315925345e-05f, 0.00013664881407748908f, 0.00017355216550640762f, 9.07092253328301e-05f, 0.00013545111869461834f, 9.376677917316556e-05f, 0.000226347561692819f, 0.00014246640785131603f, 0.00023927564325276762f, 0.00013187041622586548f, 9.276921628043056e-05f, 0.0003800777776632458f, 0.0002875710488297045f, 7.250960334204137e-05f, 0.0001954321633093059f, 0.00013715690874960274f, 0.00029082890250720084f, 0.00017537653911858797f, 0.00014043420378584415f, 9.468881762586534e-05f, 7.264183659572154e-05f, 0.00013735609536524862f, 0.00011821391672128811f, 6.0298079915810376e-05f, 0.00012161616905359551f, 0.00012140865146648139f, 0.00014394726895261556f, 0.00021789201127830893f, 0.00015892315423116088f, 9.206435788655654e-05f, 0.00015723961405456066f, 0.0001593585329828784f, 0.00019980616343673319f, 0.0003059830632992089f, 7.840504258638248e-05f, 0.00020467284775804728f, 0.00014224958431441337f, 0.000306629401165992f, 3.287888830527663e-05f, 0.00013046360982116312f, 0.00022158688807394356f, 5.9707304899347946e-05f, 5.935030276305042e-05f, 9.163943468593061e-05f, 0.00011200321750948206f, 0.00012200518540339544f, 0.00013176539505366236f, 0.00013294261589180678f, 7.994358747964725e-05f, 5.2166764362482354e-05f, 0.0002120009157806635f, 0.0002143922174582258f, 0.0001716942060738802f, 0.00017662771278992295f, 0.00014945566363167018f, 8.187166531570256e-05f, 0.00012246210826560855f, 8.160060679074377e-05f, 0.00012660809443332255f, 6.504137127194554e-05f, 0.0002153969107894227f, 5.351160143618472e-05f, 0.00013321390724740922f, 0.00016352224338334054f, 8.621296001365408e-05f, 6.96446149959229e-05f, 8.698720921529457e-05f, 0.00014454746269620955f, 0.00019726742175407708f, 4.188678212813102e-05f, 0.00018776684009935707f, 9.224248788086697e-05f, 0.00010721752187237144f, 7.788336370140314e-05f, 0.00018158892635256052f, 0.00012416118988767266f, 0.00020775651501026005f, 4.866169183515012e-05f, 9.879750723484904e-05f, 0.00016214385686907917f, 0.0001630983460927382f, 0.000135485315695405f, 9.663165837991983e-05f, 0.00014945735165383667f, 6.342108827084303e-05f, 6.0756836319342256e-05f, 0.00015944935148581862f, 0.00017218886932823807f, 0.0001573257613927126f, 0.00010789040970848873f, 9.750068420544267e-05f, 6.356358790071681e-05f, 0.00012251110456418246f, 7.686299795750529e-05f, 0.0001025923338602297f, 5.071489795227535e-05f, 0.0002086829044856131f, 6.351327465381473e-05f, 0.00011069251195294783f, 0.00011135653039673343f, 0.0001139431624324061f, 0.00010013965948019177f, 0.00018401553097646683f, 0.00024962329189293087f, 6.133053102530539e-05f, 2.6867557608056813e-05f, 0.00011680372699629515f, 0.00018615869339555502f, 6.608932017115876e-05f, 0.00018983680638484657f, 5.6940461945487186e-05f, 6.163393845781684e-05f, 0.0001514809118816629f, 8.820088260108605e-05f, 0.00017031248717103153f, 8.165447798091918e-05f, 0.0001249421911779791f, 0.00014660615124739707f, 3.535631549311802e-05f, 5.40812143299263e-05f, 0.0001820168981794268f, 0.00013879738980904222f, 8.560899732401595e-05f, 0.00025205317069776356f, 7.902848301455379e-05f, 0.0002777522895485163f, 9.692106686998159e-05f, 0.00015286006964743137f, 7.024911610642448e-05f, 0.00015384018479380757f, 5.1491464546415955e-05f, 0.00010880464833462611f, 0.00010636181832524016f, 0.00014845830446574837f, 0.00019612140022218227f, 0.00017824812675826252f, 0.00015030120266601443f, 0.0001962180103873834f, 0.00014301757619250566f, 0.00014463666593655944f, 0.00020455775666050613f, 8.444345439784229e-05f, 9.907721687341109e-05f, 7.551688759122044e-05f, 0.00022881419863551855f, 0.00019023190543521196f, 0.00016401232278440148f, 0.00017717434093356133f, 0.0001401158224325627f, 6.536603905260563e-05f, 0.00027402921114116907f, 0.0001355098356725648f, 4.087596244062297e-05f, 4.076798359164968e-05f, 0.00013860806939192116f, 0.0001688930788077414f, 0.0002446349535603076f, 9.06921923160553e-05f, 0.00014426183770410717f, 0.00012378059909678996f, 0.00013587804278358817f, 0.00010932108853012323f, 5.606902777799405e-05f, 5.022638288210146e-05f, 0.00013020509504713118f, 0.00021063897293061018f, 4.648390313377604e-05f, 5.9812380641233176e-05f, 5.865726780029945e-05f, 5.8511031966190785e-05f, 0.00015984434867277741f, 9.218562627211213e-05f, 0.00014000010560266674f, 0.00016648630844429135f, 0.00014953695063013583f, 0.0001516359334345907f, 0.00019469937251415104f, 0.00012500263983383775f, 8.826142584439367e-05f, 0.00015856689424254f, 0.00015784645802341402f, 0.00011043663107557222f, 0.00013550894800573587f, 0.00016481507918797433f, 0.000147035694681108f, 0.00011752474529203027f, 0.00012549039092846215f, 0.00011088726023444906f, 0.00022975902538746595f, 0.00014997684047557414f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #135 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.018054069951176643f, 0.006620359607040882f, 0.025574853643774986f, 0.003165300702676177f, 0.0038707833737134933f, 0.010654552839696407f, 0.018586188554763794f, 0.009516652673482895f, 0.002369675086811185f, 0.009977934882044792f, 0.009137600660324097f, 0.006001332309097052f, 0.006852998398244381f, 0.0055337930098176f, 0.004216439556330442f, 0.005444965325295925f, 0.005392185878008604f, 0.001886388286948204f, 0.004735955037176609f, 0.0018985667265951633f, 0.009858437813818455f, 0.008257915265858173f, 0.01627267152070999f, 0.009266496635973454f, 0.006080280523747206f, 0.01218719407916069f, 0.009298691526055336f, 0.006684798281639814f, 0.013127396814525127f, 0.012594174593687057f, 0.004340497311204672f, 0.01436261460185051f, 0.00817538145929575f, 0.009938888251781464f, 0.00833510048687458f, 0.008014840073883533f, 0.021734444424510002f, 0.00337464502081275f, 0.007259948644787073f, 0.005115495529025793f, 0.04040203243494034f, 0.0065132747404277325f, 0.010180490091443062f, 0.017615055665373802f, 0.011495635844767094f, 0.0067142825573682785f, 0.012829427607357502f, 0.010898608714342117f, 0.006939527578651905f, 0.014497960917651653f, 0.009372871369123459f, 0.012696769088506699f, 0.0064120814204216f, 0.006217225454747677f, 0.006952555384486914f, 0.00991812627762556f, 0.013241811655461788f, 0.008346638642251492f, 0.017746424302458763f, 0.020466869696974754f, 0.00616034772247076f, 0.007098950445652008f, 0.004745627287775278f, 0.015753185376524925f, 0.010432726703584194f, 0.0037518369499593973f, 0.004354389384388924f, 0.01427605003118515f, 0.009706073440611362f, 0.01072175707668066f, 0.006314217112958431f, 0.027233602479100227f, 0.0033200338948518038f, 0.014634041115641594f, 0.008650427684187889f, 0.012654799968004227f, 0.012364260852336884f, 0.007224102504551411f, 0.0015333802439272404f, 0.017031719908118248f, 0.007008409593254328f, 0.00927030947059393f, 0.003003495279699564f, 0.0020464821718633175f, 0.0046643759123981f, 0.008930345997214317f, 0.023561742156744003f, 0.01828763633966446f, 0.008256755769252777f, 0.009024511091411114f, 0.008561867289245129f, 0.013110853731632233f, 0.010244139470160007f, 0.004618815612047911f, 0.006539377849549055f, 0.010644081979990005f, 0.009107488207519054f, 0.024293096736073494f, 0.004487911704927683f, 0.009070849046111107f, 0.011705826036632061f, 0.009653838351368904f, 0.010212792083621025f, 0.004330016206949949f, 0.003704899689182639f, 0.007189409341663122f, 0.01952354423701763f, 0.017613664269447327f, 0.006330360192805529f, 0.005396105349063873f, 0.016108980402350426f, 0.0017283160705119371f, 0.00666263559833169f, 0.015792200341820717f, 0.013920251280069351f, 0.00924642849713564f, 0.005742236971855164f, 0.013588028959929943f, 0.019500192254781723f, 0.004343730863183737f, 0.01191216055303812f, 0.016114214435219765f, 0.003987095318734646f, 0.007410502061247826f, 0.017223171889781952f, 0.006030035670846701f, 0.019651329144835472f, 0.011775963939726353f, 0.011120031587779522f, 0.010214206762611866f, 0.02053849585354328f, 0.007564245257526636f, 0.014181413687765598f, 0.009137528948485851f, 0.008277913555502892f, 0.008080964908003807f, 0.00548674026504159f, 0.005394511856138706f, 0.004774217959493399f, 0.006883119698613882f, 0.007588690146803856f, 0.017314834520220757f, 0.010868092998862267f, 0.00927661545574665f, 0.009569159708917141f, 0.015397798269987106f, 0.006086662411689758f, 0.008693883195519447f, 0.01323214266449213f, 0.004951925482600927f, 0.008388222195208073f, 0.014585408382117748f, 0.001807614928111434f, 0.001677349559031427f, 0.03017820417881012f, 0.038819875568151474f, 0.009412476792931557f, 0.005315831396728754f, 0.005033385008573532f, 0.02320755273103714f, 0.005093209911137819f, 0.005347067024558783f, 0.004767707083374262f, 0.021697018295526505f, 0.0214054137468338f, 0.021281491965055466f, 0.012034153565764427f, 0.00662871403619647f, 0.017615893855690956f, 0.013947735540568829f, 0.02492549456655979f, 0.016685280948877335f, 0.0028590322472155094f, 0.010823585093021393f, 0.015073404647409916f, 0.011003278195858002f, 0.005029336083680391f, 0.002625341759994626f, 0.0014480185927823186f, 0.007488604169338942f, 0.007097747642546892f, 0.0037012833636254072f, 0.007103467360138893f, 0.011099714785814285f, 0.005984210409224033f, 0.005986114498227835f, 0.010553400032222271f, 0.005812572315335274f, 0.013979761861264706f, 0.0033526450861245394f, 0.0028871374670416117f, 0.005886649712920189f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #136 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00042480166302993894f, 0.00015577317390125245f, 0.0006017612759023905f, 7.447766256518662e-05f, 9.107725782087073e-05f, 0.0002506953605916351f, 0.0004373221017885953f, 0.00022392124810721725f, 5.5757060181349516e-05f, 0.00023477493959944695f, 0.0002150023792637512f, 0.00014120782725512981f, 0.00016124702233355492f, 0.0001302068994846195f, 9.92103450698778e-05f, 0.00012811683700419962f, 0.00012687496200669557f, 4.4385607907315716e-05f, 0.00011143423762405291f, 4.467216058401391e-05f, 0.00023196324764285237f, 0.0001943038951139897f, 0.00038288638461381197f, 0.00021803521667607129f, 0.00014306542288977653f, 0.00028675750945694745f, 0.00021879274572711438f, 0.00015728938160464168f, 0.0003088799421675503f, 0.0002963335136882961f, 0.00010212935012532398f, 0.00033794387127272785f, 0.00019236192747484893f, 0.000233856204431504f, 0.00019612001779023558f, 0.00018858448311220855f, 0.0005113987135700881f, 7.940341311041266e-05f, 0.0001708223280729726f, 0.00012036460248054937f, 0.0009506360511295497f, 0.00015325352433137596f, 0.0002395409537712112f, 0.00041447189869359136f, 0.00027048555784858763f, 0.0001579831150593236f, 0.0003018688876181841f, 0.0002564378664828837f, 0.0001632830098969862f, 0.000341128499712795f, 0.0002205381606472656f, 0.0002987475018016994f, 0.00015087251085788012f, 0.0001462876534787938f, 0.00016358954599127173f, 0.0002333676820853725f, 0.0003115720464847982f, 0.000196391498320736f, 0.00041756292921490967f, 0.00048157342826016247f, 0.00014494935749098659f, 0.00016703412984497845f, 0.00011166182230226696f, 0.0003706631832756102f, 0.0002454759378451854f, 8.827851706882939e-05f, 0.00010245622252114117f, 0.0003359070688020438f, 0.00022837820870336145f, 0.00025227662990801036f, 0.00014856981579214334f, 0.0006407906766980886f, 7.81184426159598e-05f, 0.00034433038672432303f, 0.00020353947184048593f, 0.0002977600088343024f, 0.0002909237809944898f, 0.00016997888451442122f, 3.607953476603143e-05f, 0.000400746357627213f, 0.000164903758559376f, 0.00021812492923345417f, 7.067048136377707e-05f, 4.8152523959288374e-05f, 0.00010975002078339458f, 0.0002101257850881666f, 0.0005543939187191427f, 0.00043029733933508396f, 0.00019427661027293652f, 0.0002123414451489225f, 0.00020145571033935994f, 0.0003084906784351915f, 0.0002410385786788538f, 0.00010867801756830886f, 0.00015386771701741964f, 0.00025044899666681886f, 0.00021429384651128203f, 0.0005716023151762784f, 0.00010559792281128466f, 0.0002134317473974079f, 0.00027543120086193085f, 0.00022714913939125836f, 0.0002403010003035888f, 0.00010188273881794885f, 8.717411401448771e-05f, 0.00016916258027777076f, 0.00045937750837765634f, 0.00041443915688432753f, 0.00014894964988343418f, 0.00012696719204541296f, 0.00037903484189882874f, 4.066626206622459e-05f, 0.00015676789917051792f, 0.00037158120539970696f, 0.0003275353228673339f, 0.000217563021578826f, 0.00013511146244127303f, 0.0003197183250449598f, 0.00045882805716246367f, 0.0001022054348140955f, 0.0002802861272357404f, 0.0003791579802054912f, 9.381400741403922e-05f, 0.00017436475900467485f, 0.00040525110671296716f, 0.00014188319619279355f, 0.0004623842251021415f, 0.0002770815044641495f, 0.0002616478013806045f, 0.00024033428053371608f, 0.00048325874377042055f, 0.00017798224871512502f, 0.0003336803347337991f, 0.00021500069124158472f, 0.00019477444584481418f, 0.0001901403593365103f, 0.00012909977522213012f, 0.00012692969175986946f, 0.00011233454279135913f, 0.0001619557588128373f, 0.00017855741316452622f, 0.00040740787517279387f, 0.0002557198458816856f, 0.00021827331511303782f, 0.0002251567057101056f, 0.0003623011289164424f, 0.00014321558410301805f, 0.00020456196216400713f, 0.0003113445418421179f, 0.00011651589738903567f, 0.00019736993999686092f, 0.0003431860823184252f, 4.25321159127634e-05f, 3.94670496461913e-05f, 0.0007100754301063716f, 0.0009134088759310544f, 0.000221470050746575f, 0.0001250783825526014f, 0.00011843258835142478f, 0.0005460600950755179f, 0.0001198402387672104f, 0.0001258133415831253f, 0.0001121813475037925f, 0.0005105180898681283f, 0.0005036568036302924f, 0.0005007410072721541f, 0.0002831565507221967f, 0.00015596974117215723f, 0.000414491631090641f, 0.0003281820099800825f, 0.0005864822305738926f, 0.0003925948403775692f, 6.727135041728616e-05f, 0.00025467260275036097f, 0.0003546683583408594f, 0.00025890066171996295f, 0.00011833732423838228f, 6.177274917718023e-05f, 3.407102485653013e-05f, 0.00017620244761928916f, 0.00016700582636985928f, 8.708902169018984e-05f, 0.00016714041703380644f, 0.00026116977096535265f, 0.00014080495748203248f, 0.00014084976282902062f, 0.00024831530754454434f, 0.0001367664081044495f, 0.00032893556635826826f, 7.888576510595158e-05f, 6.793264765292406e-05f, 0.00013850940740667284f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #137 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007749897427856922f, 0.005714763421565294f, 0.00891017820686102f, 0.0028800428844988346f, 0.011259741149842739f, 0.006039251107722521f, 0.003631435101851821f, 0.006122638005763292f, 0.0035006001126021147f, 0.011075149290263653f, 0.0063078561797738075f, 0.006608118303120136f, 0.006569951307028532f, 0.0054818810895085335f, 0.005352150183171034f, 0.005054481793195009f, 0.012093666940927505f, 0.01664048433303833f, 0.007726133335381746f, 0.012266820296645164f, 0.013870679773390293f, 0.007803161628544331f, 0.016888733953237534f, 0.004401994403451681f, 0.010988786816596985f, 0.005640050396323204f, 0.014101756736636162f, 0.012818151153624058f, 0.0036602572072297335f, 0.00567741459235549f, 0.004379058722406626f, 0.007833954878151417f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #138 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_46_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00018235052993986756f, 0.0001344650227110833f, 0.00020965126168448478f, 6.776571535738185e-05f, 0.0002649350790306926f, 0.00014210003428161144f, 8.54455356602557e-05f, 0.00014406206901185215f, 8.236706344177946e-05f, 0.00026059173978865147f, 0.0001484201493440196f, 0.00015548513329122216f, 0.00015458709094673395f, 0.00012898544082418084f, 0.00012593294377438724f, 0.00011892898328369483f, 0.00028455688152462244f, 0.00039154081605374813f, 0.00018179137259721756f, 0.0002886310685425997f, 0.00032636892865411937f, 0.00018360381363891065f, 0.00039738198393024504f, 0.00010357634164392948f, 0.00025855968124233186f, 0.0001327070640400052f, 0.00033180604805238545f, 0.00030160354799591005f, 8.612369856564328e-05f, 0.00013358623255044222f, 0.00010303667659172788f, 0.00018432835349813104f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #139 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0008625427144579589f, 0.00051379285287112f, 0.0007296895491890609f, 0.000546658702660352f, 0.001209146692417562f, 0.0005111004575155675f, 0.0006256686756387353f, 0.0008359849452972412f, 0.0005311143468134105f, 0.000782495888415724f, 0.0007235250086523592f, 0.001010733307339251f, 0.0002581264707259834f, 0.0007385193603113294f, 0.000339593825628981f, 0.0006864143651910126f, 0.0010900238994508982f, 0.0006189288105815649f, 0.00078851223224774f, 0.0004767559003084898f, 0.000597604492213577f, 0.0010670560877770185f, 0.0010359393199905753f, 0.0010001875925809145f, 0.0007992943283170462f, 0.00034232038888148963f, 0.0007739160791970789f, 0.0006788976606912911f, 0.0010651586344465613f, 0.0005619360599666834f, 0.0006341176340356469f, 0.0009419318521395326f, 0.0003293619956821203f, 0.00034364452585577965f, 0.0007245560409501195f, 0.0006921215099282563f, 0.0002382792008575052f, 0.00059777736896649f, 0.0004890146665275097f, 0.0009467689669691026f, 0.00047706166515126824f, 0.0008485311991535127f, 0.0005926581216044724f, 0.0011245313799008727f, 0.0005165537586435676f, 0.0008116841781884432f, 0.0005404351395554841f, 0.0006057712598703802f, 0.0014962459681555629f, 0.0007633787463419139f, 0.0006356958183459938f, 0.0009400745038874447f, 0.000943232502322644f, 0.00016035352018661797f, 0.0009569679968990386f, 0.00021536275744438171f, 0.0007625056896358728f, 0.0008143483428284526f, 0.0007173212943598628f, 0.0007827544468455017f, 0.0005537251709029078f, 0.0014227807987481356f, 0.0008706835797056556f, 0.0006278990767896175f, 0.0003101000329479575f, 0.0007867384701967239f, 0.0008765716920606792f, 0.00041726717608980834f, 0.001086161588318646f, 0.0004928153939545155f, 0.0004844842478632927f, 0.0005188795039430261f, 0.0005307404207997024f, 0.0008663290645927191f, 0.001121107256039977f, 0.0008398945210501552f, 0.0009402642608620226f, 0.0008013627957552671f, 0.0004064335080329329f, 0.0012637708568945527f, 0.0005791607545688748f, 0.0007223670254461467f, 0.0008164357859641314f, 0.0004893203149549663f, 0.0006815489032305777f, 0.00033381141838617623f, 0.0009274841868318617f, 0.0006080447346903384f, 0.000664547027554363f, 0.0008764293161220849f, 0.0008444120758213103f, 0.0009694222826510668f, 0.0007733152015134692f, 0.0010843065101653337f, 0.0009733180631883442f, 0.0005611676606349647f, 0.0004615365469362587f, 0.0011277964804321527f, 0.000733088469132781f, 0.0007174392812885344f, 0.0005699022440239787f, 0.000882044667378068f, 0.00037464036722667515f, 0.0007754567777737975f, 0.0008738130563870072f, 0.0004071898583788425f, 0.000660342862829566f, 0.0006980164325796068f, 0.0010012310231104493f, 0.0006227890262380242f, 0.0007714850944466889f, 0.0004533161118160933f, 0.00022306227765511721f, 0.0008311395649798214f, 0.0007627648301422596f, 0.0007503266097046435f, 0.0007808137452229857f, 0.0004313462704885751f, 0.0008490485488437116f, 0.0008822308154776692f, 0.00045108652557246387f, 0.0005932406056672335f, 0.0007453255821019411f, 0.000491010898258537f, 0.0008564531453885138f, 0.0005125324241816998f, 0.0006771680200472474f, 0.0008079250692389905f, 0.0009258085628971457f, 0.00032946636201813817f, 0.0008485734579153359f, 0.0002794366155285388f, 0.002470482839271426f, 0.0007100891671143472f, 0.0004241573915351182f, 0.0006259874789975584f, 0.0010425894288346171f, 0.0005358005873858929f, 0.00045203304034657776f, 0.0009928301442414522f, 0.0008864885312505066f, 0.0009048365755006671f, 0.0007861183839850128f, 0.001098264125175774f, 0.0004907884285785258f, 0.0011856890050694346f, 0.0006651260773651302f, 0.0007853349670767784f, 0.00032986249425448477f, 0.0006142286001704633f, 0.0009907200001180172f, 0.0008178122225217521f, 0.0009024980827234685f, 0.0008739387849345803f, 0.0010244139702990651f, 0.0010817450238391757f, 0.00033939265995286405f, 0.0009125432698056102f, 0.000779742025770247f, 0.0008890738245099783f, 0.0012509481748566031f, 0.00122064258903265f, 0.000714385649189353f, 0.0013826241483911872f, 0.000877216225489974f, 0.000656621006783098f, 0.0009237349731847644f, 0.0007226343150250614f, 0.00028698352980427444f, 0.0008438162039965391f, 0.000777672918047756f, 0.0006596830207854509f, 0.0003550536057446152f, 0.0004507796256802976f, 0.00037243010592646897f, 0.0003904745390173048f, 0.0007339532603509724f, 0.0005985241150483489f, 0.0007098575006239116f, 0.0009141196496784687f, 0.0007627690793015063f, 0.0007413552375510335f, 0.0007431278354488313f, 0.000912803749088198f, 0.001705822185613215f, 0.0008764963713474572f, 0.0003245310508646071f, 0.0006256687338463962f, 0.001273418660275638f, 0.0008483212441205978f, 0.0010146802524104714f, 0.0008299885084852576f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #140 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001651688653510064f, 9.838652476901188e-05f, 0.00013972872693557292f, 0.00010468003165442497f, 0.00023154028167482466f, 9.787095768842846e-05f, 0.00011980970157310367f, 0.00016008330567274243f, 0.00010170343011850491f, 0.00014984064910095185f, 0.0001385482755722478f, 0.00019354597316123545f, 4.94288069603499e-05f, 0.00014141955762170255f, 6.502904579974711e-05f, 0.00013144193508196622f, 0.0002087293833028525f, 0.00011851907765958458f, 0.00015099272422958165f, 9.129429963650182e-05f, 0.00011443567200331017f, 0.00020433127065189183f, 0.00019837269792333245f, 0.00019152657478116453f, 0.00015305739361792803f, 6.555115396622568e-05f, 0.00014819769421592355f, 0.00013000256149098277f, 0.00020396792388055474f, 0.00010760550503619015f, 0.00012142759806010872f, 0.00018037114932667464f, 6.306973955361173e-05f, 6.580471381312236e-05f, 0.00013874570140615106f, 0.0001325347984675318f, 4.562823960441165e-05f, 0.00011446877761045471f, 9.36417345656082e-05f, 0.00018129740783479065f, 9.135284926742315e-05f, 0.00016248579777311534f, 0.00011348848784109578f, 0.0002153372479369864f, 9.89152176771313e-05f, 0.00015542993787676096f, 0.0001034882734529674f, 0.00011599952995311469f, 0.0002865171118173748f, 0.00014617989654652774f, 0.00012172980495961383f, 0.0001800154714146629f, 0.00018062020535580814f, 3.070620005019009e-05f, 0.00018325042037758976f, 4.123995313420892e-05f, 0.00014601270959246904f, 0.00015594009892083704f, 0.00013736031542066485f, 0.00014989015471655875f, 0.00010603319242363796f, 0.0002724492223933339f, 0.00016672776837367564f, 0.00012023680028505623f, 5.9381258324719965e-05f, 0.00015065306797623634f, 0.00016785527986939996f, 7.990276208147407e-05f, 0.00020798978221137077f, 9.436954132979736e-05f, 9.277420031139627e-05f, 9.936057176673785e-05f, 0.00010163182741962373f, 0.00016589391452725977f, 0.0002146815531887114f, 0.000160831943503581f, 0.00018005180754698813f, 0.00015345348219852895f, 7.782821921864524e-05f, 0.00024200030020438135f, 0.00011090387124568224f, 0.00013832653348799795f, 0.00015633982548024505f, 9.37002623686567e-05f, 0.00013051024870947003f, 6.392176874214783e-05f, 0.00017760455375537276f, 0.00011643487960100174f, 0.00012725454871542752f, 0.00016782802413217723f, 0.0001616970112081617f, 0.00018563530466053635f, 0.00014808263222221285f, 0.0002076345554087311f, 0.00018638130859471858f, 0.00010745836334535852f, 8.837993664201349e-05f, 0.0002159624855266884f, 0.00014037959044799209f, 0.0001373829145450145f, 0.00010913095320574939f, 0.00016890330880414695f, 7.174012716859579e-05f, 0.00014849271974526346f, 0.00016732703079469502f, 7.797304715495557e-05f, 0.00012644947855733335f, 0.00013366361963562667f, 0.00019172637257725f, 0.00011925827857339755f, 0.0001477321784477681f, 8.680579776410013e-05f, 4.2714342271210626e-05f, 0.00015915546100586653f, 0.00014606233162339777f, 0.0001436805323464796f, 0.00014951852790545672f, 8.259878086391836e-05f, 0.00016258485266007483f, 0.00016893894644454122f, 8.637885184725747e-05f, 0.00011360002827132121f, 0.000142722885357216f, 9.402399882674217e-05f, 0.00016400277672801167f, 9.814516670303419e-05f, 0.0001296713453484699f, 0.00015471009828615934f, 0.00017728368402458727f, 6.308972660917789e-05f, 0.0001624938886379823f, 5.350949868443422e-05f, 0.00047307435306720436f, 0.00013597543875221163f, 8.122217695927247e-05f, 0.00011987074685748667f, 0.0001996461214730516f, 0.00010260080307489261f, 8.656010322738439e-05f, 0.0001901176874525845f, 0.00016975426115095615f, 0.0001732677483232692f, 0.00015053432434797287f, 0.00021030730567872524f, 9.398139809491113e-05f, 0.0002270483528263867f, 0.00012736541975755244f, 0.00015038430865388364f, 6.316558574326336e-05f, 0.00011761903442675248f, 0.00018971360987052321f, 0.00015660338976886123f, 0.00017281994223594666f, 0.00016735109966248274f, 0.00019616569625213742f, 0.00020714405400212854f, 6.499051960418001e-05f, 0.00017474350170232356f, 0.00014931330224499106f, 0.00017024933185894042f, 0.00023954488278832287f, 0.00023374163720291108f, 0.00013679817493539304f, 0.0002647595829330385f, 0.00016797870921436697f, 0.00012573678395710886f, 0.00017688660591375083f, 0.00013837771257385612f, 5.495466393767856e-05f, 0.0001615829096408561f, 0.00014891709724906832f, 0.00012632312427740544f, 6.798944377806038e-05f, 8.63200839376077e-05f, 7.131688471417874e-05f, 7.477222243323922e-05f, 0.0001405451912432909f, 0.00011461177200544626f, 0.00013593106996268034f, 0.0001750453666318208f, 0.00014606314653065056f, 0.00014196259144227952f, 0.0001423020294168964f, 0.0001747933856677264f, 0.0003266489948146045f, 0.00016784085892140865f, 6.214465975062922e-05f, 0.0001198097161250189f, 0.00024384776770602912f, 0.00016244559083133936f, 0.0001943017850862816f, 0.00015893504314590245f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #141 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.016203798353672028f, 0.007554057519882917f, 0.004066365770995617f, 0.004748281091451645f, 0.004219761583954096f, 0.012228432111442089f, 0.0046197157353162766f, 0.020520733669400215f, 0.005375362001359463f, 0.00460541108623147f, 0.005876836366951466f, 0.006047585513442755f, 0.018575487658381462f, 0.002638086210936308f, 0.011204955168068409f, 0.0059713092632591724f, 0.0029317927546799183f, 0.020427679643034935f, 0.006107732187956572f, 0.007507406175136566f, 0.00726756127551198f, 0.008298497647047043f, 0.0135270981118083f, 0.011631753295660019f, 0.0021178063470870256f, 0.010800798423588276f, 0.005408957600593567f, 0.016951031982898712f, 0.008287230506539345f, 0.004936345387250185f, 0.009154113940894604f, 0.005108756013214588f, 0.012456993572413921f, 0.01994352973997593f, 0.012352596037089825f, 0.015573079697787762f, 0.018828265368938446f, 0.003236063988879323f, 0.005848153959959745f, 0.010064392350614071f, 0.008015774190425873f, 0.005387116689234972f, 0.007616246119141579f, 0.0036570231895893812f, 0.006200704257935286f, 0.006238773465156555f, 0.003814087016507983f, 0.008336582221090794f, 0.0025631317403167486f, 0.005506657995283604f, 0.008391538634896278f, 0.0012246272526681423f, 0.0021680211648344994f, 0.025277849286794662f, 0.0041873520240187645f, 0.023499736562371254f, 0.007079042959958315f, 0.002604075940325856f, 0.010222547687590122f, 0.004853956867009401f, 0.006549963727593422f, 0.005234846379607916f, 0.005766728427261114f, 0.00585844274610281f, 0.014938839711248875f, 0.005808607675135136f, 0.00799810141324997f, 0.007871921174228191f, 0.004368157126009464f, 0.00888268556445837f, 0.006928008049726486f, 0.01448057871311903f, 0.0065931170247495174f, 0.005201361607760191f, 0.010389847680926323f, 0.0044304425828158855f, 0.004964267369359732f, 0.0046560149639844894f, 0.010677642188966274f, 0.004456842318177223f, 0.014525695703923702f, 0.005282385274767876f, 0.005113884806632996f, 0.028444737195968628f, 0.007052164524793625f, 0.008121535181999207f, 0.007076418958604336f, 0.0036364237312227488f, 0.008585551753640175f, 0.0017275908030569553f, 0.005375778768211603f, 0.005427372641861439f, 0.0014747085515409708f, 0.0047073462046682835f, 0.0014292163541540504f, 0.009676567278802395f, 0.006433594040572643f, 0.006272854749113321f, 0.005234536714851856f, 0.0069043319672346115f, 0.013152011670172215f, 0.00797850638628006f, 0.01835136115550995f, 0.0015132968546822667f, 0.006619186606258154f, 0.023146644234657288f, 0.0024009146727621555f, 0.006353786215186119f, 0.012704758904874325f, 0.003986837808042765f, 0.005294825416058302f, 0.007499827072024345f, 0.0119880186393857f, 0.0016590936575084925f, 0.012636708095669746f, 0.0057333228178322315f, 0.009924924932420254f, 0.013512912206351757f, 0.0015329272719100118f, 0.004222664050757885f, 0.0188178401440382f, 0.006678732577711344f, 0.011024024337530136f, 0.01520662009716034f, 0.0044531188905239105f, 0.005063287913799286f, 0.006685076281428337f, 0.006183235440403223f, 0.008996655233204365f, 0.015121294185519218f, 0.007910223677754402f, 0.024142660200595856f, 0.001490857801400125f, 0.011371629312634468f, 0.01391166914254427f, 0.0063115814700722694f, 0.0017983692232519388f, 0.006221874617040157f, 0.003920017275959253f, 0.004404927138239145f, 0.00456650834530592f, 0.006975763011723757f, 0.0034290167968720198f, 0.00343267060816288f, 0.014398650266230106f, 0.005281529854983091f, 0.005939324852079153f, 0.005377169698476791f, 0.014922181144356728f, 0.008395967073738575f, 0.005178079940378666f, 0.007585057523101568f, 0.003966381307691336f, 0.0020307828672230244f, 0.004857709165662527f, 0.005210993345826864f, 0.007899516262114048f, 0.009750034660100937f, 0.004706408362835646f, 0.010133291594684124f, 0.004169276915490627f, 0.008083284832537174f, 0.011183748953044415f, 0.005547034554183483f, 0.003646834520623088f, 0.008109643124043941f, 0.006832651793956757f, 0.007940644398331642f, 0.018626684322953224f, 0.004149153828620911f, 0.005238965153694153f, 0.002244005212560296f, 0.00616175914183259f, 0.005735913757234812f, 0.008705979213118553f, 0.01571616716682911f, 0.008512546308338642f, 0.005795422941446304f, 0.0050806812942028046f, 0.0079620610922575f, 0.005968877114355564f, 0.004010705277323723f, 0.00588963134214282f, 0.002929034875705838f, 0.004261421505361795f, 0.002787009347230196f, 0.012331672012805939f, 0.009056318551301956f, 0.007884956896305084f, 0.006958882790058851f, 0.004402851220220327f, 0.0037137973122298717f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #142 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0003812658542301506f, 0.00017774253501556814f, 9.567919914843515e-05f, 0.00011172426457051188f, 9.928851068252698e-05f, 0.00028772783116437495f, 0.00010869919788092375f, 0.00048284081276506186f, 0.0001264791062567383f, 0.00010836261935764924f, 0.00013827851216774434f, 0.00014229613589122891f, 0.00043707029544748366f, 6.207262049429119e-05f, 0.00026364601217210293f, 0.00014050138997845352f, 6.898336141603068e-05f, 0.0004806513024959713f, 0.00014371135330293328f, 0.00017664485494606197f, 0.00017100144759751856f, 0.00019525877723935992f, 0.0003182846703566611f, 0.00027368831797502935f, 4.983073813491501e-05f, 0.000254136451985687f, 0.00012726959539577365f, 0.0003988478274550289f, 0.0001949936558958143f, 0.00011614930554060265f, 0.0002153909154003486f, 0.00012020602298434824f, 0.00029310572426766157f, 0.00046925953938625753f, 0.0002906493318732828f, 0.00036642540362663567f, 0.00044301801244728267f, 7.614268542965874e-05f, 0.00013760362344328314f, 0.00023680923914071172f, 0.00018860645650420338f, 0.00012675569450948387f, 0.00017920578829944134f, 8.604760660091415e-05f, 0.00014589892816729844f, 0.00014679467130918056f, 8.974322554422542e-05f, 0.00019615488417912275f, 6.030898293829523e-05f, 0.00012956841965205967f, 0.00019744796736631542f, 2.8814760298701003e-05f, 5.101226270198822e-05f, 0.0005947729223407805f, 9.852593211689964e-05f, 0.0005529350019060075f, 0.00016656571824569255f, 6.127237429609522e-05f, 0.00024053054221440107f, 0.00011421075032558292f, 0.0001541168021503836f, 0.00012317285290919244f, 0.0001356877328362316f, 0.00013784570910502225f, 0.0003515021235216409f, 0.00013667313032783568f, 0.00018819062097463757f, 0.00018522168102208525f, 0.00010278016998199746f, 0.00020900437084492296f, 0.0001630119513720274f, 0.00034071950358338654f, 0.0001551321620354429f, 0.0001223849831148982f, 0.0002444669953547418f, 0.00010424570791656151f, 0.00011680629540933296f, 0.00010955329344142228f, 0.00025123864179477096f, 0.0001048668782459572f, 0.00034178109490312636f, 0.00012429141497705132f, 0.00012032670201733708f, 0.0006692879251204431f, 0.00016593329200986773f, 0.00019109495042357594f, 0.0001665039744693786f, 8.556291140848771e-05f, 0.00020201299048494548f, 4.064919630764052e-05f, 0.00012648891424760222f, 0.0001277028932236135f, 3.469902367214672e-05f, 0.0001107610878534615f, 3.362862116773613e-05f, 0.00022768393682781607f, 0.00015137868467718363f, 0.00014759658370167017f, 0.00012316557695157826f, 0.00016245487495325506f, 0.0003094591083936393f, 0.00018772957264445722f, 0.0004317967395763844f, 3.5606986784841865e-05f, 0.00015574556891806424f, 0.0005446269060485065f, 5.649211016134359e-05f, 0.00014950086188036948f, 0.0002989355125464499f, 9.380795381730422e-05f, 0.00012458412675186992f, 0.00017646652122493833f, 0.00028207103605382144f, 3.903749893652275e-05f, 0.0002973343071062118f, 0.00013490171113517135f, 0.00023352765128947794f, 0.0003179508785251528f, 3.606887912610546e-05f, 9.93568028206937e-05f, 0.0004427727253641933f, 0.00015714665642008185f, 0.00025938882026821375f, 0.00035780284088104963f, 0.00010477926844032481f, 0.00011913618800463155f, 0.0001572959154145792f, 0.00014548789476975799f, 0.00021168601233512163f, 0.00035579517134465277f, 0.00018612291023600847f, 0.0005680625909008086f, 3.5079006920568645e-05f, 0.0002675677533261478f, 0.00032733340049162507f, 0.00014850779552944005f, 4.231457205605693e-05f, 0.00014639705477748066f, 9.223569941241294e-05f, 0.0001036453468259424f, 0.00010744726023403928f, 0.0001641356066102162f, 8.068275201367214e-05f, 8.076872472884133e-05f, 0.0003387917822692543f, 0.00012427128967829049f, 0.0001397488231305033f, 0.00012652164150495082f, 0.0003511101531330496f, 0.00019755217363126576f, 0.00012183717626612633f, 0.00017847194976639003f, 9.332662011729553e-05f, 4.778312722919509e-05f, 0.00011429904407123104f, 0.0001226116146426648f, 0.00018587097292765975f, 0.00022941258794162422f, 0.00011073901987401769f, 0.00023843039525672793f, 9.810063784243539e-05f, 0.0001901949435705319f, 0.00026314702699892223f, 0.00013051845598965883f, 8.580787107348442e-05f, 0.00019081513164564967f, 0.00016076827887445688f, 0.00018683868984226137f, 0.0004382749320939183f, 9.762714762473479e-05f, 0.00012326976866461337f, 5.280012192088179e-05f, 0.00014498256496153772f, 0.0001349626836599782f, 0.00020484656852204353f, 0.0003697921638377011f, 0.0002002952096518129f, 0.00013636289804708213f, 0.00011954544606851414f, 0.00018734262266661972f, 0.00014044417184777558f, 9.436954132979736e-05f, 0.0001385795621899888f, 6.891846715006977e-05f, 0.000100268742244225f, 6.557669257745147e-05f, 0.0002901569823734462f, 0.0002130898501491174f, 0.00018552840629126877f, 0.00016373842663597316f, 0.00010359650332247838f, 8.738346514292061e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #143 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0101264463737607f, 0.00918611977249384f, 0.010365044698119164f, 0.005089129786938429f, 0.011219711042940617f, 0.0069084553979337215f, 0.004548918455839157f, 0.00854492001235485f, 0.006949711125344038f, 0.018635746091604233f, 0.00885335449129343f, 0.009021056815981865f, 0.009762370958924294f, 0.005212767980992794f, 0.006458087358623743f, 0.006344901397824287f, 0.014575164765119553f, 0.015147115103900433f, 0.007065828889608383f, 0.01379906851798296f, 0.030049363151192665f, 0.014199403114616871f, 0.027553731575608253f, 0.005239518359303474f, 0.03390667587518692f, 0.009121792390942574f, 0.02397788316011429f, 0.018095890060067177f, 0.00576006667688489f, 0.0073937661945819855f, 0.004664139822125435f, 0.00832268875092268f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #144 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_50_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 32,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00023826933465898037f, 0.00021614400611724705f, 0.0002438834053464234f, 0.00011974423250649124f, 0.0002639931917656213f, 0.00016255189257208258f, 0.00010703337466111407f, 0.000201056944206357f, 0.00016352262173313648f, 0.00043848814675584435f, 0.00020831423171330243f, 0.00021226015815045685f, 0.00022970285499468446f, 0.00012265336408745497f, 0.00015195499872788787f, 0.00014929179451428354f, 0.00034294507349841297f, 0.0003564027138054371f, 0.00016625480202492326f, 0.0003246839623898268f, 0.0007070438587106764f, 0.00033410362084396183f, 0.0006483230972662568f, 0.00012328279262874275f, 0.0007978041539900005f, 0.00021463041775859892f, 0.0005641854950226843f, 0.0004257856635376811f, 0.00013553097960539162f, 0.00017397096962668002f, 0.00010974446922773495f, 0.00019582797540351748f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #145 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0007653206121176481f, 0.0006299425149336457f, 0.0005949361948296428f, 0.00047267350601032376f, 0.0006513496628031135f, 0.001058668247424066f, 0.001816323958337307f, 0.0010857894085347652f, 0.001072707469575107f, 0.0011234898120164871f, 0.000573095167055726f, 0.0006114342832006514f, 0.0005448478041216731f, 0.0007142863469198346f, 0.0013426911318674684f, 0.0006049048388376832f, 0.0008690024842508137f, 0.0002919101098086685f, 0.0009353847126476467f, 0.00098491704557091f, 0.0011313777649775147f, 0.000485420721815899f, 0.0006553393322974443f, 0.0006643316010013223f, 0.0007078956696204841f, 0.0007084242533892393f, 0.0007156254723668098f, 0.0008788052364252508f, 0.0006407378823496401f, 0.0005908616585657f, 0.0008390236180275679f, 0.0008337265462614596f, 0.0007419582107104361f, 0.0007365032215602696f, 0.0006312023033387959f, 0.0009218861232511699f, 0.0012705380795523524f, 0.0006730147288180888f, 0.0005956536042504013f, 0.0008489458123221993f, 0.0007397206500172615f, 0.0006131107802502811f, 0.001136388280428946f, 0.0008339046617038548f, 0.0007653885404579341f, 0.0007062885561026633f, 0.0009955506538972259f, 0.0007945940596982837f, 0.0008887035073712468f, 0.0006127237575128675f, 0.0006986695225350559f, 0.0006550028920173645f, 0.0006830822676420212f, 0.0010010438272729516f, 0.0011202315799891949f, 0.0007012280984781682f, 0.0008057239465415478f, 0.000580072752200067f, 0.0007062641670927405f, 0.0006601916393265128f, 0.0010650847107172012f, 0.0005910960026085377f, 0.0007692505605518818f, 0.0004490108403842896f, 0.0010924322996288538f, 0.0008853589533828199f, 0.0008410512236878276f, 0.0009643537341617048f, 0.0007739485590718687f, 0.0009991845581680536f, 0.0006546428194269538f, 0.0007597490912303329f, 0.0006493020919151604f, 0.0011633310932666063f, 0.0007234367658384144f, 0.00120117561891675f, 0.0009501109598204494f, 0.0008759661577641964f, 0.00012707778660114855f, 0.00046699753147549927f, 0.000810597266536206f, 0.0007498445920646191f, 0.001393856480717659f, 0.0007382231415249407f, 0.001074098632670939f, 0.0009630116983316839f, 0.0006063252221792936f, 0.0007428828394040465f, 0.0014866264536976814f, 0.0005553147057071328f, 0.00123645702842623f, 0.0008591893711127341f, 0.0010322353336960077f, 0.0008031727047637105f, 0.0011823801323771477f, 0.0010679408442229033f, 0.0012993600685149431f, 0.0004921942600049078f, 0.0009617207106202841f, 0.0005668814992532134f, 0.0008156906696967781f, 0.0007449545082636178f, 0.001065681572072208f, 0.000648419139906764f, 0.0006072766846045852f, 0.0008604033500887454f, 0.0006203708471730351f, 0.0007727888878434896f, 0.000455924920970574f, 0.0010554728796705604f, 0.0006336540682241321f, 0.0008895943174138665f, 0.0008807274280115962f, 0.0005733222351409495f, 0.0008103718282654881f, 0.0011205404298380017f, 0.0009419800480827689f, 0.0007543040555901825f, 0.000549929216504097f, 0.001017384696751833f, 0.0009328936575911939f, 0.0004703828599303961f, 0.001226139604113996f, 0.0008944662404246628f, 0.0010733610251918435f, 0.0009951255051419139f, 0.0009900034638121724f, 0.0004660437989514321f, 0.0005946456803940237f, 0.00018142240878660232f, 0.0005543497973121703f, 0.0008888635202310979f, 0.001475580153055489f, 0.0005209995433688164f, 0.0010578507790341973f, 0.0005582949379459023f, 0.0006605645176023245f, 0.0006793899228796363f, 0.0006175233866088092f, 0.0008597653941251338f, 0.0009327676962129772f, 0.0007032018038444221f, 0.0004550608282443136f, 0.0006568426615558565f, 0.0012350326869636774f, 0.0015564346686005592f, 0.0006890519871376455f, 0.0006754823843948543f, 0.0006636612233705819f, 0.0006759474636055529f, 0.0007022958598099649f, 0.0006855291430838406f, 0.000758960610255599f, 0.0007065821555443108f, 0.0005751291173510253f, 0.0007913770969025791f, 0.0007944458047859371f, 0.0009448741329833865f, 0.0015702878590673208f, 0.0005577494157478213f, 0.0007833252311684191f, 0.0005640321760438383f, 0.00079737463966012f, 0.0010043868096545339f, 0.0004153692570980638f, 0.000635752861853689f, 0.0005910141044296324f, 0.0006366406450979412f, 0.0008556044194847345f, 0.0007082325173541903f, 0.0008418226498179138f, 0.0006507334182970226f, 0.0006876332336105406f, 0.0008901226683519781f, 0.0006700005033053458f, 0.0009134577121585608f, 0.0011370222782716155f, 0.0008243467891588807f, 0.00081832759315148f, 0.0009958473965525627f, 0.0013876969460397959f, 0.000685600854922086f, 0.0006086709327064455f, 0.0005869036540389061f, 0.0007114008185453713f, 0.0009374994551762938f, 0.0007523528183810413f, 0.0005065113073214889f, 0.00046758976532146335f, 0.0012141508050262928f, 0.0007564661209471524f, 0.00018892358639277518f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #146 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001561599492561072f, 0.0001285367034142837f, 0.00012139383761677891f, 9.644672536524013e-05f, 0.00013290472270455211f, 0.00021601610933430493f, 0.00037061204784549773f, 0.00022155004262458533f, 0.00021888074115850031f, 0.0002292426215717569f, 0.00011693727719830349f, 0.00012476019037421793f, 0.00011117354006273672f, 0.0001457466569263488f, 0.0002739695773925632f, 0.0001234278897754848f, 0.00017731572734192014f, 5.956283712293953e-05f, 0.0001908606936922297f, 0.0002009675226872787f, 0.0002308521216036752f, 9.904773469315842e-05f, 0.00013371880049817264f, 0.00013555362238548696f, 0.00014444265980273485f, 0.0001445505185984075f, 0.00014601989823859185f, 0.00017931593174580485f, 0.0001307394413743168f, 0.00012056244304403663f, 0.00017119868425652385f, 0.0001701178407529369f, 0.00015139296010602266f, 0.0001502798986621201f, 0.0001287937629967928f, 0.00018810637993738055f, 0.0002592471137177199f, 0.00013732537627220154f, 0.00012154021533206105f, 0.00017322326311841607f, 0.00015093639376573265f, 0.00012510227679740638f, 0.00023187449551187456f, 0.00017015419143717736f, 0.00015617380267940462f, 0.00014411474694497883f, 0.0002031372714554891f, 0.0001621330447960645f, 0.00018133562116418034f, 0.00012502330355346203f, 0.0001425601076334715f, 0.0001336501445621252f, 0.00013937961193732917f, 0.00020425811817403883f, 0.00022857780277263373f, 0.0001430821866961196f, 0.00016440404579043388f, 0.00011836102203233168f, 0.00014410977018997073f, 0.00013470888370648026f, 0.0002173253451474011f, 0.00012061026063747704f, 0.00015696183254476637f, 9.161847265204415e-05f, 0.0002229054953204468f, 0.00018065317999571562f, 0.00017161240975838155f, 0.0001967716816579923f, 0.00015792043996043503f, 0.0002038787497440353f, 0.0001335766864940524f, 0.0001550231099827215f, 0.0001324869372183457f, 0.00023737204901408404f, 0.00014761375496163964f, 0.00024509403738193214f, 0.00019386551866773516f, 0.0001787366345524788f, 2.5929602998076007e-05f, 9.528857481200248e-05f, 0.00016539842181373388f, 0.00015300213999580592f, 0.00028440961614251137f, 0.0001506308326497674f, 0.00021916459081694484f, 0.0001964978437172249f, 0.00012371770571917295f, 0.00015158162568695843f, 0.00030333889299072325f, 0.0001133092591771856f, 0.00025229304446838796f, 0.00017531341291032732f, 0.00021062258747406304f, 0.00016388348012696952f, 0.0002412589092273265f, 0.00021790813480038196f, 0.00026512809563428164f, 0.00010042983922176063f, 0.000196234424947761f, 0.00011566941248020157f, 0.0001664377050474286f, 0.00015200434427242726f, 0.0002174471301259473f, 0.0001323067699559033f, 0.00012391185737214983f, 0.00017556111561134458f, 0.0001265836472157389f, 0.00015768381126690656f, 9.302925900556147e-05f, 0.00021536409622058272f, 0.0001292940287385136f, 0.00018151738913729787f, 0.00017970814951695502f, 0.00011698361049639061f, 0.000165352423209697f, 0.00022864081256557256f, 0.00019220644026063383f, 0.0001539120712550357f, 0.00011221037857467309f, 0.00020759239851031452f, 0.00019035240984521806f, 9.597933240002021e-05f, 0.00025018781889230013f, 0.00018251148867420852f, 0.00021901409490965307f, 0.00020305051293689758f, 0.00020200539438519627f, 9.509396477369592e-05f, 0.00012133455311413854f, 3.701835885294713e-05f, 0.0001131123790401034f, 0.0001813682756619528f, 0.0003010849468410015f, 0.00010630742326611653f, 0.00021584930073004216f, 0.0001139173618867062f, 0.0001347849756712094f, 0.0001386262010782957f, 0.00012600264744833112f, 0.00017543094872962683f, 0.00019032671116292477f, 0.00014348491095006466f, 9.285294800065458e-05f, 0.00013402554031927139f, 0.000252002413617447f, 0.0003175829187966883f, 0.00014059770910535008f, 0.00013782888709101826f, 0.00013541684893425554f, 0.00013792379468213767f, 0.00014330005797091872f, 0.00013987888814881444f, 0.00015486222400795668f, 0.0001441746426280588f, 0.00011735229782061651f, 0.00016147663700394332f, 0.00016210280591621995f, 0.00019279697153251618f, 0.0003204095992259681f, 0.00011380605428712443f, 0.00015983369667083025f, 0.00011508801981108263f, 0.0001627004094189033f, 0.00020494023920036852f, 8.475407230434939e-05f, 0.0001297222770517692f, 0.00012059354776283726f, 0.0001299034192925319f, 0.00017458191723562777f, 0.00014451140305027366f, 0.0001717698178254068f, 0.0001327789796050638f, 0.00014030821330379695f, 0.00018162520427722484f, 0.0001367103395750746f, 0.0001863866054918617f, 0.00023200386203825474f, 0.00016820394375827163f, 0.00016697576211299747f, 0.0002031978074228391f, 0.0002831527963280678f, 0.00013989351282361895f, 0.0001241963473148644f, 0.00011975483357673511f, 0.00014515787188429385f, 0.00019129220163449645f, 0.00015351393085438758f, 0.00010335116530768573f, 9.540941391605884e-05f, 0.0002477415546309203f, 0.00015435322711709887f, 3.854893657262437e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #147 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.004314908757805824f, 0.002649448113515973f, 0.003374994033947587f, 0.0045773619785904884f, 0.004104216117411852f, 0.0035769487731158733f, 0.0009729044395498931f, 0.0039015973452478647f, 0.006177680566906929f, 0.004992414731532335f, 0.004664007108658552f, 0.004513063468039036f, 0.0019481314811855555f, 0.0025273326318711042f, 0.0032668483909219503f, 0.003509611589834094f, 0.0015259088249877095f, 0.011944684199988842f, 0.004345881752669811f, 0.0039019035175442696f, 0.0014141497667878866f, 0.002185175893828273f, 0.006100804544985294f, 0.004934641066938639f, 0.003092352068051696f, 0.005519087892025709f, 0.0034143917728215456f, 0.0020023109391331673f, 0.003921364434063435f, 0.0017979335971176624f, 0.0014870415907353163f, 0.0014639911241829395f, 0.002002543769776821f, 0.0016757764387875795f, 0.004346621222794056f, 0.0035552047193050385f, 0.002765296259894967f, 0.003043955424800515f, 0.0035127003211528063f, 0.003197475802153349f, 0.0035353570710867643f, 0.002480089198797941f, 0.0038717009592801332f, 0.002133316360414028f, 0.004076441749930382f, 0.002389742759987712f, 0.00414830818772316f, 0.0038531264290213585f, 0.004322872031480074f, 0.004775397013872862f, 0.00325251673348248f, 0.0021900911815464497f, 0.003465766552835703f, 0.0023811061400920153f, 0.005391736049205065f, 0.0038462579250335693f, 0.004639057908207178f, 0.00477550458163023f, 0.0031398527789860964f, 0.00628485344350338f, 0.003518199548125267f, 0.002252047648653388f, 0.0030118036083877087f, 0.0037934945430606604f, 0.003603368066251278f, 0.002489405684173107f, 0.003620502073317766f, 0.005420824512839317f, 0.0014605995966121554f, 0.0036074756644666195f, 0.003920667339116335f, 0.004424818325787783f, 0.003976491279900074f, 0.0011296524899080396f, 0.003467186586931348f, 0.004339213483035564f, 0.005244983360171318f, 0.003205004846677184f, 0.00525083439424634f, 0.008910317905247211f, 0.005257208365947008f, 0.004057386424392462f, 0.0023099679965525866f, 0.0016007745871320367f, 0.0023616363760083914f, 0.0023178798146545887f, 0.0033954186365008354f, 0.0017828105483204126f, 0.004012363031506538f, 0.006461850833147764f, 0.0024492342490702868f, 0.0033052561338990927f, 0.004411769565194845f, 0.004663617350161076f, 0.0030465128365904093f, 0.00238631060346961f, 0.001221217098645866f, 0.0054838345386087894f, 0.00553191639482975f, 0.0031561327632516623f, 0.0037597501650452614f, 0.0040629529394209385f, 0.0024915479589253664f, 0.0022125407122075558f, 0.004302074667066336f, 0.001806753221899271f, 0.003331280080601573f, 0.002616901881992817f, 0.004185068421065807f, 0.0036220091860741377f, 0.003432272933423519f, 0.002470677252858877f, 0.0027315232437103987f, 0.003053679596632719f, 0.004891824442893267f, 0.004931086208671331f, 0.0017051419708877802f, 0.004654018674045801f, 0.00760864419862628f, 0.003991309553384781f, 0.004837697371840477f, 0.005580045748502016f, 0.0018286440754309297f, 0.0036427276208996773f, 0.0016635647043585777f, 0.0016784906620159745f, 0.005600806791335344f, 0.005641627125442028f, 0.002422882942482829f, 0.011194935068488121f, 0.005050571169704199f, 0.0039756642654538155f, 0.0014278707094490528f, 0.002159907715395093f, 0.00431427638977766f, 0.004758033901453018f, 0.004211979452520609f, 0.003245822386816144f, 0.002405528211966157f, 0.004350580740720034f, 0.004991121590137482f, 0.006606617942452431f, 0.009653797373175621f, 0.0022174594923853874f, 0.00487481290474534f, 0.0019027068046852946f, 0.004109630361199379f, 0.002591331023722887f, 0.004313227254897356f, 0.0037382515147328377f, 0.0024465767201036215f, 0.00378734664991498f, 0.005164913833141327f, 0.0020317048765718937f, 0.006337813101708889f, 0.0023614673409610987f, 0.0033381888642907143f, 0.003162107430398464f, 0.00134503364097327f, 0.004035306628793478f, 0.0036809330340474844f, 0.005619870498776436f, 0.005405685398727655f, 0.002648942405357957f, 0.0038413063157349825f, 0.005155226681381464f, 0.002263101749122143f, 0.004004153423011303f, 0.002528493758291006f, 0.0031233401969075203f, 0.0038173419889062643f, 0.002338931430131197f, 0.003220207756385207f, 0.003001332748681307f, 0.005252020433545113f, 0.0038994373753666878f, 0.0028445625212043524f, 0.00403415085747838f, 0.004373136442154646f, 0.0031920920591801405f, 0.001675499719567597f, 0.003159981919452548f, 0.0034963779617100954f, 0.0031821441370993853f, 0.0019517902983352542f, 0.001863130833953619f, 0.002626303816214204f, 0.003839067881926894f, 0.004374506883323193f, 0.0037297706585377455f, 0.0032025587279349566f, 0.008879171684384346f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #148 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 192,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001015272646327503f, 6.233995372895151e-05f, 7.941162766655907e-05f, 0.0001077026390703395f, 9.656979091232643e-05f, 8.416350465267897e-05f, 2.2891868866281584e-05f, 9.180229244520888e-05f, 0.0001453571894671768f, 0.00011746858217520639f, 0.00010974134784191847f, 0.0001061897273757495f, 4.58383874502033e-05f, 5.946665260125883e-05f, 7.686702156206593e-05f, 8.2579099398572e-05f, 3.5903736716136336e-05f, 0.00028105141245760024f, 0.00010225604637525976f, 9.180949564324692e-05f, 3.327411104692146e-05f, 5.141590372659266e-05f, 0.0001435483427485451f, 0.00011610920046223328f, 7.276122778421268e-05f, 0.00012986089859623462f, 8.033862832235172e-05f, 4.7113200707826763e-05f, 9.226740075973794e-05f, 4.230432023177855e-05f, 3.498921432765201e-05f, 3.4446849895175546e-05f, 4.7118679503910244e-05f, 3.943003321182914e-05f, 0.00010227344318991527f, 8.365187386516482e-05f, 6.506579666165635e-05f, 7.162248220993206e-05f, 8.265177166322246e-05f, 7.52347259549424e-05f, 8.318487380165607e-05f, 5.835504271090031e-05f, 9.109884558711201e-05f, 5.019567834096961e-05f, 9.59162789513357e-05f, 5.6229240726679564e-05f, 9.760725515661761e-05f, 9.066180064110085e-05f, 0.00010171463509323075f, 0.00011236228601774201f, 7.652981003047898e-05f, 5.153155871084891e-05f, 8.154744864441454e-05f, 5.602602686849423e-05f, 0.00012686438276432455f, 9.050018707057461e-05f, 0.00010915430902969092f, 0.00011236481805099174f, 7.38788876333274e-05f, 0.00014787890540901572f, 8.27811672934331e-05f, 5.298935866449028e-05f, 7.086597179295495e-05f, 8.925869769882411e-05f, 8.478513336740434e-05f, 5.8574252761900425e-05f, 8.518828690284863e-05f, 0.00012754881754517555f, 3.436705083004199e-05f, 8.488177991239354e-05f, 9.225100075127557e-05f, 0.00010411337279947475f, 9.356450027553365e-05f, 2.6580059056868777e-05f, 8.158085984177887e-05f, 0.00010209914034930989f, 0.0001234113733517006f, 7.541188097093254e-05f, 0.00012354904902167618f, 0.00020965453586541116f, 0.00012369902106001973f, 9.546791989123449e-05f, 5.435218918137252e-05f, 3.766528607229702e-05f, 5.5567914387211204e-05f, 5.453834819491021e-05f, 7.989220466697589e-05f, 4.19484858866781e-05f, 9.440854046260938e-05f, 0.00015204354713205248f, 5.762904402217828e-05f, 7.777073187753558e-05f, 0.00010380634194007143f, 0.00010973217285936698f, 7.168265437940136e-05f, 5.614848487311974e-05f, 2.873452103813179e-05f, 0.00012903141032438725f, 0.0001301627344219014f, 7.426195224979892e-05f, 8.846470882417634e-05f, 9.55988944042474e-05f, 5.862466059625149e-05f, 5.205978231970221e-05f, 0.00010122529056388885f, 4.251184145687148e-05f, 7.838306191843003e-05f, 6.157416646601632e-05f, 9.84721991699189e-05f, 8.522374992026016e-05f, 8.07593678473495e-05f, 5.8133584388997406e-05f, 6.427113839890808e-05f, 7.185128924902529e-05f, 0.00011510175681905821f, 0.00011602556332945824f, 4.0120987250702456e-05f, 0.00010950632713502273f, 0.00017902693070936948f, 9.391316416440532e-05f, 0.00011382817319827154f, 0.00013129519356880337f, 4.302692104829475e-05f, 8.571123908041045e-05f, 3.914269836968742e-05f, 3.9493897929787636e-05f, 0.00013178368681110442f, 0.00013274417142383754f, 5.7009012380149215e-05f, 0.00026341024204157293f, 0.00011883697152370587f, 9.354504436487332e-05f, 3.359695983817801e-05f, 5.082135976408608e-05f, 0.0001015123852994293f, 0.00011195374099770561f, 9.910540393320844e-05f, 7.637229282408953e-05f, 5.66006638109684e-05f, 0.00010236660455120727f, 0.00011743815412046388f, 0.00015544983034487814f, 0.0002271481789648533f, 5.217551733949222e-05f, 0.00011470148456282914f, 4.47695711045526e-05f, 9.669718565419316e-05f, 6.097249570302665e-05f, 0.00010148770525120199f, 8.795886242296547e-05f, 5.756651080446318e-05f, 8.911403710953891e-05f, 0.00012152738781878725f, 4.7804820496821776e-05f, 0.00014912501501385123f, 5.556393807637505e-05f, 7.854562136344612e-05f, 7.440253102686256e-05f, 3.16478508466389e-05f, 9.494839468970895e-05f, 8.661019091960043e-05f, 0.00013223224959801883f, 0.00012719260121230036f, 6.232805753825232e-05f, 9.038367716129869e-05f, 0.00012129945389460772f, 5.32494523213245e-05f, 9.421537833986804e-05f, 5.949397018412128e-05f, 7.349035877268761e-05f, 8.981981227407232e-05f, 5.503368083736859e-05f, 7.576959615107626e-05f, 7.061959331622347e-05f, 0.0001235769595950842f, 9.17514698812738e-05f, 6.693088653264567e-05f, 9.492119716014713e-05f, 0.00010289732745150104f, 7.510805153287947e-05f, 3.9423524867743254e-05f, 7.435251609422266e-05f, 8.22677175165154e-05f, 7.487398397643119e-05f, 4.5924480218673125e-05f, 4.383837222121656e-05f, 6.179538468131796e-05f, 9.033101378008723e-05f, 0.0001029295744956471f, 8.775931200943887e-05f, 7.535432087024674e-05f, 0.00020892168686259538f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #149 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.009533326141536236f, 0.008584550581872463f, 0.008388249203562737f, 0.010866490192711353f, 0.010092702694237232f, 0.008638420142233372f, 0.012402785941958427f, 0.008882776834070683f, 0.009763581678271294f, 0.009203629568219185f, 0.009199123829603195f, 0.007536252029240131f, 0.010540405288338661f, 0.007845109328627586f, 0.012860418297350407f, 0.010717393830418587f, 0.010358933359384537f, 0.011385289952158928f, 0.007690103258937597f, 0.009190372191369534f, 0.0074843354523181915f, 0.008188856765627861f, 0.008919746614992619f, 0.011640509590506554f, 0.00744195282459259f, 0.008141133934259415f, 0.011725598946213722f, 0.008650464937090874f, 0.0076873344369232655f, 0.008572283200919628f, 0.008720044046640396f, 0.006104491651058197f, 0.010987033136188984f, 0.008815215900540352f, 0.008693328127264977f, 0.009604510851204395f, 0.009939659386873245f, 0.007160607259720564f, 0.008906310424208641f, 0.007439324166625738f, 0.008104548789560795f, 0.006380293518304825f, 0.01788734272122383f, 0.008142066188156605f, 0.008164488710463047f, 0.007110198028385639f, 0.008561200462281704f, 0.01051352359354496f, 0.009092814289033413f, 0.007715991698205471f, 0.010086922906339169f, 0.007952072657644749f, 0.009709075093269348f, 0.008111713454127312f, 0.009539704769849777f, 0.011278841644525528f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #150 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_55_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00022431356774177402f, 0.00020198943093419075f, 0.00019737058028113097f, 0.0002556821273174137f, 0.00023747536761220545f, 0.0002032569464063272f, 0.0002918302488978952f, 0.00020900652452837676f, 0.00022973133309278637f, 0.00021655599994119257f, 0.0002164499746868387f, 0.00017732358537614346f, 0.0002480095427017659f, 0.00018459081184118986f, 0.00030259808409027755f, 0.00025217398069798946f, 0.0002437396178720519f, 0.00026788917602971196f, 0.00018094360711984336f, 0.00021624405053444207f, 0.00017610201030038297f, 0.00019267898460384458f, 0.00020987639436498284f, 0.00027389434399083257f, 0.00017510478210169822f, 0.00019155610061716288f, 0.0002758964546956122f, 0.00020354035950731486f, 0.00018087845819536597f, 0.00020170077914372087f, 0.00020517750817816705f, 0.00014363510126713663f, 0.00025851844111457467f, 0.0002074168442049995f, 0.00020454889454413205f, 0.00022598849318455905f, 0.00023387433611787856f, 0.00016848488303367049f, 0.00020956025400664657f, 0.00017504292191006243f, 0.00019069526751991361f, 0.0001501245569670573f, 0.00042087867041118443f, 0.00019157803035341203f, 0.0001921056245919317f, 0.00016729878552723676f, 0.00020144000882282853f, 0.0002473770291544497f, 0.00021394857321865857f, 0.0001815527502913028f, 0.00023733936541248113f, 0.00018710759468376637f, 0.00022844882914796472f, 0.00019086385145783424f, 0.00022446364164352417f, 0.00026538450038060546f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #151 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00042928577749989927f, 0.0005573263624683022f, 0.0004090734291821718f, 0.0007260119309648871f, 0.0005148794734850526f, 0.0005679684691131115f, 0.0005150361103005707f, 0.0009229715797118843f, 0.0007861324120312929f, 0.0004690679779741913f, 0.0004847782838623971f, 0.0006044183392077684f, 0.0004163326520938426f, 0.00040144348167814314f, 0.0005693355924449861f, 0.000824830261990428f, 0.0007785637862980366f, 0.0016101333312690258f, 0.0005788090056739748f, 0.000602437648922205f, 0.000967905973084271f, 0.0005683291819877923f, 0.0006322715780697763f, 0.0006145351799204946f, 0.0005178914871066809f, 0.0007041294011287391f, 0.0004777975264005363f, 0.0009330672910436988f, 0.0009362092241644859f, 0.0005970708443783224f, 0.0007456050952896476f, 0.0012741971295326948f, 0.0004618161474354565f, 0.0008420507656410336f, 0.0014397981576621532f, 0.0014380370266735554f, 0.0006781695410609245f, 0.0013118732022121549f, 0.000704277481418103f, 0.0004688726912718266f, 0.000779030320700258f, 0.001924334210343659f, 0.0007867860840633512f, 0.0006610905984416604f, 0.0008392397430725396f, 0.00047642859863117337f, 0.0008134982781484723f, 0.0009492703247815371f, 0.0009797585662454367f, 0.0006502544274553657f, 0.000961769837886095f, 0.0005364881944842637f, 0.0005042045377194881f, 0.0005224474589340389f, 0.0009910512017086148f, 0.0010730904759839177f, 0.0007974145119078457f, 0.0013076630420982838f, 0.0014045099960640073f, 0.0009525254718028009f, 0.0011431716848164797f, 0.003588717197999358f, 0.0009396056411787868f, 0.0009595952578820288f, 0.0005786056281067431f, 0.0010048910044133663f, 0.0006285416893661022f, 0.001123863155953586f, 0.0007415009313262999f, 0.0011331979185342789f, 0.0005774335004389286f, 0.001570980530232191f, 0.000394271599361673f, 0.0004936536424793303f, 0.0010369508527219296f, 0.000987194711342454f, 0.001059159985743463f, 0.00035875928006134927f, 0.0009492933750152588f, 0.0010158660588786006f, 0.0005084961885586381f, 0.0005768781411461532f, 0.0013241821434348822f, 0.0008347340044565499f, 0.0006211516447365284f, 0.0010432974668219686f, 0.0004932357696816325f, 0.0009661538060754538f, 0.001089937868528068f, 0.0015245556132867932f, 0.0006366211455315351f, 0.000887481844983995f, 0.0008756717434152961f, 0.000677277974318713f, 0.0008258528541773558f, 0.000477377325296402f, 0.0006047216011211276f, 0.00038295378908514977f, 0.0006154270377010107f, 0.00042180027230642736f, 0.0008751673740334809f, 0.0009809371549636126f, 0.0006114071002230048f, 0.0006457034032791853f, 0.0005594762042164803f, 0.0011376721085980535f, 0.0006024775211699307f, 0.0005689411773346364f, 0.0008815153269097209f, 0.0007793987169861794f, 0.0008786312537267804f, 0.0003590694395825267f, 0.0009322756086476147f, 0.0006261438247747719f, 0.0011871234746649861f, 0.0012701029190793633f, 0.000980932847596705f, 0.0006507301004603505f, 0.0007793800323270261f, 0.0012517876457422972f, 0.0011989576742053032f, 0.0005910518229939044f, 0.0006023484747856855f, 0.0010605129646137357f, 0.0011509854812175035f, 0.00047690622159279883f, 0.0009177171159535646f, 0.0006379784317687154f, 0.0007719465647824109f, 0.00097542634466663f, 0.0010574677726253867f, 0.0006045941263437271f, 0.0019562530796974897f, 0.001086596050299704f, 0.0008885955903679132f, 0.0010827850783243775f, 0.0011377132032066584f, 0.0005367817939259112f, 0.0013084581587463617f, 0.0006138592725619674f, 0.0012123218039050698f, 0.0006685921689495444f, 0.001143662491813302f, 0.0007773596444167197f, 0.00042236311128363013f, 0.001072858227416873f, 0.00043181743239983916f, 0.0008299274486489594f, 0.0004679902922362089f, 0.0006561424816027284f, 0.0007713463855907321f, 0.0009897274430841208f, 0.0009702134993858635f, 0.00027215946465730667f, 0.0011848628055304289f, 0.0014811479486525059f, 0.0006345989531837404f, 0.0010355828562751412f, 0.0008458707015961409f, 0.001581934280693531f, 0.0005138227134011686f, 0.0004411432601045817f, 0.0005788367707282305f, 0.0009980074828490615f, 0.0007114825421012938f, 0.00079846300650388f, 0.001022895099595189f, 0.0005114851519465446f, 0.0009039583965204656f, 0.0011467484291642904f, 0.0017324271611869335f, 0.0005634224507957697f, 0.0005623736069537699f, 0.0009739467641338706f, 0.0002510290942154825f, 0.0007609115564264357f, 0.0015174215659499168f, 0.0006317541119642556f, 0.0009206317481584847f, 0.0005621887394227087f, 0.0011028610169887543f, 0.0009676131303422153f, 0.0007311873487196863f, 0.0005404276889748871f, 0.0011439656373113394f, 0.0008048087474890053f, 0.0005928612663410604f, 0.00044965880806557834f, 0.0009069514344446361f, 0.0008229275117628276f, 0.0011212972458451986f, 0.00032042645034380257f, 0.001264982856810093f, 0.0004843043570872396f, 0.0003642999508883804f, 0.002302232664078474f, 0.0006788295577280223f, 0.0005031576147302985f, 0.0011653297115117311f, 0.0007154963095672429f, 0.001283424673601985f, 0.00050448311958462f, 0.0011317169992253184f, 0.0011204552138224244f, 0.0004353293334133923f, 0.0013179552042856812f, 0.0005034518544562161f, 0.00037929427344352007f, 0.003340802388265729f, 0.0011555296368896961f, 0.000933205068577081f, 0.001375598250888288f, 0.0012258555507287383f, 0.0006133101414889097f, 0.0009291812893934548f, 0.000768377271015197f, 0.000663168728351593f, 0.0005510458140634f, 0.0009852818911895156f, 0.0009334433707408607f, 0.0019347126362845302f, 0.0006776598165743053f, 0.00037151234573684633f, 0.0006033910904079676f, 0.0003061455499846488f, 0.0011469109449535608f, 0.0011456392239779234f, 0.0009130337275564671f, 0.0002562442678026855f, 0.0008723823120817542f, 0.0010401204926893115f, 0.0005696446751244366f, 0.00013729449710808694f, 0.0009562266059219837f, 7.441913751904394e-09f, 0.0003465105255600065f, 0.0006356291123665869f, 0.0004644568543881178f, 0.0011109376791864634f, 0.0008332154247909784f, 0.0008288684766739607f, 0.00037669253651984036f, 0.0008199381409212947f, 0.0005774049204774201f, 0.0009018635028041899f, 0.0004603192210197449f, 0.0008788726408965886f, 0.0012339743552729487f, 0.0015696792397648096f, 0.0008403704850934446f, 0.0011186953634023666f, 0.0006399783305823803f, 0.0007694389787502587f, 0.0009070888627320528f, 0.0007168992888182402f, 0.0008703829371370375f, 0.0008026679279282689f, 0.0006494582048617303f, 0.001187171321362257f, 0.0006230896688066423f, 0.0009940371382981539f, 0.0005582367302849889f, 0.0004947673878632486f, 0.0003460619191173464f, 0.0009544598287902772f, 0.0005282929632812738f, 0.0008626411436125636f, 0.0004283000307623297f, 0.0009380962583236396f, 0.0012376990634948015f, 0.00038440630305558443f, 0.0005566786276176572f, 0.0005957828834652901f, 0.00039023635326884687f, 0.0007911575958132744f, 0.0009794948855414987f, 0.0005728279356844723f, 0.0013190656900405884f, 0.0008897414663806558f, 0.0005299331387504935f, 0.0008591029909439385f, 0.0008673944394104183f, 0.0005265825311653316f, 0.0007710435893386602f, 0.00046137289609760046f, 0.0007181822438724339f, 0.00040795208769850433f, 0.0012254122411832213f, 0.000605476088821888f, 0.0010225636651739478f, 0.00042088847840204835f, 0.001150153111666441f, 0.00046918896259739995f, 0.0007569235749542713f, 0.000803229515440762f, 0.0005900604883208871f, 0.000632172916084528f, 0.0008349006529897451f, 0.0007107594865374267f, 0.0008300148183479905f, 0.0009458669810555875f, 0.0014344279188662767f, 0.0009254714823327959f, 0.0008149297791533172f, 0.0008740840130485594f, 0.0005085791344754398f, 0.000610063667409122f, 0.0006398322293534875f, 0.0006539832684211433f, 0.00045568248606286943f, 0.0005118445260450244f, 0.0009463104070164263f, 0.0008628928917460144f, 0.0005833353498019278f, 0.00044552728650160134f, 0.0007002161000855267f, 0.0012015693355351686f, 0.0009570936672389507f, 0.0012327816803008318f, 0.0011633527465164661f, 0.000509640434756875f, 0.0009236938203684986f, 0.0012286078417673707f, 0.0011581461876630783f, 0.0012017444241791964f, 0.0013574251206591725f, 0.00032553254277445376f, 0.0006464249454438686f, 0.0014054671628400683f, 0.0008068879833444953f, 0.0011563068255782127f, 0.0007944353856146336f, 0.0013724536402150989f, 0.0010799398878589272f, 0.0012260806979611516f, 0.00012736738426610827f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.693656567018479e-05f, 7.39187016733922e-05f, 5.425578274298459e-05f, 9.629162377677858e-05f, 6.82889367453754e-05f, 7.533017924288288e-05f, 6.830970960436389e-05f, 0.00012241456715855747f, 0.00010426546214148402f, 6.221291550900787e-05f, 6.429658969864249e-05f, 8.016455831239e-05f, 5.521858111023903e-05f, 5.324381709215231e-05f, 7.551150338258594e-05f, 0.00010939799540210515f, 0.00010326162737328559f, 0.00021355345961637795f, 7.676796667510644e-05f, 7.990185986272991e-05f, 0.00012837426038458943f, 7.537801866419613e-05f, 8.385875844396651e-05f, 8.150636131176725e-05f, 6.868842319818214e-05f, 9.338932432001457e-05f, 6.337072409223765e-05f, 0.00012375356163829565f, 0.0001241702848346904f, 7.919005292933434e-05f, 9.889028297038749e-05f, 0.0001689979253569618f, 6.125109939603135e-05f, 0.00011168196215294302f, 0.00019096174219157547f, 0.00019072816940024495f, 8.994624658953398e-05f, 0.00017399493663106114f, 9.340896940557286e-05f, 6.218701309990138e-05f, 0.00010332350211683661f, 0.00025522621581330895f, 0.00010435215517645702f, 8.768105180934072e-05f, 0.00011130913480883464f, 6.318915984593332e-05f, 0.00010789502266561612f, 0.00012590258847922087f, 0.00012994627468287945f, 8.624383917776868e-05f, 0.00012756041542161256f, 7.115492189768702e-05f, 6.687310815323144e-05f, 6.929268420208246e-05f, 0.0001314440305577591f, 0.00014232497778721154f, 0.00010576181375654414f, 0.00017343655053991824f, 0.0001862814388005063f, 0.00012633432925213128f, 0.00015161991177592427f, 0.00047597484081052244f, 0.00012462075392249972f, 0.00012727199646178633f, 7.674099470023066e-05f, 0.0001332796091446653f, 8.336405880982056e-05f, 0.00014905899297446012f, 9.834594675339758e-05f, 0.00015029706992208958f, 7.658553658984601e-05f, 0.00020836057956330478f, 5.2292602049419656e-05f, 6.547373050125316e-05f, 0.000137531736982055f, 0.000130932530737482f, 0.00014047735021449625f, 4.7582572733517736e-05f, 0.00012590564438141882f, 0.00013473523722495884f, 6.744231359334663e-05f, 7.651187479496002e-05f, 0.00017562748689670116f, 0.0001107115313061513f, 8.23839072836563e-05f, 0.0001383734925184399f, 6.541830953210592e-05f, 0.00012814186629839242f, 0.00014455945347435772f, 0.00020220319856889546f, 8.443564729532227e-05f, 0.00011770753189921379f, 0.00011614114191615954f, 8.982799772638828e-05f, 0.00010953361925203353f, 6.3314990256913e-05f, 8.02047798060812e-05f, 5.0791510147973895e-05f, 8.162465383065864e-05f, 5.5943757615750656e-05f, 0.00011607424676185474f, 0.00013010259135626256f, 8.109148620860651e-05f, 8.564023301005363e-05f, 7.420383917633444e-05f, 0.00015089049702510238f, 7.99071422079578e-05f, 7.545918924733996e-05f, 0.00011691618419717997f, 0.00010337236744817346f, 0.00011653366527752951f, 4.762370735988952e-05f, 0.00012364856956992298f, 8.30460267025046e-05f, 0.00015744927804917097f, 0.00016845490608830005f, 0.00013010202383156866f, 8.630692900624126e-05f, 0.00010336988634662703f, 0.00016602574032731354f, 0.00015901884762570262f, 7.839174213586375e-05f, 7.989002915564924e-05f, 0.00014065680443309247f, 0.00015265625552274287f, 6.325251160888001e-05f, 0.00012171766138635576f, 8.461566176265478e-05f, 0.00010238397953798994f, 0.00012937169231008738f, 0.00014025291602592915f, 8.018787048058584e-05f, 0.000259459629887715f, 0.00014411623124033213f, 0.00011785524839069694f, 0.0001436107704648748f, 0.00015089593944139779f, 7.119386282283813e-05f, 0.00017354200826957822f, 8.14167142380029e-05f, 0.00016079134366009384f, 8.8675988081377e-05f, 0.00015168500249274075f, 0.00010310192010365427f, 5.601840530289337e-05f, 0.00014229417138267308f, 5.7272340200142935e-05f, 0.00011007403372786939f, 6.206997932167724e-05f, 8.70247749844566e-05f, 0.00010230437328573316f, 0.00013126846170052886f, 0.00012868030171375722f, 3.60967569577042e-05f, 0.00015714943583589047f, 0.00019644600979518145f, 8.416744094574824e-05f, 0.00013735030370298773f, 0.00011218860163353384f, 0.00020981338457204401f, 6.814877997385338e-05f, 5.850923480466008e-05f, 7.677164830965921e-05f, 0.00013236665108706802f, 9.436457912670448e-05f, 0.00010590087913442403f, 0.00013566750567406416f, 6.783874414395541e-05f, 0.00011989282938884571f, 0.0001520942896604538f, 0.00022977340267971158f, 7.472723518731073e-05f, 7.458812615368515e-05f, 0.00012917544518131763f, 3.329421815578826e-05f, 0.0001009203988360241f, 0.0002012570039369166f, 8.379012433579192e-05f, 0.00012210423301439732f, 7.456360617652535e-05f, 0.00014627346536144614f, 0.00012833542132284492f, 9.697804489405826e-05f, 7.167741568991914e-05f, 0.00015172520943451673f, 0.00010674251825548708f, 7.863173232180998e-05f, 5.963865987723693e-05f, 0.00012028979836031795f, 0.0001091456288122572f, 0.00014871868188492954f, 4.249845369486138e-05f, 0.00016777582641225308f, 6.423373270081356e-05f, 4.831743717659265e-05f, 0.0003053472319152206f, 9.003378363559023e-05f, 6.673425377812237e-05f, 0.0001545587438158691f, 9.489693184150383e-05f, 0.00017022178508341312f, 6.691005546599627e-05f, 0.0001501006627222523f, 0.00014860699593555182f, 5.773812881670892e-05f, 0.00017480160749983042f, 6.677328201476485e-05f, 5.030614556744695e-05f, 0.0004430936824064702f, 0.00015325895219575614f, 0.00012377183884382248f, 0.00018244684906676412f, 0.00016258633695542812f, 8.134388190228492e-05f, 0.00012323816190473735f, 0.00010191057663178071f, 8.79566723597236e-05f, 7.308571366593242e-05f, 0.00013067883264739066f, 0.0001238034456036985f, 0.00025660271057859063f, 8.987863839138299e-05f, 4.927402187604457e-05f, 8.00283087301068e-05f, 4.060436549480073e-05f, 0.000152115841046907f, 0.00015194718434941024f, 0.00012109649833291769f, 3.398591070435941e-05f, 0.00011570486094569787f, 0.0001379521272610873f, 7.555249612778425e-05f, 1.8209495465271175e-05f, 0.00012682520900852978f, 9.870277928314408e-10f, 4.595800783135928e-05f, 8.430406887782738e-05f, 6.160133489174768e-05f, 0.0001473446754971519f, 0.00011051012552343309f, 0.00010993358591804281f, 4.9961076001636684e-05f, 0.00010874914732994512f, 7.658174581592903e-05f, 0.00011961498239543289f, 6.105256034061313e-05f, 0.00011656567949103191f, 0.00016366314957849681f, 0.00020818799384869635f, 0.00011145910684717819f, 0.00014837358321528882f, 8.488091407343745e-05f, 0.00010205139551544562f, 0.00012030802463414147f, 9.508300718152896e-05f, 0.00011543968139449134f, 0.00010645858128555119f, 8.613823592895642e-05f, 0.00015745562268421054f, 8.264095231425017e-05f, 0.0001318400609306991f, 7.403944618999958e-05f, 6.562145426869392e-05f, 4.58985086879693e-05f, 0.0001265908795176074f, 7.006798114161938e-05f, 0.00011441288370406255f, 5.680582398781553e-05f, 0.00012442056322470307f, 0.0001641571579966694f, 5.098415931570344e-05f, 7.383279444184154e-05f, 7.901922799646854e-05f, 5.1757404435193166e-05f, 0.00010493195441085845f, 0.00012991130643058568f, 7.597469084430486e-05f, 0.00017494888743385673f, 0.00011800722131738439f, 7.028551772236824e-05f, 0.00011394361354177818f, 0.00011504331632750109f, 6.984112405916676e-05f, 0.00010226421727566049f, 6.119230965850875e-05f, 9.525317000225186e-05f, 5.4107058531371877e-05f, 0.00016252754721790552f, 8.030484605114907e-05f, 0.0001356235588900745f, 5.582282392424531e-05f, 0.00015254586469382048f, 6.222895899554715e-05f, 0.00010039146582130343f, 0.00010653306526364759f, 7.826026558177546e-05f, 8.384566899621859e-05f, 0.00011073363566538319f, 9.426868200534955e-05f, 0.00011008562432834879f, 0.00012545120262075216f, 0.00019024948414880782f, 0.0001227461325470358f, 0.00010808488150360063f, 0.00011593056115088984f, 6.745331484125927e-05f, 8.091330528259277e-05f, 8.486153092235327e-05f, 8.673840056871995e-05f, 6.043758548912592e-05f, 6.788640894228593e-05f, 0.00012551002146210521f, 0.00011444627307355404f, 7.73682986618951e-05f, 5.909069295739755e-05f, 9.28703011595644e-05f, 0.00015936524141579866f, 0.00012694021279457957f, 0.00016350495570804924f, 0.00015429653285536915f, 6.759407551726326e-05f, 0.00012251036241650581f, 0.00016295138630084693f, 0.00015360598627012223f, 0.00015938846627250314f, 0.00018003652803599834f, 4.317567800171673e-05f, 8.573593368055299e-05f, 0.00018640838970895857f, 0.00010701829160097986f, 0.0001533620379632339f, 0.00010536669287830591f, 0.0001820297766244039f, 0.0001432334101991728f, 0.00016261619748547673f, 1.689285272732377e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #153 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007825935259461403f, 0.01299240905791521f, 0.007723917253315449f, 0.006867685355246067f, 0.005593663547188044f, 0.004755862057209015f, 0.009268234483897686f, 0.014328781515359879f, 0.00274422625079751f, 0.0074450294487178326f, 0.006256438326090574f, 0.01572675071656704f, 0.01047467440366745f, 0.012266453355550766f, 0.01115775853395462f, 0.006678607780486345f, 0.0036589461378753185f, 0.002882776316255331f, 0.005907048471271992f, 0.0064288778230547905f, 0.0037872730754315853f, 0.005986938718706369f, 0.004345461260527372f, 0.007184000685811043f, 0.007537662982940674f, 0.006998371332883835f, 0.010939104482531548f, 0.007372237741947174f, 0.005365185905247927f, 0.0026085947174578905f, 0.005080768372863531f, 0.006310209631919861f, 0.007830456830561161f, 0.00835137628018856f, 0.0029802799690514803f, 0.006409929133951664f, 0.008914180099964142f, 0.007498995400965214f, 0.006811207626014948f, 0.01064600795507431f, 0.007563465740531683f, 0.004484064411371946f, 0.007111836224794388f, 0.010051301680505276f, 0.011328790336847305f, 0.006688043940812349f, 0.0047980016097426414f, 0.015677474439144135f, 0.0039921533316373825f, 0.0052179316990077496f, 0.002006828784942627f, 0.005364612210541964f, 0.008613552898168564f, 0.009019805118441582f, 0.005784997250884771f, 0.0024030604399740696f, 0.005274871829897165f, 0.0026816397439688444f, 0.010015634819865227f, 0.005660230293869972f, 0.005809737369418144f, 0.010569253005087376f, 0.002480641473084688f, 0.007496165577322245f, 0.013227532617747784f, 0.007400856353342533f, 0.006197948008775711f, 0.007125506177544594f, 0.007573227863758802f, 0.0047293612733483315f, 0.007087354548275471f, 0.002098031109198928f, 0.007960649207234383f, 0.021744001656770706f, 0.0036065587773919106f, 0.005531896837055683f, 0.00634026899933815f, 0.019291609525680542f, 0.005899797659367323f, 0.007093743421137333f, 0.006620932370424271f, 0.01037029642611742f, 0.011386409401893616f, 0.007677809335291386f, 0.005214863456785679f, 0.002583656460046768f, 0.00599770899862051f, 0.009244261309504509f, 0.003582686884328723f, 0.009414313361048698f, 0.010069487616419792f, 0.007160534616559744f, 0.013118013739585876f, 0.007463764399290085f, 0.005118140019476414f, 0.008226045407354832f, 0.004759808536618948f, 0.011616019532084465f, 0.005884626414626837f, 0.005879709497094154f, 0.006285961717367172f, 0.00556746544316411f, 0.007514387834817171f, 0.005144632421433926f, 0.015559077262878418f, 0.011177764274179935f, 0.005314768757671118f, 0.007479274179786444f, 0.017425836995244026f, 0.008912330493330956f, 0.008732100948691368f, 0.008092198520898819f, 0.009464792907238007f, 0.0062214345671236515f, 0.006360511761158705f, 0.0020664813928306103f, 0.008971343748271465f, 0.00689599709585309f, 0.007059801369905472f, 0.0034532081335783005f, 0.008009670302271843f, 0.006716371979564428f, 0.0025989520363509655f, 0.0018637944012880325f, 0.01024861540645361f, 0.008183418773114681f, 0.003739577252417803f, 0.00843227468430996f, 0.013767465949058533f, 0.0015930883819237351f, 0.004032874014228582f, 0.009366904385387897f, 0.006906319875270128f, 0.00452135456725955f, 0.02137160301208496f, 0.0016452086856588721f, 0.011013912968337536f, 0.004418643191456795f, 0.0025593622121959925f, 0.004284280352294445f, 0.006434489507228136f, 0.009608142077922821f, 0.00649708416312933f, 0.005848165601491928f, 0.01209114957600832f, 0.005205809138715267f, 0.013049930334091187f, 0.0036327296402305365f, 0.010119356215000153f, 0.015925880521535873f, 0.0038967079017311335f, 0.005907867103815079f, 0.011886599473655224f, 0.015455172397196293f, 0.01078518945723772f, 0.00247614411637187f, 0.008338211104273796f, 0.003005241509526968f, 0.012213998474180698f, 0.0016915085725486279f, 0.01380784809589386f, 0.005722889676690102f, 0.007791133131831884f, 0.0027171727269887924f, 0.008512292988598347f, 0.007394341751933098f, 0.00877574272453785f, 0.010051531717181206f, 0.0068348306231200695f, 0.008818498812615871f, 0.0011896161595359445f, 0.006243076175451279f, 0.006429832894355059f, 0.0058157965540885925f, 0.014856388792395592f, 0.007124131079763174f, 0.0026461470406502485f, 0.011006120592355728f, 0.009028071537613869f, 0.008102662861347198f, 0.004310280550271273f, 0.011590343900024891f, 0.005203640554100275f, 0.013667084276676178f, 0.005957416258752346f, 0.014691132120788097f, 0.0072812363505363464f, 0.007472996599972248f, 0.009727152064442635f, 0.0038375400472432375f, 0.0023733917623758316f, 0.01808423548936844f, 0.010926878079771996f, 0.007197093218564987f, 0.009160175919532776f, 0.0021193567663431168f, 0.01471023727208376f, 0.009450823999941349f, 0.013630850240588188f, 0.004990869667381048f, 0.0069882539100945f, 0.00954101700335741f, 0.004778325092047453f, 0.006243910640478134f, 0.010098611004650593f, 0.008770275861024857f, 0.0115268025547266f, 0.007298235781490803f, 0.00796010997146368f, 0.018977295607328415f, 0.002994326176121831f, 0.011327886022627354f, 0.0023168534971773624f, 0.008640500716865063f, 0.0048729730769991875f, 0.004086566623300314f, 0.006726943887770176f, 0.014513709582388401f, 0.008909326046705246f, 0.005182474385946989f, 0.010530720464885235f, 0.0060333083383738995f, 0.01040664128959179f, 0.006505084224045277f, 0.012738293036818504f, 0.009197683073580265f, 0.00778215192258358f, 0.004762162454426289f, 0.014603656716644764f, 0.007682816591113806f, 0.006794599816203117f, 0.009539209306240082f, 0.018858643248677254f, 0.010304294526576996f, 0.13515953719615936f, 0.010605080053210258f, 0.00579939316958189f, 0.004222302697598934f, 0.014644003473222256f, 0.015375562943518162f, 0.012748553417623043f, 0.006996435578912497f, 0.004738663323223591f, 0.008592825382947922f, 0.003087725257501006f, 0.008880279026925564f, 0.007144061848521233f, 0.0024355719797313213f, 0.0087824035435915f, 0.006897639948874712f, 0.008042968809604645f, 0.006034154910594225f, 0.002787506440654397f, 0.004067649133503437f, 0.005642351694405079f, 0.004585638176649809f, 0.007098800968378782f, 0.01569535955786705f, 0.007901892066001892f, 0.0027663849759846926f, 0.002913397504016757f, 0.0114605026319623f, 0.009411702863872051f, 0.006658544298261404f, 0.004851949401199818f, 0.012679839506745338f, 0.006259653717279434f, 0.007954702712595463f, 0.004530700389295816f, 0.00646366598084569f, 0.014980321750044823f, 0.01065476331859827f, 0.008866463787853718f, 0.007424966432154179f, 0.005767343565821648f, 0.011410432867705822f, 0.004690644796937704f, 0.00466669537127018f, 0.004622758831828833f, 0.006119291763752699f, 0.0056945220567286015f, 0.013379807583987713f, 0.004961048252880573f, 0.014590318314731121f, 0.006939163897186518f, 0.007563568186014891f, 0.016403568908572197f, 0.0033094044774770737f, 0.010835697874426842f, 0.005085371434688568f, 0.013734562322497368f, 0.009743313305079937f, 0.006586045958101749f, 0.005001510493457317f, 0.008805522695183754f, 0.008207220584154129f, 0.004625616129487753f, 0.005680132191628218f, 0.008189259096980095f, 0.006370764225721359f, 0.020307060331106186f, 0.0030750150326639414f, 0.01613924466073513f, 0.005936744157224894f, 0.004420241340994835f, 0.011077254079282284f, 0.007809294853359461f, 0.011408556252717972f, 0.0071028973907232285f, 0.010390518233180046f, 0.013968037441372871f, 0.007131598424166441f, 0.0024071591906249523f, 0.014627144671976566f, 0.009632887318730354f, 0.0027008720207959414f, 0.002193572698161006f, 0.012879031710326672f, 0.01848437450826168f, 0.001999045256525278f, 0.009951970539987087f, 0.0038335409481078386f, 0.0029733125120401382f, 0.003692319616675377f, 0.0019008825765922666f, 0.011782863177359104f, 0.023831147700548172f, 0.005553562194108963f, 0.002241404727101326f, 0.007035982795059681f, 0.003554430790245533f, 0.013194410130381584f, 0.00582598801702261f, 0.007281225174665451f, 0.0021771849133074284f, 0.013541053980588913f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #154 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0001841396588133648f, 0.0003057037538383156f, 0.00018173923308495432f, 0.00016159260121639818f, 0.00013161561219021678f, 0.0001119026419473812f, 0.000218076107557863f, 0.0003371477941982448f, 6.457002746174112e-05f, 0.00017517716332804412f, 0.0001472103176638484f, 0.00037004120531491935f, 0.0002464629360474646f, 0.00028862242470495403f, 0.00026253549731336534f, 0.00015714371693320572f, 8.609284850535914e-05f, 6.783003482269123e-05f, 0.00013898937322665006f, 0.0001512677117716521f, 8.911231270758435e-05f, 0.0001408691459801048f, 0.00010224615107290447f, 0.00016903530922718346f, 0.00017735677829477936f, 0.00016466756642330438f, 0.0002573906967882067f, 0.00017346441745758057f, 0.00012623966904357076f, 6.137869786471128e-05f, 0.00011954749061260372f, 0.00014847551938146353f, 0.0001842460478655994f, 0.0001965029805433005f, 7.012423884589225e-05f, 0.0001508218701928854f, 0.0002097454125760123f, 0.00017644694889895618f, 0.0001602637057658285f, 0.00025049431133084f, 0.00017796389875002205f, 0.0001055074026226066f, 0.00016733731899876148f, 0.00023650121875107288f, 0.0002665597712621093f, 0.00015736575005576015f, 0.00011289415851933882f, 0.000368881766917184f, 9.393302025273442e-05f, 0.00012277487257961184f, 4.721950244856998e-05f, 0.00012622616486623883f, 0.00020267184299882501f, 0.00021223071962594986f, 0.00013611758186016232f, 5.654259803122841e-05f, 0.00012411463831085712f, 6.309741002041847e-05f, 0.00023566199524793774f, 0.00013318189303390682f, 0.00013669970212504268f, 0.00024868830223567784f, 5.836803757119924e-05f, 0.0001763803738867864f, 0.00031123607186600566f, 0.00017413779278285801f, 0.0001458340702811256f, 0.0001676589745329693f, 0.00017819360073190182f, 0.00011127909237984568f, 0.00016676128143444657f, 4.936544064548798e-05f, 0.00018730940064415336f, 0.0005116235697641969f, 8.486020669806749e-05f, 0.00013016228331252933f, 0.00014918280066922307f, 0.00045392022002488375f, 0.00013881876657251269f, 0.00016691161727067083f, 0.00015578664897475392f, 0.00024400698021054268f, 0.0002679155149962753f, 0.0001806543441489339f, 0.00012270266597624868f, 6.079191734897904e-05f, 0.0001411225675838068f, 0.0002175120316678658f, 8.429851732216775e-05f, 0.00022151325538288802f, 0.000236929117818363f, 0.00016848316590767354f, 0.00030865916050970554f, 0.00017561798449605703f, 0.00012042682647006586f, 0.00019355402037035674f, 0.00011199549771845341f, 0.0002733181172516197f, 0.00013846179354004562f, 0.0001383461058139801f, 0.00014790498244110495f, 0.00013099919306114316f, 0.000176809131517075f, 0.0001210501795867458f, 0.00036609594826586545f, 0.00026300622266717255f, 0.00012505338236223906f, 0.00017598293197806925f, 0.00041001971112564206f, 0.0002097019023494795f, 0.00020546119776554406f, 0.00019040468032471836f, 0.00022270101180765778f, 0.00014638669381383806f, 0.00014965909940656275f, 4.862309288000688e-05f, 0.00021109044610057026f, 0.00016225875879172236f, 0.0001661129790591076f, 8.125195745378733e-05f, 0.0001884628291008994f, 0.00015803228598088026f, 6.11518116784282e-05f, 4.38539864262566e-05f, 0.0002411438908893615f, 0.00019255102961324155f, 8.799005445325747e-05f, 0.0001984064729185775f, 0.0003239403886254877f, 3.748443486983888e-05f, 9.489115473115817e-05f, 0.0002203977492172271f, 0.00016250164480879903f, 0.0001063848176272586f, 0.0005028612795285881f, 3.871079388773069e-05f, 0.00025915089645422995f, 0.00010396807920187712f, 6.0220289014978334e-05f, 0.00010080659558298066f, 0.0001513997558504343f, 0.00022607394203078002f, 0.00015287256974261254f, 0.00013760389992967248f, 0.000284497655229643f, 0.0001224896259373054f, 0.00030705719836987555f, 8.547599281882867e-05f, 0.00023810249695088714f, 0.00037472660187631845f, 9.168724500341341e-05f, 0.00013900863996241242f, 0.000279684696579352f, 0.000363651110092178f, 0.00025376916164532304f, 5.8262216043658555e-05f, 0.00019619319937191904f, 7.071156869642437e-05f, 0.0002873882185667753f, 3.980020119342953e-05f, 0.00032489054137840867f, 0.00013465623487718403f, 0.00018332077888771892f, 6.393347575794905e-05f, 0.0002002892579184845f, 0.00017398451745975763f, 0.000206488068215549f, 0.00023650663206353784f, 0.00016081954527180642f, 0.0002074941003229469f, 2.799096910166554e-05f, 0.0001468959089834243f, 0.00015129019448067993f, 0.00013684228179045022f, 0.0003495620912872255f, 0.0001676266110735014f, 6.22622828814201e-05f, 0.00025896754232235253f, 0.0002124252205248922f, 0.00019065089873038232f, 0.00010141836537513882f, 0.0002727139799389988f, 0.00012243860692251474f, 0.00032157846726477146f, 0.00014017449575476348f, 0.00034567370312288404f, 0.00017132320499513298f, 0.0001758352154865861f, 0.00022887416707817465f, 9.029506327351555e-05f, 5.5844513553893194e-05f, 0.0004255114181432873f, 0.0002571030054241419f, 0.000169343373272568f, 0.00021553355327341706f, 4.9867219786392525e-05f, 0.00034612324088811874f, 0.00022237232769839466f, 0.0003207258996553719f, 0.00011743223149096593f, 0.00016442951164208353f, 0.00022449452080763876f, 0.00011243118206039071f, 0.0001469155540689826f, 0.00023761438205838203f, 0.00020635942928493023f, 0.00027121888706460595f, 0.0001717231934890151f, 0.00018729671137407422f, 0.0004465246165636927f, 7.04547346686013e-05f, 0.0002665384963620454f, 5.451419929158874e-05f, 0.00020330589904915541f, 0.00011465819261502475f, 9.615450835553929e-05f, 0.00015828103641979396f, 0.00034149904968217015f, 0.0002096312091453001f, 0.0001219405748997815f, 0.00024778165970928967f, 0.00014196020492818207f, 0.00024486216716468334f, 0.0001530608133180067f, 0.0002997245464939624f, 0.00021641608327627182f, 0.00018310945597477257f, 0.00011205088230781257f, 0.00034361545112915337f, 0.00018077215645462275f, 0.00015987294318620116f, 0.00022445198555942625f, 0.00044373280252330005f, 0.00024245399981737137f, 0.003180224448442459f, 0.00024953129468485713f, 0.000136456306790933f, 9.934829722624272e-05f, 0.00034456478897482157f, 0.00036177795846015215f, 0.000299965962767601f, 0.0001646220189286396f, 0.00011149796046083793f, 0.0002021841355599463f, 7.265235763043165e-05f, 0.00020894774934276938f, 0.000168095575645566f, 5.7307577662868425e-05f, 0.0002066447923425585f, 0.0001622974086785689f, 0.00018924633332062513f, 0.00014198011194821447f, 6.558838504133746e-05f, 9.570939437253401e-05f, 0.00013276121171656996f, 0.0001078973727999255f, 0.0001670306082814932f, 0.0003693025792017579f, 0.00018592688138596714f, 6.509141530841589e-05f, 6.855052924947813e-05f, 0.00026965889264829457f, 0.00022145183174870908f, 0.00015667163825128227f, 0.00011416351480875164f, 0.0002983491576742381f, 0.00014728597307112068f, 0.0001871694839792326f, 0.00010660471889423206f, 0.00015208625700324774f, 0.0003524781786836684f, 0.00025070030824281275f, 0.00020862268866039813f, 0.0001747050991980359f, 0.00013570219743996859f, 0.000268480769591406f, 0.00011036811338271946f, 0.00010980459774145856f, 0.00010877080057980493f, 0.00014398334315046668f, 0.00013398875307757407f, 0.0003148190153297037f, 0.00011673055269056931f, 0.0003433016245253384f, 0.0001632744533708319f, 0.00017796631436794996f, 0.00038596632657572627f, 7.786833884892985e-05f, 0.00025495761656202376f, 0.00011965580051764846f, 0.00032316616852767766f, 0.00022925443772692233f, 0.00015496578998863697f, 0.0001176826044684276f, 0.0002071887720376253f, 0.00019311107462272048f, 0.00010883803042815998f, 0.00013365017366595566f, 0.00019268845790065825f, 0.0001499003410572186f, 0.000477813184261322f, 7.235329394461587e-05f, 0.0003797469544224441f, 0.00013968809798825532f, 0.00010400568135082722f, 0.00026064127450808883f, 0.00018374812498223037f, 0.0002684366190806031f, 0.0001671270001679659f, 0.0002444827987346798f, 0.00032865972025319934f, 0.00016780232544988394f, 5.663904084940441e-05f, 0.0003441681037656963f, 0.0002266561787109822f, 6.354993092827499e-05f, 5.16134750796482e-05f, 0.0003030360385309905f, 0.0004349264781922102f, 4.703635931946337e-05f, 0.00023416402109432966f, 9.020096331369132e-05f, 6.996029696892947e-05f, 8.68781135068275e-05f, 4.472665023058653e-05f, 0.00027724384563043714f, 0.000560732907615602f, 0.00013067205145489424f, 5.273893475532532e-05f, 0.0001655525411479175f, 8.363366941921413e-05f, 0.00031045672949403524f, 0.00013708206824958324f, 0.00017132294306065887f, 5.122788206790574e-05f, 0.0003186130488757044f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #155 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003722590859979391f, 0.005166194401681423f, 0.006411546841263771f, 0.006104451138526201f, 0.008650653064250946f, 0.009354004636406898f, 0.007212489377707243f, 0.004446621518582106f, 0.011430935934185982f, 0.004489575512707233f, 0.008673436939716339f, 0.01507863774895668f, 0.003991708625108004f, 0.012610597535967827f, 0.009684494696557522f, 0.0032138540409505367f, 0.0063924542628228664f, 0.006518612615764141f, 0.006334715057164431f, 0.005306134466081858f, 0.0071409824304282665f, 0.00658711651340127f, 0.011111904866993427f, 0.005219192244112492f, 0.009618445299565792f, 0.005887886043637991f, 0.004762082826346159f, 0.010199238546192646f, 0.006264984607696533f, 0.004968222230672836f, 0.009383726865053177f, 0.0160351675003767f, 0.004920480772852898f, 0.007519877515733242f, 0.004266605246812105f, 0.007062897086143494f, 0.00655359635129571f, 0.011172286234796047f, 0.0032313591800630093f, 0.010231728665530682f, 0.008439477533102036f, 0.019687501713633537f, 0.004405539948493242f, 0.004756871145218611f, 0.005347731988877058f, 0.011479390785098076f, 0.005219428800046444f, 0.006460215430706739f, 0.005866401828825474f, 0.00501851923763752f, 0.009528109803795815f, 0.008587398566305637f, 0.007519822102040052f, 0.008015179075300694f, 0.008610982447862625f, 0.006810722406953573f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #156 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_58_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.723480277694762e-05f, 0.00012106406211387366f, 0.000150247520650737f, 0.00014305107470136136f, 0.00020271849643904716f, 0.00021920076687820256f, 0.00016901672643143684f, 0.00010420166654512286f, 0.00026787136448547244f, 0.00010520824434934184f, 0.00020325242076069117f, 0.00035335123538970947f, 9.354128269478679e-05f, 0.00029551543411798775f, 0.00022694544168189168f, 7.531311712227762e-05f, 0.00014980010746512562f, 0.00015275648911483586f, 0.00014844705583527684f, 0.00012434340897016227f, 0.00016734104428905994f, 0.00015436179819516838f, 0.0002603952307254076f, 0.00012230600987095386f, 0.00022539764177054167f, 0.00013797610881738365f, 0.00011159415589645505f, 0.00023900788801256567f, 0.00014681299217045307f, 0.0001164248023997061f, 0.0002198972797486931f, 0.0003757664526347071f, 0.00011530603660503402f, 0.00017622002633288503f, 9.998318273574114e-05f, 0.00016551119915675372f, 0.00015357630036305636f, 0.0002618102007545531f, 7.572333561256528e-05f, 0.00023976925876922905f, 0.00019776984117925167f, 0.0004613548517227173f, 0.00010323896276531741f, 0.00011147202167194337f, 0.00012531819811556488f, 0.0002690068504307419f, 0.00012231155415065587f, 0.000151388012454845f, 0.00013747265620622784f, 0.00011760345660150051f, 0.00022328073100652546f, 0.00020123620925005525f, 0.0001762187312124297f, 0.00018782686674967408f, 0.00020178886188659817f, 0.0001596017536940053f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #157 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0005764568340964615f, 0.0005423232796601951f, 0.0010303477756679058f, 0.0006638749036937952f, 0.0008720578043721616f, 0.0006585454102605581f, 0.0016895580338314176f, 0.0007446880335919559f, 0.0007089873543009162f, 0.0007022980134934187f, 0.00027071169461123645f, 0.0012841671705245972f, 0.0010621445253491402f, 0.0006077828584238887f, 0.0005683014751411974f, 0.000296157319098711f, 0.0008524819277226925f, 0.0006806721212342381f, 0.0013563603861257434f, 0.0005509974434971809f, 0.0004096156044397503f, 0.0009711158345453441f, 0.000755250221118331f, 0.0009097674628719687f, 0.00042412805487401783f, 0.0006566779920831323f, 0.0005046341102570295f, 0.0006350338808260858f, 0.0005467486917041242f, 0.0006819072877988219f, 0.0003202423104085028f, 0.0009004311868920922f, 0.0005017536459490657f, 0.000763557618483901f, 0.0006429023342207074f, 0.00040411174995824695f, 0.0008481190889142454f, 0.0008370815776288509f, 0.00031104922527447343f, 0.0003814268275164068f, 0.0005169797805137932f, 0.00033719342900440097f, 0.0010868702083826065f, 0.0006684440304525197f, 0.0007356541464105248f, 0.0009286841377615929f, 0.0007559863734059036f, 0.0013422103365883231f, 0.0007863965583965182f, 0.0008385462570004165f, 0.0004087817796971649f, 0.0007050101412460208f, 0.0008302631322294474f, 0.0010051779681816697f, 0.0006775742513127625f, 0.0005824226536788046f, 0.0008389101712964475f, 0.0006843233131803572f, 0.0005537836696021259f, 0.000604048022069037f, 0.00044210487976670265f, 0.0006202583899721503f, 0.0007435393636114895f, 0.0002606152556836605f, 0.0006201800424605608f, 0.00037009938387200236f, 0.0005853591137565672f, 0.00036678012111224234f, 0.0007466966053470969f, 0.000780573405791074f, 0.00036893165088258684f, 0.00046701382962055504f, 0.0008881894173100591f, 0.0008671369287185371f, 0.0006067116628400981f, 0.00047535993508063257f, 0.000768498401157558f, 0.0004306133487261832f, 0.00034724894794635475f, 0.000680572644341737f, 0.000990980421192944f, 0.0004456835158634931f, 0.0007649481412954628f, 0.0005346631514839828f, 0.00038722436875104904f, 0.0005143532180227339f, 0.0005988790653645992f, 0.0004755106056109071f, 0.0005394488107413054f, 0.0008225610363297164f, 0.0004680970450863242f, 0.0008722737547941506f, 0.0004060437495354563f, 0.0008653984987176955f, 0.0006972866831347346f, 0.0005570548819378018f, 0.0007153099286369979f, 0.00048331075231544673f, 0.000760250783059746f, 0.0005694050923921168f, 0.00048263478674925864f, 0.000651601527351886f, 0.0008008485310710967f, 0.0007181179244071245f, 0.0007292472873814404f, 0.0009522295440547168f, 0.0004137176729273051f, 0.0009036797564476728f, 0.0007908676634542644f, 0.0010248656617477536f, 0.0004070586001034826f, 0.0006585383671335876f, 0.00048172182869166136f, 0.000660477380733937f, 0.0011007346911355853f, 0.0007574806804768741f, 0.0008325328235514462f, 0.0005614469409920275f, 0.0006495650741271675f, 0.0007058629998937249f, 0.0004777382127940655f, 0.0004165793361607939f, 0.0006813335930928588f, 0.0004925585817545652f, 0.0006582345231436193f, 0.00045083026634529233f, 0.000844196998514235f, 5.517206227523275e-05f, 0.0005299861659295857f, 0.000364342937245965f, 0.0004355336131993681f, 0.0006692348979413509f, 0.0008974457741715014f, 0.0004351605020929128f, 0.000473147229058668f, 0.00043498221202753484f, 0.00038845313247293234f, 0.0006424154271371663f, 0.0006835070089437068f, 0.0010234416695311666f, 0.0003456384874880314f, 0.0008141638827510178f, 0.0007155180210247636f, 0.0011677120346575975f, 0.0006744283600710332f, 0.0005805547698400915f, 0.0010610900353640318f, 0.0006003576563671231f, 0.0008319597109220922f, 0.00037461769534274936f, 0.0005131170037202537f, 0.0004277118423487991f, 0.0006978872115723789f, 0.00039449799805879593f, 0.0006699693622067571f, 0.0014492843765765429f, 0.0007562972023151815f, 0.0005075189401395619f, 0.00043793770601041615f, 0.0010521382791921496f, 0.0007864244980737567f, 0.0006818301044404507f, 0.0004850155964959413f, 0.0005548803019337356f, 0.00075968645978719f, 0.0009002372389659286f, 0.0007427912205457687f, 0.0006484441109932959f, 0.0003483426698949188f, 0.000744495599064976f, 0.0006594801088795066f, 0.0006138590397313237f, 0.001139461062848568f, 0.0007724636816419661f, 0.0008326562237925828f, 0.0009569113608449697f, 0.0008842534734867513f, 0.000208821875276044f, 0.00040611278382129967f, 0.0003877095296047628f, 0.0005058685783296824f, 0.0006710236775688827f, 0.0013349608052521944f, 0.0007652717176824808f, 0.00042882919660769403f, 0.00046376415411941707f, 0.0005674092099070549f, 0.0004279313434381038f, 0.001231739530339837f, 0.0010362102184444666f, 0.0007660217816010118f, 0.000511208432726562f, 0.0005479246028698981f, 0.00040808008634485304f, 0.0008274595020338893f, 0.0007820419850759208f, 0.00039233179995790124f, 0.0008025761344470084f, 0.0009308959124609828f, 0.0003375438682269305f, 0.0009068554500117898f, 0.0007096815388649702f, 0.0006146026425994933f, 0.0006218778435140848f, 0.0009329730528406799f, 0.0006311951437965035f, 0.00036736144102178514f, 0.0009962260955944657f, 0.0007606182480230927f, 0.0008977151592262089f, 0.00038453435990959406f, 0.00129055161960423f, 0.0008775726892054081f, 0.0005177489947527647f, 0.0006398863042704761f, 0.0008087416063062847f, 0.000937949400395155f, 0.000740537594538182f, 0.0006960763712413609f, 0.00028603230020962656f, 0.000514222017955035f, 0.0011427632998675108f, 0.0006409519701264799f, 0.0005910841864533722f, 0.0006062710890546441f, 0.00029881109367124736f, 0.0005719228647649288f, 0.0005010950844734907f, 0.00030769355362281203f, 0.0008769555133767426f, 0.0006765472353436053f, 0.000478168367408216f, 0.0006358715472742915f, 0.0008697412558831275f, 0.0006533824489451945f, 0.0002652071416378021f, 0.0009104169439524412f, 0.0008829112630337477f, 0.00047626724699512124f, 0.0005525168380700052f, 0.0003202176303602755f, 0.000763817981351167f, 0.0007840168545953929f, 0.0007419525645673275f, 0.0006414932431653142f, 0.00043420467409305274f, 0.000725971651263535f, 0.000573726836591959f, 0.0005960622802376747f, 0.0009677622001618147f, 0.000600817147642374f, 0.00023029099975246936f, 0.0005833784816786647f, 0.0008455839706584811f, 0.0004253120278008282f, 0.000484094227431342f, 0.0003345632285345346f, 0.0006704256520606577f, 0.0008369739516638219f, 0.000597357633523643f, 0.0008316842140629888f, 0.0007355866255238652f, 0.0003878417192026973f, 0.0008324418449774384f, 0.00042118068085983396f, 0.0007976651540957391f, 0.0004791353130713105f, 0.0005599388969130814f, 0.0006864155875518918f, 0.00039913924410939217f, 0.0013572657480835915f, 0.0008250927785411477f, 0.00033405033173039556f, 0.0005276220035739243f, 0.0006405177409760654f, 0.0010161662939935923f, 0.0006508614169433713f, 0.002023607026785612f, 0.0009090382955037057f, 0.000747669255360961f, 0.0004929961869493127f, 0.0006205242243595421f, 0.000845136761199683f, 0.0007090542349033058f, 0.0003957573208026588f, 0.0009522633627057076f, 0.0003916363057214767f, 0.0009494375553913414f, 0.0011515411315485835f, 0.0005825507687404752f, 0.0011906453873962164f, 0.0006142642232589424f, 0.0007588415173813701f, 0.0006500929594039917f, 0.0006588094402104616f, 0.0003280515084043145f, 0.0008707355009391904f, 0.0008772147702984512f, 0.0008445259882137179f, 0.0005458776140585542f, 0.0006903329049237072f, 0.00033653731225058436f, 0.00042017336818389595f, 0.0004965896951034665f, 0.000812902522739023f, 0.0005048617022112012f, 0.00038727547507733107f, 0.0006280053057707846f, 0.0005999045097269118f, 0.0002473389031365514f, 0.0010358532890677452f, 0.000520066125318408f, 0.0005790544091723859f, 0.00047165071009658277f, 0.00046822105650790036f, 0.0008078339160420001f, 0.0006113086128607392f, 0.0006543149356730282f, 0.000570831703953445f, 0.0002958358090836555f, 0.0006206100806593895f, 0.0008666564244776964f, 0.0005665792850777507f, 0.0007955426699481905f, 0.0005045979050919414f, 0.0009126923396252096f, 0.0002799311187118292f, 0.0011028748704120517f, 0.0005283884820528328f, 0.00025026031653396785f, 0.0005786542897112668f, 0.00046257529174908996f, 0.0015140583273023367f, 0.00031088737887330353f, 0.0005962432478554547f, 0.0007398063316941261f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #158 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(7.961459050420672e-05f, 7.490039570257068e-05f, 0.00014230157830752432f, 9.168792166747153e-05f, 0.00012044010509271175f, 9.095186396734789e-05f, 0.0002333452575840056f, 0.0001028490369208157f, 9.791841148398817e-05f, 9.699454676592723e-05f, 3.7388057535281405e-05f, 0.00017735663277562708f, 0.00014669302618131042f, 8.39410349726677e-05f, 7.848825043765828e-05f, 4.090235597686842e-05f, 0.00011773648293456063f, 9.400778799317777e-05f, 0.00018732725584413856f, 7.609838939970359e-05f, 5.6572109315311536e-05f, 0.00013412102998699993f, 0.00010430778638692573f, 0.00012564819189719856f, 5.857642463524826e-05f, 9.069395309779793e-05f, 6.969513924559578e-05f, 8.770467684371397e-05f, 7.551159069407731e-05f, 9.41783728194423e-05f, 4.422874189913273e-05f, 0.0001243587612407282f, 6.929731171112508e-05f, 0.0001054551248671487f, 8.879139204509556e-05f, 5.581196819548495e-05f, 0.00011713392450474203f, 0.00011560953134903684f, 4.2959080019500107e-05f, 5.267894812277518e-05f, 7.140020170481876e-05f, 4.656986493500881e-05f, 0.0001501078950241208f, 9.231896547134966e-05f, 0.00010160137026105076f, 0.00012826078454963863f, 0.00010440945334266871f, 0.0001853729918366298f, 0.00010860941256396472f, 0.00011581181752262637f, 5.645694909617305e-05f, 9.736911306390539e-05f, 0.00011466783325886354f, 0.00013882535859011114f, 9.357993985759094e-05f, 8.043852722039446e-05f, 0.00011586207983782515f, 9.451205551158637e-05f, 7.648319297004491e-05f, 8.342521323356777e-05f, 6.105921056587249e-05f, 8.566403266740963e-05f, 0.00010269039921695367f, 3.599363481043838e-05f, 8.565321331843734e-05f, 5.111451173434034e-05f, 8.084408182185143e-05f, 5.065609002485871e-05f, 0.00010312644735677168f, 0.00010780517914099619f, 5.095323649584316e-05f, 6.449939246522263e-05f, 0.0001226680469699204f, 0.00011976048699580133f, 8.37930929264985e-05f, 6.565207149833441e-05f, 0.00010613749327603728f, 5.947210956946947e-05f, 4.7958634240785614e-05f, 9.39940509852022e-05f, 0.00013686454622074962f, 6.155345181468874e-05f, 0.00010564716649241745f, 7.384245691355318e-05f, 5.347964906832203e-05f, 7.103744428604841e-05f, 8.271132537629455e-05f, 6.567288073711097e-05f, 7.45034049032256e-05f, 0.00011360409553162754f, 6.464899342972785e-05f, 0.0001204699365189299f, 5.60787993890699e-05f, 0.00011952038767049089f, 9.630242857383564e-05f, 7.69349790061824e-05f, 9.879162098513916e-05f, 6.675015902146697e-05f, 0.0001049984130077064f, 7.864067447371781e-05f, 6.665680120931938e-05f, 8.999284182209522e-05f, 0.00011060538236051798f, 9.917943680193275e-05f, 0.00010071651195175946f, 0.00013151264283806086f, 5.7138644478982314e-05f, 0.0001248074258910492f, 0.00010922691581072286f, 0.0001415444421581924f, 5.621895979857072e-05f, 9.095088898902759e-05f, 6.65307161398232e-05f, 9.121868788497522e-05f, 0.0001520227233413607f, 0.00010461583588039503f, 0.0001149813033407554f, 7.754156831651926e-05f, 8.971158240456134e-05f, 9.74869035417214e-05f, 6.59805373288691e-05f, 5.753387085860595e-05f, 9.409914491698146e-05f, 6.802738062106073e-05f, 9.090892126550898e-05f, 6.226427649380639e-05f, 0.0001165922440122813f, 7.619826646987349e-06f, 7.31965119484812e-05f, 5.031948967371136e-05f, 6.0151651268824935e-05f, 9.242819214705378e-05f, 0.00012394644727464765f, 6.010011929902248e-05f, 6.534647400258109e-05f, 6.0075497458456084e-05f, 5.364935350371525e-05f, 8.872414764482528e-05f, 9.43993145483546e-05f, 0.00014134777302388102f, 4.7736211854498833e-05f, 0.00011244436609558761f, 9.882036101771519e-05f, 0.00016127298295032233f, 9.314545604865998e-05f, 8.018055814318359e-05f, 0.00014654739061370492f, 8.291553967865184e-05f, 0.0001149021481978707f, 5.173853787709959e-05f, 7.086670666467398e-05f, 5.907138256588951e-05f, 9.638536721467972e-05f, 5.448421143228188e-05f, 9.252962627215311e-05f, 0.0002001610118895769f, 0.0001044523814925924f, 7.009356340859085e-05f, 6.0483678680611774e-05f, 0.00014531105989590287f, 0.00010861327609745786f, 9.416771354153752e-05f, 6.698561628581956e-05f, 7.663464930374175e-05f, 0.00010492047294974327f, 0.00012433197116479278f, 0.00010258707334287465f, 8.955677185440436e-05f, 4.810968675883487e-05f, 0.00010282246512360871f, 9.108095400733873e-05f, 8.478021482005715e-05f, 0.00015737123612780124f, 0.00010668514005374163f, 0.00011499834363348782f, 0.00013215925719123334f, 0.00012212446017656475f, 2.884043897211086e-05f, 5.608833089354448e-05f, 5.354665336199105e-05f, 6.986562948441133e-05f, 9.267524001188576e-05f, 0.00018437174730934203f, 0.00010569185542408377f, 5.922570198890753e-05f, 6.405057501979172e-05f, 7.836501754354686e-05f, 5.9101697843289e-05f, 0.00017011583258863539f, 0.00014311123231891543f, 0.00010579545050859451f, 7.060312054818496e-05f, 7.56739973439835e-05f, 5.636003697873093e-05f, 0.00011428062862250954f, 0.00010800800373544917f, 5.418503860710189e-05f, 0.00011084397556260228f, 0.0001285662583541125f, 4.661826460505836e-05f, 0.00012524602061603218f, 9.801428677747026e-05f, 8.488291496178135e-05f, 8.588769560446963e-05f, 0.00012885313481092453f, 8.717450691619888e-05f, 5.073637657915242e-05f, 0.00013758901332039386f, 0.00010504916281206533f, 0.0001239836565218866f, 5.310813139658421e-05f, 0.00017823839152697474f, 0.00012120177416363731f, 7.150643796194345e-05f, 8.837485074764118e-05f, 0.0001116954954341054f, 0.00012954040721524507f, 0.00010227582242805511f, 9.613527072360739e-05f, 3.950398968299851e-05f, 7.10193271515891e-05f, 0.00015782730770297348f, 8.852202881826088e-05f, 8.163477468769997e-05f, 8.373224409297109e-05f, 4.126887142774649e-05f, 7.898839976405725e-05f, 6.920636224094778e-05f, 4.249563062330708e-05f, 0.00012111652904422954f, 9.343809506390244e-05f, 6.603994552278891e-05f, 8.78203718457371e-05f, 0.00012012016668450087f, 9.023880556924269e-05f, 3.6627821828005835e-05f, 0.00012573790445458144f, 0.00012193908332847059f, 6.577737804036587e-05f, 7.630822801729664e-05f, 4.4225333112990484e-05f, 0.00010549108264967799f, 0.00010828075028257445f, 0.00010247124009765685f, 8.8596782006789e-05f, 5.9968107962049544e-05f, 0.00010026411473518237f, 7.923755038063973e-05f, 8.232230175053701e-05f, 0.00013365787162911147f, 8.297900058096275e-05f, 3.18055426760111e-05f, 8.05705421953462e-05f, 0.0001167837981483899f, 5.873994450666942e-05f, 6.68583670631051e-05f, 4.620660547516309e-05f, 9.259264334104955e-05f, 0.00011559466656763107f, 8.250120299635455e-05f, 0.00011486410221550614f, 0.00010159204248338938f, 5.356491237762384e-05f, 0.00011496873776195571f, 5.816936391056515e-05f, 0.00011016572534572333f, 6.617348844883963e-05f, 7.733329402981326e-05f, 9.480102016823366e-05f, 5.512521602213383e-05f, 0.0001874522858997807f, 0.00011395375622669235f, 4.6135770389810205e-05f, 7.28699960745871e-05f, 8.846205309964716e-05f, 0.0001403429632773623f, 8.989062189357355e-05f, 0.00027948085335083306f, 0.00012554749264381826f, 0.00010326077608624473f, 6.808782200096175e-05f, 8.57007471495308e-05f, 0.00011672203982016072f, 9.792764467420056e-05f, 5.465813592309132e-05f, 0.00013151731400284916f, 5.408898141467944e-05f, 0.0001311270461883396f, 0.0001590396132087335f, 8.045622234931216e-05f, 0.00016444030916318297f, 8.483617421006784e-05f, 0.000104803781141527f, 8.978449477581307e-05f, 9.098832379095256e-05f, 4.5307271648198366e-05f, 0.00012025748583255336f, 0.00012115234130760655f, 0.00011663768236758187f, 7.539128273492679e-05f, 9.53420385485515e-05f, 4.647924652090296e-05f, 5.803024396300316e-05f, 6.858412234578282e-05f, 0.00011227015784243122f, 6.972657138248906e-05f, 5.348670674720779e-05f, 8.67339622345753e-05f, 8.285295189125463e-05f, 3.416003528400324e-05f, 0.00014306194498203695f, 7.182645640568808e-05f, 7.997333887033165e-05f, 6.51397931505926e-05f, 6.466612103395164e-05f, 0.00011157013068441302f, 8.442797843599692e-05f, 9.036759001901373e-05f, 7.883770012995228e-05f, 4.0857954445527866e-05f, 8.571260696044192e-05f, 0.00011969412298640236f, 7.825039938325062e-05f, 0.0001098725842894055f, 6.969013338675722e-05f, 0.00012605215306393802f, 3.866135375574231e-05f, 0.00015231830184347928f, 7.297585398191586e-05f, 3.4563512599561363e-05f, 7.991807797225192e-05f, 6.388638576027006e-05f, 0.00020910694729536772f, 4.2936728277709335e-05f, 8.234729466494173e-05f, 0.00010217482486041263f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #159 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.003986581228673458f, 0.004265355411916971f, 0.00405023992061615f, 0.003894002176821232f, 0.004770467523485422f, 0.006517968140542507f, 0.0028859549202024937f, 0.007582823280245066f, 0.008036617189645767f, 0.006870428565889597f, 0.007251964416354895f, 0.006006656214594841f, 0.002795731881633401f, 0.007456622086465359f, 0.007226862944662571f, 0.009156133979558945f, 0.011699317954480648f, 0.005922253243625164f, 0.011935006827116013f, 0.003494794713333249f, 0.00957949087023735f, 0.00599547429010272f, 0.008594626560807228f, 0.012308595702052116f, 0.0033234863076359034f, 0.007458388805389404f, 0.005299712531268597f, 0.006591538432985544f, 0.00279097817838192f, 0.005901511292904615f, 0.01126986462622881f, 0.005774894263595343f, 0.006371113937348127f, 0.0049024298787117004f, 0.007083145435899496f, 0.007931267842650414f, 0.003854272421449423f, 0.008520376868546009f, 0.008391209878027439f, 0.0076475078240036964f, 0.008486940525472164f, 0.007300563622266054f, 0.006518820766359568f, 0.005416196305304766f, 0.0020357253961265087f, 0.004039425868541002f, 0.0038592456839978695f, 0.005067409947514534f, 0.002704393584281206f, 0.009009766392409801f, 0.0075386203825473785f, 0.0027376858051866293f, 0.00317312590777874f, 0.006567422766238451f, 0.005807327106595039f, 0.008049622178077698f, 0.003995547536760569f, 0.006356644444167614f, 0.013414678163826466f, 0.006899082101881504f, 0.009038809686899185f, 0.006940938998013735f, 0.004327190574258566f, 0.01334702130407095f, 0.004730137065052986f, 0.004220979288220406f, 0.005502942483872175f, 0.007137413136661053f, 0.005992077756673098f, 0.006203422322869301f, 0.015805769711732864f, 0.006643000058829784f, 0.016741082072257996f, 0.008580761030316353f, 0.005681533366441727f, 0.001433399855159223f, 0.006291293539106846f, 0.021499106660485268f, 0.009092300198972225f, 0.010097970254719257f, 0.0038666652981191874f, 0.013626877218484879f, 0.0015428599435836077f, 0.0036043229047209024f, 0.0070280213840305805f, 0.009912942536175251f, 0.011446019634604454f, 0.010288786143064499f, 0.0049148621037602425f, 0.0055427937768399715f, 0.0032764507923275232f, 0.009486708790063858f, 0.005912918131798506f, 0.0029149833135306835f, 0.004604875575751066f, 0.016671989113092422f, 0.009821872226893902f, 0.010020637884736061f, 0.002962188096717f, 0.010619275271892548f, 0.0029796722810715437f, 0.007594469003379345f, 0.008012717589735985f, 0.017671987414360046f, 0.010792922228574753f, 0.0011612457456067204f, 0.005928938277065754f, 0.00463944673538208f, 0.008048515766859055f, 0.005211780779063702f, 0.004118075128644705f, 0.007111347280442715f, 0.0033290947321802378f, 0.0052373469807207584f, 0.004607453942298889f, 0.004488830920308828f, 0.004606710281223059f, 0.008996855467557907f, 0.0030691390857100487f, 0.012146180495619774f, 0.0034916952718049288f, 0.004089586902409792f, 0.007209028583019972f, 0.010622133500874043f, 0.003458832623437047f, 0.008659918792545795f, 0.005830818321555853f, 0.18318727612495422f, 0.009691260755062103f, 0.014229022897779942f, 0.016230929642915726f, 0.002321495208889246f, 0.005865119397640228f, 0.008985960856080055f, 0.012499937787652016f, 0.003911823034286499f, 0.01454925537109375f, 0.003924067597836256f, 0.003600434632971883f, 0.002040113089606166f, 0.014523496851325035f, 0.002870710100978613f, 0.0044358293525874615f, 0.006418390665203333f, 0.001207095105201006f, 0.006780398078262806f, 0.007122736889868975f, 0.005257424432784319f, 0.006062102038413286f, 0.019986392930150032f, 0.0027939348947256804f, 0.004774697590619326f, 0.007736705243587494f, 0.010494733229279518f, 0.00849099736660719f, 0.0012754278723150492f, 0.0070600565522909164f, 0.008782629854977131f, 0.01554808858782053f, 0.006029572803527117f, 0.008596818894147873f, 0.006344845052808523f, 0.0031876948196440935f, 0.003716184990480542f, 0.005105137825012207f, 0.002011190867051482f, 0.0017161063151434064f, 0.004161303862929344f, 0.007659387309104204f, 0.006168346386402845f, 0.0044962638057768345f, 0.00403189193457365f, 0.0016749122878536582f, 0.00913112424314022f, 0.003351974068209529f, 0.0035429729614406824f, 0.005586015526205301f, 0.018582625314593315f, 0.005407437216490507f, 0.009255667217075825f, 0.007358316332101822f, 0.005844171158969402f, 0.007701467722654343f, 0.0031608683057129383f, 0.019264906644821167f, 0.007780506741255522f, 0.006871683988720179f, 0.009070298634469509f, 0.004991977941244841f, 0.004018355160951614f, 0.006490308791399002f, 0.007765051443129778f, 0.007056157570332289f, 0.0025807619094848633f, 0.004702460020780563f, 0.0014110880438238382f, 0.0036399648524820805f, 0.012897636741399765f, 0.0028401457238942385f, 0.019781917333602905f, 0.010179707780480385f, 0.004682526458054781f, 0.0042519401758909225f, 0.012136195786297321f, 0.007233080454170704f, 0.01102440059185028f, 0.0090734101831913f, 0.007725305389612913f, 0.0035558638628572226f, 0.01144507247954607f, 0.022218599915504456f, 0.009234985336661339f, 0.006783450022339821f, 0.001948460703715682f, 0.007579800207167864f, 0.0015347911976277828f, 0.008036362938582897f, 0.0038627067115157843f, 0.005389223340898752f, 0.012011048384010792f, 0.004152080975472927f, 0.0019574323669075966f, 0.011648508720099926f, 0.012594981119036674f, 0.007614612113684416f, 0.010976358316838741f, 0.00816228985786438f, 0.009660403244197369f, 0.006498024798929691f, 0.00822004210203886f, 0.011531050316989422f, 0.008025242015719414f, 0.006965884938836098f, 0.0020084248390048742f, 0.00714086415246129f, 0.008242735639214516f, 0.004161593969911337f, 0.005933578126132488f, 0.010801240801811218f, 0.004438138101249933f, 0.006986919324845076f, 0.00508681358769536f, 0.0044112359173595905f, 0.01238177064806223f, 0.006949361879378557f, 0.005898738745599985f, 0.009283707477152348f, 0.0044143060222268105f, 0.0033757882192730904f, 0.00907593872398138f, 0.0015842834254726768f, 0.013429033569991589f, 0.010209799744188786f, 0.0014485924039036036f, 0.008543891832232475f, 0.004180521704256535f, 0.009819074533879757f, 0.015282667241990566f, 0.005584838334470987f, 0.005511076655238867f, 0.008059040643274784f, 0.002883533015847206f, 0.0031367959454655647f, 0.005588970612734556f, 0.014254635199904442f, 0.003563378006219864f, 0.010806047357618809f, 0.006984042003750801f, 0.007953895255923271f, 0.005466955713927746f, 0.010594721883535385f, 0.012054994702339172f, 0.006099284626543522f, 0.006286675110459328f, 0.004018334671854973f, 0.0013322742888703942f, 0.006753504276275635f, 0.006616905331611633f, 0.00752987340092659f, 0.010540811344981194f, 0.0020375188905745745f, 0.0034300500992685556f, 0.011686010286211967f, 0.0037832544185221195f, 0.005466551054269075f, 0.003493217984214425f, 0.008963664062321186f, 0.005242681596428156f, 0.005152217112481594f, 0.005351724568754435f, 0.003356321481987834f, 0.007995998486876488f, 0.00675751268863678f, 0.0069473665207624435f, 0.006551441270858049f, 0.00674639455974102f, 0.006781953852623701f, 0.0028022744227200747f, 0.0020962455309927464f, 0.004261614754796028f, 0.008249045349657536f, 0.0186807531863451f, 0.005930028855800629f, 0.0021199325565248728f, 0.009491130709648132f, 0.005200052168220282f, 0.0049818591214716434f, 0.00451402273029089f, 0.008267806842923164f, 0.1805020123720169f, 0.008079704828560352f, 0.0028978220652788877f, 0.004257858265191317f, 0.012588941492140293f, 0.005427975673228502f, 0.010489578358829021f, 0.014231113716959953f, 0.01339210569858551f, 0.009728919714689255f, 0.015994537621736526f, 0.007224287372082472f, 0.007181243970990181f, 0.0067487140186131f, 0.010809380561113358f, 0.00986594520509243f, 0.003554128808900714f, 0.014426007866859436f, 0.0024851388297975063f, 0.009382425807416439f, 0.009525511413812637f, 0.013625465333461761f, 0.010744319297373295f, 0.006503599230200052f, 0.020398925989866257f, 0.0038926631677895784f, 0.009518614038825035f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #160 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(9.380191477248445e-05f, 0.00010036130697699264f, 9.52997652348131e-05f, 9.16235803742893e-05f, 0.00011224629997741431f, 0.00015336395881604403f, 6.790482439100742e-05f, 0.00017841937369666994f, 0.0001890968851512298f, 0.000161657138960436f, 0.00017063446284737438f, 0.0001413330901414156f, 6.578192551387474e-05f, 0.00017544993897899985f, 0.00017004384426400065f, 0.00021543845650739968f, 0.00027527808560989797f, 0.00013934713206253946f, 0.00028082370408810675f, 8.223046461353078e-05f, 0.00022539979545399547f, 0.00014106999151408672f, 0.0002022265107370913f, 0.0002896140213124454f, 7.819967868272215e-05f, 0.00017549149924889207f, 0.00012469911598600447f, 0.0001550950255477801f, 6.567007949342951e-05f, 0.0001388590899296105f, 0.00026517329388298094f, 0.00013587986177299172f, 0.00014990856288932264f, 0.00011535129306139424f, 0.00016666225565131754f, 0.0001866180682554841f, 9.068876534001902e-05f, 0.0002004794660024345f, 0.00019744024029932916f, 0.00017994135851040483f, 0.00019969271670561284f, 0.00017177796689793468f, 0.00015338402590714395f, 0.00012743991101160645f, 4.789942249772139e-05f, 9.504531772108749e-05f, 9.080578456632793e-05f, 0.00011923317651962861f, 6.363278953358531e-05f, 0.000211994512937963f, 0.00017737930465955287f, 6.441614095820114e-05f, 7.466178794857115e-05f, 0.0001545276027172804f, 0.00013664299331139773f, 0.0001894028828246519f, 9.401288843946531e-05f, 0.00014956810628063977f, 0.00031563948141410947f, 0.00016233134374488145f, 0.00021267788542900234f, 0.00016331621736753732f, 0.00010181625111727044f, 0.00031404756009578705f, 0.00011129734775749967f, 9.931716340361163e-05f, 0.00012948100629728287f, 0.00016793914255686104f, 0.00014099007239565253f, 0.0001459628838347271f, 0.00037190047441981733f, 0.0001563058904139325f, 0.0003939078305847943f, 0.00020190025679767132f, 0.00013368313375394791f, 3.3727057598298416e-05f, 0.0001480304345022887f, 0.0005058613605797291f, 0.0002139364805771038f, 0.00023759930627420545f, 9.098036389332265e-05f, 0.0003206324181519449f, 3.6302586522651836e-05f, 8.480760152451694e-05f, 0.00016536521434318274f, 0.00023324570793192834f, 0.0002693181158974767f, 0.00024208909599110484f, 0.00011564381566131487f, 0.00013041867350693792f, 7.709296187385917e-05f, 0.00022321668802760541f, 0.0001391274854540825f, 6.858784763608128e-05f, 0.00010835001739906147f, 0.00039228209061548114f, 0.0002311028802068904f, 0.00023577972024213523f, 6.969854439375922e-05f, 0.00024986531934700906f, 7.010993431322277e-05f, 0.00017869338626042008f, 0.0001885345409391448f, 0.0004158114898018539f, 0.00025395111879333854f, 2.732342909439467e-05f, 0.0001395044382661581f, 0.00010916345490841195f, 0.00018937684944830835f, 0.0001226301392307505f, 9.68958847806789e-05f, 0.00016732582298573107f, 7.83316427259706e-05f, 0.00012323170085437596f, 0.00010841068433364853f, 0.00010561955423327163f, 0.00010839318565558642f, 0.00021169072715565562f, 7.221503619803116e-05f, 0.00028579248464666307f, 8.215753769036382e-05f, 9.622557263355702e-05f, 0.00016962421068456024f, 0.0002499325491953641f, 8.138429984683171e-05f, 0.00020376280008349568f, 0.00013719573325943202f, 0.004310288932174444f, 0.00022802967578172684f, 0.0003348005411680788f, 0.00038190424675121903f, 5.4623418691335246e-05f, 0.0001380028115818277f, 0.0002114343806169927f, 0.0002941161801572889f, 9.20428938115947e-05f, 0.00034233543556183577f, 9.233100718120113e-05f, 8.47161136334762e-05f, 4.800266106030904e-05f, 0.0003417293482925743f, 6.754611968062818e-05f, 0.00010437245509820059f, 0.00015102095494512469f, 2.8402238967828453e-05f, 0.00015953878755681217f, 0.00016759381105657667f, 0.00012370409967843443f, 0.00014263769844546914f, 0.0004702680744230747f, 6.573964492417872e-05f, 0.00011234582780161873f, 0.00018204012303613126f, 0.00024693491286598146f, 0.00019978817726951092f, 3.001006734848488e-05f, 0.0001661189744481817f, 0.00020665011834353209f, 0.0003658373898360878f, 0.0001418722968082875f, 0.00020227809727657586f, 0.00014929047028999776f, 7.500458741560578e-05f, 8.743965008761734e-05f, 0.00012012089428026229f, 4.732214074465446e-05f, 4.0378974517807364e-05f, 9.791303455131128e-05f, 0.00018022088625002652f, 0.00014513757196255028f, 0.00010579444642644376f, 9.486804628977552e-05f, 3.9409700548276305e-05f, 0.00021484999160747975f, 7.88699762779288e-05f, 8.336407336173579e-05f, 0.0001314356632065028f, 0.00043723825365304947f, 0.0001272338122362271f, 0.00021778041264042258f, 0.00017313685384579003f, 0.00013750990910921246f, 0.00018121101311407983f, 7.437337626470253e-05f, 0.0004532919265329838f, 0.00018307074788026512f, 0.00016168667934834957f, 0.00021341879619285464f, 0.00011745830852305517f, 9.454953396925703e-05f, 0.00015271315351128578f, 0.00018270709551870823f, 0.00016602723917458206f, 6.072381074773148e-05f, 0.00011064612044719979f, 3.320207179058343e-05f, 8.564623567508534e-05f, 0.00030347381834872067f, 6.682695675408468e-05f, 0.0004654568911064416f, 0.00023952254559844732f, 0.0001101770976674743f, 0.00010004565410781652f, 0.0002855575585272163f, 0.00017019013466779143f, 0.0002593976678326726f, 0.00021349200687836856f, 0.000181771902134642f, 8.366738620679826e-05f, 0.0002692958223633468f, 0.0005227905930951238f, 0.00021729378204327077f, 0.00015961058670654893f, 4.5846136345062405e-05f, 0.00017834824393503368f, 3.611273496062495e-05f, 0.0001890908897621557f, 9.088721708394587e-05f, 0.0001268052583327517f, 0.00028261292027309537f, 9.769602183951065e-05f, 4.605723370332271e-05f, 0.00027408255846239626f, 0.00029635248938575387f, 0.000179167342139408f, 0.0002582672459539026f, 0.00019205387798137963f, 0.00022730360797140747f, 0.0001528947032056749f, 0.00019341276492923498f, 0.0002713188296183944f, 0.00018882923177443445f, 0.00016390318342018872f, 4.725705730379559e-05f, 0.00016802034224383533f, 0.00019394671835470945f, 9.791985939955339e-05f, 0.0001396136067342013f, 0.00025414684205316007f, 0.00010442677739774808f, 0.0001643981086090207f, 0.00011968973558396101f, 0.00010379379091318697f, 0.0002913357748184353f, 0.00016351439990103245f, 0.00013879385369364172f, 0.0002184401819249615f, 0.00010386602662038058f, 7.94303123257123e-05f, 0.00021355150965973735f, 3.727725925273262e-05f, 0.0003159772604703903f, 0.00024023058358579874f, 3.4084529033862054e-05f, 0.00020103275892324746f, 9.836522076511756e-05f, 0.00023103704734239727f, 0.0003595921734813601f, 0.00013140795635990798f, 0.00012967239308636636f, 0.0001896244939416647f, 6.784783909097314e-05f, 7.380696479231119e-05f, 0.00013150519225746393f, 0.00033540319418534636f, 8.384419197682291e-05f, 0.00025425993953831494f, 0.00016433039854746312f, 0.00018715047917794436f, 0.00012863425945397466f, 0.00024928757920861244f, 0.00028364695026539266f, 0.000143512588692829f, 0.00014792177535127848f, 9.454905375605449e-05f, 3.1347630283562467e-05f, 0.0001589059829711914f, 0.0001556918869027868f, 0.00017717349692247808f, 0.0002480190887581557f, 4.794162305188365e-05f, 8.070706098806113e-05f, 0.000274964957498014f, 8.901775436243042e-05f, 0.00012862472794950008f, 8.219336450565606e-05f, 0.0002109097404172644f, 0.00012335721112322062f, 0.00012122863699914888f, 0.00012592293205671012f, 7.89722689660266e-05f, 0.00018814114446286112f, 0.00015900030848570168f, 0.00016346745542250574f, 0.00015415156667586416f, 0.0001587386941537261f, 0.0001595753856236115f, 6.593587022507563e-05f, 4.932342562824488e-05f, 0.00010027328971773386f, 0.00019409519154578447f, 0.0004395471478346735f, 0.00013953009329270571f, 4.9880767619470134e-05f, 0.00022332073422148824f, 0.00012235417671035975f, 0.00011722021736204624f, 0.00010621230467222631f, 0.0001945366384461522f, 0.004247106146067381f, 0.0001901107025332749f, 6.818404654040933e-05f, 0.00010018490138463676f, 0.0002962104044854641f, 0.00012771708134096116f, 0.0002468136081006378f, 0.00033484972664155066f, 0.00031510836561210454f, 0.00022891575645189732f, 0.00037634206819348037f, 0.0001699832355370745f, 0.00016897045134101063f, 0.0001587932783877477f, 0.00025433837436139584f, 0.0002321398933418095f, 8.362656080862507e-05f, 0.0003394354716874659f, 5.8473855460761115e-05f, 0.00022076295863371342f, 0.00022412968974094838f, 0.0003205991815775633f, 0.00025280751287937164f, 0.00015302587416954339f, 0.00047997472574934363f, 9.159207547781989e-05f, 0.0002239673922304064f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #161 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.006004514172673225f, 0.006672288756817579f, 0.0075259641744196415f, 0.011787718161940575f, 0.010811428539454937f, 0.011334644630551338f, 0.008355858735740185f, 0.006288899574428797f, 0.016605764627456665f, 0.007369942497462034f, 0.01625916175544262f, 0.017795192077755928f, 0.00704930629581213f, 0.010395390912890434f, 0.021041570231318474f, 0.006864215712994337f, 0.008627905510365963f, 0.009934168308973312f, 0.01113484613597393f, 0.011730756610631943f, 0.011761287227272987f, 0.01130280178040266f, 0.009016536176204681f, 0.007169374264776707f, 0.01562911830842495f, 0.009375156834721565f, 0.00883254874497652f, 0.022451287135481834f, 0.009491574950516224f, 0.013603302650153637f, 0.013262934051454067f, 0.019815586507320404f, 0.008827341720461845f, 0.011305060237646103f, 0.008206081576645374f, 0.014803512021899223f, 0.005457728169858456f, 0.023198174312710762f, 0.005911354906857014f, 0.017302898690104485f, 0.008570591919124126f, 0.017877688631415367f, 0.004735969007015228f, 0.008470072411000729f, 0.012854507192969322f, 0.018218044191598892f, 0.006430936977267265f, 0.008358840830624104f, 0.010580864734947681f, 0.007810387294739485f, 0.012674505822360516f, 0.013405994512140751f, 0.014385713264346123f, 0.012731337919831276f, 0.010558334179222584f, 0.00998570118099451f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #162 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_62_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 56,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012760052049998194f, 0.0001417912426404655f, 0.00015993250417523086f, 0.00025049803662113845f, 0.00022975113824941218f, 0.00024086987832561135f, 0.00017756839224603027f, 0.0001336439308943227f, 0.00035288522485643625f, 0.00015661692305002362f, 0.0003455196274444461f, 0.0003781614650506526f, 0.00014980316336732358f, 0.0002209100202890113f, 0.00044714947580359876f, 0.00014586983888875693f, 0.0001833496062317863f, 0.0002111086796503514f, 0.00023662400781176984f, 0.000249287550104782f, 0.00024993636179715395f, 0.00024019319971557707f, 0.00019160829833708704f, 0.00015235469618346542f, 0.00033213073038496077f, 0.0001992292673094198f, 0.00018769843154586852f, 0.0004771070380229503f, 0.00020170323841739446f, 0.0002890806063078344f, 0.00028184751863591373f, 0.00042109639616683125f, 0.00018758776423055679f, 0.00024024119193200022f, 0.00017438552458770573f, 0.0003145859809592366f, 0.00011598090350162238f, 0.0004929789574816823f, 0.000125620819744654f, 0.00036769986036233604f, 0.00018213164003100246f, 0.00037991456338204443f, 0.00010064296657219529f, 0.0001799955207388848f, 0.0002731681161094457f, 0.000387147389119491f, 0.00013666233280673623f, 0.0001776317658368498f, 0.0002248514792881906f, 0.00016597671492490917f, 0.00026934294146485627f, 0.0002848876465577632f, 0.00030570742092095315f, 0.0002705506922211498f, 0.00022437269217334688f, 0.00021220379858277738f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #163 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0006649402785114944f, 0.0007016371819190681f, 0.0006823450676165521f, 0.00038752934779040515f, 0.0010318420827388763f, 0.001696089399047196f, 0.0012214476009830832f, 0.0004119074728805572f, 0.000776986125856638f, 0.0006520307506434619f, 0.0007898996700532734f, 0.0005561304278671741f, 0.000725434860214591f, 0.0007528444984927773f, 0.000570882810279727f, 0.0007315912516787648f, 0.0007319690776057541f, 0.0005577296251431108f, 0.0006917889695614576f, 0.0007486868998967111f, 0.0006801199051551521f, 0.0007849588291719556f, 0.0006584518123418093f, 0.0004536891356110573f, 0.0008272877312265337f, 0.0010672510834410787f, 0.00041948974831029773f, 0.0007390722166746855f, 0.0004609463212545961f, 0.0006863683229312301f, 0.0008935623336583376f, 0.0007655819645151496f, 0.0008401668746955693f, 0.000964007806032896f, 0.0006039122818037868f, 0.0007070221472531557f, 0.0006653124000877142f, 0.0010880768531933427f, 0.0006344556459225714f, 0.0005510462215170264f, 0.0006192507571540773f, 0.0006442319136112928f, 0.000798747583758086f, 0.0007824029889889061f, 0.0007424806826747954f, 0.0005568764754571021f, 0.0008408682770095766f, 0.0009031985537149012f, 0.0007894692244008183f, 0.0006747341831214726f, 0.000268580304691568f, 0.0008293255814351141f, 0.0006266394047997892f, 0.0009253064636141062f, 0.0004643349093385041f, 0.0008749538101255894f, 0.0007463135989382863f, 0.0007135902997106314f, 0.0007052310975268483f, 0.0005086322780698538f, 0.0006267601856961846f, 0.000617068784777075f, 0.0005208669463172555f, 0.0005122447619214654f, 0.0009067363571375608f, 0.0006690305308438838f, 0.0007627886370755732f, 0.00032541804830543697f, 0.0008087654714472592f, 0.001101383357308805f, 0.0008099450496956706f, 0.0005581793375313282f, 0.0005641504540108144f, 0.0004897693870589137f, 0.0009046258055604994f, 0.0008677614969201386f, 0.0006496286951005459f, 0.0006111497059464455f, 0.0005427730502560735f, 0.0009012096561491489f, 0.0008865157142281532f, 0.0010000335751101375f, 0.0014974242076277733f, 0.0010252241045236588f, 0.0005524339503608644f, 0.0005018217489123344f, 0.0006486981292255223f, 0.0006214958266355097f, 0.0004932566662319005f, 0.0008064733119681478f, 0.0007182647241279483f, 0.0007632864871993661f, 0.0005514384247362614f, 0.000708598701748997f, 0.00079065264435485f, 0.0006732718902640045f, 0.0007120525115169585f, 0.0008881025132723153f, 0.000682998972479254f, 0.0005107492324896157f, 0.0005839763325639069f, 0.0006604923983104527f, 0.0010148006258532405f, 0.000852219935040921f, 0.0007370282546617091f, 0.0009174800361506641f, 0.0006176052265800536f, 0.000966439547482878f, 0.0007404366042464972f, 0.0008296563173644245f, 0.0003971608530264348f, 0.0007663253927603364f, 0.0005548582412302494f, 0.0006955345743335783f, 0.0005433241021819413f, 0.000794643652625382f, 0.0007300672004930675f, 0.0009290980524383485f, 0.0008731738198548555f, 0.0007790510426275432f, 0.0007122164824977517f, 0.0006496662390418351f, 0.0006310648750513792f, 0.0006980012403801084f, 0.0011033689370378852f, 0.0008455868810415268f, 0.001059798989444971f, 0.0008595704566687346f, 0.0007392800180241466f, 0.0005228102672845125f, 0.000836299208458513f, 0.0005055915680713952f, 0.000738660164643079f, 0.0005357160698622465f, 0.0003413863596506417f, 0.000769502017647028f, 0.0006515212589874864f, 0.0006481357850134373f, 0.0009932483080774546f, 0.0005974641535431147f, 0.0005079153925180435f, 0.0006440321449190378f, 0.0011980341514572501f, 0.0007443932117894292f, 0.0007645730511285365f, 0.0008629985968582332f, 0.0007776675629429519f, 0.0005717951571568847f, 0.0008317836909554899f, 0.0010040400084108114f, 0.00048461832921020687f, 0.0007265011081472039f, 0.0009660912328399718f, 0.0006104922504164279f, 0.000715815054718405f, 0.0005773053853772581f, 0.0005395496846176684f, 0.0007730299257673323f, 0.0008862834656611085f, 0.0006451529334299266f, 0.0005049113533459604f, 0.0008896293002180755f, 0.0010158185614272952f, 0.0005213829572312534f, 0.0006666505942121148f, 0.0004966082633472979f, 0.0012062093010172248f, 0.000834634352941066f, 0.0007221339619718492f, 0.0009476802661083639f, 0.0006136801675893366f, 0.0009166725794784725f, 0.0009257923229597509f, 0.00081584881991148f, 0.0005824693944305182f, 0.000789992802310735f, 0.0007081245421431959f, 0.0006237251218408346f, 0.0006963793421164155f, 0.0007158592343330383f, 0.0006192934815771878f, 0.0012883666204288602f, 0.0007644848083145916f, 0.0011048807064071298f, 0.0006988706300035119f, 0.001664515002630651f, 0.0006124029750935733f, 0.0005761178326793015f, 0.0005902366247028112f, 0.0007354816189035773f, 0.000516422267537564f, 0.0005960081471130252f, 0.0006981016485951841f, 0.0004966252599842846f, 0.0008808944257907569f, 0.0006731220637448132f, 0.0023691197857260704f, 0.0006153880385681987f, 0.0006232004961930215f, 0.0006243691314011812f, 0.0008073897333815694f, 0.0010309397475793958f, 0.0008432955364696681f, 0.0006954643176868558f, 0.0006461467128247023f, 0.001237629447132349f, 0.0008223797776736319f, 0.0005952493520453572f, 0.0005784654640592635f, 0.00047910751891322434f, 0.0007281992584466934f, 0.0005200597806833684f, 0.0004774031403940171f, 0.0006553486455231905f, 0.0005547984619624913f, 0.0005771591677330434f, 0.0008327788673341274f, 0.0006448639906011522f, 0.00036707971594296396f, 0.0013325391337275505f, 0.0006791321211494505f, 0.0008541470160707831f, 0.0006411985377781093f, 0.0006564127979800105f, 0.0007730436627753079f, 0.0007835862343199551f, 0.0006455513648688793f, 0.000928052410017699f, 0.0010667558526620269f, 0.0010185865685343742f, 0.0014743218198418617f, 0.0009656815673224628f, 0.0007533603347837925f, 0.0006726727588102221f, 0.0008569830097258091f, 0.0005153596284799278f, 0.0008041919791139662f, 0.000872890290338546f, 0.0008216716232709587f, 0.0005795761244371533f, 0.0006649067508988082f, 0.0007662393618375063f, 0.000752572319470346f, 0.0005786336841993034f, 0.0005732288700528443f, 0.0009738713270053267f, 0.0010180409299209714f, 0.0007430104305967689f, 0.00079192133853212f, 0.0010527493432164192f, 0.0007440099725499749f, 0.0009008998749777675f, 0.0007418413879349828f, 0.0009428259800188243f, 0.0005554371164180338f, 0.0006758459494449198f, 0.0005959613481536508f, 0.0006964536150917411f, 0.0007224155706353486f, 0.000700930948369205f, 0.0007383791962638497f, 0.0006590168341062963f, 0.0007068226113915443f, 0.0005311210406944156f, 0.0005404299590736628f, 0.0008274185238406062f, 0.0006979000754654408f, 0.0007115774787962437f, 0.00045073599903844297f, 0.0010233415523543954f, 0.0008540228009223938f, 0.000854324025567621f, 0.0006314110360108316f, 0.0009409774793311954f, 0.0006152119603939354f, 0.0006033758982084692f, 0.000726023456081748f, 0.0009334191563539207f, 0.000657502852845937f, 0.0008735554874874651f, 0.0005718721076846123f, 0.0005827210261486471f, 0.0009951452957466245f, 0.0011103133438155055f, 0.000857610662933439f, 0.0008587014162912965f, 0.0007484618108719587f, 0.0005938700633123517f, 0.0010011321865022182f, 0.0005589908105321229f, 0.0011637533316388726f, 0.000691585591994226f, 0.0006090041715651751f, 0.0004874364531133324f, 0.0008569139172323048f, 0.0006685436819680035f, 0.0005932959029451013f, 0.0007423193892464042f, 0.0007524426328018308f, 0.0005995317478664219f, 0.0010298789711669087f, 0.0005969707854092121f, 0.0013417761074379086f, 0.0011379476636648178f, 0.0008261798648163676f, 0.0005103235016576946f, 0.0008949760813266039f, 0.0006799369584769011f, 0.0005645584315061569f, 0.0008377734338864684f, 0.000847703660838306f, 0.000654683681204915f, 0.0007077237823978066f, 0.0007923412485979497f, 0.000655554817058146f, 0.0006246514385566115f, 0.0006450929795391858f, 0.0006529766251333058f, 0.000604666885919869f, 0.0006776911322958767f, 0.000966912426520139f, 0.00054059864487499f, 0.0006470021326094866f, 0.0009280264494009316f, 0.0014496106887236238f, 0.0006949928938411176f, 0.0004989245207980275f, 0.0007888039690442383f, 0.00099334423430264f, 0.0007020909106358886f, 0.0005758300540037453f, 0.0006072219694033265f, 0.00039745241519995034f, 0.0006620276835747063f, 0.0005242477636784315f, 0.0007953707245178521f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #164 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00010815727728186175f, 0.00011412629100959748f, 0.000110988286905922f, 6.303440750343725e-05f, 0.0001678364642430097f, 0.0002758810296654701f, 0.00019867715309374034f, 6.699968798784539e-05f, 0.00012638233602046967f, 0.00010605745046632364f, 0.00012848281767219305f, 9.04585758689791e-05f, 0.00011799715139204636f, 0.0001224555162480101f, 9.285815758630633e-05f, 0.00011899853416252881f, 0.0001190599869005382f, 9.071869862964377e-05f, 0.00011252440890530124f, 0.00012177925964351743f, 0.00011062635167036206f, 0.0001276791444979608f, 0.0001071018778020516f, 7.379577436950058e-05f, 0.00013456425222102553f, 0.00017359599587507546f, 6.823299918323755e-05f, 0.00012021536531392485f, 7.497620390495285e-05f, 0.00011164270108565688f, 0.00014534428191836923f, 0.00012452735973056406f, 0.000136659131385386f, 0.00015680273645557463f, 9.8230637377128e-05f, 0.00011500219261506572f, 0.00010821780597325414f, 0.0001769834489095956f, 0.00010319873399566859f, 8.963159780250862e-05f, 0.00010072554869111627f, 0.0001047889090841636f, 0.0001299219875363633f, 0.00012726342538371682f, 0.00012076977145625278f, 9.057992429006845e-05f, 0.00013677321840077639f, 0.00014691168325953186f, 0.00012841279385611415f, 0.00010975032637361437f, 4.368650115793571e-05f, 0.00013489571574609727f, 0.00010192736226599663f, 0.00015050769434310496f, 7.552737952210009e-05f, 0.0001423174689989537f, 0.00012139322643633932f, 0.00011607055057538673f, 0.00011471086327219382f, 8.273266575997695e-05f, 0.00010194700735155493f, 0.00010037063475465402f, 8.472272020298988e-05f, 8.332026482094079e-05f, 0.0001474871241953224f, 0.00010882258357014507f, 0.00012407300528138876f, 5.2931565733160824e-05f, 0.00013155146734789014f, 0.0001791478571249172f, 0.00013174333435017616f, 9.079184383153915e-05f, 9.176308958558366e-05f, 7.966448174556717e-05f, 0.00014714382996317f, 0.0001411475968779996f, 0.00010566673881839961f, 9.940785821527243e-05f, 8.828590216580778e-05f, 0.00014658817963209003f, 0.00014419810031540692f, 0.00016266258899122477f, 0.00024356671201530844f, 0.00016676000086590648f, 8.985731983557343e-05f, 8.16248866613023e-05f, 0.00010551537707215175f, 0.00010109072900377214f, 8.023171540116891e-05f, 0.00013117863272782415f, 0.00011683087359415367f, 0.00012415398668963462f, 8.969539339886978e-05f, 0.00011525862646522f, 0.00012860528659075499f, 0.0001095124680432491f, 0.00011582041770452634f, 0.00014445620763581246f, 0.00011109464685432613f, 8.307700045406818e-05f, 9.498791041551158e-05f, 0.00010743379243649542f, 0.00016506455722264946f, 0.00013861965271644294f, 0.00011988289770670235f, 0.00014923466369509697f, 0.00010045788803836331f, 0.0001571982866153121f, 0.00012043728929711506f, 0.00013494951417669654f, 6.460104486905038e-05f, 0.00012464828614611179f, 9.025164763443172e-05f, 0.00011313365394016728f, 8.837553468765691e-05f, 0.00012925444752909243f, 0.00011875063501065597f, 0.00015112441906239837f, 0.0001420279440935701f, 0.0001267182087758556f, 0.00011584708408918232f, 0.00010567284334683791f, 0.00010264720185659826f, 0.00011353487934684381f, 0.00017947082233149558f, 0.00013754073006566614f, 0.00017238386499229819f, 0.00013981526717543602f, 0.00012024916213704273f, 8.503881690558046e-05f, 0.00013603002298623323f, 8.223807526519522e-05f, 0.00012014833919238299f, 8.713803981663659e-05f, 5.55289261683356e-05f, 0.0001251649810001254f, 0.0001059745773090981f, 0.00010542390373302624f, 0.0001615589135326445f, 9.718180081108585e-05f, 8.261606126325205e-05f, 0.00010475641465745866f, 0.00019486878591123968f, 0.00012108086230000481f, 0.00012436325778253376f, 0.00014037286746315658f, 0.00012649317795876414f, 9.300655801780522e-05f, 0.00013529554416891187f, 0.00016331426741089672f, 7.88266261224635e-05f, 0.00011817058111773804f, 0.00015714162145741284f, 9.930091619025916e-05f, 0.00011643242032732815f, 9.390283230459318e-05f, 8.776160393608734e-05f, 0.00012573882122524083f, 0.00014416032354347408f, 0.00010493872105143964f, 8.212742977775633e-05f, 0.00014470455062109977f, 0.0001652301289141178f, 8.48066556500271e-05f, 0.00010843547352124006f, 8.077687380136922e-05f, 0.00019619853992480785f, 0.00013575922639574856f, 0.00011746023665182292f, 0.00015414695371873677f, 9.981945186154917e-05f, 0.00014910333266016096f, 0.00015058672579471022f, 0.0001327036297880113f, 9.474279795540497e-05f, 0.00012849796621594578f, 0.00011518150131450966f, 0.00010145333362743258f, 0.00011327106039971113f, 0.00011643960897345096f, 0.00010073249723063782f, 0.0002095620147883892f, 0.0001243489095941186f, 0.00017971672059502453f, 0.00011367628758307546f, 0.0002707452222239226f, 9.9611708719749e-05f, 9.370967018185183e-05f, 9.600619523553178e-05f, 0.00011963132419623435f, 8.399975922657177e-05f, 9.69449756667018e-05f, 0.00011355120659573004f, 8.077963866526261e-05f, 0.00014328375982586294f, 0.0001094881008611992f, 0.00038535421481356025f, 0.00010009724792325869f, 0.00010136800119653344f, 0.00010155808558920398f, 0.0001313276879955083f, 0.00016768969362601638f, 0.0001371680264128372f, 0.00011312223068671301f, 0.00010510037100175396f, 0.00020130924531258643f, 0.00013376593415159732f, 9.682154632173479e-05f, 9.409152698935941e-05f, 7.793024997226894e-05f, 0.00011844679829664528f, 8.459143282379955e-05f, 7.765302143525332e-05f, 0.00010659713007044047f, 9.024192695505917e-05f, 9.387905447511002e-05f, 0.00013545741967391223f, 0.00010489172564120963f, 5.9708130720537156e-05f, 0.00021674699382856488f, 0.00011046567669836804f, 0.00013893310097046196f, 0.0001042955118464306f, 0.00010677021782612428f, 0.000125741062220186f, 0.0001274558890145272f, 0.00010500352800590917f, 0.00015095433627720922f, 0.00017351543647237122f, 0.00016568036517128348f, 0.00023980895639397204f, 0.00015707498823758215f, 0.00012253942259121686f, 0.00010941502114292234f, 0.0001393943966832012f, 8.382691885344684e-05f, 0.0001308075588895008f, 0.00014198182907421142f, 0.00013365074119064957f, 9.427218901691958e-05f, 0.00010815182031365111f, 0.0001246342872036621f, 0.0001224112493218854f, 9.411889186594635e-05f, 9.323975973529741e-05f, 0.00015840711421333253f, 0.00016559161304030567f, 0.00012085594062227756f, 0.00012881164730060846f, 0.0001712371886242181f, 0.00012101852189516649f, 0.0001465377863496542f, 0.00012066579074598849f, 0.00015335736679844558f, 9.034580580191687e-05f, 0.00010993116302415729f, 9.693735773907974e-05f, 0.00011328314576530829f, 0.00011750603880500421f, 0.00011401141091482714f, 0.0001201026389026083f, 0.00010719378769863397f, 0.00011496973456814885f, 8.639062434667721e-05f, 8.790478750597686e-05f, 0.00013458551256917417f, 0.00011351842113072053f, 0.00011574314703466371f, 7.33154229237698e-05f, 0.00016645379946567118f, 0.00013891288836020976f, 0.00013896188465878367f, 0.00010270350321661681f, 0.00015305669512599707f, 0.00010006860975408927f, 9.814339136937633e-05f, 0.00011809288844233379f, 0.0001518272765679285f, 0.00010694752563722432f, 0.00014209002256393433f, 9.301907266490161e-05f, 9.478372521698475e-05f, 0.0001618674723431468f, 0.00018060037109535187f, 0.00013949649292044342f, 0.00013967390987090766f, 0.00012174264702480286f, 9.659719944465905e-05f, 0.0001628412865102291f, 9.092383697861806e-05f, 0.00018929276848211884f, 0.00011249132512602955f, 9.905886690830812e-05f, 7.928501145215705e-05f, 0.0001393831626046449f, 0.0001087433920474723f, 9.65038052527234e-05f, 0.00012074354162905365f, 0.0001223901635967195f, 9.751811012392864e-05f, 0.00016751715156715363f, 9.710155427455902e-05f, 0.0002182494499720633f, 0.00018509529763832688f, 0.00013438404130283743f, 8.3007755165454e-05f, 0.0001455742312828079f, 0.00011059659300372005f, 9.182945359498262e-05f, 0.0001362698239972815f, 0.00013788504293188453f, 0.00010648896568454802f, 0.00011511631601024419f, 0.0001288799539906904f, 0.00010663066495908424f, 0.00010160401143366471f, 0.00010492897126823664f, 0.00010621130059007555f, 9.835337550612167e-05f, 0.00011023128899978474f, 0.00015727519348729402f, 8.793222514213994e-05f, 0.00010523950913920999f, 0.000150950116221793f, 0.00023578951368108392f, 0.00011304554936941713f, 8.115363016258925e-05f, 0.000128304585814476f, 0.00016157451318576932f, 0.00011420009104767814f, 9.366286394651979e-05f, 9.876897820504382e-05f, 6.464846956077963e-05f, 0.00010768351785372943f, 8.527263707946986e-05f, 0.00012937271094415337f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #165 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.007026305887848139f, 0.0036353529430925846f, 0.0043481579050421715f, 0.008057111874222755f, 0.003183589316904545f, 0.0027583667542785406f, 0.003780241822823882f, 0.007726652547717094f, 0.004968347959220409f, 0.005624198820441961f, 0.004172229673713446f, 0.0031316557433456182f, 0.004894586279988289f, 0.002193683059886098f, 0.0642755776643753f, 0.0040529025718569756f, 0.004861879162490368f, 0.005475187674164772f, 0.003523684572428465f, 0.003793739015236497f, 0.004936523269861937f, 0.003193435026332736f, 0.004381969105452299f, 0.011412026360630989f, 0.002301872009411454f, 0.005593509413301945f, 0.005368095822632313f, 0.0021228219848126173f, 0.005094510968774557f, 0.003938939888030291f, 0.003465060144662857f, 0.0058786217123270035f, 0.003438799176365137f, 0.0043287742882966995f, 0.0038222346920520067f, 0.006653220392763615f, 0.003924541641026735f, 0.002440341981127858f, 0.0033816045615822077f, 0.003662097966298461f, 0.0040904865600168705f, 0.010454904288053513f, 0.005960528273135424f, 0.0028180594090372324f, 0.004318201914429665f, 0.005548769608139992f, 0.004094368778169155f, 0.0051822783425450325f, 0.005441732704639435f, 0.006758775562047958f, 0.02370382845401764f, 0.004296198952943087f, 0.005581038072705269f, 0.0017924278508871794f, 0.0034576384350657463f, 0.0032016041222959757f, 0.0031843273900449276f, 0.006726375315338373f, 0.0030015420634299517f, 0.0043002404272556305f, 0.003664026502519846f, 0.006434028036892414f, 0.004881277680397034f, 0.0046693491749465466f, 0.0035531490575522184f, 0.004411450587213039f, 0.0056914035230875015f, 0.0163893885910511f, 0.002642915118485689f, 0.004250579979270697f, 0.003994683735072613f, 0.004687989596277475f, 0.004319107159972191f, 0.004353510681539774f, 0.0020532789640128613f, 0.01010042242705822f, 0.004713099449872971f, 0.00464484840631485f, 0.008694387041032314f, 0.004849503748118877f, 0.002649323083460331f, 0.0037551983259618282f, 0.006822052877396345f, 0.0034535008016973734f, 0.0042635295540094376f, 0.0030570910312235355f, 0.0038581560365855694f, 0.0031596976332366467f, 0.007940893992781639f, 0.0019640843383967876f, 0.008930223993957043f, 0.005371318198740482f, 0.005744413007050753f, 0.0029245803598314524f, 0.007753543555736542f, 0.006413228809833527f, 0.005709158722311258f, 0.0025956472381949425f, 0.002790553495287895f, 0.003386574564501643f, 0.004355667624622583f, 0.004137834068387747f, 0.003153326688334346f, 0.0047872671857476234f, 0.006252498831599951f, 0.004070739261806011f, 0.004481947980821133f, 0.003659911686554551f, 0.00381884234957397f, 0.0030711940489709377f, 0.006808190140873194f, 0.0028181946836411953f, 0.006303002592176199f, 0.004351021721959114f, 0.004787645302712917f, 0.0022095858585089445f, 0.003434413345530629f, 0.005142256151884794f, 0.003685382893308997f, 0.004150067456066608f, 0.005020297132432461f, 0.0045674992725253105f, 0.004001356195658445f, 0.0018157820450142026f, 0.0035077587235718966f, 0.002471582032740116f, 0.0031753829680383205f, 0.0023147377651184797f, 0.004188192542642355f, 0.0050335838459432125f, 0.0016429719980806112f, 0.0066215344704687595f, 0.007094143889844418f, 0.003244758350774646f, 0.017853837460279465f, 0.0021608907263725996f, 0.00404993025586009f, 0.004498165566474199f, 0.00237607816234231f, 0.005129439756274223f, 0.0048299371264874935f, 0.0023331379052251577f, 0.001702204579487443f, 0.0037458916194736958f, 0.003990980330854654f, 0.004722705576568842f, 0.002407197142019868f, 0.006313357502222061f, 0.0035650404170155525f, 0.005057231057435274f, 0.006367780268192291f, 0.005226158536970615f, 0.0018044125754386187f, 0.005949866957962513f, 0.004910432267934084f, 0.0026581089477986097f, 0.004516463726758957f, 0.00603885855525732f, 0.0037233096081763506f, 0.005230995826423168f, 0.005408903118222952f, 0.002575879218056798f, 0.0025459090247750282f, 0.006581171415746212f, 0.004278930835425854f, 0.0055853757075965405f, 0.0035550864413380623f, 0.003986450377851725f, 0.004394447430968285f, 0.0031657994259148836f, 0.0022170848678797483f, 0.0035492312163114548f, 0.004178149159997702f, 0.00456454511731863f, 0.004653145093470812f, 0.0027996054850518703f, 0.0059822057373821735f, 0.0037832113448530436f, 0.005278708413243294f, 0.00497553450986743f, 0.003997192718088627f, 0.0027048231568187475f, 0.003485300811007619f, 0.0035568445455282927f, 0.005490637384355068f, 0.0022080312483012676f, 0.005447689443826675f, 0.0027553376276046038f, 0.004064467269927263f, 0.007070546504110098f, 0.005796933546662331f, 0.005282799247652292f, 0.003939659800380468f, 0.006877190433442593f, 0.007609374821186066f, 0.00458519859239459f, 0.0039587500505149364f, 0.004205511417239904f, 0.0032176338136196136f, 0.0046674953773617744f, 0.004302313085645437f, 0.003316274145618081f, 0.005796187557280064f, 0.006121799349784851f, 0.004162074998021126f, 0.004304991569370031f, 0.001682663569226861f, 0.002282768953591585f, 0.006524393800646067f, 0.0061553241685032845f, 0.003055906854569912f, 0.004598713479936123f, 0.0055746715515851974f, 0.003909089602530003f, 0.004700998309999704f, 0.004975238814949989f, 0.003800296690315008f, 0.0055268011055886745f, 0.005057735368609428f, 0.0024294257164001465f, 0.0045027825981378555f, 0.0031977402977645397f, 0.004256733693182468f, 0.004438144154846668f, 0.00301182153634727f, 0.004923816304653883f, 0.0032859870698302984f, 0.002459344221279025f, 0.004615515936166048f, 0.0026306379586458206f, 0.003161703236401081f, 0.003403307870030403f, 0.003850178560242057f, 0.002680955920368433f, 0.003304394194856286f, 0.006883312948048115f, 0.0042607346549630165f, 0.006623898167163134f, 0.004177474416792393f, 0.004200772847980261f, 0.004677495453506708f, 0.004325640853494406f, 0.005212373100221157f, 0.003942255862057209f, 0.0048080445267260075f, 0.002576688537374139f, 0.002445887541398406f, 0.006772426888346672f, 0.002428667852655053f, 0.0035877772606909275f, 0.0024100197479128838f, 0.0025519386399537325f, 0.003891038242727518f, 0.00238648965023458f, 0.005907416809350252f, 0.0038133657071739435f, 0.009106242097914219f, 0.004252016544342041f, 0.0046784463338553905f, 0.0038370199035853148f, 0.004881618544459343f, 0.00405421108007431f, 0.0040916032157838345f, 0.0111374007537961f, 0.003552887123078108f, 0.0034982911311089993f, 0.005068909376859665f, 0.0053169019520282745f, 0.0059785619378089905f, 0.003508134977892041f, 0.0046171811409294605f, 0.006955884397029877f, 0.00230309646576643f, 0.004287064541131258f, 0.0033074328675866127f, 0.004417729564011097f, 0.005528740584850311f, 0.00434800935909152f, 0.005196909885853529f, 0.004455406218767166f, 0.0022807985078543425f, 0.004327484872192144f, 0.0046179043129086494f, 0.0038224111776798964f, 0.0036609165836125612f, 0.0027214838191866875f, 0.0030328838620334864f, 0.004453353583812714f, 0.005692995153367519f, 0.005361975636333227f, 0.0037250069435685873f, 0.005731720011681318f, 0.005036912392824888f, 0.005591175984591246f, 0.00796284805983305f, 0.004324917681515217f, 0.004602448083460331f, 0.004843942821025848f, 0.004163730423897505f, 0.003978013526648283f, 0.0036294772289693356f, 0.012953465804457664f, 0.0020756935700774193f, 0.004439596552401781f, 0.005450421944260597f, 0.004445825237780809f, 0.0041140904650092125f, 0.006975745782256126f, 0.003756680991500616f, 0.0064507536590099335f, 0.003711734199896455f, 0.005529663525521755f, 0.0020452069584280252f, 0.004133058711886406f, 0.0032451197039335966f, 0.00495003629475832f, 0.003195772645995021f, 0.004709722939878702f, 0.005082792602479458f, 0.0025306642055511475f, 0.0018099579028785229f, 0.005530160386115313f, 0.0053873322904109955f, 0.004230875987559557f, 0.0025703832507133484f, 0.003149328986182809f, 0.004499286878854036f, 0.006192033179104328f, 0.00451452424749732f, 0.004228617064654827f, 0.0023970953188836575f, 0.0023629760835319757f, 0.00640035979449749f, 0.006206463556736708f, 0.0059488750994205475f, 0.004185473080724478f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #166 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00016532484733033925f, 8.553771476726979e-05f, 0.00010230959742330015f, 0.00018957910651806742f, 7.490798452636227e-05f, 6.490274972748011e-05f, 8.894686470739543e-05f, 0.0001818035962060094f, 0.00011690230894600973f, 0.00013233409845270216f, 9.817010868573561e-05f, 7.368601654889062e-05f, 0.00011516673839651048f, 5.161607259651646e-05f, 0.0015123665798455477f, 9.536241850582883e-05f, 0.0001143971603596583f, 0.00012882794544566423f, 8.291022822959349e-05f, 8.926444570533931e-05f, 0.00011615348921623081f, 7.513965101679787e-05f, 0.00010310515790479258f, 0.0002685182844288647f, 5.416169369709678e-05f, 0.00013161198876332492f, 0.00012630813580472022f, 4.9948754167417064e-05f, 0.00011987084872089326f, 9.268093708669767e-05f, 8.153083035722375e-05f, 0.0001383205089950934f, 8.091292693279684e-05f, 0.00010185351129621267f, 8.993493247544393e-05f, 0.00015654636081308126f, 9.234216122422367e-05f, 5.741981294704601e-05f, 7.956716581247747e-05f, 8.616701234132051e-05f, 9.62467456702143e-05f, 0.0002459977404214442f, 0.00014024772099219263f, 6.630727875744924e-05f, 0.00010160475358134136f, 0.00013055928866378963f, 9.633808804210275e-05f, 0.0001219359619426541f, 0.00012804077414330095f, 0.000159030023496598f, 0.0005577371339313686f, 0.00010108703281730413f, 0.0001313185493927449f, 4.217477544443682e-05f, 8.135620009852573e-05f, 7.533185998909175e-05f, 7.492535223718733e-05f, 0.0001582676632096991f, 7.062451913952827e-05f, 0.00010118212958332151f, 8.621239248896018e-05f, 0.00015138890012167394f, 0.00011485359573271126f, 0.00010986704000970349f, 8.360351057490334e-05f, 0.00010379884042777121f, 0.00013391538232099265f, 0.0003856326802633703f, 6.218624184839427e-05f, 0.00010001364717027172f, 9.399255941389129e-05f, 0.00011030564201064408f, 0.00010162605030927807f, 0.00010243554424960166f, 4.831244586966932e-05f, 0.00023765700461808592f, 0.00011089645704487339f, 0.0001092905513360165f, 0.00020457382197491825f, 0.00011410596925998107f, 6.233701424207538e-05f, 8.835760672809556e-05f, 0.00016051888815127313f, 8.125884050969034e-05f, 0.00010031834244728088f, 7.193155761342496e-05f, 9.078014409169555e-05f, 7.434582948917523e-05f, 0.00018684456881601363f, 4.6213750465540215e-05f, 0.0002101229183608666f, 0.00012638396583497524f, 0.00013516265607904643f, 6.881365698063746e-05f, 0.000182436328032054f, 0.00015089950466062874f, 0.00013433315325528383f, 6.107405351940542e-05f, 6.566008232766762e-05f, 7.968411227921024e-05f, 0.0001024863013299182f, 9.736080392030999e-05f, 7.419592293445021e-05f, 0.00011264158092672005f, 0.0001471176219638437f, 9.578210301697254e-05f, 0.00010545759869273752f, 8.611557132098824e-05f, 8.985511522041634e-05f, 7.226339221233502e-05f, 0.0001601927069714293f, 6.631046562688425e-05f, 0.00014830594591330737f, 0.0001023769800667651f, 0.0001126504794228822f, 5.199025690671988e-05f, 8.080972474999726e-05f, 0.0001209942638524808f, 8.671489194966853e-05f, 9.76486480794847e-05f, 0.00011812464072136208f, 0.00010747057240223512f, 9.414956002729014e-05f, 4.272428486729041e-05f, 8.253550186054781e-05f, 5.8154873840976506e-05f, 7.471489516319707e-05f, 5.44644208275713e-05f, 9.854570816969499e-05f, 0.0001184372667921707f, 3.86581668863073e-05f, 0.00015580080798827112f, 0.00016692103235982358f, 7.634725625393912e-05f, 0.00042009030585177243f, 5.084449003334157e-05f, 9.52924820012413e-05f, 0.00010583919356577098f, 5.590772343566641e-05f, 0.00012069270451320335f, 0.00011364558304194361f, 5.489736213348806e-05f, 4.005187292932533e-05f, 8.81386295077391e-05f, 9.390542254550382e-05f, 0.000111122484668158f, 5.663993215421215e-05f, 0.00014854958862997591f, 8.388330752495676e-05f, 0.00011899367382284254f, 0.00014983012806624174f, 0.00012296844215597957f, 4.245676609571092e-05f, 0.00013999687507748604f, 0.0001155395875684917f, 6.254373874980956e-05f, 0.00010626973380567506f, 0.00014209079381544143f, 8.760728815104812e-05f, 0.00012308225268498063f, 0.00012726831482723355f, 6.060892337700352e-05f, 5.990374120301567e-05f, 0.00015485109179280698f, 0.0001006807287922129f, 0.00013142060197424144f, 8.36490944493562e-05f, 9.379883704241365e-05f, 0.00010339876462239772f, 7.44893986848183e-05f, 5.2166702516842633e-05f, 8.351132419193164e-05f, 9.830939234234393e-05f, 0.00010740106517914683f, 0.00010948577255476266f, 6.587307143490762e-05f, 0.0001407577801728621f, 8.901673572836444e-05f, 0.00012420490384101868f, 0.00011707140220096335f, 9.405159653397277e-05f, 6.364289583871141e-05f, 8.200707816286013e-05f, 8.369045826839283e-05f, 0.00012919146683998406f, 5.195367702981457e-05f, 0.00012818092363886535f, 6.483147444669157e-05f, 9.563452476868406e-05f, 0.00016636580403428525f, 0.0001363984338240698f, 0.00012430116476025432f, 9.26978827919811e-05f, 0.00016181624960154295f, 0.00017904411652125418f, 0.00010788702638819814f, 9.314706403529271e-05f, 9.895321272779256e-05f, 7.57090310798958e-05f, 0.00010982342064380646f, 0.00010123090032720938f, 7.802998152328655e-05f, 0.0001363808842143044f, 0.00014404233661480248f, 9.793118078960106e-05f, 0.00010129392467206344f, 3.9592083339812234e-05f, 5.371221050154418e-05f, 0.00015351515321526676f, 0.0001448311668355018f, 7.190369069576263e-05f, 0.00010820502211572602f, 0.0001311687519773841f, 9.197858162224293e-05f, 0.00011061172699555755f, 0.00011706444638548419f, 8.94187469384633e-05f, 0.00013004237553104758f, 0.00011900554090971127f, 5.7162960729328915e-05f, 0.00010594783088890836f, 7.524094689870253e-05f, 0.00010015843872679397f, 0.00010442692291690037f, 7.086639379849657e-05f, 0.00011585450556594878f, 7.731734513072297e-05f, 5.786692418041639e-05f, 0.00010860037582460791f, 6.189736450323835e-05f, 7.439302135026082e-05f, 8.007783617358655e-05f, 9.059243893716484e-05f, 6.308131560217589e-05f, 7.775045378366485e-05f, 0.00016196031356230378f, 0.0001002525823423639f, 0.00015585642540827394f, 9.829351620282978e-05f, 9.884171595331281e-05f, 0.00011005871783709154f, 0.00010177978401770815f, 0.00012264407996553928f, 9.275896445615217e-05f, 0.00011313045979477465f, 6.0627968196058646e-05f, 5.755029633291997e-05f, 0.00015935122792143375f, 5.714512735721655e-05f, 8.441828686045483e-05f, 5.670634709531441e-05f, 6.004561510053463e-05f, 9.155384032055736e-05f, 5.6152697652578354e-05f, 0.00013899804616812617f, 8.972625073511153e-05f, 0.00021426452440209687f, 0.00010004745126934722f, 0.00011008109140675515f, 9.02828251128085e-05f, 0.00011486161383800209f, 9.539320308249444e-05f, 9.627301915315911e-05f, 0.0002620565064717084f, 8.359734783880413e-05f, 8.231273386627436e-05f, 0.00011926845763809979f, 0.0001251035719178617f, 0.0001406720548402518f, 8.254435670096427e-05f, 0.00010863955685636029f, 0.0001636678643990308f, 5.4190506489248946e-05f, 0.00010087210830533877f, 7.782195461913943e-05f, 0.0001039465787471272f, 0.00013008801033720374f, 0.00010230610496364534f, 0.00012228023842908442f, 0.00010483308869879693f, 5.36658480996266e-05f, 0.00010182317782891914f, 0.00010865657532121986f, 8.993908704724163e-05f, 8.613921818323433e-05f, 6.4034917159006e-05f, 7.136197382351384e-05f, 0.00010478479089215398f, 0.00013395282439887524f, 0.0001261641300516203f, 8.764722588239238e-05f, 0.00013486400712281466f, 0.00011851558519992977f, 0.0001315570843871683f, 0.0001873611327027902f, 0.00010176277282880619f, 0.00010829290113179013f, 0.0001139751257142052f, 9.797012899070978e-05f, 9.360031981486827e-05f, 8.539946429664269e-05f, 0.0003047874488402158f, 4.883985093329102e-05f, 0.00010446109808981419f, 0.0001282452285522595f, 0.00010460765770403668f, 9.680213406682014e-05f, 0.0001641351991565898f, 8.839249494485557e-05f, 0.0001517824421171099f, 8.73349272296764e-05f, 0.0001301097363466397f, 4.812251791008748e-05f, 9.724844130687416e-05f, 7.63557618483901e-05f, 0.00011647144128801301f, 7.519464998040348e-05f, 0.00011081701086368412f, 0.00011959511903114617f, 5.9545040130615234e-05f, 4.258724584360607e-05f, 0.00013012142153456807f, 0.00012676075857598335f, 9.955002315109596e-05f, 6.047960778232664e-05f, 7.410185935441405e-05f, 0.00010586557618808001f, 0.0001456948957638815f, 0.0001062240989995189f, 9.949687228072435e-05f, 5.640224480885081e-05f, 5.559943747357465e-05f, 0.00015059670840855688f, 0.000146034435601905f, 0.00013997353380545974f, 9.848172339843586e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #167 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0051702396012842655f, 0.003933512140065432f, 0.006776363123208284f, 0.00791235826909542f, 0.007383089512586594f, 0.0062961033545434475f, 0.004107504151761532f, 0.004586101043969393f, 0.004398425109684467f, 0.006394623778760433f, 0.003803581465035677f, 0.00664782989770174f, 0.005358477123081684f, 0.00557493744418025f, 0.004056703764945269f, 0.0032515048515051603f, 0.0045471033081412315f, 0.006316397804766893f, 0.006214596796780825f, 0.005046133417636156f, 0.004489897284656763f, 0.00384509121067822f, 0.005561631638556719f, 0.004232609178870916f, 0.006142400670796633f, 0.004175421316176653f, 0.005545170046389103f, 0.004456901457160711f, 0.0038304426707327366f, 0.007476408965885639f, 0.0069056726060807705f, 0.004357399884611368f, 0.004407310858368874f, 0.004731259774416685f, 0.006068896967917681f, 0.006464445497840643f, 0.005846076179295778f, 0.006531501654535532f, 0.003145240480080247f, 0.00597647437825799f, 0.005938253365457058f, 0.004549773409962654f, 0.0057222372852265835f, 0.0038655553944408894f, 0.005639679729938507f, 0.005893393885344267f, 0.005410644691437483f, 0.004650223534554243f, 0.005786540452390909f, 0.0056258030235767365f, 0.004007744137197733f, 0.006442468147724867f, 0.003833305323496461f, 0.006970121990889311f, 0.006646773312240839f, 0.00771242706105113f, 0.005093471147119999f, 0.005755057092756033f, 0.005167159717530012f, 0.005395140964537859f, 0.0066772340796887875f, 0.00526269618421793f, 0.003828224493190646f, 0.004740943666547537f, 0.006213617045432329f, 0.007586998865008354f, 0.005445805378258228f, 0.006510192062705755f, 0.005512433126568794f, 0.005922163370996714f, 0.005875071045011282f, 0.005139862187206745f, 0.006534202955663204f, 0.005981749389320612f, 0.0038464840035885572f, 0.005004631355404854f, 0.004425148479640484f, 0.005022104829549789f, 0.006523207761347294f, 0.00555387744680047f, 0.006832383573055267f, 0.006475015077739954f, 0.004725515376776457f, 0.0049006883054971695f, 0.006334464997053146f, 0.004047265741974115f, 0.0035896101035177708f, 0.00591857498511672f, 0.004558531567454338f, 0.005309073254466057f, 0.006017567124217749f, 0.006089219357818365f, 0.0038427147082984447f, 0.00513308122754097f, 0.0058120680041611195f, 0.004907998722046614f, 0.0032660828437656164f, 0.006738620810210705f, 0.004471802618354559f, 0.004527008160948753f, 0.005991404876112938f, 0.005259570199996233f, 0.005875489674508572f, 0.0032369818072766066f, 0.004783761687576771f, 0.005976741202175617f, 0.005063795018941164f, 0.005210614297538996f, 0.0038403228390961885f, 0.005555823910981417f, 0.006063421722501516f, 0.004106469918042421f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #168 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_66_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 112,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00012165270163677633f, 9.255322947865352e-05f, 0.00015944383630994707f, 0.0001861731434473768f, 0.00017371975991409272f, 0.0001481436047470197f, 9.664715616963804e-05f, 0.00010790826490847394f, 0.00010349235526518896f, 0.00015046173939481378f, 8.949603943619877e-05f, 0.00015641952631995082f, 0.00012608180986717343f, 0.00013117499474901706f, 9.545185457682237e-05f, 7.650599582120776e-05f, 0.00010699066478991881f, 0.00014862112584523857f, 0.00014622580783907324f, 0.00011873255425598472f, 0.00010564464173512533f, 9.04727348824963e-05f, 0.00013086192484479398f, 9.959080489352345e-05f, 0.0001445270754629746f, 9.824521112022921e-05f, 0.00013047459651716053f, 0.00010486827522981912f, 9.012806549435481e-05f, 0.00017591551295481622f, 0.00016248642350547016f, 0.00010252706124447286f, 0.00010370143718319014f, 0.00011132375948363915f, 0.0001427975803380832f, 0.0001521046069683507f, 0.00013755474356003106f, 0.00015368239837698638f, 7.400565664283931e-05f, 0.00014062292757444084f, 0.00013972360466141254f, 0.00010705349268391728f, 0.0001346408826066181f, 9.095424320548773e-05f, 0.00013269834744278342f, 0.00013866809604223818f, 0.00012730929302051663f, 0.00010941702930722386f, 0.0001361538888886571f, 0.00013237183156888932f, 9.429986675968394e-05f, 0.00015158749010879546f, 9.019541903398931e-05f, 0.00016400287859141827f, 0.00015639467164874077f, 0.0001814688730519265f, 0.00011984637967543676f, 0.00013541310909204185f, 0.00012158023309893906f, 0.0001269444910576567f, 0.00015711139712948352f, 0.00012382815475575626f, 9.007587505038828e-05f, 0.00011155162064824253f, 0.0001462027576053515f, 0.00017851762822829187f, 0.00012813659850507975f, 0.00015318099758587778f, 0.00012970430543646216f, 0.00013934502203483135f, 0.00013823696644976735f, 0.00012093793338863179f, 0.0001537459611427039f, 0.00014074704085942358f, 9.050550579559058e-05f, 0.00011775603343266994f, 0.0001041211435222067f, 0.0001181671759695746f, 0.00015348724264185876f, 0.0001306794729316607f, 0.00016076196334324777f, 0.0001523532991996035f, 0.00011118860129499808f, 0.00011531031486811116f, 0.00014904623094480485f, 9.522978507447988e-05f, 8.446141873719171e-05f, 0.00013926059182267636f, 0.0001072595696314238f, 0.00012491937377490103f, 0.00014158981502987444f, 0.00014327575627248734f, 9.04168191482313e-05f, 0.00012077838619006798f, 0.0001367545482935384f, 0.00011548232578206807f, 7.684900629101321e-05f, 0.00015855579113122076f, 0.00010521888907533139f, 0.00010651784396031871f, 0.00014097423991188407f, 0.00012375459482427686f, 0.00013824681809637696f, 7.616428047185764e-05f, 0.00011255910067120567f, 0.0001406292140018195f, 0.00011914812057511881f, 0.0001226026943186298f, 9.036053961608559e-05f, 0.00013072526780888438f, 0.00014266875223256648f, 9.662282536737621e-05f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #169 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0029621743597090244f, 0.0033644703216850758f, 0.0049153524450957775f, 0.0032927750144153833f, 0.003900615032762289f, 0.004424807149916887f, 0.0034887518268078566f, 0.0034346419852226973f, 0.0041217198595404625f, 0.0035716199781745672f, 0.004293471109122038f, 0.003848699387162924f, 0.0034123845398426056f, 0.0036328909918665886f, 0.004890523850917816f, 0.005025461781769991f, 0.00393777946010232f, 0.003102334449067712f, 0.0032731476239860058f, 0.003895457601174712f, 0.0036590408999472857f, 0.0038306897040456533f, 0.0036488703917711973f, 0.004305759444832802f, 0.0039032879285514355f, 0.003702098038047552f, 0.003837374271824956f, 0.0033054640516638756f, 0.004221534356474876f, 0.0032322590705007315f, 0.0032622944563627243f, 0.003234345465898514f, 0.0043456945568323135f, 0.003198967082425952f, 0.0036099764984101057f, 0.0040717413648962975f, 0.0031526193488389254f, 0.0033254511654376984f, 0.004248072858899832f, 0.00271798949688673f, 0.003532933536916971f, 0.0033612586557865143f, 0.003316854126751423f, 0.004583351779729128f, 0.00375380739569664f, 0.003646325320005417f, 0.0033430755138397217f, 0.003338437993079424f, 0.00485564349219203f, 0.0035840366035699844f, 0.004379378631711006f, 0.00479535385966301f, 0.003416685853153467f, 0.003651074366644025f, 0.0041238171979784966f, 0.0044944193214178085f, 0.005938307382166386f, 0.004499021917581558f, 0.004957282915711403f, 0.003938966430723667f, 0.005099035333842039f, 0.003849896602332592f, 0.0031181268859654665f, 0.0032906183041632175f, 0.0036717732436954975f, 0.005371137987822294f, 0.004111108835786581f, 0.003390368539839983f, 0.0034574829041957855f, 0.0032442992087453604f, 0.0052483235485851765f, 0.003320713760331273f, 0.0047577545046806335f, 0.0037853147368878126f, 0.003660373855382204f, 0.004052985459566116f, 0.0034788409247994423f, 0.0037654766347259283f, 0.0035777667071670294f, 0.00322128226980567f, 0.004163912031799555f, 0.004439814481884241f, 0.0028503912035375834f, 0.0036186901852488518f, 0.004053816664963961f, 0.0041634258814156055f, 0.004628990311175585f, 0.0036114307586103678f, 0.004538137931376696f, 0.0034262577537447214f, 0.003470691153779626f, 0.004572177305817604f, 0.003930628765374422f, 0.0034403798636049032f, 0.004216828383505344f, 0.004287114832550287f, 0.003045364050194621f, 0.002938083605840802f, 0.00401325523853302f, 0.0033415695652365685f, 0.004316762089729309f, 0.0037072384729981422f, 0.0034710951149463654f, 0.003110656049102545f, 0.004544608294963837f, 0.0031723687425255775f, 0.004046203568577766f, 0.005045578349381685f, 0.004894716665148735f, 0.003499529790133238f, 0.003774539800360799f, 0.003427438670769334f, 0.003892133943736553f, 0.0035728097427636385f, 0.004251927603036165f, 0.00433994410559535f, 0.003647909965366125f, 0.003345117438584566f, 0.0036913298536092043f, 0.003138078609481454f, 0.0027960767038166523f, 0.0038398378528654575f, 0.005039792507886887f, 0.004316587932407856f, 0.004293434787541628f, 0.003208696376532316f, 0.004374955780804157f, 0.004422201309353113f, 0.003224818268790841f, 0.003907157573848963f, 0.003477038349956274f, 0.002922841813415289f, 0.0035453643649816513f, 0.003880483331158757f, 0.003936633002012968f, 0.003302880795672536f, 0.004205590113997459f, 0.0035609877668321133f, 0.00409786868840456f, 0.00515262596309185f, 0.0027498393319547176f, 0.004421652294695377f, 0.003410582197830081f, 0.0035203061997890472f, 0.0032483094837516546f, 0.0033308679703623056f, 0.0029898423235863447f, 0.004326171241700649f, 0.0034060287289321423f, 0.004507994279265404f, 0.0052445512264966965f, 0.004290164913982153f, 0.003649138379842043f, 0.0035159692633897066f, 0.0038118178490549326f, 0.004307774361222982f, 0.00383915682323277f, 0.003390311496332288f, 0.0030954566318541765f, 0.006119788624346256f, 0.003342142328619957f, 0.004260276444256306f, 0.0036841370165348053f, 0.0033493991941213608f, 0.0031952124554663897f, 0.0037867750506848097f, 0.00400565518066287f, 0.0027008422184735537f, 0.003619050607085228f, 0.003319782204926014f, 0.004175545182079077f, 0.003344203345477581f, 0.003935686312615871f, 0.003371675731614232f, 0.004278067499399185f, 0.0033198276069015265f, 0.00410841079428792f, 0.0036911156494170427f, 0.004427166655659676f, 0.004071194678544998f, 0.0041862186044454575f, 0.003799168858677149f, 0.004343350883573294f, 0.0032892145682126284f, 0.004136508796364069f, 0.003958592191338539f, 0.004303037654608488f, 0.0031933810096234083f, 0.003676677355542779f, 0.003103886963799596f, 0.004584965296089649f, 0.004086196422576904f, 0.0030248654074966908f, 0.0035784943029284477f, 0.004008707590401173f, 0.004072778392583132f, 0.003423432819545269f, 0.0040171267464756966f, 0.0034773284569382668f, 0.004585679620504379f, 0.0035897057969123125f, 0.003431397955864668f, 0.003146434435620904f, 0.0029587838798761368f, 0.00477429386228323f, 0.004196573980152607f, 0.003918379079550505f, 0.0035362106282263994f, 0.003449812764301896f, 0.0038263655733317137f, 0.003309657797217369f, 0.003911591600626707f, 0.003494484815746546f, 0.004628441762179136f, 0.003941776230931282f, 0.0038159871473908424f, 0.003246939042583108f, 0.0040299599058926105f, 0.0033057990949600935f, 0.004657807294279337f, 0.003644191659986973f, 0.0031818062998354435f, 0.0030362787656486034f, 0.0035908606369048357f, 0.0042848060838878155f, 0.00393308699131012f, 0.004263146314769983f, 0.005063691642135382f, 0.0036539132706820965f, 0.00630768109112978f, 0.0036029089242219925f, 0.003445018781349063f, 0.003987973555922508f, 0.003754357108846307f, 0.003475191304460168f, 0.004207054618746042f, 0.00454884534701705f, 0.004790264647454023f, 0.005521835293620825f, 0.0038377537857741117f, 0.00419484032317996f, 0.004195132292807102f, 0.004448089748620987f, 0.00633424473926425f, 0.0032034090254455805f, 0.003082899609580636f, 0.0038549788296222687f, 0.003230325412005186f, 0.0037528942339122295f, 0.004231833852827549f, 0.004594755824655294f, 0.004471823573112488f, 0.0039125001057982445f, 0.0038791170809417963f, 0.004584516864269972f, 0.003646549768745899f, 0.004184157121926546f, 0.0036161956377327442f, 0.0032765676733106375f, 0.004271447192877531f, 0.004238890949636698f, 0.003505409462377429f, 0.0035445503890514374f, 0.003352345898747444f, 0.004001225344836712f, 0.0038233718369156122f, 0.004652536939829588f, 0.003743969602510333f, 0.004537845496088266f, 0.0041128601878881454f, 0.0035382285714149475f, 0.004026023205369711f, 0.003350239945575595f, 0.004091943614184856f, 0.0038305821362882853f, 0.003431562567129731f, 0.006354889366775751f, 0.0038771696854382753f, 0.0031766952015459538f, 0.006071371957659721f, 0.004741188138723373f, 0.003523157676681876f, 0.0031935949809849262f, 0.0038386699743568897f, 0.003979406785219908f, 0.004884691443294287f, 0.003888314589858055f, 0.003666393691673875f, 0.0034294205252081156f, 0.003630507504567504f, 0.005184345878660679f, 0.00438412232324481f, 0.0031753932125866413f, 0.0032344693318009377f, 0.003810434602200985f, 0.0038565322756767273f, 0.0044325548224151134f, 0.005660794209688902f, 0.004007241223007441f, 0.0034891427494585514f, 0.00391959585249424f, 0.0037625269033014774f, 0.0032248455099761486f, 0.0034492583945393562f, 0.0030559138394892216f, 0.004196772351861f, 0.0031696599908173084f, 0.0030325460247695446f, 0.0032967571169137955f, 0.004571749363094568f, 0.004812916275113821f, 0.0037127721589058638f, 0.003925019409507513f, 0.004623056389391422f, 0.003556302050128579f, 0.004301831591874361f, 0.0039612106047570705f, 0.004419439006596804f, 0.00391819141805172f, 0.0037713053170591593f, 0.004642801824957132f, 0.00438147597014904f, 0.004088780842721462f, 0.0034643267281353474f, 0.003346133977174759f, 0.0036364933475852013f, 0.0034638133365660906f, 0.00327310967259109f, 0.003134253667667508f, 0.00333037949167192f, 0.0030644931830465794f, 0.003174717305228114f, 0.005083031021058559f, 0.0034763580188155174f, 0.0040988498367369175f, 0.0035751487594097853f, 0.004742742981761694f, 0.004511799197643995f, 0.0035490624140948057f, 0.0038101691752672195f, 0.00406529288738966f, 0.003094490384683013f, 0.003443113761022687f, 0.003168839029967785f, 0.0036394898779690266f, 0.0037023858167231083f, 0.003490738570690155f, 0.0036068614572286606f, 0.003930498380213976f, 0.0032765199430286884f, 0.0047698840498924255f, 0.0046587735414505005f, 0.005383722484111786f, 0.004109837580472231f, 0.005526264198124409f, 0.003496570745483041f, 0.0032788091339170933f, 0.003133246907964349f, 0.004803256597369909f, 0.00329365162178874f, 0.0035719391889870167f, 0.004280454479157925f, 0.00372205744497478f, 0.0032016735058277845f, 0.0037282356061041355f, 0.0042003183625638485f, 0.003306593047454953f, 0.0032957373186945915f, 0.004800454247742891f, 0.003335255663841963f, 0.004352608695626259f, 0.0032475918997079134f, 0.0034948475658893585f, 0.004117960575968027f, 0.0038880847860127687f, 0.005015515256673098f, 0.003927293233573437f, 0.004906860180199146f, 0.002877302933484316f, 0.003215562552213669f, 0.004144994542002678f, 0.003147804643958807f, 0.003283244324848056f, 0.004246704280376434f, 0.00335312751121819f, 0.004042781889438629f, 0.0038578903768211603f, 0.0044078705832362175f, 0.004800190217792988f, 0.0034336342941969633f, 0.003342418698593974f, 0.0041420478373765945f, 0.0031723130960017443f, 0.004348712041974068f, 0.004520172718912363f, 0.003839158918708563f, 0.0038421638309955597f, 0.003500158665701747f, 0.004192360211163759f, 0.0037458851002156734f, 0.0033213256392627954f, 0.003410576144233346f, 0.00416570482775569f, 0.0034403603058308363f, 0.0036236036103218794f, 0.0038853243459016085f, 0.004353208001703024f, 0.00396908400580287f, 0.006485541816800833f, 0.004381355829536915f, 0.004019616171717644f, 0.004383882973343134f, 0.0033321583177894354f, 0.0038412604480981827f, 0.003513435833156109f, 0.00473377900198102f, 0.004256685264408588f, 0.004033641889691353f, 0.004690112080425024f, 0.0034506202209740877f, 0.0041711097583174706f, 0.004795975983142853f, 0.004205739125609398f, 0.0034325227607041597f, 0.0032271621748805046f, 0.003925822675228119f, 0.00332421762868762f, 0.003914021421223879f, 0.003951767459511757f, 0.003582450794056058f, 0.0035022131633013487f, 0.004267056938260794f, 0.0037143072113394737f, 0.004206966143101454f, 0.003702020039781928f, 0.0035629388876259327f, 0.0036350504960864782f, 0.0041279555298388f, 0.0037537405733019114f, 0.0036773751489818096f, 0.003952719271183014f, 0.0033756510820239782f, 0.0048948414623737335f, 0.0032220634166151285f, 0.004089789930731058f, 0.003362115705385804f, 0.003610435873270035f, 0.003887295024469495f, 0.00531136617064476f, 0.004615883342921734f, 0.0031316163949668407f, 0.004317651502788067f, 0.005071340128779411f, 0.0035983577836304903f, 0.00377773423679173f, 0.0039926921017467976f, 0.003786012064665556f, 0.003109527286142111f, 0.003410974284633994f, 0.00290185259655118f, 0.0066179269924759865f, 0.0049520572647452354f, 0.0029818916227668524f, 0.0032399462070316076f, 0.004219433758407831f, 0.0035106795839965343f, 0.0034611383453011513f, 0.0041664717718958855f, 0.004967675544321537f, 0.003332019317895174f, 0.0036424859426915646f, 0.004190773703157902f, 0.0031857311259955168f, 0.0033744312822818756f, 0.0034841797314584255f, 0.004697736352682114f, 0.0032495942432433367f, 0.004388927482068539f, 0.004178712144494057f, 0.004058487247675657f, 0.004560193512588739f, 0.003754423698410392f, 0.002611876465380192f, 0.004303581081330776f, 0.005203274544328451f, 0.0033818844240158796f, 0.004607797134667635f, 0.004298161715269089f, 0.00304318661801517f, 0.0034339630510658026f, 0.0033718817867338657f, 0.004272162914276123f, 0.0034826400224119425f, 0.00353202479891479f, 0.004304851870983839f, 0.0035449028946459293f, 0.0043202973902225494f, 0.004805420525372028f, 0.003576156683266163f, 0.003997931722551584f, 0.003388427197933197f, 0.005083013325929642f, 0.0034545923117548227f, 0.003727123374119401f, 0.0035533630289137363f, 0.004298783373087645f, 0.004713017959147692f, 0.00373062607832253f, 0.003512405790388584f, 0.00281945476308465f, 0.0032879288773983717f, 0.003462927881628275f, 0.0032281847670674324f, 0.0045919413678348064f, 0.0033374351914972067f, 0.004353893455117941f, 0.004066035617142916f, 0.004484729375690222f, 0.004393632523715496f, 0.003506285836920142f, 0.0033648458775132895f, 0.004113911651074886f, 0.005349946673959494f, 0.0041417526081204414f, 0.003848234424367547f, 0.003397733438760042f, 0.0046790288761258125f, 0.004853780847042799f, 0.0046649519354105f, 0.0032742787152528763f, 0.0063657257705926895f, 0.003535504685714841f, 0.003633310319855809f, 0.0030023346189409494f, 0.004154188092797995f, 0.00448373518884182f, 0.0036109385546296835f, 0.0033877005334943533f, 0.0038082946557551622f, 0.0032024437095969915f, 0.0037793503142893314f, 0.00530313840135932f, 0.004779394716024399f, 0.0031299875117838383f, 0.003210383001714945f, 0.003936838358640671f, 0.004272839054465294f, 0.0037714773789048195f, 0.00294130714610219f, 0.004011011682450771f, 0.005140672437846661f, 0.00633307034149766f, 0.00379301980137825f, 0.003450100077316165f, 0.0038420299533754587f, 0.0032766994554549456f, 0.003919941373169422f, 0.003880188101902604f, 0.004928578622639179f, 0.003675773274153471f, 0.004200443159788847f, 0.00394864659756422f, 0.004022696055471897f, 0.0035731950774788857f, 0.004084239713847637f, 0.0036705033853650093f, 0.003865630365908146f, 0.004764966666698456f, 0.003472303505986929f, 0.0031003281474113464f, 0.004549398086965084f, 0.004818455316126347f, 0.004989089909940958f, 0.0034518444444984198f, 0.004079070873558521f, 0.0035510207526385784f, 0.003354366635903716f, 0.0033248907420784235f, 0.003467963309958577f, 0.0029625638853758574f, 0.003761970903724432f, 0.004135383293032646f, 0.003659704001620412f, 0.004776648711413145f, 0.005870512221008539f, 0.004650127608329058f, 0.00322336726821959f, 0.004082805477082729f, 0.0051069194450974464f, 0.0037863198667764664f, 0.0037340756971389055f, 0.004183941055089235f, 0.004042982589453459f, 0.004448819439858198f, 0.0044803014025092125f, 0.003756837220862508f, 0.0035036804620176554f, 0.0031629009172320366f, 0.002847203053534031f, 0.003151366952806711f, 0.0037002863828092813f, 0.003421926172450185f, 0.005089926067739725f, 0.003592798486351967f, 0.00421297037974f, 0.00397491455078125f, 0.003584706224501133f, 0.004571598023176193f, 0.003927632700651884f, 0.0032710356172174215f, 0.005061660427600145f, 0.004301175940781832f, 0.0032074914779514074f, 0.00376138836145401f, 0.003455533180385828f, 0.004005294293165207f, 0.004653532523661852f, 0.004386376589536667f, 0.004143550992012024f, 0.003762919921427965f, 0.004184543155133724f, 0.004391332156956196f, 0.004077984020113945f, 0.0032656381372362375f, 0.005854274611920118f, 0.004045072477310896f, 0.003897598944604397f, 0.0029065634589642286f, 0.004519837908446789f, 0.003582653822377324f, 0.004148488398641348f, 0.003747234819456935f, 0.0038128106389194727f, 0.003723974572494626f, 0.004262762609869242f, 0.003855583257973194f, 0.004367745481431484f, 0.003120989305898547f, 0.003983011469244957f, 0.0034893120173364878f, 0.005846032407134771f, 0.0039939284324646f, 0.0039042325224727392f, 0.003287811763584614f, 0.004331226926296949f, 0.004535997286438942f, 0.0038230870850384235f, 0.0032234271056950092f, 0.002940013073384762f, 0.004420932848006487f, 0.0033648849930614233f, 0.003510913113132119f, 0.005485952366143465f, 0.002958085387945175f, 0.003923716489225626f, 0.0056234318763017654f, 0.003082903567701578f, 0.0037146038375794888f, 0.0033215901348739862f, 0.003593590809032321f, 0.0036987634375691414f, 0.0032525788992643356f, 0.004292162135243416f, 0.0040128654800355434f, 0.003820545971393585f, 0.003391462843865156f, 0.004036093596369028f, 0.003352417843416333f, 0.0031651968602091074f, 0.004436196759343147f, 0.004314885474741459f, 0.003969805780798197f, 0.003564580576494336f, 0.0037234758492559195f, 0.0037635022308677435f, 0.0037297774106264114f, 0.0034196653869003057f, 0.004178146831691265f, 0.0035949326120316982f, 0.0038610813207924366f, 0.0037413188256323338f, 0.005509563256055117f, 0.0030475177336484194f, 0.0045599727891385555f, 0.004571881610900164f, 0.0035430616699159145f, 0.0029997294768691063f, 0.0032783683855086565f, 0.00462679285556078f, 0.0033908847253769636f, 0.0038366413209587336f, 0.002781146438792348f, 0.004241006448864937f, 0.0034110562410205603f, 0.0033770836889743805f, 0.004305133130401373f, 0.004008967895060778f, 0.003983802627772093f, 0.004068258684128523f, 0.004230304155498743f, 0.0035255977418273687f, 0.003278439398854971f, 0.0033478301484137774f, 0.0031949542462825775f, 0.003808283945545554f, 0.004298692103475332f, 0.004734646994620562f, 0.0038734683766961098f, 0.005410806275904179f, 0.0036318472120910883f, 0.0032526934519410133f, 0.0035975053906440735f, 0.003990450873970985f, 0.0036530718207359314f, 0.0033299101050943136f, 0.004036975558847189f, 0.003097260370850563f, 0.004319015424698591f, 0.004831819329410791f, 0.0033691891003400087f, 0.0035797771997749805f, 0.004385650623589754f, 0.004873013589531183f, 0.005865420680493116f, 0.004063860047608614f, 0.0035398281179368496f, 0.003063357435166836f, 0.003520447527989745f, 0.003479900537058711f, 0.004149496555328369f, 0.0037014512345194817f, 0.004281267523765564f, 0.004563324153423309f, 0.004182690754532814f, 0.004538063425570726f, 0.003617816139012575f, 0.003659724025055766f, 0.004247055388987064f, 0.004130721092224121f, 0.0035810882691293955f, 0.0031423233449459076f, 0.0033550416119396687f, 0.0036861810367554426f, 0.006072734948247671f, 0.003580274526029825f, 0.0036758105270564556f, 0.0038705957122147083f, 0.003920970018953085f, 0.003733755322173238f, 0.0031526009552180767f, 0.0041847326792776585f, 0.004725039470940828f, 0.004196533001959324f, 0.003375475527718663f, 0.0037838721182197332f, 0.0037047755904495716f, 0.00448200386017561f, 0.003945316653698683f, 0.003851888468489051f, 0.003912697080522776f, 0.0035066341515630484f, 0.004275746643543243f, 0.0033818574156612158f, 0.004516232293099165f, 0.003608993487432599f, 0.0035271355882287025f, 0.0029475355986505747f, 0.004480111878365278f, 0.0038984178099781275f, 0.004397981334477663f, 0.0036905973684042692f, 0.0039566317573189735f, 0.004126035608351231f, 0.003393761580809951f, 0.004017827101051807f, 0.004384600557386875f, 0.003472927724942565f, 0.003927913028746843f, 0.003928858786821365f, 0.005807938519865274f, 0.0043465509079396725f, 0.0041412306018173695f, 0.0034971393179148436f, 0.004865826107561588f, 0.0035962238907814026f, 0.0037453460972756147f, 0.004292232915759087f, 0.003040376352146268f, 0.003620086470618844f, 0.00403149239718914f, 0.004563336260616779f, 0.004896350670605898f, 0.0033160748425871134f, 0.003017794108018279f, 0.0037410128861665726f, 0.0038430807180702686f, 0.0037303066346794367f, 0.0038062536623328924f, 0.0037109525874257088f, 0.0029094316996634007f, 0.003603394376114011f, 0.004206246696412563f, 0.003390462836250663f, 0.003353436477482319f, 0.00332513265311718f, 0.0034080983605235815f, 0.0030388899613171816f, 0.0035089512821286917f, 0.0037134727463126183f, 0.0029600325506180525f, 0.004264439921826124f, 0.0031387850176542997f, 0.004202780779451132f, 0.004709987435489893f, 0.0038652517832815647f, 0.004131568595767021f, 0.0039000832475721836f, 0.0031189967412501574f, 0.003231070237234235f, 0.003516832599416375f, 0.0034131330903619528f, 0.0035837336909025908f, 0.0037023969925940037f, 0.003444469766691327f, 0.004690661560744047f, 0.003776862984523177f, 0.0036350961308926344f, 0.0029302246402949095f, 0.004101108759641647f, 0.004383181221783161f, 0.0032548157032579184f, 0.004400069825351238f, 0.0035027344711124897f, 0.002985740313306451f, 0.004245380405336618f, 0.003629618790000677f, 0.004228337202221155f, 0.0031357109546661377f, 0.0033481549471616745f, 0.004325544461607933f, 0.00364362308755517f, 0.00405625207349658f, 0.004190986044704914f, 0.0037382133305072784f, 0.0035301605239510536f, 0.003848389955237508f, 0.004513812251389027f, 0.0035816326271742582f, 0.0044907573610544205f, 0.0030734518077224493f, 0.004113675095140934f, 0.0032499057706445456f, 0.0029603575821965933f, 0.003121484536677599f, 0.003096085973083973f, 0.0034700059331953526f, 0.003664362942799926f, 0.00415640277788043f, 0.003283877857029438f, 0.004119792953133583f, 0.003627513302490115f, 0.0035495443735271692f, 0.00330821773968637f, 0.002972076181322336f, 0.004225956276059151f, 0.0034761277493089437f, 0.003616757458075881f, 0.0030844772700220346f, 0.003596588736400008f, 0.004312840756028891f, 0.003382220398634672f, 0.003983812872320414f, 0.00473918579518795f, 0.003948417492210865f, 0.004426038824021816f, 0.0041347104124724865f, 0.0026497822254896164f, 0.0029900120571255684f, 0.003603713819757104f, 0.004140692763030529f, 0.003226194530725479f, 0.003353161970153451f, 0.004237430635839701f, 0.0034699696116149426f, 0.003261550795286894f, 0.004420971963554621f, 0.004506830126047134f, 0.003706392366439104f, 0.00487936707213521f, 0.004529417492449284f, 0.004179668612778187f, 0.003669495228677988f, 0.0034063938073813915f, 0.003189353970810771f, 0.0036273670848459005f, 0.004923535045236349f, 0.003010094864293933f, 0.004265320021659136f, 0.004500055685639381f, 0.004156975075602531f, 0.002885600319132209f, 0.0029739129822701216f, 0.00408858060836792f, 0.0036299508064985275f, 0.004287448711693287f, 0.0032969219610095024f, 0.003886751364916563f, 0.003322541480883956f, 0.004545123782008886f, 0.0031153575982898474f, 0.0032655452378094196f, 0.0042764050886034966f, 0.0032842406071722507f, 0.004038607701659203f, 0.0036575670819729567f, 0.0032638446427881718f, 0.0038801939226686954f, 0.004386259242892265f, 0.006266017910093069f, 0.0033433043863624334f, 0.0035418341867625713f, 0.0037159353960305452f, 0.003750019008293748f, 0.004375551361590624f, 0.003761537605896592f, 0.0035675386898219585f, 0.0043622758239507675f, 0.0040155029855668545f, 0.003268867963925004f, 0.004967513028532267f, 0.0036836382932960987f, 0.003703545080497861f, 0.005030590109527111f, 0.004102685023099184f, 0.003496711142361164f, 0.004623484332114458f, 0.0044000460766255856f, 0.0035491923335939646f, 0.004719546530395746f, 0.003473901655524969f, 0.0028756060637533665f, 0.003623445052653551f, 0.003577266586944461f, 0.0032603470608592033f, 0.003417127998545766f, 0.003827174659818411f, 0.003970835357904434f, 0.004037435166537762f, 0.0038029642309993505f, 0.004964381922036409f, 0.003615353722125292f, 0.004663451574742794f, 0.00370883964933455f, 0.0032223700545728207f, 0.003398207714781165f, 0.00341453542932868f, 0.0053894114680588245f, 0.004285176284611225f, 0.0029914667829871178f, 0.004213717766106129f, 0.003656169632449746f, 0.005473132710903883f, 0.004141768906265497f, 0.0052666086703538895f, 0.004633591044694185f, 0.003192879958078265f, 0.0033314276952296495f, 0.003959445282816887f, 0.0034829718060791492f, 0.0037485812790691853f, 0.003829778404906392f, 0.003791988827288151f, 0.0044307224452495575f, 0.0047205425798892975f, 0.005846777465194464f, 0.004771678242832422f, 0.004090785048902035f, 0.004043771885335445f, 0.004073330666869879f, 0.004721174947917461f, 0.003996714949607849f, 0.003887275466695428f, 0.0037436571437865496f, 0.0032804214861243963f, 0.0038602601271122694f, 0.0036037880927324295f, 0.004096061456948519f, 0.004099768120795488f, 0.003571128472685814f, 0.0033752296585589647f, 0.003964386414736509f, 0.0036886492744088173f, 0.004123199265450239f, 0.004765571095049381f, 0.004150883294641972f, 0.003768018912523985f, 0.004433669615536928f, 0.0045180791057646275f, 0.0034048312809318304f, 0.00390043156221509f, 0.0038431943394243717f, 0.0029916309285908937f, 0.0030236640013754368f, 0.003688886994495988f, 0.006153726018965244f, 0.0034774576779454947f, 0.0048773265443742275f, 0.0036245444789528847f, 0.0035867250990122557f, 0.003957362379878759f, 0.005563497543334961f, 0.0037009778898209333f, 0.0036931829527020454f, 0.0033976363483816385f, 0.00351080484688282f, 0.00312315602786839f, 0.003882891498506069f, 0.0036013557109981775f, 0.004141919780522585f, 0.0037264388520270586f, 0.004249583464115858f, 0.003505573607981205f, 0.0033702615182846785f, 0.0034968634136021137f, 0.0040143923833966255f, 0.004930148366838694f, 0.00408761203289032f, 0.003532127710059285f, 0.0035236028488725424f, 0.002986844163388014f, 0.0031893234699964523f, 0.0034949963446706533f, 0.003837575437501073f, 0.003057049820199609f, 0.004893495235592127f, 0.003361109644174576f, 0.00346668460406363f, 0.003403447102755308f, 0.0037285350263118744f, 0.0032160645350813866f, 0.004089984577149153f, 0.003120443318039179f, 0.00305331964045763f, 0.0044115083292126656f, 0.0032609186600893736f, 0.004274354316294193f, 0.004194176290184259f, 0.004207543097436428f, 0.003657449036836624f, 0.00410618307068944f, 0.003955939318984747f, 0.005211900919675827f, 0.0037916889414191246f, 0.003477461403235793f, 0.0030775475315749645f, 0.004935852717608213f, 0.0038171960040926933f, 0.003478416707366705f, 0.003811120055615902f, 0.002807736163958907f, 0.004117438569664955f, 0.004986507818102837f, 0.0045080832205712795f, 0.003377595916390419f, 0.00481773866340518f, 0.003528469940647483f, 0.004120280966162682f, 0.003474973840638995f, 0.0035590704064816236f, 0.004208311904221773f, 0.0032097615767270327f, 0.0038121389225125313f, 0.0038719859439879656f, 0.0047120158560574055f, 0.003297202754765749f, 0.002832177560776472f, 0.004443935118615627f, 0.005546832922846079f, 0.004733807872980833f, 0.005225821863859892f, 0.004065012093633413f, 0.004077001474797726f, 0.0032616560347378254f, 0.004428495187312365f, 0.0034507380332797766f, 0.0041101593524217606f, 0.0034873299300670624f, 0.0033979464787989855f, 0.0033217077143490314f, 0.004126436542719603f, 0.00435124384239316f, 0.004121549427509308f, 0.0038676862604916096f, 0.004171481356024742f, 0.0036255212035030127f, 0.003853175789117813f, 0.0031272454652935266f, 0.0033538248389959335f, 0.0037400489673018456f, 0.004161571618169546f, 0.0038523413240909576f, 0.004082819912582636f, 0.00397453224286437f, 0.0041042594239115715f, 0.003406716277822852f, 0.004060358740389347f, 0.0033030244521796703f, 0.003911598585546017f, 0.003598912386223674f, 0.0033983171451836824f, 0.0033244984224438667f, 0.003917078487575054f, 0.003810863709077239f, 0.0035392967984080315f, 0.004076141864061356f, 0.0032399501651525497f, 0.0035825250670313835f, 0.0037887967191636562f, 0.0034658743534237146f, 0.004923576954752207f, 0.0037815668620169163f, 0.004306468181312084f, 0.0036415415816009045f, 0.005419928580522537f, 0.0034398981370031834f, 0.004198750015348196f, 0.0041436259634792805f, 0.0037347155157476664f, 0.005426941905170679f, 0.005220815073698759f, 0.003001410746946931f, 0.0033461847342550755f, 0.004142788704484701f, 0.004206974059343338f, 0.004153857938945293f, 0.005149049684405327f, 0.0033035746309906244f, 0.004102028906345367f, 0.004466928541660309f, 0.003459393046796322f, 0.004695061594247818f, 0.003192311618477106f, 0.004960471764206886f, 0.004678432364016771f, 0.003454388352110982f, 0.0036572555545717478f, 0.004506152588874102f, 0.004157997667789459f, 0.003855086164548993f, 0.004047448746860027f, 0.0032528992742300034f, 0.0031916447915136814f, 0.003914966247975826f, 0.003505163360387087f, 0.006585283670574427f, 0.004344310611486435f, 0.004599435720592737f, 0.0035100169479846954f, 0.0038444832898676395f, 0.0033834646455943584f, 0.004003350622951984f, 0.00420225178822875f, 0.0038245401810854673f, 0.004241290036588907f, 0.003688027150928974f, 0.0036127702333033085f, 0.005398440174758434f, 0.003105719108134508f, 0.004005788825452328f, 0.005779620725661516f, 0.005785456858575344f, 0.0033214506693184376f, 0.00358084705658257f, 0.003359256312251091f, 0.005698921158909798f, 0.003717217594385147f, 0.004625357687473297f, 0.005211648065596819f, 0.004571720026433468f, 0.004278083331882954f, 0.0039446596056222916f, 0.0038785599172115326f, 0.003817210905253887f, 0.00523017905652523f, 0.003970299381762743f, 0.006923343054950237f, 0.003713170764967799f, 0.0033579959999769926f, 0.0034032564144581556f, 0.004482343792915344f, 0.0032880061771720648f, 0.0036915855016559362f, 0.004144938196986914f, 0.004888671450316906f, 0.003922427073121071f, 0.004262295551598072f, 0.0038386518135666847f, 0.003214051714166999f, 0.0032410144340246916f, 0.004596067126840353f, 0.0037974808365106583f, 0.004636260215193033f, 0.004012779798358679f, 0.0035720285959541798f, 0.004115900956094265f, 0.0031793650705367327f, 0.004722312092781067f, 0.004841194953769445f, 0.003152833553031087f, 0.00377991353161633f, 0.0036642816849052906f, 0.004059858154505491f, 0.0031551532447338104f, 0.004072639625519514f, 0.003970149904489517f, 0.0037611115258187056f, 0.003861056873574853f, 0.004342364612966776f, 0.003719653934240341f, 0.0035633568186312914f, 0.003688241820782423f, 0.0035809515975415707f, 0.003973361570388079f, 0.004169093910604715f, 0.0031605239491909742f, 0.0037840595468878746f, 0.004318686667829752f, 0.004346385598182678f, 0.0035405000671744347f, 0.0032194769009947777f, 0.003782112617045641f, 0.004200844094157219f, 0.00346943037584424f, 0.004298144951462746f, 0.003203001106157899f, 0.00426093116402626f, 0.004389071837067604f, 0.003562566824257374f, 0.0037465740460902452f, 0.003922441974282265f, 0.0036037294194102287f, 0.0054223062470555305f, 0.003808380337432027f, 0.004504825454205275f, 0.004984700586646795f, 0.0034064396750181913f, 0.004675333853811026f, 0.003728574840351939f, 0.003573769936338067f, 0.004096942022442818f, 0.005298291798681021f, 0.004652389325201511f, 0.0032641575671732426f, 0.0034198560751974583f, 0.003755254205316305f, 0.004505309741944075f, 0.0036802904214709997f, 0.003964756149798632f, 0.003509960602968931f, 0.004345394670963287f, 0.003441914450377226f, 0.0041640279814600945f, 0.0034352662041783333f, 0.00451092841103673f, 0.004927424248307943f, 0.0037634146865457296f, 0.0032375187147408724f, 0.0040099965408444405f, 0.003226038534194231f, 0.003193993354216218f, 0.003271788125857711f, 0.0028674043715000153f, 0.0034625413827598095f, 0.00473668472841382f, 0.004426618106663227f, 0.00339365191757679f, 0.0038227688055485487f, 0.0037828937638550997f, 0.0038020992651581764f, 0.004168372135609388f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #170 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1280,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00027937174309045076f, 0.00031731350463815033f, 0.00046358193503692746f, 0.00031055169529281557f, 0.0003678789362311363f, 0.0004173171182628721f, 0.00032903486862778664f, 0.00032393159926868975f, 0.0003887320344801992f, 0.0003368504112586379f, 0.0004049304116051644f, 0.00036298262421041727f, 0.0003218324272893369f, 0.00034262906410731375f, 0.0004612402699422091f, 0.00047396670561283827f, 0.0003713840269483626f, 0.00029259067378006876f, 0.0003087005752604455f, 0.00036739252391271293f, 0.0003450953518040478f, 0.0003612840664573014f, 0.0003441361477598548f, 0.000406089355237782f, 0.00036813103361055255f, 0.0003491562092676759f, 0.00036191451363265514f, 0.00031174844480119646f, 0.0003981458430644125f, 0.00030484425951726735f, 0.00030767699354328215f, 0.0003050410305149853f, 0.0004098557692486793f, 0.00030170439276844263f, 0.00034046793007291853f, 0.0003840184072032571f, 0.00029733317205682397f, 0.00031363347079604864f, 0.0004006487724836916f, 0.00025634191115386784f, 0.00033320178044959903f, 0.00031701059197075665f, 0.0003128226671833545f, 0.00043226993875578046f, 0.00035403307992964983f, 0.00034389609936624765f, 0.0003152956778649241f, 0.0003148583055008203f, 0.0004579506057780236f, 0.0003380214620847255f, 0.00041303259786218405f, 0.00045226450311020017f, 0.00032223810558207333f, 0.0003443440073169768f, 0.0003889298241119832f, 0.00042388244764879346f, 0.0005600599688477814f, 0.00042431653128005564f, 0.000467536534415558f, 0.00037149598938412964f, 0.0004809056408703327f, 0.0003630955470725894f, 0.00029408009140752256f, 0.00031034828862175345f, 0.00034629617584869266f, 0.0005065684672445059f, 0.00038773127016611397f, 0.0003197560436092317f, 0.00032608580659143627f, 0.0003059798036701977f, 0.0004949854919686913f, 0.0003131866978947073f, 0.00044871840509586036f, 0.00035700463922694325f, 0.0003452210803516209f, 0.0003822494763880968f, 0.0003281001409050077f, 0.0003551336412783712f, 0.0003374301304575056f, 0.00030380900716409087f, 0.0003927112848032266f, 0.000418732495745644f, 0.00026882911333814263f, 0.0003412897640373558f, 0.0003823278530035168f, 0.00039266544627025723f, 0.0004365742497611791f, 0.0003406050964258611f, 0.0004280056746210903f, 0.0003231408481951803f, 0.0003273315087426454f, 0.0004312160308472812f, 0.00037070963298901916f, 0.00032447275589220226f, 0.0003977020096499473f, 0.0004043309309054166f, 0.00028721761191263795f, 0.0002770996652543545f, 0.0003785023873206228f, 0.0003151536511722952f, 0.00040712705231271684f, 0.00034964102087542415f, 0.00032736960565671325f, 0.00029337548767216504f, 0.0004286159237381071f, 0.0002991958172060549f, 0.00038160986150614917f, 0.0004758639552164823f, 0.0004616357327904552f, 0.000330051378114149f, 0.0003559884207788855f, 0.0003232522285543382f, 0.0003670790756586939f, 0.00033696263562887907f, 0.00040101230842992663f, 0.00040931341936811805f, 0.000344045547535643f, 0.0003154882579110563f, 0.00034814063110388815f, 0.0002959617995657027f, 0.00026370654813945293f, 0.0003621468786150217f, 0.0004753182583954185f, 0.00040711063775233924f, 0.0004049269773531705f, 0.00030262197833508253f, 0.00041261548176407814f, 0.000417071336414665f, 0.0003041424788534641f, 0.00036849599564448f, 0.00032793014543130994f, 0.0002756621688604355f, 0.00033437417005188763f, 0.00036598026053979993f, 0.0003712759062182158f, 0.00031150481663644314f, 0.0003966420772485435f, 0.0003358476678840816f, 0.00038648254121653736f, 0.0004859599284827709f, 0.00025934577570296824f, 0.00041701956070028245f, 0.0003216624609194696f, 0.0003320108517073095f, 0.000306358007946983f, 0.00031414435943588614f, 0.0002819811925292015f, 0.0004080144572071731f, 0.00032123300479725003f, 0.00042516275425441563f, 0.0004946296685375273f, 0.00040461859316565096f, 0.00034416140988469124f, 0.00033160182647407055f, 0.00035950422170571983f, 0.00040627940325066447f, 0.0003620826464612037f, 0.0003197506594005972f, 0.0002919420076068491f, 0.0005771759897470474f, 0.0003152076678816229f, 0.00040179971256293356f, 0.00034746224991977215f, 0.0003158921026624739f, 0.00030135028646327555f, 0.0003571423585526645f, 0.00037778561818413436f, 0.0002547246986068785f, 0.00034132375731132925f, 0.00031309883343055844f, 0.00039380844100378454f, 0.00031540205236524343f, 0.00037118661566637456f, 0.00031799307907931507f, 0.00040347763570025563f, 0.0003131031116936356f, 0.00038747681537643075f, 0.0003481204330455512f, 0.0004175396461505443f, 0.00038396683521568775f, 0.00039481508429162204f, 0.0003583112556952983f, 0.0004096347256563604f, 0.00031021589529700577f, 0.0003901268064510077f, 0.00037334696389734745f, 0.0004058326594531536f, 0.00030117755522951484f, 0.00034675869392231107f, 0.0002927370951510966f, 0.0004324221226852387f, 0.0003853816888295114f, 0.0002852843317668885f, 0.00033749875728972256f, 0.0003780734841711819f, 0.0003841161960735917f, 0.00032287443173117936f, 0.000378867523977533f, 0.00032795750303193927f, 0.00043248949805274606f, 0.0003385561576578766f, 0.00032362565980292857f, 0.0002967498730868101f, 0.00027905197930522263f, 0.0004502782830968499f, 0.0003957917506340891f, 0.00036955432733520865f, 0.00033351086312904954f, 0.0003253624017816037f, 0.0003608762635849416f, 0.00031214396585710347f, 0.0003689141885843128f, 0.00032957555959001184f, 0.0004365225322544575f, 0.0003717609797604382f, 0.00035989744355902076f, 0.0003062287578359246f, 0.00038007786497473717f, 0.00031178005156107247f, 0.0004392920818645507f, 0.0003436948754824698f, 0.0003000858996529132f, 0.0002863607369363308f, 0.0003386650641914457f, 0.0004041131760459393f, 0.0003709414741024375f, 0.0004020703781861812f, 0.0004775722627528012f, 0.00034461176255717874f, 0.0005948967300355434f, 0.00033980136504396796f, 0.00032491027377545834f, 0.000376117997802794f, 0.00035408491385169327f, 0.00032775592990219593f, 0.00039678020402789116f, 0.0004290155484341085f, 0.0004517845227383077f, 0.00052078120643273f, 0.0003619503113441169f, 0.0003956282453145832f, 0.00039565577753819525f, 0.0004195129731670022f, 0.00059740204596892f, 0.00030212331330403686f, 0.00029075771453790367f, 0.00036357485805638134f, 0.00030466189491562545f, 0.00035394696169532835f, 0.0003991172125097364f, 0.0004333454999141395f, 0.00042175137787126005f, 0.0003689998702611774f, 0.00036585141788236797f, 0.0004323798348195851f, 0.00034391728695482016f, 0.00039462067070417106f, 0.00034105448867194355f, 0.00030902313301339746f, 0.0004028532712254673f, 0.00039978278800845146f, 0.0003306058933958411f, 0.00033429739414714277f, 0.00031617001513950527f, 0.0003773678035940975f, 0.0003605938982218504f, 0.00043879501754418015f, 0.00035310524981468916f, 0.00042797811329364777f, 0.00038789643440395594f, 0.0003337011730764061f, 0.0003797065874096006f, 0.00031597138149663806f, 0.00038592374767176807f, 0.00036127393832430243f, 0.000323641172144562f, 0.0005993490922264755f, 0.0003656677436083555f, 0.00029960385290905833f, 0.0005726096569560468f, 0.0004471559659577906f, 0.00033227980020456016f, 0.00030119772418402135f, 0.00036203672061674297f, 0.0003753100463654846f, 0.00046069020754657686f, 0.0003667188575491309f, 0.0003457888087723404f, 0.0003234391624573618f, 0.0003424042952246964f, 0.0004889515112154186f, 0.0004134800110477954f, 0.0002994810638483614f, 0.0003050527011509985f, 0.0003593737492337823f, 0.00036372136673890054f, 0.0004180478281341493f, 0.0005338868359103799f, 0.0003779351827688515f, 0.0003290717431809753f, 0.00036966908373869956f, 0.0003548554377630353f, 0.0003041450690943748f, 0.0003253101313021034f, 0.0002882125845644623f, 0.0003958104643970728f, 0.0002989403437823057f, 0.00028600869700312614f, 0.00031092725112102926f, 0.0004311756929382682f, 0.0004539208603091538f, 0.0003501629107631743f, 0.0003701806126628071f, 0.00043601461220532656f, 0.0003354057262185961f, 0.0004057189216837287f, 0.00037359390989877284f, 0.00041681082802824676f, 0.00036953663220629096f, 0.000355683354428038f, 0.0004378768499009311f, 0.00041323041659779847f, 0.00038562543340958655f, 0.0003267312713433057f, 0.0003155841550324112f, 0.00034296882222406566f, 0.0003266828425694257f, 0.0003086969954892993f, 0.00029560105758719146f, 0.00031409828807227314f, 0.0002890217292588204f, 0.0002994173264596611f, 0.00047939622891135514f, 0.00032786597148515284f, 0.00038657509139738977f, 0.0003371832426637411f, 0.0004473026201594621f, 0.00042552160448394716f, 0.00033472295035608113f, 0.0003593487199395895f, 0.0003834102244582027f, 0.0002918508544098586f, 0.0003247306158300489f, 0.0002988629275932908f, 0.000343251449521631f, 0.00034918333403766155f, 0.0003292222390882671f, 0.00034017415600828826f, 0.0003706973511725664f, 0.00030901862191967666f, 0.00044986236025579274f, 0.00043938320595771074f, 0.0005077553796581924f, 0.00038761136238463223f, 0.000521198904607445f, 0.00032977230148389935f, 0.00030923454323783517f, 0.0002955061208922416f, 0.0004530098522081971f, 0.00031063437927514315f, 0.0003368805337231606f, 0.0004037027829326689f, 0.0003510386450216174f, 0.0003019596333615482f, 0.0003516213328111917f, 0.0003961448965128511f, 0.0003118549066130072f, 0.0003108310920652002f, 0.00045274553121998906f, 0.00031455818680115044f, 0.00041050786967389286f, 0.0003062903415411711f, 0.00032960978569462895f, 0.00038837746251374483f, 0.00036669717519544065f, 0.00047302860184572637f, 0.0003703950496856123f, 0.00046278099762275815f, 0.0002713672583922744f, 0.00030326953856274486f, 0.00039092713268473744f, 0.000296879094094038f, 0.00030965282348915935f, 0.00040051969699561596f, 0.0003162437351420522f, 0.00038128712913021445f, 0.00036384945269674063f, 0.00041571978363208473f, 0.00045272064744494855f, 0.0003238365752622485f, 0.00031523374491371214f, 0.0003906492202077061f, 0.0002991905785165727f, 0.0004101403465028852f, 0.0004263113369233906f, 0.0003620828501880169f, 0.0003623662341851741f, 0.0003301106917206198f, 0.0003953943378292024f, 0.0003532858972903341f, 0.00031324438168667257f, 0.00032166187884286046f, 0.0003928803780581802f, 0.0003244709223508835f, 0.0003417531552258879f, 0.00036643684143200517f, 0.00041056438931263983f, 0.00037433646502904594f, 0.000611671304795891f, 0.0004132190952077508f, 0.00037910230457782745f, 0.000413457426475361f, 0.00031426604255102575f, 0.00036228104727342725f, 0.00033136288402602077f, 0.00044645718298852444f, 0.00040146103128790855f, 0.0003804251318797469f, 0.00044233884545974433f, 0.00032543856650590897f, 0.0003933901316486299f, 0.00045232317643240094f, 0.0003966561343986541f, 0.00032373174326494336f, 0.0003043635515496135f, 0.000370256369933486f, 0.0003135171427857131f, 0.0003691433521453291f, 0.00037270330358296633f, 0.00033787189750000834f, 0.0003303044359199703f, 0.0004024392110295594f, 0.00035030770231969655f, 0.0003967718512285501f, 0.0003491488459985703f, 0.00033603169140405953f, 0.00034283273271285f, 0.00038932013558223844f, 0.0003540267643984407f, 0.0003468245267868042f, 0.0003727930597960949f, 0.0003183679946232587f, 0.00046164749073795974f, 0.00030388266895897686f, 0.00038572060293518007f, 0.00031709144241176546f, 0.0003405112656764686f, 0.00036662269849330187f, 0.0005009312299080193f, 0.0004353380936663598f, 0.0002953523362521082f, 0.00040721092955209315f, 0.0004782936302945018f, 0.00033937214175239205f, 0.00035628967452794313f, 0.0003765630244743079f, 0.000357070384779945f, 0.00029326905496418476f, 0.00032169942278414965f, 0.00027368261362425983f, 0.0006241569644771516f, 0.00046704369015060365f, 0.00028123133233748376f, 0.0003055692359339446f, 0.0003979477332904935f, 0.0003311029577162117f, 0.00032643057056702673f, 0.0003929527010768652f, 0.00046851669321767986f, 0.0003142529458273202f, 0.00034353401861153543f, 0.00039524471503682435f, 0.0003004560712724924f, 0.00031825294718146324f, 0.00032860366627573967f, 0.00044305791379883885f, 0.0003064791962970048f, 0.0004139331867918372f, 0.000394107133615762f, 0.0003827683685813099f, 0.0004300858126953244f, 0.0003540912002790719f, 0.0002463340642862022f, 0.0004058839112985879f, 0.0004907367401756346f, 0.00031895589199848473f, 0.00043457545689307153f, 0.00040537278982810676f, 0.00028701225528493524f, 0.00032386757084168494f, 0.0003180124913342297f, 0.0004029207630082965f, 0.00032845843816176057f, 0.00033311606966890395f, 0.00040600376087240875f, 0.0003343306598253548f, 0.0004074604657944292f, 0.00045321392826735973f, 0.0003372782957740128f, 0.0003770571784116328f, 0.0003195729514118284f, 0.00047939454088918865f, 0.00032581319101154804f, 0.00035151641350239515f, 0.00033512854133732617f, 0.0004054314340464771f, 0.00044449916458688676f, 0.00035184677108190954f, 0.0003312657354399562f, 0.0002659114252310246f, 0.000310094648739323f, 0.00032659934367984533f, 0.0003044600016437471f, 0.00043308004387654364f, 0.00031476374715566635f, 0.00041062902892008424f, 0.0003834802773781121f, 0.00042296855826862156f, 0.00041437693289481103f, 0.00033068854827433825f, 0.0003173489239998162f, 0.0003879956202581525f, 0.0005045698489993811f, 0.000390621367841959f, 0.000362938764737919f, 0.0003204506356269121f, 0.0004412935522850603f, 0.00045777493505738676f, 0.000439965893747285f, 0.0003088072407990694f, 0.0006003711023367941f, 0.00033344427356496453f, 0.00034266861621290445f, 0.000283159373793751f, 0.00039179419400170445f, 0.00042287478572688997f, 0.00034055867581628263f, 0.0003195044118911028f, 0.0003591719432733953f, 0.0003020322765223682f, 0.00035644209128804505f, 0.000500155205372721f, 0.00045075934031046927f, 0.0002951986971311271f, 0.00030278105987235904f, 0.0003712952893693f, 0.0004029845295008272f, 0.00035569959436543286f, 0.0002774036838673055f, 0.00037829080247320235f, 0.0004848325625061989f, 0.0005972912767902017f, 0.000357731303665787f, 0.0003253894974477589f, 0.0003623536031227559f, 0.0003090355603490025f, 0.0003697016800288111f, 0.0003659524372778833f, 0.0004648293543141335f, 0.0003466734488029033f, 0.00039615665446035564f, 0.0003724089474417269f, 0.0003793927899096161f, 0.0003369989572092891f, 0.0003851971705444157f, 0.0003461764135863632f, 0.0003645794349722564f, 0.0004493985907174647f, 0.0003274835762567818f, 0.00029240144067443907f, 0.0004290676733944565f, 0.00045444327406585217f, 0.0004705363535322249f, 0.00032555402140133083f, 0.0003847096813842654f, 0.00033490764326415956f, 0.00031636058702133596f, 0.0003135806182399392f, 0.00032707423088140786f, 0.00027940847212448716f, 0.00035480299266055226f, 0.000390020664781332f, 0.00034515789593569934f, 0.00045050037442706525f, 0.0005536659737117589f, 0.000438567774835974f, 0.00030400563264265656f, 0.0003850618959404528f, 0.0004816492146346718f, 0.00035709943040274084f, 0.00035217212280258536f, 0.00039460029802285135f, 0.0003813060757238418f, 0.0004195817746222019f, 0.0004225509474053979f, 0.00035431882133707404f, 0.00033044282463379204f, 0.0002983028825838119f, 0.0002685284416656941f, 0.00029721506871283054f, 0.0003489853406790644f, 0.0003227323468308896f, 0.0004800465248990804f, 0.000338847836246714f, 0.0003973381535615772f, 0.00037488635280169547f, 0.0003380846173968166f, 0.00043116140295751393f, 0.00037042706389911473f, 0.0003085013886447996f, 0.00047738070134073496f, 0.00040565707604400814f, 0.00030250835698097944f, 0.00035474804462864995f, 0.0003259019285906106f, 0.0003777515667025f, 0.0004388889065012336f, 0.00041369261452928185f, 0.00039079098496586084f, 0.0003548925160430372f, 0.00039465707959607244f, 0.00041415999294258654f, 0.00038460714858956635f, 0.00030799233354628086f, 0.0005521345883607864f, 0.0003815031668636948f, 0.00036759450449608266f, 0.0002741269127000123f, 0.00042627975926734507f, 0.0003378910478204489f, 0.0003912566462531686f, 0.00035341319744475186f, 0.00035959784872829914f, 0.00035121943801641464f, 0.00040203420212492347f, 0.0003636318724602461f, 0.0004119354416616261f, 0.0002943500585388392f, 0.0003756500082090497f, 0.0003290876920800656f, 0.0005513572250492871f, 0.00037667961441911757f, 0.0003682201204355806f, 0.00031008358928374946f, 0.0004084912652615458f, 0.0004278038104530424f, 0.0003605670644901693f, 0.00030401127878576517f, 0.00027728165150620043f, 0.0004169517196714878f, 0.0003173526201862842f, 0.00033112496021203697f, 0.00051739695481956f, 0.0002789860882330686f, 0.0003700577071867883f, 0.0005303630605340004f, 0.00029075806378386915f, 0.00035033567110076547f, 0.00031326935277320445f, 0.00033892254577949643f, 0.0003488417132757604f, 0.00030676068854518235f, 0.00040480695315636694f, 0.00037846562918275595f, 0.0003603273944463581f, 0.0003198592457920313f, 0.00038065636181272566f, 0.0003161767963320017f, 0.00029851941508241f, 0.0004183913115411997f, 0.00040695007191970944f, 0.00037440453888848424f, 0.00033618652378208935f, 0.00035117240622639656f, 0.00035494743497110903f, 0.0003517667355481535f, 0.0003225191030651331f, 0.00039405381539836526f, 0.00033904911833815277f, 0.0003641504154074937f, 0.0003528552479110658f, 0.0005196238053031266f, 0.0002874207275453955f, 0.00043006500345654786f, 0.00043118814937770367f, 0.0003341569972690195f, 0.00028291367925703526f, 0.0003091929538641125f, 0.0004363670013844967f, 0.0003198047343175858f, 0.0003618453920353204f, 0.00026229844661429524f, 0.00039998229476623237f, 0.00032170716440305114f, 0.00031850309460423887f, 0.0004060303035657853f, 0.0003780980478040874f, 0.00037572463043034077f, 0.0003836899413727224f, 0.0003989729448221624f, 0.00033250992419198155f, 0.00030919964774511755f, 0.0003157441096846014f, 0.00030132592655718327f, 0.0003591709246393293f, 0.0004054228193126619f, 0.00044653905206359923f, 0.00036531867226585746f, 0.0005103097064420581f, 0.0003425306349527091f, 0.0003067714860662818f, 0.00033929175697267056f, 0.00037635164335370064f, 0.0003445323964115232f, 0.00031405402114614844f, 0.000380739540560171f, 0.0002921121194958687f, 0.0004073395684827119f, 0.00045570367365144193f, 0.00031775853130966425f, 0.0003376197419129312f, 0.00041362413321621716f, 0.0004595888312906027f, 0.0005531857605092227f, 0.0003832750953733921f, 0.00033385201822966337f, 0.00028891462716273963f, 0.00033202418126165867f, 0.00032820008345879614f, 0.00039135172846727073f, 0.00034909520763903856f, 0.00040377944242209196f, 0.000430381071055308f, 0.00039448236930184066f, 0.0004279986605979502f, 0.00034120731288567185f, 0.00034515978768467903f, 0.00040055278805084527f, 0.0003895809641107917f, 0.00033774340408854187f, 0.0002963621518574655f, 0.00031642423709854484f, 0.00034765503369271755f, 0.0005727382376790047f, 0.00033766665728762746f, 0.0003466769412625581f, 0.0003650477447081357f, 0.0003697986830957234f, 0.0003521419130265713f, 0.000297331454930827f, 0.00039467494934797287f, 0.0004456329334061593f, 0.00039578787982463837f, 0.00031835143454372883f, 0.000356868578819558f, 0.00034940874320454895f, 0.0004227115132380277f, 0.0003720948880072683f, 0.0003632834122981876f, 0.0003690184385050088f, 0.0003307214064989239f, 0.000403258774895221f, 0.00031895333086140454f, 0.0004259397101122886f, 0.00034037523437291384f, 0.00033265494857914746f, 0.00027799111558124423f, 0.00042253307765349746f, 0.0003676717169582844f, 0.0004147870931774378f, 0.00034807153861038387f, 0.0003731620672624558f, 0.00038913905154913664f, 0.0003200760402251035f, 0.00037893358967266977f, 0.0004135250928811729f, 0.0003275424533057958f, 0.0003704535192809999f, 0.00037054269341751933f, 0.0005477644735947251f, 0.0004099365323781967f, 0.00039057215326465666f, 0.00032982591073960066f, 0.0004589109739754349f, 0.00033917088876478374f, 0.0003532350528985262f, 0.00040481361793354154f, 0.00028674720670096576f, 0.00034142142976634204f, 0.0003802223945967853f, 0.0004303822061046958f, 0.0004617898375727236f, 0.00031274918001145124f, 0.00028461741749197245f, 0.00035282637691125274f, 0.00036245270166546106f, 0.0003518166486173868f, 0.00035897945053875446f, 0.0003499913145788014f, 0.0002743974037002772f, 0.0003398471453692764f, 0.00039670401019975543f, 0.000319764920277521f, 0.00031627286807633936f, 0.0003136034356430173f, 0.00032142820418812335f, 0.0002866070135496557f, 0.0003309399471618235f, 0.0003502289764583111f, 0.0002791697334032506f, 0.0004021923814434558f, 0.00029602841823361814f, 0.0003963771159760654f, 0.0004442133358679712f, 0.000364543724572286f, 0.0003896608832292259f, 0.00036782879033125937f, 0.0002941621351055801f, 0.00030473212245851755f, 0.0003316832589916885f, 0.00032190303318202496f, 0.00033799291122704744f, 0.00034918441087938845f, 0.0003248584980610758f, 0.0004423906502779573f, 0.0003562075144145638f, 0.00034283704007975757f, 0.0002763584489002824f, 0.00038678813143633306f, 0.0004133912443649024f, 0.00030697163310833275f, 0.00041498406790196896f, 0.00033035362139344215f, 0.00028159431531094015f, 0.00040039484156295657f, 0.000342320476192981f, 0.00039878743700683117f, 0.0002957385149784386f, 0.00031577475601807237f, 0.0004079553473275155f, 0.0003436412662267685f, 0.0003825575695373118f, 0.0003952647384721786f, 0.00035256234696134925f, 0.0003329402534291148f, 0.00036295343306846917f, 0.00042571144877001643f, 0.00033779474324546754f, 0.0004235370724927634f, 0.00028986664256080985f, 0.00038797329762019217f, 0.00030650856206193566f, 0.0002792003797367215f, 0.0002943967701867223f, 0.00029200135031715035f, 0.00032726689823903143f, 0.0003455973055679351f, 0.00039200307219289243f, 0.000309712573653087f, 0.0003885502810589969f, 0.0003421219007577747f, 0.00033476841053925455f, 0.0003120081382803619f, 0.000280305597698316f, 0.000398562871851027f, 0.0003278442600276321f, 0.00034110748674720526f, 0.0002909064933191985f, 0.0003392052894923836f, 0.0004067572299391031f, 0.00031898755696602166f, 0.00037572559085674584f, 0.0004469671403057873f, 0.000372387352399528f, 0.0004174332716502249f, 0.0003899571893271059f, 0.000249909091508016f, 0.0002819971996359527f, 0.0003398772969376296f, 0.0003905214252881706f, 0.00030427228193730116f, 0.00031624696566723287f, 0.0003996450686827302f, 0.00032726346398703754f, 0.0003076068533118814f, 0.0004169554158579558f, 0.0004250529455021024f, 0.0003495612181723118f, 0.0004601880500558764f, 0.00042718322947621346f, 0.00039419735549017787f, 0.00034608133137226105f, 0.00032126743462868035f, 0.00030079775024205446f, 0.0003421081055421382f, 0.00046435368130914867f, 0.00028389127692207694f, 0.0004022753855679184f, 0.0004244140291120857f, 0.0003920570597983897f, 0.00027214980218559504f, 0.0002804788528010249f, 0.00038560654502362013f, 0.00034235179191455245f, 0.0004043624212499708f, 0.0003109428216703236f, 0.0003665714175440371f, 0.0003133590507786721f, 0.0004286645562388003f, 0.00029381891363300383f, 0.0003079835732933134f, 0.0004033208533655852f, 0.00030974679975770414f, 0.00038089347071945667f, 0.00034495635190978646f, 0.0003078231820836663f, 0.0003659529611468315f, 0.0004136815550737083f, 0.0005909673636779189f, 0.00031531727290712297f, 0.0003340412222314626f, 0.00035046125412918627f, 0.0003536757722031325f, 0.00041267165215685964f, 0.000354762130882591f, 0.0003364655131008476f, 0.00041141960537061095f, 0.00037871437962166965f, 0.0003082969633396715f, 0.00046850135549902916f, 0.00034741521812975407f, 0.0003492926771286875f, 0.00047445035306736827f, 0.00038693679380230606f, 0.00032978554372675717f, 0.00043605497921817005f, 0.0004149818269070238f, 0.0003347352030687034f, 0.0004451148852240294f, 0.00032763430499471724f, 0.0002712072164285928f, 0.00034173819585703313f, 0.0003373829822521657f, 0.0003074933192692697f, 0.00032227981137111783f, 0.0003609525738283992f, 0.00037450165837071836f, 0.0003807828761637211f, 0.0003586692037060857f, 0.00046820606803521514f, 0.0003409750934224576f, 0.00043982439092360437f, 0.00034979204065166414f, 0.00030391159816645086f, 0.0003204953682143241f, 0.00032203528098762035f, 0.0005082918796688318f, 0.0004041481006424874f, 0.00028213439509272575f, 0.00039740861393511295f, 0.00034482456976547837f, 0.0005161879234947264f, 0.0003906229103449732f, 0.0004967100103385746f, 0.00043700815876945853f, 0.0003011302906088531f, 0.00031419715378433466f, 0.00037342740688472986f, 0.00032848972477950156f, 0.0003535401774570346f, 0.00036119812284596264f, 0.00035763406776823103f, 0.00041787500958889723f, 0.00044520883238874376f, 0.0005514274816960096f, 0.00045003159902989864f, 0.00038581446278840303f, 0.0003813805233221501f, 0.00038416829193010926f, 0.0004452684661373496f, 0.0003769424220081419f, 0.0003666208649519831f, 0.0003530757676344365f, 0.0003093866107519716f, 0.0003640729410108179f, 0.0003398842818569392f, 0.0003863121091853827f, 0.00038666167529299855f, 0.0003368040779605508f, 0.0003183282387908548f, 0.0003738934174180031f, 0.0003478878061287105f, 0.0003888715582434088f, 0.0004494556051213294f, 0.0003914825210813433f, 0.0003553733986336738f, 0.00041815295116975904f, 0.0004261138674337417f, 0.00032112005283124745f, 0.000367861648555845f, 0.0003624634409788996f, 0.00028214987833052874f, 0.00028517100145109f, 0.0003479102160781622f, 0.0005803767708130181f, 0.00032796969753690064f, 0.00045999561552889645f, 0.0003418418928049505f, 0.000338275043759495f, 0.0003732309560291469f, 0.0005247105145826936f, 0.00034905056236311793f, 0.00034831539960578084f, 0.0003204414970241487f, 0.00033111474476754665f, 0.00029455439653247595f, 0.0003662073868326843f, 0.0003396548854652792f, 0.00039063714211806655f, 0.0003514518612064421f, 0.0004007912357337773f, 0.0003306213766336441f, 0.00031785969622433186f, 0.00032979989191517234f, 0.00037860963493585587f, 0.00046497740549966693f, 0.0003855152172036469f, 0.0003331257903482765f, 0.00033232176792807877f, 0.0002816984197124839f, 0.00030079486896283925f, 0.0003296238137409091f, 0.00036193348933011293f, 0.000288319744868204f, 0.000461520510725677f, 0.00031699653482064605f, 0.0003269536537118256f, 0.000320989522151649f, 0.0003516495635267347f, 0.00030331689049489796f, 0.00038573896745219827f, 0.00029429857386276126f, 0.000287967937765643f, 0.0004160628595855087f, 0.0003075472195632756f, 0.0004031274584122002f, 0.0003955656138714403f, 0.00039682627539150417f, 0.000344945234246552f, 0.0003872667148243636f, 0.0003730967582669109f, 0.0004915503668598831f, 0.00035760580794885755f, 0.0003279700467828661f, 0.0002902529377024621f, 0.00046551538980565965f, 0.0003600114432629198f, 0.0003280601231381297f, 0.00035943841794505715f, 0.00026480620726943016f, 0.0003883282479364425f, 0.00047029281267896295f, 0.00042517113615758717f, 0.00031855140696279705f, 0.00045437569497153163f, 0.0003327807935420424f, 0.00038859632331877947f, 0.00032773541170172393f, 0.00033566681668162346f, 0.0003968987730331719f, 0.0003027224447578192f, 0.00035953448968939483f, 0.0003651788574643433f, 0.0004444046353455633f, 0.0003109692770522088f, 0.0002671113470569253f, 0.00041912111919373274f, 0.0005231387913227081f, 0.00044645991874858737f, 0.0004928632406517863f, 0.0003833837399724871f, 0.0003845144819933921f, 0.00030761677771806717f, 0.0004176649381406605f, 0.00032544968416914344f, 0.0003876417176797986f, 0.000328900758177042f, 0.0003204707463737577f, 0.00031328044133260846f, 0.00038917685742489994f, 0.0004103791434317827f, 0.00038871594006195664f, 0.0003647733246907592f, 0.0003934251726604998f, 0.00034193400642834604f, 0.00036340480437502265f, 0.00029494010959751904f, 0.00031630948069505394f, 0.00035273548564873636f, 0.0003924905613530427f, 0.00036332610761746764f, 0.0003850632638204843f, 0.00037485032225959003f, 0.0003870852815452963f, 0.00032129784813150764f, 0.00038294485420919955f, 0.0003115183499176055f, 0.00036891482886858284f, 0.0003394244413357228f, 0.00032050570007413626f, 0.0003135436272714287f, 0.0003694316546898335f, 0.0003594142326619476f, 0.00033380193053744733f, 0.0003844334278255701f, 0.0003055696142837405f, 0.0003378789115231484f, 0.0003573330177459866f, 0.0003268772270530462f, 0.00046435761032626033f, 0.00035665114410221577f, 0.0004061562067363411f, 0.00034344493178650737f, 0.00051117007387802f, 0.0003244273248128593f, 0.00039599696174263954f, 0.00039079805719666183f, 0.00035223245504312217f, 0.0005118314875289798f, 0.0004923910601064563f, 0.00028307223692536354f, 0.0003155889280606061f, 0.0003907190985046327f, 0.00039677260792814195f, 0.00039176305290311575f, 0.00048562264419160783f, 0.0003115702420473099f, 0.00038687491905875504f, 0.0004212897038087249f, 0.00032626595930196345f, 0.0004428056417964399f, 0.0003010766813531518f, 0.00046783729339949787f, 0.0004412372945807874f, 0.00032579395337961614f, 0.0003449269861448556f, 0.00042498906259424984f, 0.00039215348078869283f, 0.0003635849861893803f, 0.0003817272954620421f, 0.00030679089832119644f, 0.0003010137879755348f, 0.00036923246807418764f, 0.0003305826976429671f, 0.0006210782448761165f, 0.00040972523856908083f, 0.0004337868595030159f, 0.0003310404426883906f, 0.0003625850076787174f, 0.0003191049036104232f, 0.0003775682707782835f, 0.00039632723201066256f, 0.0003607040853239596f, 0.0004000090411864221f, 0.00034782913280650973f, 0.0003407314361538738f, 0.0005091433995403349f, 0.0002929098845925182f, 0.00037779822014272213f, 0.0005450937314890325f, 0.0005456441431306303f, 0.000313256197841838f, 0.0003377206448931247f, 0.0003168217372149229f, 0.0005374827305786312f, 0.000350582180544734f, 0.0004362316394690424f, 0.0004915265017189085f, 0.0004311729280743748f, 0.0004034791490994394f, 0.0003720329259522259f, 0.0003657988563645631f, 0.0003600128402467817f, 0.0004932741867378354f, 0.000374451105017215f, 0.000652961665764451f, 0.0003502005129121244f, 0.0003167028771713376f, 0.00032097153598442674f, 0.000422743585659191f, 0.0003101019246969372f, 0.00034816472907550633f, 0.00039092180668376386f, 0.0004610655887518078f, 0.0003699361113831401f, 0.00040199013892561197f, 0.000362035003490746f, 0.00030312707531265914f, 0.0003056699933949858f, 0.00043346916208975017f, 0.0003581520577427f, 0.0004372599069029093f, 0.000378457538317889f, 0.0003368889447301626f, 0.0003881832235492766f, 0.00029985565925017f, 0.00044537571375258267f, 0.00045658793533220887f, 0.0002973533992189914f, 0.00035649523488245904f, 0.00034558962215669453f, 0.0003828976477961987f, 0.00029757217271253467f, 0.00038410312845371664f, 0.0003744369896594435f, 0.00035472193849273026f, 0.00036414808710105717f, 0.00040954170981422067f, 0.0003508119552861899f, 0.00033607109799049795f, 0.0003478493890725076f, 0.00033773051109164953f, 0.0003747399023268372f, 0.0003932000254280865f, 0.00029807869577780366f, 0.00035688624484464526f, 0.0004073085729032755f, 0.0004099209327250719f, 0.00033391540637239814f, 0.0003036387206520885f, 0.00035670262877829373f, 0.00039619446033611894f, 0.00032721259049139917f, 0.0004053712182212621f, 0.00030208483804017305f, 0.00040186147089116275f, 0.00041394680738449097f, 0.0003359965921845287f, 0.000353350886143744f, 0.000369937508367002f, 0.0003398787521291524f, 0.0005113942897878587f, 0.0003591800050344318f, 0.00042486388701945543f, 0.0004701223806478083f, 0.0003212717710994184f, 0.00044094506301917136f, 0.00035165331792086363f, 0.00033705317764542997f, 0.0003863951424136758f, 0.0004996981006115675f, 0.0004387810768093914f, 0.00030785269336774945f, 0.00032253708923235536f, 0.000354169518686831f, 0.00042490955092944205f, 0.00034709947067312896f, 0.00037392828380689025f, 0.0003310351457912475f, 0.00040982748032547534f, 0.0003246174892410636f, 0.0003927222278434783f, 0.0003239904763177037f, 0.00042543947347439826f, 0.0004647204768843949f, 0.0003549391694832593f, 0.0003053403052035719f, 0.0003781950508709997f, 0.0003042575845029205f, 0.000301235297229141f, 0.00030857237288728356f, 0.00027043369482271373f, 0.00032656287658028305f, 0.0004467312537599355f, 0.0004174878995399922f, 0.00032006570836529136f, 0.00036053702933713794f, 0.0003567762905731797f, 0.00035858762566931546f, 0.0003931319515686482f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #171 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.001333365449681878f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #172 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.6331084882258438e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #173 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0028666348662227392f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #174 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.00011966558889390817f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #175 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #176 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_3_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #177 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_5_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #178 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_7_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #179 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_9_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #180 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_10_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #181 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_13_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #182 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #183 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #184 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #185 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #186 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #187 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #188 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #189 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #190 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #191 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #192 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #193 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #194 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #195 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #196 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #197 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #198 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #199 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #200 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #201 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #202 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #203 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_scratch1_intq, AI_STATIC_CONST,
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
  sequential_3_input_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 1, 1, 3, 672),
  1, &sequential_3_input_output_array, &sequential_3_input_output_intq)

/* Tensor #1 */
AI_TENSOR_OBJ_DECLARE(
  conversion_0_output, AI_STATIC,
  1, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 1, 1, 3, 672),
  1, &conversion_0_output_array, &conversion_0_output_intq)

/* Tensor #2 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_output, AI_STATIC,
  2, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_2_output_array, &conv2d_2_output_intq)

/* Tensor #3 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_output, AI_STATIC,
  3, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_3_output_array, &conv2d_3_output_intq)

/* Tensor #4 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_output, AI_STATIC,
  4, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 112, 112), AI_STRIDE_INIT(4, 1, 1, 8, 896),
  1, &conv2d_4_output_array, &conv2d_4_output_intq)

/* Tensor #5 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_output, AI_STATIC,
  5, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 112, 112), AI_STRIDE_INIT(4, 1, 1, 48, 5376),
  1, &conv2d_5_output_array, &conv2d_5_output_intq)

/* Tensor #6 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_output, AI_STATIC,
  6, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_7_output_array, &conv2d_7_output_intq)

/* Tensor #7 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_output, AI_STATIC,
  7, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 1, 1, 8, 448),
  1, &conv2d_8_output_array, &conv2d_8_output_intq)

/* Tensor #8 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_output, AI_STATIC,
  8, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_9_output_array, &conv2d_9_output_intq)

/* Tensor #9 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_output, AI_STATIC,
  9, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_10_output_array, &conv2d_10_output_intq)

/* Tensor #10 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_output, AI_STATIC,
  10, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 1, 1, 8, 448),
  1, &conv2d_11_output_array, &conv2d_11_output_intq)

/* Tensor #11 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_12_output, AI_STATIC,
  11, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 56, 56), AI_STRIDE_INIT(4, 1, 1, 8, 448),
  1, &eltwise_12_output_array, &eltwise_12_output_intq)

/* Tensor #12 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_output, AI_STATIC,
  12, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_13_output_array, &conv2d_13_output_intq)

/* Tensor #13 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_output, AI_STATIC,
  13, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 28, 28), AI_STRIDE_INIT(4, 1, 1, 48, 1344),
  1, &conv2d_15_output_array, &conv2d_15_output_intq)

/* Tensor #14 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_output, AI_STATIC,
  14, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &conv2d_16_output_array, &conv2d_16_output_intq)

/* Tensor #15 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_output, AI_STATIC,
  15, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_17_output_array, &conv2d_17_output_intq)

/* Tensor #16 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_output, AI_STATIC,
  16, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_18_output_array, &conv2d_18_output_intq)

/* Tensor #17 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_output, AI_STATIC,
  17, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &conv2d_19_output_array, &conv2d_19_output_intq)

/* Tensor #18 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_20_output, AI_STATIC,
  18, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &eltwise_20_output_array, &eltwise_20_output_intq)

/* Tensor #19 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_output, AI_STATIC,
  19, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_21_output_array, &conv2d_21_output_intq)

/* Tensor #20 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_output, AI_STATIC,
  20, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_22_output_array, &conv2d_22_output_intq)

/* Tensor #21 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_output, AI_STATIC,
  21, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &conv2d_23_output_array, &conv2d_23_output_intq)

/* Tensor #22 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_24_output, AI_STATIC,
  22, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 28, 28), AI_STRIDE_INIT(4, 1, 1, 16, 448),
  1, &eltwise_24_output_array, &eltwise_24_output_intq)

/* Tensor #23 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_output, AI_STATIC,
  23, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_25_output_array, &conv2d_25_output_intq)

/* Tensor #24 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_output, AI_STATIC,
  24, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 14, 14), AI_STRIDE_INIT(4, 1, 1, 96, 1344),
  1, &conv2d_27_output_array, &conv2d_27_output_intq)

/* Tensor #25 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_output, AI_STATIC,
  25, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_28_output_array, &conv2d_28_output_intq)

/* Tensor #26 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_output, AI_STATIC,
  26, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_29_output_array, &conv2d_29_output_intq)

/* Tensor #27 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_output, AI_STATIC,
  27, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_30_output_array, &conv2d_30_output_intq)

/* Tensor #28 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_output, AI_STATIC,
  28, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_31_output_array, &conv2d_31_output_intq)

/* Tensor #29 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_32_output, AI_STATIC,
  29, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &eltwise_32_output_array, &eltwise_32_output_intq)

/* Tensor #30 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_output, AI_STATIC,
  30, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_33_output_array, &conv2d_33_output_intq)

/* Tensor #31 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_output, AI_STATIC,
  31, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_34_output_array, &conv2d_34_output_intq)

/* Tensor #32 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_output, AI_STATIC,
  32, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_35_output_array, &conv2d_35_output_intq)

/* Tensor #33 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_36_output, AI_STATIC,
  33, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &eltwise_36_output_array, &eltwise_36_output_intq)

/* Tensor #34 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_output, AI_STATIC,
  34, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_37_output_array, &conv2d_37_output_intq)

/* Tensor #35 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_output, AI_STATIC,
  35, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_38_output_array, &conv2d_38_output_intq)

/* Tensor #36 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_output, AI_STATIC,
  36, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &conv2d_39_output_array, &conv2d_39_output_intq)

/* Tensor #37 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_40_output, AI_STATIC,
  37, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 14, 14), AI_STRIDE_INIT(4, 1, 1, 24, 336),
  1, &eltwise_40_output_array, &eltwise_40_output_intq)

/* Tensor #38 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_output, AI_STATIC,
  38, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_41_output_array, &conv2d_41_output_intq)

/* Tensor #39 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_output, AI_STATIC,
  39, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_42_output_array, &conv2d_42_output_intq)

/* Tensor #40 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_output, AI_STATIC,
  40, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &conv2d_43_output_array, &conv2d_43_output_intq)

/* Tensor #41 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_output, AI_STATIC,
  41, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_44_output_array, &conv2d_44_output_intq)

/* Tensor #42 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_output, AI_STATIC,
  42, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_45_output_array, &conv2d_45_output_intq)

/* Tensor #43 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_output, AI_STATIC,
  43, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &conv2d_46_output_array, &conv2d_46_output_intq)

/* Tensor #44 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_47_output, AI_STATIC,
  44, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &eltwise_47_output_array, &eltwise_47_output_intq)

/* Tensor #45 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_output, AI_STATIC,
  45, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_48_output_array, &conv2d_48_output_intq)

/* Tensor #46 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_output, AI_STATIC,
  46, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_49_output_array, &conv2d_49_output_intq)

/* Tensor #47 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_output, AI_STATIC,
  47, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &conv2d_50_output_array, &conv2d_50_output_intq)

/* Tensor #48 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_51_output, AI_STATIC,
  48, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 14, 14), AI_STRIDE_INIT(4, 1, 1, 32, 448),
  1, &eltwise_51_output_array, &eltwise_51_output_intq)

/* Tensor #49 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_output, AI_STATIC,
  49, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_52_output_array, &conv2d_52_output_intq)

/* Tensor #50 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_output, AI_STATIC,
  50, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 7, 7), AI_STRIDE_INIT(4, 1, 1, 192, 1344),
  1, &conv2d_54_output_array, &conv2d_54_output_intq)

/* Tensor #51 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_output, AI_STATIC,
  51, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &conv2d_55_output_array, &conv2d_55_output_intq)

/* Tensor #52 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_output, AI_STATIC,
  52, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_56_output_array, &conv2d_56_output_intq)

/* Tensor #53 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_output, AI_STATIC,
  53, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_57_output_array, &conv2d_57_output_intq)

/* Tensor #54 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_output, AI_STATIC,
  54, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &conv2d_58_output_array, &conv2d_58_output_intq)

/* Tensor #55 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_59_output, AI_STATIC,
  55, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &eltwise_59_output_array, &eltwise_59_output_intq)

/* Tensor #56 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_output, AI_STATIC,
  56, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_60_output_array, &conv2d_60_output_intq)

/* Tensor #57 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_output, AI_STATIC,
  57, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_61_output_array, &conv2d_61_output_intq)

/* Tensor #58 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_output, AI_STATIC,
  58, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &conv2d_62_output_array, &conv2d_62_output_intq)

/* Tensor #59 */
AI_TENSOR_OBJ_DECLARE(
  eltwise_63_output, AI_STATIC,
  59, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 7, 7), AI_STRIDE_INIT(4, 1, 1, 56, 392),
  1, &eltwise_63_output_array, &eltwise_63_output_intq)

/* Tensor #60 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_output, AI_STATIC,
  60, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_64_output_array, &conv2d_64_output_intq)

/* Tensor #61 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_output, AI_STATIC,
  61, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_65_output_array, &conv2d_65_output_intq)

/* Tensor #62 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_output, AI_STATIC,
  62, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 7, 7), AI_STRIDE_INIT(4, 1, 1, 112, 784),
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
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 1, 1, 100, 100),
  1, &dense_69_output_array, &dense_69_output_intq)

/* Tensor #65 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_output, AI_STATIC,
  65, 0x1,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6, 6),
  1, &dense_70_output_array, &dense_70_output_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_fmt_output, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &dense_70_fmt_output_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  nl_71_output, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &nl_71_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  nl_71_fmt_output, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 1, 1, 6, 6),
  1, &nl_71_fmt_output_array, &nl_71_fmt_output_intq)

/* Tensor #69 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_weights, AI_STATIC,
  69, 0x1,
  AI_SHAPE_INIT(4, 3, 3, 3, 16), AI_STRIDE_INIT(4, 1, 3, 9, 27),
  1, &conv2d_2_weights_array, &conv2d_2_weights_intq)

/* Tensor #70 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_bias, AI_STATIC,
  70, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_2_bias_array, &conv2d_2_bias_intq)

/* Tensor #71 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_weights, AI_STATIC,
  71, 0x1,
  AI_SHAPE_INIT(4, 16, 3, 3, 1), AI_STRIDE_INIT(4, 1, 16, 48, 144),
  1, &conv2d_3_weights_array, &conv2d_3_weights_intq)

/* Tensor #72 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_bias, AI_STATIC,
  72, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_3_bias_array, &conv2d_3_bias_intq)

/* Tensor #73 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_weights, AI_STATIC,
  73, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 8), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_4_weights_array, &conv2d_4_weights_intq)

/* Tensor #74 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_bias, AI_STATIC,
  74, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_4_bias_array, &conv2d_4_bias_intq)

/* Tensor #75 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_weights, AI_STATIC,
  75, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_5_weights_array, &conv2d_5_weights_intq)

/* Tensor #76 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_bias, AI_STATIC,
  76, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_5_bias_array, &conv2d_5_bias_intq)

/* Tensor #77 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_weights, AI_STATIC,
  77, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_7_weights_array, &conv2d_7_weights_intq)

/* Tensor #78 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_bias, AI_STATIC,
  78, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_7_bias_array, &conv2d_7_bias_intq)

/* Tensor #79 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_weights, AI_STATIC,
  79, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_8_weights_array, &conv2d_8_weights_intq)

/* Tensor #80 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_bias, AI_STATIC,
  80, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_8_bias_array, &conv2d_8_bias_intq)

/* Tensor #81 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_weights, AI_STATIC,
  81, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_9_weights_array, &conv2d_9_weights_intq)

/* Tensor #82 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_bias, AI_STATIC,
  82, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_9_bias_array, &conv2d_9_bias_intq)

/* Tensor #83 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_weights, AI_STATIC,
  83, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_10_weights_array, &conv2d_10_weights_intq)

/* Tensor #84 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_bias, AI_STATIC,
  84, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_10_bias_array, &conv2d_10_bias_intq)

/* Tensor #85 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_weights, AI_STATIC,
  85, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 8), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_11_weights_array, &conv2d_11_weights_intq)

/* Tensor #86 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_bias, AI_STATIC,
  86, 0x1,
  AI_SHAPE_INIT(4, 1, 8, 1, 1), AI_STRIDE_INIT(4, 4, 4, 32, 32),
  1, &conv2d_11_bias_array, &conv2d_11_bias_intq)

/* Tensor #87 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_weights, AI_STATIC,
  87, 0x1,
  AI_SHAPE_INIT(4, 8, 1, 1, 48), AI_STRIDE_INIT(4, 1, 8, 8, 8),
  1, &conv2d_13_weights_array, &conv2d_13_weights_intq)

/* Tensor #88 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_bias, AI_STATIC,
  88, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_13_bias_array, &conv2d_13_bias_intq)

/* Tensor #89 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_weights, AI_STATIC,
  89, 0x1,
  AI_SHAPE_INIT(4, 48, 3, 3, 1), AI_STRIDE_INIT(4, 1, 48, 144, 432),
  1, &conv2d_15_weights_array, &conv2d_15_weights_intq)

/* Tensor #90 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_bias, AI_STATIC,
  90, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &conv2d_15_bias_array, &conv2d_15_bias_intq)

/* Tensor #91 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_weights, AI_STATIC,
  91, 0x1,
  AI_SHAPE_INIT(4, 48, 1, 1, 16), AI_STRIDE_INIT(4, 1, 48, 48, 48),
  1, &conv2d_16_weights_array, &conv2d_16_weights_intq)

/* Tensor #92 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_bias, AI_STATIC,
  92, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_16_bias_array, &conv2d_16_bias_intq)

/* Tensor #93 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_weights, AI_STATIC,
  93, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_17_weights_array, &conv2d_17_weights_intq)

/* Tensor #94 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_bias, AI_STATIC,
  94, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_17_bias_array, &conv2d_17_bias_intq)

/* Tensor #95 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_weights, AI_STATIC,
  95, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_18_weights_array, &conv2d_18_weights_intq)

/* Tensor #96 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_bias, AI_STATIC,
  96, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_18_bias_array, &conv2d_18_bias_intq)

/* Tensor #97 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_weights, AI_STATIC,
  97, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_19_weights_array, &conv2d_19_weights_intq)

/* Tensor #98 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_bias, AI_STATIC,
  98, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_19_bias_array, &conv2d_19_bias_intq)

/* Tensor #99 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_weights, AI_STATIC,
  99, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_21_weights_array, &conv2d_21_weights_intq)

/* Tensor #100 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_bias, AI_STATIC,
  100, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_21_bias_array, &conv2d_21_bias_intq)

/* Tensor #101 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_weights, AI_STATIC,
  101, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_22_weights_array, &conv2d_22_weights_intq)

/* Tensor #102 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_bias, AI_STATIC,
  102, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_22_bias_array, &conv2d_22_bias_intq)

/* Tensor #103 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_weights, AI_STATIC,
  103, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 16), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_23_weights_array, &conv2d_23_weights_intq)

/* Tensor #104 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_bias, AI_STATIC,
  104, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 1, 1), AI_STRIDE_INIT(4, 4, 4, 64, 64),
  1, &conv2d_23_bias_array, &conv2d_23_bias_intq)

/* Tensor #105 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_weights, AI_STATIC,
  105, 0x1,
  AI_SHAPE_INIT(4, 16, 1, 1, 96), AI_STRIDE_INIT(4, 1, 16, 16, 16),
  1, &conv2d_25_weights_array, &conv2d_25_weights_intq)

/* Tensor #106 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_bias, AI_STATIC,
  106, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_25_bias_array, &conv2d_25_bias_intq)

/* Tensor #107 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_weights, AI_STATIC,
  107, 0x1,
  AI_SHAPE_INIT(4, 96, 3, 3, 1), AI_STRIDE_INIT(4, 1, 96, 288, 864),
  1, &conv2d_27_weights_array, &conv2d_27_weights_intq)

/* Tensor #108 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_bias, AI_STATIC,
  108, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 1, 1), AI_STRIDE_INIT(4, 4, 4, 384, 384),
  1, &conv2d_27_bias_array, &conv2d_27_bias_intq)

/* Tensor #109 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_weights, AI_STATIC,
  109, 0x1,
  AI_SHAPE_INIT(4, 96, 1, 1, 24), AI_STRIDE_INIT(4, 1, 96, 96, 96),
  1, &conv2d_28_weights_array, &conv2d_28_weights_intq)

/* Tensor #110 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_bias, AI_STATIC,
  110, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_28_bias_array, &conv2d_28_bias_intq)

/* Tensor #111 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_weights, AI_STATIC,
  111, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_29_weights_array, &conv2d_29_weights_intq)

/* Tensor #112 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_bias, AI_STATIC,
  112, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_29_bias_array, &conv2d_29_bias_intq)

/* Tensor #113 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_weights, AI_STATIC,
  113, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_30_weights_array, &conv2d_30_weights_intq)

/* Tensor #114 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_bias, AI_STATIC,
  114, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_30_bias_array, &conv2d_30_bias_intq)

/* Tensor #115 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_weights, AI_STATIC,
  115, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_31_weights_array, &conv2d_31_weights_intq)

/* Tensor #116 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_bias, AI_STATIC,
  116, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_31_bias_array, &conv2d_31_bias_intq)

/* Tensor #117 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_weights, AI_STATIC,
  117, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_33_weights_array, &conv2d_33_weights_intq)

/* Tensor #118 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_bias, AI_STATIC,
  118, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_33_bias_array, &conv2d_33_bias_intq)

/* Tensor #119 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_weights, AI_STATIC,
  119, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_34_weights_array, &conv2d_34_weights_intq)

/* Tensor #120 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_bias, AI_STATIC,
  120, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_34_bias_array, &conv2d_34_bias_intq)

/* Tensor #121 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_weights, AI_STATIC,
  121, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_35_weights_array, &conv2d_35_weights_intq)

/* Tensor #122 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_bias, AI_STATIC,
  122, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_35_bias_array, &conv2d_35_bias_intq)

/* Tensor #123 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_weights, AI_STATIC,
  123, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_37_weights_array, &conv2d_37_weights_intq)

/* Tensor #124 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_bias, AI_STATIC,
  124, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_37_bias_array, &conv2d_37_bias_intq)

/* Tensor #125 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_weights, AI_STATIC,
  125, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_38_weights_array, &conv2d_38_weights_intq)

/* Tensor #126 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_bias, AI_STATIC,
  126, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_38_bias_array, &conv2d_38_bias_intq)

/* Tensor #127 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_weights, AI_STATIC,
  127, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 24), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_39_weights_array, &conv2d_39_weights_intq)

/* Tensor #128 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_bias, AI_STATIC,
  128, 0x1,
  AI_SHAPE_INIT(4, 1, 24, 1, 1), AI_STRIDE_INIT(4, 4, 4, 96, 96),
  1, &conv2d_39_bias_array, &conv2d_39_bias_intq)

/* Tensor #129 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_weights, AI_STATIC,
  129, 0x1,
  AI_SHAPE_INIT(4, 24, 1, 1, 144), AI_STRIDE_INIT(4, 1, 24, 24, 24),
  1, &conv2d_41_weights_array, &conv2d_41_weights_intq)

/* Tensor #130 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_bias, AI_STATIC,
  130, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_41_bias_array, &conv2d_41_bias_intq)

/* Tensor #131 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_weights, AI_STATIC,
  131, 0x1,
  AI_SHAPE_INIT(4, 144, 3, 3, 1), AI_STRIDE_INIT(4, 1, 144, 432, 1296),
  1, &conv2d_42_weights_array, &conv2d_42_weights_intq)

/* Tensor #132 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_bias, AI_STATIC,
  132, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 4, 4, 576, 576),
  1, &conv2d_42_bias_array, &conv2d_42_bias_intq)

/* Tensor #133 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_weights, AI_STATIC,
  133, 0x1,
  AI_SHAPE_INIT(4, 144, 1, 1, 32), AI_STRIDE_INIT(4, 1, 144, 144, 144),
  1, &conv2d_43_weights_array, &conv2d_43_weights_intq)

/* Tensor #134 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_bias, AI_STATIC,
  134, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_43_bias_array, &conv2d_43_bias_intq)

/* Tensor #135 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_weights, AI_STATIC,
  135, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_44_weights_array, &conv2d_44_weights_intq)

/* Tensor #136 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_bias, AI_STATIC,
  136, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_44_bias_array, &conv2d_44_bias_intq)

/* Tensor #137 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_weights, AI_STATIC,
  137, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_45_weights_array, &conv2d_45_weights_intq)

/* Tensor #138 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_bias, AI_STATIC,
  138, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_45_bias_array, &conv2d_45_bias_intq)

/* Tensor #139 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_weights, AI_STATIC,
  139, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_46_weights_array, &conv2d_46_weights_intq)

/* Tensor #140 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_bias, AI_STATIC,
  140, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_46_bias_array, &conv2d_46_bias_intq)

/* Tensor #141 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_weights, AI_STATIC,
  141, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_48_weights_array, &conv2d_48_weights_intq)

/* Tensor #142 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_bias, AI_STATIC,
  142, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_48_bias_array, &conv2d_48_bias_intq)

/* Tensor #143 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_weights, AI_STATIC,
  143, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_49_weights_array, &conv2d_49_weights_intq)

/* Tensor #144 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_bias, AI_STATIC,
  144, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_49_bias_array, &conv2d_49_bias_intq)

/* Tensor #145 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_weights, AI_STATIC,
  145, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 32), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_50_weights_array, &conv2d_50_weights_intq)

/* Tensor #146 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_bias, AI_STATIC,
  146, 0x1,
  AI_SHAPE_INIT(4, 1, 32, 1, 1), AI_STRIDE_INIT(4, 4, 4, 128, 128),
  1, &conv2d_50_bias_array, &conv2d_50_bias_intq)

/* Tensor #147 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_weights, AI_STATIC,
  147, 0x1,
  AI_SHAPE_INIT(4, 32, 1, 1, 192), AI_STRIDE_INIT(4, 1, 32, 32, 32),
  1, &conv2d_52_weights_array, &conv2d_52_weights_intq)

/* Tensor #148 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_bias, AI_STATIC,
  148, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_52_bias_array, &conv2d_52_bias_intq)

/* Tensor #149 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_weights, AI_STATIC,
  149, 0x1,
  AI_SHAPE_INIT(4, 192, 3, 3, 1), AI_STRIDE_INIT(4, 1, 192, 576, 1728),
  1, &conv2d_54_weights_array, &conv2d_54_weights_intq)

/* Tensor #150 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_bias, AI_STATIC,
  150, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 1, 1), AI_STRIDE_INIT(4, 4, 4, 768, 768),
  1, &conv2d_54_bias_array, &conv2d_54_bias_intq)

/* Tensor #151 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_weights, AI_STATIC,
  151, 0x1,
  AI_SHAPE_INIT(4, 192, 1, 1, 56), AI_STRIDE_INIT(4, 1, 192, 192, 192),
  1, &conv2d_55_weights_array, &conv2d_55_weights_intq)

/* Tensor #152 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_bias, AI_STATIC,
  152, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_55_bias_array, &conv2d_55_bias_intq)

/* Tensor #153 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_weights, AI_STATIC,
  153, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_56_weights_array, &conv2d_56_weights_intq)

/* Tensor #154 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_bias, AI_STATIC,
  154, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_56_bias_array, &conv2d_56_bias_intq)

/* Tensor #155 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_weights, AI_STATIC,
  155, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_57_weights_array, &conv2d_57_weights_intq)

/* Tensor #156 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_bias, AI_STATIC,
  156, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_57_bias_array, &conv2d_57_bias_intq)

/* Tensor #157 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_weights, AI_STATIC,
  157, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_58_weights_array, &conv2d_58_weights_intq)

/* Tensor #158 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_bias, AI_STATIC,
  158, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_58_bias_array, &conv2d_58_bias_intq)

/* Tensor #159 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_weights, AI_STATIC,
  159, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_60_weights_array, &conv2d_60_weights_intq)

/* Tensor #160 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_bias, AI_STATIC,
  160, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_60_bias_array, &conv2d_60_bias_intq)

/* Tensor #161 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_weights, AI_STATIC,
  161, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_61_weights_array, &conv2d_61_weights_intq)

/* Tensor #162 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_bias, AI_STATIC,
  162, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_61_bias_array, &conv2d_61_bias_intq)

/* Tensor #163 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_weights, AI_STATIC,
  163, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 56), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_62_weights_array, &conv2d_62_weights_intq)

/* Tensor #164 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_bias, AI_STATIC,
  164, 0x1,
  AI_SHAPE_INIT(4, 1, 56, 1, 1), AI_STRIDE_INIT(4, 4, 4, 224, 224),
  1, &conv2d_62_bias_array, &conv2d_62_bias_intq)

/* Tensor #165 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_weights, AI_STATIC,
  165, 0x1,
  AI_SHAPE_INIT(4, 56, 1, 1, 336), AI_STRIDE_INIT(4, 1, 56, 56, 56),
  1, &conv2d_64_weights_array, &conv2d_64_weights_intq)

/* Tensor #166 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_bias, AI_STATIC,
  166, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_64_bias_array, &conv2d_64_bias_intq)

/* Tensor #167 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_weights, AI_STATIC,
  167, 0x1,
  AI_SHAPE_INIT(4, 336, 3, 3, 1), AI_STRIDE_INIT(4, 1, 336, 1008, 3024),
  1, &conv2d_65_weights_array, &conv2d_65_weights_intq)

/* Tensor #168 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_bias, AI_STATIC,
  168, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 1, 1), AI_STRIDE_INIT(4, 4, 4, 1344, 1344),
  1, &conv2d_65_bias_array, &conv2d_65_bias_intq)

/* Tensor #169 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_weights, AI_STATIC,
  169, 0x1,
  AI_SHAPE_INIT(4, 336, 1, 1, 112), AI_STRIDE_INIT(4, 1, 336, 336, 336),
  1, &conv2d_66_weights_array, &conv2d_66_weights_intq)

/* Tensor #170 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_bias, AI_STATIC,
  170, 0x1,
  AI_SHAPE_INIT(4, 1, 112, 1, 1), AI_STRIDE_INIT(4, 4, 4, 448, 448),
  1, &conv2d_66_bias_array, &conv2d_66_bias_intq)

/* Tensor #171 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_weights, AI_STATIC,
  171, 0x1,
  AI_SHAPE_INIT(4, 112, 1, 1, 1280), AI_STRIDE_INIT(4, 1, 112, 112, 112),
  1, &conv2d_67_weights_array, &conv2d_67_weights_intq)

/* Tensor #172 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_bias, AI_STATIC,
  172, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 1, 1), AI_STRIDE_INIT(4, 4, 4, 5120, 5120),
  1, &conv2d_67_bias_array, &conv2d_67_bias_intq)

/* Tensor #173 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_weights, AI_STATIC,
  173, 0x1,
  AI_SHAPE_INIT(4, 1280, 100, 1, 1), AI_STRIDE_INIT(4, 1, 1280, 128000, 128000),
  1, &dense_69_weights_array, &dense_69_weights_intq)

/* Tensor #174 */
AI_TENSOR_OBJ_DECLARE(
  dense_69_bias, AI_STATIC,
  174, 0x1,
  AI_SHAPE_INIT(4, 1, 100, 1, 1), AI_STRIDE_INIT(4, 4, 4, 400, 400),
  1, &dense_69_bias_array, &dense_69_bias_intq)

/* Tensor #175 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_weights, AI_STATIC,
  175, 0x1,
  AI_SHAPE_INIT(4, 100, 6, 1, 1), AI_STRIDE_INIT(4, 1, 100, 600, 600),
  1, &dense_70_weights_array, &dense_70_weights_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_bias, AI_STATIC,
  176, 0x1,
  AI_SHAPE_INIT(4, 1, 6, 1, 1), AI_STRIDE_INIT(4, 4, 4, 24, 24),
  1, &dense_70_bias_array, &dense_70_bias_intq)

/* Tensor #177 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch0, AI_STATIC,
  177, 0x0,
  AI_SHAPE_INIT(4, 1, 1196, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1196, 1196),
  1, &conv2d_2_scratch0_array, NULL)

/* Tensor #178 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_2_scratch1, AI_STATIC,
  178, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_2_scratch1_array, &conv2d_2_scratch1_intq)

/* Tensor #179 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch0, AI_STATIC,
  179, 0x0,
  AI_SHAPE_INIT(4, 1, 593, 1, 1), AI_STRIDE_INIT(4, 1, 1, 593, 593),
  1, &conv2d_3_scratch0_array, NULL)

/* Tensor #180 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_3_scratch1, AI_STATIC,
  180, 0x1,
  AI_SHAPE_INIT(4, 1, 16, 112, 112), AI_STRIDE_INIT(4, 1, 1, 16, 1792),
  1, &conv2d_3_scratch1_array, &conv2d_3_scratch1_intq)

/* Tensor #181 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_4_scratch0, AI_STATIC,
  181, 0x0,
  AI_SHAPE_INIT(4, 1, 144, 1, 1), AI_STRIDE_INIT(4, 1, 1, 144, 144),
  1, &conv2d_4_scratch0_array, NULL)

/* Tensor #182 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch0, AI_STATIC,
  182, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_5_scratch0_array, NULL)

/* Tensor #183 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_5_scratch1, AI_STATIC,
  183, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 112, 112), AI_STRIDE_INIT(4, 1, 1, 48, 5376),
  1, &conv2d_5_scratch1_array, &conv2d_5_scratch1_intq)

/* Tensor #184 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch0, AI_STATIC,
  184, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_7_scratch0_array, NULL)

/* Tensor #185 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_7_scratch1, AI_STATIC,
  185, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_7_scratch1_array, &conv2d_7_scratch1_intq)

/* Tensor #186 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_8_scratch0, AI_STATIC,
  186, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_8_scratch0_array, NULL)

/* Tensor #187 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch0, AI_STATIC,
  187, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_9_scratch0_array, NULL)

/* Tensor #188 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_9_scratch1, AI_STATIC,
  188, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_9_scratch1_array, &conv2d_9_scratch1_intq)

/* Tensor #189 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch0, AI_STATIC,
  189, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_10_scratch0_array, NULL)

/* Tensor #190 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_10_scratch1, AI_STATIC,
  190, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_10_scratch1_array, &conv2d_10_scratch1_intq)

/* Tensor #191 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_11_scratch0, AI_STATIC,
  191, 0x0,
  AI_SHAPE_INIT(4, 1, 272, 1, 1), AI_STRIDE_INIT(4, 1, 1, 272, 272),
  1, &conv2d_11_scratch0_array, NULL)

/* Tensor #192 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch0, AI_STATIC,
  192, 0x0,
  AI_SHAPE_INIT(4, 1, 512, 1, 1), AI_STRIDE_INIT(4, 1, 1, 512, 512),
  1, &conv2d_13_scratch0_array, NULL)

/* Tensor #193 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_13_scratch1, AI_STATIC,
  193, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 56, 56), AI_STRIDE_INIT(4, 1, 1, 48, 2688),
  1, &conv2d_13_scratch1_array, &conv2d_13_scratch1_intq)

/* Tensor #194 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_15_scratch0, AI_STATIC,
  194, 0x0,
  AI_SHAPE_INIT(4, 1, 1777, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1777, 1777),
  1, &conv2d_15_scratch0_array, NULL)

/* Tensor #195 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  195, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch1, AI_STATIC,
  197, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_17_scratch1_array, &conv2d_17_scratch1_intq)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  198, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch1, AI_STATIC,
  199, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_18_scratch1_array, &conv2d_18_scratch1_intq)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  200, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch1, AI_STATIC,
  202, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_21_scratch1_array, &conv2d_21_scratch1_intq)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  203, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch1, AI_STATIC,
  204, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_22_scratch1_array, &conv2d_22_scratch1_intq)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  205, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch1, AI_STATIC,
  207, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_25_scratch1_array, &conv2d_25_scratch1_intq)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  208, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch1, AI_STATIC,
  209, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 14, 14), AI_STRIDE_INIT(4, 1, 1, 96, 1344),
  1, &conv2d_27_scratch1_array, &conv2d_27_scratch1_intq)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  210, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  211, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch1, AI_STATIC,
  212, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_29_scratch1_array, &conv2d_29_scratch1_intq)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  213, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch1, AI_STATIC,
  214, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_30_scratch1_array, &conv2d_30_scratch1_intq)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  215, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch1, AI_STATIC,
  217, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_33_scratch1_array, &conv2d_33_scratch1_intq)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  218, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch1, AI_STATIC,
  219, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_34_scratch1_array, &conv2d_34_scratch1_intq)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_scratch0, AI_STATIC,
  220, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_35_scratch0_array, NULL)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch1, AI_STATIC,
  222, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_37_scratch1_array, &conv2d_37_scratch1_intq)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  223, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch1, AI_STATIC,
  224, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_38_scratch1_array, &conv2d_38_scratch1_intq)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  225, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch1, AI_STATIC,
  227, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_41_scratch1_array, &conv2d_41_scratch1_intq)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  228, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch1, AI_STATIC,
  229, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_42_scratch1_array, &conv2d_42_scratch1_intq)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  230, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch0, AI_STATIC,
  231, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_44_scratch0_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch1, AI_STATIC,
  232, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_44_scratch1_array, &conv2d_44_scratch1_intq)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch0, AI_STATIC,
  233, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_45_scratch0_array, NULL)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch1, AI_STATIC,
  234, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_45_scratch1_array, &conv2d_45_scratch1_intq)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_scratch0, AI_STATIC,
  235, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_46_scratch0_array, NULL)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch1, AI_STATIC,
  237, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_48_scratch1_array, &conv2d_48_scratch1_intq)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  238, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch1, AI_STATIC,
  239, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_49_scratch1_array, &conv2d_49_scratch1_intq)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_scratch0, AI_STATIC,
  240, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_50_scratch0_array, NULL)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch0, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_52_scratch0_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch1, AI_STATIC,
  242, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_52_scratch1_array, &conv2d_52_scratch1_intq)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch0, AI_STATIC,
  243, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_54_scratch0_array, NULL)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch1, AI_STATIC,
  244, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 7, 7), AI_STRIDE_INIT(4, 1, 1, 192, 1344),
  1, &conv2d_54_scratch1_array, &conv2d_54_scratch1_intq)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_scratch0, AI_STATIC,
  245, 0x0,
  AI_SHAPE_INIT(4, 1, 1328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1328, 1328),
  1, &conv2d_55_scratch0_array, NULL)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  246, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch1, AI_STATIC,
  247, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_56_scratch1_array, &conv2d_56_scratch1_intq)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch0, AI_STATIC,
  248, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_57_scratch0_array, NULL)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_scratch0, AI_STATIC,
  249, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_58_scratch0_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch0, AI_STATIC,
  250, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_60_scratch0_array, NULL)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch1, AI_STATIC,
  251, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_60_scratch1_array, &conv2d_60_scratch1_intq)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch0, AI_STATIC,
  252, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_61_scratch0_array, NULL)

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
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
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
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
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
  AI_SHAPE_INIT(4, 1, 1280, 7, 7), AI_STRIDE_INIT(4, 1, 1, 1280, 8960),
  1, &conv2d_67_scratch1_array, &conv2d_67_scratch1_intq)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch2, AI_STATIC,
  261, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 7, 7), AI_STRIDE_INIT(4, 1, 1, 1280, 8960),
  1, &conv2d_67_scratch2_array, &conv2d_67_scratch2_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &sequential_3_input_output),
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
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_15_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_15_layer, 14,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_15_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_16_layer, AI_STATIC, 
  .groups = 48, 
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
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_57_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_57_layer, 57,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_57_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_58_layer, AI_STATIC, 
  .groups = 336, 
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
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &conv2d_61_scratch0)
)

AI_LAYER_OBJ_DECLARE(
  conv2d_61_layer, 61,
  CONV2D_TYPE, 0x0, NULL,
  conv2d, forward_conv2d_integer_SSSA_ch,
  &conv2d_61_chain,
  &AI_NET_OBJ_INSTANCE, &conv2d_62_layer, AI_STATIC, 
  .groups = 336, 
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
  .pool_size = AI_SHAPE_2D_INIT(7, 7), 
  .pool_stride = AI_SHAPE_2D_INIT(7, 7), 
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
  &AI_NET_OBJ_INSTANCE, &dense_70_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_70_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_69_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 2, &dense_70_weights, &dense_70_bias),
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_70_layer, 70,
  DENSE_TYPE, 0x0, NULL,
  dense, forward_dense_integer_SSSA,
  &dense_70_chain,
  &AI_NET_OBJ_INSTANCE, &dense_70_fmt_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_70_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_70_fmt_layer, 70,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &dense_70_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_71_layer, AI_STATIC, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_71_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &dense_70_fmt_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_71_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_71_layer, 71,
  NL_TYPE, 0x0, NULL,
  nl, forward_sm,
  &nl_71_chain,
  &AI_NET_OBJ_INSTANCE, &nl_71_fmt_layer, AI_STATIC, 
  .nl_params = NULL, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  nl_71_fmt_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_71_output),
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &nl_71_fmt_output),
  AI_TENSOR_LIST_OBJ_EMPTY,
  AI_TENSOR_LIST_OBJ_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  nl_71_fmt_layer, 71,
  NL_TYPE, 0x0, NULL,
  nl, node_convert,
  &nl_71_fmt_chain,
  &AI_NET_OBJ_INSTANCE, &nl_71_fmt_layer, AI_STATIC, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 539232, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 610784, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &sequential_3_input_output),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_OUT_NUM, &nl_71_fmt_output),
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
    sequential_3_input_output_array.data = AI_PTR(NULL);
    sequential_3_input_output_array.data_start = AI_PTR(NULL);
    conversion_0_output_array.data = AI_PTR(activations + 364672);
    conversion_0_output_array.data_start = AI_PTR(activations + 364672);
    conv2d_2_output_array.data = AI_PTR(activations + 312688);
    conv2d_2_output_array.data_start = AI_PTR(activations + 312688);
    conv2d_3_output_array.data = AI_PTR(activations + 309072);
    conv2d_3_output_array.data_start = AI_PTR(activations + 309072);
    conv2d_4_output_array.data = AI_PTR(activations + 509920);
    conv2d_4_output_array.data_start = AI_PTR(activations + 509920);
    conv2d_5_output_array.data = AI_PTR(activations + 2736);
    conv2d_5_output_array.data_start = AI_PTR(activations + 2736);
    conv2d_7_output_array.data = AI_PTR(activations + 0);
    conv2d_7_output_array.data_start = AI_PTR(activations + 0);
    conv2d_8_output_array.data = AI_PTR(activations + 150800);
    conv2d_8_output_array.data_start = AI_PTR(activations + 150800);
    conv2d_9_output_array.data = AI_PTR(activations + 326416);
    conv2d_9_output_array.data_start = AI_PTR(activations + 326416);
    conv2d_10_output_array.data = AI_PTR(activations + 175888);
    conv2d_10_output_array.data_start = AI_PTR(activations + 175888);
    conv2d_11_output_array.data = AI_PTR(activations + 272);
    conv2d_11_output_array.data_start = AI_PTR(activations + 272);
    eltwise_12_output_array.data = AI_PTR(activations + 25360);
    eltwise_12_output_array.data_start = AI_PTR(activations + 25360);
    conv2d_13_output_array.data = AI_PTR(activations + 200976);
    conv2d_13_output_array.data_start = AI_PTR(activations + 200976);
    conv2d_15_output_array.data = AI_PTR(activations + 1780);
    conv2d_15_output_array.data_start = AI_PTR(activations + 1780);
    conv2d_16_output_array.data = AI_PTR(activations + 39412);
    conv2d_16_output_array.data_start = AI_PTR(activations + 39412);
    conv2d_17_output_array.data = AI_PTR(activations + 127220);
    conv2d_17_output_array.data_start = AI_PTR(activations + 127220);
    conv2d_18_output_array.data = AI_PTR(activations + 202484);
    conv2d_18_output_array.data_start = AI_PTR(activations + 202484);
    conv2d_19_output_array.data = AI_PTR(activations + 544);
    conv2d_19_output_array.data_start = AI_PTR(activations + 544);
    eltwise_20_output_array.data = AI_PTR(activations + 13088);
    eltwise_20_output_array.data_start = AI_PTR(activations + 13088);
    conv2d_21_output_array.data = AI_PTR(activations + 100896);
    conv2d_21_output_array.data_start = AI_PTR(activations + 100896);
    conv2d_22_output_array.data = AI_PTR(activations + 176160);
    conv2d_22_output_array.data_start = AI_PTR(activations + 176160);
    conv2d_23_output_array.data = AI_PTR(activations + 544);
    conv2d_23_output_array.data_start = AI_PTR(activations + 544);
    eltwise_24_output_array.data = AI_PTR(activations + 25632);
    eltwise_24_output_array.data_start = AI_PTR(activations + 25632);
    conv2d_25_output_array.data = AI_PTR(activations + 113440);
    conv2d_25_output_array.data_start = AI_PTR(activations + 113440);
    conv2d_27_output_array.data = AI_PTR(activations + 22372);
    conv2d_27_output_array.data_start = AI_PTR(activations + 22372);
    conv2d_28_output_array.data = AI_PTR(activations + 624);
    conv2d_28_output_array.data_start = AI_PTR(activations + 624);
    conv2d_29_output_array.data = AI_PTR(activations + 35088);
    conv2d_29_output_array.data_start = AI_PTR(activations + 35088);
    conv2d_30_output_array.data = AI_PTR(activations + 91536);
    conv2d_30_output_array.data_start = AI_PTR(activations + 91536);
    conv2d_31_output_array.data = AI_PTR(activations + 6144);
    conv2d_31_output_array.data_start = AI_PTR(activations + 6144);
    eltwise_32_output_array.data = AI_PTR(activations + 10848);
    eltwise_32_output_array.data_start = AI_PTR(activations + 10848);
    conv2d_33_output_array.data = AI_PTR(activations + 43776);
    conv2d_33_output_array.data_start = AI_PTR(activations + 43776);
    conv2d_34_output_array.data = AI_PTR(activations + 72000);
    conv2d_34_output_array.data_start = AI_PTR(activations + 72000);
    conv2d_35_output_array.data = AI_PTR(activations + 816);
    conv2d_35_output_array.data_start = AI_PTR(activations + 816);
    eltwise_36_output_array.data = AI_PTR(activations + 5520);
    eltwise_36_output_array.data_start = AI_PTR(activations + 5520);
    conv2d_37_output_array.data = AI_PTR(activations + 38448);
    conv2d_37_output_array.data_start = AI_PTR(activations + 38448);
    conv2d_38_output_array.data = AI_PTR(activations + 66672);
    conv2d_38_output_array.data_start = AI_PTR(activations + 66672);
    conv2d_39_output_array.data = AI_PTR(activations + 816);
    conv2d_39_output_array.data_start = AI_PTR(activations + 816);
    eltwise_40_output_array.data = AI_PTR(activations + 10224);
    eltwise_40_output_array.data_start = AI_PTR(activations + 10224);
    conv2d_41_output_array.data = AI_PTR(activations + 43152);
    conv2d_41_output_array.data_start = AI_PTR(activations + 43152);
    conv2d_42_output_array.data = AI_PTR(activations + 71376);
    conv2d_42_output_array.data_start = AI_PTR(activations + 71376);
    conv2d_43_output_array.data = AI_PTR(activations + 896);
    conv2d_43_output_array.data_start = AI_PTR(activations + 896);
    conv2d_44_output_array.data = AI_PTR(activations + 46848);
    conv2d_44_output_array.data_start = AI_PTR(activations + 46848);
    conv2d_45_output_array.data = AI_PTR(activations + 122112);
    conv2d_45_output_array.data_start = AI_PTR(activations + 122112);
    conv2d_46_output_array.data = AI_PTR(activations + 8256);
    conv2d_46_output_array.data_start = AI_PTR(activations + 8256);
    eltwise_47_output_array.data = AI_PTR(activations + 14528);
    eltwise_47_output_array.data_start = AI_PTR(activations + 14528);
    conv2d_48_output_array.data = AI_PTR(activations + 58432);
    conv2d_48_output_array.data_start = AI_PTR(activations + 58432);
    conv2d_49_output_array.data = AI_PTR(activations + 96064);
    conv2d_49_output_array.data_start = AI_PTR(activations + 96064);
    conv2d_50_output_array.data = AI_PTR(activations + 1088);
    conv2d_50_output_array.data_start = AI_PTR(activations + 1088);
    eltwise_51_output_array.data = AI_PTR(activations + 7360);
    eltwise_51_output_array.data_start = AI_PTR(activations + 7360);
    conv2d_52_output_array.data = AI_PTR(activations + 51264);
    conv2d_52_output_array.data_start = AI_PTR(activations + 51264);
    conv2d_54_output_array.data = AI_PTR(activations + 16516);
    conv2d_54_output_array.data_start = AI_PTR(activations + 16516);
    conv2d_55_output_array.data = AI_PTR(activations + 1328);
    conv2d_55_output_array.data_start = AI_PTR(activations + 1328);
    conv2d_56_output_array.data = AI_PTR(activations + 24120);
    conv2d_56_output_array.data_start = AI_PTR(activations + 24120);
    conv2d_57_output_array.data = AI_PTR(activations + 40584);
    conv2d_57_output_array.data_start = AI_PTR(activations + 40584);
    conv2d_58_output_array.data = AI_PTR(activations + 5976);
    conv2d_58_output_array.data_start = AI_PTR(activations + 5976);
    eltwise_59_output_array.data = AI_PTR(activations + 8720);
    eltwise_59_output_array.data_start = AI_PTR(activations + 8720);
    conv2d_60_output_array.data = AI_PTR(activations + 27928);
    conv2d_60_output_array.data_start = AI_PTR(activations + 27928);
    conv2d_61_output_array.data = AI_PTR(activations + 44392);
    conv2d_61_output_array.data_start = AI_PTR(activations + 44392);
    conv2d_62_output_array.data = AI_PTR(activations + 1904);
    conv2d_62_output_array.data_start = AI_PTR(activations + 1904);
    eltwise_63_output_array.data = AI_PTR(activations + 4648);
    eltwise_63_output_array.data_start = AI_PTR(activations + 4648);
    conv2d_64_output_array.data = AI_PTR(activations + 23856);
    conv2d_64_output_array.data_start = AI_PTR(activations + 23856);
    conv2d_65_output_array.data = AI_PTR(activations + 56784);
    conv2d_65_output_array.data_start = AI_PTR(activations + 56784);
    conv2d_66_output_array.data = AI_PTR(activations + 2464);
    conv2d_66_output_array.data_start = AI_PTR(activations + 2464);
    conv2d_67_output_array.data = AI_PTR(activations + 0);
    conv2d_67_output_array.data_start = AI_PTR(activations + 0);
    dense_69_output_array.data = AI_PTR(activations + 1280);
    dense_69_output_array.data_start = AI_PTR(activations + 1280);
    dense_70_output_array.data = AI_PTR(activations + 0);
    dense_70_output_array.data_start = AI_PTR(activations + 0);
    dense_70_fmt_output_array.data = AI_PTR(activations + 8);
    dense_70_fmt_output_array.data_start = AI_PTR(activations + 8);
    nl_71_output_array.data = AI_PTR(activations + 32);
    nl_71_output_array.data_start = AI_PTR(activations + 32);
    nl_71_fmt_output_array.data = AI_PTR(NULL);
    nl_71_fmt_output_array.data_start = AI_PTR(NULL);
    conv2d_2_scratch0_array.data = AI_PTR(activations + 515200);
    conv2d_2_scratch0_array.data_start = AI_PTR(activations + 515200);
    conv2d_2_scratch1_array.data = AI_PTR(activations + 312688);
    conv2d_2_scratch1_array.data_start = AI_PTR(activations + 312688);
    conv2d_3_scratch0_array.data = AI_PTR(activations + 515800);
    conv2d_3_scratch0_array.data_start = AI_PTR(activations + 515800);
    conv2d_3_scratch1_array.data = AI_PTR(activations + 309072);
    conv2d_3_scratch1_array.data_start = AI_PTR(activations + 309072);
    conv2d_4_scratch0_array.data = AI_PTR(activations + 509776);
    conv2d_4_scratch0_array.data_start = AI_PTR(activations + 509776);
    conv2d_5_scratch0_array.data = AI_PTR(activations + 610272);
    conv2d_5_scratch0_array.data_start = AI_PTR(activations + 610272);
    conv2d_5_scratch1_array.data = AI_PTR(activations + 2736);
    conv2d_5_scratch1_array.data_start = AI_PTR(activations + 2736);
    conv2d_7_scratch0_array.data = AI_PTR(activations + 609004);
    conv2d_7_scratch0_array.data_start = AI_PTR(activations + 609004);
    conv2d_7_scratch1_array.data = AI_PTR(activations + 0);
    conv2d_7_scratch1_array.data_start = AI_PTR(activations + 0);
    conv2d_8_scratch0_array.data = AI_PTR(activations + 150528);
    conv2d_8_scratch0_array.data_start = AI_PTR(activations + 150528);
    conv2d_9_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_9_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_9_scratch1_array.data = AI_PTR(activations + 175888);
    conv2d_9_scratch1_array.data_start = AI_PTR(activations + 175888);
    conv2d_10_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_10_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_10_scratch1_array.data = AI_PTR(activations + 175888);
    conv2d_10_scratch1_array.data_start = AI_PTR(activations + 175888);
    conv2d_11_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_11_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_13_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_13_scratch1_array.data = AI_PTR(activations + 50448);
    conv2d_13_scratch1_array.data_start = AI_PTR(activations + 50448);
    conv2d_15_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_15_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch1_array.data = AI_PTR(activations + 51956);
    conv2d_17_scratch1_array.data_start = AI_PTR(activations + 51956);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_18_scratch1_array.data = AI_PTR(activations + 51956);
    conv2d_18_scratch1_array.data_start = AI_PTR(activations + 51956);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch1_array.data = AI_PTR(activations + 25632);
    conv2d_21_scratch1_array.data_start = AI_PTR(activations + 25632);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_22_scratch1_array.data = AI_PTR(activations + 25632);
    conv2d_22_scratch1_array.data_start = AI_PTR(activations + 25632);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch1_array.data = AI_PTR(activations + 38176);
    conv2d_25_scratch1_array.data_start = AI_PTR(activations + 38176);
    conv2d_27_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_27_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_27_scratch1_array.data = AI_PTR(activations + 3556);
    conv2d_27_scratch1_array.data_start = AI_PTR(activations + 3556);
    conv2d_28_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_28_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_29_scratch0_array.data = AI_PTR(activations + 5328);
    conv2d_29_scratch0_array.data_start = AI_PTR(activations + 5328);
    conv2d_29_scratch1_array.data = AI_PTR(activations + 6864);
    conv2d_29_scratch1_array.data_start = AI_PTR(activations + 6864);
    conv2d_30_scratch0_array.data = AI_PTR(activations + 5328);
    conv2d_30_scratch0_array.data_start = AI_PTR(activations + 5328);
    conv2d_30_scratch1_array.data = AI_PTR(activations + 63312);
    conv2d_30_scratch1_array.data_start = AI_PTR(activations + 63312);
    conv2d_31_scratch0_array.data = AI_PTR(activations + 5328);
    conv2d_31_scratch0_array.data_start = AI_PTR(activations + 5328);
    conv2d_33_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_33_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_33_scratch1_array.data = AI_PTR(activations + 15552);
    conv2d_33_scratch1_array.data_start = AI_PTR(activations + 15552);
    conv2d_34_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_34_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_34_scratch1_array.data = AI_PTR(activations + 15552);
    conv2d_34_scratch1_array.data_start = AI_PTR(activations + 15552);
    conv2d_35_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_35_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_37_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_37_scratch1_array.data = AI_PTR(activations + 10224);
    conv2d_37_scratch1_array.data_start = AI_PTR(activations + 10224);
    conv2d_38_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_38_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_38_scratch1_array.data = AI_PTR(activations + 10224);
    conv2d_38_scratch1_array.data_start = AI_PTR(activations + 10224);
    conv2d_39_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_39_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_41_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_41_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_41_scratch1_array.data = AI_PTR(activations + 14928);
    conv2d_41_scratch1_array.data_start = AI_PTR(activations + 14928);
    conv2d_42_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_42_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_42_scratch1_array.data = AI_PTR(activations + 5332);
    conv2d_42_scratch1_array.data_start = AI_PTR(activations + 5332);
    conv2d_43_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_43_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_44_scratch0_array.data = AI_PTR(activations + 7168);
    conv2d_44_scratch0_array.data_start = AI_PTR(activations + 7168);
    conv2d_44_scratch1_array.data = AI_PTR(activations + 9216);
    conv2d_44_scratch1_array.data_start = AI_PTR(activations + 9216);
    conv2d_45_scratch0_array.data = AI_PTR(activations + 7168);
    conv2d_45_scratch0_array.data_start = AI_PTR(activations + 7168);
    conv2d_45_scratch1_array.data = AI_PTR(activations + 84480);
    conv2d_45_scratch1_array.data_start = AI_PTR(activations + 84480);
    conv2d_46_scratch0_array.data = AI_PTR(activations + 7168);
    conv2d_46_scratch0_array.data_start = AI_PTR(activations + 7168);
    conv2d_48_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_48_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_48_scratch1_array.data = AI_PTR(activations + 20800);
    conv2d_48_scratch1_array.data_start = AI_PTR(activations + 20800);
    conv2d_49_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_49_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_49_scratch1_array.data = AI_PTR(activations + 20800);
    conv2d_49_scratch1_array.data_start = AI_PTR(activations + 20800);
    conv2d_50_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_50_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_52_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_52_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_52_scratch1_array.data = AI_PTR(activations + 13632);
    conv2d_52_scratch1_array.data_start = AI_PTR(activations + 13632);
    conv2d_54_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_54_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_54_scratch1_array.data = AI_PTR(activations + 7108);
    conv2d_54_scratch1_array.data_start = AI_PTR(activations + 7108);
    conv2d_55_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_55_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_56_scratch0_array.data = AI_PTR(activations + 4072);
    conv2d_56_scratch0_array.data_start = AI_PTR(activations + 4072);
    conv2d_56_scratch1_array.data = AI_PTR(activations + 7656);
    conv2d_56_scratch1_array.data_start = AI_PTR(activations + 7656);
    conv2d_57_scratch0_array.data = AI_PTR(activations + 4072);
    conv2d_57_scratch0_array.data_start = AI_PTR(activations + 4072);
    conv2d_58_scratch0_array.data = AI_PTR(activations + 4072);
    conv2d_58_scratch0_array.data_start = AI_PTR(activations + 4072);
    conv2d_60_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_60_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_60_scratch1_array.data = AI_PTR(activations + 11464);
    conv2d_60_scratch1_array.data_start = AI_PTR(activations + 11464);
    conv2d_61_scratch0_array.data = AI_PTR(activations + 11464);
    conv2d_61_scratch0_array.data_start = AI_PTR(activations + 11464);
    conv2d_62_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_62_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_64_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_64_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_64_scratch1_array.data = AI_PTR(activations + 7392);
    conv2d_64_scratch1_array.data_start = AI_PTR(activations + 7392);
    conv2d_65_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_65_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_65_scratch1_array.data = AI_PTR(activations + 40320);
    conv2d_65_scratch1_array.data_start = AI_PTR(activations + 40320);
    conv2d_66_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_66_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_67_scratch0_array.data = AI_PTR(activations + 7952);
    conv2d_67_scratch0_array.data_start = AI_PTR(activations + 7952);
    conv2d_67_scratch1_array.data = AI_PTR(activations + 21200);
    conv2d_67_scratch1_array.data_start = AI_PTR(activations + 21200);
    conv2d_67_scratch2_array.data = AI_PTR(activations + 83920);
    conv2d_67_scratch2_array.data_start = AI_PTR(activations + 83920);
    
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
    dense_69_bias_array.data = AI_PTR(weights + 538208);
    dense_69_bias_array.data_start = AI_PTR(weights + 538208);
    dense_70_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_70_weights_array.data = AI_PTR(weights + 538608);
    dense_70_weights_array.data_start = AI_PTR(weights + 538608);
    dense_70_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_70_bias_array.data = AI_PTR(weights + 539208);
    dense_70_bias_array.data_start = AI_PTR(weights + 539208);
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
      
      .n_macc            = 58587764,
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

