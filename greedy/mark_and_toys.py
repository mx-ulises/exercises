#!/bin/python

n, k = map(int, raw_input().split())
A = map(int, raw_input().split())
A.sort()

count = 0
for a in A:
    if a < k:
        k = k - a
        count += 1
    else:
        break

print count
