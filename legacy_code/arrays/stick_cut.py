#!/bin/python

n = 8
sticks = map(int, "1 2 3 4 3 3 2 1".split())
stick_count = {x: 0 for x in range(1, 1001)}

for sticker in sticks:
    stick_count[sticker] += 1

for stick_size in stick_count:
    if stick_count[stick_size]:
        print n
        n = n - stick_count[stick_size]
