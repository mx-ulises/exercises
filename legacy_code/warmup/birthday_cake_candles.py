#!/bin/python

n = int(raw_input())
H = map(int, raw_input().split())

count = 0
max_h = 0

for i in xrange(n):
    h = H[i]
    if max_h < h:
        max_h = h
        count = 0
    if max_h == h:
        count += 1

print count
