#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: merge_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:27:29 PM CST
# =============================================================================


def merge_sort(lst):
    def merge(left, right):
        result = []
        while left and right:
            if left[0] <= right[0]:
                result.append(left.pop(0))
            else:
                result.append(right.pop(0))
        if left:
            result += left
        if right:
            result += right
        return result

    if len(lst) <= 1:
        return lst
    mid = len(lst) // 2
    left = lst[:mid]
    right = lst[mid:]
    left = merge_sort(left)
    right = merge_sort(right)
    return merge(left, right)


if __name__ == "__main__":
    l = [1, 4, 2, 3, 6, -1, 0, 25, -34, 8, 9, 1, 0]
    ls = merge_sort(l)
    print(ls)

