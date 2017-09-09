#!/bin/python

def solve(n):
    zero_count = 0
    while 0 < n:
        if (n & 1) == 0:
            zero_count += 1
        n = n >> 1
    return 2 ** zero_count

n = int(raw_input())
print solve(n)
