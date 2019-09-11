#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: load_module.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Wed 11 Sep 2019 07:53:03 PM CST
# =============================================================================


"""
load .py file inside module.
"""


import os
import sys


# add full path
sys.path.append(os.path.abspath(
    os.path.join(os.path.dirname(__file__), "../thread/"))
)  # add path: "../thread/"


# like a package, all dir have __init__.py
from ..thread.thread_pool import func
from ... import get_code.GetCode
# run command: $ python -m Python3.x.load_module
