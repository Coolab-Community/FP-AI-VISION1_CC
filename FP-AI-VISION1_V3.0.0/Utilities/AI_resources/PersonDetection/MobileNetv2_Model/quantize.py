#   Copyright (c) 2020 STMicroelectronics.
#
#   This software component is licensed by ST under BSD-3-Clause license,
#   the "License"; You may not use this file except in compliance with the
#   License. You may obtain a copy of the License at:
#             https://opensource.org/licenses/BSD-3-Clause

import itertools
import numpy as np
import pathlib
import tensorflow as tf
from tensorflow.compat.v1.lite import TFLiteConverter
from tensorflow.keras.preprocessing.image import ImageDataGenerator

DATASET_DIR = 'person20'
TENSOR_SIZE = (128, 128, 3)
TARGET_SIZE = (TENSOR_SIZE[0], TENSOR_SIZE[1])
KERAS_MODEL = 'mobv2_128x128x3_adam02.best_train.001.h5'

# https://tensorflow.google.cn/hub/tutorials/tf2_image_retraining#optional_deployment_to_tensorflow_lite


def mob_pre_data(i_tensor):
    return ((i_tensor / 127.5) - 1.0).astype(np.float32)


train_datagen = ImageDataGenerator(preprocessing_function=mob_pre_data)
train_generator = train_datagen.flow_from_directory(DATASET_DIR,
                                                    target_size=TARGET_SIZE,
                                                    batch_size=1,
                                                    color_mode='rgb')


def representative_dataset():
    num_calibration_examples = 100
    return itertools.islice(
        ([img[None, ...]] for batch, _ in train_generator for img in batch),
        num_calibration_examples)


converter = TFLiteConverter.from_keras_model_file(KERAS_MODEL)
converter.optimizations = [tf.lite.Optimize.DEFAULT]
converter.target_spec.supported_ops = [tf.lite.OpsSet.TFLITE_BUILTINS_INT8]
converter.inference_input_type = tf.uint8
converter.inference_output_type = tf.uint8
converter.representative_dataset = representative_dataset
q_model = converter.convert()

tflite_model_file = pathlib.Path(KERAS_MODEL + '.uint8.tflite')
tflite_model_file.write_bytes(q_model)
