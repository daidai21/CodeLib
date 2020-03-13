#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: GUI_adjust_binary_img.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 10:39:53 PM CST
# =============================================================================


import cv2

img_path = "1.png"

img = cv2.imread(img_path)
cv2.namedWindow('main')
min_val, max_val = None, None

def update(x):
    global min_val
    global max_val
    min_val = cv2.getTrackbarPos('min_val', 'main')
    max_val = cv2.getTrackbarPos('max_val', 'main')
    _, binary_img = cv2.threshold(img, min_val, max_val, cv2.THRESH_BINARY)
    cv2.imshow('main', binary_img)

cv2.createTrackbar('min_val', 'main', 0, 255, update)
cv2.createTrackbar('max_val', 'main', 0, 255, update)
cv2.waitKey(0)
cv2.destroyAllWindows()
