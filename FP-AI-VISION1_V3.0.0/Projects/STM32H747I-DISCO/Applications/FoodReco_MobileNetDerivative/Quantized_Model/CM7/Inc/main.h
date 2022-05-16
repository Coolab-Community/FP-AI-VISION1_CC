/**
 ******************************************************************************
 * @file    main.h
 * @author  MCD Application Team
 * @brief   Header for main.c module for Cortex-M7.
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
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <string.h>

#include "stm32h7xx_hal.h"
#include "stm32h747i_discovery.h"
#include "stm32h747i_discovery_conf.h"
#include "stm32h747i_discovery_audio.h"
#include "stm32h747i_discovery_qspi.h"

#include "fp_vision_display.h"
#include "fp_vision_app.h"


typedef enum {
  AUDIO_ERROR_NONE = 0,
  AUDIO_ERROR_NOTREADY,
  AUDIO_ERROR_IO,
  AUDIO_ERROR_EOF,
}AUDIO_ErrorTypeDef;

/*Defines related to cache settings*/
#define EXT_SDRAM_CACHE_ENABLED 1

/* SDRAM write address */
//#define SDRAM_WRITE_READ_ADDR         0xD0177000
//#define AUDIO_REC_START_ADDR         SDRAM_WRITE_READ_ADDR
//#define AUDIO_REC_TOTAL_SIZE         ((uint32_t) 0x0000E000)
//#define AUDIO_RECPDM_START_ADDR      (AUDIO_REC_START_ADDR+AUDIO_REC_TOTAL_SIZE)

/* The Audio file is flashed with ST-Link Utility @ flash address =  AUDIO_SRC_FILE_ADDRESS */
#define AUDIO_SRC_FILE_ADDRESS_DEFAU       0x90000000   /* Audio file address in external flash */
#define AUDIO_FILE_SIZE              286720
#define AUDIO_SRC_FILE_ADDRESS_LEFT       0x90050000   /* Audio file address in external flash */
#define AUDIO_FILE_SIZE_TWO              40912
#define AUDIO_SRC_FILE_ADDRESS_RIGHT       0x900A0000   /* Audio file address in external flash */
#define AUDIO_SRC_FILE_ADDRESS_STRAI       0x900F0000   /* Audio file address in external flash */
#define AUDIO_SRC_FILE_ADDRESS_UTURN       0x90100000   /* Audio file address in external flash */


#define AUDIO_PLAY_SAMPLE        0
#define AUDIO_PLAY_RECORDED      1


/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void AudioPlay_demo (uint8_t myTest);
void AudioRecord_demo(void);
uint8_t AUDIO_Process(void);

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
