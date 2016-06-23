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


    def palindrome(self, list_q):
        list_q.append(self.value)
        tail_result = True
        if self.next:
            tail_result = self.next.palindrome(list_q)
        value = list_q.pop(0)
        node_result = True
        if value != self.value:
            node_result = False
        return node_result and tail_result


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
