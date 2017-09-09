#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.L = None
        self.R = None
        self.depth = -1
        self.traversal_str = ""

    def set_childs(self, left, right):
        self.L = left
        self.R = right

    def set_depth(self, depth):
        self.depth = depth

    def swap(self, k):
        if not self.depth % k:
            self.L, self.R = self.R, self.L

    def in_order(self):
        self.traversal_str = ""
        if self.L:
            self.traversal_str += self.L.traversal_str
        self.traversal_str += "{0} ".format(self.value)
        if self.R:
            self.traversal_str += self.R.traversal_str
        return self.traversal_str

def build_tree(n):
    nodes = [Node(i + 1) for i in xrange(n)]
    nodes[0].set_depth(1)
    for i in xrange(n):
        parent = nodes[i]
        left, right = map(int, raw_input().split())
        if left == -1:
            left = None
        else:
            left = nodes[left - 1]
            left.set_depth(parent.depth + 1)
        if right == -1:
            right = None
        else:
            right = nodes[right - 1]
            right.set_depth(parent.depth + 1)
        parent.set_childs(left, right)
    return nodes

n = int(raw_input())
nodes = build_tree(n)
t = int(raw_input())

for _ in xrange(t):
    k = int(raw_input())
    for node in nodes:
        node.swap(k)
    for i in xrange(n):
        node = nodes[n - 1 - i]
        node.in_order()
    print nodes[0].in_order()
