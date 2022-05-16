/**
 ******************************************************************************
 * @file    fp_vision_test.h
 * @author  MCD Application Team
 * @brief   Header for fp_vision_test.c module
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __FP_VISION_TEST_H
#define __FP_VISION_TEST_H

#ifdef __cplusplus
extern "C"
{
#endif

/* Includes ------------------------------------------------------------------*/
#include "ai_interface.h"
#include "fp_vision_global.h"
#include "stm32_fs.h"
  

#define COUNTOF(__BUFFER__)   (sizeof(__BUFFER__) / sizeof(*(__BUFFER__)))
  
/* Size of UART buffers in bytes */
#define RX_TRANSFER_SIZE                 10
#define RX_BUFFER_SIZE                   32
#ifdef OBJECTDETECT
#define TXBUFFERSIZE_MAX                 (1)//(AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE*4)// causes linking issue when set to its original value
#else
#define TXBUFFERSIZE_MAX                 (AI_NET_OUTPUT_SIZE*AI_NET_OUTPUT_SIZE*4)
#endif
#define TX_EVT_SIZE                      1
  
#define MAX_STRING_SIZE  32
#define BUFF_NAME_STRING_TOTAL_SIZE  (MAX_STRING_SIZE*APP_BUFF_NUM)
  
#define DUMP_INTERMEDIATE_DATA_BUFFER_SIZE     (CAM_FRAME_BUFFER_SIZE + PFC_OUTPUT_BUFFER_SIZE + RESIZE_OUTPUT_BUFFER_SIZE + AI_INPUT_BUFFER_SIZE + AI_NET_OUTPUT_SIZE_BYTES + BUFF_NAME_STRING_TOTAL_SIZE)


