#!/bin/python

A = [[] for _ in xrange(100)]

t = int(raw_input())

for _ in xrange(t):
    i, word = raw_input().split()
    A[int(i)].append(word)

count = 0
B = []
for i in xrange(100):
    count += len(A[i])
    B.append(str(count))

print " ".join(B)
