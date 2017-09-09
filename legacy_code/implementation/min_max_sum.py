#!/bin/python

A = map(int, raw_input().split())
A.sort()

min_sum = sum(A[:4])
max_sum = sum(A[1:])

print "{0} {1}".format(min_sum, max_sum)
