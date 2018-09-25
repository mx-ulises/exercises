#!/bin/python

n = int(raw_input())

s = 5
l = s / 2
c = l

for _ in xrange(1, n):
    s = l * 3
    l = s / 2
    c += l

print c
