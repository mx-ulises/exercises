#!/bin/python

n = int(raw_input())
p = map(int, raw_input().split())
q = {p[i]: (i + 1) for i in xrange(n)}

for i in xrange(1, n + 1):
    print q[q[i]]
