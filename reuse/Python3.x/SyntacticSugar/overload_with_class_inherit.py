#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: overload_with_class_inherit.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 09:45:39 PM CST
# =============================================================================



"""
reference url: https://python3-cookbook.readthedocs.io/zh_CN/latest/c09/p20_implement_multiple_dispatch_with_function_annotations.html
"""


import inspect
import types


class MultiMethod(object):
    """
    represents a single multimethod
    """
    def __init__(self, name):
        self._methods = {}
        self.__name = name

    def register(self, meth):
        """
        register a new method as a multimethod
        """
        sig = inspect.signature(meth)
        # build a type signature from the method's annotations
        types = []
        for name, param in sig.parameters.items():
            if name == "self":
                continue
            if param.annotation is inspect.Parameter.empty:
                raise TypeError("Argument {} must be annotated with a type".format(name))
            if not isinstance(param.annotation, type):
                raise TypeError("Argument {} annotation must be a type".format(name))
            if param.default is not inspect.Parameter.empty:
                self._methods[tuple(types)] = meth
            types.append(param.annotation)
        self._methods[tuple(types)] = meth

    def __call__(self, *args):
        """
        call a method based on type signature of the arguments
        """
        types = tuple(type(arg) for arg in args[1:])
        meth = self._methods.get(types, None)
        if meth:
            return meth(*args)
        else:
            raise TypeError("No matching method for types {}".format(types))

    def __get__(self, instance, cls):
        """
        descriptor method needed to make calls work in a class
        """
        if instance is not None:
            return types.MethodType(self, instance)
        else:
            return self


class MultiDict(dict):
    """
    special dictionary to build multimethods in a metaclass
    """
    def __setitem__(self, key, value):
        if key in self:
            # If key already exists, it must be a multimethod or callable
            current_value = self[key]
            if isinstance(current_value, MultiMethod):
                current_value.register(value)
            else:
                mvalue = MultiMethod(key)
                mvalue.register(current_value)
                mvalue.register(value)
                super().__setitem__(key, mvalue)
        else:
            super().__setitem__(key, value)


class MultipleMeta(type):
    """
    metaclass that allows multiple dispatch of methods
    """
    def __new__(cls, clsname, bases, clsdict):
        return type.__new__(cls, clsname, bases, dict(clsdict))

    @classmethod
    def __prepare__(cls, claname, bases):
        return MultiDict()
