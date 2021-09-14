/**
 ******************************************************************************
 * @file    fp_vision_test.c
 * @author  MCD Application Team
 * @brief   FP VISION test
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
#include "fp_vision_test.h"

/* Private typedef -----------------------------------------------------------*/
/* Private defines -----------------------------------------------------------*/
/* Private macros ------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Global variables ----------------------------------------------------------*/
TestContext_TypeDef TestContext;

static char tmp_msg[512];

#ifndef OBJECTDETECT
#if defined(__ICCARM__)
#pragma location = "Validation_image_buffer"
#pragma data_alignment=32
#elif defined(__CC_ARM)
__attribute__((section(".Validation_image_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined(__GNUC__)
__attribute__((section(".Validation_image_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
/*! Used to store image buffer read from microSD */
unsigned char valid_image_buff[(MAX_RES_WIDTH * MAX_RES_HEIGHT * RGB_888_BPP) + 32 - ((MAX_RES_WIDTH * MAX_RES_HEIGHT * RGB_888_BPP)%32)];
#endif /* !OBJECTDETECT */

#if defined(__ICCARM__)
#pragma location = "Dump_output_buffer"
#pragma data_alignment=32
#elif defined(__CC_ARM)
__attribute__((section(".Dump_output_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined(__GNUC__)
__attribute__((section(".Dump_output_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
/*! Used to store the output (i.e. the probability number for each output class) of the dump  */
float dump_output_buff[AI_NET_OUTPUT_SIZE + 32 - (AI_NET_OUTPUT_SIZE%32)];

#ifndef OBJECTDETECT
#if defined(__ICCARM__)
#pragma location = "Validation_output_buffer"
#pragma data_alignment=32
#elif defined(__CC_ARM)
__attribute__((section(".Validation_output_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined(__GNUC__)
__attribute__((section(".Validation_output_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
/*! Used to store the NN output (i.e. the probability number for each output class) of each file/inference during the validation */
float validation_output_buff[(AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE*NUM_FILE_PER_DIR) + 32 - ((AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE*NUM_FILE_PER_DIR)%32)];

#if defined(__ICCARM__)
#pragma location = "dump_intermediate_data_ping_buffer"
#pragma data_alignment=32
#elif defined(__CC_ARM)
__attribute__((section(".dump_intermediate_data_ping_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined(__GNUC__)
__attribute__((section(".dump_intermediate_data_ping_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
/*! Used to dump the intermediate data during a NN inference when SDRAM is selected as memory location for the dump operation*/
uint8_t dump_intermediate_data_ping_buff[DUMP_INTERMEDIATE_DATA_BUFFER_SIZE + 32 - (DUMP_INTERMEDIATE_DATA_BUFFER_SIZE%32)];

#if defined(__ICCARM__)
#pragma location = "dump_intermediate_data_pong_buffer"
#pragma data_alignment=32
#elif defined(__CC_ARM)
__attribute__((section(".dump_intermediate_data_pong_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined(__GNUC__)
__attribute__((section(".dump_intermediate_data_pong_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
/*! Used to dump the intermediate data during a NN inference when SDRAM is selected as memory location for the dump operation*/
uint8_t dump_intermediate_data_pong_buff[DUMP_INTERMEDIATE_DATA_BUFFER_SIZE + 32 - (DUMP_INTERMEDIATE_DATA_BUFFER_SIZE%32)];

#if defined(__ICCARM__)
#pragma location = "execution_timings_buffer"
#pragma data_alignment=32
#elif defined(__CC_ARM)
__attribute__((section(".execution_timings_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined(__GNUC__)
__attribute__((section(".execution_timings_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
/*! Used to dump the execution timings of each operation during test*/
uint32_t execution_timings_buff[APP_FRAMEOPERATION_NUM + 32 - (APP_FRAMEOPERATION_NUM%32)];

#if defined ( __ICCARM__ )
#pragma data_alignment=32
#elif defined ( __CC_ARM )
__attribute__ ((aligned (32)))
#elif defined ( __GNUC__ )
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
uint8_t Cam_Reg_Table[NUM_CAM_REG + 32 - (NUM_CAM_REG%32)];

#if defined ( __ICCARM__ )
#pragma location = "uart_rx_buffer"
#pragma data_alignment=32
#elif defined ( __CC_ARM )
__attribute__((section(".uart_rx_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined ( __GNUC__ )
__attribute__((section(".uart_rx_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
uint8_t aRxBuffer[RX_BUFFER_SIZE];

#if defined ( __ICCARM__ )
#pragma location = "uart_tx_buffer"
#pragma data_alignment=32
#elif defined ( __CC_ARM )
__attribute__((section(".uart_tx_buffer"), zero_init))
__attribute__ ((aligned (32)))
#elif defined ( __GNUC__ )
__attribute__((section(".uart_tx_buffer")))
__attribute__ ((aligned (32)))
#else
#error Unknown compiler
#endif
uint8_t aTxBuffer[TXBUFFERSIZE_MAX + 32 - (TXBUFFERSIZE_MAX % 32)];
#endif /* !OBJECTDETECT */

char Test_buffer_names[APP_BUFF_NUM][MAX_STRING_SIZE] = {"camera_frame_buff", "resize_output_buff", "pfc_output_buff", "nn_input_buff", "nn_output_buff"};

#ifndef OBJECTDETECT
static void UartCmd_Run_NonRegression(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Run_Validation(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_NonRegression_Report_Size(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_Validation_Report_Size(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_Timing_Report_Size(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_NonRegression_Debug_Report_Size(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_NonRegression_Report(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_Validation_Report(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_Timing_Report(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_Validation_Report(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_NonRegression_Debug_Report(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_Validation_Final_Accuracy(TestContext_TypeDef *, uint8_t*, uint16_t);

static void UartCmd_Launch_Dump(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Trigger_Dump(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Launch_Capture(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Trigger_Capture(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_Valid_Output_Size(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_Valid_Output(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_Dump_Output_Data_Size(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_Dump_Output_Data(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Get_Dump_Whole_Data_Size(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Upload_Dump_Whole_Data(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Read_Camera_Register(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Write_Camera_Register(TestContext_TypeDef *, uint8_t*, uint16_t);
static void UartCmd_Set_Camera_Mode(TestContext_TypeDef *, uint8_t*, uint16_t);

static void DisplayConfusionMatrix(uint32_t conf_matrix[AI_NET_OUTPUT_SIZE][AI_NET_OUTPUT_SIZE]);
static int FindClassIndexFromString(char *);
static void DisplayClassificationReport(TestContext_TypeDef *, const ClassificationReport_Typedef *);
static void WriteConfusionMatrix(uint32_t conf_matrix[AI_NET_OUTPUT_SIZE][AI_NET_OUTPUT_SIZE] , const char *);
static void WriteClassificationReport(const ClassificationReport_Typedef *, const char *);
static ClassificationReport_Typedef classification_report(uint32_t conf_matrix[AI_NET_OUTPUT_SIZE][AI_NET_OUTPUT_SIZE] );
#endif /* !OBJECTDETECT */

static void FrameCaptureInit(TestContext_TypeDef *);
static void MemoryDumpInit(TestContext_TypeDef *);
static void OnBoardValidInit(TestContext_TypeDef *);
#ifndef OBJECTDETECT
static void Uart_Init(TestContext_TypeDef *);
static void Uart_Tx(TestContext_TypeDef *, uint8_t *, uint32_t, uint32_t );
static void Uart_Rx(TestContext_TypeDef *, uint8_t *, uint32_t );
#endif /* !OBJECTDETECT */
static void DisplayIntroMessage(TestContext_TypeDef *);
static void Capture_PostProcess(TestContext_TypeDef *);
static void Dump_PostProcess(TestContext_TypeDef *);
static void Validation_PostProcess(TestContext_TypeDef *);
#ifndef OBJECTDETECT
static void Test_ComIf_Init(TestContext_TypeDef *);
#endif /* !OBJECTDETECT */
static void Test_Context_Init(TestContext_TypeDef *);

#ifndef OBJECTDETECT
static UartCmdFctPtr UartCmdFct_Table[UART_CMD_NUMBER]=
{
  UartCmd_Run_NonRegression,
  UartCmd_Run_Validation,
  UartCmd_Get_NonRegression_Report_Size,
  UartCmd_Get_Validation_Report_Size,
  UartCmd_Get_Timing_Report_Size,
  UartCmd_Get_NonRegression_Debug_Report_Size,
  UartCmd_Upload_NonRegression_Report,
  UartCmd_Upload_Validation_Report,
  UartCmd_Upload_Timing_Report,
  UartCmd_Upload_NonRegression_Debug_Report,
  UartCmd_Get_Validation_Final_Accuracy,

  UartCmd_Launch_Dump,
  UartCmd_Trigger_Dump,
  UartCmd_Launch_Capture,
  UartCmd_Trigger_Capture,
  UartCmd_Get_Valid_Output_Size,
  UartCmd_Upload_Valid_Output,
  UartCmd_Get_Dump_Output_Data_Size,
  UartCmd_Upload_Dump_Output_Data,
  UartCmd_Get_Dump_Whole_Data_Size,
  UartCmd_Upload_Dump_Whole_Data,
  UartCmd_Read_Camera_Register,
  UartCmd_Write_Camera_Register,
  UartCmd_Set_Camera_Mode
};
#endif /* !OBJECTDETECT */

/* Private function prototypes -----------------------------------------------*/

#ifndef OBJECTDETECT
static void UartCmd_Run_NonRegression(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /**************************************************************RUN_NONREG_CMD*******************************************************************************
  *Launch the execution of the non-regression, i.e. perform consecutive DUMP w/ camera in test mode.
  *This command has one parameter:
  *Number of consecutive full run (-1) to execute (4 bytes): 0x00000000 <=> one run, 0xFFFFFFFE <=> 2^32 runs and 0xFFFFFFFF <=> infinite runs (= debug mode)
  ************************************************************************************************************************************************************/

  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;

  Test_Context_Ptr->UartContext.uart_cmd_ongoing = 1;
  Test_Context_Ptr->UartContext.uart_host_requested_mode=DUMP;
  App_Cxt_Ptr->run_loop = 0;

  Test_Context_Ptr->UartContext.uart_host_requested_dump_submode=CAMERA_COLORBAR;
  Test_Context_Ptr->UartContext.uart_host_requested_dump_memory=SDRAM;

  Test_Context_Ptr->DumpContext.dump_write_bufferPtr=dump_intermediate_data_ping_buff;

  Test_Context_Ptr->UartContext.uart_host_requested_dump_number=*(uint32_t*)(data_buffer);

  Test_Context_Ptr->UartContext.uart_host_nonreg_run=1;
}

static void UartCmd_Run_Validation(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /***************RUN_VALIDATION_CMD***************
  *Launch the execution of the onboard validation.
  *This command has no parameter
  ************************************************/

  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;

  Test_Context_Ptr->UartContext.uart_cmd_ongoing = 1;
  Test_Context_Ptr->UartContext.uart_host_requested_mode=VALID;
  Test_Context_Ptr->ValidationContext.validation_write_bufferPtr=(uint8_t*)validation_output_buff;
  App_Cxt_Ptr->run_loop = 0;
}

static void UartCmd_Get_NonRegression_Report_Size(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************GET_NONREG_REPORT_SIZE_CMD***************************
  *Returns the size (in bytes) of the NN output generated by a run of Non-Regression.
  *This command has no parameter.
  ************************************************************************************/

  /**Sent the NN output size to Host**/
  *((uint32_t*)aTxBuffer) = AI_NET_OUTPUT_SIZE_BYTES;
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), 4);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Get_Validation_Report_Size(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************GET_VALIDATION_REPORT_SIZE_CMD***************************
  *Returns the size (in bytes) of all the NN outputs generated by the Validation process.
  *This command has no parameter.
  ***************************************************************************************/

  /**Sent the validation output size to Host**/
  *((uint32_t*)aTxBuffer) = AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE_BYTES*NUM_FILE_PER_DIR;
#ifdef OBJECTDETECT
  /* *((uint32_t*)aTxBuffer) = AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE_BYTES*NUM_FILE_PER_DIR; //2codemodif2
  old yoloLC version
  */
#endif /* OBJECTDETECT */
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), 4);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Get_Timing_Report_Size(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************GET_TIMING_REPORT_SIZE_CMD**************************
  *Returns the size (in bytes) of the timing report.
  *This command has no parameter.
  ***********************************************************************************/

  /**Sent the timing report size to Host**/
  *((uint32_t*)aTxBuffer) = APP_FRAMEOPERATION_NUM*sizeof(uint32_t);
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), 4);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Get_NonRegression_Debug_Report_Size(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /***************************GET_NONREG_DEBUG_REPORT_SIZE_CMD************************
  *Returns the size (in bytes) of the full dump generated by a run of Non-Regression.
  *This command has no parameter.
  ************************************************************************************/

  /**Sent the dump output size to Host**/
  *((uint32_t*)aTxBuffer) = DUMP_INTERMEDIATE_DATA_BUFFER_SIZE*2;
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), 4);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Upload_NonRegression_Report(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /*********************UPLOAD_NONREG_REPORT_CMD********************
  *Uploads the Non-regression report ot the host
  *This command has no parameter.
  ******************************************************************/

  /**Sent the non-regression report to Host**/
  Uart_Tx(Test_Context_Ptr, (uint8_t*)dump_output_buff, sizeof(dump_output_buff), AI_NET_OUTPUT_SIZE_BYTES);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Upload_Validation_Report(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /*******************UPLOAD_VALIDATION_REPORT_CMD******************
  *Uploads the Validation report ot the host
  *This command has no parameter.
  ******************************************************************/

  /**Sent the validation report to Host**/
  Uart_Tx(Test_Context_Ptr, (uint8_t*)validation_output_buff, sizeof(validation_output_buff), AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE_BYTES*NUM_FILE_PER_DIR);
#ifdef OBJECTDETECT
/*
  old yoloLC version
Uart_Tx(Test_Context_Ptr, (uint8_t*)validation_output_buff, sizeof(validation_output_buff),1); //AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE_BYTES*NUM_FILE_PER_DIR);*/
#endif /* OBJECTDETECT */

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Upload_Timing_Report(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /*******************UPLOAD_TIMING_REPORT_CMD******************
  *Uploads the Timing report to the host
  *This command has no parameter.
  **************************************************************/

  /**Sent the validation report to Host**/
  Uart_Tx(Test_Context_Ptr, (uint8_t*)execution_timings_buff, sizeof(execution_timings_buff), APP_FRAMEOPERATION_NUM*sizeof(uint32_t));

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Upload_NonRegression_Debug_Report(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /***************UPLOAD_NONREG_DEBUG_REPORT_CMD****************
  *Uploads the non-regression debug report to the host
  *This command has no parameter.
  **************************************************************/

  /**Sent the whole dumped data to Host**/
  Uart_Tx(Test_Context_Ptr, (uint8_t*)dump_intermediate_data_ping_buff, sizeof(dump_intermediate_data_ping_buff), DUMP_INTERMEDIATE_DATA_BUFFER_SIZE);
  Uart_Tx(Test_Context_Ptr, (uint8_t*)dump_intermediate_data_pong_buff, sizeof(dump_intermediate_data_pong_buff), DUMP_INTERMEDIATE_DATA_BUFFER_SIZE);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Get_Validation_Final_Accuracy(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /***************GET_VALIDATION_ACCURACY_CMD****************
  *Get the validation final accuracy
  *This command has no parameter.
  ***********************************************************/

  /**Sent the validation final accuracy**/
  *((float*)aTxBuffer) = Test_Context_Ptr->ValidationContext.final_accuracy;
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), sizeof(Test_Context_Ptr->ValidationContext.final_accuracy));

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}


static void UartCmd_Launch_Dump(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************LAUNCH_DUMP_CMD**************************************
  *Launch the Dump mode.
  *This command has two parameters:
  *Dump sub-mode (1 byte): CAMERA_LIVE= 0x01, CAMERA_COLORBAR= 0x02, SDCARD_FILE= 0x03
  *Dump memory location (1 byte): SDCARD (0x00) or SDRAM (0x01)
  ***********************************************************************************/

  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;

  Test_Context_Ptr->UartContext.uart_cmd_ongoing = 1;
  Test_Context_Ptr->UartContext.uart_host_requested_mode=DUMP;
  App_Cxt_Ptr->run_loop = 0;

  Test_Context_Ptr->UartContext.uart_host_requested_dump_submode=(MemDumpFrameSource_TypeDef)(*(uint8_t*)(data_buffer));
  Test_Context_Ptr->UartContext.uart_host_requested_dump_memory=(MemDumpMemoryLocation_TypeDef)(*(uint8_t*)(data_buffer+1));

  if(Test_Context_Ptr->UartContext.uart_host_requested_dump_memory == SDRAM)
    Test_Context_Ptr->DumpContext.dump_write_bufferPtr=dump_intermediate_data_ping_buff;
}

static void UartCmd_Trigger_Dump(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /************************TRIGGER_DUMP_CMD********************************************************************************
  *Triggers a dump.
  *This command has one parameter:
  *Dump trigger mode (2 bytes): number of consecutive dump to execute - 1  (0x0000 <=> one dump, 0x0001 <=> two dumps, etc. and 0xFFFF <=> continuous mode which is a debug mode)
  ************************************************************************************************************************/

  /*Check if already in DUMP mode*/
  if(Test_Context_Ptr->UartContext.uart_host_requested_mode==DUMP)
  {
    Test_Context_Ptr->UartContext.uart_cmd_ongoing = 1;

    Test_Context_Ptr->DumpContext.dump_state = 1;

    Test_Context_Ptr->UartContext.uart_host_requested_dump_number=*(uint16_t*)(data_buffer);

    /**RAZ the dump_output_buff located in external memory**/
    for(uint32_t i=0; i<AI_NET_OUTPUT_SIZE;i++)
    {
      dump_output_buff[i]=0x00;
    }
  }
  else
  {
    /**Sent "CMD ERROR" Event to Host**/
    *(aTxBuffer) = CMD_ERROR_EVT;
    Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);

    /**Configure the UART in reception mode for receiving subsequent command from Host**/
    Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
  }
}

static void UartCmd_Launch_Capture(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /*************************************************LAUNCH_CAPTURE_CMD***********************************************************
  *Launch the Capture mode.
  *This command has three parameters:
  *Capure format (1 byte): possible values are RAW= 0x03, BMP= 0x04
  *Inter-capture delay (2 bytes): expressed in milliseconds, for 'automatic' capture mode. If equals zero=> 'manual' capture mode
  *Number of capture (2 bytes): applies for 'automatic' mode only
  *******************************************************************************************************************************/

  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;

  Test_Context_Ptr->UartContext.uart_cmd_ongoing = 1;
  Test_Context_Ptr->UartContext.uart_host_requested_mode=CAPTURE;
  App_Cxt_Ptr->run_loop = 0;

  Test_Context_Ptr->UartContext.uart_host_requested_capture_format=(DataFormat_TypeDef)(*(uint8_t*)(data_buffer));
  Test_Context_Ptr->UartContext.uart_host_requested_capture_delay=*(uint16_t*)(data_buffer+1);
  Test_Context_Ptr->UartContext.uart_host_requested_capture_number=*(uint16_t*)(data_buffer+3);

  if(Test_Context_Ptr->UartContext.uart_host_requested_capture_delay == 0)
  {
    /*Manual mode*/
    ;
  }
  else
  {
    /*Automatic mode => Program TIM for periodic capture*/
    ;
  }
}

static void UartCmd_Trigger_Capture(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /************************TRIGGER_CAPTURE_CMD**********************
  *Triggers a capture when in 'manual' mode.
  *This command has no parameter.
  ******************************************************************/

  /*Check if already in CAPTURE 'manual' mode*/
  if((Test_Context_Ptr->UartContext.uart_host_requested_mode==CAPTURE)&&(Test_Context_Ptr->UartContext.uart_host_requested_capture_delay==0))
  {
    Test_Context_Ptr->UartContext.uart_cmd_ongoing = 1;
    Test_Context_Ptr->CaptureContext.capture_state = 1;
  }
  else
  {
    /**Sent "CMD ERROR" Event to Host**/
    *(aTxBuffer) = CMD_ERROR_EVT;
    Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);

    /**Configure the UART in reception mode for receiving subsequent command from Host**/
    Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
  }
}

static void UartCmd_Get_Valid_Output_Size(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************GET_VALIDATION_OUTPUT_SIZE_CMD**********************
  *Returns the size (in bytes) of the output generated by the Validation process.
  *This command has no parameter.
  ***********************************************************************************/

  /**Sent the validation output size to Host**/
  *((uint32_t*)aTxBuffer) = AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE_BYTES*NUM_FILE_PER_DIR;
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), 4);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Upload_Valid_Output(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************UPLOAD_VALIDATION_OUTPUT_CMD**********************
  *Upload the output of the validation execution.
  *This command has no parameter.
  ***********************************************************************************/

  /**Sent the validation output data to Host**/
  Uart_Tx(Test_Context_Ptr, (uint8_t*)validation_output_buff, sizeof(validation_output_buff), AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE_BYTES*NUM_FILE_PER_DIR);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Get_Dump_Output_Data_Size(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************GET_DUMP_OUTPUT_DATA_SIZE_CMD**********************
  *Returns the size (in bytes) of only of the NN output generated by the Dump process.
  *This command has no parameter.
  ***********************************************************************************/

  /**Sent the dump output size to Host**/
  *((uint16_t*)aTxBuffer) = AI_NET_OUTPUT_SIZE_BYTES;
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), 2);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Upload_Dump_Output_Data(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************UPLOAD_DUMP_OUTPUT_DATA_CMD*************************
  *Upload the output of the dump execution, i.e. the NN output.
  *This command has no parameter.
  ***********************************************************************************/

  /**Sent the dump output data to Host**/
  Uart_Tx(Test_Context_Ptr, (uint8_t*)dump_output_buff, sizeof(dump_output_buff), AI_NET_OUTPUT_SIZE_BYTES);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Get_Dump_Whole_Data_Size(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************GET_DUMP_WHOLE_DATA_SIZE_CMD************************
  *Returns the size (in bytes) of the whole data generated by the Dump process.
  *This command has no parameter.
  ***********************************************************************************/

  /**Sent the dump output size to Host**/
  *((uint32_t*)aTxBuffer) = DUMP_INTERMEDIATE_DATA_BUFFER_SIZE;
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), 4);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Upload_Dump_Whole_Data(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /***********************************UPLOAD_DUMP_WHOLE_DATA_CMD*****************************
  *Upload the whole dumped data: i.e. the NN output as well as all the intermediate buffers.
  *This command has one parameter:
  *Buffer to be uploaded (1 byte): PING  (0x00) or PONG (0x01)
  ******************************************************************************************/

  /**Sent the whole dumped data to Host**/
  if((*(uint8_t*)(data_buffer))== 0x00)
  {
    Uart_Tx(Test_Context_Ptr, (uint8_t*)dump_intermediate_data_ping_buff, sizeof(dump_intermediate_data_ping_buff), DUMP_INTERMEDIATE_DATA_BUFFER_SIZE);
  }
  else if((*(uint8_t*)(data_buffer))== 0x01)
  {
    Uart_Tx(Test_Context_Ptr, (uint8_t*)dump_intermediate_data_pong_buff, sizeof(dump_intermediate_data_pong_buff), DUMP_INTERMEDIATE_DATA_BUFFER_SIZE);
  }
  else
  {
    /**Sent "CMD ERROR" Event to Host**/
    *(aTxBuffer) = CMD_ERROR_EVT;
    Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);
  }

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Read_Camera_Register(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************READ_CAMERA_REGISTER_CMD**********************
  *Read and return the content of a list of camera registers
  *This command has two parameters:
  *Register list start address (1 byte)
  *Register list end address (1 byte)
  *NB: registers at both start and end address are included in the list!
  ***********************************************************************************/
  uint32_t Num_reg_to_read=(*(data_buffer+1) - *data_buffer)+1;

  /**Read the list of register's content**/
  for(uint8_t i=0; i<Num_reg_to_read;i++)
  {
    OV9655_Object_t *pObj=Camera_CompObj;
    uint8_t tmp;

    ov9655_read_reg(&pObj->Ctx, *(data_buffer+i), &tmp, 1);

    Cam_Reg_Table[i]=tmp;
  }

  /**Sent the list of camera register's content to Host**/
  Uart_Tx(Test_Context_Ptr, (uint8_t*)Cam_Reg_Table, sizeof(Cam_Reg_Table), Num_reg_to_read);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Write_Camera_Register(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************WRITE_CAMERA_REGISTER_CMD**********************
  *Write the content of a camera register
  *This command has two parameters:
  *Register address (1 bytes)
  *Register value to be written (1 byte)
  ***********************************************************************************/
  OV9655_Object_t *pObj=Camera_CompObj;
  uint8_t tmp=*(data_buffer+1);

  ov9655_write_reg(&pObj->Ctx, *(data_buffer), &tmp, 1);

  HAL_Delay(300);

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

static void UartCmd_Set_Camera_Mode(TestContext_TypeDef *Test_Context_Ptr, uint8_t* data_buffer, uint16_t data_size)
{
  /******************************SET_CAMERA_MODE_CMD**********************
  *Configure the camera in test bar or normal mode.
  *This command has one parameter:
  *Camera mode: 0x00=Normal, 0x01= Test bar
  ***********************************************************************************/
  OV9655_Object_t *pObj=Camera_CompObj;
  uint8_t tmp;

  if(*(data_buffer) == 0x00)
  {
    tmp=0x00;

    ov9655_write_reg(&pObj->Ctx, /*0x8D*/OV9655_COMMON_CTRL20, &tmp, 1);
    HAL_Delay(300);

    ov9655_write_reg(&pObj->Ctx, /*0x0C*/OV9655_COMMON_CTRL3, &tmp, 1);
    HAL_Delay(300);
  }
  else if(*(data_buffer) == 0x01)
  {
    tmp=0x10;

    ov9655_write_reg(&pObj->Ctx, /*0x8D*/OV9655_COMMON_CTRL20, &tmp, 1);
    HAL_Delay(300);
  }
  if(*(data_buffer) == 0x02)
  {
    CAMERA_Set_TestBar_Mode(NULL);
  }

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
}

/**
 * @brief Displays the confusion matrix to screen
 *
 * @param conf_matrix confusion matrix as a 2D array of uint32_t
 */
static void DisplayConfusionMatrix(uint32_t conf_matrix[AI_NET_OUTPUT_SIZE][AI_NET_OUTPUT_SIZE])
{
  /* Heat-map LUTs */
  static const uint32_t heat_map[10] = {0xff07071d, 0xff461c48, 0xff6e1f57, 0xff951c5b, 0xffbf1654,
  0xffdf2f44, 0xfff16445, 0xfff58860, 0xfff6b995, 0xfff8dcc};

  /* find max value of confusion matrix */
  int conf_max = 0;
  for (int row = 0; row < NN_OUTPUT_CLASS_NUMBER; row++)
  {
    for (int col = 0; col < NN_OUTPUT_CLASS_NUMBER; col++)
    {
      if (conf_matrix[row][col] > conf_max)
      {
        conf_max = conf_matrix[row][col];
      }
    }
  }

  /* Set a smaller font to fit screen */
  UTIL_LCD_SetFont(&Font12);

  /* Offset from top-left of LCD */
  const int x_off = 385;
  const int y_off = 60;
  char conf_value[8];
  for (int row = 0; row < NN_OUTPUT_CLASS_NUMBER; row++)
  {
    for (int col = 0; col < NN_OUTPUT_CLASS_NUMBER; col++)
    {
      uint32_t value = conf_matrix[row][col];
      if (value > 0)
      {
        float value_norm = value / (float)(conf_max + 1);
        int heat_map_idx = (int)floorf(value_norm * 9.0f);
        UTIL_LCD_SetBackColor(heat_map[heat_map_idx]);
        uint32_t text_color = heat_map_idx > 5 ? UTIL_LCD_COLOR_BLACK : UTIL_LCD_COLOR_WHITE;
        UTIL_LCD_SetTextColor(text_color);
        sprintf(conf_value, "%d", (unsigned int)conf_matrix[row][col]);
      }
      else
      {
        sprintf(conf_value, ".");
      }
      UTIL_LCD_DisplayStringAt(x_off + col * 20, y_off + row * 20, (uint8_t *)conf_value, LEFT_MODE);
      UTIL_LCD_SetBackColor(UTIL_LCD_COLOR_BLACK);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
    }
  }

  UTIL_LCD_SetFont(&Font20);
}
#endif /* !OBJECTDETECT */

/**
 * @brief Look for the index of a class name in the global NN_OUTPUT_CLASS_LIST array
 *
 * @param className string to look for in NN_OUTPUT_CLASS_LIST
 * @return int index of the class, -1 if not found
 */
static int FindClassIndexFromString(char *className)
{
  for (size_t j = 0; j < AI_NET_OUTPUT_SIZE; j++)
  {
    if (strcmp(className, NN_OUTPUT_CLASS_LIST[j]) == 0)
    {
      return j;
    }
  }

  /* Class name was not found, return -1 */
  return -1;
}

#ifndef OBJECTDETECT
/**
 * @brief Displays a classification report to screen
 *        inspired from scikit-learn classification_report()
 *
 * @param TestContext_Ptr pointer to test context
 * @param report pointer to classification report
 */
static void DisplayClassificationReport(TestContext_TypeDef * TestContext_Ptr, const ClassificationReport_Typedef *report)
{
  char line[64];
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;

  UTIL_LCD_DisplayStringAt(320, LINE(0), (uint8_t *)"precision recall f1-score support", LEFT_MODE);
  for (uint32_t target = 0; target < AI_NET_OUTPUT_SIZE; target++)
  {
    sprintf(line, "%20s %8.3f %8.3f %8.3f %4d", NN_OUTPUT_CLASS_LIST[target], report->precisions[target],
            report->recalls[target], report->f1_scores[target], (unsigned int)report->supports[target]);

    UTIL_LCD_DisplayStringAt(40, LINE(2 + target), (uint8_t *)line, LEFT_MODE);
  }

  sprintf(line, "%20s %26.3f %4d", "accuracy", report->accuracy, (unsigned int)report->total_support);
  UTIL_LCD_DisplayStringAt(40, LINE(3 + AI_NET_OUTPUT_SIZE), (uint8_t *)line, LEFT_MODE);
  sprintf(line, "%20s %8.3f %8.3f %8.3f %4d", "macro avg", report->macro_avg_precision, report->macro_avg_recall,
          report->macro_avg_f1_score, (unsigned int)report->total_support);
  UTIL_LCD_DisplayStringAt(40, LINE(4 + AI_NET_OUTPUT_SIZE), (uint8_t *)line, LEFT_MODE);
  sprintf(line, "%20s %8.3f %8.3f %8.3f %4d", "weighted avg", report->weighted_avg_precision,
          report->weighted_avg_recall, report->weighted_avg_f1_score, (unsigned int)report->total_support);
  UTIL_LCD_DisplayStringAt(40, LINE(5 + AI_NET_OUTPUT_SIZE), (uint8_t *)line, LEFT_MODE);

  DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
}

/**
 * @brief Writes a confusion matrix to a csv file on filesystem
 *
 * @param conf_matrix Confusion matrix as 2D array of uint32_t to be written
 * @param path path in the filesystem
 */
static void WriteConfusionMatrix(uint32_t conf_matrix[AI_NET_OUTPUT_SIZE][AI_NET_OUTPUT_SIZE], const char *path)
{
  FIL File;

  /* Deletes previous file */
  f_open(&File, path, FA_CREATE_ALWAYS | FA_WRITE);
  f_close(&File);

  f_open(&File, path, FA_OPEN_APPEND | FA_WRITE);
  f_printf(&File, ",Confusion Matrix\n\n");
  f_printf(&File, ",Predicted\n");

  for (int row = 0; row < NN_OUTPUT_CLASS_NUMBER; row++)
  {
    f_printf(&File, "%s,", NN_OUTPUT_CLASS_LIST[row]);
    for (int col = 0; col < NN_OUTPUT_CLASS_NUMBER; col++)
    {
      uint32_t value = conf_matrix[row][col];
      f_printf(&File, "%d,", value);
    }
    if (row == NN_OUTPUT_CLASS_NUMBER / 2)
    {
      f_printf(&File, " Ground truth");
    }
    f_printf(&File, "\n");
  }

  f_close(&File);
}

/**
 * @brief Writes the classification report in a text file on filesystem
 *
 * @param report pointer to classification report
 * @param path pointer to the file name path in the filesystem
 */
static void WriteClassificationReport(const ClassificationReport_Typedef *report, const char *path)
{
  FIL File;

  char line[64];
  int byteswritten;

  /* Deletes previous file */
  f_open(&File, path, FA_CREATE_ALWAYS | FA_WRITE);
  f_close(&File);

  f_open(&File, path, FA_OPEN_APPEND | FA_WRITE);

  f_printf(&File, "                       precision recall f1-score support\n");

  for (uint32_t target = 0; target < AI_NET_OUTPUT_SIZE; target++)
  {
    /* f_printf doesn't support floating point formating so f_write is used */
    sprintf(line, "%20s %8.3f %8.3f %8.3f %4d\n", NN_OUTPUT_CLASS_LIST[target], report->precisions[target],
            report->recalls[target], report->f1_scores[target], (unsigned int)report->supports[target]);
    f_write(&File, line, strlen(line), (void *)&byteswritten);
  }

  f_printf(&File, "\n");
  sprintf(line, "%20s %26.3f %4d\n", "accuracy", report->accuracy, (unsigned int)report->total_support);
  f_write(&File, line, strlen(line), (void *)&byteswritten);
  sprintf(line, "%20s %8.3f %8.3f %8.3f %4d\n", "macro avg", report->macro_avg_precision, report->macro_avg_recall,
          report->macro_avg_f1_score, (unsigned int)report->total_support);
  f_write(&File, line, strlen(line), (void *)&byteswritten);
  sprintf(line, "%20s %8.3f %8.3f %8.3f %4d\n", "weighted avg", report->weighted_avg_precision,
          report->weighted_avg_recall, report->weighted_avg_f1_score, (unsigned int)report->total_support);
  f_write(&File, line, strlen(line), (void *)&byteswritten);

  f_close(&File);
}

/**
 * @brief Creates a classification report from the confusion matrix.
 *        The classification report is inspired from
 *        scikit-learn.org/stable/modules/generated/sklearn.metrics.classification_report.html
 *
 * @param conf_matrix Confusion matrix from which the classification report should be created
 * @return ClassificationReport_Typedef Classification report as a structure
 */
static ClassificationReport_Typedef classification_report(uint32_t conf_matrix[AI_NET_OUTPUT_SIZE][AI_NET_OUTPUT_SIZE])
{
  ClassificationReport_Typedef report;

  uint32_t diagonal_sum = 0;
  uint32_t total_support = 0;

  /* For each class, compute precision, recall and f1-score */
  for (uint32_t target = 0; target < AI_NET_OUTPUT_SIZE; target++)
  {
    uint32_t true_positives = 0;
    uint32_t false_positives = 0;
    uint32_t false_negatives = 0;
    uint32_t support = 0;

    /* First pass columnwise to find false negatives */
    for (uint32_t pred = 0; pred < AI_NET_OUTPUT_SIZE; pred++)
    {
      support += conf_matrix[target][pred];

      if (target != pred)
      { /* False negatives */
        false_negatives += conf_matrix[target][pred];
      }
    } /* End pass columnwise */

    /* Second pass row-wise to compute false positives */
    for (uint32_t gtruth = 0; gtruth < AI_NET_OUTPUT_SIZE; gtruth++)
    {
      if (target != gtruth)
      { /* False positive */
        false_positives += conf_matrix[gtruth][target];
      }
    } /* End pass row-wise */

    /* True positives are in the diagonal */
    true_positives = conf_matrix[target][target];

    float precision = 0.0f;
    if ((true_positives + false_positives) != 0)
    {
      precision = true_positives / (float)(true_positives + false_positives);
    }
    float recall = 0.0f;
    if ((true_positives + false_negatives) != 0)
    {
      recall = true_positives / (float)(true_positives + false_negatives);
    }
    float f1_score = 0.0f;
    if ((recall + precision) != 0.0f)
    {
      f1_score = 2 * (recall * precision) / (recall + precision);
    }

    report.precisions[target] = precision;
    report.recalls[target] = recall;
    report.f1_scores[target] = f1_score;
    report.supports[target] = support;

    /* Increment total numbers to compute accuracy */
    diagonal_sum += true_positives;
    total_support += support;

  } /* End for target class */

  report.accuracy = 0.0f;
  if (total_support != 0)
  {
    report.accuracy = diagonal_sum / (float)total_support;
  }

  report.total_support = total_support;

  /* Compute macro average and weighted average */
  report.macro_avg_precision = 0.0f;
  report.macro_avg_recall = 0.0f;
  report.macro_avg_f1_score = 0.0f;

  report.weighted_avg_precision = 0.0f;
  report.weighted_avg_recall = 0.0f;
  report.weighted_avg_f1_score = 0.0f;

  for (uint32_t target = 0; target < AI_NET_OUTPUT_SIZE; target++)
  {
    report.macro_avg_precision += (float)report.precisions[target];
    report.macro_avg_recall += (float)report.recalls[target];
    report.macro_avg_f1_score += (float)report.f1_scores[target];

    report.weighted_avg_precision += (float)report.precisions[target] * report.supports[target];
    report.weighted_avg_recall += (float)report.recalls[target] * report.supports[target];
    report.weighted_avg_f1_score += (float)report.f1_scores[target] * report.supports[target];
  }
  report.macro_avg_precision /= (float)AI_NET_OUTPUT_SIZE;
  report.macro_avg_recall /= (float)AI_NET_OUTPUT_SIZE;
  report.macro_avg_f1_score /= (float)AI_NET_OUTPUT_SIZE;

  report.weighted_avg_precision /= (float)report.total_support;
  report.weighted_avg_recall /= (float)report.total_support;
  report.weighted_avg_f1_score /= (float)report.total_support;

  return report;
}
#endif /* !OBJECTDETECT */

/**
 * @brief Initializes the Frame capture mode
 *
 * @param TestContext_Ptr pointer to test context
 */
static void FrameCaptureInit(TestContext_TypeDef *Test_Context_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;

  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

  UTIL_LCD_DrawRect(200, 10, 400, 50, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"Capture file format", CENTER_MODE);

  UTIL_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)"Press one of the key of the joystick", CENTER_MODE);
  UTIL_LCD_DisplayStringAt(0, LINE(6), (uint8_t *)"to select the format of the captured files", CENTER_MODE);

  /* Draw the "joystick arrows" */
  struct point_t
  {
    uint16_t x;
    uint16_t y;
  };
  const struct point_t pt_center = {.x = 400, .y = 350}; /* x,y coordinates */
  const uint16_t pt_offset = 50;                         /* pixels offset from the center (wideness of the square) */

  UTIL_LCD_DrawLine(pt_center.x - pt_offset, pt_center.y, pt_center.x, pt_center.y - pt_offset, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x, pt_center.y - pt_offset, pt_center.x + pt_offset, pt_center.y, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x + pt_offset, pt_center.y, pt_center.x, pt_center.y + pt_offset, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x, pt_center.y + pt_offset, pt_center.x - pt_offset, pt_center.y, UTIL_LCD_COLOR_WHITE);

  const char *appli_names[] = {"RAW", "BMP"};

  UTIL_LCD_DisplayStringAt(0, pt_center.y - pt_offset - LINE(2), (uint8_t*)appli_names[0], CENTER_MODE);//UP
 // UTIL_LCD_DisplayStringAt(pt_center.x + pt_offset + 10, pt_center.y - LINE(1) / 2, (uint8_t*)appli_names[1], LEFT_MODE);//RIGHT
  UTIL_LCD_DisplayStringAt(0, pt_center.y + pt_offset + LINE(1), (uint8_t*)appli_names[1], CENTER_MODE);//DOWN
 // UTIL_LCD_DisplayStringAt(20, pt_center.y - LINE(1) / 2, (uint8_t*)appli_names[3], LEFT_MODE);//LEFT

  DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

  if(Test_Context_Ptr->UartContext.uart_cmd_ongoing)
  {
  #ifndef OBJECTDETECT
    switch (Test_Context_Ptr->UartContext.uart_host_requested_capture_format)
    {
    case RAW:
      Test_Context_Ptr->CaptureContext.capture_file_format=RAW;
      break;
    case BMP:
      Test_Context_Ptr->CaptureContext.capture_file_format=BMP;
      break;
    default:
      break;
    }

    Test_Context_Ptr->UartContext.uart_cmd_ongoing = 0;

    /**Configure the UART in reception mode for receiving subsequent command from Host**/
    Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
  #endif /* !OBJECTDETECT */
  }
  else
  {
    HAL_Delay(200);
    JOYPin_TypeDef joy_state = JOY_NONE;
    while (joy_state == JOY_NONE || joy_state == JOY_RIGHT || joy_state == JOY_LEFT || joy_state == JOY_SEL)
    {
      joy_state = (JOYPin_TypeDef) BSP_JOY_GetState(JOY1, 0);
    }

    switch (joy_state)
    {
    case JOY_UP:
      Test_Context_Ptr->CaptureContext.capture_file_format=RAW;
      break;
    case JOY_DOWN:
      Test_Context_Ptr->CaptureContext.capture_file_format=BMP;
      break;
    default:
      break;
    };
  }

  /* Init Random Number Generator */
  Test_Context_Ptr->RngHandle.Instance = RNG;
  HAL_RNG_DeInit(&Test_Context_Ptr->RngHandle);
  HAL_RNG_Init(&Test_Context_Ptr->RngHandle);

  /* Generate a session ID */
  HAL_RNG_GenerateRandomNumber(&Test_Context_Ptr->RngHandle, &Test_Context_Ptr->CaptureContext.capture_session_id);

  sprintf(Test_Context_Ptr->CaptureContext.capture_session_name, "Session %X", (unsigned int)Test_Context_Ptr->CaptureContext.capture_session_id);

  /* Init SDCard */
  if (BSP_SD_Init(0) != BSP_ERROR_NONE)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. SD Card not detected", CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
    BSP_LED_On(LED_RED);
    while (1);
  }

  /* Init STM32Fs library */
  STM32Fs_Init();

  /*Create folder with session name where all the captures will be stored*/
  STM32Fs_CreateDir("/Camera_Capture");
  sprintf(Test_Context_Ptr->CaptureContext.capture_folder_name, "/Camera_Capture/CAM_CAPTURE_SESS_%X", (unsigned int)Test_Context_Ptr->CaptureContext.capture_session_id);
  STM32Fs_CreateDir(Test_Context_Ptr->CaptureContext.capture_folder_name);

  BSP_SD_DeInit(0);
}

/**
 * @brief Initializes the memory dump mode
 *
 * @param TestContext_Ptr pointer to test context
 */
static void MemoryDumpInit(TestContext_TypeDef *Test_Context_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;
  uint32_t nbr_dir;
  stm32fs_err_t ret;
#if CAMERA_CAPTURE_RES == VGA_640_480_RES
  char  dump_dir_path[64]=  "/dump_src_image_vga";
#elif CAMERA_CAPTURE_RES == QVGA_320_240_RES
  char dump_dir_path[64]=  "/dump_src_image_qvga";
#endif

  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

  UTIL_LCD_DrawRect(200, 10, 400, 50, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"Memory dump sub-mode", CENTER_MODE);

  UTIL_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)"Press one of the key of the joystick", CENTER_MODE);
  UTIL_LCD_DisplayStringAt(0, LINE(6), (uint8_t *)"to select the frame source", CENTER_MODE);

  /* Draw the "joystick arrows" */
  struct point_t
  {
    uint16_t x;
    uint16_t y;
  };
  const struct point_t pt_center = {.x = 400, .y = 350}; /* x,y coordinates */
  const uint16_t pt_offset = 50;                         /* pixels offset from the center (wideness of the square) */

  UTIL_LCD_DrawLine(pt_center.x - pt_offset, pt_center.y, pt_center.x, pt_center.y - pt_offset, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x, pt_center.y - pt_offset, pt_center.x + pt_offset, pt_center.y, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x + pt_offset, pt_center.y, pt_center.x, pt_center.y + pt_offset, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x, pt_center.y + pt_offset, pt_center.x - pt_offset, pt_center.y, UTIL_LCD_COLOR_WHITE);

  const char *appli_names[] = {"Camera live", "Test Color Bar", "SD card"};

  UTIL_LCD_DisplayStringAt(0, pt_center.y - pt_offset - LINE(2), (uint8_t*)appli_names[0], CENTER_MODE);//UP
  UTIL_LCD_DisplayStringAt(pt_center.x + pt_offset + 10, pt_center.y - LINE(1) / 2, (uint8_t*)appli_names[1], LEFT_MODE);//RIGHT
  //UTIL_LCD_DisplayStringAt(0, pt_center.y + pt_offset + LINE(1), (uint8_t*)appli_names[1], CENTER_MODE);//DOWN
  UTIL_LCD_DisplayStringAt(200, pt_center.y - LINE(1) / 2, (uint8_t*)appli_names[2], LEFT_MODE);//LEFT

  DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

  if(Test_Context_Ptr->UartContext.uart_cmd_ongoing)
  {
  #ifndef OBJECTDETECT
    switch (Test_Context_Ptr->UartContext.uart_host_requested_dump_submode)
    {
    case CAMERA_LIVE:
      Test_Context_Ptr->DumpContext.Dump_FrameSource=CAMERA_LIVE;
      break;

    case CAMERA_COLORBAR:
      Test_Context_Ptr->DumpContext.Dump_FrameSource=CAMERA_COLORBAR;

      /* Initialize the CAMERA */
      CAMERA_Init(App_Cxt_Ptr->Camera_ContextPtr);

      /*Set CAMERA in test bar mode*/
      CAMERA_Set_TestBar_Mode(App_Cxt_Ptr->Camera_ContextPtr);

      break;

    case SDCARD_FILE:
      Test_Context_Ptr->DumpContext.Dump_FrameSource=SDCARD_FILE;

      break;

    default:
      break;
    }

    if(Test_Context_Ptr->UartContext.uart_host_nonreg_run==1)
    {
      Test_Context_Ptr->DumpContext.dump_state = 1;

      Test_Context_Ptr->UartContext.uart_host_nonreg_run=0;

      /**RAZ the dump_output_buff located in external memory**/
      for(uint32_t i=0; i<AI_NET_OUTPUT_SIZE;i++)
      {
        dump_output_buff[i]=0x00;
      }
    }
    else
    {
      Test_Context_Ptr->UartContext.uart_cmd_ongoing = 0;

      /**Configure the UART in reception mode for receiving subsequent command from Host**/
      Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
    }
  #endif /* !OBJECTDETECT */
  }
  else
  {

    HAL_Delay(200);
    JOYPin_TypeDef joy_state = JOY_NONE;
    while (joy_state == JOY_NONE || joy_state == JOY_DOWN || joy_state == JOY_SEL)
    {
      joy_state = (JOYPin_TypeDef) BSP_JOY_GetState(JOY1, 0);
    }

    switch (joy_state)
    {
    case JOY_UP:
      Test_Context_Ptr->DumpContext.Dump_FrameSource=CAMERA_LIVE;
      break;

    case JOY_RIGHT:
      Test_Context_Ptr->DumpContext.Dump_FrameSource=CAMERA_COLORBAR;

      /* Initialize the CAMERA */
      CAMERA_Init(App_Cxt_Ptr->Camera_ContextPtr);

      /*Set CAMERA in test bar mode*/
      CAMERA_Set_TestBar_Mode(App_Cxt_Ptr->Camera_ContextPtr);

      break;

    case JOY_LEFT:
      Test_Context_Ptr->DumpContext.Dump_FrameSource=SDCARD_FILE;

   break;

    default:
      break;
    };

  }

  /* Init SDCard */
  if (BSP_SD_Init(0) != BSP_ERROR_NONE)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. SD Card not detected", CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
    BSP_LED_On(LED_RED);
    while (1);
  }

  /* Init STM32Fs library */
  STM32Fs_Init();

  /* Init Random Number Generator */
  Test_Context_Ptr->RngHandle.Instance = RNG;
  HAL_RNG_DeInit(&Test_Context_Ptr->RngHandle);
  HAL_RNG_Init(&Test_Context_Ptr->RngHandle);

  /*Create folder where all the dumps will be stored*/
  sprintf(Test_Context_Ptr->DumpContext.dump_folder_name, "/Memory_Dump");
  STM32Fs_CreateDir(Test_Context_Ptr->DumpContext.dump_folder_name);

  if(Test_Context_Ptr->DumpContext.Dump_FrameSource==SDCARD_FILE)
  {
    /* Open the 'dump_src_image_vga or qvga' directory */
    nbr_dir = 0;
    ret = STM32Fs_GetNumberFiles(dump_dir_path, &nbr_dir, STM32FS_COUNT_DIRS);
    if (ret == STM32FS_ERROR_DIR_NOT_FOUND)
    {
      UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Directory 'dataset' doesn't exist", CENTER_MODE);
      DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
      BSP_LED_On(LED_RED);
      while (1)
        ;
    }

    if (nbr_dir != 0)
    {
      UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Number of found directories incorrect", CENTER_MODE);
      DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
      BSP_LED_On(LED_RED);
      while (1)
        ;
    }
  }
  else
  {
    BSP_SD_DeInit(0);
  }
}

/**
 * @brief Initializes the "on-board" validation mode
 * @param TestContext_Ptr pointer to test context
 */
static void OnBoardValidInit(TestContext_TypeDef *Test_Context_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;
  uint8_t sd_error;
  uint32_t nbr_dir;
  stm32fs_err_t ret;
  char valid_dir_path[64];


  DisplayIntroMessage(Test_Context_Ptr);

  /* Init SDCard */
  sd_error = BSP_SD_Init(0);
  if (sd_error != BSP_ERROR_NONE)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. SD Card not detected", CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
    BSP_LED_On(LED_RED);
    while (1)
      ;
  }

  /* Init STM32Fs library */
  STM32Fs_Init();

  /* Open the 'onboard_valid_dataset_qvga or vga' directory */
  nbr_dir = 0;

  strcpy(valid_dir_path, Test_Context_Ptr->ValidationContext.class_path);
  valid_dir_path[strlen(valid_dir_path)-1]='\0';/*so to remove the '/' at the end of the string*/
  ret = STM32Fs_GetNumberFiles(valid_dir_path, &nbr_dir, STM32FS_COUNT_DIRS);
  if (ret == STM32FS_ERROR_DIR_NOT_FOUND)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Directory 'onboard_valid_dataset' doesn't exist", CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
    BSP_LED_On(LED_RED);
    while (1)
      ;
  }

#ifndef OBJECTDETECT
  if (nbr_dir != AI_NETWORK_OUT_1_SIZE)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Number of found directories incorrect", CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
    BSP_LED_On(LED_RED);
    while (1)
      ;
  }
#endif /* !OBJECTDETECT */

  /* Start validation */
  BSP_LED_On(LED_GREEN);

#ifndef OBJECTDETECT
  /* Create the 'missclassified'  file */
  sprintf(tmp_msg, "List of missclassified files:\n");
  if (STM32Fs_WriteTextToFile("missclassified.txt", tmp_msg, STM32FS_CREATE_NEW_FILE) != STM32FS_ERROR_NONE)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Unable to create the missclassified file", CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
    BSP_LED_On(LED_RED);
    while (1)
      ;
  }
#endif /* !OBJECTDETECT */

  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

  UTIL_LCD_SetFont(&Font20);
  sprintf(tmp_msg, "Found %d classes", (unsigned int)nbr_dir);
  UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)tmp_msg, CENTER_MODE);

  STM32Fs_OpenDir(valid_dir_path, &Test_Context_Ptr->ValidationContext.dataset_dir);

  /* Go into first directory in "/onboard_valid_dataset_qvga or vga" directory */
  if(STM32Fs_GetNextDir(&Test_Context_Ptr->ValidationContext.dataset_dir, &Test_Context_Ptr->ValidationContext.fno) != STM32FS_ERROR_NONE)
    while(1);

#ifndef OBJECTDETECT
  /* Find corresponding class index */
  Test_Context_Ptr->ValidationContext.class_index = FindClassIndexFromString(Test_Context_Ptr->ValidationContext.fno.fname);

  if(Test_Context_Ptr->ValidationContext.class_index == -1)
  { /* Class index was not found */
    sprintf(tmp_msg, "Error, class %s doesn't exists", Test_Context_Ptr->ValidationContext.fno.fname);
    UTIL_LCD_DisplayStringAt(0, LINE(3), (uint8_t *)tmp_msg, CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
    BSP_LED_On(LED_RED);
    while (1)
      ;
  }
#endif /* !OBJECTDETECT */

  strcpy(Test_Context_Ptr->ValidationContext.tmp_class_path, ""); //string "null"
  strcpy(Test_Context_Ptr->ValidationContext.tmp_class_path, Test_Context_Ptr->ValidationContext.class_path );
  strcat(Test_Context_Ptr->ValidationContext.tmp_class_path, Test_Context_Ptr->ValidationContext.fno.fname);
  STM32Fs_OpenDir(Test_Context_Ptr->ValidationContext.tmp_class_path, &Test_Context_Ptr->ValidationContext.class_dir);

  /*reset*/
  Test_Context_Ptr->ValidationContext.validation_completed = 0;
}

#ifndef OBJECTDETECT
/**
 * @brief UART I/F Initialization
 *
 * @param TestContext_Ptr pointer to test context
 */
static void Uart_Init(TestContext_TypeDef *Test_Context_Ptr)
{
  /*########### Configure the UART peripheral ################*/
  /* Put the USART peripheral in the Asynchronous mode (UART Mode) */
  /* UART configured as follows as per VCOM config on H747 DK board:
  - Word Length = 8 Bits
  - Stop Bit    = One Stop bit
  - Parity      = NONE parity
  - BaudRate    = 115200 baud
  - Hardware flow control disabled (RTS and CTS signals) */
  Test_Context_Ptr->UartContext.UartHandle.Instance        = USARTx;

  Test_Context_Ptr->UartContext.UartHandle.Init.BaudRate   = 115200;
  Test_Context_Ptr->UartContext.UartHandle.Init.WordLength = UART_WORDLENGTH_8B;
  Test_Context_Ptr->UartContext.UartHandle.Init.StopBits   = UART_STOPBITS_1;
  Test_Context_Ptr->UartContext.UartHandle.Init.Parity     = UART_PARITY_NONE;
  Test_Context_Ptr->UartContext.UartHandle.Init.HwFlowCtl  = UART_HWCONTROL_NONE;
  Test_Context_Ptr->UartContext.UartHandle.Init.Mode       = UART_MODE_TX_RX;
  Test_Context_Ptr->UartContext.UartHandle.Init.OverSampling = UART_OVERSAMPLING_16;
  Test_Context_Ptr->UartContext.UartHandle.Init.ClockPrescaler  = UART_PRESCALER_DIV1;
  Test_Context_Ptr->UartContext.UartHandle.Init.OneBitSampling  = UART_ONE_BIT_SAMPLE_DISABLE;

  if(HAL_UART_Init(&Test_Context_Ptr->UartContext.UartHandle) != HAL_OK)
  {
    /* Initialization Error */
    Error_Handler();
  }

  /**Sent alive msg to the host**/
  char alive_msg[64]="Board ON & UART link OK \n";
  strcpy((char*)aTxBuffer, alive_msg);
  Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), strlen (alive_msg));

  /**Configure the UART in reception mode for receiving subsequent command from Host**/
#ifdef OBJECTDETECT
//for the moment , we don't use reception  mode in the yoloLC project and it interfers with USART transmit used for transmitting the yoloLC result via the USART (transmitting result usart is not mendatory, it can be better than using the sd card interface)
#else
  Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
#endif /* OBJECTDETECT */
}

/**
 * @brief Configure and start TX on UART
 *
 * @param TestContext_Ptr pointer to test context
 * @param TxDataBufPtr pointer to the buffer containing the data to TX
 * @param TxDataBufSize Data size in bytes of the TX buffer
 * @param TxDataTransferSize Data size in bytes of the TX transfer
 */
static void Uart_Tx(TestContext_TypeDef *Test_Context_Ptr, uint8_t *TxDataBufPtr, uint32_t TxDataBufSize, uint32_t TxDataTransferSize)
{
  /*Check that TxDataTransferSize is lower or equal to TxDataBufSize*/
  if(TxDataTransferSize > TxDataBufSize)
    while(1);

  /*Perform D-Cache clean before DMA transfer*/
  UTILS_DCache_Coherency_Maintenance((void *)TxDataBufPtr, TxDataBufSize, CLEAN);

  if(TxDataTransferSize<0xFFFF)
  {
    /* Start transmission data */
    if(HAL_UART_Transmit_DMA(&Test_Context_Ptr->UartContext.UartHandle, (uint8_t*)TxDataBufPtr, TxDataTransferSize)!= HAL_OK)
    {
      /* Transfer error in transmission process */
      Error_Handler();
    }
    /*######## Wait for the end of the transfer ######*/
    while (HAL_UART_GetState(&Test_Context_Ptr->UartContext.UartHandle) != HAL_UART_STATE_READY);
  }
  else
  {
    uint32_t dma_xfer_num;
    uint32_t i;

    dma_xfer_num=TxDataTransferSize/0xFFFF;

    for(i=0;i<dma_xfer_num;i++)
    {
      /* Start transmission data */
      if(HAL_UART_Transmit_DMA(&Test_Context_Ptr->UartContext.UartHandle, (uint8_t*)(TxDataBufPtr+i*0xFFFF), 0xFFFF)!= HAL_OK)
      {
        /* Transfer error in transmission process */
        Error_Handler();
      }
      /*######## Wait for the end of the transfer ######*/
      while (HAL_UART_GetState(&Test_Context_Ptr->UartContext.UartHandle) != HAL_UART_STATE_READY);
    }

    if((TxDataTransferSize%0xFFFF)!=0)
    {
      /* Start transmission data */
      if(HAL_UART_Transmit_DMA(&Test_Context_Ptr->UartContext.UartHandle, (uint8_t*)(TxDataBufPtr+i*0xFFFF), TxDataTransferSize%0xFFFF)!= HAL_OK)
      {
        /* Transfer error in transmission process */
        Error_Handler();
      }
      /*######## Wait for the end of the transfer ######*/
      while (HAL_UART_GetState(&Test_Context_Ptr->UartContext.UartHandle) != HAL_UART_STATE_READY);
    }
  }
}

/**
 * @brief Configure and start RX on UART
 * @param TestContext_Ptr pointer to test context
 * @param RxDataBufPtr pointer to the buffer for storing the data to RX
 * @param RxDataSize Data size in bytes expected to RX
 */
static void Uart_Rx(TestContext_TypeDef *Test_Context_Ptr, uint8_t *RxDataBufPtr, uint32_t RxDataSize)
{
  /**Configure the UART in reception mode for receiving subsequent command from Host**/
  if (HAL_UART_Receive_DMA(&Test_Context_Ptr->UartContext.UartHandle, (uint8_t *)RxDataBufPtr, RxDataSize) != HAL_OK)
  {
    /* Transfer error in reception process */
    Error_Handler();
  }
}
#endif /* !OBJECTDETECT */

/**
 * @brief Displays to LCD an explanation on how to perform on-board validation
 *
 * @param TestContext_Ptr pointer to test context
 */
static void DisplayIntroMessage(TestContext_TypeDef *Test_Context_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;
  static const uint16_t margin = 15; /* margin for text in pixels*/

  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
  UTIL_LCD_DrawRect(200, 10, 400, 50, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"Onboard Validation", CENTER_MODE);

  UTIL_LCD_DisplayStringAt(margin, LINE(4), (uint8_t *)"Onboard validation will look for a directory", LEFT_MODE);
  UTIL_LCD_DisplayStringAt(margin, LINE(5), (uint8_t *)"named 'onboard_valid_dataset_vga or _qvga'", LEFT_MODE);
  UTIL_LCD_DisplayStringAt(margin, LINE(6), (uint8_t *)"at the root of the SDCard.", LEFT_MODE);
  UTIL_LCD_DisplayStringAt(margin, LINE(7), (uint8_t *)"This directory should contain one directory", LEFT_MODE);
  UTIL_LCD_DisplayStringAt(margin, LINE(8), (uint8_t *)"per class containing images in BPM 16 bpp", LEFT_MODE);
  UTIL_LCD_DisplayStringAt(margin, LINE(9), (uint8_t *)"format.", LEFT_MODE);

  UTIL_LCD_DisplayStringAt(margin, LINE(12), (uint8_t *)"Please insert the SDCard now,", LEFT_MODE);
  UTIL_LCD_DisplayStringAt(margin, LINE(13), (uint8_t *)"then press the WAKE-UP button to get started", LEFT_MODE);

  DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

  /* Wait for button input */
  while ((Test_Context_Ptr->UartContext.uart_cmd_ongoing==0) && (BSP_PB_GetState(BUTTON_WAKEUP) == RESET))
    ;
}

/**
 * @brief Post process for the CAPTURE mode
 *
 * @param TestContext_Ptr pointer to test context
 */
static void Capture_PostProcess(TestContext_TypeDef *TestContext_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;

  /* Check for user trigger in polling rather than w/ interrupt*/
  if ((TestContext_Ptr->CaptureContext.capture_state==0) /*&& (BSP_PB_GetState(BUTTON_WAKEUP) != RESET)*/)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)TestContext_Ptr->CaptureContext.capture_session_name, LEFT_MODE);
    UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"CAPTURE READY", RIGHT_MODE);

    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

    if(BSP_PB_GetState(BUTTON_WAKEUP) != RESET)
    {
      TestContext_Ptr->CaptureContext.capture_state = 1;
    }
  }
  else if(TestContext_Ptr->CaptureContext.capture_state==2)
  {
    TestContext_Ptr->CaptureContext.capture_state = 0;

    BSP_SD_DeInit(0);

    CAMERA_Init(App_Cxt_Ptr->Camera_ContextPtr);

#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
    while (!App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready);
    App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready = 0; /* Reset flag */
#endif

#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
    BSP_CAMERA_Resume(0);
#endif

  #ifndef OBJECTDETECT
    /////added to manage the uart cmd/////
    if(TestContext_Ptr->UartContext.uart_cmd_ongoing)
    {
      TestContext_Ptr->UartContext.uart_cmd_ongoing=0;//terminates the UART command processing

      /**Sent "CMD COMPLETE" Event to Host**/
      *(aTxBuffer) = CMD_COMPLETE_SUCCESS_EVT;
      Uart_Tx(TestContext_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);

      /**Configure the UART in reception mode for receiving subsequent command from Host**/
      Uart_Rx(TestContext_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
    }
  #endif /* !OBJECTDETECT */

    BSP_LED_On(LED_GREEN);
    BSP_LED_Off(LED_RED);
  }
}

/**
 * @brief Post process for the DUMP mode
 *
 * @param TestContext_Ptr pointer to test context
 */
static void Dump_PostProcess(TestContext_TypeDef *TestContext_Ptr)
{
  char msg[70];
#ifndef OBJECTDETECT
  uint8_t cmd_status=CMD_COMPLETE_SUCCESS_EVT;
#endif /* !OBJECTDETECT */
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;

  /* Check for user trigger in polling rather than w/ interrupt*/
  if(TestContext_Ptr->DumpContext.dump_state==0)
  {
    UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)TestContext_Ptr->DumpContext.dump_session_name, LEFT_MODE);
    UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"DUMP READY", RIGHT_MODE);

    /*Display output (for debug)*/
    sprintf(msg, "%s %.0f%%", App_Cxt_Ptr->nn_top1_output_class_name, App_Cxt_Ptr->nn_top1_output_class_proba * 100);
    UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_TOP_N_LAST_LINE - NN_TOP_N_DISPLAY + 0), (uint8_t *)msg, CENTER_MODE);
    sprintf(msg, "Inference: %ldms", App_Cxt_Ptr->nn_inference_time);
    UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_INFER_TIME_LINE), (uint8_t *)msg, CENTER_MODE);

    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

    if(BSP_PB_GetState(BUTTON_WAKEUP) != RESET)
    {
      TestContext_Ptr->DumpContext.dump_state = 1;
    }
  }
  else if(TestContext_Ptr->DumpContext.dump_state == 2)
  {
    if(TestContext_Ptr->DumpContext.Dump_FrameSource != SDCARD_FILE)
    {
      if((TestContext_Ptr->UartContext.uart_cmd_ongoing==0)|| (TestContext_Ptr->UartContext.uart_cmd_ongoing==1 && TestContext_Ptr->UartContext.uart_host_requested_dump_memory == SDCARD))
      {
        BSP_SD_DeInit(0);

        CAMERA_Init(App_Cxt_Ptr->Camera_ContextPtr);

        if(TestContext_Ptr->DumpContext.Dump_FrameSource == CAMERA_COLORBAR)
          /*Set CAMERA in test bar mode*/
          CAMERA_Set_TestBar_Mode(App_Cxt_Ptr->Camera_ContextPtr);

#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
        while (!App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready);
        App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready = 0; /* Reset flag */
#endif

#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
        BSP_CAMERA_Resume(0);
#endif
      }
    }
    else if(TestContext_Ptr->DumpContext.Dump_FrameSource == SDCARD_FILE)
    {
      ;
    }

    TestContext_Ptr->DumpContext.dump_state = 0;

  #ifndef OBJECTDETECT
    /////Manage the uart cmd/////
    if(TestContext_Ptr->UartContext.uart_cmd_ongoing)
    {
      if(TestContext_Ptr->UartContext.uart_host_requested_dump_memory == SDRAM)
      {
        uint32_t first_run=1;
        uint32_t issue_ocurence=0;

        /**check if first run**/
        for(uint32_t i=0; i<AI_NET_OUTPUT_SIZE;i++)
        {
          if(dump_output_buff[i]!=0)
            first_run =0;
        }

        if(first_run == 0)
        {
          /*if not the first run, compare the previous NN output with the current one*/
          for(uint32_t i=0; i<AI_NET_OUTPUT_SIZE;i++)
          {
            if(dump_output_buff[i] != *((float*)App_Cxt_Ptr->Ai_ContextPtr->nn_output_buffer + i))
              issue_ocurence =1;
          }

          if(issue_ocurence == 1)
          {
            TestContext_Ptr->UartContext.uart_host_requested_dump_number = 0;//so to subsequently terminates the UART command processing

            cmd_status=CMD_COMPLETE_FAILURE_EVT;
          }
        }

        /*swap write buffer*/
        if(TestContext_Ptr->DumpContext.dump_write_bufferPtr == (dump_intermediate_data_ping_buff + DUMP_INTERMEDIATE_DATA_BUFFER_SIZE))
        {
          TestContext_Ptr->DumpContext.dump_write_bufferPtr=dump_intermediate_data_pong_buff;
        }
        else if(TestContext_Ptr->DumpContext.dump_write_bufferPtr == (dump_intermediate_data_pong_buff + DUMP_INTERMEDIATE_DATA_BUFFER_SIZE))
        {
          TestContext_Ptr->DumpContext.dump_write_bufferPtr=dump_intermediate_data_ping_buff;
        }
      }

      if(TestContext_Ptr->UartContext.uart_host_requested_dump_number == 0)
      {
        /*Command execution completed => return to NOMINAL mode*/
        TestContext_Ptr->UartContext.uart_host_requested_mode=NOMINAL;

        /*Re-initiliaze the dump context*/

        /*Set run_loop to zero*/
        App_Cxt_Ptr->run_loop = 0;

        /**Sent status Event to Host**/
        *(aTxBuffer) = cmd_status;
        Uart_Tx(TestContext_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);

        /**Configure the UART in reception mode for receiving subsequent command from Host**/
        Uart_Rx(TestContext_Ptr, aRxBuffer, RX_TRANSFER_SIZE);

         BSP_SD_DeInit(0);/*Required in order to avoid subsequent call to Camera_Init() fct to fail*/
      }
      else
      { /*Re-trigger a dump*/
        if(TestContext_Ptr->UartContext.uart_host_requested_dump_number == 0xFFFF)
        {/*specific debug mode*/

          /*Send the top1 class on the serial link*/
          sprintf(msg, "%s %.0f%%", App_Cxt_Ptr->nn_top1_output_class_name, App_Cxt_Ptr->nn_top1_output_class_proba * 100);

          /**Send to Host**/
          for(int i=0;i<strlen(msg);i++)
          {
            *(aTxBuffer + i) = msg[i];
          }

          *(aTxBuffer + strlen(msg)) = 32;//Space

          Uart_Tx(TestContext_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), strlen(msg)+1);

          /*Send the inference time on the serial link*/
          sprintf(msg, "Inference: %ldms", App_Cxt_Ptr->nn_inference_time);

          /**Send to Host**/
          for(int i=0;i<strlen(msg);i++)
          {
            *(aTxBuffer + i) = msg[i];
          }

          *(aTxBuffer + strlen(msg)) = 13;//CR
          *(aTxBuffer + strlen(msg)+1) = 10;//LF

          Uart_Tx(TestContext_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), strlen(msg)+2);
        }
        else
        {
          TestContext_Ptr->UartContext.uart_host_requested_dump_number --;
        }


        UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)TestContext_Ptr->DumpContext.dump_session_name, LEFT_MODE);
        UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"DUMP READY", RIGHT_MODE);

        DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

        TestContext_Ptr->DumpContext.dump_state = 1;
      }

      /**write the output to the dump_output_buff located in external memory**/
      for(uint32_t i=0; i<AI_NET_OUTPUT_SIZE;i++)
      {
        dump_output_buff[i] = *((float*)App_Cxt_Ptr->Ai_ContextPtr->nn_output_buffer + i);
      }

      /**write the execution timings to the execution_timings_buff located in external memory**/
      for(uint32_t i=0; i<APP_FRAMEOPERATION_NUM;i++)
      {
        execution_timings_buff[i] = App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.operation_exec_time[i];
      }
    }
  #endif /* !OBJECTDETECT */

    BSP_LED_On(LED_GREEN);
    BSP_LED_Off(LED_RED);
  }
}

/**
 * @brief Post process for the VALIDATION mode
 *
 * @param TestContext_Ptr pointer to test context
 */
static void Validation_PostProcess(TestContext_TypeDef *TestContext_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;

#ifdef OBJECTDETECT
  stm32fs_err_t resul = STM32FS_ERROR_NONE;
  char msgtmp[255];
  char pathtmp[255];
  extern int32_t network_nms_comparator_out(const void *pa, const void *pb);

  if(TestContext_Ptr->ValidationContext.validation_completed == 0)
  {
    strcpy(pathtmp, TestContext_Ptr->ValidationContext.tmp_class_path);
    strcat(pathtmp, "/");
    strcat(pathtmp, TestContext_Ptr->ValidationContext.img_fno.fname);
    strcat(pathtmp," \n");
    UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)pathtmp, LEFT_MODE);

    /* Create txt file matching img name */
    strcpy(pathtmp,TestContext_Ptr->ValidationContext.img_fno.fname);
    pathtmp[strlen(pathtmp)-4]='\0';
    strcat(pathtmp, ".txt");
    if (STM32Fs_WriteTextToFile(pathtmp, "", STM32FS_CREATE_NEW_FILE) != STM32FS_ERROR_NONE)
    {
      UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Unable to create the output file", CENTER_MODE);
      DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
      BSP_LED_On(LED_RED);
      while (1)
      ;
    }

    network_pp_outBuffer_t *pOutBuff = App_Cxt_Ptr->People_ContextPtr->output.pOutBuff;
    qsort(pOutBuff, App_Cxt_Ptr->People_ContextPtr->output.nb_detect, sizeof(network_pp_outBuffer_t),
          network_nms_comparator_out);

    for (int32_t class_idx = 0; class_idx < AI_PEOPLEDETECT_NETWORK_PP_NB_CLASSES; class_idx++)
    {
      pOutBuff = App_Cxt_Ptr->People_ContextPtr->output.pOutBuff;
      for (int32_t i = 0; i < App_Cxt_Ptr->People_ContextPtr->output.nb_detect; i++)
      {
        if (pOutBuff->class_index == class_idx)
        {
          float32_t x_center = pOutBuff->x_center;
          float32_t y_center = pOutBuff->y_center;
          float32_t width = pOutBuff->width;
          float32_t height = pOutBuff->height;
          float32_t conf = pOutBuff->conf;

          DISPLAY_DrawBBox(x_center, y_center, width, height);

          sprintf(msgtmp, "%.f%% x:%.1fy:%.1f", (conf * 100), x_center, y_center);
          UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_TOP_N_LAST_LINE - NN_TOP_N_DISPLAY + i - 1), (uint8_t *)msgtmp,
                                   LEFT_MODE);

          /* Write object detection output to SD card */
          sprintf(msgtmp, "%i %f %f %f %f %f\n", pOutBuff->class_index, conf, x_center, y_center, width, height);
          resul |= STM32Fs_WriteTextToFile(pathtmp, msgtmp, STM32FS_APPEND_TO_FILE);
          if (resul != STM32FS_ERROR_NONE)
          {
              UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Unable to write to output file", CENTER_MODE);
              DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
              while (1)
                ;
          }
        }
        pOutBuff++;
      }

    }

    sprintf(msgtmp, "nb_detect %i :", (App_Cxt_Ptr->People_ContextPtr->output.nb_detect));
    UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_TOP_N_LAST_LINE - NN_TOP_N_DISPLAY-2), (uint8_t *)msgtmp, LEFT_MODE);

    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
  }
  else
  {
    UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);
    sprintf(msgtmp, "Test VALID finished");
    UTIL_LCD_DisplayStringAt(0, LINE(2), (uint8_t *)msgtmp, CENTER_MODE);
    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

    /*Validation execution completed => wait indefinitely for user to press RESET button*/
    while (1)
    {
      HAL_Delay(100);
      BSP_LED_Toggle(LED_GREEN);
    };
  }
#else

  if(TestContext_Ptr->ValidationContext.validation_completed == 0)
  {
    strcpy(tmp_msg, TestContext_Ptr->ValidationContext.tmp_class_path);
    strcat(tmp_msg, "/");
    strcat(tmp_msg, TestContext_Ptr->ValidationContext.img_fno.fname);

    /* AI Post Processing */
    size_t predicted_class = App_Cxt_Ptr->ranking[0];
    if (predicted_class != TestContext_Ptr->ValidationContext.class_index)
    {
      stm32fs_err_t res = STM32Fs_WriteTextToFile("missclassified.txt", tmp_msg, STM32FS_APPEND_TO_FILE);
      sprintf(tmp_msg, " was missclassified as %s\n", NN_OUTPUT_CLASS_LIST[predicted_class]);
      res |= STM32Fs_WriteTextToFile("missclassified.txt", tmp_msg, STM32FS_APPEND_TO_FILE);
      if (res != STM32FS_ERROR_NONE)
      {
        UTIL_LCD_DisplayStringAt(0, LINE(14), (uint8_t *)"Error. Unable to write to missclassified file", CENTER_MODE);
        DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
        while (1)
          ;
      }
    }

    float confidence = App_Cxt_Ptr->nn_top1_output_class_proba;

    /* Compute categorical-crossentropy
    * As the output comes from the softmax layer, the loss is the negative log of confidence */

    TestContext_Ptr->ValidationContext.nbr_tested++;
    double categorical_crossentropy = 10.0;
    if (confidence > 0)
    {
      categorical_crossentropy = -log((double)confidence);
    }
    TestContext_Ptr->ValidationContext.overall_loss += categorical_crossentropy;

    if (TestContext_Ptr->ValidationContext.nbr_tested > 0)
    {
      TestContext_Ptr->ValidationContext.avg_loss = TestContext_Ptr->ValidationContext.overall_loss / (double)TestContext_Ptr->ValidationContext.nbr_tested;
    }

    /* Update confusion matrix */
    TestContext_Ptr->ValidationContext.valid_conf_matrix[TestContext_Ptr->ValidationContext.class_index][predicted_class]++;

    /* Display confusion matrix */
    DisplayConfusionMatrix(TestContext_Ptr->ValidationContext.valid_conf_matrix);

    sprintf(tmp_msg, "%s %.0f%%", NN_OUTPUT_CLASS_LIST[predicted_class], confidence * 100);
    UTIL_LCD_DisplayStringAt(40, LINE(21), (uint8_t *)tmp_msg, LEFT_MODE);
    sprintf(tmp_msg, "Average loss (categorical cross-entropy) %.4f ", TestContext_Ptr->ValidationContext.avg_loss);
    UTIL_LCD_DisplayStringAt(40, LINE(22), (uint8_t *)tmp_msg, LEFT_MODE);

    /*Moved from Run_StartNewFrameAcquisition() to here since a LCD CLEAR is done inRun_GetNextReadyFrame() */
    sprintf(tmp_msg, "Class: %s, id %d", TestContext_Ptr->ValidationContext.fno.fname, TestContext_Ptr->ValidationContext.class_index);
    UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)tmp_msg, CENTER_MODE);

    DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

    if(TestContext_Ptr->UartContext.uart_cmd_ongoing)
    {
      /**write the output to the validation_output_buff located in external memory**/
      for (int i=0; i<AI_NET_OUTPUT_SIZE*4; i++)
      {
        *(TestContext_Ptr->ValidationContext.validation_write_bufferPtr)++=*((uint8_t *)(App_Cxt_Ptr->Ai_ContextPtr->nn_output_buffer) + i);
      }
    }
  }
  else
  {
    if(TestContext_Ptr->UartContext.uart_cmd_ongoing)
    {
      /*Command execution completed => return to NOMINAL mode*/
      TestContext_Ptr->UartContext.uart_host_requested_mode=NOMINAL;

      /*Re-initiliaze the validation context*/
      TestContext_Ptr->ValidationContext.overall_loss = 0.0;
      TestContext_Ptr->ValidationContext.avg_loss = 0.0;
      TestContext_Ptr->ValidationContext.nbr_tested = 1;
      TestContext_Ptr->ValidationContext.validation_completed=0;
      for (int i=0; i<AI_NET_OUTPUT_SIZE; i++)
      {
        for (int j=0; j<AI_NET_OUTPUT_SIZE; j++)
        {
          TestContext_Ptr->ValidationContext.valid_conf_matrix[i][j]=0;
        }
      }

      /*Set run_loop to zero*/
      App_Cxt_Ptr->run_loop = 0;

      /*SD de-init rerquired before the subsequent call to CAMERA_Init() following goto RESTART*/
      BSP_SD_DeInit(0);

      /**Sent "CMD_COMPLETE_SUCCESS_EVT" Event to Host**/
      *(aTxBuffer) = CMD_COMPLETE_SUCCESS_EVT;
      Uart_Tx(TestContext_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);

      /**Configure the UART in reception mode for receiving subsequent command from Host**/
      Uart_Rx(TestContext_Ptr, aRxBuffer, RX_TRANSFER_SIZE);

      /**write the execution timings to the execution_timings_buff located in external memory**/
      for(uint32_t i=0; i<APP_FRAMEOPERATION_NUM;i++)
      {
        execution_timings_buff[i] = App_Cxt_Ptr->Utils_ContextPtr->ExecTimingContext.operation_exec_time[i];
      }
    }
    else
    {
      /*Validation execution completed => wait indefinitely for user to press RESET button*/
      while (1)
      {
        HAL_Delay(100);
        BSP_LED_Toggle(LED_GREEN);
      };
    }
  }
#endif /* OBJECTDETECT */
}

#ifndef OBJECTDETECT
/**
 * @brief Configure communication i/f used for test purpose
 *
 * @param TestContext_Ptr pointer to test context
 */
static void Test_ComIf_Init(TestContext_TypeDef *Test_Context_Ptr)
{
   Uart_Init(Test_Context_Ptr);
}
#endif /* !OBJECTDETECT */

/**
 * @brief Initializes the utilities context structure
 *
 * @param TestContext_Ptr pointer to test context
 */
static void Test_Context_Init(TestContext_TypeDef *Test_Context_Ptr)
{
  Test_Context_Ptr->DumpContext.Dump_FrameSource=CAMERA_LIVE;
  Test_Context_Ptr->DumpContext.dump_session_id = 0;
  Test_Context_Ptr->DumpContext.dump_frame_count = 0;
  Test_Context_Ptr->DumpContext.dump_state = 0;

  Test_Context_Ptr->CaptureContext.capture_file_format=RAW;
  Test_Context_Ptr->CaptureContext.capture_state=0;
  Test_Context_Ptr->CaptureContext.capture_session_id=0;
  Test_Context_Ptr->CaptureContext.capture_frame_count=0;

  Test_Context_Ptr->ValidationContext.overall_loss = 0.0;
  Test_Context_Ptr->ValidationContext.avg_loss = 0.0;
  Test_Context_Ptr->ValidationContext.nbr_tested = 1;
  Test_Context_Ptr->ValidationContext.validation_completed=0;
#ifndef OBJECTDETECT
  for (int i=0; i<AI_NET_OUTPUT_SIZE; i++)
  {
    for (int j=0; j<AI_NET_OUTPUT_SIZE; j++)
    {
      Test_Context_Ptr->ValidationContext.valid_conf_matrix[i][j]=0;
    }
  }
#endif

  Test_Context_Ptr->UartContext.uart_cmd_ongoing=0;
  Test_Context_Ptr->UartContext.uart_host_requested_mode = NOMINAL;
  Test_Context_Ptr->UartContext.uart_host_nonreg_run=0;
}

/* Functions Definition ------------------------------------------------------*/
/**
 * @brief Test Init
 *
 * @param Test_Context_Ptr pointer to test context
 */
void TEST_Init(TestContext_TypeDef *Test_Context_Ptr)
{
  Test_Context_Init(Test_Context_Ptr);

#ifndef OBJECTDETECT
  Test_ComIf_Init(Test_Context_Ptr);
#endif /* !OBJECTDETECT */
}

#ifndef OBJECTDETECT
/**
 * @brief Check UART status for any received frame
 *
 * @param Test_Context_Ptr pointer to test context
 */
void TEST_CmdIf_Check(TestContext_TypeDef *Test_Context_Ptr)
{
  if((HAL_UART_GetState(&Test_Context_Ptr->UartContext.UartHandle) == HAL_UART_STATE_READY) && (Test_Context_Ptr->UartContext.uart_cmd_ongoing ==0))
  {
    UTILS_DCache_Coherency_Maintenance((void *)aRxBuffer, RX_BUFFER_SIZE, INVALIDATE);

    if(aRxBuffer[0]< UART_CMD_NUMBER)
    {
      *(aTxBuffer) = CMD_ACK_EVT;
      Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);

      /*Wait a 500ms tempo so to make sure that the host is ready to receive subsequent transmitted data*/
      HAL_Delay(500);

      /*Call processing function corresponding to COMMAND ID*/
      (*UartCmdFct_Table[*(uint8_t*)aRxBuffer])(Test_Context_Ptr, (uint8_t *)(aRxBuffer+1), 0/*not used for now*/);
    }
    else
    {
      /*Send "NACK" Event*/
      *(aTxBuffer) = CMD_NACK_EVT;
      Uart_Tx(Test_Context_Ptr, (uint8_t*)aTxBuffer, sizeof(aTxBuffer), TX_EVT_SIZE);

      /**Configure the UART in reception mode for receiving subsequent command from Host**/
      Uart_Rx(Test_Context_Ptr, aRxBuffer, RX_TRANSFER_SIZE);
    }
  }
}
#endif /* !OBJECTDETECT */

/**
 * @brief Runs the main menu providing a way to choose beetween 4 applications:
 *        - NN Inference
 *        - NN Inference with intermediate dumps
 *        - OnBoard validation
 *        - Camera Capture
 *
 * @param Test_Context_Ptr pointer to test context
 */
void TEST_MainMenu(TestContext_TypeDef *Test_Context_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=Test_Context_Ptr->AppCtxPtr;

  UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

  UTIL_LCD_DrawRect(200, 10, 400, 50, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"Operating mode", CENTER_MODE);

  UTIL_LCD_DisplayStringAt(0, LINE(5), (uint8_t *)"Press one of the key of the joystick", CENTER_MODE);
  UTIL_LCD_DisplayStringAt(0, LINE(6), (uint8_t *)"to select an operating mode", CENTER_MODE);

  /* Draw the "joystick arrows" */
  struct point_t
  {
    uint16_t x;
    uint16_t y;
  };
  const struct point_t pt_center = {.x = 400, .y = 350}; /* x,y coordinates */
  const uint16_t pt_offset = 50;                         /* pixels offset from the center (wideness of the square) */

  UTIL_LCD_DrawLine(pt_center.x - pt_offset, pt_center.y, pt_center.x, pt_center.y - pt_offset, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x, pt_center.y - pt_offset, pt_center.x + pt_offset, pt_center.y, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x + pt_offset, pt_center.y, pt_center.x, pt_center.y + pt_offset, UTIL_LCD_COLOR_WHITE);
  UTIL_LCD_DrawLine(pt_center.x, pt_center.y + pt_offset, pt_center.x - pt_offset, pt_center.y, UTIL_LCD_COLOR_WHITE);

  const char *appli_names[] = {"Nominal Run", "Frame Capture", "OnBoard Validation",
                                   "Memory Dump"};

  UTIL_LCD_DisplayStringAt(0, pt_center.y - pt_offset - LINE(2), (uint8_t*)appli_names[0], CENTER_MODE);//UP
  UTIL_LCD_DisplayStringAt(pt_center.x + pt_offset + 10, pt_center.y - LINE(1) / 2, (uint8_t*)appli_names[1], LEFT_MODE);//RIGHT
  UTIL_LCD_DisplayStringAt(0, pt_center.y + pt_offset + LINE(1), (uint8_t*)appli_names[2], CENTER_MODE);//DOWN
  UTIL_LCD_DisplayStringAt(150, pt_center.y - LINE(1) / 2, (uint8_t*)appli_names[3], LEFT_MODE);//LEFT

  DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

  if(Test_Context_Ptr->UartContext.uart_cmd_ongoing)
  {
    switch (Test_Context_Ptr->UartContext.uart_host_requested_mode)
    {
    case CAPTURE:
      FrameCaptureInit(Test_Context_Ptr);
      App_Cxt_Ptr->Operating_Mode=CAPTURE;
      break;
    case DUMP:
      MemoryDumpInit(Test_Context_Ptr);
      App_Cxt_Ptr->Operating_Mode=DUMP;
      if(Test_Context_Ptr->DumpContext.Dump_FrameSource == SDCARD_FILE)
        App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready=1;
      break;
    case NOMINAL:
      App_Cxt_Ptr->Operating_Mode=NOMINAL;
      Test_Context_Ptr->UartContext.uart_cmd_ongoing=0;//returning to NOMINAL mode terminates the UART command processing
      break;
    case VALID:
      OnBoardValidInit(Test_Context_Ptr);
      App_Cxt_Ptr->Operating_Mode=VALID;
      App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready=1;
      break;
    default:
      break;
    };
  }
  else
  {
    JOYPin_TypeDef joy_state = JOY_NONE;
    while (joy_state == JOY_NONE)
    {
      joy_state = (JOYPin_TypeDef) BSP_JOY_GetState(JOY1, 0);
    }

    switch (joy_state)
    {
    case JOY_RIGHT:
      FrameCaptureInit(Test_Context_Ptr);
      App_Cxt_Ptr->Operating_Mode=CAPTURE;
      break;
    case JOY_LEFT:
      MemoryDumpInit(Test_Context_Ptr);
      App_Cxt_Ptr->Operating_Mode=DUMP;
      if(Test_Context_Ptr->DumpContext.Dump_FrameSource == SDCARD_FILE)
        App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready=1;
      break;
    case JOY_UP:
      App_Cxt_Ptr->Operating_Mode=NOMINAL;
      break;
    case JOY_DOWN:
      OnBoardValidInit(Test_Context_Ptr);
      App_Cxt_Ptr->Operating_Mode=VALID;
      App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready=1;
      break;
    default:
      break;
    };

    //Tempo joystick
    HAL_Delay(200);
  }
}

/**
 * @brief Retrieve the next file (from the SDcard) to be used as input for the dump
 *
 * @param TestContext_Ptr pointer to test context
 * @param DestBuffPtr pointer to the destination buffer where the input file data content is copied to
 */
void TEST_GetNextDumpInput(TestContext_TypeDef *TestContext_Ptr, uint8_t * DestBuffPtr)
{
  DIR class_dir;
  FILINFO img_fno;
#if CAMERA_CAPTURE_RES == VGA_640_480_RES
  char  class_path[64]=  "/dump_src_image_vga";
#elif CAMERA_CAPTURE_RES == QVGA_320_240_RES
  char class_path[64]=  "/dump_src_image_qvga";
#endif
  stm32fs_err_t err;
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;


  STM32Fs_OpenDir(class_path, &class_dir);

  /* For each image in this directory (i.e class) */
  if(STM32Fs_GetNextFile(&class_dir, &img_fno) != STM32FS_ERROR_NONE)
    while(1);

  strcpy(tmp_msg, class_path);
  strcat(tmp_msg, "/");
  strcat(tmp_msg, img_fno.fname);

  /* Read the image to DestBuffPtr */
  err = STM23Fs_ReadImageBMP(tmp_msg, DestBuffPtr);
  if (err != STM32FS_ERROR_NONE)
  {
    while(1);
  }

  f_closedir(&class_dir);

  App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready = 1;
}

/**
 * @brief Retrieve the next file (from the SDcard) to be used as input for the validation
 *
 * @param TestContext_Ptr pointer to test context
 * @param DestBuffPtr pointer to the destination buffer where the input file data content is copied to
 */
void TEST_GetNextValidationInput(TestContext_TypeDef *TestContext_Ptr, uint8_t * DestBuffPtr)
{
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;

#ifdef OBJECTDETECT
/*image is will be pointed depending if we wanted to be post processed or not*/  
#if DIRECT_TO_NN_INPUT ==1
  DestBuffPtr = (uint8_t *)App_Cxt_Ptr->People_ContextPtr->nn_input_buffer;
#else
  DestBuffPtr = App_Cxt_Ptr->Camera_ContextPtr->camera_capture_buffer;
#endif
#endif /* OBJECTDETECT */

  /* Get next image in this directory (i.e class) */
  if(STM32Fs_GetNextFile(&TestContext_Ptr->ValidationContext.class_dir, &TestContext_Ptr->ValidationContext.img_fno) == STM32FS_ERROR_NONE)
  {
    stm32fs_err_t err;

    BSP_LED_Toggle(LED_BLUE);
    UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

    strcpy(tmp_msg, TestContext_Ptr->ValidationContext.tmp_class_path);
    strcat(tmp_msg, "/");
    strcat(tmp_msg, TestContext_Ptr->ValidationContext.img_fno.fname);

    /* Read the image to DestBuffPtr */
    err = STM23Fs_ReadImageBMP(tmp_msg, DestBuffPtr);

    if (err != STM32FS_ERROR_NONE)
    {
      while(1);
    }

    App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready = 1;

  } /* End for each file in class directory */
  else
  {
    /*Close class directory*/
    f_closedir(&TestContext_Ptr->ValidationContext.class_dir);

  FIND_NEXT_DIR:
    /* Get into next directory in "/onboard_valid_dataset" directory */
    if(STM32Fs_GetNextDir(&TestContext_Ptr->ValidationContext.dataset_dir, &TestContext_Ptr->ValidationContext.fno) == STM32FS_ERROR_NONE)
    {
      /* Find corresponding class index */
      TestContext_Ptr->ValidationContext.class_index = FindClassIndexFromString(TestContext_Ptr->ValidationContext.fno.fname);

      if(TestContext_Ptr->ValidationContext.class_index == -1)
      { /* Class index was not found */
        sprintf(tmp_msg, "Error, class %s doesn't exists", TestContext_Ptr->ValidationContext.fno.fname);
        UTIL_LCD_DisplayStringAt(0, LINE(3), (uint8_t *)tmp_msg, CENTER_MODE);
        DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
        BSP_LED_On(LED_RED);
        while (1)
          ;
      }

      strcpy(TestContext_Ptr->ValidationContext.tmp_class_path, ""); //chaine "nulle"
      strcpy(TestContext_Ptr->ValidationContext.tmp_class_path, TestContext_Ptr->ValidationContext.class_path );
      strcat(TestContext_Ptr->ValidationContext.tmp_class_path, TestContext_Ptr->ValidationContext.fno.fname);
      STM32Fs_OpenDir(TestContext_Ptr->ValidationContext.tmp_class_path, &TestContext_Ptr->ValidationContext.class_dir);

      /*Get first file immediately*/
      if(STM32Fs_GetNextFile(&TestContext_Ptr->ValidationContext.class_dir, &TestContext_Ptr->ValidationContext.img_fno) == STM32FS_ERROR_NONE)
      {
        stm32fs_err_t err;

        BSP_LED_Toggle(LED_BLUE);
        UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

        strcpy(tmp_msg, TestContext_Ptr->ValidationContext.tmp_class_path);
        strcat(tmp_msg, "/");
        strcat(tmp_msg, TestContext_Ptr->ValidationContext.img_fno.fname);

        /* Read the image to DestBuffPtr */
        err = STM23Fs_ReadImageBMP(tmp_msg, DestBuffPtr);
        if (err != STM32FS_ERROR_NONE)
        {
          while(1);
        }

        App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready = 1;

      }
      else
      {
        goto FIND_NEXT_DIR; /* empty dir */
      }
    }
    else
    {
      /* Program has Looped through all class dirs*/
      /*=>Close the onboard_valid_dataset directory*/
      f_closedir(&TestContext_Ptr->ValidationContext.dataset_dir);

      /******Moved here from the postprocess() to avoid going thru the main appli while(1) loop again after the validation is completed******/
      /* End of validation */
#ifndef OBJECTDETECT
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_BLACK);
      BSP_LCD_FillRect(0, 50, 130, 224, 224, UTIL_LCD_COLOR_WHITE);
      UTIL_LCD_SetTextColor(UTIL_LCD_COLOR_WHITE);
      UTIL_LCD_DisplayStringAt(40, LINE(10), (uint8_t*)"End of validation.", LEFT_MODE);
      UTIL_LCD_DisplayStringAt(40, LINE(11), (uint8_t*)"Press wake-up", LEFT_MODE);
      UTIL_LCD_DisplayStringAt(40, LINE(12), (uint8_t*)"button to see report", LEFT_MODE);
      DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

      /* Wait for button input */
      while((TestContext_Ptr->UartContext.uart_cmd_ongoing==0) && (BSP_PB_GetState(BUTTON_WAKEUP) == RESET))
        ;
#endif /* !OBJECTDETECT */
      if(TestContext_Ptr->UartContext.uart_cmd_ongoing)
        HAL_Delay(1000);

      UTIL_LCD_Clear(UTIL_LCD_COLOR_BLACK);

#ifndef OBJECTDETECT
      ClassificationReport_Typedef report = classification_report(TestContext_Ptr->ValidationContext.valid_conf_matrix);

      DisplayClassificationReport(TestContext_Ptr, &report);

      WriteClassificationReport(&report, "classification_report.txt");

      TestContext_Ptr->ValidationContext.final_accuracy=report.accuracy;

      WriteConfusionMatrix(TestContext_Ptr->ValidationContext.valid_conf_matrix, "confusion_matrix.csv");
#endif /* !OBJECTDETECT */

      if(TestContext_Ptr->UartContext.uart_cmd_ongoing)
        HAL_Delay(1000);

      TestContext_Ptr->ValidationContext.validation_completed =1;
    }
  }
}

/**
 * @brief Run test
 *
 * To be called before each PrepProcess stage for:
 * timing measurement + Dump +  capture
 *
 * @param TestContext_Ptr pointer to test context
 * @param Operating_Mode current operating mode
 */
void TEST_Run(TestContext_TypeDef *TestContext_Ptr, AppOperatingMode_TypeDef Operating_Mode)
{
  char file_name[150];
  char msg[70];
  uint8_t sd_error;
  stm32fs_err_t ret;
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;


  if((Operating_Mode == DUMP) && (TestContext_Ptr->TestRunContext.src_buff_addr != NULL))
  {
    switch(TestContext_Ptr->DumpContext.dump_state)
    {
      /*User has not yet triggered the memory dump*/
    case 0:
      ;
      break;

      /*User has triggered the memory dump*/
    case 1:

      BSP_LED_Off(LED_GREEN);
      BSP_LED_On(LED_RED);
      UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"DUMP BUSY ", RIGHT_MODE);

      /*Display output (for debug)*/
#ifndef OBJECTDETECT
      sprintf(msg, "%s %.0f%%", App_Cxt_Ptr->nn_top1_output_class_name, App_Cxt_Ptr->nn_top1_output_class_proba * 100);
      UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_TOP_N_LAST_LINE - NN_TOP_N_DISPLAY + 0), (uint8_t *)msg, CENTER_MODE);
#endif /* !OBJECTDETECT */
      sprintf(msg, "Inference: %ldms", App_Cxt_Ptr->nn_inference_time);
      UTIL_LCD_DisplayStringAt(0, LINE(DISPLAY_INFER_TIME_LINE), (uint8_t *)msg, CENTER_MODE);

      DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

      HAL_Delay(200);

      /*Wait for camera acquisition to be completed*/
#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
      while(App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready == 0);
#endif

      if((App_Cxt_Ptr->Test_ContextPtr->UartContext.uart_cmd_ongoing) && (App_Cxt_Ptr->Test_ContextPtr->UartContext.uart_host_requested_dump_memory == SDRAM))
      {/* Dump intermediate data in SDRAM */

        /*Dump buffer name in SDRAM*/
        for(int i=0; i<strlen(TestContext_Ptr->TestRunContext.src_buff_name);i++)
        {
          *(App_Cxt_Ptr->Test_ContextPtr->DumpContext.dump_write_bufferPtr)++=*(TestContext_Ptr->TestRunContext.src_buff_name+i);
        }

         /*Dump data buffer in SDRAM*/
        for(int i=0; i<TestContext_Ptr->TestRunContext.src_size;i++)
        {
          *(App_Cxt_Ptr->Test_ContextPtr->DumpContext.dump_write_bufferPtr)++=*(((uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr)+i);
        }
      }
      else
      {/* Dump intermediate data in SDCARD */

        if(App_Cxt_Ptr->Test_ContextPtr->DumpContext.Dump_FrameSource != SDCARD_FILE)
        {
          BSP_CAMERA_DeInit(0);

          if (BSP_SD_Init(0) != BSP_ERROR_NONE)
          {
            UTIL_LCD_DisplayStringAt(0, LINE(12), (uint8_t *)"Error. SD Card not detected", CENTER_MODE);
            DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
            Error_Handler();
          }
        }

        /***Create a folder with session name where to store the 5 intermediates dump files***/
        /* Generate a session ID */
        HAL_RNG_GenerateRandomNumber(&TestContext_Ptr->RngHandle, &TestContext_Ptr->DumpContext.dump_session_id);
        sprintf(TestContext_Ptr->DumpContext.dump_session_name, "Session %X", (unsigned int)TestContext_Ptr->DumpContext.dump_session_id);

        sprintf(TestContext_Ptr->DumpContext.dump_session_folder_name,"%s/DUMP_SESS_%X", TestContext_Ptr->DumpContext.dump_folder_name, (unsigned int)TestContext_Ptr->DumpContext.dump_session_id);
        STM32Fs_CreateDir(TestContext_Ptr->DumpContext.dump_session_folder_name);


        ret = STM32FS_ERROR_NONE;

        if(TestContext_Ptr->TestRunContext.DumpFormat == GRAY8)
        {
          sprintf(file_name, "%s/%s_.bmp", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteImageBMPGray(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == BMP888)
        {
          sprintf(file_name, "%s/%s_.bmp", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteImageBMP(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == BMP565)
        {
          sprintf(file_name, "%s/%s_.bmp", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteImageBMP16(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size, 0);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == RAW)
        {
          sprintf(file_name, "%s/%s.raw", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteRaw(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size*TestContext_Ptr->TestRunContext.src_height_size);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == TXT)
        {
          sprintf(file_name, "%s/%s.txt", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteTextToFile(file_name, "          Neural Network Output\n\n", STM32FS_CREATE_NEW_FILE);
          for (int i = 0; i < (TestContext_Ptr->TestRunContext.src_size/4); i++)
          {
            char str[128];
            sprintf(str, "%20s:%8.3f\n", NN_OUTPUT_CLASS_LIST[i], *((float*)TestContext_Ptr->TestRunContext.src_buff_addr + i));
            ret = STM32Fs_WriteTextToFile(file_name, str, STM32FS_APPEND_TO_FILE);
          }
        }
        else
        {
          Error_Handler(); /* DumpFormat no supported */
        }

        if (ret != STM32FS_ERROR_NONE)
        {
          UTIL_LCD_DisplayStringAt(0, LINE(12), (uint8_t *)"Error. Writting image failed", CENTER_MODE);
          DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
          Error_Handler();
        }
      }

      TestContext_Ptr->DumpContext.dump_state = 2;

      break;

    case 2:

      if((App_Cxt_Ptr->Test_ContextPtr->UartContext.uart_cmd_ongoing) && (App_Cxt_Ptr->Test_ContextPtr->UartContext.uart_host_requested_dump_memory == SDRAM))
      {/* Dump intermediate data in SDRAM */

        /*Dump buffer name in SDRAM*/
        for(int i=0; i<strlen(TestContext_Ptr->TestRunContext.src_buff_name);i++)
        {
          *(App_Cxt_Ptr->Test_ContextPtr->DumpContext.dump_write_bufferPtr)++=*(TestContext_Ptr->TestRunContext.src_buff_name+i);
        }

        /*Dump data buffer in SDRAM*/
        for(int i=0; i<TestContext_Ptr->TestRunContext.src_size;i++)
        {
          *(App_Cxt_Ptr->Test_ContextPtr->DumpContext.dump_write_bufferPtr)++=*(((uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr)+i);
        }
      }
      else
      {/* Dump intermediate data in SDCARD */

        ret = STM32FS_ERROR_NONE;

        if(TestContext_Ptr->TestRunContext.DumpFormat == GRAY8)
        {
          sprintf(file_name, "%s/%s.bmp", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteImageBMPGray(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == BMP565)
        {
          sprintf(file_name, "%s/%s.bmp", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteImageBMP16(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size, 0);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == BMP888)
        {
          sprintf(file_name, "%s/%s.bmp", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteImageBMP(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == RAW)
        {
          sprintf(file_name, "%s/%s.raw", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteRaw(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size*TestContext_Ptr->TestRunContext.src_height_size);
        }
        else if(TestContext_Ptr->TestRunContext.DumpFormat == TXT)
        {
          sprintf(file_name, "%s/%s.txt", TestContext_Ptr->DumpContext.dump_session_folder_name, TestContext_Ptr->TestRunContext.src_buff_name);
          ret = STM32Fs_WriteTextToFile(file_name, "          Neural Network Output\n\n", STM32FS_CREATE_NEW_FILE);
        #ifndef OBJECTDETECT
          for (int i = 0; i < (TestContext_Ptr->TestRunContext.src_size)/4; i++)
          {
            char str[128];
            sprintf(str, "%20s:%8.3f\n", NN_OUTPUT_CLASS_LIST[i], *((float*)TestContext_Ptr->TestRunContext.src_buff_addr + i));
            ret = STM32Fs_WriteTextToFile(file_name, str, STM32FS_APPEND_TO_FILE);
          }
        #endif /* !OBJECTDETECT */
        }
        else
        {
          Error_Handler(); /* DumpFormat no supported */
        }

        if (ret != STM32FS_ERROR_NONE)
        {
          UTIL_LCD_DisplayStringAt(0, LINE(12), (uint8_t *)"Error. Writting image failed", CENTER_MODE);
          DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
          Error_Handler();
        }
      }
      break;
    }
  }
  else if((Operating_Mode == CAPTURE) && (TestContext_Ptr->TestRunContext.PerformCapture == 1) && (TestContext_Ptr->TestRunContext.src_buff_addr != NULL))
  {
    switch(TestContext_Ptr->CaptureContext.capture_state)
    {
      /*User has not yet triggered the frame capture*/
    case 0:
      break;

      /*User has triggered the frame capture and the camera buffer must be captured onto SD card*/
    case 1:
      BSP_LED_Off(LED_GREEN);
      BSP_LED_On(LED_RED);
      UTIL_LCD_DisplayStringAt(0, LINE(1), (uint8_t *)"CAPTURE BUSY ", RIGHT_MODE);

      DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);

      HAL_Delay(200);

      /*Wait for camera acquisition to be completed*/
#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
      while(App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready == 0);
#endif
      BSP_CAMERA_DeInit(0);

      TestContext_Ptr->CaptureContext.capture_frame_count ++;

      sd_error = BSP_SD_Init(0);
      if (sd_error != BSP_ERROR_NONE)
      {
        UTIL_LCD_DisplayStringAt(0, LINE(12), (uint8_t *)"Error. SD Card not detected", CENTER_MODE);
        DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
        Error_Handler();
      }

      ret = STM32FS_ERROR_NONE;

      if(TestContext_Ptr->TestRunContext.rb_swap == 1)
        PREPROC_Pixel_RB_Swap((void*)TestContext_Ptr->TestRunContext.src_buff_addr, (void*)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size*TestContext_Ptr->TestRunContext.src_height_size);//caution: this is modifying the content of the data contained at src_buff_addr! To do: implement this on the fly when writing onto the SD card!!

      if(TestContext_Ptr->CaptureContext.capture_file_format == BMP)
      {
        sprintf(file_name, "%s/%s_%d.bmp", TestContext_Ptr->CaptureContext.capture_folder_name, TestContext_Ptr->TestRunContext.src_buff_name, (unsigned int)TestContext_Ptr->CaptureContext.capture_frame_count);

        /*swap_bytes parameter is set to 0 since the camera is providing data in rgb order, i.e. in the order expected by the write BMP16 fct*/
        ret = STM32Fs_WriteImageBMP16(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size, 0);
      }
      else if(TestContext_Ptr->CaptureContext.capture_file_format == RAW)
      {
        sprintf(file_name, "%s/%s_%d.raw", TestContext_Ptr->CaptureContext.capture_folder_name, TestContext_Ptr->TestRunContext.src_buff_name, (unsigned int)TestContext_Ptr->CaptureContext.capture_frame_count);

        ret = STM32Fs_WriteRaw(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size*TestContext_Ptr->TestRunContext.src_height_size);
      }
      else
      {
        Error_Handler(); /* Capture Format no supported */
      }

      if (ret != STM32FS_ERROR_NONE)
      {
        UTIL_LCD_DisplayStringAt(0, LINE(12), (uint8_t *)"Error. Writting image failed", CENTER_MODE);
        DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
        Error_Handler();
      }

      TestContext_Ptr->CaptureContext.capture_state = 2;
      break;

      /*User has triggered the frame capture and the NN input must be captured onto SD card*/
    case 2:
      /*Wait for camera acquisition to be completed*/
#if MEMORY_SCHEME != FULL_INTERNAL_MEM_OPT
      while(App_Cxt_Ptr->Camera_ContextPtr->new_frame_ready == 0);
#endif

      ret = STM32FS_ERROR_NONE;

      if(TestContext_Ptr->TestRunContext.rb_swap == 1)
        PREPROC_Pixel_RB_Swap((void*)TestContext_Ptr->TestRunContext.src_buff_addr, (void*)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size*TestContext_Ptr->TestRunContext.src_height_size);//caution: this is modifying the content of the data contained at src_buff_addr! To do: implement this on the fly when writing onto the SD card!!

      if(TestContext_Ptr->CaptureContext.capture_file_format == BMP)
      {
        sprintf(file_name, "%s/%s_%d.bmp", TestContext_Ptr->CaptureContext.capture_folder_name, TestContext_Ptr->TestRunContext.src_buff_name, (unsigned int)TestContext_Ptr->CaptureContext.capture_frame_count);

        ret = STM32Fs_WriteImageBMP(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size, TestContext_Ptr->TestRunContext.src_height_size);
      }
      else if(TestContext_Ptr->CaptureContext.capture_file_format == RAW)
      {
        sprintf(file_name, "%s/%s_%d.raw", TestContext_Ptr->CaptureContext.capture_folder_name, TestContext_Ptr->TestRunContext.src_buff_name, (unsigned int)TestContext_Ptr->CaptureContext.capture_frame_count);

        ret = STM32Fs_WriteRaw(file_name, (uint8_t *)TestContext_Ptr->TestRunContext.src_buff_addr, TestContext_Ptr->TestRunContext.src_width_size*TestContext_Ptr->TestRunContext.src_height_size);
      }
      else
      {
        Error_Handler(); /* Capture Format no supported */
      }

      if (ret != STM32FS_ERROR_NONE)
      {
        UTIL_LCD_DisplayStringAt(0, LINE(12), (uint8_t *)"Error. Writting image failed", CENTER_MODE);
        DISPLAY_Refresh(App_Cxt_Ptr->Display_ContextPtr);
        Error_Handler();
      }

      break;

    default:
      break;
    }
  }
}

/**
 * @brief Post process for the TEST modes
 *
 * @param TestContext_Ptr pointer to test context
 */
void TEST_PostProcess(TestContext_TypeDef *TestContext_Ptr)
{
  AppContext_TypeDef *App_Cxt_Ptr=TestContext_Ptr->AppCtxPtr;

  if(App_Cxt_Ptr->Operating_Mode == CAPTURE)
  {
    Capture_PostProcess(App_Cxt_Ptr->Test_ContextPtr);
  }
  else if(App_Cxt_Ptr->Operating_Mode == DUMP)
  {
    Dump_PostProcess(App_Cxt_Ptr->Test_ContextPtr);
  }
  else if(App_Cxt_Ptr->Operating_Mode == VALID)
  {
    Validation_PostProcess(App_Cxt_Ptr->Test_ContextPtr);
  }
}

#ifndef OBJECTDETECT
/**
 * @brief UART error callback
 *
 * Traps UART errors.
 *
 * @param huart pointer to UART handle
 */
void HAL_UART_ErrorCallback(UART_HandleTypeDef *huart)
{
  while(1);
}
#endif /* !OBJECTDETECT */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
