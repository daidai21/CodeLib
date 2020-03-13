#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: thread_sync_semaphore.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 10 Sep 2019 03:16:40 PM CST
# =============================================================================


"""
using thread for glob_var add 1, 2 and 3 in turn, test whether threads run
 sequentially. thread sync using Semaphore, result is true.
URL: https://docs.python.org/zh-cn/3/library/threading.html
"""


from threading import Thread
from threading import Semaphore
import time
import random


glob_var = []


def func1():
    time.sleep(random.random())
    glob_var.append(1)

    global semaphores
    semaphores[2].release()


def func2():
    global semaphores

    with semaphores[2]:
        time.sleep(random.random())
        glob_var.append(2)

        semaphores[3].release()


def func3():
    global semaphores
    with semaphores[3]:
        time.sleep(random.random())
        glob_var.append(3)


def using_multiply_thread():
    print(glob_var)

    # define global
    global semaphores
    semaphores = (
        None,    # start from index 1
        None,    # the first thread need't semaphore
        Semaphore(0),
        Semaphore(0),
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
