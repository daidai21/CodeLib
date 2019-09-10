#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_rlock.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:15:47 PM CST
# =============================================================================


"""
using thread for glob_var add "< n" and "n >" in turn inside funtion, test
 whether threads run sequentially. thread sync using RLock, result is true. in
 function "using_multiply_thread_rlock", function run order is 1, 2, 3, not
 about RLock also accidental.
URL: https://docs.python.org/zh-cn/3/library/threading.html
"""
# TODO: RLock not show recursion method


from threading import Thread
from concurrent.futures import ThreadPoolExecutor
from threading import RLock
import time
import random


glob_var = []


###############################################################################
# confusion
###############################################################################


def func1():
    glob_var.append("< 1")
    time.sleep(random.random())
    glob_var.append("1 >")


def func2():
    glob_var.append("< 2")
    time.sleep(random.random())
    glob_var.append("2 >")


def func3():
    glob_var.append("< 3")
    time.sleep(random.random())
    glob_var.append("3 >")


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


###############################################################################
# RLock
###############################################################################


def rlock_func1():
    global rlock
    rlock.acquire()

    glob_var.append("< 1")
    time.sleep(random.random())
    glob_var.append("1 >")

    rlock.release()


def rlock_func2():
    global rlock
    rlock.acquire()

    glob_var.append("< 2")
    time.sleep(random.random())
    glob_var.append("2 >")

    rlock.release()


def rlock_func3():
    global rlock
    rlock.acquire()

    glob_var.append("< 3")
    time.sleep(random.random())
    glob_var.append("3 >")

    rlock.release()


def using_multiply_thread_rlock():
    print(glob_var)

    # define global lock
    global rlock
    rlock = RLock()

    with ThreadPoolExecutor(max_workers=3) as tpe:
        # submit run
        for func in (rlock_func1, rlock_func2, rlock_func3):
            tpe.submit(func)
        # wait sub thread complete
        tpe.shutdown()

    print(glob_var)


if __name__ == "__main__":
    print("confusion thread: ")
    using_multiply_thread()
    print("rlock thread: ")
    using_multiply_thread_rlock()
