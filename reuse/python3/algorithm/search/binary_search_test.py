#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: binary_search_test.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sun 08 Dec 2019 12:03:57 PM CST
# =============================================================================


from binary_search import binary_search_iteration
from binary_search import binary_search_recursion

import unittest
import random


ARRAY_LENGTH = 1000
ARRAY_MAX_VALUE = 1000
TEST_NUMBER = 1000


class TestMain(unittest.TestCase):
    def _make_sorted_list(self):
        lst = [random.randrange(ARRAY_MAX_VALUE) for _ in range(ARRAY_LENGTH)]
        lst.sort()
        key = random.choice(lst)
        return lst, key

    def test_binary_search_recursion(self):
        for _ in range(TEST_NUMBER):
            lst, key = self._make_sorted_list()
            idx = binary_search_recursion(lst, 0, len(lst) - 1, key)
            err_msg = "Error: binary_search_recursion, lst: {}, key: {}, idx: {}"
            assert lst[idx] == key, err_msg.format(lst, key, idx)
            print("OK")

    def test_binary_search_iteration(self):
        for _ in range(TEST_NUMBER):
            lst, key = self._make_sorted_list()
            idx = binary_search_iteration(lst, 0, len(lst) - 1, key)
            err_msg = "Error: binary_search_iteration, lst: {}, key: {}, idx: {}"
            assert lst[idx] == key, err_msg.format(lst, key, idx)
            print("OK")


if __name__ == "__main__":
    unittest.main()

