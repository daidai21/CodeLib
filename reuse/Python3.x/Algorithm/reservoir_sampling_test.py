#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: reservoir_sampling_test.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sun 13 Oct 2019 03:32:39 PM CST
# =============================================================================


from reservoir_sampling import ReservoirSampling

import unittest
from collections import Counter


class TestMain(unittest.TestCase):
    def test_reservoir_sampling(self):
        for n_sample in range(1, 11):
            samples = []
            for _ in range(10000):
                RS = ReservoirSampling(n_sample)
                for sample in range(1, 11):
                    RS.feed(sample)
                samples.extend(RS.get_sample)
            print(n_sample, Counter(samples))


if __name__ == "__main__":
    unittest.main()

