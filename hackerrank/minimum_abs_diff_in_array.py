#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())
A.sort()

minimal = A[1] - A[0]
for i in xrange(2, n):
    minimal = min(minimal, A[i] - A[i - 1])

print minimal
