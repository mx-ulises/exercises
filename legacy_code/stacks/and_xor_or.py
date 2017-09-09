#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())

s = [A[0]]
max_val = 0

for i in xrange(1, n):
    while s and A[i] <= s[-1]:
        max_val = max(max_val, A[i] ^ s.pop())
    if s:
        max_val = max(max_val, s[-1] ^ A[i])
    s.append(A[i])

print max_val
