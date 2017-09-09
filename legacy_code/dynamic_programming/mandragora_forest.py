#!/bin/python

t = int(raw_input())

for _ in xrange(t):
    n = int(raw_input())
    A = map(int, raw_input().split())
    A.sort()
    B = [0] * (n + 1)
    for i in xrange(n):
        B[i + 1] = B[i] + A[i]
    C = [(i + 1) * (B[-1] - B[i]) for i in xrange(n + 1)]
    print max(C)
