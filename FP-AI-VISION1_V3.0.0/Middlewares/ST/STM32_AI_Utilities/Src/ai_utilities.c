/**
 ******************************************************************************
 * @file    ai_utilities.c
 * @author  MCD Application Team
 * @brief   Module containing optimized functions
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
#include "ai_utilities.h"

/** @addtogroup Middlewares
  * @{
  */

/** @addtogroup STM32_AI_Utilities
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
static DataFormat_TypeDef get_dump_format(Image_TypeDef *img);

/* Functions Definition ------------------------------------------------------*/
/**
* @brief Initializes the application data memory layout
* @param  Pointer to Application context
*/
void Init_DataMemoryLayout(AppContext_TypeDef *App_Context_Ptr)
{  
#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
 /*Offset so to "bottom" align camera_frame_buff buffer and resize_output_buff buffer*/
 #define  RESIZE_OUTPUT_BUFFER_OFFSET (CAM_FRAME_BUFFER_SIZE - RESIZE_OUTPUT_BUFFER_SIZE) 
  App_Context_Ptr->Camera_ContextPtr->camera_capture_buffer = ai_fp_global_memory;
  App_Context_Ptr->Camera_ContextPtr->camera_frame_buffer = ai_fp_global_memory;
  App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData = ai_fp_global_memory;
  App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData = ai_fp_global_memory + RESIZE_OUTPUT_BUFFER_OFFSET;
  App_Context_Ptr->Ai_ContextPtr->activation_buffer = ai_fp_global_memory;
  #ifdef AI_NETWORK_INPUTS_IN_ACTIVATIONS
   /*Initialized to NULL since input buffer is allocated within activation buffer ==> its size does not need to be taken into account*/  
   App_Context_Ptr->Ai_ContextPtr->nn_input_buffer = NULL;
  #else
   App_Context_Ptr->Ai_ContextPtr->nn_input_buffer = ai_fp_global_memory + AI_ACTIVATION_BUFFER_SIZE;
  #endif
#elif MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
  App_Context_Ptr->Camera_ContextPtr->camera_capture_buffer = ai_fp_global_memory;
  App_Context_Ptr->Camera_ContextPtr->camera_frame_buffer = ai_fp_global_memory + CAM_FRAME_BUFFER_SIZE;
 #if MEMORY_SCHEME == SPLIT_INT_EXT
  /*Offset so to "bottom" align pfc_output_buff buffer and resize_output_buff buffer*/
  #define  RESIZE_OUTPUT_BUFFER_OFFSET (PFC_OUTPUT_BUFFER_SIZE - RESIZE_OUTPUT_BUFFER_SIZE) 
  App_Context_Ptr->Ai_ContextPtr->activation_buffer = ai_fp_activation_memory;
  App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData = ai_fp_activation_memory;
  App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData = ai_fp_activation_memory + RESIZE_OUTPUT_BUFFER_OFFSET;
  #ifdef AI_NETWORK_INPUTS_IN_ACTIVATIONS
   /*Initialized to NULL since input buffer is allocated within activation buffer ==> its size does not need to be taken into account*/  
   App_Context_Ptr->Ai_ContextPtr->nn_input_buffer = NULL;
  #else
   App_Context_Ptr->Ai_ContextPtr->nn_input_buffer = ai_fp_global_memory + CAM_FRAME_BUFFER_SIZE;
  #endif
 #else /*MEMORY_SCHEME == FULL_EXTERNAL*/
  /*Offset so to "bottom" align camera_frame_buff buffer and resize_output_buff buffer*/
  #define  RESIZE_OUTPUT_BUFFER_OFFSET (CAM_FRAME_BUFFER_SIZE - RESIZE_OUTPUT_BUFFER_SIZE) 
  App_Context_Ptr->Ai_ContextPtr->activation_buffer  = ai_fp_global_memory + CAM_FRAME_BUFFER_SIZE;
  App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData = ai_fp_global_memory + CAM_FRAME_BUFFER_SIZE;
  App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData = ai_fp_global_memory + CAM_FRAME_BUFFER_SIZE + RESIZE_OUTPUT_BUFFER_OFFSET;
  #ifdef AI_NETWORK_INPUTS_IN_ACTIVATIONS
   /*Initialized to NULL since input buffer is allocated within activation buffer ==> its size does not need to be taken into account*/  
   App_Context_Ptr->Ai_ContextPtr->nn_input_buffer = NULL;
  #else
   App_Context_Ptr->Ai_ContextPtr->nn_input_buffer = ai_fp_global_memory + CAM_FRAME_BUFFER_SIZE + AI_ACTIVATION_BUFFER_SIZE;
  #endif
 #endif
#else
 #error Please check definition of MEMORY_SCHEME define
#endif
}

