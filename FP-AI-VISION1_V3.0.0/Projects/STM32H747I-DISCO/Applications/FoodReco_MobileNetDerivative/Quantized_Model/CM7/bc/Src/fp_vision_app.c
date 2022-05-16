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
#include "main.h"
#include "fp_vision_app.h"
#include "ai_utilities.h"
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
  


float nn_output_buff[AI_NET_OUTPUT_SIZE] = {0};
 
const char* output_labels[AI_NET_OUTPUT_SIZE] = {
		"Background", "Sensor tile", "Craddle", "IoT Node", "Fan", "Grasshoper"   };

/* Private function prototypes -----------------------------------------------*/
static void CameraCaptureBuff2LcdBuff_Copy(AppContext_TypeDef *);
static void App_Output_Display(AppContext_TypeDef *);
static void App_Context_Init(AppContext_TypeDef *);

/* Functions Definition ------------------------------------------------------*/

/**
 * @brief  Transfer from camera frame buffer to LCD frame buffer for display
 * @param App_Context_Ptr pointer to application context
 */
static void CameraCaptureBuff2LcdBuff_Copy(AppContext_TypeDef *App_Context_Ptr)
{
  int red_blue_swap=0;
  
  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
  
  if((App_Context_Ptr->Operating_Mode == DUMP)&& (App_Context_Ptr->Test_ContextPtr->DumpContext.Dump_FrameSource == SDCARD_FILE))
  {
    /*When reading bmp file, swapping R & B is not required since B component in bmp 888 file is at "@ + 0"  and DMA2D is expected B to be at "@ + 0". Same for 565, compoent are stored in the same way as DMA2D is expected */
    /*When reading ppm file, swapping R & B is  required since B component in bmp 888 file is at "@ + 2"  and DMA2D is expected B to be at "@ + 0"*/
    red_blue_swap=0;
    
    /*In VALID mode, the files are always in BMP 16bpp format => red_blue_swap =0*/
  }
  
  if(App_Context_Ptr->Operating_Mode == VALID || ((App_Context_Ptr->Operating_Mode == DUMP)&& (App_Context_Ptr->Test_ContextPtr->DumpContext.Dump_FrameSource == SDCARD_FILE)))
  {
    /*Coherency purpose: clean the source buffer area in L1 D-Cache before DMA2D reading*/
    UTILS_DCache_Coherency_Maintenance((void *)App_Context_Ptr->Camera_ContextPtr->camera_capture_buffer,
                                       CAM_RES_WIDTH*CAM_RES_HEIGHT*RGB_565_BPP/*since format of BMP files on SDCard is 16-bpp*/, 
                                       CLEAN);
  }
  
  if(App_Context_Ptr->Operating_Mode == VALID)
  {       
    /*224x224 is the size of the image that is displayed on the LCD in VALID mode*/
    if((CAM_RES_WIDTH != 224) && (CAM_RES_HEIGHT != 224))
    {
      /*Copy from Camera capture buffer to temp buffer "valid_image_buff" in external memory, and perform a PFC (565 to 888) at the same time*/
      UTILS_Dma2d_Memcpy((uint32_t *)(App_Context_Ptr->Camera_ContextPtr->camera_capture_buffer), 
                         (uint32_t *)(valid_image_buff), 
                         0, 
                         0, 
                         CAM_RES_WIDTH, CAM_RES_HEIGHT, 
                         CAM_RES_WIDTH, 
                         DMA2D_INPUT_RGB565, 
                         DMA2D_OUTPUT_RGB888, 
                         1, 
                         0);
      
      /*Coherency purpose: Invalidate the source buffer area in L1 D-Cache before CPU reading*/
      UTILS_DCache_Coherency_Maintenance((void *)valid_image_buff, CAM_RES_WIDTH*CAM_RES_HEIGHT*RGB_888_BPP, INVALIDATE);
      
      App_Context_Ptr->Preproc_ContextPtr->Resize_Src_Img.pData=valid_image_buff;
      App_Context_Ptr->Preproc_ContextPtr->Resize_Src_Img.width=CAM_RES_WIDTH;
      App_Context_Ptr->Preproc_ContextPtr->Resize_Src_Img.height=CAM_RES_HEIGHT;
      App_Context_Ptr->Preproc_ContextPtr->Resize_Src_Img.format=PXFMT_RGB888;
      App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData=valid_image_buff;
      App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.width=224;
      App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.height=224;
      App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.format=PXFMT_RGB888;
      App_Context_Ptr->Preproc_ContextPtr->Roi.x0=0;
      App_Context_Ptr->Preproc_ContextPtr->Roi.y0=0;
      App_Context_Ptr->Preproc_ContextPtr->Roi.width=0;
      App_Context_Ptr->Preproc_ContextPtr->Roi.height=0;
      
      /* Resize the image (read from SDCard) to 224x224 : use NearestNeighbor method so to always do the resize "in-place" */
      ImageResize_NearestNeighbor(&App_Context_Ptr->Preproc_ContextPtr->Resize_Src_Img, 
                                  &App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img,
                                  &App_Context_Ptr->Preproc_ContextPtr->Roi);  
      
      /*Coherency purpose: clean the source buffer area in L1 D-Cache before DMA2D reading*/
      UTILS_DCache_Coherency_Maintenance((void *)valid_image_buff, CAM_RES_WIDTH*CAM_RES_HEIGHT*RGB_888_BPP, CLEAN);
      
      /*DMA2D transfer from temp buffer "valid_image_buff" in external memory to LCD write buffer*/
      DISPLAY_Copy2LCDWriteBuffer(App_Context_Ptr->Display_ContextPtr, (uint32_t *)(valid_image_buff), 50,
                               130, 224, 224, DMA2D_INPUT_RGB888,
                               red_blue_swap);
    }   
  }
  else
  { 
    /*DMA2D transfer from Camera capture buffer to LCD write buffer*/
    DISPLAY_Copy2LCDWriteBuffer(App_Context_Ptr->Display_ContextPtr, (uint32_t *)(App_Context_Ptr->Camera_ContextPtr->camera_capture_buffer), 
                                (LCD_RES_WIDTH - CAM_RES_WIDTH) >> 1, 
                                (LCD_RES_HEIGHT - CAM_RES_HEIGHT) >> 1, 
                                CAM_RES_WIDTH, 
                                CAM_RES_HEIGHT, 
                                DMA2D_INPUT_RGB565,
                                red_blue_swap);
  }
}

