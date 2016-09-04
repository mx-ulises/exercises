#!/bin/python

from sets import Set

def get_nearest(A, k):
    exist = Set([0])
    for i in xrange(1, k + 1):
        for a in A:
            y = i - a
            if y in exist:
                exist.add(i)
                break
    return max(exist)

t = int(raw_input())

for _ in xrange(t):
    _, k = map(int, raw_input().split())
    A = Set(map(int, raw_input().split()))
    print get_nearest(A, k)
