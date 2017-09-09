#!/bin/python
from dj_set import DisjointSet
from math import factorial

def nCr(n, r):
    if r > n:
        return 0
    return (factorial(n)) / (factorial(r) * factorial(n - r))

n = int(raw_input())
nodes_set = DisjointSet(n)

for _ in xrange(n - 1):
    x, y, c = raw_input().split()
    x, y = int(x) - 1, int(y) - 1
    if c == "b":
        nodes_set.union(x, y)

node_count = {}
for x in xrange(n):
    x_parent = nodes_set.find(x)
    if x_parent not in node_count:
        node_count[x_parent] = 0
    node_count[x_parent] += 1

total = nCr(n, 3)
for x in node_count:
    x_n = node_count[x]
    if x_n > 1:
        total -= (nCr(x_n, 2) * (n - x_n))
        total -= nCr(x_n, 3)

print total % (pow(10, 9) + 7)