/* Exported types ------------------------------------------------------------*/
typedef enum
{
  /*Subset of commands for automatic testing purpose*/
  RUN_NONREG_CMD                   = 0x00,/*Launches the non-regression, i.e. perform DUMP w/ camera configured in test color bar*/
  RUN_VALIDATION_CMD               = 0x01,/*Launches the on-board VALIDATION mode*/
  GET_NONREG_REPORT_SIZE_CMD       = 0x02,/*Returns the size of the data that will be uploaded upon reception of UPLOAD_NONREG_REPORT_CMD command*/
  GET_VALIDATION_REPORT_SIZE_CMD   = 0x03,/*Returns the size of the data that will be uploaded upon reception of UPLOAD_VALIDATION_REPORT_CMD command*/
  GET_TIMING_REPORT_SIZE_CMD       = 0x04,/*Returns the size of the data that will be uploaded upon reception of UPLOAD_TIMING_REPORT_CMD command*/
  GET_NONREG_DEBUG_REPORT_SIZE_CMD = 0x05,/*Returns the size of the data that will be uploaded upon reception of UPLOAD_NONREG_DEBUG_REPORT_CMD command*/
  UPLOAD_NONREG_REPORT_CMD         = 0x06,/*Uploads to the host the Non-Regression report (containing the NN output consistently generated during the execution of the test)*/
  UPLOAD_VALIDATION_REPORT_CMD     = 0x07,/*Uploads to the host the Validation report (containing the NN output of each run)*/
  UPLOAD_TIMING_REPORT_CMD         = 0x08,/*Uploads to the host the Timing report (containing the execution time for each operation involved in the test)*/
  UPLOAD_NONREG_DEBUG_REPORT_CMD   = 0x09,/*Uploads to the host the Non-Regression debug report (containing the full memory dump including the NN output as well as all the camera pipeline buffers contents of the two consecutive runs that have generated different output results)*/
  GET_VALIDATION_ACCURACY_CMD      = 0x0A,/*Returns the final classification accuracy after running the validation*/
  
  /*Whole set of commands*/
  LAUNCH_DUMP_CMD                  = 0x0B, /*Launch the DUMP mode by specifying: 1st) the DUMP sub-mode, i.e. the image frame source: SDCARD, CAMERA LIVE  or CAMERA TEST COLOR BAR, 2nd) the memory location where the intermediates data are dumped to: SDCARD (0x00) or SDRAM (0x01)*/
  TRIGGER_DUMP_CMD                 = 0x0C, /*Once in a specified DUMP sub-mode, triggers a given number (provided as param) of consecutive DUMP of the memory*/
  LAUNCH_CAPTURE_CMD               = 0x0D, /*Launch the CAPTURE mode: input param are: Format, inter-Capture delay in ms (if ==0 => 'manual' mode, else 'automatic mode), Number of captures to trigger (if in 'automatic' mode))*/
  TRIGGER_CAPTURE_CMD              = 0x0E, /*Once in CAPTURE mode, triggers a CAPTURE if 'manual' mode has been selected, otherwise it has no effect*/
  GET_VALIDATION_OUTPUT_SIZE_CMD   = 0x0F, /*Return the size of the data that will be uploaded upon reception of GET_VALIDATION_OUTPUT_CMD command*/
  UPLOAD_VALIDATION_OUTPUT_CMD     = 0x10, /*Upload to the host the output of the Validation located in VALIDATION (?) folder on SDCARD: confusion matrix only (NN output for each single file/inference is not uploaded at that point)*/
  GET_DUMP_OUTPUT_DATA_SIZE_CMD    = 0x11, /*Return the size of the data that will be uploaded upon reception of UPLOAD_DUMP_OUTPUT_DATA_CMD command*/
  UPLOAD_DUMP_OUTPUT_DATA_CMD      = 0x12, /*Upload to the host the output data of the Dump (i.e. NN output) stored in the dump_output_buff buffer*/
  GET_DUMP_WHOLE_DATA_SIZE_CMD     = 0x13, /*Return the size of the data that will be uploaded upon reception of UPLOAD_DUMP_WHOLE_DATA_CMD command*/
  UPLOAD_DUMP_WHOLE_DATA_CMD       = 0x14, /*Upload to the host the whole data of the Dump (i.e. NN output buffer but also all the intermediate buffers) stored in the dump_intermediate_data_ping/pong_buff buffers*/
  READ_CAMERA_REGISTER_CMD         = 0x16, /*Reads the content of one camera register or a list of camera registers */
  WRITE_CAMERA_REGISTER_CMD        = 0x16, /*Writes the content of a camera register*/
  SET_CAMERA_MODE_CMD              = 0x17, /*Configure the camera in test bar or normal mode*/
  SET_CONFIG_SDCARD_PATH_CMD       = 0x18, /*Set the path (on SD card) where to write the results (validation + dump test bar) for a given config (i.e. binary)*/

  UART_CMD_NUMBER
} Uart_Command_TypeDef;/*From Host to STM32*/

typedef enum
{
  CMD_ACK_EVT              = 0x00,
  CMD_NACK_EVT             = 0x01,
  CMD_COMPLETE_SUCCESS_EVT = 0x02,
  CMD_COMPLETE_FAILURE_EVT = 0x03,
  CMD_ERROR_EVT            = 0x04,

  UART_EVT_NUMBER
} Uart_Event_TypeDef;/*From STM32 to Host*/

typedef enum
{
  GRAY8               = 0x00,
  BMP565              = 0x01,
  BMP888              = 0x02,
  RAW                 = 0x03,
  BMP                 = 0x04,
  TXT                 = 0x05 /*should be used only for the NN outputs*/
}DataFormat_TypeDef;

typedef enum
{
  CAMERA_LIVE             = 0x01,     
  CAMERA_COLORBAR         = 0x02,
  SDCARD_FILE             = 0x03
}MemDumpFrameSource_TypeDef;

typedef enum
{
  SDCARD             = 0x00,     
  SDRAM              = 0x01
}MemDumpMemoryLocation_TypeDef;

