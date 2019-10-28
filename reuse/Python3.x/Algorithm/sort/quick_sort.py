#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: quick_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:20:52 PM CST
# =============================================================================


def quick_sort(lst, first, last):
    if first >= last:
        return 
    mid_val = lst[first]
    low = first
    high = last
    while low < high:
        while low < high and lst[high] >= mid_val:
            high -= 1
        lst[low] = lst[high]
        while low < high and lst[low] < mid_val:
            low += 1
        lst[high] = lst[low]
    lst[low] = mid_val
    quick_sort(lst, first, low - 1)
    quick_sort(lst, low + 1, last)


if __name__ == "__main__":
    l = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    quick_sort(l, 0, len(l) - 1)
    print(l)

