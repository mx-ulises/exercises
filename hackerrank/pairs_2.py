#!/bin/python

n, k = map(int, raw_input().split())
A = map(int, raw_input().split())
A = set(A)

count = 0

for a in A:
    if (a - k) in A:
        count += 1

print count
