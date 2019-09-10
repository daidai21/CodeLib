#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_lock.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:15:29 PM CST
# =============================================================================


"""
using thread for glob_var add 1, 2 and 3 in turn, test whether threads run
 sequentially. thread sync using Lock, result is true.
URL: https://docs.python.org/zh-cn/3/library/threading.html
"""


from threading import Thread
from threading import Lock
import time
import random


glob_var = []


def func1():
    global locks
    time.sleep(random.random())
    glob_var.append(1)
    # lock 2
    locks[2].release()


def func2():
    global locks
    with locks[2]:
        time.sleep(random.random())
        glob_var.append(2)
        # lock 3
        locks[3].release()


def func3():
    global locks
    with locks[3]:
        time.sleep(random.random())
        glob_var.append(3)


def using_multiply_thread():
    print(glob_var)

    # define global lock
    global locks
    locks = (
        None,    # start from index 1
        None,    # the first thread need't lock
        Lock(),
        Lock(),
    )
    locks[2].acquire()
    locks[3].acquire()

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
