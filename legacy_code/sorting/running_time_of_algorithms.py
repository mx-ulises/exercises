#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())

shift_count = 0

for i in xrange(1, n):
    j = i
    while 0 < j and A[j] < A[j - 1]:
        A[j], A[j - 1] = A[j - 1], A[j]
        j -= 1
        shift_count += 1

print shift_count
