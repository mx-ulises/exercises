#!/bin/python

from heapq import heappush, heappop

n, m, k = map(int, raw_input().split())
total_cells = n * m

rows = {}

for _ in xrange(k):
    r, c_1, c_2 = map(int, raw_input().split())
    if r not in rows:
        rows[r] = []
    heappush(rows[r], (c_1, c_2))

for r in rows:
    c_1, c_2 = heappop(rows[r])
    while rows[r]:
        d_1, d_2 = heappop(rows[r])
        if d_1 <= c_2 and c_2 <= d_2:
            c_2 = d_2
        elif c_2 < d_1:
            total_cells -= c_2 - c_1 + 1
            c_1, c_2 = d_1, d_2
    total_cells -= c_2 - c_1 + 1

print total_cells
