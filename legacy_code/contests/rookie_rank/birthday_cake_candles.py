#!/bin/python

_ = raw_input()
A = map(int, raw_input().split())

B = {}
for a in A:
    if a not in B:
        B[a] = 0
    B[a] += 1

print B[max(B.keys())]
