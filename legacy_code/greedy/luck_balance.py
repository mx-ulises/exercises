#!/bin/python

from heapq import heappush, heappop

n, k = map(int, raw_input().split())
h = []

luck_counter = 0

for _ in xrange(n):
    l, t = map(int, raw_input().split())
    if not t:
        luck_counter += l
    else:
        heappush(h, -l)

while h:
    l = -heappop(h)
    if k:
        k -= 1
        luck_counter += l
    else:
        luck_counter -= l

print luck_counter
