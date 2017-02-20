#!/bin/python

def get_h(n):
    h = 1
    for i in xrange(n):
        if i % 2 == 0:
            h *= 2
        else:
            h += 1
    return h

t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    print get_h(n)
