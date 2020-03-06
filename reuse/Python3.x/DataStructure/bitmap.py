#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: bitmap.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Sat 11 Jan 2020 00:07:52 AM CST
# =============================================================================


# TODO: not test


from typing import Optional


class Bitmap(object):
    def __init__(self, bits_num: int) -> None:
        self._bits_num = bits_num
        self._bytes = bytearray(bits_num // 8 + 1)

    def setbit_true(self, idx: int) -> None:
        if idx > self._bits_num or idx < 1:
            return 
        self._bytes[idx // 8] |= (1 << idx % 8)

    def setbit_false(self, idx: int) -> None:
        if idx > self._bits_num or idx < 1:
            return 
        self._bytes[idx // 8] ^= (1 << idx % 8)

    def getbit(self, idx: int) -> Optional[bool]:
        if idx > self._bits_num or idx < 1:
            return 
        return self._bytes[idx // 8] & (1 << idx % 8) != 0


if __name__ == "__main__":
    bitmap = Bitmap(10)
    bitmap.setbit_true(1)
    bitmap.setbit_true(6)
    bitmap.setbit_true(10)
    bitmap.setbit_false(10)

    for idx in range(1, 11):
        print(bitmap.getbit(idx))
    print(len(bitmap._bytes))
