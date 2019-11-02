#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: big_num.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri 25 Oct 2019 10:23:45 PM CST
# =============================================================================


import gmpy2


a = gmpy2.mpz(999999999)
print(a)
print("a + a: ", a + a)
print("a - a: ", a - a - a)
print("a * a: ", a * a)
print("a / a: ", a * a / a)
print("a ** a: ", a ** 2)
print("a // a: ", a // 8)
print("a % a: ", a % 8)
