#!/bin/python

def binary_search(A, a):
    i_max = len(A) - 1
    i_min = 0
    while i_min < i_max:
        i_mid = (i_max + i_min) / 2
        if a == A[i_mid]:
            return i_mid
        elif a < A[i_mid]:
            i_max = i_mid - 1
        else:
            i_min = i_mid + 1
    i_mid = (i_max + i_min) / 2
    if 0 <= i_mid and a < A[i_mid]:
        i_mid -= 1
    return i_mid


_ = int(raw_input())
scores = map(int, raw_input().split())
scores = list(set(scores))
scores.sort()
n = len(scores)

_ = int(raw_input())
A = map(int, raw_input().split())

for a in A:
    rank = n - binary_search(scores, a)
    print rank
