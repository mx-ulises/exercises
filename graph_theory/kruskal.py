#!/bin/python

from heapq import heappush, heappop

class DisjointSet(object):
    def __init__(self, n):
        self.parent = [x for x in range(n)]
        self.rank = [0 for x in range(n)]

    def find(self, x):
        if(self.parent[x]!=x):
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        if(x_root == y_root):
            return
        if self.rank[x_root] < self.rank[y_root]:
            self.parent[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.parent[y_root] = x_root
        else:
            self.parent[y_root] = x_root
            self.rank[x_root]+=1

n, m = map(int, raw_input().split())
tree = DisjointSet(n + 1)
h = []
w = 0

for _ in xrange(m):
    x, y, r = map(int, raw_input().split())
    edge = (x, y)
    heappush(h, (r, edge))

while h:
    r, edge = heappop(h)
    x, y = edge
    if tree.find(x) != tree.find(y):
        w += r
        tree.union(x, y)

print w
