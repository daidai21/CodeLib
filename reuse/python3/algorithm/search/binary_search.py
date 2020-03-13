#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: binary_search.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 09:15:45 PM CST
# =============================================================================


# recursion
def binary_search_recursion(array, start, end, key):
    if start > end:
        return -1
    mid = (start + end) // 2
    if array[mid] == key:
        return mid
    elif array[mid] > key:
        return binary_search_recursion(array, start, mid - 1, key)
    else:
        return binary_search_recursion(array, mid + 1, end, key)


# iteration
def binary_search_iteration(array, left, right, key):
    while left <= right:
        mid = (left + right) // 2
        if array[mid] == key:
            return mid
        elif array[mid] < key:
            left = mid + 1
        else:
            right = mid - 1
    return -1


if __name__ == "__main__":
    lst = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

    assert binary_search_recursion(lst, 0, len(lst) - 1, -10) == -1
    assert binary_search_recursion(lst, 0, len(lst) - 1, 10) == -1
    assert binary_search_recursion(lst, 0, len(lst) - 1, 6) == 6
    assert binary_search_recursion(lst, 0, len(lst) - 1, 0) == 0
    assert binary_search_recursion(lst, 0, len(lst) - 1, 9) == 9

    assert binary_search_iteration(lst, 0, len(lst) - 1, -10) == -1
    assert binary_search_iteration(lst, 0, len(lst) - 1, 10) == -1
    assert binary_search_iteration(lst, 0, len(lst) - 1, 6) == 6
    assert binary_search_iteration(lst, 0, len(lst) - 1, 0) == 0
    assert binary_search_iteration(lst, 0, len(lst) - 1, 9) == 9
