#!/bin/python

def semi_sort(A):
    n = len(A)
    p = n - 1
    i, j = 0, 0
    while i < p:
        while i < p:
            if A[i] <= A[p]:
                A[i], A[j] = A[j], A[i]
                j += 1
            i += 1
        A[p], A[j] = A[j], A[p]
        if A[p] <= 0:
            i = j + 1
        else:
            p = j - 1
        j = i

def test(A):
    print "Before {0}".format(A)
    semi_sort(A)
    print "After  {0}".format(A)
    print "========================================="

test([-2, 8, 10, -5, -7, 11, 9, 15, -3])
test([-2, 8, 0, -5, -7, 1, 0, -15, -3])
