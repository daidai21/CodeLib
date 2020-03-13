#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: bubble_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:33:44 PM CST
# =============================================================================


def bubble_sort(lst):
    for i in range(len(lst)):
        for j in range(i + 1, len(lst)):
            if lst[i] > lst[j]:
                lst[i], lst[j] = lst[j], lst[i]
    return lst


if __name__ == "__main__":
    l = [27, 33, 28, 4, 2, 26, 13, 35, 8, 14]
    ls = bubble_sort(l)
    print(ls)

