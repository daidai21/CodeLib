# Python Project Guide

There are some Python project sample in different branch.

- Python project directory structure sample. [link](https://github.com/daidai21/Python-Project-Guide/tree/project)
- Python project ML/DL (kaggle/tianchi) code and directory structure sample. [link](https://github.com/daidai21/Python-Project-Guide/tree/competition)

### Environment Management

- `conda`
- `pyenv`
- `virtualenv`

### Code Style

You can read the following two documents:

- [Python社区官方建议采用的Python编码风格:PEP8](https://www.python.org/dev/peps/pep-0008/)  [中文版](http://wiki.woodpecker.org.cn/moin/PythonCodingRule)
- [Google SoC 建议的 Python 编码风格:Google Python Style Guide](http://google-styleguide.googlecode.com/svn/trunk/pyguide.html) [中文版](http://www.elias.cn/Python/PythonStyleGuide)

There are some tools can help you.

- Flake8
- Yapf
- Pylint
- Autopep8
- etc.


### Catelog

```bash

```

### Code File Structure

```python
#!/usr/bin/env python3
# coding:utf-8


# =============================================================================
# File Name: xxx.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: 日  4/8 21:39:51 2019
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
from socket import AF_INET
from socket import SOCK_STREAM
from socket import 
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


def reduce_mem_usage(df, verbose=True):
    numerics = ['int16', 'int32', 'int64', 'float16', 'float32', 'float64']
    start_mem = df.memory_usage().sum() / 1024**2    
    for col in df.columns:
        col_type = df[col].dtypes
        if col_type in numerics:
            c_min = df[col].min()
            c_max = df[col].max()
            if str(col_type)[:3] == 'int':
                if c_min > np.iinfo(np.int8).min and c_max < np.iinfo(np.int8).max:
                    df[col] = df[col].astype(np.int8)
                elif c_min > np.iinfo(np.int16).min and c_max < np.iinfo(np.int16).max:
                    df[col] = df[col].astype(np.int16)
                elif c_min > np.iinfo(np.int32).min and c_max < np.iinfo(np.int32).max:
                    df[col] = df[col].astype(np.int32)
                elif c_min > np.iinfo(np.int64).min and c_max < np.iinfo(np.int64).max:
                    df[col] = df[col].astype(np.int64)  
            else:
                if c_min > np.finfo(np.float16).min and c_max < np.finfo(np.float16).max:
                    df[col] = df[col].astype(np.float16)
                elif c_min > np.finfo(np.float32).min and c_max < np.finfo(np.float32).max:
                    df[col] = df[col].astype(np.float32)
                else:
                    df[col] = df[col].astype(np.float64)    
    end_mem = df.memory_usage().sum() / 1024**2
    if verbose:
        print('Mem. usage decreased to {:5.2f} Mb ({:.1f}% reduction)'.format(end_mem, 100 * (start_mem - end_mem) / start_mem))
    return df


class ClassName(object):
    def __init__(self, *args, **kwargs):
        return super().__init__(*args, **kwargs)

    def __new__(self):
        pass

    def __del__(self):
        pass

    def __str__(self):
        return super().__str__()

    @classmethod
    @staticmethod
    @property
    def func(self):
        pass


@contextmanager
def function_name():
    pass


if __name__ == "__main__":
    CN = ClassName()
    CN.func()

    function_name()

```

- Multiple OS platform compatible

```python
if "unix" in sys.platform:  # unix
    pass
elif sys.platform == "win32":  # win32
    pass
else:
    pass  # unrecognize OS
```

### Main Lib

- Operator System
  - `multiprocessing`
  - `threading`
  - `asyncio`
  - `gc`
  - `sys`
  - `os`
- Network
  - `socket`
- Platform
  - `platform`
- Data Structure
  - `collections`
  - `queue`
  - `numpy`
  - `pandas`
- OOP
  - `abc`
- CPython Version
  - `__future__`
- Test
  - `unittest`
  - `docstest`
  - `line_profiler`
  - `memory_profiler`
  - `profile`
  - `cProfile`
- Compute
  - `decimal`
- Time
  - `time`
- Log
  - `logging`
- Other
  - `warnings`
  - `argparse`
  - `itertools`
  - `hashlib`
  - `contextlib`
  - `tqdm`
  - `dis`
  - `cffi`

### Special Annotation

- `XXX` Warning about possible pitfalls.
- `HACK` Not very well written or malformed code to circumvent a problem/bug. 
- `FIXME` This works, sort of, but it could be done better. (usually code written in a hurry that needs rewriting).
- `TODO` There are functions that are not completed.

Python alone possess

- `# noqu`  No Quality Assurance

### Unit Testing

There are some tools can help you.

- mypy(static type checking)
- PyUnit
- Pytest
- etc.


### Performance Bottleneck Testing

- `timeit`
- `profile`
- `cProfile`
- `line_profile`
- `memory_profiler`
- `objgraph`

### Pack

Python has a dedicated module packaging system named [distutils](http://docs.python.org/library/distutils.html). You can use this mechanism to package and distribute your code to [Pypi](http://pypi.python.org/pypi), So anyone can install your module with `pip` or `easy_install`. Of course, you can also refer to [Python 打包指南](https://www.ibm.com/developerworks/cn/opensource/os-pythonpackaging/) or [Creating a Source Distribution](https://docs.python.org/release/3.1.5/distutils/sourcedist.html#manifest).

### ReadTheDocs

Using ReadTheDocs record.

### Version Named

`Major_Version_Number.Minor_Version_Number[.Revision_Number[.Build_Number]]`

- `Major`: Under the same name, but program with different Major Version Number are not interchangeable.
- `Minor`: Backward compatibility
- `Build`: Recompilation of the same source
- `Revision`: repair bug

### Reference Link

- [Sample Module Repository](https://github.com/kennethreitz/samplemod)
- [结构化您的工程](https://pythonguidecn.readthedocs.io/zh/latest/writing/structure.html)
- [python空项目](https://github.com/onlytiancai/pyempty)
- [如何编写高质量的python程序](https://github.com/onlytiancai/codesnip/blob/master/mypost/How_to_write_high-quality_python_program.md#%E5%A6%82%E4%BD%95%E7%BC%96%E5%86%99%E9%AB%98%E8%B4%A8%E9%87%8F%E7%9A%84python%E7%A8%8B%E5%BA%8F)
- [Web.py](https://github.com/webpy/webpy)
- [Python单元测试框架](http://pyunit.sourceforge.net/pyunit_cn.html)

### CopyRight

You can look, fork or reprint, but the copyright belongs to individual, reprint please indicate the source.`daidai21@github`
