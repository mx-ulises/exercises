#!/bin/python

def sum_swap(A, B):
    total_sum = sum(A) - sum(B)
    if total_sum % 2:
        return None
    delta = total_sum / 2
    A_set = set(A)
    B_set = set(B)
    for b in B_set:
        a = b + delta
        if a in A_set:
            return (a, b)
    return None

A = [4, 1, 2, 1, 1, 2, 3]
B = [3, 6, 3, 3, 1]

print "A: {0}".format(sum(A))
print "B: {0}".format(sum(B))
print sum_swap(A, B)