/**
* @brief  Run preprocessing stages on captured frame
* @param  App context ptr
* @retval None
*/
void Run_Preprocessing(AppContext_TypeDef *App_Context_Ptr)
{
  uint32_t tpfc_start;
  uint32_t tpfc_stop;
  uint32_t tresize_start;
  uint32_t tresize_stop;
  uint32_t tpvc_start;
  uint32_t tpvc_stop;
  TestRunContext_TypeDef* TestRunCtxt_Ptr=&App_Context_Ptr->Test_ContextPtr->TestRunContext;
  PreprocContext_TypeDef* PreprocCtxt_Ptr=App_Context_Ptr->Preproc_ContextPtr;
  
#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT   
  
  if(App_Context_Ptr->Operating_Mode != VALID)
  {
    /*********************************************************************************************/
    /****Coherency purpose: invalidate the source buffer area in L1 D-Cache before CPU reading****/
    /*********************************************************************************************/
    UTILS_DCache_Coherency_Maintenance((void *)(App_Context_Ptr->Camera_ContextPtr->camera_frame_buffer), CAM_FRAME_BUFFER_SIZE, INVALIDATE);
  }
#endif
  
  TestRunCtxt_Ptr->src_buff_addr=(void *)(App_Context_Ptr->Camera_ContextPtr->camera_frame_buffer);
  TestRunCtxt_Ptr->src_buff_name=Test_buffer_names[0];
  TestRunCtxt_Ptr->src_width_size=CAM_RES_WIDTH;
  TestRunCtxt_Ptr->src_height_size=CAM_RES_HEIGHT;
  TestRunCtxt_Ptr->src_size=CAM_FRAME_BUFFER_SIZE;
  TestRunCtxt_Ptr->PerformCapture=1;
  TestRunCtxt_Ptr->DumpFormat=BMP565;
  TestRunCtxt_Ptr->rb_swap=0;
  TEST_Run(App_Context_Ptr->Test_ContextPtr, App_Context_Ptr->Operating_Mode);
  
  tresize_start=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);
  
  /**********************/
  /****Image resizing****/
  /**********************/
  PreprocCtxt_Ptr->Resize_Src_Img.pData=App_Context_Ptr->Camera_ContextPtr->camera_frame_buffer;
  PreprocCtxt_Ptr->Resize_Src_Img.width=CAM_RES_WIDTH;
  PreprocCtxt_Ptr->Resize_Src_Img.height=CAM_RES_HEIGHT;
  PreprocCtxt_Ptr->Resize_Src_Img.format=PXFMT_RGB565;
  PreprocCtxt_Ptr->Resize_Dst_Img.pData=App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData;
  PreprocCtxt_Ptr->Resize_Dst_Img.width=App_Context_Ptr->Ai_ContextPtr->nn_width;
  PreprocCtxt_Ptr->Resize_Dst_Img.height=App_Context_Ptr->Ai_ContextPtr->nn_height;
  PreprocCtxt_Ptr->Resize_Dst_Img.format=PXFMT_RGB565;
  PreprocCtxt_Ptr->Roi.x0=0;
  PreprocCtxt_Ptr->Roi.y0=0;
  PreprocCtxt_Ptr->Roi.width=0;
  PreprocCtxt_Ptr->Roi.height=0;
  PREPROC_ImageResize(App_Context_Ptr->Preproc_ContextPtr);
  
  tresize_stop=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);
  
#if PIXEL_FMT_CONV == HW_PFC
  /******************************************************************************************/
  /****Coherency purpose: clean the source buffer area in L1 D-Cache before DMA2D reading****/
  /******************************************************************************************/
  UTILS_DCache_Coherency_Maintenance((void *)(App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData), RESIZE_OUTPUT_BUFFER_SIZE, CLEAN);
