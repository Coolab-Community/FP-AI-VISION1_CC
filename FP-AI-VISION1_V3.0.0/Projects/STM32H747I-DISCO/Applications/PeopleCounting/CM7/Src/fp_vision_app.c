/**
 ******************************************************************************
 * @file    fp_vision_app.c
 * @author  MCD Application Team
 * @brief   FP VISION Application configuration
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
#include "fp_vision_app.h"
#include "people_ai_utilities.h"
#include "occupancy_logos.h"
#include <stdio.h>
#include <string.h>

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
AppContext_TypeDef App_Context;

/*****************************************/
/***AI_FP_GLOBAL_BUFFER_SIZE definition***/
/*****************************************/
#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT   
 #ifdef AI_NETWORK_INPUTS_IN_ACTIVATIONS
  #define AI_FP_GLOBAL_BUFFER_SIZE  (MAX(AI_ACTIVATION_BUFFER_SIZE, CAM_FRAME_BUFFER_SIZE)) 
 #else
  #define AI_FP_GLOBAL_BUFFER_SIZE  (MAX(AI_ACTIVATION_BUFFER_SIZE, CAM_FRAME_BUFFER_SIZE) + AI_INPUT_BUFFER_SIZE) 
 #endif
#elif MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
 #if MEMORY_SCHEME == SPLIT_INT_EXT
  #ifdef AI_NETWORK_INPUTS_IN_ACTIVATIONS
   #define AI_FP_GLOBAL_BUFFER_SIZE (CAM_FRAME_BUFFER_SIZE + CAM_FRAME_BUFFER_SIZE) 
  #else
   #define AI_FP_GLOBAL_BUFFER_SIZE (CAM_FRAME_BUFFER_SIZE + MAX(AI_INPUT_BUFFER_SIZE, CAM_FRAME_BUFFER_SIZE)) 
  #endif
 #else /*MEMORY_SCHEME == FULL_EXTERNAL*/
  #ifdef AI_NETWORK_INPUTS_IN_ACTIVATIONS
   #define AI_FP_GLOBAL_BUFFER_SIZE (CAM_FRAME_BUFFER_SIZE + MAX(AI_ACTIVATION_BUFFER_SIZE, CAM_FRAME_BUFFER_SIZE))
  #else
   #define AI_FP_GLOBAL_BUFFER_SIZE (CAM_FRAME_BUFFER_SIZE + MAX(AI_ACTIVATION_BUFFER_SIZE + AI_INPUT_BUFFER_SIZE, CAM_FRAME_BUFFER_SIZE))
  #endif
 #endif
#else
 #error Please check definition of MEMORY_SCHEME define
#endif

#if MEMORY_SCHEME == FULL_EXTERNAL
  #if defined ( __ICCARM__ )
    #pragma location="Vision_App_Complete"
    #pragma data_alignment=32
  #elif defined ( __CC_ARM )
    __attribute__((section(".Vision_App_Complete"), zero_init))
    __attribute__ ((aligned (32)))
  #elif defined ( __GNUC__ )
    __attribute__((section(".Vision_App_Complete")))
    __attribute__ ((aligned (32)))
  #else
    #error Unknown compiler
  #endif
  uint8_t ai_fp_global_memory[AI_FP_GLOBAL_BUFFER_SIZE];
