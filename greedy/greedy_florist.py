#!/bin/python

N, K = map(int, raw_input().split())
F = map(int, raw_input().split())
F.sort()
F.reverse()

total = 0
for i in xrange(N):
    x = i / K
    total += ((x + 1) * F[i])

print total
