#!/bin/python

n, r = map(int, raw_input().split())
A = map(int, raw_input().split())

A.sort()

i = 0
count = 0

while i < n:
    count += 1
    start = A[i]
    while i < n and A[i] <= (start + r):
        i += 1
    mid = A[i - 1]
    while i < n and A[i] <= (mid + r):
        i += 1

print count
