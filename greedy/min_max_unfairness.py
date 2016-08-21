#!/bin/python

def get_min_diff(A, n, k):
    diff = A[k - 1] - A[0]
    for i in xrange(1, n - k + 1):
        diff = min(A[k - 1 + i] - A[i], diff)
    return diff

n = int(raw_input())
k = int(raw_input())
A = [int(raw_input()) for _ in range(n)]
A.sort()

diff = get_min_diff(A, n, k)

print diff
