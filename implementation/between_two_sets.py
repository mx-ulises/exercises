#!/bin/python

_ = raw_input()
A = map(int, raw_input().split())
B = map(int, raw_input().split())
maximal = max(A)
minimal = min(B)

total = 0
for x in xrange(maximal, minimal + 1):
    valid = True
    for a in A:
        if x % a:
            valid = False
    for b in B:
        if b % x:
            valid = False
    if valid:
        total += 1

print total
