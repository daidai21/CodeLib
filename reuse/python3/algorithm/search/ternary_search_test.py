#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: ternary_search_test.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat 23 Nov 2019 03:59:21 PM CST
# =============================================================================


from ternary_search import ternary_search_recursion_list
from ternary_search import ternary_search_iteration_list


import unittest
import random


ARRAY_LENGTH = 1000
NUMBER_RANGE = 1000
TEST_NUMBER = 1000


class TestMain(unittest.TestCase):
    def _generate_convex_array(self):
        lst = [random.randrange(NUMBER_RANGE) for _ in range(ARRAY_LENGTH)]
        lst.sort()
        idx = random.randrange(ARRAY_LENGTH)
        return lst[:idx] + lst[idx:][::-1]

    def test_ternary_search_recursion_list(self):
        for _ in range(TEST_NUMBER):
            lst = self._generate_convex_array()
            max_val_idx = ternary_search_recursion_list(lst, 0, len(lst))
            err_msg = "Error, last input lst: {}"
            assert lst[max_val_idx] == max(lst), err_msg.format(lst, max_val_idx)
            print("OK")

    def test_ternary_search_iteration_list(self):
        for _ in range(TEST_NUMBER):
            lst = self._generate_convex_array()
            max_val_idx = ternary_search_iteration_list(lst, 0, len(lst))
            err_msg = "Error, last input lst: {}"
            assert lst[max_val_idx] == max(lst), err_msg.format(lst, max_val_idx)
            print("OK")


if __name__ == "__main__":
    unittest.main()
