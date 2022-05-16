/**
  ******************************************************************************
  * @file    network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Tue Apr 26 14:10:10 2022
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
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
#define AI_NETWORK_MODEL_SIGNATURE     "c4192f3c211e0be3cb591cc4598a8e07"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     ""
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Tue Apr 26 14:10:10 2022"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_NETWORK_N_BATCHES
#define AI_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array serving_default_sequential_33_input0_output_array;   /* Array #0 */
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
AI_STATIC ai_array conv2d_15_scratch1_array;   /* Array #195 */
AI_STATIC ai_array conv2d_16_scratch0_array;   /* Array #196 */
AI_STATIC ai_array conv2d_17_scratch0_array;   /* Array #197 */
AI_STATIC ai_array conv2d_17_scratch1_array;   /* Array #198 */
AI_STATIC ai_array conv2d_18_scratch0_array;   /* Array #199 */
AI_STATIC ai_array conv2d_18_scratch1_array;   /* Array #200 */
AI_STATIC ai_array conv2d_19_scratch0_array;   /* Array #201 */
AI_STATIC ai_array conv2d_21_scratch0_array;   /* Array #202 */
AI_STATIC ai_array conv2d_21_scratch1_array;   /* Array #203 */
AI_STATIC ai_array conv2d_22_scratch0_array;   /* Array #204 */
AI_STATIC ai_array conv2d_22_scratch1_array;   /* Array #205 */
AI_STATIC ai_array conv2d_23_scratch0_array;   /* Array #206 */
AI_STATIC ai_array conv2d_25_scratch0_array;   /* Array #207 */
AI_STATIC ai_array conv2d_25_scratch1_array;   /* Array #208 */
AI_STATIC ai_array conv2d_27_scratch0_array;   /* Array #209 */
AI_STATIC ai_array conv2d_27_scratch1_array;   /* Array #210 */
AI_STATIC ai_array conv2d_28_scratch0_array;   /* Array #211 */
AI_STATIC ai_array conv2d_29_scratch0_array;   /* Array #212 */
AI_STATIC ai_array conv2d_29_scratch1_array;   /* Array #213 */
AI_STATIC ai_array conv2d_30_scratch0_array;   /* Array #214 */
AI_STATIC ai_array conv2d_30_scratch1_array;   /* Array #215 */
AI_STATIC ai_array conv2d_31_scratch0_array;   /* Array #216 */
AI_STATIC ai_array conv2d_33_scratch0_array;   /* Array #217 */
AI_STATIC ai_array conv2d_33_scratch1_array;   /* Array #218 */
AI_STATIC ai_array conv2d_34_scratch0_array;   /* Array #219 */
AI_STATIC ai_array conv2d_34_scratch1_array;   /* Array #220 */
AI_STATIC ai_array conv2d_35_scratch0_array;   /* Array #221 */
AI_STATIC ai_array conv2d_37_scratch0_array;   /* Array #222 */
AI_STATIC ai_array conv2d_37_scratch1_array;   /* Array #223 */
AI_STATIC ai_array conv2d_38_scratch0_array;   /* Array #224 */
AI_STATIC ai_array conv2d_38_scratch1_array;   /* Array #225 */
AI_STATIC ai_array conv2d_39_scratch0_array;   /* Array #226 */
AI_STATIC ai_array conv2d_41_scratch0_array;   /* Array #227 */
AI_STATIC ai_array conv2d_41_scratch1_array;   /* Array #228 */
AI_STATIC ai_array conv2d_42_scratch0_array;   /* Array #229 */
AI_STATIC ai_array conv2d_42_scratch1_array;   /* Array #230 */
AI_STATIC ai_array conv2d_43_scratch0_array;   /* Array #231 */
AI_STATIC ai_array conv2d_44_scratch0_array;   /* Array #232 */
AI_STATIC ai_array conv2d_44_scratch1_array;   /* Array #233 */
AI_STATIC ai_array conv2d_45_scratch0_array;   /* Array #234 */
AI_STATIC ai_array conv2d_45_scratch1_array;   /* Array #235 */
AI_STATIC ai_array conv2d_46_scratch0_array;   /* Array #236 */
AI_STATIC ai_array conv2d_48_scratch0_array;   /* Array #237 */
AI_STATIC ai_array conv2d_48_scratch1_array;   /* Array #238 */
AI_STATIC ai_array conv2d_49_scratch0_array;   /* Array #239 */
AI_STATIC ai_array conv2d_49_scratch1_array;   /* Array #240 */
AI_STATIC ai_array conv2d_50_scratch0_array;   /* Array #241 */
AI_STATIC ai_array conv2d_52_scratch0_array;   /* Array #242 */
AI_STATIC ai_array conv2d_52_scratch1_array;   /* Array #243 */
AI_STATIC ai_array conv2d_54_scratch0_array;   /* Array #244 */
AI_STATIC ai_array conv2d_54_scratch1_array;   /* Array #245 */
AI_STATIC ai_array conv2d_55_scratch0_array;   /* Array #246 */
AI_STATIC ai_array conv2d_56_scratch0_array;   /* Array #247 */
AI_STATIC ai_array conv2d_56_scratch1_array;   /* Array #248 */
AI_STATIC ai_array conv2d_57_scratch0_array;   /* Array #249 */
AI_STATIC ai_array conv2d_57_scratch1_array;   /* Array #250 */
AI_STATIC ai_array conv2d_58_scratch0_array;   /* Array #251 */
AI_STATIC ai_array conv2d_60_scratch0_array;   /* Array #252 */
AI_STATIC ai_array conv2d_60_scratch1_array;   /* Array #253 */
AI_STATIC ai_array conv2d_61_scratch0_array;   /* Array #254 */
AI_STATIC ai_array conv2d_61_scratch1_array;   /* Array #255 */
AI_STATIC ai_array conv2d_62_scratch0_array;   /* Array #256 */
AI_STATIC ai_array conv2d_64_scratch0_array;   /* Array #257 */
AI_STATIC ai_array conv2d_64_scratch1_array;   /* Array #258 */
AI_STATIC ai_array conv2d_65_scratch0_array;   /* Array #259 */
AI_STATIC ai_array conv2d_65_scratch1_array;   /* Array #260 */
AI_STATIC ai_array conv2d_66_scratch0_array;   /* Array #261 */
AI_STATIC ai_array conv2d_67_scratch0_array;   /* Array #262 */
AI_STATIC ai_array conv2d_67_scratch1_array;   /* Array #263 */
AI_STATIC ai_array conv2d_67_scratch2_array;   /* Array #264 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor serving_default_sequential_33_input0_output;   /* Tensor #0 */
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
AI_STATIC ai_tensor conv2d_15_scratch1;   /* Tensor #195 */
AI_STATIC ai_tensor conv2d_16_scratch0;   /* Tensor #196 */
AI_STATIC ai_tensor conv2d_17_scratch0;   /* Tensor #197 */
AI_STATIC ai_tensor conv2d_17_scratch1;   /* Tensor #198 */
AI_STATIC ai_tensor conv2d_18_scratch0;   /* Tensor #199 */
AI_STATIC ai_tensor conv2d_18_scratch1;   /* Tensor #200 */
AI_STATIC ai_tensor conv2d_19_scratch0;   /* Tensor #201 */
AI_STATIC ai_tensor conv2d_21_scratch0;   /* Tensor #202 */
AI_STATIC ai_tensor conv2d_21_scratch1;   /* Tensor #203 */
AI_STATIC ai_tensor conv2d_22_scratch0;   /* Tensor #204 */
AI_STATIC ai_tensor conv2d_22_scratch1;   /* Tensor #205 */
AI_STATIC ai_tensor conv2d_23_scratch0;   /* Tensor #206 */
AI_STATIC ai_tensor conv2d_25_scratch0;   /* Tensor #207 */
AI_STATIC ai_tensor conv2d_25_scratch1;   /* Tensor #208 */
AI_STATIC ai_tensor conv2d_27_scratch0;   /* Tensor #209 */
AI_STATIC ai_tensor conv2d_27_scratch1;   /* Tensor #210 */
AI_STATIC ai_tensor conv2d_28_scratch0;   /* Tensor #211 */
AI_STATIC ai_tensor conv2d_29_scratch0;   /* Tensor #212 */
AI_STATIC ai_tensor conv2d_29_scratch1;   /* Tensor #213 */
AI_STATIC ai_tensor conv2d_30_scratch0;   /* Tensor #214 */
AI_STATIC ai_tensor conv2d_30_scratch1;   /* Tensor #215 */
AI_STATIC ai_tensor conv2d_31_scratch0;   /* Tensor #216 */
AI_STATIC ai_tensor conv2d_33_scratch0;   /* Tensor #217 */
AI_STATIC ai_tensor conv2d_33_scratch1;   /* Tensor #218 */
AI_STATIC ai_tensor conv2d_34_scratch0;   /* Tensor #219 */
AI_STATIC ai_tensor conv2d_34_scratch1;   /* Tensor #220 */
AI_STATIC ai_tensor conv2d_35_scratch0;   /* Tensor #221 */
AI_STATIC ai_tensor conv2d_37_scratch0;   /* Tensor #222 */
AI_STATIC ai_tensor conv2d_37_scratch1;   /* Tensor #223 */
AI_STATIC ai_tensor conv2d_38_scratch0;   /* Tensor #224 */
AI_STATIC ai_tensor conv2d_38_scratch1;   /* Tensor #225 */
AI_STATIC ai_tensor conv2d_39_scratch0;   /* Tensor #226 */
AI_STATIC ai_tensor conv2d_41_scratch0;   /* Tensor #227 */
AI_STATIC ai_tensor conv2d_41_scratch1;   /* Tensor #228 */
AI_STATIC ai_tensor conv2d_42_scratch0;   /* Tensor #229 */
AI_STATIC ai_tensor conv2d_42_scratch1;   /* Tensor #230 */
AI_STATIC ai_tensor conv2d_43_scratch0;   /* Tensor #231 */
AI_STATIC ai_tensor conv2d_44_scratch0;   /* Tensor #232 */
AI_STATIC ai_tensor conv2d_44_scratch1;   /* Tensor #233 */
AI_STATIC ai_tensor conv2d_45_scratch0;   /* Tensor #234 */
AI_STATIC ai_tensor conv2d_45_scratch1;   /* Tensor #235 */
AI_STATIC ai_tensor conv2d_46_scratch0;   /* Tensor #236 */
AI_STATIC ai_tensor conv2d_48_scratch0;   /* Tensor #237 */
AI_STATIC ai_tensor conv2d_48_scratch1;   /* Tensor #238 */
AI_STATIC ai_tensor conv2d_49_scratch0;   /* Tensor #239 */
AI_STATIC ai_tensor conv2d_49_scratch1;   /* Tensor #240 */
AI_STATIC ai_tensor conv2d_50_scratch0;   /* Tensor #241 */
AI_STATIC ai_tensor conv2d_52_scratch0;   /* Tensor #242 */
AI_STATIC ai_tensor conv2d_52_scratch1;   /* Tensor #243 */
AI_STATIC ai_tensor conv2d_54_scratch0;   /* Tensor #244 */
AI_STATIC ai_tensor conv2d_54_scratch1;   /* Tensor #245 */
AI_STATIC ai_tensor conv2d_55_scratch0;   /* Tensor #246 */
AI_STATIC ai_tensor conv2d_56_scratch0;   /* Tensor #247 */
AI_STATIC ai_tensor conv2d_56_scratch1;   /* Tensor #248 */
AI_STATIC ai_tensor conv2d_57_scratch0;   /* Tensor #249 */
AI_STATIC ai_tensor conv2d_57_scratch1;   /* Tensor #250 */
AI_STATIC ai_tensor conv2d_58_scratch0;   /* Tensor #251 */
AI_STATIC ai_tensor conv2d_60_scratch0;   /* Tensor #252 */
AI_STATIC ai_tensor conv2d_60_scratch1;   /* Tensor #253 */
AI_STATIC ai_tensor conv2d_61_scratch0;   /* Tensor #254 */
AI_STATIC ai_tensor conv2d_61_scratch1;   /* Tensor #255 */
AI_STATIC ai_tensor conv2d_62_scratch0;   /* Tensor #256 */
AI_STATIC ai_tensor conv2d_64_scratch0;   /* Tensor #257 */
AI_STATIC ai_tensor conv2d_64_scratch1;   /* Tensor #258 */
AI_STATIC ai_tensor conv2d_65_scratch0;   /* Tensor #259 */
AI_STATIC ai_tensor conv2d_65_scratch1;   /* Tensor #260 */
AI_STATIC ai_tensor conv2d_66_scratch0;   /* Tensor #261 */
AI_STATIC ai_tensor conv2d_67_scratch0;   /* Tensor #262 */
AI_STATIC ai_tensor conv2d_67_scratch1;   /* Tensor #263 */
AI_STATIC ai_tensor conv2d_67_scratch2;   /* Tensor #264 */


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
  serving_default_sequential_33_input0_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
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
  NULL, NULL, 5, AI_STATIC)

/* Array#66 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_fmt_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#67 */
AI_ARRAY_OBJ_DECLARE(
  nl_71_output_array, AI_ARRAY_FORMAT_FLOAT,
  NULL, NULL, 5, AI_STATIC)

/* Array#68 */
AI_ARRAY_OBJ_DECLARE(
  nl_71_fmt_output_array, AI_ARRAY_FORMAT_U8|AI_FMT_FLAG_IS_IO,
  NULL, NULL, 5, AI_STATIC)

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
  NULL, NULL, 500, AI_STATIC)

/* Array#176 */
AI_ARRAY_OBJ_DECLARE(
  dense_70_bias_array, AI_ARRAY_FORMAT_S32,
  NULL, NULL, 5, AI_STATIC)

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
  conv2d_15_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#196 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_16_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 352, AI_STATIC)

/* Array#197 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#198 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_17_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#199 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#200 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_18_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#201 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_19_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#202 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#203 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_21_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#204 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#205 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_22_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#206 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_23_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 544, AI_STATIC)

/* Array#207 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1024, AI_STATIC)

/* Array#208 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_25_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 75264, AI_STATIC)

/* Array#209 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3553, AI_STATIC)

/* Array#210 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_27_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 18816, AI_STATIC)

/* Array#211 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_28_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 624, AI_STATIC)

/* Array#212 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#213 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_29_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#214 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#215 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_30_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#216 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_31_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#217 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#218 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_33_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#219 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#220 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_34_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#221 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_35_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#222 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#223 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_37_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#224 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#225 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_38_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#226 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_39_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 816, AI_STATIC)

/* Array#227 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1536, AI_STATIC)

/* Array#228 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_41_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#229 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 5329, AI_STATIC)

/* Array#230 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_42_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 28224, AI_STATIC)

/* Array#231 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_43_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 896, AI_STATIC)

/* Array#232 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#233 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_44_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#234 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#235 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_45_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#236 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_46_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#237 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#238 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_48_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#239 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#240 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_49_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#241 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_50_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1088, AI_STATIC)

/* Array#242 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2048, AI_STATIC)

/* Array#243 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_52_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 37632, AI_STATIC)

/* Array#244 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 7105, AI_STATIC)

/* Array#245 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_54_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 9408, AI_STATIC)

/* Array#246 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_55_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1328, AI_STATIC)

/* Array#247 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#248 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_56_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#249 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#250 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_57_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#251 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_58_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#252 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#253 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_60_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#254 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#255 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_61_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#256 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_62_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 1904, AI_STATIC)

/* Array#257 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 3584, AI_STATIC)

/* Array#258 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_64_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#259 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 12433, AI_STATIC)

/* Array#260 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_65_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 16464, AI_STATIC)

/* Array#261 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_66_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 2464, AI_STATIC)

/* Array#262 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch0_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 13248, AI_STATIC)

/* Array#263 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch1_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 62720, AI_STATIC)

/* Array#264 */
AI_ARRAY_OBJ_DECLARE(
  conv2d_67_scratch2_array, AI_ARRAY_FORMAT_S8,
  NULL, NULL, 62720, AI_STATIC)

