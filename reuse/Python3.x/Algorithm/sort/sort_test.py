#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: sort_test.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat 02 Nov 2019 06:00:26 PM CST
# =============================================================================


from bubble_sort import bubble_sort
from bucket_sort import bucket_sort
from count_sort import count_sort
from insert_sort import insert_sort
from merge_sort import merge_sort
from quick_sort import quick_sort
from heap_sort import heap_sort

import random
import unittest


LIST_LENGTH = 1000
LIST_VALUE_MIN = -100
LIST_VALUE_MAX = 100


class TestMain(unittest.TestCase):
    def _sort_template(self, func):
        lst = [random.randint(LIST_VALUE_MIN, LIST_VALUE_MAX) for _ in range(LIST_LENGTH)]
        return sorted(lst) == func(lst)

    def test_all_sort(self):
        for func in [bubble_sort, bucket_sort, count_sort, insert_sort, 
        merge_sort, quick_sort, heap_sort]:
            if self._sort_template(func):
                print("OK ", str(func))
            else:
                assert False, "{} error".format(func)


if __name__ == "__main__":
    unittest.main()

