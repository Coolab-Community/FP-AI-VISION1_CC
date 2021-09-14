/**
  ******************************************************************************
  * @file    peopledetect_network_pp_if.h
  * @author  Artificial Intelligence Solutions group (AIS)
  * @brief   global interface for Post processing of network Object Detection
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

#ifndef __peopledetect_network_PP_IF_H__
#define __peopledetect_network_PP_IF_H__


#ifdef __cplusplus
 extern "C" {
#endif

#include "arm_math.h"
#include "peopledetect_network_pp_user.h"


/* Error return codes */
#define AI_PEOPLEDETECT_NETWORK_PP_ERROR_NO                    (0)
#define AI_PEOPLEDETECT_NETWOK_PP_ERROR_BAD_HW                (-1)


/* I/O structures for network detector type */
/* --------------------------------------- */
typedef struct network_pp_inBuffer
{
	float32_t      x_center;
	float32_t      y_center;
  float32_t      width;
	float32_t      height;
	float32_t      objectness;
	float32_t      class_proba[AI_PEOPLEDETECT_NETWORK_PP_NB_CLASSES];
} network_pp_inBuffer_t;

typedef struct network_pp_in
{
	network_pp_inBuffer_t inBuff[AI_PEOPLEDETECT_NETWORK_PP_GRID_WIDTH * 
                              AI_PEOPLEDETECT_NETWORK_PP_GRID_HEIGHT * 
                              AI_PEOPLEDETECT_NETWORK_PP_NB_ANCHORS];
} network_pp_in_t;

typedef struct network_pp_outBuffer
{
	float32_t      x_center;
	float32_t      y_center;
	float32_t      width;
	float32_t      height;
	float32_t      conf;
	int32_t        class_index;
} network_pp_outBuffer_t;

typedef struct network_pp_out
{
	network_pp_outBuffer_t *pOutBuff;
	int32_t nb_detect;
} network_pp_out_t;


/* Generic Static parameters */
/* ------------------------- */
typedef enum network_pp_optim {
  AI_PEOPLEDETECT_NETWORK_PP_OPTIM_NORMAL     = 0,
  AI_PEOPLEDETECT_NETWORK_PP_OPTIM_FAST       = 1
} network_pp_optim_e;


typedef struct network_pp_static_param {
  int32_t  nb_classes;
  int32_t  nb_anchors;
  int32_t  grid_width;
  int32_t  grid_height;
  int32_t  nb_input_boxes;
  int32_t  max_boxes_limit;
  float32_t	conf_threshold;
  float32_t	iou_threshold;
  const float32_t	*pAnchors;
  network_pp_optim_e optim;
  void *pPersistent_mem;
} network_pp_static_param_t;



/* Exported functions ------------------------------------------------------- */
/*!
 * @brief Get persistent memory size (in bytes) for network post processing
 *        The application code can then allocate it
 *
 * @param [IN] Input static parameters
 * @retval Persistent memory size in bytes
 */
int32_t peopledetect_network_pp_getPersistentMemorySize(network_pp_static_param_t *pInput_static_param);


/*!
 * @brief Resets object detection network post processing
 *
 * @param [IN] Input static parameters
 *             pointer on persistent memory allocated by the application
 * @retval Error code
 */
int32_t peopledetect_network_pp_reset(network_pp_static_param_t *pInput_static_param,
                                  void *pPersistent_mem);


/*!
 * @brief Object detector post processing : includes output detector remapping,
 *        nms and score filtering for network.
 *
 * @param [IN] Pointer on input data
 *             Pointer on output data
 *             pointer on static parameters
 * @retval Error code
 */
int32_t peopledetect_network_pp_process(network_pp_in_t *pInput,
                                    network_pp_out_t *pOutput,
                                    network_pp_static_param_t *pInput_static_param);



#endif      /* __peopledetect_network_PP_IF_H__  */


