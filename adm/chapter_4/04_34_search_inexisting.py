#!/bin/python

def find_inexisting(A):
    n = len(A)
    left = 0
    right = n - 1
    while left < right:
        mid = (left + right) / 2
        print "   {0}: {1}".format(mid, A[mid])
        if A[mid] == mid:
            left = mid + 1
        else:
            right = mid - 1
    if (A[left] == left):
        left += 1
    return left

def test(A):
    print A
    print "Not found: {0}".format(find_inexisting(A))
    print "=============================="

test([1, 2, 3, 4, 5, 6, 7])
test([0, 1, 2, 3, 4, 5, 7])
test([0, 1, 3, 4, 5, 6, 7])
test([0, 1, 2, 3, 4, 5, 6])

