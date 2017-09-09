#!/bin/python

from dj_set_modified import DisjointSet

n, q = map(int, raw_input().split())
set_forest = DisjointSet(n)

for _ in xrange(q):
    query = raw_input().split()
    if query[0] == "Q":
        print set_forest.set_size(int(query[1]) - 1)
    if query[0] == "M":
        set_forest.union(int(query[1]) - 1, int(query[2]) - 1)
