#!/bin/python

def binary_search(X, x):
    l = 0
    r = len(X) - 1
    while l <= r:
        m = (l + r) / 2
        if A[m] < x:
            l = m + 1
        elif x < A[m]:
            r = m - 1
        else:
            return True
    return False

def find_pair(A, B, x):
    A.sort()
    for b in B:
        a = x - b
        if binary_search(A, a):
            return (a, b)
    return None

def test(A, B, x):
    print "Find match: {0}".format(x)
    print A
    print B
    print "Pair found is {0}".format(find_pair(A, B, x))
    print "============================================="


A = [8, 1, 2, 14, 24]
B = [3, 4, 10, 1, 15]

test(A, B, 10)
test(A, B, 5)
test(A, B, 1)
test(A, B, 2)
test(A, B, 5)
test(A, B, 12)
test(A, B, 0)

