#!/bin/python

from math import log

n = int(raw_input())
a = int(log((n - 1) / 3 + 1, 2))
x = 3 * (2 ** a)
t = x - 2
print (x - n + t)
