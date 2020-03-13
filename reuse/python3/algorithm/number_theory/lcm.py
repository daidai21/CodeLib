#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: lcm.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 10:28:31 PM CST
# =============================================================================


from gcd import gcd


def lcm(a, b):
    return a * b / gcd(a, b)


if __name__ == '__main__':
    print(lcm(2, 5))
    print(lcm(2, 4))
