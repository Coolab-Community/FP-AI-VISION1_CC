/**
  ******************************************************************************
  * @file    peopledetect_network_pp_user.h
  * @author  Artificial Intelligence Solutions group (AIS)
  * @brief   User header file for Post processing of network Object Detection
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */

#ifndef __peopledetect_network_PP_USER_H__
#define __peopledetect_network_PP_USER_H__


#ifdef __cplusplus
 extern "C" {
#endif

#include "arm_math.h"


/* ---------------    Can be modified by the application          ----------------- */
/* I/O configuration examples */
#define AI_PEOPLEDETECT_NETWORK_PP_NB_CLASSES        (1)
#define AI_PEOPLEDETECT_NETWORK_PP_NB_ANCHORS        (5)
#define AI_PEOPLEDETECT_NETWORK_PP_GRID_WIDTH        (15)
#define AI_PEOPLEDETECT_NETWORK_PP_GRID_HEIGHT       (15)
#define AI_PEOPLEDETECT_NETWORK_PP_NB_INPUT_BOXES    (AI_PEOPLEDETECT_NETWORK_PP_GRID_WIDTH * AI_PEOPLEDETECT_NETWORK_PP_GRID_HEIGHT)
#define AI_PEOPLEDETECT_NETWORK_PP_MAX_BOXES_LIMIT   (30)

/* Tuning example */
#define AI_PEOPLEDETECT_NETWORK_PP_CONF_THRESHOLD    (0.5f)
#define AI_PEOPLEDETECT_NETWORK_PP_IOU_THRESHOLD     (0.5f)

/* Anchor boxes examples */
static const float32_t AI_PEOPLEDETECT_NETWORK_PP_ANCHORS[2*AI_PEOPLEDETECT_NETWORK_PP_NB_ANCHORS] = {
                                                                     0.3780,
                                                                    0.9000,
                                                                    1.1577,
                                                                    2.7430,
                                                                    2.5438,
                                                                    6.2511,
                                                                    5.0088,
                                                                    9.8389,
                                                                    10.8392,
                                                                    11.0220
                                                                  };


#endif      /* __peopledetect_network_PP_USER_H__  */

