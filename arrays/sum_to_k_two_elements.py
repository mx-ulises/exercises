#!/bin/python

def get_nums(A, n):
    i, j = 0, len(A) - 1
    while i < j:
        b = n - A[i]
        if (n - A[i]) == A[j]:
            return (i, j)
        if b < A[j]:
            j -= 1
        else:
            i += 1
    return (-1, -1)

A = [1, 5 -5, 11, -7, -12, 17, 2, 7, 13]
n = 10
A.sort()

i, j = get_nums(A, n)

print A
print ""
print "n: {0}".format(n)
print "A[{0}]: {1}".format(i, A[i])
print "A[{0}]: {1}".format(j, A[j])
