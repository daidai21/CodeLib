#!/usr/bin/env python3
# -*- coding:utf-8 -*-



def inorder_recursion(node):
    if not node:
        return 

    inorder_recursion(node.left)

    # opt val
    print(node.val)

    inorder_recursion(node.right)


def inorder_iteration(node):
    if not node:
        return 
    stack = []
    result = []
    while node or stack:
        while node:
            stack.append(node)
            node = node.left
        node = stack.pop()
        result.append(node.val)
        node = node.right
    return result
