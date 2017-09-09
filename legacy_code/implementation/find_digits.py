#!/bin/python

T = int(raw_input())

for _ in xrange(T):
    count = 0
    s = raw_input()
    n = int(s)
    for c in s:
        c = int(c)
        if c > 0 and n % c == 0:
            count += 1
    print count
