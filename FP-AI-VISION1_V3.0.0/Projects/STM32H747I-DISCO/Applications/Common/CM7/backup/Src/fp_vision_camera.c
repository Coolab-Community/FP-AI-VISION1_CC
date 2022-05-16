/**
 ******************************************************************************
 * @file    fp_vision_camera.c
 * @author  MCD Application Team
 * @brief   Library to manage camera related operation
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
#include "fp_vision_camera.h"

/* Global variables ----------------------------------------------------------*/
CameraContext_TypeDef CameraContext;
MDMA_HandleTypeDef hmdma;

/* Private defines -----------------------------------------------------------*/

#define CAM_LINE_SIZE  (CAM_RES_WIDTH * 2U) /* 640 or 480 px with 16-bit per px in RGB565 */

/* Private variables ---------------------------------------------------------*/
static uint8_t pCameraLineBuffer[CAM_LINE_SIZE] __attribute__ ((section(".camera_line_buffer")));

/* Private function prototypes -----------------------------------------------*/
HAL_StatusTypeDef HAL_DCMIEx_Start_DMA_MDMA(DCMI_HandleTypeDef *hdcmi, uint32_t DCMI_Mode, uint8_t *pData,
                                            uint32_t line_size, uint32_t num_lines);
static void DCMI_DMALineXferCplt(DMA_HandleTypeDef *hdma);
static void DCMI_DMAError(DMA_HandleTypeDef *hdma);
static void DCMI_MDMAFrameXferCplt(MDMA_HandleTypeDef *hmdma);
static void DCMI_MDMAError(MDMA_HandleTypeDef *hmdma);

/**
 * @brief Initializes the camera context structure
 * @param  Camera_Context_Ptr Pointer to camera context
 */
void CAMERA_Context_Init(CameraContext_TypeDef *Camera_Context_Ptr)
{
  Camera_Context_Ptr->new_frame_ready=0;
  Camera_Context_Ptr->Tframe_evt=0;
  Camera_Context_Ptr->Tvsync_evt=0;
  Camera_Context_Ptr->vsync_it=0;
  Camera_Context_Ptr->mirror_flip=1;
}

/**
 * @brief  CAMERA Initialization
 * @param  Camera_Context_Ptr Pointer to camera context
 * @retval None
 */
