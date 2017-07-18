#!/bin/python

v = int(raw_input())
n = int(raw_input())
A = map(int, raw_input().split())

for i in xrange(n):
    if v == A[i]:
        print i
        break
