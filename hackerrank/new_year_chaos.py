#!/bin/python

def count_bribes(A, n):
    bribes = 0
    for i in xrange(n):
        j = n - i - 1
        x = n - i
        if A[j] == x:
            bribes += 0
        elif A[j - 1] == x:
            bribes += 1
            A[j - 1], A[j] = A[j], A[j - 1]
        elif A[j - 2] == x:
            bribes += 2
            A[j - 2], A[j - 1], A[j] = A[j - 1], A[j], A[j - 2]
        else:
            return "Too chaotic"
    return bribes


t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    A = map(int, raw_input().split())
    print count_bribes(A, n)
