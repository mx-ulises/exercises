#!/bin/python

def get_new_left(A, seed):
    left = seed
    for a in A:
        if A[a] != None:
            left = min(A[a], left)
    return left

def shortest_superseq(A, B):
    A = {a: None for a in A}
    n = len(A)
    left = None
    right = None
    min_range = (0, len(B))
    for i in xrange(len(B)):
        b = B[i]
        if b in A:
            if left == None:
                left = i
            if A[b] == None:
                n -= 1
            A[b] = i
            right = i
            left = get_new_left(A, i)
            if (n == 0) and (right - left) < (min_range[1] - min_range[0]):
                min_range = (left, right)
    if n > 0:
        return None
    return min_range

A = [1, 5, 9]
B = [7, 5, 9, 0, 2, 1, 3, 5, 9, 9, 1, 5, 5, 8, 8, 9, 7]
print A
print B
left, right = shortest_superseq(A, B)
print (left, right)
print B[left:right + 1]
