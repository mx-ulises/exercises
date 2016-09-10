#!/bin/python

from sets import Set

t = int(raw_input())

for _ in xrange(t):
    a, b = Set(list(raw_input())), Set(list(raw_input()))
    if len(a & b) == 0:
        print "NO"
    else:
        print "YES"
