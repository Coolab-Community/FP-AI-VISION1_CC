/**
  ******************************************************************************
  * @file    usbd_video_if.h
  * @author  MCD Application Team
  * @brief   Header file for the video Interface application layer functions
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
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
#ifndef __USBD_VIDEO_IF_H__
#define __USBD_VIDEO_IF_H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usbd_video.h"

/* Exported types ------------------------------------------------------------*/
typedef enum {
  CAM_STATE_STOPPED = 0,
  CAM_STATE_SETUP,
  CAM_STATE_CONFIGURED
} camera_state_t;

/* Exported variables ------------------------------------------------------- */
extern USBD_VIDEO_ItfTypeDef USBD_VIDEO_fops;

extern volatile uint8_t *usb_tx_buff;
extern volatile uint32_t usb_tx_size;
extern volatile uint32_t usb_tx_complete;
extern volatile uint32_t camera_buf_size;
extern volatile uint32_t camera_format;
extern volatile uint32_t camera_res;
extern volatile uint32_t camera_res_width;
extern volatile uint32_t camera_res_height;
extern volatile camera_state_t camera_state;

#ifdef __cplusplus
}
#endif

#endif /* USBD_VIDEO_IF_H_ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
