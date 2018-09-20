#!/bin/python

def min_abs_delta(A, n):
    A.sort()
    minimal = abs(A[0] - A[1])
    for i in xrange(1, n - 1):
        minimal = min(minimal, abs(A[i] - A[i + 1]))
    return minimal

n = int(raw_input())
A = map(int, raw_input().split())
print min_abs_delta(A, n)
