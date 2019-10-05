#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: str_to_var.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 04 Oct 2019 07:48:30 PM CST
# =============================================================================


# exec
x = "a"
exec("{0} = {1}".format(x, 2))
print(a, type(a))


# dict
dic = {}
x = "a"
dic[x] = 2
print(dic["a"], type(dic["a"]))


# setattr
class C:
    def func(self):
        name = "x"
        value = 2
        setattr(self, name, value)
        print(self.x, type(self.x))
C().func()