/**
 * @brief Process the output from NN and display it on LCD and LED
 * @param App_Context_Ptr pointer to application context
 */
static void App_Output_Display(AppContext_TypeDef *App_Context_Ptr)
{
  static uint32_t occurrence_number = NN_OUTPUT_DISPLAY_REFRESH_RATE;
  static uint32_t display_mode=1;//by default, normal mode i.e. logo is displayed
  uint8_t myTest;

  occurrence_number--;

  if (occurrence_number == 0)
  {
    char msg[70];

    occurrence_number = NN_OUTPUT_DISPLAY_REFRESH_RATE;
    
    /*Check if PB is pressed*/
    if (BSP_PB_GetState(BUTTON_WAKEUP) != RESET)
    {
      display_mode = !display_mode;
      
      UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
      
      if (display_mode == 1)
      {
        sprintf(msg, "Entering CAMERA PREVIEW mode");
      }
      else  if (display_mode == 0)
      {
        sprintf(msg, "Exiting CAMERA PREVIEW mode");
      }
      
      UTIL_LCD_DisplayStringAt(0, LINE(9), (uint8_t*)msg, CENTER_MODE);
      
      sprintf(msg, "Please release button");
      UTIL_LCD_DisplayStringAt(0, LINE(11), (uint8_t*)msg, CENTER_MODE);
      DISPLAY_Refresh(App_Context_Ptr->Display_ContextPtr);
      
      /*Wait for PB release*/
      while (BSP_PB_GetState(BUTTON_WAKEUP) != RESET);
      HAL_Delay(200);
      
      UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
    }
    
    if (display_mode == 0)
    {
      UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);/*To clear the camera capture*/
      
      DISPLAY_FoodLogo(App_Context_Ptr->Display_ContextPtr, LCD_RES_WIDTH / 2 - 64, LCD_RES_HEIGHT / 2 -100, App_Context_Ptr->ranking[0]);
    }
    else  if (display_mode == 1)
    {      
      sprintf(msg, "CAMERA PREVIEW MODE");
      
      UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_ACQU_MODE_LINE), (uint8_t*)msg, CENTER_MODE);
    }
  
    for (int i = 0; i < NN_TOP_N_DISPLAY; i++)
    {
      sprintf(msg, "%s %.0f%%", NN_OUTPUT_CLASS_LIST[App_Context_Ptr->ranking[i]], *((float*)(App_Context_Ptr->Ai_ContextPtr->nn_output_buffer)+i) * 100);
      UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_TOP_N_LAST_LINE - NN_TOP_N_DISPLAY + i), (uint8_t *)msg, CENTER_MODE);
      myTest = App_Context_Ptr->ranking[i];
    }

    sprintf(msg, "Inference: %ldms", App_Context_Ptr->nn_inference_time);
    UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_INFER_TIME_LINE), (uint8_t *)msg, CENTER_MODE);

    sprintf(msg, "Fps: %.1f", 1000.0F / (float)(App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.Tfps));
    UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_FPS_LINE), (uint8_t *)msg, CENTER_MODE);

    DISPLAY_Refresh(App_Context_Ptr->Display_ContextPtr);

    /*Toggle LED based on result confidence*/
    BSP_LED_Off(LED_GREEN);
    BSP_LED_Off(LED_ORANGE);
    BSP_LED_Off(LED_RED);

    if ((*((float*)(App_Context_Ptr->Ai_ContextPtr->nn_output_buffer)+0) * 100) < NN_BAD_RES)
    {
      myTest=6;
      BSP_LED_On(LED_RED);
      AudioPlay_demo(myTest);
    }
    else if (((*((float*)(App_Context_Ptr->Ai_ContextPtr->nn_output_buffer)+0) * 100) >= NN_BAD_RES) && ((*((float*)(App_Context_Ptr->Ai_ContextPtr->nn_output_buffer)+0) * 100) < NN_GOOD_RES))
    {
      BSP_LED_On(LED_ORANGE);
      AudioPlay_demo(myTest);
    }
    else
    {
      BSP_LED_On(LED_GREEN);

    	  AudioPlay_demo(myTest);
    }
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
  App_Context_Ptr->Ai_ContextPtr=&Ai_Context;
  App_Context_Ptr->Preproc_ContextPtr=&Preproc_Context;
  
  /*Initializes app specific context's parameters */
  /**Camera**/
  App_Context_Ptr->Camera_ContextPtr->mirror_flip=CAMERA_MIRRORFLIP_NONE;
  App_Context_Ptr->Camera_ContextPtr->AppCtxPtr =App_Context_Ptr;
  
  /**Utilities**/
  App_Context_Ptr->Utils_ContextPtr->AppCtxPtr =App_Context_Ptr;
  
  /**Test**/
  App_Context_Ptr->Test_ContextPtr->AppCtxPtr =App_Context_Ptr;