#elif MEMORY_SCHEME == SPLIT_INT_EXT
  #if defined ( __ICCARM__ )
    #pragma location="Vision_App_ImgPipeline"
    #pragma data_alignment=32
  #elif defined ( __CC_ARM )
    __attribute__((section(".Vision_App_ImgPipeline"), zero_init))
    __attribute__ ((aligned (32)))
  #elif defined ( __GNUC__ )
    __attribute__((section(".Vision_App_ImgPipeline")))
    __attribute__ ((aligned (32)))
  #else
    #error Unknown compiler
  #endif
  uint8_t ai_fp_global_memory[AI_FP_GLOBAL_BUFFER_SIZE];
  #if defined ( __ICCARM__ )
    #pragma location="Vision_App_Inference"
    #pragma data_alignment=32
  #elif defined ( __CC_ARM )
    __attribute__((section(".Vision_App_Inference"), zero_init))
    __attribute__ ((aligned (32)))
  #elif defined ( __GNUC__ )
    __attribute__((section(".Vision_App_Inference")))
    __attribute__ ((aligned (32)))
  #else
    #error Unknown compiler
  #endif
 uint8_t ai_fp_activation_memory[AI_ACTIVATION_BUFFER_SIZE];
#elif MEMORY_SCHEME == FULL_INTERNAL_FPS_OPT || MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
  #if defined ( __ICCARM__ )
    #pragma location="Vision_App_SingleOverlay"
    #pragma data_alignment=32
  #elif defined ( __CC_ARM )
    __attribute__((section(".Vision_App_SingleOverlay"), zero_init))
    __attribute__ ((aligned (32)))
  #elif defined ( __GNUC__ )
    __attribute__((section(".Vision_App_SingleOverlay")))
    __attribute__ ((aligned (32)))
  #else
    #error Unknown compiler
  #endif
  uint8_t ai_fp_global_memory[AI_FP_GLOBAL_BUFFER_SIZE];
#else
 #error Please check definition of MEMORY_SCHEME define
#endif


extern const unsigned char stlogo[];
const char* output_labels[AI_PEOPLEDETECT_NETWORK_PP_NB_CLASSES] = {"person"};
float nn_output_buff[AI_NET_OUTPUT_SIZE] = {0};



/* Private function prototypes -----------------------------------------------*/
static void App_Output_Display(AppContext_TypeDef *);
static void App_Context_Init(AppContext_TypeDef *);

/* Functions Definition ------------------------------------------------------*/
int32_t network_nms_comparator_out(const void *pa, const void *pb)
{
    network_pp_outBuffer_t a = *(network_pp_outBuffer_t *)pa;
    network_pp_outBuffer_t b = *(network_pp_outBuffer_t *)pb;
    float32_t diff = 0;

    diff = b.conf - a.conf;

    if (diff < 0) return 1;
    else if (diff > 0) return -1;
    return 0;
}

/**
 * @brief  Process the output from NN and display it on LCD and LED
 * @param App_Context_Ptr pointer to application context
 */
