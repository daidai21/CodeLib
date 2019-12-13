#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: .py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Fri Dec 13 14:21:17 2019
# ========================binary_tree_postorder_traversal=====================================================


def postorder_recursion(node):
    if not node:
        return 

    postorder_recursion(node.left)
    postorder_recursion(node.right)

    # opt val
    print(node.val)


def postorder_iteration(node):
    if not node:
        return
    stack = [node]
    result = []
    while stack:
        node = stack.pop()
        if node.left:
            stack.append(node.left)
        if node.right:
            stack.append(node.right)
        result.append(node)
    while result:
        # opt val
        print(result.pop().val)
