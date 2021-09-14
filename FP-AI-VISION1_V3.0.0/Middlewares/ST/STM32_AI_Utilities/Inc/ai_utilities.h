/**
 ******************************************************************************
 * @file    ai_utilities.h
 * @author  MCD Application Team
 * @brief   Header for ai_utilities.c module
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
#ifndef __AI_UTILITIES_H
#define __AI_UTILITIES_H

#ifdef __cplusplus
extern "C"
{
#endif
  
/* Includes ------------------------------------------------------------------*/
#include "fp_vision_app.h"
#include "img_preprocess.h"
#include "ai_interface.h"

void Run_Preprocessing(AppContext_TypeDef *);
void Init_DataMemoryLayout(AppContext_TypeDef *);
void Resize_Frame(Image_TypeDef *, Image_TypeDef *, Roi_TypeDef *);

#ifdef __cplusplus
}
#endif

#endif /*__AI_UTILITIES_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
