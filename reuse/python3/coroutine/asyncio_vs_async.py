#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# #############################################################################
# File Name   : asyncio_vs_async.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 三  3/31 17:29:56 2021
# #############################################################################


import warnings
warnings.filterwarnings("ignore", category=DeprecationWarning)
warnings.filterwarnings("ignore", category=RuntimeWarning)

import asyncio


@asyncio.coroutine
def decorated(x):
    yield from x


async def native(x):
    await x


if __name__ == '__main__':
    print(list(decorated('foo')))

    try:
        print(list(native('foo')))
    except Exception as err:
        print(err)