void CAMERA_Init(CameraContext_TypeDef* Camera_Context_Ptr)
{
  CAMERA_Context_Init(Camera_Context_Ptr);

  __HAL_RCC_MDMA_CLK_ENABLE();

  /* Init MDMA for camera line buffer to frame buffer copy */
  hmdma.Instance = MDMA_Channel0;
  hmdma.Init.Request                  = MDMA_REQUEST_SW;
  hmdma.Init.TransferTriggerMode      = MDMA_BLOCK_TRANSFER;
  hmdma.Init.Priority                 = MDMA_PRIORITY_HIGH;
  hmdma.Init.Endianness               = MDMA_LITTLE_ENDIANNESS_PRESERVE;
  hmdma.Init.SourceInc                = MDMA_SRC_INC_WORD;
  hmdma.Init.DestinationInc           = MDMA_DEST_INC_WORD;
  hmdma.Init.SourceDataSize           = MDMA_SRC_DATASIZE_WORD;
  hmdma.Init.DestDataSize             = MDMA_DEST_DATASIZE_WORD;
  hmdma.Init.DataAlignment            = MDMA_DATAALIGN_PACKENABLE;
  hmdma.Init.SourceBurst              = MDMA_DEST_BURST_SINGLE;
  hmdma.Init.DestBurst                = MDMA_DEST_BURST_16BEATS;
  hmdma.Init.BufferTransferLength     = 128;
  hmdma.Init.SourceBlockAddressOffset = 0;
  hmdma.Init.DestBlockAddressOffset   = 0;
  if (HAL_MDMA_Init(&hmdma) != HAL_OK)
  {
    Error_Handler();
  }

  /* NVIC configuration for MDMA transfer complete interrupt */
  HAL_NVIC_SetPriority(MDMA_IRQn, 15U, 0);
  HAL_NVIC_EnableIRQ(MDMA_IRQn);

  /* Reset and power down camera to be sure camera is Off prior start */
  BSP_CAMERA_PwrDown(0);
  
  /* Wait delay */ 
  HAL_Delay(200);
  
  /* Initialize the Camera */
  if (BSP_CAMERA_Init(0, CAMERA_RESOLUTION, CAMERA_PF_RGB565) != BSP_ERROR_NONE) 
  {
    Error_Handler();
  }

  /* Set OV5640 pixel clock (PCLK) to 48MHz and get a 30fps camera frame rate */
  if (Camera_Ctx[0].CameraId == OV5640_ID)
  {
    OV5640_Object_t *pObj = Camera_CompObj;
    uint8_t tmp = 0xC0; /* Bits[7:0]: PLL multiplier */
    if (ov5640_write_reg(&pObj->Ctx, OV5640_SC_PLL_CONTRL2,  &tmp, 1) != OV5640_OK)
    {
      while(1);
    }
  }

  /* Set camera mirror / flip configuration */
  CAMERA_Set_MirrorFlip(Camera_Context_Ptr, Camera_Context_Ptr->mirror_flip);

  HAL_Delay(100);


  /* Center-crop the 640x480 frame to 480x480 */
   const uint32_t x0 = (640 - 480) / 2;
   const uint32_t y0 = 0;

   /* Note: 1 px every 2 DCMI_PXCLK (8-bit interface in RGB565) */
   HAL_DCMI_ConfigCrop(&hcamera_dcmi,
                       x0 * 2,
                       y0,
                       CAM_RES_WIDTH * 2 - 1,
                       CAM_RES_HEIGHT - 1);

   HAL_DCMI_EnableCrop(&hcamera_dcmi);
   /* Wait for the camera initialization after HW reset */
   HAL_Delay(200);

  /*
   * Start the Camera Capture
   * Using intermediate line buffer in D2-AHB domain to support high pixel clocks.
   */
  if (HAL_DCMIEx_Start_DMA_MDMA(&hcamera_dcmi, CAMERA_MODE_CONTINUOUS,
                                (uint8_t *)Camera_Context_Ptr->camera_capture_buffer,
                                CAM_LINE_SIZE, CAM_RES_HEIGHT) != HAL_OK)
  {
    while(1);
  }

  /* Wait for the camera initialization after HW reset */
  HAL_Delay(200);

#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
  /* Wait until camera acquisition of first frame is completed => frame ignored*/
  while (Camera_Context_Ptr->new_frame_ready == 0)
  {
    BSP_LED_Toggle(LED_GREEN);
    HAL_Delay(100);
  };
  Camera_Context_Ptr->new_frame_ready = 0;
#endif
}

/**
 * @brief Set the camera Mirror/Flip.
 * @param  Camera_Context_Ptr Pointer to camera context
 * @param  MirrorFlip CAMERA_MIRRORFLIP_NONE or any combination of
 *                    CAMERA_MIRRORFLIP_FLIP and CAMERA_MIRRORFLIP_MIRROR
 * @retval None
 */
void CAMERA_Set_MirrorFlip(CameraContext_TypeDef* Camera_Context_Ptr, uint32_t MirrorFlip)
{
  Camera_Context_Ptr->mirror_flip = MirrorFlip;
  if (BSP_CAMERA_SetMirrorFlip(0, Camera_Context_Ptr->mirror_flip) != BSP_ERROR_NONE)
  {
    while(1);
  }
}

/**
 * @brief  CAMERA Set test bar mode
 * @param  Camera_Context_Ptr Pointer to camera context
 * @retval None
 */
void CAMERA_Set_TestBar_Mode(CameraContext_TypeDef* Camera_Context_Ptr)
{
  uint32_t camera_id = Camera_Ctx[0].CameraId;

  /* Send I2C command(s) to configure the camera in test color bar mode */
  if ((camera_id == OV9655_ID) || (camera_id == OV9655_ID_2))
  {
    uint8_t tmp;
    OV9655_Object_t *pObj = Camera_CompObj;
    ov9655_read_reg(&pObj->Ctx, OV9655_COMMON_CTRL20, &tmp, 1);
    tmp |= 0x10; /* Set bit[4]: Color bar test mode */
    ov9655_write_reg(&pObj->Ctx, OV9655_COMMON_CTRL20, &tmp, 1);
  }
  else
  {
    OV5640_Object_t *pObj = Camera_CompObj;
    if (OV5640_ColorbarModeConfig(pObj, COLORBAR_MODE_ENABLE) != OV5640_OK)
    {
      while(1);
    }
  }

  HAL_Delay(500);
}