/**  Array metadata declarations section  *************************************/
/* Int quant #0 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(serving_default_sequential_33_input0_output_intq, AI_STATIC_CONST,
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
    AI_PACK_INTQ_SCALE(0.30757537484169006f),
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
    AI_PACK_INTQ_SCALE(0.25494977831840515f),
    AI_PACK_INTQ_ZP(-13)))

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
    AI_PACK_INTQ_SCALE(0.48506391048431396f),
    AI_PACK_INTQ_ZP(-11)))

/* Int quant #11 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_12_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.47160017490386963f),
    AI_PACK_INTQ_ZP(-1)))

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
    AI_PACK_INTQ_SCALE(0.236260786652565f),
    AI_PACK_INTQ_ZP(12)))

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
    AI_PACK_INTQ_SCALE(0.3066592514514923f),
    AI_PACK_INTQ_ZP(-1)))

/* Int quant #18 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_20_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3036149740219116f),
    AI_PACK_INTQ_ZP(-11)))

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
    AI_PACK_INTQ_SCALE(0.27191653847694397f),
    AI_PACK_INTQ_ZP(20)))

/* Int quant #22 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_24_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3885001242160797f),
    AI_PACK_INTQ_ZP(5)))

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
    AI_PACK_INTQ_SCALE(0.1901276558637619f),
    AI_PACK_INTQ_ZP(10)))

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
    AI_PACK_INTQ_SCALE(0.19393612444400787f),
    AI_PACK_INTQ_ZP(-23)))

/* Int quant #29 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_32_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.22111763060092926f),
    AI_PACK_INTQ_ZP(-14)))

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
    AI_PACK_INTQ_SCALE(0.18962959945201874f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #33 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_36_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.24281476438045502f),
    AI_PACK_INTQ_ZP(-9)))

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
    AI_PACK_INTQ_SCALE(0.17839467525482178f),
    AI_PACK_INTQ_ZP(-22)))

/* Int quant #37 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_40_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.27833735942840576f),
    AI_PACK_INTQ_ZP(-6)))

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
    AI_PACK_INTQ_SCALE(0.1908549815416336f),
    AI_PACK_INTQ_ZP(-4)))

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
    AI_PACK_INTQ_SCALE(0.1687372922897339f),
    AI_PACK_INTQ_ZP(11)))

/* Int quant #44 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_47_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.21362440288066864f),
    AI_PACK_INTQ_ZP(6)))

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
    AI_PACK_INTQ_SCALE(0.21370477974414825f),
    AI_PACK_INTQ_ZP(23)))

/* Int quant #48 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_51_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.3032996654510498f),
    AI_PACK_INTQ_ZP(23)))

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
    AI_PACK_INTQ_SCALE(0.13700659573078156f),
    AI_PACK_INTQ_ZP(-9)))

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
    AI_PACK_INTQ_SCALE(0.11659403890371323f),
    AI_PACK_INTQ_ZP(7)))

/* Int quant #55 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_59_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.14759859442710876f),
    AI_PACK_INTQ_ZP(-3)))

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
    AI_PACK_INTQ_SCALE(0.15839621424674988f),
    AI_PACK_INTQ_ZP(-3)))

/* Int quant #59 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(eltwise_63_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.18422017991542816f),
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
    AI_PACK_INTQ_SCALE(0.1207033172249794f),
    AI_PACK_INTQ_ZP(-7)))

/* Int quant #63 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.020258009433746338f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #64 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.027927357703447342f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #65 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_output_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.11811815202236176f),
    AI_PACK_INTQ_ZP(-15)))

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
    AI_PACK_INTQ_SCALE(0.006357043515890837f, 0.01532160583883524f, 0.0066710710525512695f, 2.51141898388596e-07f, 0.006800525821745396f, 1.8187306238814926e-07f, 0.0034435198176652193f, 1.8307131810502142e-08f, 0.003978225868195295f, 0.015115455724298954f, 0.004665786400437355f, 1.8814594682226016e-07f, 0.010604714043438435f, 4.271763742735857e-08f, 0.0059135183691978455f, 0.015915120020508766f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #68 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_2_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 16,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(4.985916893929243e-05f, 0.00012016946129733697f, 5.232212788541801e-05f, 1.9697405928553735e-09f, 5.333746230462566e-05f, 1.4264555092680098e-09f, 2.7007999960915186e-05f, 1.435853519415886e-10f, 3.120177279924974e-05f, 0.00011855259799631312f, 3.65944069926627e-05f, 1.4756545985150638e-09f, 8.317422907566652e-05f, 3.3504030105824256e-10f, 4.638053724193014e-05f, 0.00012482448073569685f),
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
    AI_PACK_INTQ_SCALE(0.003871348686516285f, 0.0003942394396290183f, 0.00033070050994865596f, 0.000140734642627649f, 0.00024641325580887496f, 0.003679329063743353f, 0.0005930564366281033f, 0.00018934858962893486f, 0.0010081649525091052f, 0.0002335033641429618f, 0.0001757603749865666f, 0.001743006519973278f, 0.0005910067702643573f, 0.002691978123039007f, 0.00019014839199371636f, 0.0030662131030112505f, 0.0004360736347734928f, 0.00022513467411044985f, 0.00018232077127322555f, 0.0003179429331794381f, 0.0002821106172632426f, 0.00031932073761709034f, 0.003907931502908468f, 0.0021735255140811205f, 0.0002796765766106546f, 0.0005096672684885561f, 0.0003968198725488037f, 0.00042253706487827003f, 0.0007372458931058645f, 0.00011481370165711269f, 0.0026217603590339422f, 0.0004807790683116764f, 0.00024526205379515886f, 0.0001716010447125882f, 0.001127247465774417f, 0.0007233275682665408f, 0.0006879411521367729f, 0.00030793764744885266f, 0.0004359880113042891f, 0.00033917772816494107f, 0.0033806548453867435f, 0.0005991543876007199f, 0.00010628116433508694f, 0.00048105843598023057f, 0.00029590490157715976f, 0.0026443235110491514f, 0.001831056084483862f, 0.0031177508644759655f),
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
    AI_PACK_INTQ_SCALE(0.0002593041572254151f, 0.0005433742189779878f, 7.298077980522066e-05f, 0.0003017404524143785f, 0.0008851001039147377f, 0.00013780694280285388f, 0.0002761548093985766f, 0.00023138185497373343f, 0.00012590302503667772f, 0.0005383316311053932f, 0.0008873672340996563f, 0.0006259905640035868f, 0.0005915320944041014f, 0.001083872397430241f, 0.0005609729560092092f, 0.00031537245376966894f, 0.00014428800204768777f, 0.00019350000366102904f, 7.11874381522648e-05f, 0.00015154042921494693f, 8.142329897964373e-05f, 0.00021093229588586837f, 0.0004134853952564299f, 0.0005310475244186819f, 0.00026462203823029995f, 0.00040503087802790105f, 0.00042803582618944347f, 0.00034781722933985293f, 0.00022738058760296553f, 0.00023240127484314144f, 0.0003375200612936169f, 0.00031676734215579927f, 0.0002275318984175101f, 0.00022159794752951711f, 0.0002954721567220986f, 0.00015434926899615675f, 0.0004349439113866538f, 8.58883504406549e-05f, 0.00047354018897749484f, 0.00030199086177162826f, 0.0004245425807312131f, 0.0006178522016853094f, 0.00019930594135075808f, 0.0001647329772822559f, 0.0004893678124062717f, 0.0004323649627622217f, 0.0006927253562025726f, 0.0004150842141825706f),
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
    AI_PACK_INTQ_SCALE(0.00045627489453181624f, 0.0004974296316504478f, 0.0005923412973061204f, 0.0003646862751338631f, 0.00039297324838116765f, 0.0008433550829067826f, 0.0003087896038778126f, 0.00042394918273203075f, 0.0003362642601132393f, 0.000528633885551244f, 0.0002588741772342473f, 0.00034351032809354365f, 0.0003085294156335294f, 0.0002018496161326766f, 0.00015809487376827747f, 0.0005608287174254656f, 0.00087862549116835f, 0.00036381956306286156f, 0.00024566263891756535f, 0.00026041513774544f, 0.00024244326050393283f, 0.00035225009196437895f, 0.0004147253348492086f, 0.0005556451505981386f, 0.002092288574203849f, 0.00010986444976879284f, 0.00031935551669448614f, 0.0002741000207606703f, 0.00036625852226279676f, 0.00017340453632641584f, 0.00016066186071839184f, 0.0005248793167993426f, 0.0003316506918054074f, 0.0007258491241373122f, 0.0002831965684890747f, 0.0001808744273148477f, 0.0005666689830832183f, 0.0004143172991462052f, 0.0004292658413760364f, 0.00020309996034484357f, 0.0009264107793569565f, 0.0003043893084395677f, 0.00021696678595617414f, 0.00018177079618908465f, 0.0002016295911744237f, 0.0006027226336300373f, 0.0002682972699403763f, 0.0004085517721250653f),
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
    AI_PACK_INTQ_SCALE(0.0007196695660240948f, 0.0008143050945363939f, 0.0005564200691878796f, 0.000545108166988939f, 0.0007059267954900861f, 0.0008888617157936096f, 0.0004908799310214818f, 0.0005303053767420352f, 0.0005651280516758561f, 0.0007710265927016735f, 0.00047769778757356107f, 0.0008058336097747087f, 0.0005353919696062803f, 0.000746769888792187f, 0.0005780206993222237f, 0.0007795738056302071f),
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
    AI_PACK_INTQ_SCALE(0.0007299646968021989f, 0.0001143098488682881f, 4.2009836761280894e-05f, 0.0001945481781149283f, 0.0002190510422224179f, 5.7069093600148335e-05f, 0.00021808376186527312f, 0.00018433919467497617f, 0.00021251320140436292f, 0.0002814588078763336f, 0.00029136970988474786f, 0.00037767319008708f, 9.68589520198293e-05f, 9.074194531422108e-05f, 0.00038523387047462165f, 0.0001666120660956949f, 0.00012100716412533075f, 0.00032435121829621494f, 0.00022647055448032916f, 0.00022480454936157912f, 0.0003092479018960148f, 0.0001241000136360526f, 0.00016011543630156666f, 0.00017934649076778442f, 0.0003124507493339479f, 0.00011354438174748793f, 0.0002777991467155516f, 0.0002432370965834707f, 0.00046674651093780994f, 0.00026230979710817337f, 0.00014894122432451695f, 0.00014865263074170798f, 0.00018222283688373864f, 0.0001310667721554637f, 0.0006688470602966845f, 6.403705629054457e-05f, 0.00019847812654916197f, 8.979982521850616e-05f, 9.872580267256126e-05f, 0.0004906123504042625f, 0.00020331346604507416f, 0.00023699470330029726f, 0.00031484916689805686f, 0.0006105680367909372f, 0.00039916232344694436f, 0.0002200633753091097f, 0.0005079728434793651f, 0.0005041533731855452f, 0.0002649697125889361f, 0.0002560102439019829f, 0.00035717448918148875f, 0.0003693730686791241f, 0.0005782839725725353f, 0.00011047584121115506f, 8.053112833295017e-05f, 0.0004766900383401662f, 0.0002077803510474041f, 8.194306428777054e-05f, 0.00016586239507887512f, 0.00025262817507609725f, 0.0002097239630529657f, 0.00019491618149913847f, 0.0002704874495975673f, 0.0001020450217765756f, 0.00046806340105831623f, 0.000257071980740875f, 0.0002482608542777598f, 0.0001765773631632328f, 0.00025828974321484566f, 0.0003292432229500264f, 0.00013082774239592254f, 0.0003611025167629123f, 0.0002029247407335788f, 0.00014891863975208253f, 0.00017148930055554956f, 0.00027142890030518174f, 0.00044880853965878487f, 0.00010057143663289025f, 0.00014709701645188034f, 0.00018711401207838207f, 0.0002725636586546898f, 0.00015158203314058483f, 0.0001238240220118314f, 0.000236965948715806f, 0.0002391234738752246f, 0.0004070239665452391f, 0.0002457294031046331f, 0.0006346402806229889f, 0.0005047527374699712f, 0.0005095502128824592f, 0.00045104572200216353f, 0.00014984930749051273f, 0.0002554240054450929f, 0.00027383779524825513f, 0.0002435412025079131f, 0.000457194255432114f),
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
    AI_PACK_INTQ_SCALE(0.000287519273115322f, 0.00012202463403809816f, 8.406298729823902e-05f, 0.00024421955458819866f, 0.00021031063806731254f, 0.0007913421140983701f, 0.0007649559411220253f, 0.0001400229666614905f, 5.5883778259158134e-05f, 0.0002278258907608688f, 0.00014781337813474238f, 0.00015456123219337314f, 0.00021859446133021265f, 0.0002788621641229838f, 0.00036918328260071576f, 0.00019789059297181666f, 0.0001616301160538569f, 0.0003269677981734276f, 0.00033544801408424973f, 0.00026212126249447465f, 9.831371426116675e-05f, 0.00013431358092930168f, 0.0002284894435433671f, 0.00021927827037870884f, 0.0005516040255315602f, 0.0003688687284011394f, 0.00028428921359591186f, 0.00021187509992159903f, 0.0001866915845312178f, 0.00021119021403137594f, 0.0001485624525230378f, 0.0001921853981912136f, 0.0002758591144811362f, 0.0002809599682223052f, 0.0001322896423516795f, 0.0002650102542247623f, 7.630870095454156e-05f, 0.00020674601546488702f, 0.00016432814300060272f, 0.00015417982649523765f, 0.0003143836511299014f, 0.00021417067910078913f, 0.0005552264046855271f, 0.0002704717917367816f, 0.00028482446214184165f, 0.00024044390011113137f, 0.0002638928417582065f, 0.00012088446965208277f, 0.00013469939585775137f, 0.00027978725847788155f, 0.00012225900718476623f, 0.00023480129311792552f, 0.0002207156940130517f, 0.00030088756466284394f, 0.00020324670185800642f, 0.00015669036656618118f, 8.741494821151718e-05f, 0.0006781576666980982f, 0.0002460259711369872f, 0.0001239341654581949f, 0.00024370949540752918f, 6.586923700524494e-05f, 0.0002643686602823436f, 0.00027925209724344313f, 0.00030157106812112033f, 0.0003621328214649111f, 0.0001339122245553881f, 0.00029788760002702475f, 0.0001583458943059668f, 0.00020552196656353772f, 0.00018140132306143641f, 8.101958519546315e-05f, 0.00010544504766585305f, 0.0001367955410387367f, 0.00012337998487055302f, 0.0002527950855437666f, 0.0003425221366342157f, 7.292371446965262e-05f, 0.00014655232371296734f, 0.0003483581240288913f, 0.0002301789791090414f, 0.00035399117041379213f, 0.0002490732294972986f, 0.0001943812967510894f, 0.0001306029298575595f, 0.0003553401620592922f, 0.0001614284992683679f, 0.0003512631228659302f, 0.0003822888829745352f, 0.00017663993639871478f, 0.00017116119852289557f, 0.00010169712913921103f, 0.0002603312605060637f, 0.0001695073879091069f, 0.0003498710866551846f, 0.00027093992684967816f),
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
    AI_PACK_INTQ_SCALE(0.0001506405824329704f, 0.00020877459610346705f, 0.0002749123377725482f, 0.00029360014013946056f, 0.0002801136579364538f, 0.00022730474302079529f, 0.00021083121828269213f, 0.00012490397784858942f, 0.00021928387286607176f, 0.00048635469283908606f, 0.0006621113861910999f, 0.0006083009648136795f, 0.0005807779380120337f, 0.0007433189894072711f, 0.0006766620790585876f, 0.0005890947650186718f, 0.00025305122835561633f, 0.0005379911162890494f, 0.000719415140338242f, 0.00022011865803506225f, 0.0010283597512170672f, 0.00026315770810469985f, 0.0002313147997483611f, 0.0001754654513206333f, 0.0006122085032984614f, 0.0005203518085181713f, 0.0002562647277954966f, 0.0015552028780803084f, 0.0002983981103170663f, 0.00019281846471130848f, 0.00011821892985608429f, 0.000545286457054317f, 0.0005493239732459188f, 0.0003634233435150236f, 0.0002750476123765111f, 0.0006806543096899986f, 0.00039216369623318315f, 0.00027889676857739687f, 0.00035077810753136873f, 0.0002304818044649437f, 0.00035180870327167213f, 0.0005304419319145381f, 0.00036445868317969143f, 0.00039356615161523223f, 0.0002952466020360589f, 0.0005532202194444835f, 0.0002716975286602974f, 0.0005035132053308189f, 0.0006704074330627918f, 0.0004481159267015755f, 0.0009105263743549585f, 0.0003788608592003584f, 0.0005919898394495249f, 0.0006261278758756816f, 0.00028079995536245406f, 0.0009042967576533556f, 0.000503706163726747f, 0.0001458036422263831f, 0.0005390137666836381f, 0.0005823070532642305f, 0.00014201946032699198f, 0.0006312655168585479f, 0.0006440859287977219f, 0.000641349412035197f, 0.0003451872617006302f, 0.0005338892224244773f, 9.557718294672668e-05f, 0.0003068966034334153f, 0.0003663437382783741f, 0.0006636223988607526f, 0.001056361710652709f, 0.000492063642013818f, 0.00016180466627702117f, 0.0002292468270752579f, 0.000588545692153275f, 0.0003638734924606979f, 0.0001828142994781956f, 0.0003332865599077195f, 0.0006650810246355832f, 0.0004107365384697914f, 0.00022154368343763053f, 0.00020188956113997847f, 0.00015408042236231267f, 0.00011060540418839082f, 0.0002659540041349828f, 0.000448724371381104f, 0.00016950529243331403f, 0.0003986730007454753f, 0.00028753498918376863f, 0.00025257020024582744f, 0.0003211026487406343f, 0.00030843765125609934f, 0.00016069987032096833f, 0.0006703564431518316f, 0.0008696935256011784f, 0.00014999504492152482f),
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
    AI_PACK_INTQ_SCALE(6.82458994560875e-05f, 7.087604171829298e-05f, 8.775602327659726e-05f, 6.940843013580889e-05f, 0.0001350755919702351f, 9.384659642819315e-05f, 0.00010823070624610409f, 0.00015597869060002267f, 7.982733950484544e-05f, 0.00010861930786632001f, 0.0001280954893445596f, 9.564453648636118e-05f, 0.00014429619477596134f, 0.00015028358029667288f, 0.00018523295875638723f, 0.00025269933394156396f, 9.196517203235999e-05f, 8.835407061269507e-05f, 0.00015255669131875038f, 7.5415606261231e-05f, 9.773724741535261e-05f, 0.00015084611368365586f, 0.00021691605797968805f, 0.00010101545922225341f, 0.00011664302292047068f, 0.00016766935004852712f, 0.00014412666496355087f, 4.575632556225173e-05f, 0.0001052864026860334f, 0.0002482424897607416f, 7.014507718849927e-05f, 0.00023291671823244542f, 0.00012099922605557367f, 0.00015104960766620934f, 6.379961996572092e-05f, 0.0002587747585494071f, 0.00010611602920107543f, 0.00011781496868934482f, 0.00012193660950288177f, 6.120328180259094e-05f, 7.623933197464794e-05f, 6.0626807680819184e-05f, 0.0001904336822917685f, 0.00022099431953392923f, 0.00013609841698780656f, 0.00016893181600607932f, 0.00018665699462871999f, 7.467804971383885e-05f, 0.00011852614989038557f, 5.1468734454829246e-05f, 0.00018826236191671342f, 0.00012957390572410077f, 5.5810374760767445e-05f, 4.673634612117894e-05f, 0.00015719882503617555f, 0.00015397672541439533f, 5.6816723372321576e-05f, 0.0003646534460131079f, 0.00015246555267367512f, 7.828437082935125e-05f, 0.00011567577166715637f, 0.0001086458214558661f, 9.0040237409994e-05f, 0.00013964461686555296f, 0.00012697887723334134f, 0.00011447177530499175f, 0.00012406309542711824f, 0.00024248282716143876f, 0.00017036103236023337f, 0.00013589891023002565f, 0.00024397224478889257f, 0.0002278282045153901f, 0.00022059887123759836f, 0.000244708702666685f, 0.000133319161250256f, 0.0001700179127510637f, 0.00010409772949060425f, 0.0006265011616051197f, 0.00015252036973834038f, 6.303528789430857e-05f, 7.511849253205582e-05f, 0.00016176085046026856f, 6.78378128213808e-05f, 9.348482853965834e-05f, 0.00025694529176689684f, 0.0001919930800795555f, 8.791821892373264e-05f, 0.00012868110206909478f, 0.00022663050913251936f, 7.691956125199795e-05f, 0.00018914273823611438f, 0.00020131208293605596f, 0.00010893840226344764f, 0.00011856427590828389f, 8.935361256590113e-05f, 8.460933167953044e-05f, 0.00013532348384615034f, 9.946493082679808e-05f, 0.00016011661500670016f, 6.119236786616966e-05f, 0.00015033376985229552f, 0.00014964451838750392f, 0.00011706497025443241f, 0.00020472327014431357f, 0.00019990171131212264f, 0.00010228563769487664f, 2.5043558707693592e-05f, 4.7638663090765476e-05f, 0.00018044313765130937f, 0.00012861807772424072f, 0.00011680430179694667f, 0.0001593321212567389f, 0.0001070494472514838f, 3.246766937081702e-05f, 0.00020579546981025487f, 7.444652146659791e-05f, 0.0003146626695524901f, 9.340482938569039e-05f, 0.00016664445865899324f, 0.0001745296613080427f, 5.872511974303052e-05f, 0.0001075770051102154f, 0.0001938754867296666f, 0.0001972436875803396f, 0.00010877893510041758f, 0.00017208923236466944f, 0.00014739132893737406f, 0.00023987329041119665f, 0.00041400521877221763f, 8.546131721232086e-05f, 0.00020459442748688161f, 0.00010020433546742424f, 9.474877151660621e-05f, 0.00016810408851597458f, 0.00011863296094816178f, 0.00013593990297522396f, 0.00014187228225637227f, 0.00011133114458061755f, 0.00017886792193166912f, 0.0002371771988691762f, 3.855041359202005e-05f, 0.00015561400505248457f, 0.0003133317222818732f, 9.037747804541141e-05f),
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
    AI_PACK_INTQ_SCALE(0.0002604059118311852f, 8.927462477004156e-05f, 0.00011827200069092214f, 6.105917418608442e-05f, 0.00013922291691415012f, 9.687559213489294e-05f, 0.0001575168571434915f, 8.07550604804419e-05f, 0.00017434582696296275f, 0.0002617456193547696f, 0.00011614798859227449f, 0.00018364581046625972f, 0.00011781958164647222f, 7.326500781346112e-05f, 0.00012702152889687568f, 0.00011432249448262155f, 0.00019835372222587466f, 0.0003140607150271535f, 9.965070057660341e-05f, 6.445094186346978e-05f, 0.0001225997693836689f, 0.00015245501708704978f, 3.943922638427466e-05f, 8.463150152238086e-05f, 0.00011170915240654722f, 0.00012034396786475554f, 6.292451871559024e-05f, 5.116368265589699e-05f, 0.00011259604070801288f, 0.00017166882753372192f, 0.00014091261255089194f, 8.426980639342219e-05f, 0.00010138205834664404f, 0.0002031427138717845f, 7.911804277682677e-05f, 0.00020990509074181318f, 0.00014274670684244484f, 0.00016853836132213473f, 0.00012863973097410053f, 0.00039319079951383173f, 0.00012942600005771965f, 0.0002273447607876733f, 3.331368861836381e-05f, 0.00010429200483486056f, 0.0001199242178699933f, 6.692589522572234e-05f, 9.333407797385007e-05f, 0.00015883860760368407f, 0.0001976548956008628f, 0.00019083646475337446f, 0.00016346873599104583f, 0.00010094376921188086f, 0.000182209478225559f, 0.0002480987168382853f, 0.0001026146492222324f, 9.591125854058191e-05f, 0.0002593583194538951f, 0.00013662019046023488f, 0.00010224895959254354f, 0.0001699204440228641f, 0.00010928559640888125f, 0.00010419808677397668f, 8.10978381196037e-05f, 0.000254239042988047f, 0.0002411213208688423f, 0.00011112521315226331f, 0.0003445281181484461f, 7.171531615313143e-05f, 0.00019255635561421514f, 9.559841419104487e-05f, 0.00016396954015363008f, 0.0001873833389254287f, 7.256228855112568e-05f, 0.0001867558603407815f, 0.00011258323502261192f, 0.0001224060106324032f, 8.552768849767745e-05f, 0.00026987044839188457f, 0.00018092473328579217f, 0.00016924297960940748f, 0.00018796767108142376f, 0.00013696654059458524f, 0.00021589052630588412f, 6.527391815325245e-05f, 7.553262548753992e-05f, 0.0001987358700716868f, 0.00011432197061367333f, 0.0002029957831837237f, 0.00015828778850845993f, 8.000399975571781e-05f, 0.00012110610987292603f, 0.00019657470693346113f, 0.0001263088925043121f, 0.00011106310557806864f, 9.916276030708104e-05f, 9.158138709608465e-05f, 7.090518192853779e-05f, 0.0002262578345835209f, 0.0001900511560961604f, 0.00011709359387168661f, 9.23449988476932e-05f, 0.00018948191427625716f, 0.00010647432645782828f, 0.00023731400142423809f, 0.00014168837515171617f, 0.0001782811596058309f, 0.00019799458095803857f, 7.753295358270407e-05f, 0.0001878459588624537f, 6.178888725116849e-05f, 0.00022630199964623898f, 0.0001692963414825499f, 0.0001611164043424651f, 0.0002703255449887365f, 5.900142787140794e-05f, 0.00010923280206043273f, 0.000125211663544178f, 0.00023703758779447526f, 0.00021028803894296288f, 0.00026656893896870315f, 5.916339432587847e-05f, 0.00010065845708595589f, 8.73579629114829e-05f, 8.310446719406173e-05f, 0.00014264722994994372f, 0.00012913539831060916f, 0.00020825353567488492f, 0.0002799447102006525f, 9.918336581904441e-05f, 8.830765727907419e-05f, 0.00020596326794475317f, 9.600201155990362e-05f, 0.00020521889382507652f, 4.06081453547813e-05f, 0.0002549880591686815f, 0.0001751208328641951f, 0.00014868185098748654f, 0.00023713998962193727f, 0.00012001541472272947f, 4.7288111090892926e-05f, 0.0001514473115094006f, 0.00015201116912066936f, 0.00016672955825924873f, 0.0002566070470493287f),
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
    AI_PACK_INTQ_SCALE(7.137123611755669e-05f, 8.311283454531804e-05f, 6.191556894918904e-05f, 0.00020389833662193269f, 0.00023155318922363222f, 7.998795626917854e-05f, 0.0003237465280108154f, 0.00026769324904307723f, 0.0001770027301972732f, 0.0002156505361199379f, 0.00010867206583498046f, 4.586028808262199e-05f, 0.00010117408237420022f, 0.00016103903180919588f, 0.0001464560627937317f, 0.00022689545585308224f, 0.0001495204196544364f, 6.729227607138455e-05f, 9.043496538652107e-05f, 0.00011867239663843066f, 0.00024868655600585043f, 4.484051532926969e-05f, 4.1914016037480906e-05f, 0.00016102900553960353f, 0.00025474082212895155f, 0.0001457949838368222f, 0.0002408065483905375f, 0.0001278958225157112f, 0.00017820858920458704f, 0.00016817876894492656f, 0.00021506041230168194f, 0.00012832840729970485f, 0.00013541291991714388f, 0.0002473820641171187f, 0.0001768279034877196f, 5.8542227634461597e-05f, 0.0001113271719077602f, 0.00017868916620500386f, 5.076543675386347e-05f, 5.35502695129253e-05f, 0.00022947021352592856f, 0.00026694085681810975f, 0.00017090860637836158f, 0.0002911496558226645f, 0.0002055850491160527f, 0.0001621432020328939f, 0.00015372090274468064f, 0.0001605619618203491f, 0.0001555032067699358f, 0.00018677179468795657f, 0.0003205069515388459f, 0.00017094954091589898f, 0.00025604834081605077f, 0.00031042651971802115f, 0.00015933065151330084f, 0.00020176036923658103f, 0.00011664952035062015f, 7.457254832843319e-05f, 0.00023899701773189008f, 0.00015386904124170542f, 0.00012048972712364048f, 0.00012583035277202725f, 0.00035241901059634984f, 0.00016448360111098737f, 0.0002200466115027666f, 0.00024729318101890385f, 0.0001270229695364833f, 0.00019901346240658313f, 0.00022218974481802434f, 0.00013715167006012052f, 0.00016928343393374234f, 9.314609633293003e-05f, 8.071240881690755e-05f, 0.00012259111099410802f, 2.2757911210646853e-05f, 0.000304213521303609f, 0.0002718062896747142f, 6.114545976743102e-05f, 0.0001512131857452914f, 0.00012755452189594507f, 0.00011087407619925216f, 0.00017335191660095006f, 0.0002725404337979853f, 7.904720405349508e-05f, 0.00024414158542640507f, 0.00012291978055145591f, 0.00014872131578158587f, 0.00018874765373766422f, 0.0002487559977453202f, 0.0001890834973892197f, 0.00013694078370463103f, 0.00025067085516639054f, 0.00016031882842071354f, 0.0001245932508027181f, 0.00010573855979600921f, 9.883458551485091e-05f, 5.792170122731477e-05f, 0.00023914389021229f, 0.00015412118227686733f, 0.00014842870587017387f, 0.00015339566743932664f, 0.00022122383234091103f, 0.00022680754773318768f, 0.00019771716324612498f, 0.00010028180986410007f, 0.000183724652742967f, 8.433796028839424e-05f, 0.00011034733324777335f, 0.00012068879004800692f, 0.00023996582604013383f, 0.00022439142048824579f, 0.00020358779875095934f, 0.00011132837971672416f, 9.821479034144431e-05f, 0.00011411449668230489f, 0.000178848669747822f, 8.894352504285052e-05f, 0.00021699968783650547f, 0.00014595301763620228f, 0.00028834864497184753f, 7.250400813063607e-05f, 0.00015052457456476986f, 0.00011706623627105728f, 5.0555227062432095e-05f, 0.00012153974967077374f, 0.00013758208660874516f, 0.0003585757513064891f, 0.0002407096471870318f, 0.0001555879571242258f, 0.00015269994037225842f, 9.310540917795151e-05f, 0.00018190272385254502f, 0.0001565664861118421f, 7.607311999890953e-05f, 0.0001939282810781151f, 7.60977272875607e-05f, 0.00016634335042908788f, 0.00022788584465160966f, 0.0004051439755130559f, 0.0002496617380529642f, 4.719703065347858e-05f, 0.00015549473755527288f, 8.106060704449192e-05f, 0.00025828793877735734f),
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
    AI_PACK_INTQ_SCALE(0.00022582156816497445f, 0.00029992221971042454f, 0.00015930572408251464f, 0.0001667582109803334f, 0.00015852887008804828f, 6.029370706528425e-05f, 0.000156848574988544f, 0.000210481695830822f, 0.0001002143180812709f, 0.00020297715673223138f, 0.00018664314120542258f, 0.0002399048098595813f, 0.00023397344921249896f, 0.000309627503156662f, 0.0002497785026207566f, 0.0001914654130814597f, 0.00029072610777802765f, 0.00013823917834088206f, 0.00023564866569358855f, 0.00028043417842127383f, 0.00025638798251748085f, 0.00023776924354024231f, 0.00024570655659772456f, 0.00012405976303853095f, 0.00015287309361156076f, 0.0003294114430900663f, 0.00022346465266309679f, 9.075338311959058e-05f, 0.0002253044513054192f, 0.0002651956456247717f, 0.00022836921561975032f, 0.00044710058136843145f, 0.0002933228388428688f, 0.000209669437026605f, 0.0001223448198288679f, 0.0002945142041426152f, 0.00020429297001101077f, 0.00022916804300621152f, 0.00037256479845382273f, 0.0002824509283527732f, 0.00014193053357303143f, 0.00023153849178925157f, 0.0001417476451024413f, 0.00025470784748904407f, 0.000252009165706113f, 0.00033012620406225324f, 0.0004750315856654197f, 0.00015449622878804803f, 0.0001431740092812106f, 0.0002161818993045017f, 0.0001393825514242053f, 0.00018244604871142656f, 0.00012181338388472795f, 0.0002906249137595296f, 0.0001674202794674784f, 8.789091225480661e-05f, 0.00018160160107072443f, 0.0003903689794242382f, 0.0001982647372642532f, 0.00023917366343084723f, 0.0004424503131303936f, 0.00023625358880963176f, 0.0002494690415915102f, 0.00026418757624924183f, 0.00021175932488404214f, 7.489869312848896e-05f, 0.00025501276832073927f, 0.0002536325773689896f, 0.00022981688380241394f, 0.0005064904107712209f, 0.00020711898105219007f, 0.0002930183254648f, 0.000156713358592242f, 0.00015565079229418188f, 0.00017606407345738262f, 0.00024985740310512483f, 0.0003512150433380157f, 0.00021109968656674027f, 0.00024530765949748456f, 0.00021407684835139662f, 0.00010798717266879976f, 8.216097194235772e-05f, 0.00029962335247546434f, 0.00024670749553479254f, 0.00021289668802637607f, 0.00017584030865691602f, 0.00027688161935657263f, 0.00020381920330692083f, 0.00042459950782358646f, 0.0002662014157976955f, 0.0001890522544272244f, 0.00024882599245756865f, 0.00018851699132937938f, 0.00022947769321035594f, 0.00018304884724784642f, 0.00017133996880147606f, 0.0001336813875241205f, 0.00030021180282346904f, 9.27098881220445e-05f, 0.00016364827752113342f, 0.0003593684814404696f, 0.00027206804952584207f, 0.0001586254802532494f, 9.705000411486253e-05f, 0.000317335594445467f, 0.00020168589253444225f, 8.670115494169295e-05f, 0.00023787606914993376f, 0.0002781613729894161f, 0.00023162193247117102f, 0.00018501118756830692f, 0.00018537940923124552f, 0.0002574550162535161f, 0.00020106520969420671f, 0.00023535436776001006f, 0.00013164951815269887f, 0.00020501734979916364f, 0.0001636102533666417f, 0.0002172469103243202f, 0.0002813222527038306f, 0.0002600584994070232f, 9.898978169076145e-05f, 0.00020716288418043405f, 0.00020475214114412665f, 2.4823337298585102e-05f, 0.00018154959252569824f, 0.00024026489700190723f, 0.00011197803542017937f, 0.00025989243295043707f, 0.0002692801062949002f, 0.000143599376315251f, 0.00022844111663289368f, 0.00022484305372927338f, 0.0001768809015629813f, 0.00010786620259750634f, 0.00033622750197537243f, 0.00014383523375727236f, 0.00028619932709261775f, 0.00011295198055449873f, 0.00011727830133168027f, 0.00020163593580946326f, 0.00017201722948811948f, 0.00023162893194239587f, 0.00037777458783239126f),
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
    AI_PACK_INTQ_SCALE(6.172473513288423e-05f, 0.0002264573413413018f, 6.070310701034032e-05f, 0.00016355693514924496f, 0.00020772707648575306f, 0.00010857117013074458f, 0.0001621233968762681f, 0.0001122308021876961f, 0.0002709186519496143f, 0.00017052009934559464f, 0.00028639246011152864f, 0.00015783759590703994f, 0.00011103681026725098f, 0.00045492054778151214f, 0.000344197906088084f, 8.678778976900503e-05f, 0.00023391556169372052f, 0.00016416507423855364f, 0.0003480972955003381f, 0.00020991070778109133f, 0.00016808771761134267f, 0.00011333440488670021f, 8.694605639902875e-05f, 0.00016440347826573998f, 0.00014149193884804845f, 7.217163511086255e-05f, 0.0001455641322536394f, 0.00014531576016452163f, 0.00017229255172424018f, 0.0002607980859465897f, 0.0001902174117276445f, 0.00011019314842997119f, 0.00018820234981831163f, 0.00019073851581197232f, 0.00023915086057968438f, 0.00036623553023673594f, 9.384412260260433e-05f, 0.0002449758758302778f, 0.00017026056593749672f, 0.0003670091391541064f, 3.935321365133859e-05f, 0.00015615376469213516f, 0.0002652205293998122f, 7.146452844608575e-05f, 7.10372332832776e-05f, 0.00010968455899273977f, 0.00013405825302470475f, 0.00014602976443711668f, 0.0001577118964632973f, 0.0001591209293110296f, 9.568563109496608e-05f, 6.243914685910568e-05f, 0.0002537469263188541f, 0.0002566091134212911f, 0.00020550325280055404f, 0.00021140824537724257f, 0.00017888563161250204f, 9.799336839932948e-05f, 0.0001465766690671444f, 9.766893344931304e-05f, 0.00015153904678300023f, 7.784894842188805e-05f, 0.0002578116545919329f, 6.404879968613386e-05f, 0.0001594456407474354f, 0.00019572212477214634f, 0.00010318952990928665f, 8.3358638221398e-05f, 0.00010411623952677473f, 0.00017301093612331897f, 0.00023611220240127295f, 5.013489135308191e-05f, 0.0002247408265247941f, 0.0001104063558159396f, 0.0001283301826333627f, 9.321971447207034e-05f, 0.00021734640176873654f, 0.0001486103137722239f, 0.00024866676540113986f, 5.824388063047081e-05f, 0.00011825215915450826f, 0.00019407231593504548f, 0.0001952147576957941f, 0.00016216433141380548f, 0.00011565982276806608f, 0.00017888765432871878f, 7.590960740344599e-05f, 7.272072980413213e-05f, 0.00019084721861872822f, 0.0002060953265754506f, 0.00018830546468961984f, 0.00012913558748550713f, 0.00011669996456475928f, 7.608017040183768e-05f, 0.0001466353132855147f, 9.199843043461442e-05f, 0.0001227942411787808f, 6.070138988434337e-05f, 0.0002497755631338805f, 7.60199545766227e-05f, 0.0001324894546996802f, 0.00013328423665370792f, 0.00013638021482620388f, 0.00011985859600827098f, 0.0002202508330810815f, 0.0002987777115777135f, 7.34073983039707e-05f, 3.2158164685824886e-05f, 0.00013980406220071018f, 0.00022281601559370756f, 7.910325803095475e-05f, 0.00022721840650774539f, 6.815285451011732e-05f, 7.377054134849459e-05f, 0.00018130967509932816f, 0.0001055689062923193f, 0.00020384947129059583f, 9.773341298568994e-05f, 0.00014954509970266372f, 0.00017547501192893833f, 4.2318482883274555e-05f, 6.473057874245569e-05f, 0.00021785864373669028f, 0.0001661285787122324f, 0.00010246664169244468f, 0.0003016860573552549f, 9.459032298764214e-05f, 0.000332445721141994f, 0.00011600621655816212f, 0.00018296041525900364f, 8.408218127442524e-05f, 0.00018413351790513843f, 6.163087527966127e-05f, 0.00013022984785493463f, 0.0001273059897357598f, 0.0001776918797986582f, 0.00023474052431993186f, 0.00021334773919079453f, 0.00017989765910897404f, 0.00023485615383833647f, 0.00017117979587055743f, 0.00017311768897343427f, 0.0002448381274007261f, 0.00010107157868333161f, 0.00011858694779220968f, 9.038724965648726e-05f, 0.00027387100271880627f, 0.00022769130009692162f, 0.0001963087124750018f, 0.00021206251403782517f, 0.00016770664660725743f, 7.823755004210398e-05f, 0.0003279894881416112f, 0.00016219366807490587f, 4.892502329312265e-05f, 4.8795784096000716e-05f, 0.0001659019908402115f, 0.00020215056429151446f, 0.000292807089863345f, 0.00010855078289750963f, 0.00017266906797885895f, 0.0001481547806179151f, 0.00016263437282759696f, 0.0001308479841100052f, 6.710982415825129e-05f, 6.0116675740573555e-05f, 0.0001558443473186344f, 0.00025211682077497244f, 5.5637250625295565e-05f, 7.159030064940453e-05f, 7.0207730459515e-05f, 7.003270002314821e-05f, 0.00019131999579258263f, 0.00011033830378437415f, 0.00016756814147811383f, 0.00019926985260099173f, 0.0001789829257177189f, 0.00018149522657040507f, 0.0002330384886590764f, 0.00014961745182517916f, 0.00010564136755419895f, 0.00018979099695570767f, 0.00018892869411502033f, 0.000132183195091784f, 0.0001621926057850942f, 0.00019726954633370042f, 0.00017598913109395653f, 0.00014066706353332847f, 0.000150201260112226f, 0.0001327225472778082f, 0.00027500189025886357f, 0.00017950944311451167f),
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
    AI_PACK_INTQ_SCALE(0.00018426017777528614f, 0.00010975869372487068f, 0.0001558794901939109f, 0.00011677963630063459f, 0.0002583032473921776f, 0.00010918352927546948f, 0.00013365810445975512f, 0.00017858677892945707f, 0.00011345898383297026f, 0.00016716022219043225f, 0.0001545626000734046f, 0.00021591730182990432f, 5.514211443369277e-05f, 0.0001577657531015575f, 7.25455247447826e-05f, 0.00014663486217614263f, 0.00023285570205189288f, 0.00013221829431131482f, 0.00016844546189531684f, 0.00010184669372392818f, 0.00012766290456056595f, 0.0002279492182424292f, 0.00022130191791802645f, 0.00021366447617765516f, 0.0001707487681414932f, 7.312798697967082e-05f, 0.00016532736481167376f, 0.00014502910198643804f, 0.00022754387464374304f, 0.00012004325253656134f, 0.00013546300760935992f, 0.00020121963461861014f, 7.035976159386337e-05f, 7.341085438383743e-05f, 0.00015478285786230117f, 0.00014785405073780566f, 5.090225022286177e-05f, 0.00012769983732141554f, 0.0001044654636643827f, 0.00020225295156706125f, 0.00010191200999543071f, 0.0001812669652281329f, 0.00012660623178817332f, 0.00024022733850870281f, 0.000110348490125034f, 0.0001733955432428047f, 0.00011545013694558293f, 0.00012940751912537962f, 0.0003196346515323967f, 0.0001630763290449977f, 0.00013580014638137072f, 0.00020082284754607826f, 0.00020149747433606535f, 3.4255426726303995e-05f, 0.00020443172252271324f, 4.600674219545908e-05f, 0.00016288981714751571f, 0.00017396468319930136f, 0.00015323732804972678f, 0.0001672154467087239f, 0.00011828920833067968f, 0.0003039407019969076f, 0.00018599926261231303f, 0.0001341345632681623f, 6.62449310766533e-05f, 0.00016806653002277017f, 0.0001872571010608226f, 8.91384479473345e-05f, 0.0002320306230103597f, 0.00010527739505050704f, 0.0001034976594382897f, 0.0001108453216147609f, 0.00011337910837028176f, 0.00018506903143133968f, 0.00023949587193783373f, 0.00017942197155207396f, 0.0002008633891819045f, 0.0001711906515993178f, 8.682411862537265e-05f, 0.0002699722826946527f, 0.00012372287164907902f, 0.00015431521751452237f, 0.00017441061208955944f, 0.00010453075810801238f, 0.0001455954770790413f, 7.131026359274983e-05f, 0.0001981332607101649f, 0.00012989318929612637f, 0.00014196346455719322f, 0.00018722668755799532f, 0.0001803870254661888f, 0.00020709224918391556f, 0.00016519900236744434f, 0.0002316343307029456f, 0.00020792448776774108f, 0.00011987910693278536f, 9.859546844381839e-05f, 0.00024092485546134412f, 0.00015660558710806072f, 0.00015326253196690232f, 0.0001217450262629427f, 0.0001884262601379305f, 8.003232505870983e-05f, 0.00016565648547839373f, 0.00018666779214981943f, 8.69856885401532e-05f, 0.00014106534945312887f, 0.00014911334437783808f, 0.00021388738241512328f, 0.00013304293679539114f, 0.0001648080360610038f, 9.683938696980476e-05f, 4.765154517372139e-05f, 0.0001775516866473481f, 0.00016294518718495965f, 0.000160288080223836f, 0.00016680087719578296f, 9.214608871843666e-05f, 0.00018137748702429235f, 0.00018846603052224964f, 9.636308823246509e-05f, 0.00012673066521529108f, 0.00015921973681543022f, 0.00010489190754014999f, 0.00018295929476153105f, 0.0001094894323614426f, 0.00014465961430687457f, 0.0001725925103528425f, 0.0001977752981474623f, 7.038205512799323e-05f, 0.00018127600196748972f, 5.969448102405295e-05f, 0.000527755415532738f, 0.00015169238031376153f, 9.061036689672619e-05f, 0.00013372620742302388f, 0.00022272254864219576f, 0.00011446008284110576f, 9.656528709456325e-05f, 0.0002120927529176697f, 0.00018937558343168348f, 0.00019329517090227455f, 0.00016793406393844634f, 0.00023461601813323796f, 0.00010484438826097175f, 0.00025329209165647626f, 0.00014208715583663434f, 0.00016776671691332012f, 7.04666817910038e-05f, 0.0001312142121605575f, 0.00021164196368772537f, 0.00017470464808866382f, 0.00019279561820439994f, 0.000186694654985331f, 0.00021883982117287815f, 0.0002310871350346133f, 7.250255293911323e-05f, 0.00019494151638355106f, 0.00016657193191349506f, 0.00018992785771843046f, 0.00026723305927589536f, 0.00026075905770994723f, 0.00015261021326296031f, 0.00029536226065829396f, 0.0001873947912827134f, 0.0001402702764607966f, 0.00019733233784791082f, 0.00015437231922987849f, 6.130668771220371e-05f, 0.00018025973986368626f, 0.00016612991748843342f, 0.00014092438505031168f, 7.584811100969091e-05f, 9.62975318543613e-05f, 7.956015906529501e-05f, 8.341488864971325e-05f, 0.00015679032367188483f, 0.0001278593554161489f, 0.00015164288925006986f, 0.0001952782622538507f, 0.0001629460894037038f, 0.00015837156388442963f, 0.0001587502338225022f, 0.00019499716290738434f, 0.00036440524854697287f, 0.00018724102119449526f, 6.932775431778282e-05f, 0.00013365810445975512f, 0.00027203329955227673f, 0.00018122211622539908f, 0.00021676046890206635f, 0.0001773058029357344f),
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
    AI_PACK_INTQ_SCALE(0.00023212148516904563f, 0.00019106135005131364f, 0.00018044395255856216f, 0.0001433617144357413f, 0.0001975541381398216f, 0.0003210937138646841f, 0.000550890457816422f, 0.0003293195622973144f, 0.00032535180798731744f, 0.00034075407893396914f, 0.0001738195715006441f, 0.00018544781778473407f, 0.00016525216051377356f, 0.000216642816667445f, 0.00040723776328377426f, 0.0001834674330893904f, 0.00026356815942563117f, 8.853623876348138e-05f, 0.0002837018691934645f, 0.00029872500454075634f, 0.000343146501109004f, 0.00014722794003318995f, 0.00019876420265063643f, 0.0002014915517065674f, 0.00021470451611094177f, 0.00021486483456101269f, 0.00021704896062146872f, 0.00026654134853743017f, 0.0001943355891853571f, 0.00017920814570970833f, 0.0002544755698181689f, 0.00025286898016929626f, 0.00022503567743115127f, 0.00022338118287734687f, 0.0001914434542413801f, 0.0002796077460516244f, 0.0003853537782561034f, 0.000204125142772682f, 0.0001806615327950567f, 0.0002574849931988865f, 0.00022435701976064593f, 0.00018595629080664366f, 0.00034466618672013283f, 0.00025292299687862396f, 0.000232142090681009f, 0.0002142170851584524f, 0.00030195017461664975f, 0.00024100011796690524f, 0.00026954346685670316f, 0.00018583891505841166f, 0.0002119062264682725f, 0.00019866216462105513f, 0.00020717862935271114f, 0.0003036162524949759f, 0.00033976585837081075f, 0.00021268225100357085f, 0.00024437581305392087f, 0.0001759358710842207f, 0.00021420969278551638f, 0.00020023591059725732f, 0.000323039828799665f, 0.00017927921726368368f, 0.00023331343254540116f, 0.00013618484081234783f, 0.00033133436227217317f, 0.00026852908194996417f, 0.0002550905628595501f, 0.00029248817008920014f, 0.0002347383415326476f, 0.00030305233667604625f, 0.00019855295249726623f, 0.00023043164401315153f, 0.00019693310605362058f, 0.00035283793113194406f, 0.00021941812883596867f, 0.0003643161617219448f, 0.00028816834674216807f, 0.0002656802535057068f, 3.8542650145245716e-05f, 0.00014164019376039505f, 0.00024585388018749654f, 0.00022742761939298362f, 0.00042275621672160923f, 0.00022390282538253814f, 0.00032577375532127917f, 0.00029208112391643226f, 0.0001838982425397262f, 0.00022531612194143236f, 0.0004508933052420616f, 0.0001684267626842484f, 0.00037501699989661574f, 0.0002605918562039733f, 0.00031307662720791996f, 0.00024360201496165246f, 0.000358615507138893f, 0.00032390610431320965f, 0.00039409546297974885f, 0.00014928235032130033f, 0.00029168956098146737f, 0.00017193496751133353f, 0.00024739871150813997f, 0.000225944459089078f, 0.00032322085462510586f, 0.00019666530715767294f, 0.00018418682157061994f, 0.00026096004876308143f, 0.0001881582720670849f, 0.00023438660718966275f, 0.0001382818736601621f, 0.00032012458541430533f, 0.00019218707166146487f, 0.0002698136668186635f, 0.000267124327365309f, 0.00017388844571541995f, 0.0002457855152897537f, 0.000339859543601051f, 0.00028570223366841674f, 0.0002287801617057994f, 0.0001667933538556099f, 0.0003085724310949445f, 0.0002829463337548077f, 0.0001426669623469934f, 0.0003718877269420773f, 0.0002712912973947823f, 0.00032555003417655826f, 0.0003018212446477264f, 0.00030026771128177643f, 0.00014135093078948557f, 0.0001803558407118544f, 5.502535714185797e-05f, 0.0001681341091170907f, 0.000269592012045905f, 0.0004475429595913738f, 0.00015801898553036153f, 0.0003208457783330232f, 0.00016933066945057362f, 0.00020034899353049695f, 0.00020605874306056648f, 0.00018729463045019656f, 0.00026076656649820507f, 0.000282908120425418f, 0.00021328087314032018f, 0.0001380197936668992f, 0.00019922015781048685f, 0.00037458501174114645f, 0.00047206610906869173f, 0.00020898923685308546f, 0.00020487357687670738f, 0.00020128823234699667f, 0.00020501464314293116f, 0.00021300610387697816f, 0.00020792076247744262f, 0.00023019249783828855f, 0.00021430612832773477f, 0.00017443647084292024f, 0.00024002441205084324f, 0.00024095515254884958f, 0.0002865800051949918f, 0.00047626777086406946f, 0.0001691652141744271f, 0.00023758228053338826f, 0.0001710707729216665f, 0.00024184345966205f, 0.0003046301717404276f, 0.00012598135799635202f, 0.00019282363064121455f, 0.00017925437714438885f, 0.00019309289928060025f, 0.0002595045370981097f, 0.00021480668510776013f, 0.0002553245285525918f, 0.00019736723334062845f, 0.00020855893671978265f, 0.00026997391250915825f, 0.0002032109332503751f, 0.0002770514111034572f, 0.00034485847572796047f, 0.000250024109845981f, 0.000248198484769091f, 0.0003020401927642524f, 0.00042088801274076104f, 0.0002079425030387938f, 0.00018460968567524105f, 0.0001780076854629442f, 0.00021576763538178056f, 0.00028434325940907f, 0.00022818836441729218f, 0.00015362471458502114f, 0.000141819822601974f, 0.0003682515234686434f, 0.0002294359146617353f, 5.7300461776321754e-05f),
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
    AI_PACK_INTQ_SCALE(0.00042928577749989927f, 0.0005573263624683022f, 0.0004090734291821718f, 0.0007260119309648871f, 0.0005148794734850526f, 0.0005679684691131115f, 0.0005150361103005707f, 0.0009229715797118843f, 0.0007861324120312929f, 0.0004690679779741913f, 0.0004847782838623971f, 0.0006044183392077684f, 0.0004163326520938426f, 0.00040144348167814314f, 0.0005693355924449861f, 0.000824830261990428f, 0.0007785637862980366f, 0.0016101333312690258f, 0.0005788090056739748f, 0.000602437648922205f, 0.000967905973084271f, 0.0005683291819877923f, 0.0006322715780697763f, 0.0006145351799204946f, 0.0005178914871066809f, 0.0007041294011287391f, 0.0004777975264005363f, 0.0009330672910436988f, 0.0009362092241644859f, 0.0005970708443783224f, 0.0007456050952896476f, 0.0012741971295326948f, 0.0004618161474354565f, 0.0008420507656410336f, 0.0014397981576621532f, 0.0014380370266735554f, 0.0006781695410609245f, 0.0013118732022121549f, 0.000704277481418103f, 0.0004688726912718266f, 0.000779030320700258f, 0.001924334210343659f, 0.0007867860840633512f, 0.0006610905984416604f, 0.0008392397430725396f, 0.00047642859863117337f, 0.0008134982781484723f, 0.0009492703247815371f, 0.0009797585662454367f, 0.0006502544274553657f, 0.000961769837886095f, 0.0005364881944842637f, 0.0005042045377194881f, 0.0005224474589340389f, 0.0009910512017086148f, 0.0010730904759839177f, 0.0007974145119078457f, 0.0013076630420982838f, 0.0014045099960640073f, 0.0009525254718028009f, 0.0011431716848164797f, 0.003588717197999358f, 0.0009396056411787868f, 0.0009595952578820288f, 0.0005786056281067431f, 0.0010048910044133663f, 0.0006285416893661022f, 0.001123863155953586f, 0.0007415009313262999f, 0.0011331979185342789f, 0.0005774335004389286f, 0.001570980530232191f, 0.000394271599361673f, 0.0004936536424793303f, 0.0010369508527219296f, 0.000987194711342454f, 0.001059159985743463f, 0.00035875928006134927f, 0.0009492933750152588f, 0.0010158660588786006f, 0.0005084961885586381f, 0.0005768781411461532f, 0.0013241821434348822f, 0.0008347340044565499f, 0.0006211516447365284f, 0.0010432974668219686f, 0.0004932357696816325f, 0.0009661538060754538f, 0.001089937868528068f, 0.0015245556132867932f, 0.0006366211455315351f, 0.000887481844983995f, 0.0008756717434152961f, 0.000677277974318713f, 0.0008258528541773558f, 0.000477377325296402f, 0.0006047216011211276f, 0.00038295378908514977f, 0.0006154270377010107f, 0.00042180027230642736f, 0.0008751673740334809f, 0.0009809371549636126f, 0.0006114071002230048f, 0.0006457034032791853f, 0.0005594762042164803f, 0.0011376721085980535f, 0.0006024775211699307f, 0.0005689411773346364f, 0.0008815153269097209f, 0.0007793987169861794f, 0.0008786312537267804f, 0.0003590694395825267f, 0.0009322756086476147f, 0.0006261438247747719f, 0.0011871234746649861f, 0.0012701029190793633f, 0.000980932847596705f, 0.0006507301004603505f, 0.0007793800323270261f, 0.0012517876457422972f, 0.0011989576742053032f, 0.0005910518229939044f, 0.0006023484747856855f, 0.0010605129646137357f, 0.0011509854812175035f, 0.00047690622159279883f, 0.0009177171159535646f, 0.0006379784317687154f, 0.0007719465647824109f, 0.00097542634466663f, 0.0010574677726253867f, 0.0006045941263437271f, 0.0019562530796974897f, 0.001086596050299704f, 0.0008885955903679132f, 0.0010827850783243775f, 0.0011377132032066584f, 0.0005367817939259112f, 0.0013084581587463617f, 0.0006138592725619674f, 0.0012123218039050698f, 0.0006685921689495444f, 0.001143662491813302f, 0.0007773596444167197f, 0.00042236311128363013f, 0.001072858227416873f, 0.00043181743239983916f, 0.0008299274486489594f, 0.0004679902922362089f, 0.0006561424816027284f, 0.0007713463855907321f, 0.0009897274430841208f, 0.0009702134993858635f, 0.00027215946465730667f, 0.0011848628055304289f, 0.0014811479486525059f, 0.0006345989531837404f, 0.0010355828562751412f, 0.0008458707015961409f, 0.001581934280693531f, 0.0005138227134011686f, 0.0004411432601045817f, 0.0005788367707282305f, 0.0009980074828490615f, 0.0007114825421012938f, 0.00079846300650388f, 0.001022895099595189f, 0.0005114851519465446f, 0.0009039583965204656f, 0.0011467484291642904f, 0.0017324271611869335f, 0.0005634224507957697f, 0.0005623736069537699f, 0.0009739467641338706f, 0.0002510290942154825f, 0.0007609115564264357f, 0.0015174215659499168f, 0.0006317541119642556f, 0.0009206317481584847f, 0.0005621887394227087f, 0.0011028610169887543f, 0.0009676131303422153f, 0.0007311873487196863f, 0.0005404276889748871f, 0.0011439656373113394f, 0.0008048087474890053f, 0.0005928612663410604f, 0.00044965880806557834f, 0.0009069514344446361f, 0.0008229275117628276f, 0.0011212972458451986f, 0.00032042645034380257f, 0.001264982856810093f, 0.0004843043570872396f, 0.0003642999508883804f, 0.002302232664078474f, 0.0006788295577280223f, 0.0005031576147302985f, 0.0011653297115117311f, 0.0007154963095672429f, 0.001283424673601985f, 0.00050448311958462f, 0.0011317169992253184f, 0.0011204552138224244f, 0.0004353293334133923f, 0.0013179552042856812f, 0.0005034518544562161f, 0.00037929427344352007f, 0.003340802388265729f, 0.0011555296368896961f, 0.000933205068577081f, 0.001375598250888288f, 0.0012258555507287383f, 0.0006133101414889097f, 0.0009291812893934548f, 0.000768377271015197f, 0.000663168728351593f, 0.0005510458140634f, 0.0009852818911895156f, 0.0009334433707408607f, 0.0019347126362845302f, 0.0006776598165743053f, 0.00037151234573684633f, 0.0006033910904079676f, 0.0003061455499846488f, 0.0011469109449535608f, 0.0011456392239779234f, 0.0009130337275564671f, 0.0002562442678026855f, 0.0008723823120817542f, 0.0010401204926893115f, 0.0005696446751244366f, 0.00013729449710808694f, 0.0009562266059219837f, 7.204235430435801e-09f, 0.0003465105255600065f, 0.0006356291123665869f, 0.0004644568543881178f, 0.0011109376791864634f, 0.0008332154247909784f, 0.0008288684766739607f, 0.00037669253651984036f, 0.0008199381409212947f, 0.0005774049204774201f, 0.0009018635028041899f, 0.0004603192210197449f, 0.0008788726408965886f, 0.0012339743552729487f, 0.0015696792397648096f, 0.0008403704850934446f, 0.0011186953634023666f, 0.0006399783305823803f, 0.0007694389787502587f, 0.0009070888627320528f, 0.0007168992888182402f, 0.0008703829371370375f, 0.0008026679279282689f, 0.0006494582048617303f, 0.001187171321362257f, 0.0006230896688066423f, 0.0009940371382981539f, 0.0005582367302849889f, 0.0004947673878632486f, 0.0003460619191173464f, 0.0009544598287902772f, 0.0005282929632812738f, 0.0008626411436125636f, 0.0004283000307623297f, 0.0009380962583236396f, 0.0012376990634948015f, 0.00038440630305558443f, 0.0005566786276176572f, 0.0005957828834652901f, 0.00039023635326884687f, 0.0007911575958132744f, 0.0009794948855414987f, 0.0005728279356844723f, 0.0013190656900405884f, 0.0008897414663806558f, 0.0005299331387504935f, 0.0008591029909439385f, 0.0008673944394104183f, 0.0005265825311653316f, 0.0007710435893386602f, 0.00046137289609760046f, 0.0007181822438724339f, 0.00040795208769850433f, 0.0012254122411832213f, 0.000605476088821888f, 0.0010225636651739478f, 0.00042088847840204835f, 0.001150153111666441f, 0.00046918896259739995f, 0.0007569235749542713f, 0.000803229515440762f, 0.0005900604883208871f, 0.000632172916084528f, 0.0008349006529897451f, 0.0007107594865374267f, 0.0008300148183479905f, 0.0009458669810555875f, 0.0014344279188662767f, 0.0009254714823327959f, 0.0008149297791533172f, 0.0008740840130485594f, 0.0005085791344754398f, 0.000610063667409122f, 0.0006398322293534875f, 0.0006539832684211433f, 0.00045568248606286943f, 0.0005118445260450244f, 0.0009463104070164263f, 0.0008628928917460144f, 0.0005833353498019278f, 0.00044552728650160134f, 0.0007002161000855267f, 0.0012015693355351686f, 0.0009570936672389507f, 0.0012327816803008318f, 0.0011633527465164661f, 0.000509640434756875f, 0.0009236938203684986f, 0.0012286078417673707f, 0.0011581461876630783f, 0.0012017444241791964f, 0.0013574251206591725f, 0.00032553254277445376f, 0.0006464249454438686f, 0.0014054671628400683f, 0.0008068879833444953f, 0.0011563068255782127f, 0.0007944353856146336f, 0.0013724536402150989f, 0.0010799398878589272f, 0.0012260806979611516f, 0.00012736738426610827f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #152 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 336,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(5.881498145754449e-05f, 7.635738438693807e-05f, 5.604575926554389e-05f, 9.946842328645289e-05f, 7.0541886088904e-05f, 7.781542808515951e-05f, 7.056334288790822e-05f, 0.00012645318929571658f, 0.00010770532389869913f, 6.42654049443081e-05f, 6.641782238148153e-05f, 8.280929614556953e-05f, 5.704032082576305e-05f, 5.5000404245220125e-05f, 7.800273306202143e-05f, 0.00011300718324491754f, 0.00010666837624739856f, 0.0002205988857895136f, 7.930065476102754e-05f, 8.253793203039095e-05f, 0.00013260950800031424f, 7.786484638927504e-05f, 8.662537584314123e-05f, 8.419537334702909e-05f, 7.095454930095002e-05f, 9.647037222748622e-05f, 6.546141230501235e-05f, 0.0001278363779420033f, 0.00012826683814637363f, 8.180264558177441e-05f, 0.00010215281508862972f, 0.00017457340436521918f, 6.327185838017613e-05f, 0.0001153665070887655f, 0.0001972618483705446f, 0.00019702056306414306f, 9.291370224673301e-05f, 0.0001797352742869407f, 9.649065759731457e-05f, 6.423865124816075e-05f, 0.00010673229553503916f, 0.00026364647783339024f, 0.00010779488366097212f, 9.057376882992685e-05f, 0.00011498138337628916f, 6.527385994559154e-05f, 0.00011145463213324547f, 0.00013005630171392113f, 0.00013423338532447815f, 8.908914605854079e-05f, 0.00013176881475374103f, 7.350242231041193e-05f, 6.907934584887698e-05f, 7.15787464287132e-05f, 0.0001357805449515581f, 0.00014702047337777913f, 0.0001092510501621291f, 0.0001791584654711187f, 0.00019242713460698724f, 0.0001305022742599249f, 0.00015662205987609923f, 0.0004916778998449445f, 0.00012873216473963112f, 0.00013147087884135544f, 7.927278784336522e-05f, 0.00013767668860964477f, 8.611435623606667e-05f, 0.00015397666720673442f, 0.00010159052180824801f, 0.0001552555913804099f, 7.911220018286258e-05f, 0.00021523470059037209f, 5.4017807997297496e-05f, 6.76338022458367e-05f, 0.00014206911146175116f, 0.00013525217946153134f, 0.00014511190238408744f, 4.915238605462946e-05f, 0.00013005945947952569f, 0.00013918035256210715f, 6.966733053559437e-05f, 7.903610821813345e-05f, 0.0001814216811908409f, 0.00011436406202847138f, 8.510187035426497e-05f, 0.00014293863205239177f, 6.757655501132831e-05f, 0.00013236944505479187f, 0.00014932868361938745f, 0.00020887417485937476f, 8.722129859961569e-05f, 0.00012159086327301338f, 0.00011997280671494082f, 9.279154619434848e-05f, 0.00011314728908473626f, 6.540384492836893e-05f, 8.285084913950413e-05f, 5.24671959283296e-05f, 8.431756577920169e-05f, 5.778942067991011e-05f, 0.0001199036996695213f, 0.0001343948533758521f, 8.376680489163846e-05f, 8.846562559483573e-05f, 7.665192970307544e-05f, 0.00015586857625748962f, 8.25433962745592e-05f, 7.79486945248209e-05f, 0.00012077341671101749f, 0.00010678276157705113f, 0.00012037827400490642f, 4.91948812850751e-05f, 0.00012772790796589106f, 8.578583219787106e-05f, 0.00016264374426100403f, 0.00017401247168891132f, 0.00013439427129924297f, 8.915431681089103e-05f, 0.00010678020771592855f, 0.0001715031685307622f, 0.00016426510410383344f, 8.097799582174048e-05f, 8.252571569755673e-05f, 0.00014529726468026638f, 0.0001576926006237045f, 6.53392999083735e-05f, 0.00012573329149745405f, 8.740725024836138e-05f, 0.00010576177010079846f, 0.00013363984180614352f, 0.0001448800612706691f, 8.283337956527248e-05f, 0.00026801956119015813f, 0.0001488708221586421f, 0.00012174345465609804f, 0.0001483486994402483f, 0.000155874207848683f, 7.354264380410314e-05f, 0.00017926740110851824f, 8.410277223447338e-05f, 0.00016609608428552747f, 9.160153422271833e-05f, 0.0001566893042763695f, 0.00010650340118445456f, 5.7866531278705224e-05f, 0.0001469886483391747f, 5.9161837270949036e-05f, 0.00011370553693268448f, 6.411775393644348e-05f, 8.989584603114054e-05f, 0.00010567954450380057f, 0.00013559918443206698f, 0.0001329256483586505f, 3.728764204424806e-05f, 0.00016233402129728347f, 0.00020292703993618488f, 8.694424468558282e-05f, 0.0001418816827936098f, 0.00011588986671995372f, 0.00021673542505595833f, 7.039710180833936e-05f, 6.0439535445766523e-05f, 7.930445281090215e-05f, 0.00013673360808752477f, 9.747780131874606e-05f, 0.00010939469939330593f, 0.00014014336920809f, 7.007683598203585e-05f, 0.00012384826550260186f, 0.00015711209562141448f, 0.00023735394643153995f, 7.719259156147018e-05f, 7.704889139859006e-05f, 0.00013343713362701237f, 3.439264037297107e-05f, 0.00010424989886814728f, 0.00020789676636923105f, 8.655447891214862e-05f, 0.0001261326251551509f, 7.702356379013509e-05f, 0.00015109922969713807f, 0.0001325693738181144f, 0.00010017748718382791f, 7.404216012218967e-05f, 0.00015673083544243127f, 0.0001102641035686247f, 8.122590224957094e-05f, 6.160622433526441e-05f, 0.000124258323921822f, 0.00011274650023551658f, 0.00015362512203864753f, 4.390053800307214e-05f, 0.0001733109966153279f, 6.635289173573256e-05f, 4.991149762645364e-05f, 0.0003154210571665317f, 9.300412784796208e-05f, 6.893591489642859e-05f, 0.00015965785132721066f, 9.802771091926843e-05f, 0.00017583764565642923f, 6.911751552252099e-05f, 0.00015505269402638078f, 0.00015350975445471704f, 5.964298907201737e-05f, 0.00018056856060866266f, 6.897622370161116e-05f, 5.1965816965093836e-05f, 0.0004577119543682784f, 0.0001583151752129197f, 0.0001278552517760545f, 0.00018846603052224964f, 0.00016795028932392597f, 8.40275315567851e-05f, 0.00012730396701954305f, 0.00010527275298954919f, 9.085849160328507e-05f, 7.549690781161189e-05f, 0.00013499011402018368f, 0.00012788789172191173f, 0.0002650684036780149f, 9.284386760555208e-05f, 5.089964179205708e-05f, 8.266855729743838e-05f, 4.194396024104208e-05f, 0.00015713436005171388f, 0.00015696012997068465f, 0.00012509163934737444f, 3.5107153962599114e-05f, 0.0001195221339003183f, 0.0001425033697159961f, 7.804507913533598e-05f, 1.881025127659086e-05f, 0.00013100935029797256f, 9.870277928314408e-10f, 4.747422644868493e-05f, 8.708538371138275e-05f, 6.36336553725414e-05f, 0.00015220578643493354f, 0.0001141560060204938f, 0.00011356044706190005f, 5.1609360525617376e-05f, 0.00011233693658141419f, 7.910828571766615e-05f, 0.00012356124352663755f, 6.306677096290514e-05f, 0.0001204113505082205f, 0.0001690626231720671f, 0.00021505641052499413f, 0.00011513629578985274f, 0.00015326864377129823f, 8.768125553615391e-05f, 0.00010541821393417194f, 0.00012427715410012752f, 9.821993444347754e-05f, 0.0001192482013721019f, 0.00010997080244123936f, 8.898005762603134e-05f, 0.00016265030717477202f, 8.536739187547937e-05f, 0.0001361896429443732f, 7.648211612831801e-05f, 6.778639362892136e-05f, 4.7412766434717923e-05f, 0.0001307672937400639f, 7.237961835926399e-05f, 0.00011818752682302147f, 5.8679928770288825e-05f, 0.00012852538202423602f, 0.00016957292973529547f, 5.266620064503513e-05f, 7.626864680787548e-05f, 8.162618178175762e-05f, 5.346495527192019e-05f, 0.00010839381138794124f, 0.00013419725291896611f, 7.848120731068775e-05f, 0.00018072070088237524f, 0.00012190044799353927f, 7.260433631017804e-05f, 0.00011770277342293411f, 0.00011883876140927896f, 7.214528159238398e-05f, 0.0001056380569934845f, 6.321113323792815e-05f, 9.839570702752098e-05f, 5.589212742052041e-05f, 0.000167889564181678f, 8.295421866932884e-05f, 0.0001400979672325775f, 5.7664496125653386e-05f, 0.00015757855726405978f, 6.428197957575321e-05f, 0.00010370352538302541f, 0.00011004773841705173f, 8.084217552095652e-05f, 8.661185711389408e-05f, 0.00011438689398346469f, 9.737873915582895e-05f, 0.00011371750588295981f, 0.00012959001469425857f, 0.00019652608898468316f, 0.00012679569772444665f, 0.00011165075557073578f, 0.00011975527741014957f, 6.967869558138773e-05f, 8.358274499187246e-05f, 8.766123210079968e-05f, 8.960002014646307e-05f, 6.243150710361078e-05f, 7.012607966316864e-05f, 0.000129650768940337f, 0.0001182220148621127f, 7.992079190444201e-05f, 6.104017666075379e-05f, 9.593422146281227e-05f, 0.00016462292114738375f, 0.00013112815213389695f, 0.00016889921971596777f, 0.00015938699652906507f, 6.982409831834957e-05f, 0.00012655214231926948f, 0.00016832737310323864f, 0.00015867366164457053f, 0.00016464691725559533f, 0.00018597619782667607f, 4.460010677576065e-05f, 8.856448403093964e-05f, 0.00019255827646702528f, 0.00011054897913709283f, 0.0001584216661285609f, 0.00010884289076784626f, 0.0001880352065199986f, 0.00014795888273511082f, 0.0001679811393842101f, 1.7450171071686782e-05f),
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
    AI_PACK_INTQ_SCALE(8.759037154959515e-05f, 0.00012155751755926758f, 0.00015085992345120758f, 0.00014363414084073156f, 0.00020354478328954428f, 0.00022009422536939383f, 0.00016970562865026295f, 0.0001046263932948932f, 0.0002689631946850568f, 0.00010563707473920658f, 0.00020408087584655732f, 0.00035479149664752185f, 9.392255742568523e-05f, 0.0002967199543491006f, 0.00022787046327721328f, 7.562009704997763e-05f, 0.00015041069127619267f, 0.000153379121911712f, 0.00014905212447047234f, 0.00012485022307373583f, 0.00016802312165964395f, 0.00015499097935389727f, 0.00026145658921450377f, 0.00012280452938284725f, 0.00022631636238656938f, 0.00013853849668521434f, 0.00011204901238670573f, 0.00023998209508135915f, 0.0001474114105803892f, 0.00011689934763126075f, 0.0002207935758633539f, 0.00037729807081632316f, 0.00011577601981116459f, 0.00017693829431664199f, 0.00010039071639766917f, 0.00016618581139482558f, 0.0001542022655485198f, 0.0002628773218020797f, 7.603198173455894e-05f, 0.00024074656539596617f, 0.00019857594452332705f, 0.0004632353375200182f, 0.00010365976777393371f, 0.00011192638339707628f, 0.0001258289848919958f, 0.0002701033081393689f, 0.00012281008821446449f, 0.00015200507186818868f, 0.00013803299225401133f, 0.00011808281124103814f, 0.00022419082233682275f, 0.00020205644250381738f, 0.00017693699919618666f, 0.0001885924575617537f, 0.0002026113506872207f, 0.00016025229706428945f),
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
    AI_PACK_INTQ_SCALE(8.508421888109297e-05f, 8.004615665413439e-05f, 0.00015207788965199143f, 9.798700193641707e-05f, 0.0001287145132664591f, 9.720037633087486e-05f, 0.0002493764040991664f, 0.0001099149085348472f, 0.00010464553633937612f, 0.00010365819616708905f, 3.995666702394374e-05f, 0.00018954127153847367f, 0.00015677104238420725f, 8.970789349405095e-05f, 8.388049900531769e-05f, 4.37124035670422e-05f, 0.00012582512863446027f, 0.000100466248113662f, 0.00020019688236061484f, 8.132644870784134e-05f, 6.0458685766207054e-05f, 0.00014333533181343228f, 0.00011147386976517737f, 0.000134280402562581f, 6.2600702221971e-05f, 9.692474850453436e-05f, 7.448328688042238e-05f, 9.373010834679008e-05f, 8.069934119703248e-05f, 0.00010064855450764298f, 4.726731640403159e-05f, 0.00013290237984620035f, 7.40581308491528e-05f, 0.00011270002869423479f, 9.48914821492508e-05f, 5.9646325098583475e-05f, 0.0001251811918336898f, 0.00012355206126812845f, 4.591042670654133e-05f, 5.6298064009752125e-05f, 7.630549225723371e-05f, 4.9769274482969195e-05f, 0.00016042051720432937f, 9.86613958957605e-05f, 0.00010858151654247195f, 0.00013707247853744775f, 0.00011158252891618758f, 0.00019810836238320917f, 0.00011607102351263165f, 0.00012376824452076107f, 6.033561658114195e-05f, 0.00010405850480310619f, 0.00012254566536284983f, 0.0001483628584537655f, 0.00010000900510931388f, 8.596476254751906e-05f, 0.00012382195563986897f, 0.00010100515646627173f, 8.17376931081526e-05f, 8.915663784136996e-05f, 6.525406206492335e-05f, 9.154926374321803e-05f, 0.0001097453641705215f, 3.8466445403173566e-05f, 9.15377022465691e-05f, 5.4626147175440565e-05f, 8.639818406663835e-05f, 5.4136231483425945e-05f, 0.0001102113674278371f, 0.00011521153646754101f, 5.445379429147579e-05f, 6.893058161949739e-05f, 0.00013109551218803972f, 0.00012798819807358086f, 8.954978693509474e-05f, 7.016245945123956e-05f, 0.00011342928337398916f, 6.355792720569298e-05f, 5.1253457058919594e-05f, 0.00010045156523119658f, 0.00014626732445321977f, 6.578226020792499e-05f, 0.00011290526890661567f, 7.89155310485512e-05f, 5.71537711948622e-05f, 7.591781468363479e-05f, 8.839371002977714e-05f, 7.01846947777085e-05f, 7.962188828969374e-05f, 0.00012140885519329458f, 6.909046351211146e-05f, 0.00012874638196080923f, 5.993148806737736e-05f, 0.00012773160415235907f, 0.00010291853686794639f, 8.22205183794722e-05f, 0.00010557874338701367f, 7.133598410291597e-05f, 0.00011221195018151775f, 8.404339314438403e-05f, 7.123621617211029e-05f, 9.617547038942575e-05f, 0.00011820411600638181f, 0.00010599319648463279f, 0.00010763587488327175f, 0.00014054773782845587f, 6.10641436651349e-05f, 0.00013338186545297503f, 0.00011673095286823809f, 0.0001512687304057181f, 6.008127820678055e-05f, 9.719933586893603e-05f, 7.110146543709561e-05f, 9.748553566168994e-05f, 0.0001624668948352337f, 0.00011180308501934633f, 0.0001228806795552373f, 8.286877709906548e-05f, 9.587489330442622e-05f, 0.00010418438614578918f, 7.051348802633584e-05f, 6.148652755655348e-05f, 0.00010056388418888673f, 7.270095375133678e-05f, 9.71544868662022e-05f, 6.654191383859143e-05f, 0.00012460228754207492f, 8.143319064402021e-06f, 7.822521001799032e-05f, 5.377650450100191e-05f, 6.428414781112224e-05f, 9.877813135972247e-05f, 0.00013246173330117017f, 6.422907608794048e-05f, 6.98358635418117e-05f, 6.42027662252076e-05f, 5.7335135352332145e-05f, 9.481961751589552e-05f, 0.00010088467388413846f, 0.00015105855709407479f, 5.101575516164303e-05f, 0.00012016944674542174f, 0.00010560945520410314f, 0.00017235265113413334f, 9.954467532224953e-05f, 8.568906923756003e-05f, 0.00015661539509892464f, 8.861194510245696e-05f, 0.0001227960892720148f, 5.529304689844139e-05f, 7.57353482185863e-05f, 6.312966434052214e-05f, 0.00010300717258360237f, 5.822734965477139e-05f, 9.888653585221618e-05f, 0.00021391233894973993f, 0.00011162840382894501f, 7.490908319596201e-05f, 6.463898898800835e-05f, 0.0001552941248519346f, 0.0001160751489805989f, 0.00010063716763397679f, 7.15876230970025e-05f, 8.189955406123772e-05f, 0.00011212865501875058f, 0.00013287375622894615f, 0.00010963493696181104f, 9.570943802827969e-05f, 5.141488873050548e-05f, 0.00010988650319632143f, 9.733833576319739e-05f, 9.06047280295752e-05f, 0.00016818285803310573f, 0.00011401455412851647f, 0.00012289888400118798f, 0.00014123876462690532f, 0.00013051457062829286f, 3.0821815016679466e-05f, 5.9941674408037215e-05f, 5.7225381169700995e-05f, 7.466549141099676e-05f, 9.904215403366834e-05f, 0.00019703834550455213f, 0.00011295302829239517f, 6.329458847176284e-05f, 6.845093594165519e-05f, 8.374880417250097e-05f, 6.31620641797781e-05f, 0.00018180302868131548f, 0.00015294317563530058f, 0.00011306373926345259f, 7.545364496763796e-05f, 8.087290188996121e-05f, 6.0232046962482855e-05f, 0.00012213185254950076f, 0.00011542829452082515f, 5.7907622249331325e-05f, 0.00011845910921692848f, 0.0001373989216517657f, 4.9820999265648425e-05f, 0.00013385058264248073f, 0.00010474799637449905f, 9.071448585018516e-05f, 9.178829350275919e-05f, 0.00013770551595371217f, 9.316351497545838e-05f, 5.42220332135912e-05f, 0.00014704157365486026f, 0.00011226618516957387f, 0.00013250148913357407f, 5.6756729463813826e-05f, 0.00019048360991291702f, 0.00012952848919667304f, 7.641902629984543e-05f, 9.444631723454222e-05f, 0.00011936912778764963f, 0.00013844000932294875f, 0.00010930230928352103f, 0.00010273989755660295f, 4.221796552883461e-05f, 7.589844608446583e-05f, 0.00016867025988176465f, 9.460360888624564e-05f, 8.724319195607677e-05f, 8.948476170189679e-05f, 4.410409746924415e-05f, 8.441501267952845e-05f, 7.396093133138493e-05f, 4.5415137719828635e-05f, 0.00012943739420734346f, 9.985741780837998e-05f, 7.05769780324772e-05f, 9.38537486945279e-05f, 0.00012837258691433817f, 9.643832891015336e-05f, 3.914420085493475e-05f, 0.00013437625602819026f, 0.00013031646085437387f, 7.02963734511286e-05f, 8.15507082734257e-05f, 4.7263671149266884e-05f, 0.0001127384603023529f, 0.00011571978393476456f, 0.00010951115837087855f, 9.468349890084937e-05f, 6.408800254575908e-05f, 0.00010715239477576688f, 8.468127634841949e-05f, 8.797795453574508e-05f, 0.00014284033386502415f, 8.867976430337876e-05f, 3.399062916287221e-05f, 8.610584336565807e-05f, 0.00012480700388550758f, 6.277545617194846e-05f, 7.14516281732358e-05f, 4.938106212648563e-05f, 9.895388211589307e-05f, 0.0001235361851286143f, 8.816914487397298e-05f, 0.0001227554166689515f, 0.00010857154848054051f, 5.724489165004343e-05f, 0.0001228672481374815f, 6.216567999217659e-05f, 0.00011773425649153069f, 7.071969594107941e-05f, 8.264619100373238e-05f, 0.00010131397721124813f, 5.891239197808318e-05f, 0.00020033051259815693f, 0.00012178253382444382f, 4.930535942548886e-05f, 7.787626964272931e-05f, 9.45395149756223e-05f, 0.00014998471306171268f, 9.60662291618064e-05f, 0.00029868155252188444f, 0.000134172776597552f, 0.00011035492934752256f, 7.276554242707789e-05f, 9.158850298263133e-05f, 0.0001247409963980317f, 0.00010465540981385857f, 5.8413224905962124e-05f, 0.0001405527291353792f, 5.780496940133162e-05f, 0.00014013564214110374f, 0.0001699658459983766f, 8.598367276135832e-05f, 0.00017573758668731898f, 9.066453640116379e-05f, 0.00011200393782928586f, 9.59528042585589e-05f, 9.723934635985643e-05f, 4.8419940867461264e-05f, 0.00012851934297941625f, 0.00012947566574439406f, 0.00012465084728319198f, 8.057076775003225e-05f, 0.00010189216845901683f, 4.967243512510322e-05f, 6.201699579833075e-05f, 7.329593790927902e-05f, 0.00011998326954199001f, 7.451687997672707e-05f, 5.716131636290811e-05f, 9.26927023101598e-05f, 8.854506450006738e-05f, 3.6506873584585264e-05f, 0.00015289048315025866f, 7.676103268750012e-05f, 8.546761819161475e-05f, 6.961498002056032e-05f, 6.910876982146874e-05f, 0.00011923514830414206f, 9.022829181049019e-05f, 9.657596820034087e-05f, 8.42539593577385e-05f, 4.36649497714825e-05f, 9.160117770079523e-05f, 0.0001279172720387578f, 8.362630615010858e-05f, 0.0001174209828604944f, 7.447793905157596e-05f, 0.00013471209967974573f, 4.1317438444821164e-05f, 0.00016278278781101108f, 7.798939623171464e-05f, 3.6938072298653424e-05f, 8.540855924366042e-05f, 6.827546167187393e-05f, 0.0002234728744952008f, 4.5886539737693965e-05f, 8.800466457614675e-05f, 0.00010919437772827223f),
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
    AI_PACK_INTQ_SCALE(0.00014128268230706453f, 0.00015699502546340227f, 0.00017708151426631957f, 0.0002773580781649798f, 0.0002543865703046322f, 0.000266697519691661f, 0.00019660843827296048f, 0.0001479741040384397f, 0.0003907238715328276f, 0.0001734104153001681f, 0.0003825685125775635f, 0.0004187104059383273f, 0.00016586603305768222f, 0.0002445974387228489f, 0.0004950957954861224f, 0.00016151096497196704f, 0.00020300954929552972f, 0.00023374514421448112f, 0.0002619963779579848f, 0.00027601781766861677f, 0.00027673618751578033f, 0.00026594827068038285f, 0.0002121537982020527f, 0.00016869115643203259f, 0.00036774398176930845f, 0.00022059192997403443f, 0.00020782467618118972f, 0.0005282656056806445f, 0.0002233311824966222f, 0.00032007772824727f, 0.00031206905259750783f, 0.0004662490973714739f, 0.0002077021636068821f, 0.00026600141427479684f, 0.00019308426999486983f, 0.0003483179316390306f, 0.0001284171303268522f, 0.0005458394298329949f, 0.0001390907127643004f, 0.0004071270232088864f, 0.0002016609942074865f, 0.0004206515150144696f, 0.00011143456504214555f, 0.00019929582776967436f, 0.0003024589968845248f, 0.00042865987052209675f, 0.00015131616964936256f, 0.00019667860760819167f, 0.00024896152899600565f, 0.00018377382366452366f, 0.00029822366195730865f, 0.0003154351725243032f, 0.00033848738530650735f, 0.0002995608956553042f, 0.00024843140272423625f, 0.00023495768255088478f),
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
    AI_PACK_INTQ_SCALE(0.00012249541759956628f, 0.00012925572809763253f, 0.00012570172839332372f, 7.139072840800509e-05f, 0.0001900861389003694f, 0.0003124538925476372f, 0.00022501529019791633f, 7.588166772620752e-05f, 0.00014313652354758233f, 0.00012011721992166713f, 0.0001455154560972005f, 0.00010245044541079551f, 0.00013363973994273692f, 0.00013868915266357362f, 0.00010516813199501485f, 0.00013477387255989015f, 0.00013484347437042743f, 0.0001027450489345938f, 0.00012744148261845112f, 0.000137923241709359f, 0.00012529181549325585f, 0.00014460526290349662f, 0.000121300108730793f, 8.357869228348136e-05f, 0.00015240309585351497f, 0.00019660918042063713f, 7.7278476965148e-05f, 0.00013615201169159263f, 8.491561311529949e-05f, 0.00012644290109165013f, 0.00016461221093777567f, 0.00014103564899414778f, 0.00015477569832000881f, 0.0001775896962499246f, 0.00011125282617285848f, 0.00013024774671066552f, 0.00012256397167220712f, 0.0002004457201110199f, 0.00011687953519867733f, 0.00010151383321499452f, 0.0001140784879680723f, 0.00011868051660712808f, 0.0001471454306738451f, 0.00014413442113436759f, 0.00013677992683369666f, 0.00010258788097416982f, 0.00015490490477532148f, 0.00016638739907648414f, 0.00014543616271112114f, 0.00012429965136107057f, 4.9477912398288026e-05f, 0.00015277850616257638f, 0.00011543962318683043f, 0.00017046011635102332f, 8.553986117476597e-05f, 0.00016118414350785315f, 0.0001374860294163227f, 0.00013145773846190423f, 0.00012991779658477753f, 9.370032785227522e-05f, 0.0001154618730652146f, 0.00011367652041371912f, 9.595420124242082e-05f, 9.436582331545651e-05f, 0.000167039135703817f, 0.00012324893032200634f, 0.00014052106416784227f, 5.994857201585546e-05f, 0.00014899091911502182f, 0.000202897033886984f, 0.00014920822286512703f, 0.0001028279002639465f, 0.0001039279013639316f, 9.022540325531736e-05f, 0.00016665032308083028f, 0.00015985917707439512f, 0.00011967471800744534f, 0.00011258610902586952f, 9.998974564950913e-05f, 0.00016602101095486432f, 0.00016331407823599875f, 0.0001842263591242954f, 0.0002758557675406337f, 0.0001888669648906216f, 0.00010176948126172647f, 9.244569082511589e-05f, 0.00011950328917009756f, 0.00011449207522673532f, 9.086783393286169e-05f, 0.00014856865163892508f, 0.00013231886259745806f, 0.00014061277033761144f, 0.00010158608347410336f, 0.00013053817383479327f, 0.00014565417950507253f, 0.00012403026630636305f, 0.00013117444177623838f, 0.0001636064116610214f, 0.00012582218914758414f, 9.409031190443784e-05f, 0.00010758022835943848f, 0.0001216760283568874f, 0.00018694675236474723f, 0.0001569961168570444f, 0.00013577548088505864f, 0.00016901834169402719f, 0.00011377534247003496f, 0.00017803766240831465f, 0.00013640336692333221f, 0.00015283943503163755f, 7.316504343179986e-05f, 0.00014117259706836194f, 0.00010221608681604266f, 0.00012813150533474982f, 0.00010009126708609983f, 0.00014638940047007054f, 0.00013449310790747404f, 0.00017115860828198493f, 0.00016085624520201236f, 0.00014351692516356707f, 0.00013120465155225247f, 0.00011968163016717881f, 0.00011625488696154207f, 0.00012858591799158603f, 0.00020326282538007945f, 0.00015577416343148798f, 0.00019523636728990823f, 0.00015835023077670485f, 0.00013619029778055847f, 9.631220018491149e-05f, 0.0001540631928946823f, 9.314016642747447e-05f, 0.00013607610890176147f, 9.868971392279491e-05f, 6.289025623118505e-05f, 0.0001417578023392707f, 0.00012002336006844416f, 0.00011939969408558682f, 0.00018297637871000916f, 0.00011006495333276689f, 9.356826194562018e-05f, 0.00011864371481351554f, 0.00022070207342039794f, 0.00013713225780520588f, 0.00014084979193285108f, 0.0001589817547937855f, 0.00014326206292025745f, 0.00010533620661590248f, 0.00015323134721256793f, 0.00018496443226467818f, 8.927647286327556e-05f, 0.00013383616169448942f, 0.00017797350301407278f, 0.00011246499343542382f, 0.00013186757860239595f, 0.00010635130456648767f, 9.93959401967004e-05f, 0.0001424077054252848f, 0.00016327129560522735f, 0.00011885019193869084f, 9.3014859885443e-05f, 0.00016388767107855529f, 0.0001871342828962952f, 9.604926162865013e-05f, 0.00012281049566809088f, 9.148526442004368e-05f, 0.0002222080947831273f, 0.00015375649672932923f, 0.00013303164450917393f, 0.0001745818299241364f, 0.00011305227235425264f, 0.00016886959201656282f, 0.000170549625181593f, 0.00015029581845737994f, 0.00010730261419666931f, 0.00014553261280525476f, 0.0001304508332395926f, 0.00011490275210235268f, 0.00012828712351620197f, 0.0001318757131230086f, 0.00011408635327825323f, 0.00023734313435852528f, 0.00014083352289162576f, 0.00020354131993371993f, 0.00012874607637058944f, 0.00030663725920021534f, 0.00011281698971288279f, 0.0001061325310729444f, 0.00010873349674511701f, 0.00013549055438488722f, 9.513540135230869e-05f, 0.00010979672515532002f, 0.00012860441347584128f, 9.148839308181778e-05f, 0.0001622785348445177f, 0.00012400266132317483f, 0.00043643967364914715f, 0.00011336689203744754f, 0.00011480610555736348f, 0.00011502139386720955f, 0.0001487374829594046f, 0.00018991991237271577f, 0.00015535205602645874f, 0.0001281185686821118f, 0.00011903326230822131f, 0.00022799632279202342f, 0.00015149895625654608f, 0.00010965693945763633f, 0.00010656501399353147f, 8.826127304928377e-05f, 0.00013414899876806885f, 9.580550977261737e-05f, 8.794729365035892e-05f, 0.00012072844401700422f, 0.00010220507101621479f, 0.00010632436897139996f, 0.0001534146722406149f, 0.00011879696103278548f, 6.762349221389741e-05f, 0.0002454805944580585f, 0.00012510984379332513f, 0.0001573511108290404f, 0.00011812170851044357f, 0.00012092448014300317f, 0.00014241023745853454f, 0.0001443523942725733f, 0.00011892359179910272f, 0.00017096598458010703f, 0.0001965179544640705f, 0.0001876441965578124f, 0.00027159982710145414f, 0.00017789803678169847f, 0.00013878417667001486f, 0.00012391989002935588f, 0.00015787356824148446f, 9.493964171269909e-05f, 0.00014814839232712984f, 0.00016080400382634252f, 0.00015136849833652377f, 0.00010676962119759992f, 0.00012248924758750945f, 0.00014115675003267825f, 0.00013863900676369667f, 0.00010659600229701027f, 0.00010560032387729734f, 0.00017940675024874508f, 0.00018754368647933006f, 0.0001368775119772181f, 0.00014588789781555533f, 0.0001939376670634374f, 0.00013706165191251785f, 0.00016596393834333867f, 0.0001366621581837535f, 0.00017368757107760757f, 0.00010232272325083613f, 0.00012450446956790984f, 0.00010978810314554721f, 0.00012830081686843187f, 0.00013308352208696306f, 0.0001291256194235757f, 0.00013602434773929417f, 0.00012140419858042151f, 0.00013021098857279867f, 9.784321446204558e-05f, 9.955810674000531e-05f, 0.00015242719382513314f, 0.0001285672769881785f, 0.00013108692655805498f, 8.303466893266886e-05f, 0.00018852016364689916f, 0.00015732823521830142f, 0.00015738372167106718f, 0.00011631865345407277f, 0.00017334704170934856f, 0.00011333445581840351f, 0.00011115401866845787f, 0.00013374816626310349f, 0.00017195464170072228f, 0.00012112529657315463f, 0.0001609265455044806f, 0.00010535038018133491f, 0.00010734896932262927f, 0.0001833258429542184f, 0.00020454212790355086f, 0.00015798919775988907f, 0.00015819013060536236f, 0.00013788176875095814f, 0.00010940284846583381f, 0.00018442874716129154f, 0.0001029773848131299f, 0.00021438684780150652f, 0.0001274040259886533f, 0.00011219085718039423f, 8.979563426692039e-05f, 0.00015786083531565964f, 0.0001231592323165387f, 0.00010929707786999643f, 0.00013675021182280034f, 0.0001386151125188917f, 0.00011044584971386939f, 0.00018972449470311403f, 0.00010997406207025051f, 0.0002471822372172028f, 0.00020963292627129704f, 0.00015219900524243712f, 9.401188435731456e-05f, 0.00016487266111653298f, 0.00012525811325758696f, 0.0001040030547301285f, 0.0001543347752885893f, 0.00015616412565577775f, 0.00012060594599461183f, 0.00013037699682172388f, 0.0001459652412449941f, 0.00012076642451575026f, 0.00011507340241223574f, 0.00011883914703503251f, 0.00012029147183056921f, 0.00011139184061903507f, 0.00012484438775572926f, 0.00017812478472478688f, 9.958918235497549e-05f, 0.00011919085227418691f, 0.0001709611969999969f, 0.00026704755146056414f, 0.0001280317228520289f, 9.191196295432746e-05f, 0.00014531360648106784f, 0.00018299405928701162f, 0.00012933931429870427f, 0.00010607951844576746f, 0.00011186253686901182f, 7.321875455090776e-05f, 0.00012195885938126594f, 9.657701593823731e-05f, 0.00014652333629783243f),
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
    AI_PACK_INTQ_SCALE(0.000357544282451272f, 0.0004061027429997921f, 0.0005932993371970952f, 0.0003974488645326346f, 0.0004708171763923019f, 0.0005340888747014105f, 0.0004211039049550891f, 0.000414572685258463f, 0.0004975052434019744f, 0.00043110636761412024f, 0.0005182361928746104f, 0.00046455077244900167f, 0.0004118861397728324f, 0.00043850200017914176f, 0.0005903024575673044f, 0.0006065898924134672f, 0.00047530303709208965f, 0.00037446204805746675f, 0.00039507978362962604f, 0.0004701946454588324f, 0.00044165836879983544f, 0.0004623769491445273f, 0.0004404307692311704f, 0.0005197194404900074f, 0.0004711397923529148f, 0.00044685552711598575f, 0.00046318379463627934f, 0.0003989804827142507f, 0.0005095531814731658f, 0.0003901443851646036f, 0.00039376976201310754f, 0.0003903962206095457f, 0.0005245397333055735f, 0.000386125931981951f, 0.00043573614675551653f, 0.0004914727178402245f, 0.0003805316227953881f, 0.0004013929865323007f, 0.0005127564654685557f, 0.00032807033858262f, 0.0004264368035364896f, 0.0004057150799781084f, 0.00040035528945736587f, 0.0005532257491722703f, 0.00045309701818041503f, 0.00044012354919686913f, 0.0004035203019157052f, 0.00040296054794453084f, 0.0005860922974534333f, 0.0004326050984673202f, 0.0005286055384203792f, 0.0005788151174783707f, 0.00041240532300435007f, 0.00044069677824154496f, 0.0004977583885192871f, 0.0005424913251772523f, 0.0007167733856476843f, 0.0005430468590930104f, 0.0005983604933135211f, 0.00047544631524942815f, 0.0006154704606160522f, 0.0004646953020710498f, 0.00037636826164089143f, 0.00039718853076919913f, 0.00044319519656710327f, 0.000648314191494137f, 0.0004962245002388954f, 0.00040922872722148895f, 0.00041732966201379895f, 0.0003915976849384606f, 0.0006334900390356779f, 0.0004008211544714868f, 0.0005742767243646085f, 0.0004569000448100269f, 0.00044181925477460027f, 0.0004892087890766561f, 0.00041990765021182597f, 0.0004545055271591991f, 0.00043184831156395376f, 0.00038881946238689125f, 0.0005025980062782764f, 0.0005359003553166986f, 0.0003440516593400389f, 0.00043678790098056197f, 0.0004893091390840709f, 0.0005025393329560757f, 0.0005587344639934599f, 0.0004359116719570011f, 0.0005477683153003454f, 0.0004135606868658215f, 0.00041892394074238837f, 0.0005518769612535834f, 0.00047443993389606476f, 0.0004152652691118419f, 0.0005089851911179721f, 0.00051746895769611f, 0.000367585540516302f, 0.0003546364314388484f, 0.00048441323451697826f, 0.00040333851939067245f, 0.0005210475064814091f, 0.00044747599167749286f, 0.0004189726896584034f, 0.00037546650855802f, 0.0005485492874868214f, 0.0003829154302366078f, 0.00048839021474123f, 0.0006090180249884725f, 0.0005908085149712861f, 0.0004224048461765051f, 0.0004555994819384068f, 0.0004137032083235681f, 0.00046979347825981677f, 0.0004312499950174242f, 0.000513221777509898f, 0.0005238456651568413f, 0.0004403148195706308f, 0.0004037667822558433f, 0.000445555750047788f, 0.0003787764871958643f, 0.00033749573049135506f, 0.00046348117757588625f, 0.0006083196494728327f, 0.0005210264935158193f, 0.0005182318273000419f, 0.00038730030064471066f, 0.0005280716577544808f, 0.0005337743787094951f, 0.00038924627006053925f, 0.00047160687972791493f, 0.0004196900699753314f, 0.00035279669100418687f, 0.0004279372515156865f, 0.00046838721027597785f, 0.0004751646483782679f, 0.00039866866427473724f, 0.0005076286615803838f, 0.00042982303421013057f, 0.0004946263507008553f, 0.0006219390197657049f, 0.0003319147217553109f, 0.0005337080801837146f, 0.0004116685886401683f, 0.00042491263593547046f, 0.000392081739846617f, 0.00040204680408351123f, 0.0003608838887885213f, 0.0005221831961534917f, 0.0004111189628019929f, 0.0005441298708319664f, 0.0006330347387120128f, 0.0005178371211513877f, 0.00044046310358680785f, 0.0004243891453370452f, 0.0004600990505423397f, 0.0005199626320973039f, 0.000463398959254846f, 0.0004092218296136707f, 0.0003736318903975189f, 0.0007386787910945714f, 0.00040340767009183764f, 0.0005142295267432928f, 0.0004446875536814332f, 0.0004042835789732635f, 0.0003856727562379092f, 0.00045707629760727286f, 0.000483495881780982f, 0.0003260006196796894f, 0.0004368314112070948f, 0.00040070872637443244f, 0.000504002149682492f, 0.0004036564496345818f, 0.00047505038673989475f, 0.00040697245276533067f, 0.0005163769237697124f, 0.0004007141978945583f, 0.0004958988283760846f, 0.00044552990584634244f, 0.0005343736847862601f, 0.0004914067103527486f, 0.0005052904598414898f, 0.0004585722927004099f, 0.000524256844073534f, 0.0003970191173721105f, 0.0004992903559468687f, 0.000477815221529454f, 0.0005193909164518118f, 0.00038545168354175985f, 0.0004437871393747628f, 0.00037464944762177765f, 0.0005534205120056868f, 0.0004932174342684448f, 0.0003651112783700228f, 0.0004319361469242722f, 0.0004838643071707338f, 0.0004915978643111885f, 0.0004132197063881904f, 0.0004848805256187916f, 0.0004197250818833709f, 0.0005535067175514996f, 0.0004332893877290189f, 0.00041418112232349813f, 0.0003797850804403424f, 0.0003571350243873894f, 0.0005762731307186186f, 0.0005065404111519456f, 0.00047296134289354086f, 0.0004268323536962271f, 0.0004164038400631398f, 0.0004618550301529467f, 0.00039948668563738465f, 0.0004721420700661838f, 0.00042179590673185885f, 0.0005586682818830013f, 0.00047578546218574047f, 0.0004606023139785975f, 0.0003919163136743009f, 0.0004864295187871903f, 0.0003990209079347551f, 0.000562212779186666f, 0.0004398660094011575f, 0.0003840545832645148f, 0.00036648890818469226f, 0.0004334287950769067f, 0.0005171903176233172f, 0.00047473664744757116f, 0.0005145759205333889f, 0.0006112043629400432f, 0.00044103944674134254f, 0.000761358009185642f, 0.00043488305527716875f, 0.000415825197705999f, 0.0004813616396859288f, 0.00045316334581002593f, 0.0004194671055302024f, 0.000507805438246578f, 0.0005490606999956071f, 0.0005782008520327508f, 0.000666503852698952f, 0.00046322960406541824f, 0.0005063311546109617f, 0.0005063663702458143f, 0.0005368991987779737f, 0.0007645643781870604f, 0.00038666208274662495f, 0.0003721162211149931f, 0.0004653087235055864f, 0.00038991100154817104f, 0.0004529867728706449f, 0.0005107963806949556f, 0.000554602243937552f, 0.0005397639470174909f, 0.0004722517332993448f, 0.00046822230797261f, 0.0005533663788810372f, 0.00044015064486302435f, 0.0005050416220910847f, 0.00043648682185448706f, 0.00039549259236082435f, 0.0005155778490006924f, 0.0005116481916047633f, 0.00042311454308219254f, 0.0004278389969840646f, 0.00040463925688527524f, 0.0004829611862078309f, 0.0004614936769939959f, 0.0005615766276605427f, 0.00045190955279394984f, 0.000547732983250171f, 0.0004964358522556722f, 0.0004270759236533195f, 0.0004859543696511537f, 0.00040438506403006613f, 0.0004939111531712115f, 0.0004623639688361436f, 0.0004142009711358696f, 0.0007670562481507659f, 0.00046798723633401096f, 0.00038343764026649296f, 0.0007328347419388592f, 0.0005722771165892482f, 0.0004252568178344518f, 0.00038547749863937497f, 0.00046334019862115383f, 0.00048032760969363153f, 0.000589598435908556f, 0.0004693324735853821f, 0.00044254589010961354f, 0.00041394244180992246f, 0.00043821430881507695f, 0.00062576774507761f, 0.0005291781271807849f, 0.00038328050868585706f, 0.00039041117997840047f, 0.00045993211097083986f, 0.0004654962394852191f, 0.0005350240971893072f, 0.0006832766230218112f, 0.00048368729767389596f, 0.0004211511113680899f, 0.000473108229925856f, 0.00045414947089739144f, 0.00038924955879338086f, 0.00041633693035691977f, 0.0003688589495141059f, 0.000506564334500581f, 0.00038258847780525684f, 0.00036603835178539157f, 0.0003979295142926276f, 0.0005518253310583532f, 0.0005809349822811782f, 0.0004481439245864749f, 0.0004737628623843193f, 0.0005580182187259197f, 0.00042925745947286487f, 0.0005192453390918672f, 0.00047813126002438366f, 0.0005334409652277827f, 0.0004729387001134455f, 0.00045520905405282974f, 0.0005604015896096826f, 0.0005288586835376918f, 0.000493529427330941f, 0.0004181557160336524f, 0.00040388948400504887f, 0.00043893681140616536f, 0.00041809375397861004f, 0.00039507518522441387f, 0.00037831481313332915f, 0.0004019878397230059f, 0.00036989449290558696f, 0.0003831989015452564f, 0.0006135387229733169f, 0.0004196079389657825f, 0.0004947447450831532f, 0.00043153230217285454f, 0.0005724648362956941f, 0.0005445891292765737f, 0.00042838361696340144f, 0.000459900067653507f, 0.0004906943649984896f, 0.0003735152422450483f, 0.00041559524834156036f, 0.00038248937926255167f, 0.00043929851381108165f, 0.00044689024798572063f, 0.0004213437205180526f, 0.000435360154369846f, 0.00047442418872378767f, 0.0003954868298023939f, 0.000575740821659565f, 0.0005623294273391366f, 0.0006498331786133349f, 0.0004960710066370666f, 0.0006670384318567812f, 0.00042204768396914005f, 0.00039576314156875014f, 0.0003781933046411723f, 0.0005797690246254206f, 0.0003975546860601753f, 0.00043114490108564496f, 0.0005166650516912341f, 0.00044926468399353325f, 0.00038645262247882783f, 0.00045001041144132614f, 0.0005069923354312778f, 0.0003991167468484491f, 0.00039780643419362605f, 0.0005794307799078524f, 0.0004025764355901629f, 0.0005253743147477508f, 0.00039199512684717774f, 0.00042183970799669623f, 0.000497051514685154f, 0.00046930473763495684f, 0.000605389301199466f, 0.0004740373115055263f, 0.000592274300288409f, 0.00034729999606497586f, 0.0003881290613207966f, 0.000500314577948302f, 0.0003799504484049976f, 0.0003962984774261713f, 0.0005125912721268833f, 0.000404733611503616f, 0.00048797717317938805f, 0.00046566015225835145f, 0.0005320446216501296f, 0.0005793988821096718f, 0.00041445106035098433f, 0.00040344102308154106f, 0.0004999589291401207f, 0.0003829087072517723f, 0.0005249039968475699f, 0.0005455998471006751f, 0.0004633992211893201f, 0.0004637619131244719f, 0.00042248074896633625f, 0.0005060317926108837f, 0.00045214075362309813f, 0.000400895019993186f, 0.0004116678610444069f, 0.0005028143641538918f, 0.0004152629117015749f, 0.0004373809788376093f, 0.0004689715278800577f, 0.0005254466668702662f, 0.00047908161650411785f, 0.0007828263915143907f, 0.0005288441898301244f, 0.0004851809935644269f, 0.000529149197973311f, 0.00040220256778411567f, 0.000463652890175581f, 0.0004240833513904363f, 0.0005713828140869737f, 0.0005137960542924702f, 0.0004868739633820951f, 0.0005661121103912592f, 0.0004165013087913394f, 0.0005034667556174099f, 0.000578890205360949f, 0.000507646647747606f, 0.0004143168916925788f, 0.00038952918839640915f, 0.0004738598072435707f, 0.00040124409133568406f, 0.00047243537846952677f, 0.00047699143760837615f, 0.00043241368257440627f, 0.0004227287427056581f, 0.0005150479264557362f, 0.00044832919957116246f, 0.0005077947862446308f, 0.00044684609747491777f, 0.00043005854240618646f, 0.00043876265408471227f, 0.0004982579266652465f, 0.00045308892731554806f, 0.00044387136586010456f, 0.00047710633953101933f, 0.00040745228761807084f, 0.0005908235907554626f, 0.0003889137296937406f, 0.0004936511977575719f, 0.00040581851499155164f, 0.0004357915895525366f, 0.0004692093934863806f, 0.0006410995265468955f, 0.0005571524379774928f, 0.0003779964754357934f, 0.0005211548414081335f, 0.0006121275946497917f, 0.0004343337204772979f, 0.00045598504948429763f, 0.00048193117254413664f, 0.00045698421308770776f, 0.00037533024442382157f, 0.00041171591146849096f, 0.00035026323166675866f, 0.0007988057332113385f, 0.0005977297550998628f, 0.00035992421908304095f, 0.0003910722443833947f, 0.0005092996289022267f, 0.00042375066550448537f, 0.00041777087608352304f, 0.0005029069725424051f, 0.0005996149266138673f, 0.00040218577487394214f, 0.00043966012890450656f, 0.0005058402894064784f, 0.00038452830631285906f, 0.0004073050513397902f, 0.0004205520381219685f, 0.0005670323735103011f, 0.00039223680505529046f, 0.0005297581083141267f, 0.0005043843993917108f, 0.0004898728802800179f, 0.0005504305008798838f, 0.00045317140757106245f, 0.0003152621502522379f, 0.0005194565164856613f, 0.0006280525121837854f, 0.0004082046798430383f, 0.0005561764119192958f, 0.0005188023787923157f, 0.0003673227329272777f, 0.00041449072887189686f, 0.0004069973074365407f, 0.000515664229169488f, 0.00042036621016450226f, 0.0004263271111994982f, 0.0005196098936721683f, 0.0004278815467841923f, 0.0005214742268435657f, 0.0005800302023999393f, 0.00043165398528799415f, 0.0004825636278837919f, 0.0004089944122824818f, 0.0006135365692898631f, 0.00041698076529428363f, 0.00044987615547142923f, 0.00042890271288342774f, 0.0005188774084672332f, 0.000568876916076988f, 0.0004502989468164742f, 0.0004239590198267251f, 0.0003403175505809486f, 0.0003968639357481152f, 0.0004179868847131729f, 0.00038965261774137616f, 0.000554262544028461f, 0.0004028395051136613f, 0.0005255293799564242f, 0.0004907840047962964f, 0.0005413217004388571f, 0.0005303260404616594f, 0.00042322033550590277f, 0.00040614805766381323f, 0.0004965628031641245f, 0.0006457563140429556f, 0.0004999233060516417f, 0.0004644946602638811f, 0.0004101177037227899f, 0.000564774323720485f, 0.0005858674412593246f, 0.0005630751838907599f, 0.0003952163096982986f, 0.0007683642324991524f, 0.00042674713768064976f, 0.000438552611740306f, 0.00036239175824448466f, 0.0005014243070036173f, 0.0005412017344497144f, 0.0004358522710390389f, 0.0004089066933374852f, 0.0004596737853717059f, 0.00038654558011330664f, 0.0004561801324598491f, 0.0006401063874363899f, 0.0005768887931481004f, 0.00037779987906105816f, 0.0003875038819387555f, 0.000475189444841817f, 0.0005157458363100886f, 0.00045522983418777585f, 0.00035502552054822445f, 0.00048414242337457836f, 0.0006204962264746428f, 0.0007644225843250751f, 0.00045783008681610227f, 0.0004164385318290442f, 0.0004637457604985684f, 0.0003955084830522537f, 0.0004731499357149005f, 0.0004683515871874988f, 0.0005948957987129688f, 0.0004436780291143805f, 0.0005070074112154543f, 0.00047661474673077464f, 0.0004855527658946812f, 0.0004312965029384941f, 0.0004929812857881188f, 0.0004430419357959181f, 0.00046659441431984305f, 0.0005751472781412303f, 0.00041911855805665255f, 0.0003742199041880667f, 0.0005491274641826749f, 0.0005816035554744303f, 0.0006021996960043907f, 0.00041664906893856823f, 0.0004923573578707874f, 0.00042861999827437103f, 0.00040488317608833313f, 0.00040132534923031926f, 0.00041859468910843134f, 0.00035759128513745964f, 0.0004540823574643582f, 0.0004991544992662966f, 0.00044173840433359146f, 0.0005765573587268591f, 0.0007085903198458254f, 0.000561285822186619f, 0.0003890711232088506f, 0.0004928081762045622f, 0.0006164220976643264f, 0.000457021378679201f, 0.0004507153353188187f, 0.0005050155450589955f, 0.0004880014166701585f, 0.0005369872669689357f, 0.0005407872376963496f, 0.0004534627078101039f, 0.00042290586861781776f, 0.0003817726392298937f, 0.00034366684849373996f, 0.00038038045749999583f, 0.00044663684093393385f, 0.00041303783655166626f, 0.0006143709761090577f, 0.00043366270256228745f, 0.0005085194716230035f, 0.0004797853762283921f, 0.00043268591980449855f, 0.0005518070538528264f, 0.0004740782896988094f, 0.0003948248631786555f, 0.0006109591922722757f, 0.0005191661766730249f, 0.00038715486880391836f, 0.00045401204260997474f, 0.0004170943284407258f, 0.0004834523133467883f, 0.000561696826480329f, 0.0005294501897878945f, 0.000500140362419188f, 0.0004541969101410359f, 0.0005050882464274764f, 0.0005300483317114413f, 0.0004922262160107493f, 0.00039417334483005106f, 0.0007066303514875472f, 0.000488253659568727f, 0.00047045311657711864f, 0.0003508318623062223f, 0.0005455594509840012f, 0.00043243818799965084f, 0.0005007362924516201f, 0.00045230367686599493f, 0.0004602189001161605f, 0.00044949608854949474f, 0.0005145295872353017f, 0.0004653816868085414f, 0.0005272013950161636f, 0.0003767137532122433f, 0.00048076268285512924f, 0.00042117154225707054f, 0.0007056355243548751f, 0.0004820804169867188f, 0.0004712538211606443f, 0.0003968497912865132f, 0.0005227934452705085f, 0.0005475099314935505f, 0.0004614593053702265f, 0.0003890783409588039f, 0.00035486932029016316f, 0.0005336212343536317f, 0.0004061527724843472f, 0.00042377886711619794f, 0.0006621726206503808f, 0.00035705071059055626f, 0.0004736055852845311f, 0.0006787668680772185f, 0.0003721166867762804f, 0.00044836499728262424f, 0.00040092694689519703f, 0.0004337583377491683f, 0.0004464530211407691f, 0.0003925970522686839f, 0.0005180782172828913f, 0.0004843661736231297f, 0.000461152580101043f, 0.00040936082950793207f, 0.00048716989113017917f, 0.0004046479589305818f, 0.0003820497659035027f, 0.0005354636814445257f, 0.0005208209622651339f, 0.00047916872426867485f, 0.00043025671038776636f, 0.00044943587272427976f, 0.0004542671958915889f, 0.0004501965013332665f, 0.0004127649590373039f, 0.0005043161800131202f, 0.00043392030056566f, 0.00046604531235061586f, 0.0004515895852819085f, 0.000665022584144026f, 0.00036784549592994153f, 0.0005504038417711854f, 0.0005518412799574435f, 0.0004276593099348247f, 0.00036207729135639966f, 0.00039570993976667523f, 0.0005584692698903382f, 0.0004092910385224968f, 0.00046309534809552133f, 0.00033569359220564365f, 0.0005119035486131907f, 0.00041172580677084625f, 0.0004076251934748143f, 0.0005196438287384808f, 0.0004838957102037966f, 0.00048085820162668824f, 0.0004910523421131074f, 0.0005106117459945381f, 0.00042555134859867394f, 0.0003957184962928295f, 0.00040409420034848154f, 0.00038564158603549004f, 0.0004596725048031658f, 0.0005188664072193205f, 0.0005714875878766179f, 0.0004675404925365001f, 0.000653102237265557f, 0.00043837600969709456f, 0.00039261087658815086f, 0.00043423083843663335f, 0.0004816606524400413f, 0.00044093787437304854f, 0.0004019312036689371f, 0.0004872763529419899f, 0.00037384958704933524f, 0.0005213195108808577f, 0.0005832166061736643f, 0.0004066723049618304f, 0.000432090979302302f, 0.0005293625872582197f, 0.0005881888791918755f, 0.0007079757051542401f, 0.0004905213718302548f, 0.00042726899846456945f, 0.00036975741386413574f, 0.0004249296907801181f, 0.00042003553244285285f, 0.0005008580046705902f, 0.00044677744153887033f, 0.0005167631898075342f, 0.000550808385014534f, 0.0005048646708019078f, 0.0005477592931129038f, 0.0004366823995951563f, 0.00044174081995151937f, 0.0005126336473040283f, 0.0004985917476005852f, 0.0004322492459323257f, 0.0003792888601310551f, 0.00040496463770978153f, 0.00044493426685221493f, 0.0007329992367886007f, 0.00043215102050453424f, 0.0004436825111042708f, 0.00046719374950043857f, 0.0004732740926556289f, 0.0004506766563281417f, 0.00038052938180044293f, 0.0005051111220382154f, 0.0005703279166482389f, 0.000506535463500768f, 0.00040743110002949834f, 0.00045672591659240425f, 0.0004471786960493773f, 0.0005409927107393742f, 0.0004762127937283367f, 0.0004649357288144529f, 0.00047227551112882793f, 0.0004232623614370823f, 0.0005160968285053968f, 0.00040820142021402717f, 0.0005451242323033512f, 0.0004356174904387444f, 0.000425736972829327f, 0.0003557773306965828f, 0.0005407643620856106f, 0.0004705519531853497f, 0.0005308509571477771f, 0.00044546733261086047f, 0.0004775785782840103f, 0.00049802620196715f, 0.0004096382763236761f, 0.0004849650722462684f, 0.0005292358109727502f, 0.00041919390787370503f, 0.00047411213745363057f, 0.0004742262826766819f, 0.0007010374683886766f, 0.0005246431101113558f, 0.0004998602671548724f, 0.00042211631080135703f, 0.0005873213522136211f, 0.0004340761515777558f, 0.00045207570656202734f, 0.0005180867738090456f, 0.000366983498679474f, 0.0004369564412627369f, 0.0004866145027335733f, 0.0005508098402060568f, 0.0005910057807341218f, 0.0004002612258773297f, 0.00036425775033421814f, 0.0004515526525210589f, 0.00046387259499169886f, 0.00045026038424111903f, 0.0004594274505507201f, 0.0004479242779780179f, 0.00035117805236950517f, 0.00043494164128787816f, 0.0005077079404145479f, 0.00040924010681919754f, 0.00040477089351043105f, 0.00040135454037226737f, 0.0004113687900826335f, 0.0003668041026685387f, 0.0004235420492477715f, 0.0004482284712139517f, 0.00035728575312532485f, 0.0005147320334799588f, 0.00037886176141910255f, 0.0005072896019555628f, 0.0005685110809281468f, 0.000466548721306026f, 0.0004986940184608102f, 0.00047075297334231436f, 0.00037647323915734887f, 0.0003900009032804519f, 0.00042449336615391076f, 0.0004119764780625701f, 0.00043256854405626655f, 0.00044689158676192164f, 0.00041575892828404903f, 0.0005661784089170396f, 0.00045587989734485745f, 0.0004387681547086686f, 0.0003536878211889416f, 0.0004950174479745328f, 0.0005290645058266819f, 0.00039286704850383103f, 0.0005311029963195324f, 0.00042279166518710554f, 0.00036038877442479134f, 0.0005124314920976758f, 0.0004381070320960134f, 0.000510374316945672f, 0.00037849071668460965f, 0.00040413340320810676f, 0.0005221075844019651f, 0.0004397973825689405f, 0.0004896030877716839f, 0.0005058659007772803f, 0.00045121475704945624f, 0.0004261020803824067f, 0.0004645134322345257f, 0.0005448320880532265f, 0.00043231493327766657f, 0.0005420492962002754f, 0.00037097581662237644f, 0.000496534223202616f, 0.00039227440720424056f, 0.0003573249850887805f, 0.00037677353248000145f, 0.00037370785139501095f, 0.00041884122765623033f, 0.00044230074854567647f, 0.0005016915965825319f, 0.0003963749622926116f, 0.0004972727037966251f, 0.00043785289744846523f, 0.000428441766416654f, 0.0003993128484580666f, 0.00035873946035280824f, 0.0005100869457237422f, 0.00041958014480769634f, 0.00043655463377945125f, 0.0003723066474776715f, 0.00043412018567323685f, 0.0005205741617828608f, 0.00040824522147886455f, 0.0004808594239875674f, 0.0005720354383811355f, 0.00047658709809184074f, 0.0005342375952750444f, 0.0004990732413716614f, 0.0003198375052306801f, 0.00036090437788516283f, 0.00043498020386323333f, 0.0004997953656129539f, 0.0003894123947247863f, 0.0004047377733513713f, 0.0005114719388075173f, 0.00041883683297783136f, 0.00039368000579997897f, 0.0005336260073818266f, 0.0005439893575385213f, 0.0004473738663364202f, 0.0005889557651244104f, 0.0005467156879603863f, 0.0005044998833909631f, 0.0004429202526807785f, 0.0004111630260013044f, 0.0003849655913654715f, 0.000437835231423378f, 0.0005942870047874749f, 0.0003633284359239042f, 0.0005148382624611259f, 0.0005431716563180089f, 0.0005017606890760362f, 0.000348301517078653f, 0.00035896117333322763f, 0.0004935052711516619f, 0.00043814710807055235f, 0.000517509295605123f, 0.00039794942131266f, 0.0004691437934525311f, 0.0004010417906101793f, 0.0005486115114763379f, 0.00037603400414809585f, 0.0003941621398553252f, 0.0005161762819625437f, 0.0003964187344536185f, 0.00048747335677035153f, 0.0004414804861880839f, 0.0003939568705391139f, 0.00046835228567942977f, 0.0005294360453262925f, 0.000756329158321023f, 0.00040354792145080864f, 0.0004275111423339695f, 0.0004485257377382368f, 0.00045263973879627883f, 0.000528143544215709f, 0.00045403005788102746f, 0.00043061375617980957f, 0.0005265411455184221f, 0.00048468454042449594f, 0.00039456321974284947f, 0.0005995953106321394f, 0.0004446273669600487f, 0.0004470301792025566f, 0.0006072089308872819f, 0.000495207670610398f, 0.00042206462239846587f, 0.0005580699071288109f, 0.0005311001441441476f, 0.00042839927482418716f, 0.0005696649313904345f, 0.0004193114582449198f, 0.0003470951924100518f, 0.00043736182851716876f, 0.0004317879502195865f, 0.00039353471947833896f, 0.00041245867032557726f, 0.00046195267350412905f, 0.0004792929976247251f, 0.00048733182484284043f, 0.0004590303869917989f, 0.0005992173682898283f, 0.00043638519127853215f, 0.0005628940998576581f, 0.00044766924111172557f, 0.00038895074976608157f, 0.0004101749509572983f, 0.00041214574594050646f, 0.0006505198543891311f, 0.0005172350211068988f, 0.0003610799612943083f, 0.0005086096934974194f, 0.00044131180038675666f, 0.0006606252864003181f, 0.0004999252269044518f, 0.0006356971571221948f, 0.0005592898232862353f, 0.00038539120578207076f, 0.00040211438317783177f, 0.0004779181908816099f, 0.00042040625703521073f, 0.00045246619265526533f, 0.0004622669657692313f, 0.0004577056388370693f, 0.000534802908077836f, 0.0005697851302102208f, 0.0007057254551909864f, 0.000575957412365824f, 0.0004937713383696973f, 0.0004880966735072434f, 0.0004916645120829344f, 0.0005698614986613393f, 0.0004824167408514768f, 0.0004692070360761136f, 0.0004518718342296779f, 0.0003959577588830143f, 0.0004659462138079107f, 0.000434989167843014f, 0.0004944081883877516f, 0.0004948556306771934f, 0.0004310470540076494f, 0.00040740141412243247f, 0.0004785145865753293f, 0.0004452322027646005f, 0.000497683824505657f, 0.0005752202123403549f, 0.0005010254099033773f, 0.00045481236884370446f, 0.0005351586150936782f, 0.0005453471094369888f, 0.00041097443317994475f, 0.00047079502837732434f, 0.000463886302895844f, 0.00036109978100284934f, 0.0003649662830866873f, 0.00044526089914143085f, 0.0007427751552313566f, 0.0004197406815364957f, 0.0005887094885110855f, 0.00043749454198405147f, 0.0004329296061769128f, 0.0004776667628902942f, 0.0006715325871482491f, 0.00044672031071968377f, 0.0004457794420886785f, 0.0004101059748791158f, 0.00042376579949632287f, 0.00037697528023272753f, 0.00046867787023074925f, 0.00043469556840136647f, 0.0004999434459023178f, 0.00044979352969676256f, 0.0005129388300701976f, 0.0004231343627907336f, 0.00040680175879970193f, 0.00042208301601931453f, 0.0004845504881814122f, 0.0005950852646492422f, 0.0004933883319608867f, 0.0004263395385351032f, 0.0004253105435054749f, 0.00036052201176062226f, 0.00038496192428283393f, 0.00042185766506008804f, 0.0004632080963347107f, 0.0003689960576593876f, 0.0005906611331738532f, 0.00040569709381088614f, 0.0004184403223916888f, 0.00041080734808929265f, 0.0004500465583987534f, 0.00038818965549580753f, 0.000493674713652581f, 0.0003766478621400893f, 0.0003685458214022219f, 0.0005324836820363998f, 0.0003936036955565214f, 0.0005159287247806787f, 0.0005062510026618838f, 0.0005078644026070833f, 0.0004414662253111601f, 0.0004956299089826643f, 0.00047749499208293855f, 0.0006290937308222055f, 0.0004576694336719811f, 0.00041974111809395254f, 0.000371470203390345f, 0.0005957738030701876f, 0.00046074821148067713f, 0.0004198564274702221f, 0.0004600148240569979f, 0.0003389030753169209f, 0.0004969884757883847f, 0.00060188805218786f, 0.0005441405810415745f, 0.00040768703911453485f, 0.0005815170588903129f, 0.00042589803342707455f, 0.0004973315517418087f, 0.00041944088297896087f, 0.0004295916005503386f, 0.0005079571856185794f, 0.0003874288813676685f, 0.00046013781684450805f, 0.0004673615621868521f, 0.0005687559605576098f, 0.0003979832981713116f, 0.00034185321419499815f, 0.0005363976815715432f, 0.0006695211050100625f, 0.0005713863065466285f, 0.0006307740113697946f, 0.0004906604299321771f, 0.0004921075887978077f, 0.0003936926950700581f, 0.0005345340468920767f, 0.00041651554056443274f, 0.0004961098893545568f, 0.00042093227966688573f, 0.0004101434024050832f, 0.0004009411495644599f, 0.0004980745725333691f, 0.0005252095870673656f, 0.000497484696097672f, 0.00046684255357831717f, 0.0005035116337239742f, 0.0004376124416012317f, 0.00046509108506143093f, 0.0003774689103011042f, 0.00040481777978129685f, 0.00045143632451072335f, 0.0005023155244998634f, 0.00046499038580805063f, 0.0004928099224343896f, 0.00047973921755328774f, 0.0004953977186232805f, 0.0004112019669264555f, 0.000490098784212023f, 0.00039868601015768945f, 0.00047214291407726705f, 0.0004344006592873484f, 0.00041018816409632564f, 0.00040127799729816616f, 0.00047280435683205724f, 0.0004599838866852224f, 0.0004272048536222428f, 0.0004920038627460599f, 0.0003910727391485125f, 0.00043242264655418694f, 0.0004573203332256526f, 0.0004183425335213542f, 0.0005942920688539743f, 0.0004564476548694074f, 0.0005198050057515502f, 0.000439546158304438f, 0.0006542033515870571f, 0.00041520711965858936f, 0.0005068030441179872f, 0.0005001493846066296f, 0.0004507925477810204f, 0.0006550498655997217f, 0.000630169699434191f, 0.00036228023236617446f, 0.0004038955958094448f, 0.0005000483361072838f, 0.0005077957175672054f, 0.0005013844347558916f, 0.0006215073517523706f, 0.0003987524250987917f, 0.0004951285081915557f, 0.0005391730810515583f, 0.0004175602225586772f, 0.0005667094956152141f, 0.00038532260805368423f, 0.0005987454205751419f, 0.000564702320843935f, 0.00041695614345371723f, 0.0004414428840391338f, 0.0005439075757749379f, 0.0005018840893171728f, 0.00046532167471013963f, 0.0004885405069217086f, 0.0003926357312593609f, 0.0003852421068586409f, 0.00047254940727725625f, 0.00042308485717512667f, 0.000794865598436445f, 0.0005243726773187518f, 0.0005551671492867172f, 0.00042367068817839026f, 0.0004640418919734657f, 0.0004083953972440213f, 0.00048321770736947656f, 0.0005072257481515408f, 0.0004616346850525588f, 0.0005119377747178078f, 0.00044515711488202214f, 0.00043607334373518825f, 0.000651609618216753f, 0.0003748706076294184f, 0.00048351200530305505f, 0.000697619398124516f, 0.0006983238272368908f, 0.00040091012488119304f, 0.00043222011299803853f, 0.00040547337266616523f, 0.0006878786953166127f, 0.00044868048280477524f, 0.0005582960438914597f, 0.0006290632300078869f, 0.0005518217803910375f, 0.0005163788446225226f, 0.0004761334857903421f, 0.0004681550490204245f, 0.00046075001591816545f, 0.0006312999757938087f, 0.0004792282998096198f, 0.0008356704493053257f, 0.0004481920332182199f, 0.0004053212469443679f, 0.00041078432695940137f, 0.0005410337471403182f, 0.00039687324897386134f, 0.0004455866292119026f, 0.0005003077676519752f, 0.0005900788819417357f, 0.00047344996710307896f, 0.0005144731840118766f, 0.0004633380158338696f, 0.0003879466967191547f, 0.0003912012034561485f, 0.0005547605687752366f, 0.0004583685367833823f, 0.0005596120026893914f, 0.0004843558417633176f, 0.0004311556986067444f, 0.0004968029097653925f, 0.0003837599069811404f, 0.0005699987523257732f, 0.000584348279517144f, 0.0003805574669968337f, 0.0004562480899039656f, 0.00044229094055481255f, 0.0004900383646599948f, 0.0003808374749496579f, 0.0004915811005048454f, 0.0004792102554347366f, 0.0004539786314126104f, 0.00046604237286373973f, 0.000524137809406966f, 0.00044897457701154053f, 0.000430108979344368f, 0.00044518301729112864f, 0.00043223274406045675f, 0.0004795979184564203f, 0.0005032234475947917f, 0.0003814857336692512f, 0.00045674853026866913f, 0.0005212798132561147f, 0.0005246231448836625f, 0.00042735011084005237f, 0.0003886015329044312f, 0.00045651354594156146f, 0.0005070558399893343f, 0.0004187717568129301f, 0.0005188003415241838f, 0.0003866128681693226f, 0.0005143085145391524f, 0.0005297755124047399f, 0.0004300136351957917f, 0.000452223903266713f, 0.0004734517715405673f, 0.000434982095612213f, 0.0006544903735630214f, 0.0004596841463353485f, 0.000543747388292104f, 0.0006016698898747563f, 0.00041116855572909117f, 0.0005643282784149051f, 0.00045005136053077877f, 0.00043136588647030294f, 0.0004945144755765796f, 0.0006395214004442096f, 0.0005615588161163032f, 0.0003939946473110467f, 0.0004127879801671952f, 0.00045327164116315544f, 0.0005438058287836611f, 0.00044422326027415693f, 0.00047855923185124993f, 0.0004236638778820634f, 0.0005245035281404853f, 0.00041545048588886857f, 0.0005026119761168957f, 0.0004146480350755155f, 0.0005444840062409639f, 0.000594756449572742f, 0.00045425663120113313f, 0.0003907792561221868f, 0.0004840198962483555f, 0.0003893935645464808f, 0.00038552560727111995f, 0.0003949156671296805f, 0.000346105225617066f, 0.00041794023127295077f, 0.0005717335734516382f, 0.0005343075026758015f, 0.0004096250340808183f, 0.0004614208883140236f, 0.0004566078132484108f, 0.0004589259915519506f, 0.0005031363689340651f),
    AI_PACK_INTQ_ZP(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)))

/* Int quant #171 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0013255153317004442f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #172 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_69_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(2.6852301743929274e-05f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #173 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_weights_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0031969062983989716f),
    AI_PACK_INTQ_ZP(0)))

/* Int quant #174 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(dense_70_bias_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(8.928114573979185e-05f),
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
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_15_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #183 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_17_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #184 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_18_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #185 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_21_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #186 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_22_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #187 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_25_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #188 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_27_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #189 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_29_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #190 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_30_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #191 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_33_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #192 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_34_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #193 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_37_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #194 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_38_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #195 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_41_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #196 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_42_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #197 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_44_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #198 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_45_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #199 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_48_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #200 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_49_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #201 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_52_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #202 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_54_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #203 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_56_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #204 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_57_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #205 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_60_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #206 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_61_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #207 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_64_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #208 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_65_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #209 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_scratch1_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/* Int quant #210 */
AI_INTQ_INFO_LIST_OBJ_DECLARE(conv2d_67_scratch2_intq, AI_STATIC_CONST,
  AI_BUFFER_META_FLAG_SCALE_FLOAT|AI_BUFFER_META_FLAG_ZEROPOINT_S8, 1,
  AI_PACK_INTQ_INFO(
    AI_PACK_INTQ_SCALE(0.0235294122248888f),
    AI_PACK_INTQ_ZP(-128)))

