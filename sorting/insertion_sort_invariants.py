#!/bin/python

def insertion_sort(A, n):
    for i in xrange(1, len(A)):
        j = i - 1
        k = A[i]
        while 0 <= j and k < A[j]:
            A[j + 1] = A[j]
            j -= 1
        A[j + 1] = k

n = input()
A = map(int, raw_input().split())
insertion_sort(A, n)
print " ".join(map(str, A))
