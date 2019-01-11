#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())

B = {}
for a in A:
    if a not in B:
        B[a] = 0
    B[a] += 1

maximal = B[A[0]]
for b in B:
    maximal = max(maximal, B[b])

print n - maximal
