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

    
    def add(self, value):
        node = self
        while node.next:
            node = node.next
        node.next = LinkedList(value)


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

def print_separator():
    print "==================================================================="
