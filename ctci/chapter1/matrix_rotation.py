#!/bin/python

def matrix_rotation(A):
    n = len(A)
    k = 0
    while k < (n / 2):
        for i in xrange(n - (2 * k) - 1):
            aux = A[n - k - 1 - i][k]
            A[n - k - 1 - i][k] = A[n - k - 1][n - k - 1 - i]
            A[n - k - 1][n - k - 1 - i] = A[k + i][n - k - 1]
            A[k + i][n - k - 1] = A[k][k + i]
            A[k][k + i] = aux
        k += 1
    return A


def print_matrix(A):
    for r in A:
        r = [str(c) for c in r]
        print "\t".join(r)


def test(A):
    print '========================================='
    print "Before"
    print_matrix(A)
    print "After"
    print_matrix(matrix_rotation(A))


A = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]
    ]
test(A)

A = [[1, 2, 3, 4],
     [5, 6, 7, 8],
     [9, 10, 11, 12],
     [13, 14, 15, 16]
    ]
test(A)