#if CAMERA_CAPTURE_RES == VGA_640_480_RES
  strcpy(App_Context_Ptr->Test_ContextPtr->ValidationContext.class_path,"/onboard_valid_dataset_vga/");
#elif CAMERA_CAPTURE_RES == QVGA_320_240_RES
  strcpy(App_Context_Ptr->Test_ContextPtr->ValidationContext.class_path,"/onboard_valid_dataset_qvga/");
#endif
  
  /**Display**/
  App_Context_Ptr->Display_ContextPtr->AppCtxPtr =App_Context_Ptr;
  
  /**AI**/
  App_Context_Ptr->Ai_ContextPtr->AppCtxPtr =App_Context_Ptr;
  App_Context_Ptr->Ai_ContextPtr->nn_output_buffer=nn_output_buff;
  /*{scale,zero-point} set to {255,0} since Food Reco NN model was trained using input data normalized in the range [0, 1]*/
  App_Context_Ptr->Ai_ContextPtr->nn_input_norm_scale=255.0f;
  App_Context_Ptr->Ai_ContextPtr->nn_input_norm_zp=0;

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
  Init_DataMemoryLayout(App_Context_Ptr);
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
  }
  
  /* DMA2D transfer from camera frame buffer to LCD write buffer */
  CameraCaptureBuff2LcdBuff_Copy(App_Context_Ptr);
  
#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT  
  if(App_Context_Ptr->Operating_Mode != VALID)
  {
    /****Coherency purpose: invalidate the camera_capture_buffer area in L1 D-Cache before CPU reading****/
    UTILS_DCache_Coherency_Maintenance((void*)cam_capture_buff, 
                                       CAM_FRAME_BUFFER_SIZE, INVALIDATE);
  }
  
  /****Copy the camera_capture_buff buffer content onto the camera_frame_buff buffer so to release the camera capture buffer before triggering the subsequent camera frame capture****/
  for(uint32_t i=0;i<CAM_RES_WIDTH*CAM_RES_HEIGHT*RGB_565_BPP; i++)
  {
    *((uint8_t *)(cam_frame_buff + i)) = *((uint8_t *)(cam_capture_buff + i));
  }
