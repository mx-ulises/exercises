#!/bin/python

def print_num(n):
    i = n / 3
    while 0 <= i:
        k = i * 3
        j = n - k
        if (j % 5) == 0:
            return ("5" * k) + ("3" * j)
        i -= 1
    return "-1"

t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    print print_num(n)
