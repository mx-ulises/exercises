#!/bin/python
n, m = map(int, raw_input().split())
C = map(int, raw_input().split())

ways = [1] + [0] * n
for c in C:
    for i in xrange(n):
        if c + i <= n:
            ways[i + c] += ways[i]

print ways[n]
