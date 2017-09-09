#!/bin/python

mask = [1] + [0] * 31
for i in xrange(1, 32):
    mask[i] = mask[i - 1] << 1
mask.reverse()

n = int(raw_input())
for _ in xrange(n):
    a, b = map(int, raw_input().split())
    value = 0
    for m in mask:
        if (a & m) == (b & m):
            value |= (a & m)
        else:
            break
    print value
