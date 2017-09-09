#!/bin/python

_ = int(raw_input())
A = map(int, raw_input().split())
bird_count = [0] * 6

for a in A:
    bird_count[a] += 1

a = 0
for b in xrange(6):
    if bird_count[a] < bird_count[b]:
        a = b

print a
