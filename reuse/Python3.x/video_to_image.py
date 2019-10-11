#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: video_to_image.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 11 Oct 2019 12:32:38 PM CST
# =============================================================================


# TODO: fps


def video_to_image(file_path, save_path):
    import cv2
    import os

    vidcap = cv2.VideoCapture(file_path)
    success, image = vidcap.read()
    count = 0
    while success:
        cv2.imwrite(os.path.join(save_path + "{}.jpg".format(count)), image)     # save frame as JPEG file      
        success, image = vidcap.read()
        print('Read a new frame: ', success)
        count += 1
    print("Count {} images".format(count + 1))


if __name__ == "__main__":
    video_to_image("干电池测量仪.mp4", "tmp/")

