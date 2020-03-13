#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: gcd.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 10:27:59 PM CST
# =============================================================================


def gcd(a, b):
    if b == 0:
        return a
    else:
        if a % b == 0:
            return b
        else:
            return gcd(b, a % b)


gcd = lambda a, b: (gcd(b, a % b) if a % b else b)


if __name__ == '__main__':
    print(gcd(54, 24))
