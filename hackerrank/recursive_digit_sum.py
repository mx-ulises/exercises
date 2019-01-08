#!/bin/python

def super_digit(n, k = 1):
    digits = map(int, list((str(n))))
    total = sum(digits) * k
    if total < 10:
        return total
    else:
        return super_digit(total)


n, k = map(int, raw_input().split())
print super_digit(n, k)
