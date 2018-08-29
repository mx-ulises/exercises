#!/bin/python

def sub_sort_range(A):
    n, m = 0, 0
    current_max = A[0]
    current_min = A[-1]
    for i in xrange(1, len(A)):
        if A[i] < current_max:
            m = i
        current_max = max(current_max, A[i])
    for i in xrange(1, len(A)):
        j = len(A) - i - 1
        if current_min < A[j]:
            n = j
        current_min = min(current_min, A[j])
    return (n, m)


def test(A):
    print "================================================="
    print "Originanl: {0}".format(A)
    range_n_m = sub_sort_range(A)
    A.sort()
    print "Sorted:    {0}".format(A)
    print "Range: {0}".format(range_n_m)


A = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
test(A)

A = [1, 1, 1, 1, 1, 1]
test(A)

A = [1, 2, 3, 4, 5]
test(A)

A = [5, 4, 3, 2, 1]
test(A)

A = [1, 4, 3, 2, 5]
test(A)

A = [1, 4, 3, 2, 1]
test(A)
