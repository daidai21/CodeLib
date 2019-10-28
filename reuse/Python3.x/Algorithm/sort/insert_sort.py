#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: insert_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:36:24 PM CST
# =============================================================================


def insert_sort(lst):
    if len(lst) <= 1:
        return lst
    for i in range(1, len(lst)):
        for j in range(i, 0, -1):
            if lst[j] < lst[j - 1]:
                lst[j], lst[j - 1] = lst[j - 1], lst[j]
            else:
                break
    return lst


def insert_sort(lst):
    for i in range(1, len(lst)):
        tmp = lst[i]
        j = i - 1
        while j >= 0 and tmp < lst[j]:
            lst[j + 1] = lst[j]
            j -= 1
        lst[j + 1] = tmp
    return lst


if __name__ == "__main__":
    l = [1, 4, 2, 3, 6, -1, 0, 25, -34, 8, 9, 1, 0]
    ls = insert_sort(l)
    print(ls)

