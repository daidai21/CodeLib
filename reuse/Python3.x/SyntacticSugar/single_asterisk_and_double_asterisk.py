#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: single_asterisk_and_double_asterisk.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat Jan 18 14:31:41 2020
# =============================================================================


def foo(*args, **kwarg):
    print("foo(): ", type(args), args, type(kwarg), kwarg)
    print("args: ", end="")
    for item in args:
        print(item, end=", ")
    print()
    print("kwarg: ", end="")
    for k, v in kwarg.items():
        print("{}: {}".format(k, v), end=", ")
    print()


if __name__ == "__main__":
    tpl = (1, 2, 3, 4)
    lst = [1, 2, 3, 4]
    st = set([1, 2, 3, 4])
    dic = {"a": 1, "b": 2, "c": 3, "d": 4}

    print("*" * 10, "foo(tpl, dic)", "*" * 10)
    foo(tpl, dic)
    print("*" * 10, "foo(lst, dic)", "*" * 10)
    foo(lst, dic)
    print("*" * 10, "foo(st, dic)", "*" * 10)
    foo(st, dic)

    print("*" * 10, "foo(tpl, **dic)", "*" * 10)
    foo(tpl, **dic)
    print("*" * 10, "foo(lst, **dic)", "*" * 10)
    foo(lst, **dic)

    print("*" * 10, "foo(*lst, **dic)", "*" * 10)
    foo(*lst, **dic)

    print("*" * 10, "foo(*lst, *dic)", "*" * 10)
    foo(*lst, *dic)
