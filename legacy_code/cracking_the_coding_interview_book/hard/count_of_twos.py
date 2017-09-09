#!/bin/python

from math import log

def digit(n, p):
    return (n / (10 ** p)) % 10

def get_digit_two(n):
    total = 0
    p = int(log(n, 10))
    while 0 <= p:
        fixed = n / (10 ** p) / 10
        d = digit(n, p)
        additional = 0
        if d == 2:
            additional = (n % (10 ** p)) + 1
        if 2 < d:
            additional = (10 ** p)
        total += (fixed * (10 ** p) + additional)
        p -= 1
    return total

def test(n):
    print "2 in '{0}' is '{1}'".format(n, get_digit_two(n))

test(200)
test(201)
test(202)
test(203)
test(204)
test(205)
test(206)
test(207)
test(208)
test(209)
test(210)
test(211)
test(212)
