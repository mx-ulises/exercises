#!/bin/python

n, m = map(int, raw_input().split())
c = map(int, raw_input().split())
c.sort()

d = max(c[0], n - 1 - c[-1])
for i in range(m - 1):
    a, b = c[i], c[i + 1]
    d = max(d, (b - a)/ 2)

print d
