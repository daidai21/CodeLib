#!/usr/bin/env python3
# -*- coding:utf-8 -*-


from typing import List


def print_heap(lst: List) -> None:
    from drawtree import draw_level_order

    draw_level_order(str(lst))


if __name__ == "__main__":
    print_heap([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16])
    print_heap([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15])
    print_heap([1, 2, 3, 4, 5, 6, 7])
    print_heap([1, 2, 3])
    print_heap([1])
