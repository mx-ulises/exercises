#!/bin/python

level = 0
_ = raw_input()
s = raw_input()

count = 0

for c in s:
    if c == "U":
        level += 1
        if level == 0:
            count += 1
    if c == "D":
        level -= 1

print count
