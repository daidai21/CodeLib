#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: hamming_distance.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 06 Dec 2019 08:30:41 PM CST
# =============================================================================


def hamming_distance(x: int, y: int) -> int:
    return bin(x ^ y).count('1')

