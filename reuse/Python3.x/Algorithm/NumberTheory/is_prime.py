#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: is_prime.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 28 Nov 2019 11:03:21 AM CST
# =============================================================================


def is_prime1(num: int) -> bool:
    if num < 2:
        return False
    for divisor in range(2, num):
        if num % divisor == 0:
            return False
    return True


def is_prime2(num: int) -> bool:
    if num < 2:
        return False
    for divisor in range(2, int(num ** 0.5 + 1)):
        if num % divisor == 0:
            return False
    return True


def is_prime3(num: int) -> bool:
    if num < 2:
        return False
    elif num == 2 or num == 3:
        return True
    elif num % 6 != 1 and num % 6 != 5:
        return False
    for divisor in range(5, int(num ** 0.5 + 1)):
        if num % divisor == 0 or num % (divisor + 2) == 0:
            return False
    return True


# rename modeule method
is_prime = is_prime2
# del is_prime1
# del is_prime2
# del is_prime3


if __name__ == "__main__":
    print(is_prime(4))

