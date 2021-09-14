# FP-AI-VISION1 V2.1.0 content

This readme file describes the content of the FP-AI-VISION1 V2.1.0.

## General

The FP-AI-VISION1 v2.1.0 package demonstrates image classification applications
running on the following hardware setup:

- STM32H747I-DISCO discovery board
- B-CAMS-OMV camera bundle

All the Neural Network (NN) applications included in the FP-AI-VISION1 v2.1.0
are relying on the [X-CUBE-AI] v5.2.0 runtime library.

For more details about the [X-CUBE-AI] tool, please refer to [UM2526] "Getting
started with X-CUBE-AI Expansion Package for Artificial Intelligence (AI)"

[X-CUBE-AI]: https://www.st.com/en/embedded-software/x-cube-ai.html
[UM2526]https://www.st.com/resource/en/user_manual/dm00570145-getting-started-with-xcubeai-expansion-package-for-artificial-intelligence-ai-stmicroelectronics.pdf

## Food Recognition application

- Recognizing among 18 types of common foods and drinks.
- NN model based on the FD-MobileNet model expecting input in RGB888 color
  format and in 224x224 resolution.
- Available in several different memory allocation schemes (using internal
  memory only or using external SDRAM and/or QSPI memory).
- Demonstrates both 8-bits quantized and floating point models.

## Person Presence Detection application

