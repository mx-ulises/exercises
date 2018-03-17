#!/bin/python

def multiple_array(X):
    if not X:
        return []
    n = len(X)
    M = [1] * n
    L = [1] * n
    R = [1] * n
    L[0] = X[0]
    R[n - 1] = X[n - 1]
    for i in xrange(1, n):
        j = n - i - 1
        L[i] = L[i - 1] * X[i]
        R[j] = R[j + 1] * X[j]
        M[i] *= L[i - 1]
        M[j] *= R[j + 1]
    return M

def test(X):
    total = 1
    for x in X:
        total *= x
    M = [total / x for x in X]
    print "Algo: {0}".format(multiple_array(X))
    print "Test: {0}".format(M)

test([1, 2, 3, 4, 5, 6])
test([1])
test([])
test([1, 2, 3, -4, 5, 6])