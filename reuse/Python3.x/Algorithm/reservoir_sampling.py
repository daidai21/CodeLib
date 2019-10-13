#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: reservoir_sampling.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sun 13 Oct 2019 03:22:05 PM CST
# =============================================================================


import random


class ReservoirSampling(object):
    def __init__(self, n_sample):
        self._n_sample = n_sample
        self._samples = []
        self._idx = 0

    def feed(self, sample):
        if self._idx < self._n_sample:
            self._samples.append(sample)
        else:
            i = random.randint(0, self._idx)
            if i < self._n_sample:
                self._samples[i] = sample
        self._idx += 1

    @property
    def get_sample(self):
        return self._samples

