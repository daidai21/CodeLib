#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : yield_recursion.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  3/24 19:49:07 2021
# #############################################################################


def lprint(a):
    if isinstance(a, list):
        for i in a:
            yield from lprint(i)
    else:
        yield a


if __name__ == '__main__':
    b = [[1, [2, 3], 4], [5, 6, [7, 8, [9]]]]
    for i in lprint(b):
        print(i)
