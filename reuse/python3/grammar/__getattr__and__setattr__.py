#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : __getattr__and__setattr__.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 日  8/30 04:12:53 2020
# #############################################################################


class A(object):
    def __getattr__(self, name):
        print("You use getattr")
        try:
            return self.__dict__[name]
        except Exception as e:
            pass

    def __setattr__(self, name, value):
        print("You use setattr")
        self.__dict__[name] = value


if __name__ == '__main__':
    a = A()
    print(a.x)
    a.x = 8
    print(a.x)
