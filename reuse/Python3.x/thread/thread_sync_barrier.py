#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_barrier.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:16:23 PM CST
# =============================================================================


"""
using thread for glob_var add 1, 2 and 3 in turn, test whether threads run
 sequentially. thread sync using Barrier, result is true.
URL: https://docs.python.org/zh-cn/3/library/threading.html
"""


from threading import Thread
from threading import Barrier
import time
import random


glob_var = []


def func1():
    time.sleep(random.random())
    glob_var.append(1)

    global barriers
    barriers[2].wait()


def func2():
    global barriers
    barriers[2].wait()

    time.sleep(random.random())
    glob_var.append(2)

    barriers[3].wait()


def func3():
    global barriers
    barriers[3].wait()

    time.sleep(random.random())
    glob_var.append(3)


def using_multiply_thread():
    print(glob_var)

    # define global
    global barriers
    barriers = (
        None,    # start from index 1
        None,    # the first thread need't barrier
        Barrier(2),
        Barrier(2),
    )

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
    using_multiply_thread()