/**  Tensor declarations section  *********************************************/
/* Tensor #0 */
AI_TENSOR_OBJ_DECLARE(
  serving_default_sequential_33_input0_output, AI_STATIC,
  0, 0x1,
  AI_SHAPE_INIT(4, 1, 3, 224, 224), AI_STRIDE_INIT(4, 1, 1, 3, 672),
  1, &serving_default_sequential_33_input0_output_array, &serving_default_sequential_33_input0_output_intq)

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
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5, 5),
  1, &dense_70_output_array, &dense_70_output_intq)

/* Tensor #66 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_fmt_output, AI_STATIC,
  66, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &dense_70_fmt_output_array, NULL)

/* Tensor #67 */
AI_TENSOR_OBJ_DECLARE(
  nl_71_output, AI_STATIC,
  67, 0x0,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
  1, &nl_71_output_array, NULL)

/* Tensor #68 */
AI_TENSOR_OBJ_DECLARE(
  nl_71_fmt_output, AI_STATIC,
  68, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5, 5),
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
  AI_SHAPE_INIT(4, 100, 5, 1, 1), AI_STRIDE_INIT(4, 1, 100, 500, 500),
  1, &dense_70_weights_array, &dense_70_weights_intq)

/* Tensor #176 */
AI_TENSOR_OBJ_DECLARE(
  dense_70_bias, AI_STATIC,
  176, 0x1,
  AI_SHAPE_INIT(4, 1, 5, 1, 1), AI_STRIDE_INIT(4, 4, 4, 20, 20),
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
  conv2d_15_scratch1, AI_STATIC,
  195, 0x1,
  AI_SHAPE_INIT(4, 1, 48, 28, 28), AI_STRIDE_INIT(4, 1, 1, 48, 1344),
  1, &conv2d_15_scratch1_array, &conv2d_15_scratch1_intq)

