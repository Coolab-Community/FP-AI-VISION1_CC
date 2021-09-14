/**
  ******************************************************************************
  * @file    stm32h747i_discovery_camera_ex.h
  * @author  MCD Application Team
  * @brief   Header file of CAMERA BSP extended module.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                       opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32H747I_DISCO_CAMERA_EX_H
#define STM32H747I_DISCO_CAMERA_EX_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32h747i_discovery_camera.h"

/* Exported constants --------------------------------------------------------*/

/*
  Set CAMERA_BOOST_PCLK=1 to operate the OV5640 camera in optimal mode.
  Note: when operating the camera in optimal mode, the pixel frequency is
  above 12MHz and FCC certification is no longer guaranteed.
*/
#ifndef CAMERA_BOOST_PCLK
#define CAMERA_BOOST_PCLK   0
#endif

/* Frame rates */
#define CAMERA_TIMING_12FPS    12
#define CAMERA_TIMING_15FPS    15
#define CAMERA_TIMING_30FPS    30

/* Exported functions --------------------------------------------------------*/
int32_t BSP_CAMERAEx_SetTiming(uint32_t Instance, uint32_t fps);

#ifdef __cplusplus
}
#endif

#endif /* STM32H747I_DISCO_CAMERA_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
