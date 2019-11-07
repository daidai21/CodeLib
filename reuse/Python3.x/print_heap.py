#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: print_heap.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 07 Nov 2019 02:55:26 PM CST
# =============================================================================


from drawtree import draw_level_order

from typing import List


def print_heap(lst: List) -> None:
    draw_level_order(str(lst))


if __name__ == "__main__":
    print_heap([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16])
    print_heap([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    print_heap([1, 2, 3, 4, 5, 6, 7])
    print_heap([1, 2, 3])
    print_heap([1])