#endif
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
 * @brief Run neural network inference on preprocessed captured frame
 * @param App_Context_Ptr pointer to application context
 */
void APP_NetworkInference(AppContext_TypeDef *App_Context_Ptr)
{
  uint32_t tinf_start;
  uint32_t tinf_stop;
  TestRunContext_TypeDef* TestRunCtxt_Ptr=&App_Context_Ptr->Test_ContextPtr->TestRunContext;
  
  TestRunCtxt_Ptr->src_buff_addr=(void *)(App_Context_Ptr->Ai_ContextPtr->nn_input_buffer);
  TestRunCtxt_Ptr->src_buff_name=Test_buffer_names[3];
  TestRunCtxt_Ptr->src_width_size=ai_get_input_width();
  TestRunCtxt_Ptr->src_height_size=ai_get_input_height();
  TestRunCtxt_Ptr->src_size=AI_NET_INPUT_SIZE;
  TestRunCtxt_Ptr->PerformCapture=1;
  TestRunCtxt_Ptr->DumpFormat=BMP888;
  TestRunCtxt_Ptr->rb_swap=1;
  TEST_Run(App_Context_Ptr->Test_ContextPtr, App_Context_Ptr->Operating_Mode);
 
  tinf_start=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);
  
  /***********************************/
  /*********Run NN inference**********/
  /***********************************/
  AI_Run(App_Context_Ptr->Ai_ContextPtr);
  
  tinf_stop=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);

  App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.operation_exec_time[FRAME_INFERENCE]=tinf_stop-tinf_start;
}

/**
 * @brief Run post-processing operation
 * @param App_Context_Ptr pointer to application context
 */
void APP_Postprocess(AppContext_TypeDef *App_Context_Ptr)
{
  TestRunContext_TypeDef* TestRunCtxt_Ptr=&App_Context_Ptr->Test_ContextPtr->TestRunContext;

  /*** At that point, it is recommended to wait until current camera acquisition is completed before proceeding  
  *** before proceeding in order to avoid bottleneck at FMC slave (btw LTDC/DMA2D and DMA).
  ***/
  while(App_Context_Ptr->Camera_ContextPtr->new_frame_ready == 0);
  
  UTILS_Compute_ExecutionTiming(App_Context_Ptr->Utils_ContextPtr);
  
  /**NN ouput dequantization if required**/
  AI_Output_Dequantize(App_Context_Ptr->Ai_ContextPtr);

  TestRunCtxt_Ptr->src_buff_addr=(void *)(App_Context_Ptr->Ai_ContextPtr->nn_output_buffer);
  TestRunCtxt_Ptr->src_buff_name=Test_buffer_names[4];
  TestRunCtxt_Ptr->src_width_size=0;
  TestRunCtxt_Ptr->src_height_size=0;
  TestRunCtxt_Ptr->src_size=/*AI_NETWORK_OUT_1_SIZE*/AI_NETWORK_OUT_1_SIZE_BYTES;//so to make it compatible w/ case where dump is in SDRAM
  TestRunCtxt_Ptr->PerformCapture=0;
  TestRunCtxt_Ptr->DumpFormat=TXT;
  TestRunCtxt_Ptr->rb_swap=0;
  TEST_Run(App_Context_Ptr->Test_ContextPtr, App_Context_Ptr->Operating_Mode);

  /**Perform ranking**/
  for (int i = 0; i < NN_OUTPUT_CLASS_NUMBER; i++)
  {
    App_Context_Ptr->ranking[i] = i;
  }
  
  UTILS_Bubblesort((float*)(App_Context_Ptr->Ai_ContextPtr->nn_output_buffer), App_Context_Ptr->ranking, NN_OUTPUT_CLASS_NUMBER);
  
  App_Context_Ptr->nn_top1_output_class_name=NN_OUTPUT_CLASS_LIST[App_Context_Ptr->ranking[0]];
  App_Context_Ptr->nn_top1_output_class_proba=*((float*)(App_Context_Ptr->Ai_ContextPtr->nn_output_buffer)+0);
  
  if(App_Context_Ptr->Operating_Mode == NOMINAL)
  {
    /*Display Neural Network output classification results as well as other performances informations*/
    App_Output_Display(App_Context_Ptr);
    

    //BSP_LED_Toggle(LED_BLUE);
    //AudioPlay_demo();

  }
  else 
  {
    TEST_PostProcess(App_Context_Ptr->Test_ContextPtr);
  }
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
