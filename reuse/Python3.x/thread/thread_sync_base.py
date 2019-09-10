#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_base.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:18:18 PM CST
# =============================================================================


"""
using thread for glob_var add 1, 2 and 3 in turn, test whether threads run
 sequentially. confusion thread sync, result is error.
URL: https://docs.python.org/zh-cn/3/library/threading.html
     https://docs.python.org/zh-cn/3/library/concurrent.futures.html
"""


from threading import Thread
from concurrent.futures import ThreadPoolExecutor
import time
import random


glob_var = []


def func1():
    time.sleep(random.random())
    glob_var.append(1)


def func2():
    time.sleep(random.random())
    glob_var.append(2)


def func3():
    time.sleep(random.random())
    glob_var.append(3)


def using_thread_pool():
    print(glob_var)

    with ThreadPoolExecutor(max_workers=3) as tpe:
        # submit run
        for func in (func1, func2, func3):
            tpe.submit(func)
        # wait sub thread complete
        tpe.shutdown()

    print(glob_var)


def using_multiply_thread():
    print(glob_var)

    # create thread
    threads = (
        Thread(target=func1),
        Thread(target=func2),
        Thread(target=func3),
    )
    # start sub_thread
    for thread in threads:
        thread.start()
    # wait sub thread complete
    for thread in threads:
        thread.join()

    print(glob_var)


if __name__ == "__main__":
    using_thread_pool()
    using_multiply_thread()
