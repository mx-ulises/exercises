#!/bin/python

def min_diff(A, B):
    A.sort()
    B.sort()
    d = abs(A[0] - B[0])
    i = 0
    j = 0
    while i < len(A) and j < len(B):
        new_d = abs(A[i] - B[j])
        d = min(d, new_d)
        if A[i] < B[j]:
            i += 1
        else:
            j +=1
    return d

A = [1, 3, 15, 11, 2]
B = [23, 127, 235, 19, 8]
print A
print B
print min_diff(A, B)
