#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: levenshtein_distance.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 06 Dec 2019 08:16:56 PM CST
# =============================================================================


# Link: https://en.wikipedia.org/wiki/Levenshtein_distance


def levenshtein_distance(str1, str2):
    if not str1:
        return len(str2 or '') or 0
    if not str2:
        return len(str1 or '') or 0

    last = 0
    tmp = [0 for _ in range(len(str2) + 1)]
    result = 0
    for i in range(len(str1)):
        tmp[0] = i + 1
        last = i
        for j in range(len(str2)):
            if str1[i] == str2[j]:
                result = last
            else:
                result = 1 + min(last, tmp[j], tmp[j + 1])
            last = tmp[j + 1]
            tmp[j + 1] = result
    return result


if __name__ == "__main__":
    print(levenshtein_distance('tuesday', 'thursday'))

