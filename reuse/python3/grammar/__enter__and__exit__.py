#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : __enter__and__exit__.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 日  8/30 04:42:13 2020
# #############################################################################


class Foo(object):
    def __enter__(self):
        print("Foo.__enter__()")

    @staticmethod
    def get_foo():
        return Foo()

    def __exit__(self, type, value, trace):
        print("Foo.__exit__()")


if __name__ == '__main__':
    with Foo.get_foo() as foo:
        print("foo: " + str(foo))
