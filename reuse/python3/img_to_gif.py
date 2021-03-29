#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : img_to_gif.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 五  3/26 17:19:55 2021
# #############################################################################

"""
图片转gif
"""

import os
import imageio


def img_to_gif(path, gif_name):
    image_list = [path+img for img in  os.listdir(path)]
    image_list.sort()

    frames = []
    for image_name in image_list:
        if image_name.endswith('.jpg'):
            print(image_name)
            frames.append(imageio.imread(image_name))
    imageio.mimsave(gif_name, frames, 'GIF', duration = 0.3)


if __name__ == "__main__":
    # img_to_gif("./find/", 'find/result.gif')

    img_to_gif("./solve/", 'solve/result.gif')
