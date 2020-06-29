#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : switch_case.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 一  6/29 14:19:27 2020
# #############################################################################


# ***** Example 1 *****
def case_add(*args, **kwargs):
    return args[0] + args[1]


def case_substract(*args, **kwargs):
    return args[0] - args[1]


switch = {
    "+": case_add,
    "-": case_substract
}


print(switch["+"](1, 2))
print(switch["-"](1, 2))


# ***** Example 2 *****
def switch(k):
    return {
        'a': 10,  # The value here can be lambda
        'b': 20
    }.get(k, 100)


print(switch('a'))
print(switch('b'))
print(switch('c'))

