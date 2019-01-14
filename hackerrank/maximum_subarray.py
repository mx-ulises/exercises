#!/bin/python

def get_subsequence_sum(A):
    total = 0
    for a in A:
        if 0 < a:
            total += a
    if total == 0:
        total = max(A)
    return total

def get_subarray_sum(A, n):
    B = [0] * (n + 1)
    total = 0
    minimal = 0
    maximal = 0
    for i in xrange(n):
        B[i + 1] = B[i] + A[i]
        if B[i + 1] < minimal:
            total = max(total, maximal - minimal)
            minimal = B[i + 1]
            maximal = B[i + 1]
        maximal = max(maximal, B[i + 1])
    total = max(total, maximal - minimal)
    if total == 0:
        total = max(A)
    return total

q = int(raw_input())

for _ in xrange(q):
    n = int(raw_input())
    A = map(int, raw_input().split())
    subarray_sum = get_subarray_sum(A, n)
    subsequence_sum = get_subsequence_sum(A)
    print "{0} {1}".format(subarray_sum, subsequence_sum)
