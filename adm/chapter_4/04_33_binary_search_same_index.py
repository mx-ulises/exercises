#!/bin/python

def binary_search_same_index(A):
    left = 0
    right = len(A) - 1
    while left <= right:
        m = (left + right) / 2
        if (m + 1) == A[m]:
            return (m + 1)
        elif (m + 1) < A[m]:
            left = m + 1
        else:
            right = m - 1
    return None


def test(A):
    print A
    print binary_search_same_index(A)
    print "====================================="


test([1, 2, 3, 4, 5, 6, 7, 8])
test([0, 1, 2, 3, 4, 5, 6, 7, 8])
test([2, 3, 4, 5, 6, 7, 8])
test([2, 3, 4, 5, 6, 7, 8, 8])
test([1, 1, 2, 3, 4, 5, 6, 7, 8])

