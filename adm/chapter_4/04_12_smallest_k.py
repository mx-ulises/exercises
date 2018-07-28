#!/bin/python

from heapq import heappush, heappop


def smallest_k(l, k):
    h = []
    for i in xrange(k):
        heappush(h, -l[i])
    for i in xrange(k, len(l)):
        if l[i] < -h[0]:
            heappop(h)
            heappush(h, -l[i])
    h = [-i for i in h]
    h.sort()
    return h


def test(l, k):
    print l
    print smallest_k(l, k)
    print "========================================="


test([2, 4, 1, 2, 7, 2, 4, 8, 10, 2], 5)
test([2, 1, 1, 2, 7, 2, 4, 8, 10, 2], 3)
