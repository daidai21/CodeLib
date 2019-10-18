# -*- coding: utf-8 -*-

import cv2

trackbar_name = "interation"
win_name = "TrackbarDemo"
max_num = 10
value = 3


def on_dilate(arg):
    value = cv2.getTrackbarPos(trackbar_name, win_name)
    res = cv2.dilate(img, cv2.getStructuringElement(cv2.MORPH_RECT, (3, 3)), None, None, value)
    cv2.imshow(win_name, res)


img = cv2.imread("1.png")
cv2.namedWindow(win_name)
cv2.createTrackbar(trackbar_name, win_name, value, max_num, on_dilate)
on_dilate(0)
cv2.waitKey(0)
