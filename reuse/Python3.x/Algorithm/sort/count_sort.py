#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: count_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:42:09 PM CST
# =============================================================================


def count_sort(lst):
    max_val = max(lst)
    min_val = min(lst)
    container = [0 for _ in range(min_val, max_val + 1)]
    for i in lst:
        container[i - min_val] += 1
    result = []
    for idx in range(len(container)):
        while container[idx] > 0:
            result.append(idx + min_val)
            container[idx] -= 1
    return result


if __name__ == "__main__":
    l = [1, 4, 2, 3, 6, -1, 0, 25, -34, 8, 9, 1, 0]
    ls = count_sort(l)
    print(ls)

