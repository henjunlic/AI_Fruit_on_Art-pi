# coding=utf-8
'''
@ Summary: 
@ Update:  

@ file:    image_detection.py
@ version: 1.0.0

@ Author:  Lebhoryi@gmail.com
@ Date:    2021/6/30 上午10:38
'''
import tensorflow as tf
import time
from tensorflow.keras.models import load_model
import numpy as np
import cv2

image = "test3.jpg"
image = cv2.imread(image)
image = cv2.resize(image, (64, 64))
image = image.astype("float") / 255.0
image = np.expand_dims(image, axis=0)

# loading the stored model from file
# model = load_model(r'./TrainedModels/Fire-64x64-color-v7.1-soft.h5')
model = load_model(r'../Models/20210630.h5')

# model.summary()
start_time = time.time()
pred = model.predict(image)
stop_time = time.time()
print(pred)
print('time: {:.3f}ms'.format((stop_time - start_time) * 1000))


# [[1.0000000e+00 1.1498373e-10]]
# time: 124.759ms