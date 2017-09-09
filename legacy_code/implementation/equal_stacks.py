#!/bin/python

from sets import Set

raw_input()
Sets = [Set([0]) for _ in xrange(3)]
for i in xrange(3):
    A = map(int, raw_input().split())
    h = 0
    for j in xrange(len(A)):
        h += A[len(A) - j - 1]
        Sets[i].add(h)

print max(Sets[0] & Sets[1] & Sets[2])
