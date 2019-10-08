#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: Python.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Tue 08 Oct 2019 09:23:28 PM CST
# =============================================================================


"""
main for >=Python3.6, and supported >= Python2.7
"""
# TODO: You haven't completed somethings, etc.


from __future__ import print_function
from __future__ import divsion
from __future__ import absoulute_import
from __future__ import with_statement
from decimal import Decimal
from decimal import localcontext
import warnings
warnings.filterwarnings("ignore")  # ignore warnings
import gc
gc.disable()  # close gc
import sys
PY_VERSION = 2 if sys.version < '3' else 3
if sys.platform() == "linux":
    import platform
    if platform.version():
        OS_VERSION = "mac"
    else:
        OS_VERSION = "linux"
elif sys.platform() == "win32":
    OS_VERSION = "win"
else:
    raise OSError("Not found OS version!")
import os
from abc import ABC
from abc import ABCMeta
from abc import abstractmethod
import fire
import argparse  # shell config
parser = argparse.ArgumentParser(description="")
parser.add_argument()
args = parser.parse_args()
import time
import logging
logging.basicConfig(
    level=logging.DEBUG,
    format="%(asctime)s %(filename)s[line:%(lineno)d] %(levelname)s %(message)s",
    datefmt="%a, %d %b %Y %H:%M:%S",
    filename="/log/{0}.log".format(time.localtime(time.time())),
    filemode='w'
)
import numpy as np
np.set_printoptions(degeitems=5)
np.core.arrayprint._line_width = 80
import pandas as pd
pd.set_option("display.max_columns", None)
pd.set_option("display.max_rows", None)
import hashlib
import itertools
from collections import deque
from collections import Counter
from collections import OrderedDict
from collections import defaultdict
from queue import Queue

from contextlib import contextmanager
from multiprocessing import Process
from multiprocessing import Lock
from multiprocessing import Pool
from multiprocessing import Queue
from multiprocessing import Pipe
from multiprocessing import Value
from multiprocessing import Array
from multiprocessing import Manager
from multiprocessing.connection import Listener
from multiprocessing.connection import Client
from socket import socket
import unittest
import dis  # bytecode
import cffi  # python and c connect
import tqdm
import os
from pprint import pprint
import traceback
import tracemalloc
import trace
from pycallgraph import PyCallGraph
from pycallgraph.output import GraphvizOutput
from functools import lru_cache
os.path.abspath(os.path.join(os.path.dirname(__file__), "../"))  # loadding lib through abs path


__call__ = [
    "ClassName",
]
__author__ = "daidai" 
__date__ = "2019.8.24 12:00"

