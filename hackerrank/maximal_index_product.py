#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())

left = [0] * n
right = [0] * n

s = []
for i in xrange(n):
    a = A[i]
    while 0 < len(s) and s[-1][0] <= a:
        s.pop()
    if 0 < len(s):
        left[i] = s[-1][1]
    s.append((a, i + 1))

s = []
for i in xrange(n):
    j = n - i - 1
    a = A[j]
    while 0 < len(s) and s[-1][0] <= a:
        s.pop()
    if 0 < len(s):
        right[j] = s[-1][1]
    s.append((a, j + 1))

maximal = 0
for i in xrange(n):
    index_product = left[i] * right[i]
    maximal = max(maximal, index_product)

print maximal
