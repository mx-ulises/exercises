#!/bin/python

n, k = map(int, raw_input().split())
A = map(int, raw_input().split())

counter = 0
for i in xrange(n):
    for j in xrange(i + 1, n):
        if (A[i] + A[j]) % k == 0:
            counter += 1

print counter
