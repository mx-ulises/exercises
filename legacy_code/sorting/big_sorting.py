#!/bin/python

from heapq import heappush, heappop

n = int(raw_input())
m = {}

for _ in xrange(n):
    x = raw_input()
    l = len(x)
    if l not in m:
        m[l] = []
    heappush(m[l], x)

keys = m.keys()
keys.sort()
for l in keys:
    while m[l]:
        print heappop(m[l])
