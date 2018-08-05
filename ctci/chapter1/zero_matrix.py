#!/bin/python

def zero_matrix(M):
    # Get dimensions
    n, m = len(M), len(M[0])

    # Get 0-column zeros
    i_0 = False
    for i in xrange(n):
        if M[i][0] == 0:
            i_0 = True

    # Get 0-row zeros
    j_0 = False
    for j in xrange(m):
        if M[0][j] == 0:
            j_0 = True

    # Get Zeros from inner matrix
    for i in xrange(1, n):
        for j in xrange(1, m):
            if M[i][j] == 0:
                M[i][0] = 0
                M[0][j] = 0

    # Set Zeros for inner matrix
    for i in xrange(1, n):
        for j in xrange(1, m):
            if M[i][0] == 0 or M[0][j] == 0:
                M[i][j] = 0

    # Set Zeros in zero-column
    if i_0:
        for i in xrange(n):
            M[i][0] = 0

    # Set Zeros in zero-row
    if j_0:
        for j in xrange(m):
            M[0][j] = 0

    # Return matrix
    return M


def test(M):
    print "========================"
    for m in M:
        print m
    M = zero_matrix(M)
    print "Converted"
    for m in M:
        print m


M = [[1, 1, 0],
     [1, 0, 1],
     [1, 1, 1]]
test(M)


M = [[1, 1, 0, 1],
     [1, 0, 1, 1],
     [1, 1, 1, 1]]
test(M)


M = [[1, 1, 1, 1],
     [1, 1, 0, 1],
     [1, 0, 1, 1],
     [1, 1, 1, 1]]
test(M)

M = [[1, 1, 1, 1],
     [1, 1, 1, 1],
     [1, 1, 1, 1],
     [0, 1, 1, 1]]
test(M)

M = [[1, 1, 0, 1],
     [1, 1, 1, 1],
     [1, 1, 1, 1],
     [0, 1, 1, 1]]
test(M)
