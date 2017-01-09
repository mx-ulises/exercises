#!/bin/python

def mean(A):
    total = 0.0
    for a in A:
        total += a
    return (total / len(A))

def median(A):
    n = len(A)
    if (n % 2) == 1:
        return A[n / 2]
    else:
        values = A[n / 2] + A[n / 2 - 1]
        return (values / 2)

def mode(A):
    B = {}
    for a in A:
        if a not in B:
            B[a] = 0
        B[a] += 1
    a = A[0]
    for b in B:
        if B[a] < B[b]:
            a = b
        elif B[a] == B[b]:
            a = min(a, b)
    return int(a)

_ = raw_input()
A = map(float, raw_input().split())
A.sort()

print "{0:0.1f}".format(mean(A))
print "{0:0.1f}".format(median(A))
print "{0}".format(mode(A))
