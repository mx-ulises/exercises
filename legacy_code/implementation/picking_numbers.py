#!/bin/python

_ = raw_input()
A = map(int, raw_input().split())

count = [0] * 101
for a in A:
    count[a] += 1

maximal = count[0]

for i in xrange(1, 101):
    maximal = max(maximal, count[i] + count[i - 1])

print maximal
