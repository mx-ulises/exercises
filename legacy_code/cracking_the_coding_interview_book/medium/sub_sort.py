#!/bin/python

def get_min_out_of_order(A):
    a_min = None
    for i in xrange(1, len(A)):
        if A[i] < A[i - 1]:
            if a_min == None or A[i] < a_min:
                a_min = A[i]
    return a_min

def get_max_out_of_order(A):
    a_max = None
    for i in xrange(1, len(A)):
        if A[i] < A[i - 1]:
            if a_max == None or a_max < A[i - 1]:
                a_max = A[i - 1]
    return a_max

def sub_sort(A):
    a_n = get_min_out_of_order(A)
    a_m = get_max_out_of_order(A)
    if a_n == None:
        return (0, 0)
    n = 0
    while A[n] <= a_n:
        n += 1
    m = len(A) - 1
    while a_m <= A[m]:
        m -= 1
    return (n, m)


A = [1, 2, 4, 7, 10, 11, 7, 12, 6, 7, 16, 18, 19]
print sub_sort(A)

A = [1, 2, 3, 4, 5]
print sub_sort(A)

A = [5, 4, 3, 2, 1]
print sub_sort(A)
