#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: process_pool.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 09 Sep 2019 03:37:49 PM CST
# =============================================================================


from multiprocessing import Pool


def job(x):
    return x * x


def multi_core():
    p = Pool(processes=5)
    print(p.map(job, range(10)))
    print(p.apply_async(job, (2, )).get())
    print([p.apply_async(job, (i, )).get() for i in range(10)])


if __name__ == "__main__":
    multi_core()
