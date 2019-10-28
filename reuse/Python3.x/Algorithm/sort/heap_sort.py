#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: heap_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:03:21 PM CST
# =============================================================================


def head_sort(lst):
    def shit_down(start, end):
        root = start
        while True:
            child = 2 * root + 1
            if child > end:
                break
            if child + 1 <= end and lst[child] < lst[child + 1]:
                child += 1
            if lst[root] < lst[child]:
                lst[root], lst[child] = lst[child], lst[root]
                root = child
            else:
                break

    # create maximum heap
    for start in range(len(lst) - 2, -1, -1):
        shit_down(start, len(lst) - 1)
    # heap sort
    for end in range(len(lst) -1, 0, -1):
        lst[0], lst[end] = lst[end], lst[0]
        shit_down(0, end - 1)
    return lst


if __name__ == "__main__":
    l = [9, 2, 1, 7, 6, 8, 5, 3, 4]
    ls = head_sort(l)
    print(l)
    print(ls)
