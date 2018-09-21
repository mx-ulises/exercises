#!/bin/python

q = int(raw_input())

for _ in xrange(q):
    s_1 = set(list(raw_input()))
    s_2 = set(list(raw_input()))
    s_3 = s_1 & s_2
    if 0 < len(s_3):
        print "YES"
    else:
        print "NO"
