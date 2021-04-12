#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# #############################################################################
# File Name   : __init__and__del__.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四  4/ 8 11:34:48 2021
# #############################################################################


class Foo(object):
    def __init__(self):
        print("Foo.__init__()")

    def bar(self):
        print("Foo.bar()")

    def __del__(self):
        print("Foo.__del__()")


if __name__ == '__main__':
    foo1 = Foo()
    del foo1
    print("=====")
    foo = Foo()
