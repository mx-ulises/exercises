#!/bin/python

def get_nums(A, n):
    for k in xrange(len(A) - 2):
        i, j = k + 1, len(A) - 1
        while i < j:
            b = n - A[i] - A[k]
            if b == A[j]:
                return (k, i, j)
            if b < A[j]:
                j -= 1
            else:
                i += 1
    return (-1, -1, -1)

A = [1, 5 -5, 11, -7, -12, 17, 2, 7, 13]
n = 10
A.sort()

i, j, k = get_nums(A, n)

print A
print ""
print "k: {0}".format(n)
print "A[{0}]: {1}".format(i, A[i])
print "A[{0}]: {1}".format(j, A[j])
print "A[{0}]: {1}".format(k, A[k])