/**
 * @brief Frame Event callback
 * @param Instance Camera instance
 */
void BSP_CAMERA_FrameEventCallback(uint32_t Instance)
{
  AppContext_TypeDef *App_Cxt_Ptr=CameraContext.AppCtxPtr;
  
  __disable_irq();
  
  /*Notifies the backgound task about new frame available for processing*/
  CameraContext.new_frame_ready = 1;
  
  App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestop = HAL_GetTick();
  
  CameraContext.new_frame_ready = 1;
  
  CameraContext.Tframe_evt=HAL_GetTick();
  
  if((CameraContext.Tframe_evt-CameraContext.Tvsync_evt)<3)
  {
    CameraContext.vsync_it =2;
  }
  
  /*Suspend acquisition of the data stream coming from camera*/
  BSP_CAMERA_Suspend(0);
  
  __enable_irq();
}

/**
 * @brief VSYNC Event callback
 * @param Instance Camera instance
 */
void BSP_CAMERA_VsyncEventCallback(uint32_t Instance)
{ 
  AppContext_TypeDef *App_Cxt_Ptr=CameraContext.AppCtxPtr;
  
  __disable_irq();
  
  CameraContext.Tvsync_evt=HAL_GetTick();
  
  if(CameraContext.vsync_it==0)
  {
    CameraContext.vsync_it ++;
    App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestart2 = HAL_GetTick();
    App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestart=App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestart1;
  }
  else if(CameraContext.vsync_it==1 && ((CameraContext.new_frame_ready == 0) || ((CameraContext.new_frame_ready == 1) && ((CameraContext.Tvsync_evt - CameraContext.Tframe_evt) < 3))))//3 ms: in reality the time diff is in the magnitude of a few hundreds of ns, but some margin is required because there could be other interrupts in between the vsync_evt IT and the frame_evt IT.
  {
    App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestart=App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.tcapturestart2;
    CameraContext.vsync_it ++;
  }
  
  if(CameraContext.Tvsync_evt - CameraContext.Tframe_evt <3)
  {
    CameraContext.vsync_it =2;
  }
  
  __enable_irq();
}

/**
  * @brief  Error callback.
  * @param  Instance Camera instance.
  * @retval None
  */
void BSP_CAMERA_ErrorCallback(uint32_t Instance)
{
  Error_Handler();
}

/**
 * @brief Start DCMI capture intermediate line buffer
 *
 * Line capture using DMA from DCMI to intermediate line buffer. Line buffer is
 * then accumulated into final destination frame buffer using MDMA.
 *
 * @param hdcmi     Pointer to a DCMI_HandleTypeDef structure that contains
 *                  the configuration information for DCMI.
 * @param DCMI_Mode DCMI capture mode snapshot or continuous grab.
 * @param pData     Pointer to destination frame buffer.
 * @param line_size Horizontal frame size in bytes.
 * @param num_lines Vertical frame size in pixels.
 * @retval HAL status
 */
