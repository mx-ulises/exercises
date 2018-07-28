#!/bin/python

def mode_counting(A):
    count_dict = {}
    for a in A:
        if a not in count_dict:
            count_dict[a] = 0
        count_dict[a] += 1
    mode = A[0]
    for a in count_dict:
        if count_dict[mode] < count_dict[a]:
            mode = a
    return mode


def mode_sorting(A):
    A.sort()
    mode = A[0]
    mode_count = 1
    curr = A[0]
    curr_count = 1
    for i in xrange(1, len(A)):
        if curr == A[i]:
            curr_count += 1
            if mode_count < curr_count:
                mode = curr
                mode_count = curr_count
        else:
            curr_count = 1
            curr = A[i]
    return mode


def test(A):
    print A
    print "counting: {0}".format(mode_counting(A))
    print "sorting: {0}".format(mode_sorting(A))
    print "============================================="


test([1, 1, 1, 2, 2, 3, 4, 5, 6])
test([1, 2, 3, 4, 5])
test([4, 5, 1, 2, 1, 3, 4, 1])
test([1, 1, 1])
test([1, 1, 1, 2, 2, 2])
test([2, 2, 2, 1, 1, 1])
