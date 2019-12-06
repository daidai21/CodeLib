#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: chebyshev_distance.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 06 Dec 2019 08:26:32 PM CST
# =============================================================================


def chebyshev_distance(point1, point2):
    return max(abs(point1[0] - point2[0]), abs(point1[1], point2[1]))

