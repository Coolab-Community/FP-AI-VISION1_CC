# People Counting application

The **People Counting** application can recognize and track people in an image
through a camera on the **STM32H747I-DISCO** board. The STM32H7 microcontroller
is responsible for the camera acquisition, image processing and object detection
neural network model inference.

## Features

- Use a neural network to process images and get bounding boxes corresponding to locations of people
- Count the number of people in the image
- PeopleCounting model provided in binary form, as a library.
- 240x240 RGB888 input.
- Full internal memory allocation scheme.

## Hardware requirements

- STM32H747I-DISCO
- STM32F4DIS-CAM (OV9655) or B-CAMS-OMV (OV5640)

## Software requirements

- IAR Embedded Workbench for ARM v8.50.6

## Quickstart

1. Rebuild all files and load image into target STM32H747I-DISCO device
2. Run the example
3. Point the camera to where people can be seen.
4. Model will work best when taking people from afar, preferably from a high position (typically where a surverillance camera would be placed).
5. Lightning conditions should be classical indoor with lights on.

LCD screen should display the number of people and their position in the frame
using bounding boxes.

## Onboard validation

The Onboard validation model allows the firmwawre to perform on device tests
using images stored on the SD card instead of using the camera. This mode can be
used to check for model non-regressions and execution timing measurements.

1. Convert a set of test images to 240x240 RGB565 bitmaps. E.g. using ImageMagick:

```
$ magick mogrify -resize 240x240\! -format bmp -define bmp:subtype=RGB565 +profile "*"  *.jpg
```

2. Copy bitmap images to microSD card in `onboard_valid_dataset_qvga_yololc/input`.

```
SD/
└── onboard_valid_dataset_qvga_yololc/
    └── input
        ├── 000000000139.bmp
        ├── 000000000785.bmp
        ├── 000000000872.bmp
        └── ...
```

3. Insert SD card into STM32H747I-DISCO
4. Reset, press and hold the blue wakeup button until operating mode manu is seen
5. Select **OnBoard Validation** using the joystick
6. Press the blue wakeup to start the validation
7. After validation is complete, detections are written to SD card root as text files:

```
SD/
├── onboard_valid_dataset_qvga_yololc/
├── 000000000139.txt
├── 000000000785.txt
├── 000000000872.txt
└── ...
```

## Directory contents

- CM7/Inc/fp_vision_app.h                     Application header file
- CM7/Inc/fp_vision_global.h                  Global header file
- CM7/Inc/main.h                              Main program header file
- CM7/Inc/occupancy_logos.h                   Bitmap occupancy logos file
- CM7/Inc/stm32h7xx_hal_conf.h                HAL configuration file
- CM7/Inc/stm32h7xx_it.h                      Interrupt handlers header file
- CM7/lib/LibPeopleDetect100_CM7_GCC.a        PeopleCounting model library
- CM7/Src/fp_vision_app.c                     Application configuration and body
- CM7/Src/main.c                              Main program
- CM7/Src/system_stm32h7xx.c                  STM32H7xx system clock configuration file
- CM7/Src/stm32h7xx_it.c                      Interrupt handlers
- Common/Src/system_stm32h7xx.c               System init Source File
- EWARM                                       IAR EWARM project directory


## Performance

2.7 fps

TODO:
Support STM32CubeIDE and MDK-ARM IDE.

## Copyright

Copyright (C) 2021 STMicroelectronics
