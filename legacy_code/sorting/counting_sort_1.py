#!/bin/python

_ = raw_input()
A = map(int, raw_input().split())
B = [0] * 100

for a in A:
    B[a] += 1

print " ".join(map(str, B))
