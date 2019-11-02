#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: quick_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:20:52 PM CST
# =============================================================================


def quick_sort(lst):
    def sort(lst, first, last):
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
        sort(lst, first, low - 1)
        sort(lst, low + 1, last)
        return lst

    return sort(lst, 0, len(lst) - 1)

if __name__ == "__main__":
    lst = [9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
    l = quick_sort(lst)
    print(l)

