#!/bin/python

class Node:
    def __init__(self):
        self.parent = self
        self.size = 1

    def get_parent(self):
        if self == self.parent:
            return self
        self.parent = self.parent.get_parent()
        return self.parent

    def merge(self, node):
        parent_1 = self.get_parent()
        parent_2 = node.get_parent()
        if parent_1 == parent_2:
            return parent_1
        if parent_1.size < parent_2.size:
            parent_1.parent = parent_2
            parent_2.size += parent_1.size
            return parent_2
        else:
            parent_2.parent = parent_1
            parent_1.size += parent_2.size
            return parent_1

nodes = {}
n = int(raw_input())
maximal = 1

for _ in xrange(n):
    x, y = map(int, raw_input().split())
    if x not in nodes:
        nodes[x] = Node()
    if y not in nodes:
        nodes[y] = Node()
    maximal = max(maximal, nodes[x].merge(nodes[y]).size)
    print maximal
