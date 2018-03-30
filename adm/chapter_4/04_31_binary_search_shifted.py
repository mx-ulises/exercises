#!/bin/python

def binary_search_shift(A, x, k = 0):
    n = len(A)
    left = k
    right = n - 1 + k
    while left <= right:
        m = (left + right) / 2
        if A[m % n] < x:
            left = m + 1
        elif x < A[m % n]:
            right = m - 1
        else:
            return m % n
    return None

def between(a, b, x):
    if a <= x or x <= b:
        return True
    return False

def binary_search_shift_no_k(A, x):
    n = len(A)
    left = 0
    right = n - 1
    while left <= right:
        m = (left + right) / 2
        if A[m] == x:
            return m
        elif between(A[left], A[m], x):
            right = m - 1
        else:
            left = m + 1
    return None

def max_shift(A, k):
    i_max = (len(A) - 1 + k) % len(A)
    return A[i_max]

def test(A, x, k):
    print "A: {0}".format(A)
    print "shift: {0}".format(k)
    print "find: {0}".format(x)
    print "index: {0}".format(binary_search_shift(A, x, k))
    print "index: {0}".format(binary_search_shift_no_k(A, x))
    print "max: {0}".format(max_shift(A, k))
    print "==============================================="

A = [35, 42, 5, 15, 27, 29]
test(A, 5, 2)
print test(A, 15, 2)
print test(A, 27, 2)
