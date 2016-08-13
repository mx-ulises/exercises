#!/bin/python

t = int(raw_input())
for _ in xrange(t):
    n, m, s = map(int, raw_input().split())
    x = ((m % n) + s - 1) % n
    if not x:
        x = n
    print x
