#!/bin/python
import random

"""
Linked List implementation and functions that helps to test the code:
"""

RANDOM_LIMIT = 100
N = 10

class LinkedList:

    def __init__(self, value):
        self.value = value
        self.next = None
        self.visited = False


    def add(self, value):
        node = self
        while node.next:
            node = node.next
        node.next = LinkedList(value)


def visit_list(root):
    node = root
    while node and not node.visited:
        node.visited = True
        node = node.next


def clear_list(root):
    node = root
    while node and node.visited:
        node.visited = False
        node = node.next


def create_list(n):
    value = random.randint(0, RANDOM_LIMIT)
    root = LinkedList(value)
    node = root
    for _ in xrange(n - 1):
        value = random.randint(0, RANDOM_LIMIT)
        node.next = LinkedList(value)
        node = node.next
    return root


def create_list_2(l):
    root = None
    if l:
        root = LinkedList(l[0])
        node = root
        for i in xrange(1, len(l)):
            node.next = LinkedList(l[i])
            node = node.next
    return root


def print_list(root):
    node = root
    str_out = ""
    while node:
        str_out += "{0} ".format(node.value)
        node = node.next
    return str_out


def get_random_middle(root, n):
    if n <= 2:
        return None
    m = random.randint(0, n - 3)
    node = root.next
    for _ in xrange(m):
        node = node.next
    return node


def get_last(root):
    if not root:
        return root
    node = root
    while node.next:
        node = node.next
    return node


def print_separator():
    print "==================================================================="
