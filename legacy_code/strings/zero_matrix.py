#!/bin/python

def print_matrix(A):
    for row in A:
        print row

def zero_matrix(A, n, m):
    a_n = [False] * n
    a_m = [False] * m
    for i in xrange(n):
        for j in xrange(m):
            if A[i][j] == 0:
                a_n[i] = True
                a_m[j] = True
    for i in xrange(n):
        if a_n[i]:
            for j in xrange(m):
                A[i][j] = 0
    for j in xrange(m):
        if a_m[j]:
            for i in xrange(n):
                A[i][j] = 0
    return A

A = [[1, 2, 3, 4],
     [1, 0, 3, 4],
     [1, 2, 3, 4],
     [1, 2, 3, 4]
    ]

print_matrix(A)
print ""
print_matrix(zero_matrix(A, 4, 4))
