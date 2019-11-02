#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: stack_with_array.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Mon 28 Oct 2019 10:39:53 PM CST
# =============================================================================


class Stack(object):
    def __init__(self):
        self.values = []

    def __len__(self):
        return len(self.values)

    def __str__(self):
        return str(self.values)

    def push(self, value):
        self.values.append(value)

    def pop(self):
        return self.values.pop(0)


if __name__ == '__main__':
    stack = Stack()
    print(len(stack))
    print(stack)

    stack.push(1)
    print(len(stack))
    print(stack)

    stack.push(2)
    print(len(stack))
    print(stack)

    stack.push(3)
    print(len(stack))
    print(stack)

    stack.pop()
    print(len(stack))
    print(stack)

    stack.pop()
    print(len(stack))
    print(stack)
