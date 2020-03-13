#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# stack with list
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