static void App_Output_Display(AppContext_TypeDef *App_Context_Ptr)
{
  static uint32_t occurrence_number = NN_OUTPUT_DISPLAY_REFRESH_RATE;
  static uint32_t display_mode = 0;

  occurrence_number--;

  if (occurrence_number == 0)
  {
    char msg[70];

    occurrence_number = NN_OUTPUT_DISPLAY_REFRESH_RATE;

    /*Check if PB is pressed*/
    if (BSP_PB_GetState(BUTTON_WAKEUP) != RESET)
    {
      uint32_t mirror_flip;
      display_mode  = (display_mode + 1) % 4;

      switch (display_mode)
      {
      case 1:
        sprintf(msg, "Flip CAMERA mode");
        mirror_flip = CAMERA_MIRRORFLIP_FLIP;
        break;

      case 2:
        sprintf(msg, "Mirror CAMERA mode");
        mirror_flip = CAMERA_MIRRORFLIP_MIRROR;
        break;

      case 3:
        sprintf(msg, "Mirror and Flip CAMERA mode");
        mirror_flip = CAMERA_MIRRORFLIP_MIRROR | CAMERA_MIRRORFLIP_FLIP;
        break;

      default:
        sprintf(msg, "Normal CAMERA mode");
        mirror_flip = CAMERA_MIRRORFLIP_NONE;
        break;
      }

      UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
      UTIL_LCD_DisplayStringAt(0, LINE(9), (uint8_t*)msg, CENTER_MODE);
      CAMERA_Set_MirrorFlip(App_Context_Ptr->Camera_ContextPtr, mirror_flip);

      sprintf(msg, "Please release button");
      UTIL_LCD_DisplayStringAt(0, LINE(11), (uint8_t*)msg, CENTER_MODE);
      DISPLAY_Refresh(App_Context_Ptr->Display_ContextPtr);

      /*Wait for PB release*/
      while (BSP_PB_GetState(BUTTON_WAKEUP) != RESET);
      HAL_Delay(200);

      UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
    }

    /* Toggle LED based on result confidence */
    BSP_LED_Off(LED_GREEN);
    BSP_LED_Off(LED_ORANGE);
    BSP_LED_Off(LED_RED);

    BSP_LED_On(LED_RED);

    network_pp_outBuffer_t *pOutBuff = App_Context_Ptr->People_ContextPtr->output.pOutBuff;

    for (int32_t class_idx = 0; class_idx < AI_PEOPLEDETECT_NETWORK_PP_NB_CLASSES; class_idx++)
    {
      pOutBuff = App_Context_Ptr->People_ContextPtr->output.pOutBuff;
      for (int32_t i = 0; i < App_Context_Ptr->People_ContextPtr->output.nb_detect; ++i)
      {
        if (pOutBuff->class_index == class_idx)
        {
          DISPLAY_DrawBBox(pOutBuff->x_center, pOutBuff->y_center, pOutBuff->width, pOutBuff->height);

          BSP_LED_Off(LED_RED);
          BSP_LED_On(LED_GREEN);
        }
        pOutBuff++;
      }
    }

    /* Reset DMA2D RB-Swap for as it is not configured in BSP_LCD_DrawBitmap */
    hlcd_dma2d.LayerCfg[1].RedBlueSwap = DMA2D_RB_REGULAR;

    BSP_LCD_DrawBitmap(0, 640, 15, (uint8_t *)stlogo);

    if (App_Context_Ptr->People_ContextPtr->output.nb_detect == 0)
    {
      BSP_LCD_DrawBitmap(0, 680, 200, (uint8_t *)free_bmp);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_GREEN);
      UTIL_LCD_DisplayStringAt(320, LINE(13), (uint8_t *)"Vacant", CENTER_MODE);
    }
    else if (App_Context_Ptr->People_ContextPtr->output.nb_detect == 1)
    {
      BSP_LCD_DrawBitmap(0, 680, 200, (uint8_t *)busy_bmp);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
      UTIL_LCD_DisplayStringAt(320, LINE(13), (uint8_t *)"1 person", CENTER_MODE);
    }
    else
    {
      BSP_LCD_DrawBitmap(0, 680, 200, (uint8_t *)busy_bmp);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_RED);
      sprintf(msg, "%d persons", App_Context_Ptr->People_ContextPtr->output.nb_detect);
      UTIL_LCD_DisplayStringAt(320, LINE(13), (uint8_t *)msg, CENTER_MODE);
    }

    UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
    sprintf(msg, "%.1f fps", 1000.0F / (float)(App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.Tfps));
    UTIL_LCD_DisplayStringAt(320, LINE(DISPLAY_FPS_LINE), (uint8_t *)msg, CENTER_MODE);

    DISPLAY_Refresh(App_Context_Ptr->Display_ContextPtr);

  }
}

/** 
 * @brief Initializes the application context structure
 * @param App_Context_Ptr pointer to application context
 */
