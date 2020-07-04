# !/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: flatten_list_test.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Thu Oct 24 13:57:03 2019
# =============================================================================


from flatten_list import flatten

import unittest
import random


LIST_LENGTH = 600


class TestMain(unittest.TestCase):
    def test_value(self):
        err_msg = "value flatten error."
        assert flatten(123) == [123], err_msg
        assert flatten(123.123) == [123.123], err_msg

    def test_list_empty(self):
        err_msg = "empty list flatten error."
        assert flatten([]) == [], err_msg

    def test_list_one_dimension(self):
        for i in range(1, LIST_LENGTH):
            lst = [val for val in range(i)]
            err_msg = "one dimension flatten error."
            assert lst == flatten(lst), err_msg

    def test_list_multidimension(self):
        def construct_multidimension_list(lst_length):
            if lst_length == 1:
                return lst_length
            elif random.choice([False, True]):
                return [lst_length, [construct_multidimension_list(lst_length - 1)]]
            else:
                return [lst_length, construct_multidimension_list(lst_length - 1)]

        def is_valid(lst, length):
            if len(lst) != length:
                return False
            for idx, val in enumerate(lst):
                if length - idx != val:
                    return False
            return True

        for i in range(1, LIST_LENGTH):
            lst = construct_multidimension_list(i)
            flatten_lst = flatten(lst)
            err_msg = "multidimension flatten error."
            assert is_valid(flatten_lst, i), err_msg


if __name__ == "__main__":
    unittest.main()
