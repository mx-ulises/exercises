#!/bin/python

def measure(n, q):
    swaps_c = 0
    for _ in xrange(2):
        for i in xrange(1, n):
            if q[n - i] < q[n - i - 1]:
                q[n - i], q[n - i - 1] = q[n - i - 1], q[n - i]
                swaps_c = swaps_c + 1
    for i in xrange(n - 1):
        if q[i] > q[i + 1]: return "Too chaotic"
    return swaps_c

T = int(raw_input())
for a0 in xrange(T):
    n = int(raw_input())
    q = map(int, raw_input().split(' '))
    print measure(n, q)
