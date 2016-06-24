#!/bin/python
from collections import deque

def enq(dq, value):
    while dq and dq[-1] < value:
        dq.pop()
    dq.append(value)

N, Q = map(int, raw_input().split())
A = map(int, raw_input().split())
for _ in xrange(Q):
    d = int(raw_input())
    maximum = deque([])
    for i in xrange(d):
        enq(maximum, A[i])
    min_val = maximum[0]
    for i in xrange(N - d):
        if maximum[0] == A[i]:
            maximum.popleft()
        enq(maximum, A[d + i])
        min_val = min(min_val, maximum[0])
    print min_val
