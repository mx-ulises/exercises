#!/bin/python

_, d = map(int, raw_input().split())
A = raw_input().split()
print " ".join(A[d:] + A[:d])
