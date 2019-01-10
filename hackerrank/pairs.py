#!/bin/python

_, k = map(int, raw_input().split())
A = set(map(int, raw_input().split()))

count = 0
for a in A:
    if (a - k) in A:
        count += 1

print count
