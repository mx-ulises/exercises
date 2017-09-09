#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())
A.sort()

diffs = {}

for i in xrange(n - 1):
    a, b = A[i], A[i + 1]
    diff = b - a
    if (diff) not in diffs:
        diffs[diff] = []
    diffs[diff].append(str(a))
    diffs[diff].append(str(b))

min_diff = min(diffs.keys())
print " ".join(diffs[min_diff])
