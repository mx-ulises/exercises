#!/bin/python

def f(n):
    total = 1
    zeros = 0
    for i in xrange(1, n + 1):
        total *= i
        while not (total % 10):
            total /= 10
            zeros += 1
    return zeros

for i in xrange(1, 35 + 1):
    print "{0}:    {1}".format(i, f(i))
