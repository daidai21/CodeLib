#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: euclidean_distance.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 06 Dec 2019 08:28:32 PM CST
# =============================================================================


def euclidean_distance(point1, point2):
    return ((point1[0] - point2[0]) ** 2 + (point1[1] - point2[1]) ** 2) ** 0.5

