#!/usr/bin/env python3


class Number:
    def __init__(self, val):
        self.val = val

    def add(self, val):
        self.val += val
        return self

    def subtract(self, val):
        self.val -= val
        return self

    def multiply(self, val):
        self.val *= val
        return self

    def divide(self, val):
        self.val /= val
        return self

    def printf(self):
        print(self.val)


if __name__ == "__main__":
    num = Number(1)
    num.add(100) \
       .subtract(10) \
       .multiply(2) \
       .divide(91) \
       .printf()

