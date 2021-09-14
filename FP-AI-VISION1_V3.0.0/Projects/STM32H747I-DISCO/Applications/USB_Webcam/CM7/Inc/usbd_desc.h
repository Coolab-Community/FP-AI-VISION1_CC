/**
  ******************************************************************************
  * @file    usbd_desc.h
  * @author  MCD Application Team
  * @brief   Header for usbd_desc.c file.
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
#ifndef __USBD_DESC__H__
#define __USBD_DESC__H__

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "usbd_def.h"

/* Exported constants --------------------------------------------------------*/
#define         DEVICE_ID1          (UID_BASE)
#define         DEVICE_ID2          (UID_BASE + 0x4)
#define         DEVICE_ID3          (UID_BASE + 0x8)

#define  USB_SIZ_STRING_SERIAL       0x1A

/* Exported variables ------------------------------------------------------- */
extern USBD_DescriptorsTypeDef VIDEO_Desc;

#ifdef __cplusplus
}
#endif

#endif /* __USBD_DESC__H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
