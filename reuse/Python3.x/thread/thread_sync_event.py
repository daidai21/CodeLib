#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_event.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:16:07 PM CST
# =============================================================================


"""
using thread for glob_var add 1, 2 and 3 in turn, test whether threads run
 sequentially. thread sync using Event, result is true.
URL: https://docs.python.org/zh-cn/3/library/threading.html
"""


from threading import Thread
from threading import Event
import time
import random


glob_var = []


def func1():
    time.sleep(random.random())
    glob_var.append(1)

    global events
    events[2].set()


def func2():
    global events
    events[2].wait()

    time.sleep(random.random())
    glob_var.append(2)

    events[3].set()


def func3():
    global events
    events[3].wait()

    time.sleep(random.random())
    glob_var.append(3)


def using_multiply_thread():
    print(glob_var)

    # define global
    global events
    events = (
        None,    # start from index 1
        None,    # the first thread need't barrier
        Event(),
        Event(),
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