HAL_StatusTypeDef HAL_DCMIEx_Start_DMA_MDMA(DCMI_HandleTypeDef *hdcmi, uint32_t DCMI_Mode, uint8_t *pData,
                                            uint32_t line_size, uint32_t num_lines)
{
  /* Check function parameters */
  assert_param(IS_DCMI_CAPTURE_MODE(DCMI_Mode));

  /* Process Locked */
  __HAL_LOCK(hdcmi);

  /* Lock the DCMI peripheral state */
  hdcmi->State = HAL_DCMI_STATE_BUSY;

  /* Enable DCMI by setting DCMIEN bit */
  __HAL_DCMI_ENABLE(hdcmi);

  /* Configure the DCMI Mode */
  hdcmi->Instance->CR &= ~(DCMI_CR_CM);
  hdcmi->Instance->CR |= (uint32_t)(DCMI_Mode);

  /* Set DMA callbacks */
  hdcmi->DMA_Handle->XferCpltCallback = DCMI_DMALineXferCplt;
  hdcmi->DMA_Handle->XferErrorCallback = DCMI_DMAError;
  hdcmi->DMA_Handle->XferAbortCallback = NULL;

  /* Set MDMA callbacks */
  hmdma.XferCpltCallback = DCMI_MDMAFrameXferCplt;
  hmdma.XferErrorCallback = DCMI_MDMAError;

  hdcmi->XferCount = 0;
  hdcmi->XferTransferNumber = num_lines;
  hdcmi->XferSize = line_size / 4U;
  hdcmi->pBuffPtr = (uint32_t) pData;

  /* Enable the DMA Stream */
  uint32_t pLineData = (uint32_t) pCameraLineBuffer;
  if (HAL_DMA_Start_IT(hdcmi->DMA_Handle, (uint32_t)&hdcmi->Instance->DR, pLineData, hdcmi->XferSize) != HAL_OK)
  {
    /* Set Error Code */
    hdcmi->ErrorCode = HAL_DCMI_ERROR_DMA;
    /* Change DCMI state */
    hdcmi->State = HAL_DCMI_STATE_READY;
    /* Release Lock */
    __HAL_UNLOCK(hdcmi);
    /* Return function status */
    return HAL_ERROR;
  }

  /* Enable Capture */
  hdcmi->Instance->CR |= DCMI_CR_CAPTURE;

  /* Release Lock */
  __HAL_UNLOCK(hdcmi);

  /* Return function status */
  return HAL_OK;
}

/**
  * @brief  DMA transfer complete callback.
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *                the configuration information for the specified DMA module.
  * @retval None
  */
static void DCMI_DMALineXferCplt(DMA_HandleTypeDef *hdma)
{
  DCMI_HandleTypeDef *hdcmi = (DCMI_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  /* Copy line buffer to frame buffer using MDMA */
  uint32_t line_size =  hdcmi->XferSize * 4U;
  uint8_t *pDst = (uint8_t *) hdcmi->pBuffPtr + line_size * hdcmi->XferCount;

  if (HAL_MDMA_Start_IT(&hmdma, (uint32_t) pCameraLineBuffer, (uint32_t) pDst, line_size, 1) != HAL_OK)
  {
    Error_Handler();
  }

}

/**
  * @brief  MDMA DCMI transfer complete callback
  * @param  hmdma  MDMA handle
  * @retval None
  */
static void DCMI_MDMAFrameXferCplt(MDMA_HandleTypeDef *hmdma)
{

  DCMI_HandleTypeDef *hdcmi = &hcamera_dcmi;

  /* Disable the MDMA channel */
  __HAL_MDMA_DISABLE(hmdma);

  hdcmi->XferCount++;

  /* Check if the frame is transferred */
  if (hdcmi->XferCount == hdcmi->XferTransferNumber)
  {
    /* Enable the Frame interrupt */
    __HAL_DCMI_ENABLE_IT(hdcmi, DCMI_IT_FRAME);

    /* When snapshot mode, set dcmi state to ready */
    if ((hdcmi->Instance->CR & DCMI_CR_CM) == DCMI_MODE_SNAPSHOT)
    {
      hdcmi->State = HAL_DCMI_STATE_READY;
    }
    else
    {
      hdcmi->XferCount = 0;
    }
  }
}

/**
  * @brief  DMA error callback
  * @param  hdma pointer to a DMA_HandleTypeDef structure that contains
  *                the configuration information for the specified DMA module.
  * @retval None
  */
static void DCMI_DMAError(DMA_HandleTypeDef *hdma)
{
  DCMI_HandleTypeDef *hdcmi = (DCMI_HandleTypeDef *)((DMA_HandleTypeDef *)hdma)->Parent;

  if (hdcmi->DMA_Handle->ErrorCode != HAL_DMA_ERROR_FE)
  {
    /* Initialize the DCMI state*/
    hdcmi->State = HAL_DCMI_STATE_READY;

    /* Set DCMI Error Code */
    hdcmi->ErrorCode |= HAL_DCMI_ERROR_DMA;
  }

  Error_Handler();
}

/**
  * @brief  MDMA DCMI error callback.
  * @param  hmdma MDMA handle
  * @retval None
  */
static void DCMI_MDMAError(MDMA_HandleTypeDef *hmdma)
{
  /* Disable the MDMA channel */
  __HAL_MDMA_DISABLE(hmdma);

  Error_Handler();
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
