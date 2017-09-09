#!/bin/python

def insertionSort(A, n):
    i = n - 1
    x = A[i]
    completed = False
    while 0 < i:
        i -= 1
        if x < A[i]:
            A[i + 1] = A[i]
            print " ".join(map(str, A))
        else:
            A[i + 1] = x
            print " ".join(map(str, A))
            completed = True
            break
    if not completed:
        A[0] = x
        print " ".join(map(str, A))

n = int(raw_input())
A = map(int, raw_input().split())
insertionSort(A, n)
