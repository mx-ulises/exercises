#!/bin/python

def ceil_index(L, l, r, a):
    while r - l > 1:
        m = l + (r - l) / 2
        if L[m] >= a:
            r = m
        else:
            l = m
    return r

def calc_L(L, a):
    n = ceil_index(L, 0 - 1, len(L), a)
    if n < len(L):
        L[n] = min(a, L[n])
    else:
        L.append(a)

n = int(raw_input())
A = [int(raw_input()) for _ in xrange(n)]

L = [A[0]]

for i in xrange(1, n):
    a = A[i]
    calc_L(L, a)

print len(L)
