#!/bin/python

n = int(raw_input())
A = {}

for i in xrange(n):
    x, word = raw_input().split()
    x = int(x)
    if x not in A:
        A[x] = []
    if i < n / 2:
        word = "-"
    A[x].append(word)

keys = A.keys()
keys.sort()

B = []
for x in keys:
    for word in A[x]:
        B.append(word)

print " ".join(B)
