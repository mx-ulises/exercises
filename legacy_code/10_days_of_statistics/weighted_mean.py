#!/bin/python

def weighted_mean(A, W, n):
    total = 0
    weight = 0
    for i in xrange(n):
        total += (A[i] * W[i])
        weight += W[i]
    return (total / weight)

n = int(raw_input())
A = map(float, raw_input().split())
W = map(float, raw_input().split())

print "{0:0.1f}".format(weighted_mean(A, W, n))
