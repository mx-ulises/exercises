#!/bin/python

class Tree_count:
    def __init__(self):
        self.adj = []
        self.sub_tree_count = 0

    def child_count(self):
        if self.sub_tree_count:
            return 0
        self.sub_tree_count = 1
        for node in self.adj:
            self.sub_tree_count += node.child_count()
        return self.sub_tree_count

n, m = map(int, raw_input().split())
tree = [Tree_count() for _ in xrange(n)]

for _ in xrange(m):
    u, v = map(int, raw_input().split())
    tree[u - 1].adj.append(tree[v - 1])
    tree[v - 1].adj.append(tree[u - 1])

tree[0].child_count()
edge_count = 0
for node in tree:
    if not node.sub_tree_count % 2:
        edge_count += 1

print (edge_count - 1)