/*! Structure holding classification report data */
typedef struct
{
  float precisions[AI_NET_OUTPUT_SIZE];  /*! Precision per class */
  float recalls[AI_NET_OUTPUT_SIZE];     /*! Recall per class */
  float f1_scores[AI_NET_OUTPUT_SIZE];   /*! F1-score per class */
  uint32_t supports[AI_NET_OUTPUT_SIZE]; /*! Number of elements per class */
  float accuracy;         /*! Accuracy of the classification */
  uint32_t total_support; /*! Total number of elements classified */
  float macro_avg_precision; /*! Average precision */
  float macro_avg_recall;    /*! Average recall */
  float macro_avg_f1_score;  /*! Average F1-score */
  float weighted_avg_precision; /*! Support-weighted average precision */
  float weighted_avg_recall;    /*! Support-weighted average recall */
  float weighted_avg_f1_score;  /*! Support-weighted average F1-score */
} ClassificationReport_Typedef;

typedef struct
{
  uint8_t* dump_write_bufferPtr;/*Current pointer where to write the data. This pointer is going thru either dump_intermediate_data_ping_buff or  dump_intermediate_data_pong_buffer*/
  MemDumpFrameSource_TypeDef Dump_FrameSource;
  uint32_t dump_session_id; 
  uint32_t dump_frame_count; 
  char dump_session_name[18];
  char dump_folder_name[50];
  char dump_session_folder_name[100];
  uint32_t dump_state;
} DumpContext_TypeDef;

typedef struct
{
  DataFormat_TypeDef capture_file_format;/*RAW*/
  uint32_t capture_state;/*Set to 1 when user push wkup button to trigger a capture...*/
  uint32_t capture_session_id; 
  uint32_t capture_frame_count; 
  char capture_session_name[18];
  char capture_folder_name[50];
} CaptureContext_TypeDef;

typedef struct
{
  double overall_loss;
  double avg_loss;
  uint32_t nbr_tested;
  DIR dataset_dir;
  FILINFO fno;
  DIR class_dir;
  FILINFO img_fno;
  int class_index;
  char class_path[64];
  char tmp_class_path[64];
  uint32_t validation_completed;
  float final_accuracy;
#ifndef OBJECTDETECT
  uint32_t valid_conf_matrix[AI_NET_OUTPUT_SIZE][AI_NET_OUTPUT_SIZE]; 
#endif
  ClassificationReport_Typedef Classification_Report;
  uint8_t* validation_write_bufferPtr;/*Current pointer where to write the data into validation_output_buff buffer*/
} ValidationContext_TypeDef;

typedef struct
{
  uint32_t uart_cmd_ongoing;
  AppOperatingMode_TypeDef uart_host_requested_mode;
  MemDumpFrameSource_TypeDef uart_host_requested_dump_submode;
  MemDumpMemoryLocation_TypeDef uart_host_requested_dump_memory;
  uint32_t uart_host_requested_dump_number;
  DataFormat_TypeDef uart_host_requested_capture_format;
  uint32_t uart_host_requested_capture_delay; 
  uint32_t uart_host_requested_capture_number; 
  uint32_t uart_host_nonreg_run;
  UART_HandleTypeDef UartHandle;
} UartContext_TypeDef;

typedef struct
{
  void *src_buff_addr; /*Pointer to the source buffer*/
  char* src_buff_name; /*String containing the name of the source buffer*/
  uint32_t src_width_size;/*Source buffer width*/
  uint32_t src_height_size;/*Source buffer width*/
  uint32_t src_size;/*Time to execute one inference of the NN*/ 
  uint32_t PerformCapture;/*Variable to indicate if capture needs to be performed (1) or not (0): used only in CAPTURE mode*/
  DataFormat_TypeDef DumpFormat;/*Format of the memory Dump: used only in DUMP mode*/
  uint32_t rb_swap;/*Variable to indicate if a Red/Blue pixel's component swap needs to be performed*/
} TestRunContext_TypeDef;

typedef struct
{
  DumpContext_TypeDef       DumpContext;
  CaptureContext_TypeDef    CaptureContext;
  ValidationContext_TypeDef ValidationContext;
  UartContext_TypeDef       UartContext;
  TestRunContext_TypeDef    TestRunContext;
  RNG_HandleTypeDef         RngHandle; /* Random number generator */
  void*                     AppCtxPtr;
} TestContext_TypeDef;

