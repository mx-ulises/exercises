#!/bin/python

def get_sqrt(n):
    if n == 1:
        return 1
    left, right = 0, n
    x = (left + right) / 2
    n_test = x * x
    while n_test != n:
        if n_test < n:
            left = x
        else:
            right = x
        x = (left + right) / 2
        n_test = x * x
    return x

n = 1
print get_sqrt(n * n)
n = 0
print get_sqrt(n * n)
n = 10
print get_sqrt(n * n)
n = 100
print get_sqrt(n * n)
n = 241
print get_sqrt(n * n)
n = 1320
print get_sqrt(n * n)
n = 23554743
print get_sqrt(n * n)
n = 324983543
print get_sqrt(n * n)
