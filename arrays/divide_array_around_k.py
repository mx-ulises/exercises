#!/bin/python

def separate(A, k):
    print A
    i = 0
    for j in xrange(len(A)):
        if A[j] < k:
            A[i], A[j] = A[j], A[i]
            i += 1
        j += 1
    for j in xrange(i, len(A)):
        if A[j] == k:
            A[i], A[j] = A[j], A[i]
            i += 1
        j += 1
    return A

print separate([9, 8, 7, 6, 5, 4, 3, 2, 1], 5)
print ""
print separate([1, 1, 1, 3, 4, 5, 6, 9, 9, 9], 5)
print ""
print separate([5, 5, 5, 5, 1, 5, 1, 4, 7, 10, 9, 9, 5], 5)
