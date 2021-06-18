#!/usr/bin/env python2
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : null_object.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 日  2/ 7 11:24:25 2021
# #############################################################################

# ref:  https://gist.github.com/kernc/9484240

from collections import MutableMapping, MutableSequence

class NullObject(type):
    class _MetaNull(type):
        pass

    __metaclass__ = _MetaNull
    # 对象的hash值唯一标识
    __hash__ = type.__hash__
    # 限制实例的属性为空
    __slots__ = ()
    # 不可迭代
    def __next__(_):
        raise StopIteration
    next = __next__  # Python 2 compatibility
    # 列出对象的所有属性（方法）名
    __dir__ = lambda _: []
    # print为空字符串
    __str__ =   lambda _: ''
    # repr()函数调用
    __repr__ =  lambda _: '<Null>'
    # bytes()函数调用
    __bytes__ = lambda _: b''
    # 
    __int__ = \
    __len__ = \
    __index__ = \
    __round__ = \
    __complex__ = lambda *_: 0
    # 
    __float__ =   lambda *_: 0.
    # 
    __eq__ = \
    __ge__ = \
    __gt__ = \
    __le__ = \
    __lt__ = \
    __ne__ = \
    __or__ = \
    __and__ = \
    __del__ = \
    __get__ = \
    __set__ = \
    __abs__ = \
    __add__ = \
    __mod__ = \
    __mul__ = \
    __new__ = \
    __neg__ = \
    __pos__ = \
    __pow__ = \
    __ror__ = \
    __sub__ = \
    __xor__ = \
    __call__ = \
    __exit__ = \
    __init__ = \
    __iter__ = \
    __radd__ = \
    __rand__ = \
    __rmod__ = \
    __rmul__ = \
    __rpow__ = \
    __rsub__ = \
    __rxor__ = \
    __enter__ =  \
    __delete__ = \
    __divmod__ = \
    __invert__ = \
    __lshift__ = \
    __rshift__ = \
    __delattr__ = \
    __delitem__ = \
    __getattr__ = \
    __getitem__ = \
    __rdivmod__ = \
    __rlshift__ = \
    __rrshift__ = \
    __setattr__ = \
    __setitem__ = \
    __truediv__ = \
    __floordiv__ = \
    __rtruediv__ = \
    __rfloordiv__ = \
    __getattribute__ = lambda self, *_, **__: self


NullObject.__class__ = NullObject

class nulldict(dict):
    def __missing__(self, key):
        return NullObject


class nulllist(list):
    def __getitem__(self, i):
        return list.__getitem__(self, i) if i < len(self) else NullObject

        
class nulltuple(tuple):
    def __getitem__(self, i):
        return tuple.__getitem__(self, i) if i < len(self) else NullObject


def nullify(obj):
    if isinstance(obj, MutableMapping):
        return nulldict(obj)
    if isinstance(obj, tuple):
        return nulltuple(obj)
    if isinstance(obj, MutableSequence):
        return nulllist(obj)
    return obj or NullObject
