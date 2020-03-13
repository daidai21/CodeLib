#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: bucket_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 09:42:20 PM CST
# =============================================================================


def bucket_sort(lst):
    min_val = min(lst)
    buckets = [0] * (max(lst) - min_val + 1)
    for i in range(len(lst)):
        buckets[lst[i] - min_val] += 1
    result = []
    for i in range(len(buckets)):
        if buckets[i] != 0:
            result += [i + min_val] * buckets[i]
    return result


if __name__ == "__main__":
    l = [1, 4, 2, 3, 6, -1, 0, 25, -34, 8, 9, 1, 0]
    ls = bucket_sort(l)
    print(ls)