typedef void (*UartCmdFctPtr)(TestContext_TypeDef*, uint8_t*, uint16_t);

  /* Exported constants --------------------------------------------------------*/
#include "fp_vision_app.h"

#define NUM_FILE_PER_DIR 100 /*number of files per class directory on SDCard (in the validation context)*/
#define NUM_CAM_REG      0xD0 /*number of camera registers */

#define MAX_RES_WIDTH (1080) /* Max width in pixels */
#define MAX_RES_HEIGHT (720) /* Max height in pixels */


/****************************/
/***UART related defines***/
/****************************/
/* Definition for USARTx clock resources */
#define USARTx                           USART1
#define USARTx_CLK_ENABLE()              __HAL_RCC_USART1_CLK_ENABLE()
#define USARTx_RX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define USARTx_TX_GPIO_CLK_ENABLE()      __HAL_RCC_GPIOA_CLK_ENABLE()
#define DMAx_CLK_ENABLE()                __HAL_RCC_DMA1_CLK_ENABLE()

#define USARTx_FORCE_RESET()             __HAL_RCC_USART1_FORCE_RESET()
#define USARTx_RELEASE_RESET()           __HAL_RCC_USART1_RELEASE_RESET()

/* Definition for USARTx Pins */
#define USARTx_TX_PIN                    GPIO_PIN_9
#define USARTx_TX_GPIO_PORT              GPIOA
#define USARTx_TX_AF                     GPIO_AF7_USART1
#define USARTx_RX_PIN                    GPIO_PIN_10
#define USARTx_RX_GPIO_PORT              GPIOA
#define USARTx_RX_AF                     GPIO_AF7_USART1

/* Definition for USARTx's DMA */
#define USARTx_TX_DMA_STREAM             DMA1_Stream7
#define USARTx_RX_DMA_STREAM             DMA1_Stream5

#define USARTx_TX_DMA_CHANNEL            DMA_REQUEST_USART1_TX
#define USARTx_RX_DMA_CHANNEL            DMA_REQUEST_USART1_RX

/* Definition for USARTx's NVIC */
#define USARTx_DMA_TX_IRQn               DMA1_Stream7_IRQn
#define USARTx_DMA_RX_IRQn               DMA1_Stream5_IRQn
#define USARTx_DMA_TX_IRQHandler         DMA1_Stream7_IRQHandler
#define USARTx_DMA_RX_IRQHandler         DMA1_Stream5_IRQHandler

/* Definition for USARTx's NVIC */
#define USARTx_IRQn                      USART1_IRQn
#define USARTx_IRQHandler                USART1_IRQHandler

/* Size of Transmission buffer */
#define TXSTARTMESSAGESIZE               (COUNTOF(aTxStartMessage) - 1)
#define TXENDMESSAGESIZE                 (COUNTOF(aTxEndMessage) - 1)


/* Exported macro ------------------------------------------------------------*/

/* External variables --------------------------------------------------------*/
extern uint8_t aRxBuffer[];
extern uint8_t aTxBuffer[];
extern unsigned char valid_image_buff[];
extern float dump_output_buff[];
extern float validation_output_buff[];
extern uint8_t dump_intermediate_data_ping_buff[];
extern uint8_t dump_intermediate_data_pong_buff[];
extern uint32_t execution_timings_buff[];
extern TestContext_TypeDef TestContext;
extern char Test_buffer_names[APP_BUFF_NUM][MAX_STRING_SIZE];

/* Exported functions ------------------------------------------------------- */
void TEST_MainMenu(TestContext_TypeDef *);
void TEST_Init(TestContext_TypeDef *);
void TEST_CmdIf_Check(TestContext_TypeDef *);
void TEST_GetNextValidationInput(TestContext_TypeDef *, uint8_t *);
void TEST_GetNextDumpInput(TestContext_TypeDef *, uint8_t *);
void TEST_Run(TestContext_TypeDef *, AppOperatingMode_TypeDef );
void TEST_PostProcess(TestContext_TypeDef *TestContext_Ptr);

#ifdef __cplusplus
}
#endif

#endif /*__FP_VISION_TEST_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
