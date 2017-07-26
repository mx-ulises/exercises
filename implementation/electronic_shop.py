#!/bin/python

s, n, m = map(int, raw_input().split())
A = map(int, raw_input().split())
B = map(int, raw_input().split())

A.sort()
A.reverse()
B.sort()

i = 0
j = 0

total = -1

while i < n and j < m:
    t = A[i] + B[j]
    while t <= s:
        total = max(total, t)
        j += 1
        if j == m:
            break
        t = A[i] + B[j]
    i += 1

print total
