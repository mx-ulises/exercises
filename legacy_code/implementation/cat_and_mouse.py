#!/bin/python

q = int(raw_input())

for _ in xrange(q):
    x, y, z = map(int, raw_input().split())
    a = abs(z - x)
    b = abs(z - y)
    if a < b:
        print "Cat A"
    elif b < a:
        print "Cat B"
    else:
        print "Mouse C"
