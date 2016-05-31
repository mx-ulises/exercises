#!/bin/python
from dj_set import DisjointSet

n = int(raw_input())

set_forest = DisjointSet(n * 2)
for _ in xrange(n):
    g, b = map(int, raw_input().split())
    set_forest.Union(g - 1, b - 1)

map_count = [0] * (n * 2)
for i in xrange(n * 2):
    parent = set_forest.Buscar(i)
    map_count[parent] += 1

max_num = 0;
min_num = 15000 * 2
for i in map_count:
    max_num = max(max_num, i)
    if i > 1:
        min_num = min(min_num, i)

print "{0} {1}".format(min_num, max_num)
