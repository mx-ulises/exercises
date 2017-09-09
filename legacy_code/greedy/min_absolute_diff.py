#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())

A.sort()
minimal = abs(A[0] - A[1])

for i in xrange(1, n - 1):
    candidate = abs(A[i] - A[i + 1])
    minimal = min(minimal, candidate)

print minimal
