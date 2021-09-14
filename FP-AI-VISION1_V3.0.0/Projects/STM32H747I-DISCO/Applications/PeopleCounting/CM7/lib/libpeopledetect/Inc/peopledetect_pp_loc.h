/**
  ******************************************************************************
  * @file    peopledetect_pp_loc.h
  * @author  Artificial Intelligence Solutions group (AIS)
  * @brief   local header file for Post processing of Object Detection 
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

#ifndef __peopledetect_PP_LOC_H__
#define __peopledetect_PP_LOC_H__


#ifdef __cplusplus
 extern "C" {
#endif

#include "arm_math.h"
   

/*-----------------------------     YOLO_LC      -----------------------------*/
/* Offsets to access network input data */
#define AI_network_PP_XCENTER      (0)
#define AI_network_PP_YCENTER      (1)
#define AI_network_PP_WIDTHREL     (2)
#define AI_network_PP_HEIGHTREL    (3)
#define AI_network_PP_OBJECTNESS   (4)
#define AI_network_PP_CLASSPROB    (5)
   

/* static internal memory for network */
typedef struct network_pp_static_mem
{
    int32_t     crc_lock;
    int32_t     nb_detect;
} network_pp_static_mem_t;


typedef int _Cmpfun(const void *, const void *);
extern void qsort(void *, size_t, size_t, _Cmpfun *);


/*-----------------------------       SSD        -----------------------------*/
/* Offsets to access network input data */
#define AI_SSD_PP_CENTROID_YCENTER          (0)
#define AI_SSD_PP_CENTROID_XCENTER          (1)
#define AI_SSD_PP_CENTROID_HEIGHTREL        (2)
#define AI_SSD_PP_CENTROID_WIDTHREL         (3)
#define AI_SSD_PP_BOX_STRIDE                (4)

typedef struct ssd_pp_static_mem
{
    int32_t     crc_lock;
    int32_t     nb_detect;
} ssd_pp_static_mem_t;



#endif   /*  __peopledetect_PP_LOC_H__  */
