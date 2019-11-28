#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: is_prime_test.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu 28 Nov 2019 11:22:15 AM CST
# =============================================================================


from is_prime import is_prime1
from is_prime import is_prime2
from is_prime import is_prime3

import unittest
import time


NUM_RANGE = 10 ** 5


class TestMain(unittest.TestCase):
    def test_logic_error(self):
        for num in range(1, NUM_RANGE):
            if is_prime1(num) == is_prime2(num) == is_prime3(num):
                print("OK")
            else:
                err_msg = "Error, last input num is: {}, result: {}, {}, {}"
                assert False, err_msg.format(num, is_prime1(num), 
                                                  is_prime2(num), 
                                                  is_prime3(num))

    def test_performance(self):
        T1 = time.time()
        for num in range(1, NUM_RANGE):
            is_prime1(num)
        T2 = time.time()
        for num in range(1, NUM_RANGE):
            is_prime2(num)
        T3 = time.time()
        for num in range(1, NUM_RANGE):
            is_prime3(num)
        T4 = time.time()
        print("Run time: is_prime1: {}, is_prime2: {}, is_prime3: {}".format(T2 - T1, T3 - T2, T4 - T3))


if __name__ == "__main__":
    unittest.main()

