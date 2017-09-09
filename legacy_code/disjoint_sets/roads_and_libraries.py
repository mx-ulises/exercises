#!/bin/python

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
            self.rank[x_root] += 1

q = int(raw_input())

for _ in xrange(q):
    n, m, c_lib, c_road = map(int, raw_input().split())
    my_set = DisjointSet(n)
    for _ in xrange(m):
        x, y = map(int, raw_input().split())
        my_set.union(x - 1, y - 1)
    components = {}
    for x in xrange(n):
        c = my_set.find(x)
        if c not in components:
            components[c] = 0
        components[c] += 1
    total_cost = 0
    for c in components:
        roads_cost = c_road * (components[c] - 1) + c_lib
        lib_cost = c_lib * components[c]
        total_cost += min(roads_cost, lib_cost)
    print total_cost
