#******************************************************************************
# @file    test_set_generation_foodreco_nn.py
# @author  MCD Application Team
# @brief   Generation of dataset required for quantization process
#******************************************************************************
# @attention
#
# <h2><center>&copy; Copyright (c) 2019 STMicroelectronics 
# All rights reserved.</center></h2>
#
#   This software component is licensed by ST under BSD 3-Clause license,
#   the "License"; You may not use this file except in compliance with the
#   License. You may obtain a copy of the License at:
#                        https://opensource.org/licenses/BSD-3-Clause
#
#******************************************************************************


# import the necessary libraries to access/pre-process your database and prepare input vectors for your Keras network
#######################################################################################################################
import keras
from keras.preprocessing.image import ImageDataGenerator
from keras.utils.np_utils import to_categorical


###############################################################################################
# wrapper function
###############################################################################################
def create_test_generator(quant_test_set_dir, evaluation_test_set_dir, quant_test_ratio, batch_size):


    quant_datagen = ImageDataGenerator(
        rescale=1. / 255,
        validation_split=quant_test_ratio-0.00001
    )
    quant_test_set_labeled = quant_datagen.flow_from_directory(
        quant_test_set_dir,
        target_size=(224, 224),
        batch_size=batch_size,
        class_mode='categorical',
        subset="validation")
    # quant_test_set_labeled = None if no labels

    quant_test_set_unlabeled = quant_datagen.flow_from_directory(
        quant_test_set_dir,
        target_size=(224, 224),
        batch_size=batch_size,
        class_mode=None,
        subset="validation")

    quant_nsteps = len(quant_test_set_unlabeled)

    eval_datagen = ImageDataGenerator(
        rescale=1. / 255,
        validation_split=0.9999
    )
    eval_test_set_labeled = eval_datagen.flow_from_directory(
        evaluation_test_set_dir,
        target_size=(224, 224),
        batch_size=batch_size,
        class_mode='categorical', #None,
        subset="validation")
    # quant_test_set_labeled = None if no labels

    eval_nsteps = len(eval_test_set_labeled)

    return quant_test_set_labeled, quant_test_set_unlabeled, quant_nsteps, eval_test_set_labeled, eval_nsteps

