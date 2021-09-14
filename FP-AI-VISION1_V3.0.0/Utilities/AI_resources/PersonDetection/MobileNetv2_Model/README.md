# Create a person detection image classifier

This note describes how to retrain a new person detection image classifier from
a pre-trained network using tensorflow.


## Requirements

- python v3.5.7 and the packages listed in `requirements.txt`.
- At least 50GB of storage space is recommended to download and extract the dataset.
- `stm32ai`: command-line utility for
[X-CUBE-AI](https://www.st.com/en/embedded-software/x-cube-ai.html).

## Download COCO-2014 dataset

The [COCO dataset](https://cocodataset.org/) can be downloaded and extracted to
the current working directory from the following mirror:

```shell
wget https://pjreddie.com/media/files/train2014.zip
wget https://pjreddie.com/media/files/val2014.zip
wget https://pjreddie.com/media/files/coco/labels.tgz
unzip train2014.zip
unzip val2014.zip
tar -xzvf labels.tgz
```

## Prepare dataset

For this example, we will be using a subset of the COCO dataset to create a
**person20** dataset. The dataset will be split into images where a person is
covering more than 20% of the image and images not containing persons.

```shell
python create_dataset.py
```

Ideally, you would want to create a balanced dataset to avoid introducing any
boas to you trained model.

## Create model from a pre-trained convnet

Run `train.py` to create an image classifier model from a pre-trained MobileNetV2 head.

```shell
python train.py
```

## Quantize model

Quantize using training data on the previously trained float model.This
technique is called [post-training quantization][post_training_quantization].
The quantization process is an essential part of embedded neural networks for
computer vision problems.

Use the `quantize.py` script to convert and quantize the keras `.h5` model into
a `.tflite` model.

```shell
python quantize.py
```

## Integrate into STM32 application

To run this `.tflite` model onto the STM32 microcontroller in a efficient and optimized manner, use `stm32ai` to generate new C files.
```shell
stm32ai generate mobv2_128x128x3_adam02_respin01.best_val.035.h5.uint8.tflite --allocate-inputs
```

Copy the generated file into the STM32 application source files:

```shell
cp stm32ai_output/network*.c ../../../../Projects/STM32H747I-DISCO/Applications/PersonDetection/MobileNetv2_Model/CM7/Src/
cp stm32ai_output/network*.h ../../../../Projects/STM32H747I-DISCO/Applications/PersonDetection/MobileNetv2_Model/CM7/Inc/
```

Rebuild the STM32 project and program the STM32 to test the generated model.

[post_training_quantization]: https://www.tensorflow.org/lite/performance/post_training_quantization
