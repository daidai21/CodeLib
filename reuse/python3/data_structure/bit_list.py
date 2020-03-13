#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# TODO: not test


from typing import Optional


class BitList(object):
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
    bit_list = BitList(10)
    bit_list.setbit_true(1)
    bit_list.setbit_true(6)
    bit_list.setbit_true(10)
    bit_list.setbit_false(10)

    for idx in range(1, 11):
        print(bit_list.getbit(idx))
    print(len(bit_list._bytes))
