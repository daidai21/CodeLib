#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: search_srver_IP.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Wed 07 Aug 2019 06:54:49 PM CST
# =============================================================================


import os
import time
from multiprocessing import Pool


def loop_try_ssh(i):
    print("start try:", i)
    command = "ssh fwh@222.24.85.{0}".format(i)
    res = os.popen(command)
    print(res.read(), "IPIPIP:", i)


p = Pool(256)
for i in range(256):
    p.apply_async(loop_try_ssh, args=(i,))
p.close()
p.join()
