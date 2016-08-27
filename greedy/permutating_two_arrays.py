#!/bin/python

t = int(raw_input())

RESULT = {True: "YES", False: "NO"}

for _ in xrange(t):
    n, k = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())
    A.sort()
    B.sort()
    B.reverse()
    C = [(A[i] + B[i]) >= k for i in xrange(n)]
    print RESULT[all(C)]
