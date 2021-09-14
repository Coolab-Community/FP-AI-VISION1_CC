/**
 ******************************************************************************
 * @file    fp_vision_app.h
 * @author  MCD Application Team
 * @brief   Header for fp_vision_app.c module
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
#ifndef __FP_VISION_APP_H
#define __FP_VISION_APP_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "fp_vision_global.h"
#include "fp_vision_ai.h"
#include "fp_vision_utils.h"
#include "fp_vision_test.h"
#include "fp_vision_camera.h"
#include "fp_vision_display.h"
#include "fp_vision_preproc.h"
#include "stm32h747i_discovery_sdram.h"
#include "stm32h747i_discovery_sd.h"
#include "stm32_fs.h"
#include "stm32h747i_discovery_qspi.h"

/* Exported types ------------------------------------------------------------*/
typedef struct
{
  /**General**/
  AppOperatingMode_TypeDef Operating_Mode;/*Application's operating mode*/
  uint32_t run_loop;
  
  /**NN Output**/
  uint32_t nn_inference_time;
  char const* nn_top1_output_class_name;
  float nn_top1_output_class_proba;
  int ranking[NN_OUTPUT_CLASS_NUMBER];
  
  /**Camera context**/
  CameraContext_TypeDef* Camera_ContextPtr;
  
  /**Pre-Processing context**/
  PreprocContext_TypeDef* Preproc_ContextPtr;
  
  /**Display context**/
  DisplayContext_TypeDef* Display_ContextPtr;
  
  /**Utility context**/
  UtilsContext_TypeDef* Utils_ContextPtr;   
  
  /**Test context**/
  TestContext_TypeDef* Test_ContextPtr; 
  
  /**AI NN context**/
  AiContext_TypeDef* Ai_ContextPtr;   
}AppContext_TypeDef;

/* Exported macros -----------------------------------------------------------*/
#if WEIGHT_QSPI == 1 && WEIGHT_EXEC_EXTRAM == 1
 #define QUADSPI_EXT_FLASH  0x90000000
#endif

/* Exported constants --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
extern AppContext_TypeDef App_Context;
extern uint8_t ai_fp_global_memory[];
#if MEMORY_SCHEME == SPLIT_INT_EXT
 extern uint8_t ai_fp_activation_memory[];
#endif
extern const char* output_labels[];

#if WEIGHT_QSPI == 1
extern uint8_t weights_table_sdram[];
#endif

/*******************/
/***Misc defines****/
/*******************/ 
/* Check allowed combination of memory layout scheme and camera resolution*/
#if CAMERA_CAPTURE_RES == VGA_640_480_RES
#if MEMORY_SCHEME == FULL_INTERNAL_FPS_OPT || MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
#error Memory scheme not allowed in this application
#endif
#elif CAMERA_CAPTURE_RES == QVGA_320_240_RES
 #if MEMORY_SCHEME == FULL_EXTERNAL || MEMORY_SCHEME == SPLIT_INT_EXT
  #error Memory scheme not allowed in this application
 #endif
#endif

#define WELCOME_MSG_0            "Food image classification"
#define WELCOME_MSG_1            "Float model"
#define WELCOME_MSG_2            "Standard version"

#if CAMERA_CAPTURE_RES == VGA_640_480_RES
#define WELCOME_MSG_3 "VGA"
#elif CAMERA_CAPTURE_RES == QVGA_320_240_RES
 #error QVGA resolution is not supported for this application
#endif

#if MEMORY_SCHEME == FULL_EXTERNAL
#define WELCOME_MSG_4 "Full external"
#elif MEMORY_SCHEME == SPLIT_INT_EXT
#define WELCOME_MSG_4 "Split ext/int"
#elif MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
#define WELCOME_MSG_4 "Full int Memory optim"
#elif MEMORY_SCHEME == FULL_INTERNAL_FPS_OPT
#define WELCOME_MSG_4 "Full int FPS optim"
#else
#error Please check definition of MEMORY_SCHEME define
#endif


#if WEIGHT_QSPI == 1 /*&& WEIGHT_QSPI_PROGED == 1*/ && WEIGHT_EXEC_EXTRAM == 0
 #define WELCOME_MSG_5            "Weight/Bias in external QSPI flash"
#elif WEIGHT_QSPI == 1 /*&& WEIGHT_QSPI_PROGED == 1*/ && WEIGHT_EXEC_EXTRAM == 1
 #define WELCOME_MSG_5            "Weight/Bias in external SDRAM"
#elif WEIGHT_QSPI == 0
 #define WELCOME_MSG_5            "Weight/Bias in internal flash"
#endif

#define NN_GOOD_RES 70
#define NN_BAD_RES 55

#define RGB_565_BPP 2
#define RGB_888_BPP 3

#define MAX(x, y) ((x > y) ? x : y)
#define xstr(s) str(s)
#define str(s) #s

/**************************/
/***LCD related defines****/
/**************************/
#define DISPLAY_INFER_TIME_LINE 16
#define DISPLAY_IMG_PREPROCESS_LINE (DISPLAY_INFER_TIME_LINE + 1)
#define DISPLAY_FPS_LINE (DISPLAY_INFER_TIME_LINE + 2)
#define DISPLAY_ACQU_MODE_LINE 19
#define DISPLAY_TOP_N_LAST_LINE (DISPLAY_INFER_TIME_LINE - 4)

///*****************************/
///***Buffers size definition***/
///*****************************/
#define CAM_FRAME_BUFFER_SIZE (CAM_RES_WIDTH * CAM_RES_HEIGHT * RGB_565_BPP)

#define PFC_OUTPUT_BUFFER_SIZE AI_NET_INPUT_SIZE
#define RESIZE_OUTPUT_BUFFER_SIZE (AI_NETWORK_WIDTH *AI_NETWORK_HEIGHT * RGB_565_BPP)
  
#define AI_INPUT_BUFFER_SIZE AI_NET_INPUT_SIZE_BYTES
#define AI_ACTIVATION_BUFFER_SIZE AI_ACTIVATION_SIZE_BYTES

/* Exported functions ------------------------------------------------------- */
void APP_Init(AppContext_TypeDef *);
void APP_Deinit(AppContext_TypeDef *);
void APP_GetNextReadyFrame(AppContext_TypeDef *);
void APP_StartNewFrameAcquisition(AppContext_TypeDef *);
void APP_FramePreprocess(AppContext_TypeDef *);
void APP_NetworkInference(AppContext_TypeDef *);
void APP_Postprocess(AppContext_TypeDef *);
void APP_Context_Init(AppContext_TypeDef *);

#ifdef __cplusplus
}
#endif

#endif /*__FP_VISION_APP_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
