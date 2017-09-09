#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())

i = n / 2
for j in xrange(i):
    if (j % 2) == 0:
        A[j], A[n - j - 1] = A[n - j - 1], A[j]

A = map(str, A)
print " ".join(A)
