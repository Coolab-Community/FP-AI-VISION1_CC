#   Copyright (c) 2020 STMicroelectronics.
#
#   This software component is licensed by ST under BSD-3-Clause license,
#   the "License"; You may not use this file except in compliance with the
#   License. You may obtain a copy of the License at:
#             https://opensource.org/licenses/BSD-3-Clause

import numpy as np
import tensorflow as tf
import pandas as pd

from tensorflow.keras.models import Model, load_model
from tensorflow.keras.optimizers import Adam, RMSprop
from tensorflow.keras.callbacks import EarlyStopping, ModelCheckpoint, Callback, CSVLogger, LearningRateScheduler
from tensorflow.keras.preprocessing.image import ImageDataGenerator
from tensorflow.keras.losses import CategoricalCrossentropy
from tensorflow.keras.layers import GlobalAveragePooling2D, Dropout, Dense

print(tf.__version__)

TRAIN_DIR = 'train2014'
VALID_DIR = 'person20'
IMG_SHAPE = (128, 128, 3)
IMG_SIZE = (IMG_SHAPE[0], IMG_SHAPE[1])
COLOR_SPACE = 'rgb'

# BATCH_SIZE = 32
BATCH_SIZE = 16


def mob_pre_data(i_tensor):
    return ((i_tensor / 127.5) - 1.0).astype(np.float32)


train_df = pd.read_csv('train2014.txt', delimiter=' ')

train_datagen = ImageDataGenerator(preprocessing_function=mob_pre_data,
                                   shear_range=0.2,
                                   zoom_range=0.2,
                                   horizontal_flip=True,
                                   brightness_range=[0.5, 1.5])
train_generator = train_datagen.flow_from_dataframe(dataframe=train_df,
                                                    directory=TRAIN_DIR,
                                                    x_col='filename',
                                                    y_col='label',
                                                    target_size=IMG_SIZE,
                                                    batch_size=BATCH_SIZE,
                                                    class_mode='categorical',
                                                    color_mode=COLOR_SPACE)

test_datagen = ImageDataGenerator(preprocessing_function=mob_pre_data)
test_generator = test_datagen.flow_from_directory(VALID_DIR,
                                                  target_size=IMG_SIZE,
                                                  batch_size=BATCH_SIZE * 4,
                                                  class_mode='categorical',
                                                  color_mode=COLOR_SPACE)


run_id = "mobv2_128x128x3_adam02"

m0 = tf.keras.applications.mobilenet_v2.MobileNetV2(input_shape=IMG_SHAPE,
                                                    alpha=0.35,
                                                    weights='imagenet',
                                                    include_top=False)
# m0.trainable = False we decide to training everthing using a very low lr
x = GlobalAveragePooling2D()(m0.output)
x = Dropout(0.5)(x)
p = Dense(2, activation='softmax')(x)
m = tf.keras.Model(inputs=m0.input, outputs=p)

# training the top
m.compile(optimizer=tf.keras.optimizers.Adam(lr=0.00002),
          loss=CategoricalCrossentropy(),
          metrics=['accuracy'])
m.summary()

acc_val_checkpointer = ModelCheckpoint(run_id + ".best_val.{epoch:03d}.h5",
                                       verbose=1,
                                       save_best_only=True,
                                       monitor='val_accuracy')
acc_train_checkpointer = ModelCheckpoint(run_id + ".best_train.{epoch:03d}.h5",
                                         verbose=1,
                                         save_best_only=True,
                                         monitor='accuracy')
csv_logger = CSVLogger(run_id + '.txt')

m.fit_generator(generator=train_generator,
                epochs=100,
                initial_epoch=0,
                validation_data=test_generator,
                validation_steps=len(test_generator) // 3,
                callbacks=[acc_val_checkpointer, csv_logger, acc_train_checkpointer],
                verbose=1,
                workers=4)