#endif
  
  TestRunCtxt_Ptr->src_buff_addr=(void *)(App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData);
  TestRunCtxt_Ptr->src_buff_name=Test_buffer_names[1];
  TestRunCtxt_Ptr->src_width_size=ai_get_input_width();
  TestRunCtxt_Ptr->src_height_size=ai_get_input_height();
  TestRunCtxt_Ptr->src_size=RESIZE_OUTPUT_BUFFER_SIZE;
  TestRunCtxt_Ptr->PerformCapture=0;
  TestRunCtxt_Ptr->DumpFormat=get_dump_format(&App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img);
  TestRunCtxt_Ptr->rb_swap=0;
  TEST_Run(App_Context_Ptr->Test_ContextPtr, App_Context_Ptr->Operating_Mode);
  
  tpfc_start=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);
  
  /*************************************/
  /****Image Pixel Format Conversion****/
  /*************************************/
  PreprocCtxt_Ptr->Pfc_Src_Img.pData=App_Context_Ptr->Preproc_ContextPtr->Resize_Dst_Img.pData;
  PreprocCtxt_Ptr->Pfc_Src_Img.width=App_Context_Ptr->Ai_ContextPtr->nn_width;
  PreprocCtxt_Ptr->Pfc_Src_Img.height=App_Context_Ptr->Ai_ContextPtr->nn_height;
  PreprocCtxt_Ptr->Pfc_Src_Img.format=PXFMT_RGB565;
  PreprocCtxt_Ptr->Pfc_Dst_Img.pData=App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData;
  PreprocCtxt_Ptr->Pfc_Dst_Img.width=App_Context_Ptr->Ai_ContextPtr->nn_width;
  PreprocCtxt_Ptr->Pfc_Dst_Img.height=App_Context_Ptr->Ai_ContextPtr->nn_height;
  PreprocCtxt_Ptr->Dma2dcfg.x=0;
  PreprocCtxt_Ptr->Dma2dcfg.y=0;
  PreprocCtxt_Ptr->Dma2dcfg.rowStride=App_Context_Ptr->Ai_ContextPtr->nn_width;
  PreprocCtxt_Ptr->red_blue_swap=1;
  PREPROC_PixelFormatConversion(App_Context_Ptr->Preproc_ContextPtr);
  
  tpfc_stop=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);
  
#if PIXEL_FMT_CONV == HW_PFC 
  /**************************************************************************************/
  /****Coherency purpose: invalidate the source area in L1 D-Cache before CPU reading****/  
  /**************************************************************************************/
  UTILS_DCache_Coherency_Maintenance((void *)(App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData), 
                                     PFC_OUTPUT_BUFFER_SIZE, 
                                     INVALIDATE);
#endif
  
  TestRunCtxt_Ptr->src_buff_addr=(void *)(App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData);
  TestRunCtxt_Ptr->src_buff_name=Test_buffer_names[2];
  TestRunCtxt_Ptr->src_width_size=ai_get_input_width();
  TestRunCtxt_Ptr->src_height_size=ai_get_input_height();
  TestRunCtxt_Ptr->src_size=PFC_OUTPUT_BUFFER_SIZE;
  TestRunCtxt_Ptr->PerformCapture=0;
  TestRunCtxt_Ptr->DumpFormat=get_dump_format(&App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img);
  TestRunCtxt_Ptr->rb_swap=1;
  TEST_Run(App_Context_Ptr->Test_ContextPtr, App_Context_Ptr->Operating_Mode);

  tpvc_start=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);
  
  /***********************************************************/
  /*********Pixel value convertion and normalisation**********/
  /***********************************************************/
  AI_PixelValueConversion(App_Context_Ptr->Ai_ContextPtr, 
                                      (void*)(App_Context_Ptr->Preproc_ContextPtr->Pfc_Dst_Img.pData));
  
  tpvc_stop=UTILS_GetTimeStamp(App_Context_Ptr->Utils_ContextPtr);
  
  TestRunCtxt_Ptr->src_buff_addr=(void *)(NULL);
  TestRunCtxt_Ptr->src_buff_name="";
  TestRunCtxt_Ptr->src_width_size=0;
  TestRunCtxt_Ptr->src_height_size=0;
  TestRunCtxt_Ptr->src_size=0;
  TestRunCtxt_Ptr->PerformCapture=0;
  TestRunCtxt_Ptr->DumpFormat=RAW;
  TestRunCtxt_Ptr->rb_swap=0;
  TEST_Run(App_Context_Ptr->Test_ContextPtr, App_Context_Ptr->Operating_Mode);
  
  App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.operation_exec_time[FRAME_PFC]=tpfc_stop-tpfc_start;
  App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.operation_exec_time[FRAME_RESIZE]=tresize_stop-tresize_start;
  App_Context_Ptr->Utils_ContextPtr->ExecTimingContext.operation_exec_time[FRAME_PVC]=tpvc_stop-tpvc_start;
}

