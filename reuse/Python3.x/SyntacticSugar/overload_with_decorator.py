#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: overload_with_decorator.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 09:45:04 PM CST
# =============================================================================


"""
reference url: https://python3-cookbook.readthedocs.io/zh_CN/latest/c09/p20_implement_multiple_dispatch_with_function_annotations.html
"""


import types


class Multimethod(object):
    def __init__(self, func):
        self._methods = {}
        self.__name__ = func.__name__
        self._default = func

    def match(self, *types):
        def register(func):
            ndefaults = len(func.__defaults__) if func.__defaults__ else 0
            for n in range(ndefaults + 1):
                self._methods[types[:len(types) - n]] = func
            return self

        return register

    def __call__(self, *args):
        types = tuple(type(arg) for arg in args[1:])
        meth = self._methods.get(types, None)
        if meth:
            return meth(*args)
        else:
            return self._default(*args)

    def __get__(self, instance, cls):
        if instance is not None:
            return types.MethodType(self, instance)
        else:
            return self
