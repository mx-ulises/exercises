#!/bin/python

_ = raw_input()
steps = raw_input()

level = 0
valley_count = 0

for step in steps:
    if step == "D":
        level -= 1
    elif step == "U":
        level += 1
        if level == 0:
            valley_count += 1

print valley_count
