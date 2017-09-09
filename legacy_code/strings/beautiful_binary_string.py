#!/bin/python
_ = raw_input()
s = list(raw_input())

step = 0
steps = ["0", "1", "0"]
counter = 0

nl = "\n"
for c in s:
    if c != steps[step]:
        if c == "1":
            step = 0
        else:
            step = 1
    else:
        step += 1
        if step == 3:
            counter += 1
            step = 0

print counter
