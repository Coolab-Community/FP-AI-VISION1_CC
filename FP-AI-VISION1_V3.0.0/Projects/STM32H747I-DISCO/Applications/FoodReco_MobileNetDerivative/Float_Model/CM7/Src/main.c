/**
 ******************************************************************************
 * @file    main.c
 * @author  MCD Application Team
 * @brief   This is the main program for the application running on Cortex-M7
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

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void CPU_CACHE_Enable(void);
static void MPU_Config(void);

/* Private variables ---------------------------------------------------------*/
BSP_QSPI_Init_t init;

/**
* @brief  Application entry point
* @param  None
* @retval None
*/
int main(void)
{
  /* System Init, System clock, voltage scaling and L1-Cache configuration are done by CPU1 (Cortex-M7)
  in the meantime Domain D2 is put in STOP mode(Cortex-M4 in deep-sleep) */
  
  /* Configure the MPU attributes */
  MPU_Config();
  
  /* Enable the CPU Cache */
  CPU_CACHE_Enable();
  
  HAL_Init();
  
  /* Configure the system clock to 400 MHz */
  SystemClock_Config();
  
  /*Enable CRC HW IP block*/
  __HAL_RCC_CRC_CLK_ENABLE();
  
  /*APP init*/
  APP_Init(&App_Context);
  
  /*TEST init*/
  TEST_Init(App_Context.Test_ContextPtr);
  
  /*UTILS init */
  UTILS_Init(App_Context.Utils_ContextPtr);
  
  /*DISPLAY init*/
  DISPLAY_Init(App_Context.Display_ContextPtr);
  
  /*AI init*/
  AI_Init(App_Context.Ai_ContextPtr);

  init.InterfaceMode=MT25TL01G_QPI_MODE;
  init.TransferRate= MT25TL01G_DTR_TRANSFER ;
  init.DualFlashMode= MT25TL01G_DUALFLASH_ENABLE;
  /* Initialize the NOR QuadSPI flash */
  if (BSP_QSPI_Init(0,&init) != BSP_ERROR_NONE)
  {
    while(1);
  }
  else
  {
    if(BSP_QSPI_EnableMemoryMappedMode(0) != BSP_ERROR_NONE)
    {
      while(1);
    }
  }
  
#if WEIGHT_QSPI == 1 && WEIGHT_EXEC_EXTRAM == 1
  uint32_t idx;
  for(idx=0; idx<AI_WEIGHT_SIZE_BYTES; idx++)
  {
    *(weights_table_sdram + idx) = *(uint8_t*)(QUADSPI_EXT_FLASH + idx);
  }
#endif
  
  /*Display Welcome Screen*/
  int is_menu = DISPLAY_WelcomeScreen(App_Context.Display_ContextPtr);
  
RESTART:   
  if ((is_menu != 0) || (App_Context.Test_ContextPtr->UartContext.uart_cmd_ongoing == 1))
  {
    /* Run main menu */
    TEST_MainMenu(App_Context.Test_ContextPtr);
  }
  
  if(App_Context.Operating_Mode == NOMINAL || App_Context.Operating_Mode == CAPTURE || (App_Context.Operating_Mode == DUMP && App_Context.Test_ContextPtr->DumpContext.Dump_FrameSource == CAMERA_LIVE))
  {
    /*CAMERA init*/
    CAMERA_Init(App_Context.Camera_ContextPtr); 
  }
  
  while(App_Context.run_loop)
  {
    /* Check joystick input to adjust camera's brightness / contrast */
    UTILS_Joystick_Check(App_Context.Utils_ContextPtr);
    
    /*Check UART status for any received command from Host PC*/
    TEST_CmdIf_Check(App_Context.Test_ContextPtr);          
    
#if MEMORY_SCHEME == FULL_INTERNAL_MEM_OPT
    /*****************************************************************************/
    /**************Launch the camera acquisition of the subsequent frame *********/
    /*****************************************************************************/    
    APP_StartNewFrameAcquisition(&App_Context);
    
    /****************************************************************************/
    /**************Wait for the next frame to be ready for processing************/
    /****************************************************************************/ 
    APP_GetNextReadyFrame(&App_Context);
#endif  
    
#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
    /**************************************************************************/
    /**************Wait for the next frame to be ready for processing**********/
    /**************************************************************************/ 
    APP_GetNextReadyFrame(&App_Context);
    
    /**************************************************************************************************************************/
    /**************Launch the camera acquisition of the subsequent frame in parallel of the current frame processing***********/
    /**************************************************************************************************************************/ 
    APP_StartNewFrameAcquisition(&App_Context);
#endif 
    
    /**********************************************************************/
    /************************Run Frame Preprocessing***********************/
    /**********************************************************************/  
    APP_FramePreprocess(&App_Context);
    
    /********************************************************************/
    /*************************Run NN Inference***************************/
    /********************************************************************/
    APP_NetworkInference(&App_Context);
    
    /*****************************************************/
    /**************Run post process operations************/
    /*****************************************************/    
    APP_Postprocess(&App_Context);  
  }
  
  if(1)
  {
    AI_Deinit();
    App_Context.run_loop = 1;
    UTIL_LCD_SetFont(&Font24);
    goto RESTART;
  }
  else
  {
    ;
  }
  
  /* End of program */
}

