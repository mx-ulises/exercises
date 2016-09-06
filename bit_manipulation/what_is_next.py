#!/bin/python

def get_new_array(A, n):
    i = n
    if n % 2 == 0:
        i -= 1
    A[i] -= 1
    A[i - 1] -= 1
    D = A[1:i] + [1, 1] + A[i:]
    if n % 2 == 0:
        D.append(D[-2])
        D[-3] = 0
    return D

def remove_zeros(A):
    D = []
    n = len(A)
    i = 0
    while i < n:
        if A[i] == 0:
            if i + 1 < n:
                D[-1] += A[i + 1]
            i += 2
        else:
            D.append(A[i])
            i += 1
    return D

t = int(raw_input())

for _ in xrange(t):
    n = int(raw_input())
    A = [1] + map(int, raw_input().split())
    D = get_new_array(A, n)
    D = remove_zeros(D)
    print "{0}".format(len(D))
    print " ".join(map(str, D))