/* Tensor #196 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_16_scratch0, AI_STATIC,
  196, 0x0,
  AI_SHAPE_INIT(4, 1, 352, 1, 1), AI_STRIDE_INIT(4, 1, 1, 352, 352),
  1, &conv2d_16_scratch0_array, NULL)

/* Tensor #197 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch0, AI_STATIC,
  197, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_17_scratch0_array, NULL)

/* Tensor #198 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_17_scratch1, AI_STATIC,
  198, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_17_scratch1_array, &conv2d_17_scratch1_intq)

/* Tensor #199 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch0, AI_STATIC,
  199, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_18_scratch0_array, NULL)

/* Tensor #200 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_18_scratch1, AI_STATIC,
  200, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_18_scratch1_array, &conv2d_18_scratch1_intq)

/* Tensor #201 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_19_scratch0, AI_STATIC,
  201, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_19_scratch0_array, NULL)

/* Tensor #202 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch0, AI_STATIC,
  202, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_21_scratch0_array, NULL)

/* Tensor #203 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_21_scratch1, AI_STATIC,
  203, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_21_scratch1_array, &conv2d_21_scratch1_intq)

/* Tensor #204 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch0, AI_STATIC,
  204, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_22_scratch0_array, NULL)

/* Tensor #205 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_22_scratch1, AI_STATIC,
  205, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_22_scratch1_array, &conv2d_22_scratch1_intq)

/* Tensor #206 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_23_scratch0, AI_STATIC,
  206, 0x0,
  AI_SHAPE_INIT(4, 1, 544, 1, 1), AI_STRIDE_INIT(4, 1, 1, 544, 544),
  1, &conv2d_23_scratch0_array, NULL)

/* Tensor #207 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch0, AI_STATIC,
  207, 0x0,
  AI_SHAPE_INIT(4, 1, 1024, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1024, 1024),
  1, &conv2d_25_scratch0_array, NULL)

/* Tensor #208 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_25_scratch1, AI_STATIC,
  208, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 28, 28), AI_STRIDE_INIT(4, 1, 1, 96, 2688),
  1, &conv2d_25_scratch1_array, &conv2d_25_scratch1_intq)

/* Tensor #209 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch0, AI_STATIC,
  209, 0x0,
  AI_SHAPE_INIT(4, 1, 3553, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3553, 3553),
  1, &conv2d_27_scratch0_array, NULL)

/* Tensor #210 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_27_scratch1, AI_STATIC,
  210, 0x1,
  AI_SHAPE_INIT(4, 1, 96, 14, 14), AI_STRIDE_INIT(4, 1, 1, 96, 1344),
  1, &conv2d_27_scratch1_array, &conv2d_27_scratch1_intq)

/* Tensor #211 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_28_scratch0, AI_STATIC,
  211, 0x0,
  AI_SHAPE_INIT(4, 1, 624, 1, 1), AI_STRIDE_INIT(4, 1, 1, 624, 624),
  1, &conv2d_28_scratch0_array, NULL)

/* Tensor #212 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch0, AI_STATIC,
  212, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_29_scratch0_array, NULL)

/* Tensor #213 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_29_scratch1, AI_STATIC,
  213, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_29_scratch1_array, &conv2d_29_scratch1_intq)

/* Tensor #214 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch0, AI_STATIC,
  214, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_30_scratch0_array, NULL)

/* Tensor #215 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_30_scratch1, AI_STATIC,
  215, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_30_scratch1_array, &conv2d_30_scratch1_intq)

/* Tensor #216 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_31_scratch0, AI_STATIC,
  216, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_31_scratch0_array, NULL)

/* Tensor #217 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch0, AI_STATIC,
  217, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_33_scratch0_array, NULL)

/* Tensor #218 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_33_scratch1, AI_STATIC,
  218, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_33_scratch1_array, &conv2d_33_scratch1_intq)

/* Tensor #219 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch0, AI_STATIC,
  219, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_34_scratch0_array, NULL)

/* Tensor #220 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_34_scratch1, AI_STATIC,
  220, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_34_scratch1_array, &conv2d_34_scratch1_intq)

/* Tensor #221 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_35_scratch0, AI_STATIC,
  221, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_35_scratch0_array, NULL)

/* Tensor #222 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch0, AI_STATIC,
  222, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_37_scratch0_array, NULL)

/* Tensor #223 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_37_scratch1, AI_STATIC,
  223, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_37_scratch1_array, &conv2d_37_scratch1_intq)

/* Tensor #224 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch0, AI_STATIC,
  224, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_38_scratch0_array, NULL)

/* Tensor #225 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_38_scratch1, AI_STATIC,
  225, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_38_scratch1_array, &conv2d_38_scratch1_intq)

/* Tensor #226 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_39_scratch0, AI_STATIC,
  226, 0x0,
  AI_SHAPE_INIT(4, 1, 816, 1, 1), AI_STRIDE_INIT(4, 1, 1, 816, 816),
  1, &conv2d_39_scratch0_array, NULL)

/* Tensor #227 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch0, AI_STATIC,
  227, 0x0,
  AI_SHAPE_INIT(4, 1, 1536, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1536, 1536),
  1, &conv2d_41_scratch0_array, NULL)

/* Tensor #228 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_41_scratch1, AI_STATIC,
  228, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_41_scratch1_array, &conv2d_41_scratch1_intq)

/* Tensor #229 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch0, AI_STATIC,
  229, 0x0,
  AI_SHAPE_INIT(4, 1, 5329, 1, 1), AI_STRIDE_INIT(4, 1, 1, 5329, 5329),
  1, &conv2d_42_scratch0_array, NULL)

/* Tensor #230 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_42_scratch1, AI_STATIC,
  230, 0x1,
  AI_SHAPE_INIT(4, 1, 144, 14, 14), AI_STRIDE_INIT(4, 1, 1, 144, 2016),
  1, &conv2d_42_scratch1_array, &conv2d_42_scratch1_intq)

/* Tensor #231 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_43_scratch0, AI_STATIC,
  231, 0x0,
  AI_SHAPE_INIT(4, 1, 896, 1, 1), AI_STRIDE_INIT(4, 1, 1, 896, 896),
  1, &conv2d_43_scratch0_array, NULL)

/* Tensor #232 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch0, AI_STATIC,
  232, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_44_scratch0_array, NULL)

/* Tensor #233 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_44_scratch1, AI_STATIC,
  233, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_44_scratch1_array, &conv2d_44_scratch1_intq)

/* Tensor #234 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch0, AI_STATIC,
  234, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_45_scratch0_array, NULL)

/* Tensor #235 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_45_scratch1, AI_STATIC,
  235, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_45_scratch1_array, &conv2d_45_scratch1_intq)

/* Tensor #236 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_46_scratch0, AI_STATIC,
  236, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_46_scratch0_array, NULL)

/* Tensor #237 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch0, AI_STATIC,
  237, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_48_scratch0_array, NULL)

/* Tensor #238 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_48_scratch1, AI_STATIC,
  238, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_48_scratch1_array, &conv2d_48_scratch1_intq)

/* Tensor #239 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch0, AI_STATIC,
  239, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_49_scratch0_array, NULL)

/* Tensor #240 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_49_scratch1, AI_STATIC,
  240, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_49_scratch1_array, &conv2d_49_scratch1_intq)

/* Tensor #241 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_50_scratch0, AI_STATIC,
  241, 0x0,
  AI_SHAPE_INIT(4, 1, 1088, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1088, 1088),
  1, &conv2d_50_scratch0_array, NULL)

/* Tensor #242 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch0, AI_STATIC,
  242, 0x0,
  AI_SHAPE_INIT(4, 1, 2048, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2048, 2048),
  1, &conv2d_52_scratch0_array, NULL)

/* Tensor #243 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_52_scratch1, AI_STATIC,
  243, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 14, 14), AI_STRIDE_INIT(4, 1, 1, 192, 2688),
  1, &conv2d_52_scratch1_array, &conv2d_52_scratch1_intq)

/* Tensor #244 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch0, AI_STATIC,
  244, 0x0,
  AI_SHAPE_INIT(4, 1, 7105, 1, 1), AI_STRIDE_INIT(4, 1, 1, 7105, 7105),
  1, &conv2d_54_scratch0_array, NULL)

/* Tensor #245 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_54_scratch1, AI_STATIC,
  245, 0x1,
  AI_SHAPE_INIT(4, 1, 192, 7, 7), AI_STRIDE_INIT(4, 1, 1, 192, 1344),
  1, &conv2d_54_scratch1_array, &conv2d_54_scratch1_intq)

/* Tensor #246 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_55_scratch0, AI_STATIC,
  246, 0x0,
  AI_SHAPE_INIT(4, 1, 1328, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1328, 1328),
  1, &conv2d_55_scratch0_array, NULL)

/* Tensor #247 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch0, AI_STATIC,
  247, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_56_scratch0_array, NULL)

/* Tensor #248 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_56_scratch1, AI_STATIC,
  248, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_56_scratch1_array, &conv2d_56_scratch1_intq)

/* Tensor #249 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch0, AI_STATIC,
  249, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_57_scratch0_array, NULL)

/* Tensor #250 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_57_scratch1, AI_STATIC,
  250, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_57_scratch1_array, &conv2d_57_scratch1_intq)

/* Tensor #251 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_58_scratch0, AI_STATIC,
  251, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_58_scratch0_array, NULL)

/* Tensor #252 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch0, AI_STATIC,
  252, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_60_scratch0_array, NULL)

/* Tensor #253 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_60_scratch1, AI_STATIC,
  253, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_60_scratch1_array, &conv2d_60_scratch1_intq)

/* Tensor #254 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch0, AI_STATIC,
  254, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_61_scratch0_array, NULL)

/* Tensor #255 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_61_scratch1, AI_STATIC,
  255, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_61_scratch1_array, &conv2d_61_scratch1_intq)

/* Tensor #256 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_62_scratch0, AI_STATIC,
  256, 0x0,
  AI_SHAPE_INIT(4, 1, 1904, 1, 1), AI_STRIDE_INIT(4, 1, 1, 1904, 1904),
  1, &conv2d_62_scratch0_array, NULL)

/* Tensor #257 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch0, AI_STATIC,
  257, 0x0,
  AI_SHAPE_INIT(4, 1, 3584, 1, 1), AI_STRIDE_INIT(4, 1, 1, 3584, 3584),
  1, &conv2d_64_scratch0_array, NULL)

/* Tensor #258 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_64_scratch1, AI_STATIC,
  258, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_64_scratch1_array, &conv2d_64_scratch1_intq)

/* Tensor #259 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch0, AI_STATIC,
  259, 0x0,
  AI_SHAPE_INIT(4, 1, 12433, 1, 1), AI_STRIDE_INIT(4, 1, 1, 12433, 12433),
  1, &conv2d_65_scratch0_array, NULL)

/* Tensor #260 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_65_scratch1, AI_STATIC,
  260, 0x1,
  AI_SHAPE_INIT(4, 1, 336, 7, 7), AI_STRIDE_INIT(4, 1, 1, 336, 2352),
  1, &conv2d_65_scratch1_array, &conv2d_65_scratch1_intq)

/* Tensor #261 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_66_scratch0, AI_STATIC,
  261, 0x0,
  AI_SHAPE_INIT(4, 1, 2464, 1, 1), AI_STRIDE_INIT(4, 1, 1, 2464, 2464),
  1, &conv2d_66_scratch0_array, NULL)

/* Tensor #262 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch0, AI_STATIC,
  262, 0x0,
  AI_SHAPE_INIT(4, 1, 13248, 1, 1), AI_STRIDE_INIT(4, 1, 1, 13248, 13248),
  1, &conv2d_67_scratch0_array, NULL)

/* Tensor #263 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch1, AI_STATIC,
  263, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 7, 7), AI_STRIDE_INIT(4, 1, 1, 1280, 8960),
  1, &conv2d_67_scratch1_array, &conv2d_67_scratch1_intq)

/* Tensor #264 */
AI_TENSOR_OBJ_DECLARE(
  conv2d_67_scratch2, AI_STATIC,
  264, 0x1,
  AI_SHAPE_INIT(4, 1, 1280, 7, 7), AI_STRIDE_INIT(4, 1, 1, 1280, 8960),
  1, &conv2d_67_scratch2_array, &conv2d_67_scratch2_intq)



