#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# #############################################################################
# File Name   : example.py
# Author      : DaiDai
# Mail        : daidai4269@aliyun.com
# Created Time: 四  4/ 1 15:14:27 2021
# #############################################################################

import ast

if __name__ == '__main__':
    # define
    func_def = \
"""
def add(x, y):
    return x + y

print(add(3, 5))
"""

    # 编译并执行
    cm = compile(func_def, '<string>', 'exec')
    exec(cm)

    # 生成ast
    r_node = ast.parse(func_def)
    print(ast.dump(r_node))
