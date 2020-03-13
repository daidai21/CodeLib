#!/usr/bin/env python3
# -*- coding:utf-8 -*-

class ListNode(object):
    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList(object):
    # idx in 0 ~ n
    def __init__(self):
        self.head = None

    def add(self, val, idx):
        pass

    def remove(self, val, idx, multi=False):
        pass

    def update(self, idx, val):
        pass

    def search(self, idx):
        pass

    def reverse(self):
        pass

    # for test or display
    def display(self):
        pass

    def to_list(self):
        pass

    def from_list(self, lst):
        pass






# one_direction_linked_list
class Node(object):
    def __init__(self, data):
        self.data = data
        self.pointer = None


class LinkedList(object):
    def __init__(self):
        self._head = None
        self._length = 0

    def __len__(self):
        return self._length

    def __str__(self):
        ans = "["
        node = self._head
        while node is not None:
            ans += str(node.data) + ", "
            node = node.pointer
        return ans.rstrip(", ") + "]"

    def is_empty(self):
        return self._length == 0

    def length(self):
        tmp = self._head
        result = 0
        while tmp is not None:
            result += 1
            tmp = tmp.pointer
        return result

    def add(self, data):  # add data to head
        tmp = self._head
        self._head = Node(data)
        self._head.pointer = tmp
        self._length += 1

    def append(self, data):
        tmp = self._head
        while tmp and tmp.pointer:
            tmp = tmp.pointer
        tmp.pointer = Node(data)
        self._length += 1

    def insert(self, index, data):
        assert index >= 0
        if index == 0:
            self.add(data)
        else:
            tmp = self._head
            i = 1
            while tmp and tmp.pointer and i < index:
                tmp = tmp.pointer
                i += 1
            tmp_next = tmp.pointer
            tmp.pointer = Node(data)
            tmp.pointer.pointer = tmp_next
            self._length += 1

    def remove(self, index):
        assert len(self) > index >= 0
        if index == 0:
            ans = self._head.data
            self._head = self._head.pointer
            self._length -= 1
            return ans
        else:
            tmp = self._head
            i = 1
            while tmp and i < index:
                i += 1
                tmp = tmp.pointer
            tmp.pointer = tmp.pointer.pointer
            self._length -= 1
            return tmp.data

    def search(self, data):
        tmp = self._head
        i = 0
        while tmp and tmp.pointer and tmp.data != data:
            tmp = tmp.pointer
            i += 1
        return i if tmp.data == data else -1

    def clear(self):
        self._head = None
        self._length = 0


if __name__ == '__main__':
    l = LinkedList()
    print(l.is_empty(), len(l), l.length(), str(l))

    l.add(2)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.add(1)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.append(3)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.append(4)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.insert(0, 0)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.insert(1, 1.5)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.insert(2, 2.5)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.insert(7, 9.5)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.remove(0)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.remove(4)
    print(l.is_empty(), len(l), l.length(), str(l))

    l.remove(2)
    print(l.is_empty(), len(l), l.length(), str(l))

    print(l.search(2))
    print(l.is_empty(), len(l), l.length(), str(l))

    print(l.search(9.5))
    print(l.is_empty(), len(l), l.length(), str(l))

    print(l.search(1.5))
    print(l.is_empty(), len(l), l.length(), str(l))

    print(l.search(100))
    print(l.is_empty(), len(l), l.length(), str(l))

    l.clear()
    print(l.is_empty(), len(l), l.length(), str(l))
