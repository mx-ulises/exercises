#!/bin/python

from heapq import heappush, heappop, heapify

n, k = map(int, raw_input().split())
A = map(int, raw_input().split())

heapify(A)
operations = 0

while A[0] < k and 2 <= len(A):
    a_1 = heappop(A)
    a_2 = heappop(A)
    a = a_1 + 2 * a_2
    heappush(A, a)
    operations += 1

if 2 <= len(A):
    print operations
else:
    print -1
