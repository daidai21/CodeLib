#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_condition.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:15:58 PM CST
# =============================================================================


"""
using thread for glob_var add 1, 2 and 3 in turn, test whether threads run
 sequentially. thread sync using Condition, result is true.
URL: https://docs.python.org/zh-cn/3/library/threading.html
"""


from threading import Thread
from threading import Condition
import time
import random


glob_var = []


def func1():
    global exec_condition
    global finish_sign
    with exec_condition:
        time.sleep(random.random())
        glob_var.append(1)

        finish_sign[1] = lambda: True
        exec_condition.notify(2)


def func2():
    global exec_condition
    global finish_sign
    with exec_condition:
        exec_condition.wait_for(finish_sign[1])

        time.sleep(random.random())
        glob_var.append(2)

        finish_sign[2] = lambda: True
        exec_condition.notify(1)


def func3():
    global exec_condition
    global finish_sign
    with exec_condition:
        exec_condition.wait_for(finish_sign[2])

        time.sleep(random.random())
        glob_var.append(3)


def using_multiply_thread():
    print(glob_var)

    # define global
    global exec_condition
    exec_condition = Condition()
    global finish_sign
    finish_sign = [None, False, False]

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
