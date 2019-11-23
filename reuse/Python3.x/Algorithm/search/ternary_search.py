#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: ternary_search.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat 23 Nov 2019 02:21:55 PM CST
# =============================================================================


from typing import List


# link: https://en.wikipedia.org/wiki/Ternary_search


def ternary_search_recursion(func, left: float, right: float, absolute_precision: float) -> float:
    if abs(right - left) < absolute_precision:
        return (left + right) / 2
    left_third = (2 * left + right) / 3.0
    right_third = (left + 2 * right) / 3.0
    if func(left_third) < func(right_third):
        return ternary_search_recursion(func, left_third, right, absolute_precision)
    else:
        return ternary_search_recursion(func, left, right_third, absolute_precision)


def ternary_search_iteration(func, left: float, right: float, absolute_precision: float) -> float:
    while True:
        if abs(right - left) < absolute_precision:
            return (left + right) / 2
        left_third = left + (right - left) / 3.0
        right_third = right - (right - left) / 3.0
        if func(left_third) < func(right_third):
            left = left_third
        else:
            right = right_third


"""
This algorithm is used to find extremum in convex array or concave array. Here version apply to convex array.
"""


def ternary_search_recursion_list(lst: List, left: float, right: float) -> float:  # BUG: Arrays are incremental and not concave array
    """
    right: len(lst)
    left: 0
    """
    if left == right:
        return left
    left_third = (2 * left + right) // 3
    right_third = (left + 2 * right) // 3
    if lst[left_third] < lst[right_third]:
        return ternary_search_recursion_list(lst, left_third + 1, right)
    else:
        return ternary_search_recursion_list(lst, left, right_third)


def ternary_search_iteration_list(lst: List, left: float, right: float) -> float:  # BUG: Arrays are incremental and not concave array
    """
    right: len(lst)
    left: 0
    """
    while True:
        if left == right:
            return left
        left_third = left + (right - left) // 3
        right_third = right - (right - left) // 3
        if lst[left_third] < lst[right_third]:
            left = left_third + 1
        else:
            right = right_third - 1


if __name__ == "__main__":
    f = lambda x: -(x ** 2) + x + 1
    print(ternary_search_recursion(f, -10, 10, 0.1))
    print(ternary_search_iteration(f, -10, 10, 0.1))

    import matplotlib.pyplot as plt
    import numpy as np
    import inspect
    x = np.arange(-10, 10, 0.1)
    y = f(x)
    plt.plot(x, y)
    plt.title("function: " + inspect.getsourcelines(f)[0][0])
    plt.show()