static void App_Context_Init(AppContext_TypeDef *App_Context_Ptr)
{  
  App_Context_Ptr->Operating_Mode=NOMINAL;
  App_Context_Ptr->run_loop=1;
  
  /*Initializes app pointers to contextx*/
  App_Context_Ptr->Camera_ContextPtr=&CameraContext;
  App_Context_Ptr->Display_ContextPtr=&Display_Context;
  App_Context_Ptr->Utils_ContextPtr=&UtilsContext;
  App_Context_Ptr->Test_ContextPtr=&TestContext;
  App_Context_Ptr->People_ContextPtr=&People_Context;
  App_Context_Ptr->Preproc_ContextPtr=&Preproc_Context;
  
  /*Initializes app specific context's parameters */
  /**Camera**/
  App_Context_Ptr->Camera_ContextPtr->mirror_flip=CAMERA_MIRRORFLIP_FLIP;
  App_Context_Ptr->Camera_ContextPtr->AppCtxPtr =App_Context_Ptr;
  
  /**Utilities**/
  App_Context_Ptr->Utils_ContextPtr->AppCtxPtr =App_Context_Ptr;
  
  /**Test**/
  App_Context_Ptr->Test_ContextPtr->AppCtxPtr =App_Context_Ptr;
  strcpy(App_Context_Ptr->Test_ContextPtr->ValidationContext.class_path,"/onboard_valid_dataset_qvga_network/");

  /**Display**/
  App_Context_Ptr->Display_ContextPtr->AppCtxPtr =App_Context_Ptr;
  
  /**AI**/
  App_Context_Ptr->People_ContextPtr->AppCtxPtr =App_Context_Ptr;
  App_Context_Ptr->People_ContextPtr->nn_output_buffer=nn_output_buff;
  /*{scale,zero-point} set to {255,0} since YoloLC NN model was trained using input data normalized in the range [0, 255]*/
  App_Context_Ptr->People_ContextPtr->nn_input_norm_scale=255.0f;
  App_Context_Ptr->People_ContextPtr->nn_input_norm_zp=0;

  /**Preproc**/
  App_Context_Ptr->Preproc_ContextPtr->AppCtxPtr =App_Context_Ptr;
  App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.format=PXFMT_RGB888;
}

/**
 * @brief Initializes the application context structure
 * @param App_Context_Ptr pointer to application context
 */
void APP_Init(AppContext_TypeDef *App_Context_Ptr)
{

  App_Context_Init(App_Context_Ptr);
  Init_PeopleDataMemoryLayout(App_Context_Ptr);
  /* Patch ai_utilities.c to prevent image corruption during PFC */
  uint8_t *pfc_dst_end = (uint8_t *) App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData + PFC_OUTPUT_BUFFER_SIZE;
  App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData = pfc_dst_end - RESIZE_OUTPUT_BUFFER_SIZE;

}

/**
 * @brief Get the subsequent frame available and:
 *        1. send it to LCD for display
 *        2. make it available for subsequent processing
 * @param App_Context_Ptr pointer to application context
*/
void APP_GetNextReadyFrame(AppContext_TypeDef *App_Context_Ptr)
{
  ValidationContext_TypeDef* Validation_Ctx_Ptr=&App_Context_Ptr->Test_ContextPtr->ValidationContext;
  uint8_t* cam_capture_buff = App_Context_Ptr->Camera_ContextPtr->camera_capture_buffer;
#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
  uint8_t* cam_frame_buff = App_Context_Ptr->Camera_ContextPtr->camera_frame_buffer;
#endif
  
  if((App_Context_Ptr->Operating_Mode == VALID) && (Validation_Ctx_Ptr->validation_completed ==0))
  {
    TEST_GetNextValidationInput(App_Context_Ptr->Test_ContextPtr, 
                                cam_capture_buff);    
  } 
  else if((App_Context_Ptr->Operating_Mode == DUMP) && 
          (App_Context_Ptr->Test_ContextPtr->DumpContext.Dump_FrameSource == SDCARD_FILE))
  {
    TEST_GetNextDumpInput(App_Context_Ptr->Test_ContextPtr, 
                          cam_capture_buff);
  }
  else
  {
    /* Wait for current camera acquisition to complete*/
    while(App_Context_Ptr->Camera_ContextPtr->new_frame_ready == 0);
    UTILS_DCache_Coherency_Maintenance((void*)cam_capture_buff, CAM_FRAME_BUFFER_SIZE, INVALIDATE);
  }

  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
  DISPLAY_CameraCaptureBuffer(App_Context_Ptr->Display_ContextPtr, (uint16_t *)cam_capture_buff);

  /****Copy the camera_capture_buff buffer content onto the camera_frame_buff buffer so to release the camera capture buffer before triggering the subsequent camera frame capture****/
  for(uint32_t i=0;i<CAM_RES_WIDTH*CAM_RES_HEIGHT*RGB_565_BPP; i++)
  {
    *((uint8_t *)(cam_frame_buff + i)) = *((uint8_t *)(cam_capture_buff + i));
  }

}

