#!/bin/python

s = raw_input()

total = 1
for c in s:
    if c == "_":
        total += 1

print total
