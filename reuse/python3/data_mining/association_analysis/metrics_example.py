#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# #############################################################################
# File Name   : metrics_example.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四  9/17 16:31:22 2020
# #############################################################################


import pandas as pd

from metrics import support
from metrics import confidence
from metrics import lift

# https://github.com/geeklili/Association_Analysis


if __name__ == '__main__':
    example_df = pd.read_csv("./input.csv")
    print(example_df)

    print("support:")
    print("A, B: ", support(example_df, "A", "B"))
    print("B, C: ", support(example_df, "B", "C"))

    print("confidence:")
    print("A, B: ", confidence(example_df, "A", "B"))
    print("B, A: ", confidence(example_df, "B", "A"))
    print("D, A: ", confidence(example_df, "D", "A"))
    print("D, E: ", confidence(example_df, "D", "E"))

    print("lift:")
    print("A, B: ", lift(example_df, "A", "B"))
    print("B, A: ", lift(example_df, "B", "A"))
    print("D, A: ", lift(example_df, "D", "A"))
    print("D, E: ", lift(example_df, "D", "E"))
    print("E, D: ", lift(example_df, "E", "D"))
    print("D, C: ", lift(example_df, "D", "C"))
    print("C, D: ", lift(example_df, "C", "D"))
