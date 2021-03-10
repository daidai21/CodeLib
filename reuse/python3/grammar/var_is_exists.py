#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : var_is_exists.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  3/10 19:54:06 2021
# #############################################################################


if __name__ == "__main__":
    try:
        abc
    except:
        is_exists =  False
    else:
        is_exists =  True
    print(is_exists)

    abc = 123
    try:
        abc
    except:
        is_exists =  False
    else:
        is_exists =  True
    print(is_exists)
