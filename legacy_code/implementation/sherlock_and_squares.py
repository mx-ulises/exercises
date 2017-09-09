#!/bin/python
from math import sqrt

for _ in xrange(int(raw_input())):
    a, b = map(int, raw_input().split())
    i = int(sqrt(a))
    s = i * i
    c = 0
    while s <= b:
        if a <= s <= b:
            c += 1
        i += 1
        s = i * i
    print c