/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  conversion_0_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_OBJ_INIT(AI_FLAG_NONE, 1, &serving_default_sequential_33_input0_output),
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
                     1, 1, 539128, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 610784, 1,
                     NULL),
  AI_TENSOR_LIST_IO_OBJ_INIT(AI_FLAG_NONE, AI_NETWORK_IN_NUM, &serving_default_sequential_33_input0_output),
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
    serving_default_sequential_33_input0_output_array.data = AI_PTR(NULL);
    serving_default_sequential_33_input0_output_array.data_start = AI_PTR(NULL);
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
    conv2d_15_output_array.data = AI_PTR(activations + 39412);
    conv2d_15_output_array.data_start = AI_PTR(activations + 39412);
    conv2d_16_output_array.data = AI_PTR(activations + 352);
    conv2d_16_output_array.data_start = AI_PTR(activations + 352);
    conv2d_17_output_array.data = AI_PTR(activations + 89184);
    conv2d_17_output_array.data_start = AI_PTR(activations + 89184);
    conv2d_18_output_array.data = AI_PTR(activations + 239712);
    conv2d_18_output_array.data_start = AI_PTR(activations + 239712);
    conv2d_19_output_array.data = AI_PTR(activations + 13440);
    conv2d_19_output_array.data_start = AI_PTR(activations + 13440);
    eltwise_20_output_array.data = AI_PTR(activations + 25984);
    eltwise_20_output_array.data_start = AI_PTR(activations + 25984);
    conv2d_21_output_array.data = AI_PTR(activations + 113792);
    conv2d_21_output_array.data_start = AI_PTR(activations + 113792);
    conv2d_22_output_array.data = AI_PTR(activations + 189056);
    conv2d_22_output_array.data_start = AI_PTR(activations + 189056);
    conv2d_23_output_array.data = AI_PTR(activations + 544);
    conv2d_23_output_array.data_start = AI_PTR(activations + 544);
    eltwise_24_output_array.data = AI_PTR(activations + 13088);
    eltwise_24_output_array.data_start = AI_PTR(activations + 13088);
    conv2d_25_output_array.data = AI_PTR(activations + 100896);
    conv2d_25_output_array.data_start = AI_PTR(activations + 100896);
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
    conv2d_57_output_array.data = AI_PTR(activations + 57048);
    conv2d_57_output_array.data_start = AI_PTR(activations + 57048);
    conv2d_58_output_array.data = AI_PTR(activations + 5976);
    conv2d_58_output_array.data_start = AI_PTR(activations + 5976);
    eltwise_59_output_array.data = AI_PTR(activations + 8720);
    eltwise_59_output_array.data_start = AI_PTR(activations + 8720);
    conv2d_60_output_array.data = AI_PTR(activations + 27928);
    conv2d_60_output_array.data_start = AI_PTR(activations + 27928);
    conv2d_61_output_array.data = AI_PTR(activations + 60856);
    conv2d_61_output_array.data_start = AI_PTR(activations + 60856);
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
    nl_71_output_array.data = AI_PTR(activations + 28);
    nl_71_output_array.data_start = AI_PTR(activations + 28);
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
    conv2d_15_scratch1_array.data = AI_PTR(activations + 1780);
    conv2d_15_scratch1_array.data_start = AI_PTR(activations + 1780);
    conv2d_16_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_16_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_17_scratch0_array.data = AI_PTR(activations + 12896);
    conv2d_17_scratch0_array.data_start = AI_PTR(activations + 12896);
    conv2d_17_scratch1_array.data = AI_PTR(activations + 13920);
    conv2d_17_scratch1_array.data_start = AI_PTR(activations + 13920);
    conv2d_18_scratch0_array.data = AI_PTR(activations + 12896);
    conv2d_18_scratch0_array.data_start = AI_PTR(activations + 12896);
    conv2d_18_scratch1_array.data = AI_PTR(activations + 164448);
    conv2d_18_scratch1_array.data_start = AI_PTR(activations + 164448);
    conv2d_19_scratch0_array.data = AI_PTR(activations + 12896);
    conv2d_19_scratch0_array.data_start = AI_PTR(activations + 12896);
    conv2d_21_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_21_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_21_scratch1_array.data = AI_PTR(activations + 38528);
    conv2d_21_scratch1_array.data_start = AI_PTR(activations + 38528);
    conv2d_22_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_22_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_22_scratch1_array.data = AI_PTR(activations + 38528);
    conv2d_22_scratch1_array.data_start = AI_PTR(activations + 38528);
    conv2d_23_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_23_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_25_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_25_scratch1_array.data = AI_PTR(activations + 25632);
    conv2d_25_scratch1_array.data_start = AI_PTR(activations + 25632);
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
    conv2d_57_scratch1_array.data = AI_PTR(activations + 40584);
    conv2d_57_scratch1_array.data_start = AI_PTR(activations + 40584);
    conv2d_58_scratch0_array.data = AI_PTR(activations + 4072);
    conv2d_58_scratch0_array.data_start = AI_PTR(activations + 4072);
    conv2d_60_scratch0_array.data = AI_PTR(activations + 0);
    conv2d_60_scratch0_array.data_start = AI_PTR(activations + 0);
    conv2d_60_scratch1_array.data = AI_PTR(activations + 11464);
    conv2d_60_scratch1_array.data_start = AI_PTR(activations + 11464);
    conv2d_61_scratch0_array.data = AI_PTR(activations + 11464);
    conv2d_61_scratch0_array.data_start = AI_PTR(activations + 11464);
    conv2d_61_scratch1_array.data = AI_PTR(activations + 44392);
    conv2d_61_scratch1_array.data_start = AI_PTR(activations + 44392);
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
    dense_70_bias_array.data = AI_PTR(weights + 539108);
    dense_70_bias_array.data_start = AI_PTR(weights + 539108);
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
      
      .n_macc            = 58587644,
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

