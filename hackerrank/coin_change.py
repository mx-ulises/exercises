#!/bin/python

n, m = map(int, raw_input().split())
C = map(int, raw_input().split())

count = [0 for _ in xrange(n + 1)]
count[0] = 1

for c in C:
    for i in xrange(n):
        if (i + c) <= n: 
            count[i + c] += count[i]

print count[n]
