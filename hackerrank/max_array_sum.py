#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())
A = [max(a, 0) for a in A]

if n == 1:
    print max(A[0], 0)
else:
    opt_1 = A[0]
    opt_2 = A[1]
    for i in xrange(2, n):
        if A[i] == 0:
            opt_1 = max(opt_1, opt_2)
            opt_2 = opt_1
        else:
            aux = opt_2
            opt_2 = max(opt_1 + A[i], opt_2 - A[i - 1] + A[i])
            opt_1 = aux
    print max(opt_1, opt_2)
