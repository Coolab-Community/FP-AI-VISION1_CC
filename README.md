# FP-AI-VISION1_CC
Neural network application (image classification + audio feedback)

In this repo there are two branches available, main and GTM_network

main ==> image classification of some STMicrolectroncis board (check tuto here ==> https://wiki.st.com/stm32mcu/wiki/AI:How_to_use_Teachable_Machine_to_create_an_image_classification_application_on_STM32)

GTM_network ==> image classification of arrow for maze application ( Be carefull invariance by rotation to be treated, between left and right :) )

Project path ==> FP-AI-VISION1_CC/FP-AI-VISION1_V3.0.0/Projects/STM32H747I-DISCO/Applications/FoodReco_MobileNetDerivative/Quantized_Model/STM32CubeIDE/.project 

You must absolutely use the version of software indicated in the guideline 👇

◼ About this guideline:

The purpose of this guide is to provide the information needed to complete the development.

Prerequisite:
Hardware:
•	STM32H747I-DISCO Board
•	B-CAMS-OMV Flexible Camera Adapter board
•	A Micro-USB to USB cable
•	A Loudspeaker or headphones (jack)
•	Optional: A webcam
Software:
•	STM32Cube IDE
•	X-Cube-AI version 6.0.0
•	FP-AI-VISION1 version 3.0.0
•	STM32CubeProgrammer
•	Audacity

◼ AI part:

How to start:
First possibility:
The user has the possibility to select one of two options for generating the C code:
 • Either generating the floating-point C code directly from the CNN model in floating-point
 • Or quantizing the floating-point CNN model to obtain an 8-bit model, and subsequently generating the corresponding quantized C code
For most CNN models, the second option enables to reduce the memory footprint (Flash and RAM) as well as inference time. The impact on the final output accuracy depends on the CNN model as well as on the quantization process (mainly the test dataset and the quantization algorithm).

From a float or quantized model, the user must use the STM32Cube.AI tool (X-CUBE-AI) to generate the corresponding optimized C code, follow the getting started with X-CUBE-AI

You can either use the GUI version of STM32Cube.AI (X-CUBE-AI) with the user's own .ion file or an alternate solution is to use the CLI (command-line interface) version of STM32Cube.AI (X-CUBE-AI), so that the generated files be directly copied into the Src and Inc directories contained in the output directory provided on the command line.

The last step is the integration of the generated code to the FP-AI-VISION1 firmware, follow the section 2.1 of the UM2611.

Second possibility:
Use the Teachable Machine online tool with STM32Cube.AI and the FP-AI-VISION function pack to create an image classifier running on the STM32H747I-DISCO board, to start with Teachable Machine you can follow this wiki.

This tutorial is divided into three parts: the first part shows how to use the Teachable Machine to train and export a deep learning model, then STM32Cube.AI is used to convert this model into optimized C code for STM32 MCUs. The last part explains how to integrate this new model into the FP-AI-VISION1 to run live inference on an STM32 board with a camera.

◼ Audio part:
At the end of these tutorials, you will be able to test your own model, further development consists of adding audio feedback according to the labels computed by your NN.
 
Second scenario (maze):
The labels displayed (labels = status) on the screen are either:

-	straight_ahead
-	Left
-	Right
-	U-turn
-	Default

You must use STM32cubeProgrammer to load the audio file in the external memory (don't forget to check the external loader)


</* The Audio file is flashed with ST-Link Utility @ flash address =  AUDIO_SRC_FILE_ADDRESS */
#define AUDIO_SRC_FILE_ADDRESS_DEFAU       0x90000000   /* Audio file address in external flash */
#define AUDIO_FILE_SIZE              286720
#define AUDIO_SRC_FILE_ADDRESS_LEFT       0x90050000   /* Audio file address in external flash */
#define AUDIO_FILE_SIZE_TWO              40912
#define AUDIO_SRC_FILE_ADDRESS_RIGHT       0x900A0000   /* Audio file address in external flash */
#define AUDIO_SRC_FILE_ADDRESS_STRAI       0x900F0000   /* Audio file address in external flash */
#define AUDIO_SRC_FILE_ADDRESS_UTURN       0x90100000   /* Audio file address in external flash */>


Tips:
YouTube video:
STM32 FP-AI-VISION1 Video Application Notes: Part 1, Introduction
STM32 FP-AI-VISION1 Video Application Notes: Part 2, FP-AI-VISION1 Overview
