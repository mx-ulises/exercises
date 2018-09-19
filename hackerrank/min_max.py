#!/bin/python

def unfairness(A, k):
    A.sort()
    minimal_unfarness = A[k - 1] - A[0]
    for i in xrange(len(A) - k + 1):
        minimal_unfarness = min(minimal_unfarness, A[i + (k - 1)] - A[i])
    return minimal_unfarness


n = int(raw_input())
k = int(raw_input())
A = []
for _ in xrange(n):
    A.append(int(raw_input()))

print unfairness(A, k)
