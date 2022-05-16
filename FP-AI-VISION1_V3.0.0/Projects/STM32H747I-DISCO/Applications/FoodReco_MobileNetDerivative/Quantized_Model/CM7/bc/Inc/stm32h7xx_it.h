/**
 ******************************************************************************
 * @file    stm32h7xx_it.h
 * @author  MCD Application Team
 * @brief   This file contains the headers of the interrupt handlers for Cortex-M7.
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
#ifndef __STM32H7xx_IT_H
#define __STM32H7xx_IT_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Exported variables --------------------------------------------------------*/
extern LTDC_HandleTypeDef  hlcd_ltdc;

/* Exported functions ------------------------------------------------------- */
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
void DMA2_Stream3_IRQHandler(void);
void DCMI_IRQHandler(void);
void MDMA_IRQHandler(void);
void DSI_IRQHandler(void);
void DMA2D_IRQHandler(void);
void AUDIO_OUT_SAIx_DMAx_IRQHandler(void);
void USARTx_DMA_RX_IRQHandler(void);
void USARTx_DMA_TX_IRQHandler(void);
void USARTx_IRQHandler(void);
void LTDC_IRQHandler(void);

#ifdef __cplusplus
}
#endif

#endif /* __STM32H7xx_IT_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
