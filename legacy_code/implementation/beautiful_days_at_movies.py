#!/bin/python

i, j, k = map(int, raw_input().split())

count = 0

for x in xrange(i, j + 1):
    y = str(x)
    y = int(y[::-1])
    if abs(x - y) % k == 0:
        count += 1

print count
