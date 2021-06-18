#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: multiple_list_sort.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sun 24 Nov 2019 08:40:10 PM CST
# =============================================================================


def multiple_list_sort(*lsts):
    err_msg = "The lenghth of input all list must be same."
    assert len(set([len(lst) for lst in lsts])) == 1, err_msg
    return list(map(list, list(zip(*sorted(zip(*lsts))))))


def lists_sort(*lists):
    """
    sort key on lists order
    """
    list_count = len(lists)
    temp = []
    for line in zip(*lists):
        temp.append(line)
    temp.sort()
    result = [[] for _ in range(list_count)]
    for line in temp:
        for idx, val in enumerate(list(line)):
            result[idx].append(val)
    return result


if __name__ == "__main__":
    result = multiple_list_sort(
        [1, 2, 3],
        [2, 3, 4]
    )
    print(result, type(result))


    result = multiple_list_sort(
        [1, 2, 3],
        [2, 3, 4],
        [2, 3, 4]
    )
    print(result, type(result))


    result = multiple_list_sort(
        [1, 2, 3],
        [2, 3, 4],
        [2, 3, 4],
        [2, 3, 4]
    )
    print(result, type(result))

    print(lists_sort(
        [9, 8, 7],
        [1, 2, 3],
        [4, 5, 6],
    ))

