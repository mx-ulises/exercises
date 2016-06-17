#!/bin/python

def print_matrix(A):
    for r in A:
        print r
    print ""

def rotate_matrix(A, n):
    p = 0
    while (n - 2 * p) > 0:
        q = n - p - 1
        for i in xrange(n - 2 * p - 1):
            aux = A[p][p + i]
            A[p][p + i] = A[q - i][p]
            A[q - i][p] = A[q][q - i]
            A[q][q - i] = A[p + i][q]
            A[p + i][q] = aux
        p += 1
    return A

A = [[1, 2, 3, 4],
     [12, 1, 2, 5],
     [11, 4, 3, 6],
     [10, 9, 8, 7]]

print_matrix(A)
A = rotate_matrix(A, 4)
print_matrix(A)

A = [[1, 2, 3],
     [8, 1, 4],
     [7, 6, 5]]

print_matrix(A)
A = rotate_matrix(A, 3)
print_matrix(A)
