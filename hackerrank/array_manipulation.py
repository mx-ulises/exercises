#!/bin/python

n, m = map(int, raw_input().split())
aq = {}

for _ in xrange(m):
    a, b, k = map(int, raw_input().split())
    b = b + 1
    if a not in aq:
        aq[a] = 0
    if b not in aq:
        aq[b] = 0
    aq[a] += k
    aq[b] -= k

indexes = aq.keys()
indexes.sort()

maximal = 0
curr = 0

for i in indexes:
    curr += aq[i]
    maximal = max(maximal, curr)

print maximal
