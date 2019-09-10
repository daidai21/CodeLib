#!/usr/bin/python
# coding:utf-8

# ==================================================
# File Name: test_xxx.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: 三  6/25 22:49:50 2019
# ==================================================


from . import main

import doctest
import unittest


class DefaultTestCase(unittest.TestCase):
    def test_some(self):
        pass


if __name__ == '__main__':
    unittest.main()
