#!/bin/python

count = 0

def count_ways(A, x, j):
    global count
    while 0 < j:
        j -= 1
        r = x - A[j]
        if r == 0:
            count += 1
        elif 0 < r:
            count_ways(A, r, j)

x = int(raw_input())
n = int(raw_input())

A = []
i = 1
y = i ** n

while y <= x:
    A.append(y)
    i += 1
    y = i ** n

count_ways(A, x, len(A))
print count
