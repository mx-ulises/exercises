#!/bin/python

import random

def swap(A, i, j):
    aux = A[i]
    A[i] = A[j]
    A[j] = aux

def partition(A, left, right):
    pivot = A[right]
    index = left
    for i in xrange(left, right):
        if A[i] < pivot:
            swap(A, index, i)
            index += 1
    swap(A, index, right)
    return index

def get_first_k(A, k):
    if k < 0:
        return []
    k = k - 1
    left = 0
    right = len(A) - 1
    index = partition(A, left, right)
    while index != k:
        if index < k:
            left = index + 1
        else:
            right = index - 1
        index = partition(A, left, right)
    return A[:k + 1]

A = [random.randint(1, 100) for _ in xrange(10)]
print A
print get_first_k(A, 5)
