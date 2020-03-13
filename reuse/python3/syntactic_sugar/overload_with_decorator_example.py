#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: overload_with_decorator_example.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 09:50:44 PM CST
# =============================================================================


from overload_with_decorator import Multimethod


class Example(object):
    @Multimethod
    def func(self, *args):
        raise TypeError("No matching method for function")

    @func.match(int)
    def func(self, x):
        print("func int")

    @func.match(float)
    def func(self, x):
        print("func float")

    @func.match(str)
    def func(self, x):
        print("func str")


if __name__ == '__main__':
    Example().func(1)
    Example().func(1.1)
    Example().func("1")