/* Private functions ---------------------------------------------------------*/
/**
 * @brief  System Clock Configuration
 *         The system Clock is configured as follow :
 *            System Clock source            = PLL (HSE)
 *            SYSCLK(Hz)                     = 400000000 (Cortex-M7 CPU Clock)
 *            HCLK(Hz)                       = 200000000 (Cortex-M4 CPU, Bus matrix Clocks)
 *            AHB Prescaler                  = 2
 *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
 *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
 *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
 *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
 *            HSE Frequency(Hz)              = 25000000
 *            PLL_M                          = 5
 *            PLL_N                          = 160
 *            PLL_P                          = 2
 *            PLL_Q                          = 4
 *            PLL_R                          = 2
 *            VDD(V)                         = 3.3
 *            Flash Latency(WS)              = 4
 * @param  None
 * @retval None
 */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;

  /*!< Supply configuration update enable */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /* The voltage scaling allows optimizing the power consumption when the device is
  clocked below the maximum system frequency, to update the voltage scaling value
  regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY))
  {
  }

  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;

  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if (ret != HAL_OK)
  {
    Error_Handler();
  }

  /* Select PLL as system clock source and configure  bus clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 |
                                 RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2 | RCC_CLOCKTYPE_D3PCLK1);

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2);
  if (ret != HAL_OK)
  {
    Error_Handler();
  }

  /*
  Note : The activation of the I/O Compensation Cell is recommended with communication  interfaces
  (GPIO, SPI, FMC, QSPI ...)  when  operating at  high frequencies(please refer to product datasheet)
  The I/O Compensation Cell activation  procedure requires :
  - The activation of the CSI clock
  - The activation of the SYSCFG clock
  - Enabling the I/O Compensation Cell : setting bit[0] of register SYSCFG_CCCSR
  */

  /*activate CSI clock mandatory for I/O Compensation Cell*/
  __HAL_RCC_CSI_ENABLE();

  /* Enable SYSCFG clock mandatory for I/O Compensation Cell */
  __HAL_RCC_SYSCFG_CLK_ENABLE();

  /* Enables the I/O Compensation Cell */
  HAL_EnableCompensationCell();
}

/**
 * @brief  CPU L1-Cache enable.
 * @param  None
 * @retval None
 */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

/**
 * @brief  Configure the MPU attributes for the device's memories.
 * @param  None
 * @retval None
 */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;

  /* Disable the MPU */
  HAL_MPU_Disable();

#if EXT_SDRAM_CACHE_ENABLED == 0
  /*
  To make the memory region non cacheable and avoid any cache coherency maintenance:
  - either: MPU_ACCESS_NOT_BUFFERABLE + MPU_ACCESS_NOT_CACHEABLE
  - or: MPU_ACCESS_SHAREABLE => the S field is equivalent to non-cacheable memory
  */
  /* External SDRAM memory: LCD Frame buffer => non-cacheable */
  /*TEX=001, C=0, B=0*/
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xD0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_NOT_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
#elif EXT_SDRAM_CACHE_ENABLED == 1
  /* External SDRAM memory: all as WBWA */
  /*TEX=001, C=1, B=1*/
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xD0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL1; 
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE; 
#elif EXT_SDRAM_CACHE_ENABLED == 2
  /*External SDRAM memory: all as Write Thru:*/
  /*TEX=000, C=1, B=0*/
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = 0xD0000000;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0; 
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;
#else
#error Please check definition of EXT_SDRAM_CACHE_ENABLED define
#endif

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /*Internal SRAM memory: cache policies are WBWA (Write Back and Write Allocate) by default */

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}


/**
 * @brief  This function is executed in case of error occurrence.
 * @param  None
 * @retval None
 */
void Error_Handler(void)
{
  BSP_LED_Off(LED_GREEN);
  BSP_LED_Off(LED_ORANGE);
  BSP_LED_Off(LED_RED);
  BSP_LED_Off(LED_BLUE);

  /* Turn LED RED on */
  BSP_LED_On(LED_RED);
  while (1)
  {
  }
}

#ifdef USE_FULL_ASSERT
/**
 * @brief  Reports the name of the source file and the source line number
 *         where the assert_param error has occurred.
 * @param  file: pointer to the source file name
 * @param  line: assert_param error line source number
 * @retval None
 */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
  ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
