#!/bin/python

A = map(int, raw_input().split())
B = map(int, raw_input().split())

a_points = 0
b_points = 0

for i in xrange(3):
    if A[i] > B[i]:
        a_points += 1
    if A[i] < B[i]:
        b_points += 1

print "{0} {1}".format(a_points, b_points)
