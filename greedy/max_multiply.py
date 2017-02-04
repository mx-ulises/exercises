#!/bin/python

def get_3_2_factors(n):
    x = n / 3
    y = 0
    if n % 3 == 1:
        x -= 1
        y = 2
    if n % 3 == 2:
        y = 1
    return ([3] * x) + ([2] * y)

def get_factors(n):
    if n <= 1:
        return None
    if n == 2:
        return [1, 1]
    if n == 3:
        return [2, 1]
    return get_3_2_factors(n)

for i in xrange(2, 16):
    a = get_factors(i)
    print "{0}: {1} -> {2}".format(i, a, reduce(lambda x, y: x*y, a))