- Identifying whether a person is present in the image or not.
- Two models supported:
  - One low complexity model based on the MobileNetV1 0.25 model (so-called
    'Google' model) from [Tensor Flow
    repository](https://storage.googleapis.com/tensorflow-nightly/github/tensorflow/tensorflow/lite/micro/tools/make/gen/arduino_x86_64/prj/person_detection/tensorflow_lite.zip)
    expecting input in Grayscale color format and in 96x96 resolution.
  - One medium complexity model based on the MobileNetV2 0.35 model expecting
    input in RGB888 color format and in 128x128 resolution.
- Available in full internal memory allocation scheme.
- Demonstrate 8-bits quantized models.

## People Counting application

- Count the number of people in the image
- Detect people and their position in the image using bounding boxes.
- PeopleCounting model provided in binary form, as a library.
- 240x240 RGB888 input.
- Full internal memory allocation scheme.

See [README.md](PeopleCounting/README.md) for more details and usage information
on the People Counting application.

## USB Webcam application

- USB Video Class (UVC) device implementation example.
- 2 resolutions supported: VGA and QVGA.
- 2 formats supported: MJPEG (compressed from RGB565) and raw YUY2.
- Enables photo and video capture for Machine Learning dataset creation and/or
  enrichment.
- Enables live testing of Machine Learning models on the host with the same
  camera modules as the target camera module.

See [README.md](USB_Webcam/README.md) for more details and usage information on the USB
Webcam application.

## Software package

The FP-AI-VISION1 includes the following software components:

- Camera frame acquisition routines
- Optimized routines for frame preprocessing so to convert to expected model
  input formats
- Post processing routines

## Memory allocation schemes

Several memory allocation schemes are available depending on the complexity of
the model.

For models that do completely fit in the STM32 internal memory, a very optimized
SRAM data memory layout is provided.

For models that do not completely fit in the STM32 internal memory, integration
examples are provided demonstrating  
how to make use of external SDRAM memory and/or external QSPI flash memory.

## Functional description

### Nominal mode

Nominal operating mode is the default running mode after reset. The application
runs an inference on the camera image.

For the food recognition application: the user can switch between two display
modes:

- logo view (default): a logo corresponding to the recognized food/drink is
  displayed.
- camera view: the captured camera content is displayed.

Both display modes also report the inference time (in ms), the number of frame  
per second (fps) that are processed and the Top-1 output class probability (in
%).

In order to switch from one view to another, the user must press the blue Wakeup
button.

For the Person Presence Detection applications: when in nominal mode, only the
camera view mode is available.  
The captured camera content is displayed along with the inference time (in ms),

the number of frame per second (fps) that are processed and the Top-1 output
class probability (in %).

The Person Presence Detection applications provide four camera orientation
modes:

- Normal
- Flipped image (default)
- Mirrored image
- Mirrored and flipped image

When pressing on the blue Wakeup button, the camera sensor will cycle through  
the different camera orientation modes listed above. This functionality can be  
used to place the camera in different orientations with respect to the board LCD
display.

### Other modes

Maintaining the blue Wakeup button pressed under reset enables to enter one the
following modes (selected via joystick):

#### Camera capture mode

Camera capture mode captures image frames at two different stages: after the
camera acquisition and just before the NN inference.  
This mode is intended to be used for dataset building and/or enrichment.

When in this mode it is required to have a microSD™ card inserted into the
STM32H747I-DISCO discovery board.

When entering this operating mode, the Camera_Capture folder is created (if not
already existing)  
and a session name is generated and displayed in the top-left corner of the
screen.

A sub-folder (named CAM_CAPTURE_SESS_sessionname) is also created.  
The screen shows the image taken from the camera and in the top-right corner,
the READY message indicates that the program is ready to write to the microSD™
card.  
To trigger a frame capture, press on the blue Wakeup button.  
The READY message switches to BUSY, indicating that the frame is being written
to the microSD™ card, preventing all other capture meanwhile.  
Once the write operation is finished, the READY message is displayed and capture
enabled again.

The firmware writes the output files (in .raw or .bmp format) onto the
CAM_CAPTURE_SESS_sessionname folder.

#### Memory dump mode

Memory dump mode can be used to dump the output memory buffer content after each
preprocessing stage.  
This mode is intended to be used for debugging purposes.  
When in this mode it is required to have a microSD™ card inserted into the
STM32H747I-DISCO discovery board.

The frame source can be one the following:

- Capture from the camera in normal mode,
- capture from the camera configured in test bar pattern mode,
- capture from a  .bmp file (in rgb565 format) located on the microSD™ card  
  (under folder named dump_src_image_xx, xx being the resolution of the image:
  possible values are: vga and qvga).

When entering this operating mode, the Memory_Dump folder is created (if not
already existing).  
The screen shows the frame and in the top-right corner, the READY message
indicates that the program is ready to start a memory dump session.  
To trigger a memory dump session, press on the blue Wakeup button.  
The READY message switches to BUSY, indicating that the memory dump operations
are being performed and written to the microSD™ card,  
preventing all other capture meanwhile.  
A session name is generated and displayed in the top-left corner
of the screen.  
A sub-folder (named DUMP_SESS_sessionname) is also created.  
Once the memory dump operations are completed, the READY message is displayed
and memory dump enabled again.

The firmware will write each output buffer content onto an output file (in .raw
or .bmp format) stored on the microSD™ card.

#### Onboard validation mode

Enables to validate (from both the accuracy and execution time standpoints) the
frame preprocess as well as the NN model inference using a image dataset stored
on the microSD™ card.  
When in this mode it is required to have a microSD™ card plugged onto the
STM32H747I-DISCO discovery board.

In order for the program to find the images in the microSD™ card, a directory
named onboard_valid_dataset_xx (xx being the resolutions of the images: vga or
qvga)  
must exist at the root of the file system.  
Inside this directory, there must be one directory per class containing the
images with the same name as defined by NN_OUTPUT_CLASS_LIST in the code.  
All images must be stored in the BMP format (16-bit per pixel encoding) and have
a fix resolution (vga or qvga).

A helper script (named create_dataset.py) to convert any dataset of images to
the right .BMP format is provided in the Utilities\AI_resources\Food-Recognition
directory of the FP.

When entering this mode, a summary of the information is displayed on the
screen. The user must Press the blue Wakeup button to start the validation.

At the top of the display, the class name is presented with its index in
NN_OUTPUT_CLASS_LIST.  
The left side shows the current image being processed by the Neural Network,
which is resized to match the network input size.  
Below the image, the display shows the NN Top-1 output, the confidence level,
and the average categorical cross-entropy loss across all processed images.  
The right side of the display shows the confusion matrix, that is constantly
updated while images are being processed by the neural network.  
The rows indicate the ground-truth label, and the columns the predicted class.

When all images are processed, a message is displayed and a press on the blue
Wakeup button updates the display with a classification report.  
The classification report shows the precision, recall, and f1-score for each
class, as well as the macro average (average of the unweighted mean per class)
and  
weighted average (average of the support-weighted mean per class).  
The confusion matrix, the list of misclassified files and the classification
report are saved at the root of the microSD™ card file system as:

- confusion_matrix.csv
- missclassified.txt
- classification_report.txt

## How to use it

1. Open the selected application project with your preferred toolchain (EWARM,
   Keil or STM32CubeIDE).
2. Select a configuration.
3. Rebuild all files and load your program image into target memory.
4. Run the application.

## Application binaries

Each application folder contains a folder named Binary which contains the binary files for the applications.  
Here is described below the naming convention for the binary files:

STM32H747I-DISCO_u_v_w_x_y_z.ext  

u: application name= Food, Person  
v: model type = Std, Opt, Google, MobileNetv2  
w: model format= Float, Quant8  
x: volatile data memory allocation configuration: Ext, Split, IntMem, IntFps  
y: non-volatile data memory allocation configuration: IntFlash, QpsiFlash, ExtSdram  
z: version of FP release(a:major, b: minor, c:patch) : Vabc  
ext: binary file extension= bin, hex  

### Volatile data

Corresponds to:  
- The data buffers related to the camera pipeline processing  
- The data buffers related to the Neural Network inference (activation, input and output buffers)  

Here is a description of the memory allocation configurations:  
- Ext: all above data buffers are located in external (SDRAM) memory  
- Split: above data buffers location split between internal (SRAM) memory and external (SDRAM) memory  
- IntMem: all above data buffers are located in internal (SRAM) memory and there is no buffer dedicated to camera acquisition   
- IntFps: all above data buffers are located in internal (SRAM) memory and there is a buffer dedicated to camera acquisition    

### Non-volatile data

Corresponds to the data buffer containing the weights and biases.   

Here is a description of the memory allocation configurations:  
- IntFlash: weights/biases data buffer is stored in and accessed from internal flash memory   
- QpsiFlash: weights/biases data buffer is stored in and accessed from external QSPI flash memory  
- ExtSdram: weights/biases data buffer is stored in external QSPI flash memory but accessed from external SDRAM memory (recopy takes place at startup time) 

## Copyright

Copyright (C) 2021 STMicroelectronics