/**
* @brief  Performs image (or selected Region Of Interest) resizing using Nearest Neighbor interpolation algorithm
* @param  srcImage     Pointer to source image buffer
* @param  srcW         Source image width
* @param  srcH         Source image height
* @param  pixelSize    Number of bytes per pixel
* @param  roiX         Region Of Interest x starting location 
* @param  roiY         Region Of Interest y starting location
* @param  roiW         Region Of Interest width
* @param  roiH         Region Of Interest height
* @param  dstImage     Pointer to destination image buffer
* @param  dstW         Destination image width
* @param  dstH         Destination image height
* @param  Top2Bottom   Value of 1/0 indicates that the rescales performs from the top/bottom to the bottom/top of the buffers
* @retval void         None
*/
void Resize_Frame(Image_TypeDef *srcImage, Image_TypeDef *dstImage, Roi_TypeDef *roi)
{
  int x_ratio = (int)(((roi->width ? roi->width : srcImage->width)<<16)/dstImage->width)+1;
  int y_ratio = (int)(((roi->height ? roi->height : srcImage->height)<<16)/dstImage->height)+1;
  uint32_t pixelSize=IMG_BYTES_PER_PX(srcImage->format);
  uint32_t Top2Bottom;
  
  Top2Bottom=Image_CheckResizeMemoryLayout(srcImage, dstImage);
  
  if(Top2Bottom == 0)
  {
    for (int y=dstImage->height-1, i=(dstImage->width*dstImage->height*pixelSize -2  ); y>=0; y--)
    {
      int sy = (y*y_ratio)>>16;
      for (int x=dstImage->width-1; x>=0; x--, i-=pixelSize)
      {
        int sx = (x*x_ratio)>>16;
        
        for(int j=0; j<pixelSize; j++)
        {
          *((uint8_t*)dstImage->pData + i + j) = *((uint8_t*)srcImage->pData + (((sy+roi->y0)*srcImage->width) + (sx+roi->x0))*pixelSize + j);//(uint8_t) srcImage->pData[];
        }
      }
    }
  }
  else if(Top2Bottom == 1)
  {
    
    for (int y=0, i=0; y<dstImage->height; y++)
    {
      int sy = (y*y_ratio)>>16;
      for (int x=0; x<dstImage->width; x++, i+=pixelSize)
      {
        int sx = (x*x_ratio)>>16;
        
        for(int j=0; j<pixelSize; j++)
        {
          *((uint8_t*)dstImage->pData + i + j) =  *((uint8_t*)srcImage->pData +(((sy+roi->y0)*srcImage->width) + (sx+roi->x0))*pixelSize + j);
        }
      }
    }
  }
}

/**
 * @brief Get the dump format from image object
 *
 * @param img pointer to image object
 * @return DataFormat_TypeDef image dump format
 */
static DataFormat_TypeDef get_dump_format(Image_TypeDef *img)
{
  switch (img->format)
  {
  case PXFMT_GRAY8:
    return GRAY8;

  case PXFMT_RGB565:
    return BMP565;

  case PXFMT_RGB888:
    return BMP888;

  default:
    /* Use raw format for pixel formats not support by fp_vision_test.c */
    return RAW;
  }
}

/**
  * @}
  */

/**
  * @}
  */
///************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
