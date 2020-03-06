#!/usr/bin/env python3
# -*- coding:utf-8 -*-


# =============================================================================
# File Name: binary_search_tree.py
# Author: DaiDai
# Mail: daidai4269@aliyun.com
# Created Time: Wed 08 Jan 2020 06:24:07 PM CST
# =============================================================================


# TODO: not test
# The premise is that all keys are unique


from binary_tree_node import BinaryTreeNode


def search(root, key, res=None):
    if root.val == key:
        return root
    elif root.val > key:
        return search(root.left, key, res)
    else:
        return search(root.right, key, res)
    return res


def insert(root, val):
    if val > root.val:
        if root.right is None:
            root.right = BinaryTreeNode(val)
        else:
            insert(root.right, val)
    else:
        if root.left is None:
            root.left = BinaryTreeNode(val)
        else:
            insert(root.left, val)


def delete(root, key) -> BinaryTreeNode:
    # TODO
    # Case 1: empty tree
    # Case 2: deleting root node
    # Case 3: node not find
    # Case 4: node has no children
    # Case 5: node has left child only
    # Case 6: node has right child only
    # Case 7: node has left and right child
    pass


def print_tree(root):
    vals = []  # for print all val on one line
    que = [root]  # BFS
    while que:
        next_layer = []
        for node in que:
            print(node.val)
            
            vals.append(node.val)

            if node.left:
                next_layer.append(node.left)
            if node.right:
                next_layer.append(node.right)
        que = next_layer
    print("All vals: ", sorted(vals))


if __name__ == "__main__":
    pass

