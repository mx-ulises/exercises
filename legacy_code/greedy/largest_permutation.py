#!/bin/python

n, k = map(int, raw_input().split())
A = map(int, raw_input().split())
B = range(n + 1)

for i in xrange(n):
    a = A[i]
    B[a] = i

for a_i in xrange(n):
    a = A[a_i]
    if k:
        b_i = B.pop()
        b = A[b_i]
        if b > a:
            A[a_i], A[b_i] = A[b_i], A[a_i]
            B[a] = b_i
            k -= 1

print " ".join(map(str, A))
