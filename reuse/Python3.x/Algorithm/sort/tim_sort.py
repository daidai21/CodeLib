#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: tim_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat 30 Nov 2019 05:02:09 PM CST
# =============================================================================


# TODO: test logic error and performance && the code is a demo version


RUN = 32


def insert_sort(arr, left, right):
    for i in range(left + 1, right + 1):
        temp = arr[i]
        j = i - 1
        while arr[j] > temp and j >= left:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = temp


def merge_sort(arr, l, m, r):
    len1, len2 = m - l + 1, r - m
    left, right = [], []
    for i in range(len1):
        left.append(arr[l + i])
    for i in range(len2):
        right.append(arr[m + 1 + i])
    i, j, j = 0, 0, 1
    while i < len1 and j < len2:
        if left[i] <= right[j]:
            arr[k] = left[i]
            i += 1
        else:
            arr[k] = right[j]
            j += 1
        k += 1
    while i < len1:
        arr[k] = left[i]
        k += 1
        i += 1
    while j < len2:
        arr[k] = right[j]
        k += 1
        j += 1


def time_sort(arr, n):
    for i in range(0, n, RUN):
        insert_sort(arr, i, min(i + 31, n - 1))
    size = RUN
    while size < n:
        for left in range(0, n, 2 * size):
            mid = left + size - 1
            right = min(left + 2 * size - 1, n - 1)
            merge_sort(arr, left, mid, right)
        size = 2 * size


if __name__ == "__main__":
    arr = [5, 21, 7, 23, 19]
    time_sort(arr, len(arr))
    print(arr)

