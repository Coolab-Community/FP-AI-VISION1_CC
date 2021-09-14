;/******************** (C) COPYRIGHT 2019 STMicroelectronics ********************
;* File Name          : startup_cm4.s
;* Author             : MCD Application Team
;* Description        : STM32H747xx devices Cortex-M4 vector table for EWARM toolchain.
;*                      This module performs:
;*                      - Set the initial SP
;*                      - Set the initial PC == Reset_Handler
;*                      - Reset_Handler consists in an infinite loop so to boot CM4 core 
;*                        properly and keep it in a known state.
;******************************************************************************
;* @attention
;*
;* <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
;* All rights reserved.</center></h2>
;*
;* This software component is licensed by ST under BSD 3-Clause license,
;* the "License"; You may not use this file except in compliance with the
;* License. You may obtain a copy of the License at:
;*                        opensource.org/licenses/BSD-3-Clause
;*
;******************************************************************************
;
;
; The modules in this file are included in the libraries, and may be replaced
; by any user-defined modules that define the PUBLIC symbol _program_start or
; a user defined start symbol.
; To override the cstartup defined in the library, simply add your modified
; version to the workbench project.
;
; The vector table is normally located at address 0.
; When debugging in RAM, it can be located in RAM, aligned to at least 2^6.
; The name "__vector_table" has special meaning for C-SPY:
; it is where the SP start value is found, and the NVIC vector
; table register (VTOR) is initialized to this address if != 0.
;
; Cortex-M version
;

; MODULE  ?cstartup

        SECTION CSTACK:DATA:NOROOT(3) 
 
        SECTION .intvec_m4:CODE
 
        PUBLIC  __vector_table_m4

        DATA
__vector_table_m4
        DCD     sfe(CSTACK)
        DCD     Reset_Handler_m4                     ; Reset Handler for CortexM4 core
                                                  
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;
;; Default interrupt handlers.
;;
        THUMB
        PUBWEAK Reset_Handler_m4
        SECTION .text:CODE:NOROOT:REORDER(2)
Reset_Handler_m4

loop:   B loop
       
        END
 ///////////////////////////////////////////////////////////////////
 
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
