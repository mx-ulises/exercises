#!/bin/python

def insert(C, c):
    if not C or C[-1] != c:
        C.append(c)

def union_set(A, B):
    A.sort()
    B.sort()
    n, m = len(A), len(B)
    i, j = 0, 0
    C = []
    while i < n or j < m:
        if i == n:
            insert(C, B[j])
            j += 1
        elif j == m:
            insert(C, A[i])
            i += 1
        elif A[i] < B[j]:
            insert(C, A[i])
            i += 1
        else:
            insert(C, B[j])
            j += 1
    return C

A = [1, 2, 3, 4, 10, 11, 18]
B = [1, 3, 4, 5, 6]

print union_set(A, B)
