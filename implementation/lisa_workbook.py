#!/bin/python

n, k = map(int, raw_input().split())
T = map(int, raw_input().split())

counter = 0
i = 0
for t in T:
    x = 0
    for j in xrange(t):
        if x == k:
            x = 0
            i += 1
        if j == i:
            counter += 1
        x += 1
    i += 1
print counter
