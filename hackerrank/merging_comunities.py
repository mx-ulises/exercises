#!/bin/python

class Node:
    def __init__(self, n):
        self.n = n
        self.parent = self
        self.size = 1

    def get_parent(self):
        if self.parent == self:
            return self
        parent = self.parent.get_parent()
        self.parent = parent
        return parent

    def merge(self, node):
        parent_1 = self.get_parent()
        parent_2 = node.get_parent()
        if parent_1 == parent_2:
            return
        elif parent_1.size < parent_2.size:
            parent_1.parent = parent_2
            parent_2.size += parent_1.size
        else:
            parent_2.parent = parent_1
            parent_1.size += parent_2.size

n, q = map(int, raw_input().split())
nodes = [Node(i) for i in xrange(n + 1)]

for _ in xrange(q):
    query = raw_input().split()
    if query[0] == "Q":
        node_index = int(query[1])
        comunity_parent = nodes[node_index].get_parent()
        print comunity_parent.size
    if query[0] == "M":
        node_index_1 = int(query[1])
        node_index_2 = int(query[2])
        nodes[node_index_1].merge(nodes[node_index_2])
