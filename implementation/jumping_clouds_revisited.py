#!/bin/python

n, k = map(int, raw_input().split())
C = map(int, raw_input().split())

D = [C[i * k] * 2 for i in xrange(n / k)]
result = 100 - (sum(D) + (n / k))
print result