/**
 * @brief Start the camera acquisition of the subsequent frame
 * @param App_Context_Ptr pointer to application context
*/
void APP_StartNewFrameAcquisition(AppContext_TypeDef *App_Context_Ptr)
{
  if(App_Context_Ptr->Operating_Mode == NOMINAL || 
     App_Context_Ptr->Operating_Mode == CAPTURE || 
       ((App_Context_Ptr->Operating_Mode == DUMP)&& (App_Context_Ptr->Test_ContextPtr->DumpContext.Dump_FrameSource != SDCARD_FILE)))
  {
 //   __disable_irq();
    App_Context_Ptr->Camera_ContextPtr->vsync_it=0;
    
    App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestart1=HAL_GetTick();
    
    App_Context_Ptr->Camera_ContextPtr->new_frame_ready = 0;
    
    /***Resume the camera capture in NOMINAL mode****/
    BSP_CAMERA_Resume(0);
  //  __enable_irq();
  }
}

/**
 * @brief Run preprocessing stages on captured frame
 * @param App_Context_Ptr pointer to application context
 */
void APP_FramePreprocess(AppContext_TypeDef *App_Context_Ptr)
{
  /*Call a fct in charge of executing the sequence of preprocessing steps*/
  Run_Preprocessing(App_Context_Ptr);
}


/**
 * @brief  Run post-processing operation
 * @param App_Context_Ptr pointer to application context
 */
void APP_Postprocess(AppContext_TypeDef *App_Context_Ptr)
{
  TestRunContext_TypeDef* TestRunCtxt_Ptr=&App_Context_Ptr->Test_ContextPtr->TestRunContext;

  /*** At that point, it is recommended to wait until current camera acquisition is completed before proceeding  
  *** before proceeding in order to avoid bottleneck at FMC slave (btw LTDC/DMA2D and DMA).
  ***/
  while(App_Context_Ptr->Camera_ContextPtr->new_frame_ready == 0);

  App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestop=HAL_GetTick();
  UTILS_Compute_ExecutionTiming(App_Context_Ptr->Utils_ContextPtr);


  TestRunCtxt_Ptr->src_buff_addr=(void *)(App_Context_Ptr->People_ContextPtr->nn_output_buffer);
  TestRunCtxt_Ptr->src_buff_name=Test_buffer_names[4];
  TestRunCtxt_Ptr->src_width_size=0;
  TestRunCtxt_Ptr->src_height_size=0;
  TestRunCtxt_Ptr->src_size=AI_NETWORK_OUT_1_SIZE * sizeof(float);
  TestRunCtxt_Ptr->PerformCapture=0;
  TestRunCtxt_Ptr->DumpFormat=TXT;
  TestRunCtxt_Ptr->rb_swap=0;
  TEST_Run(App_Context_Ptr->Test_ContextPtr, App_Context_Ptr->Operating_Mode);


  if(App_Context_Ptr->Operating_Mode == NOMINAL)
    {
      /*Display Neural Network output classification results as well as other performances informations*/
      App_Output_Display(App_Context_Ptr);

      BSP_LED_Toggle(LED_BLUE);
    }
    else
    {
      TEST_PostProcess(App_Context_Ptr->Test_ContextPtr);
    }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
