#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: overload_with_class_inherit_example.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 09:50:22 PM CST
# =============================================================================


from overload_with_class_inherit import MultipleMeta


class Example(metaclass=MultipleMeta):
    def func(self, n:int):
        print("func int")

    def func(self, n:float):
        print("func float")

    def func(self, n:str):
        print("func str")


if __name__ == "__main__":
    Example().func(1)
    Example().func(1.1)
    Example().func("1")
