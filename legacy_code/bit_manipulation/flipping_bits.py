#!/bin/python

t = int(raw_input())
sum_val = 2**32

for _ in xrange(t):
    print (~int(raw_input()) + sum_val)
