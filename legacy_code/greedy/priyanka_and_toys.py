#!/bin/python

_ = raw_input()
W = map(int, raw_input().split())
W.sort()

count = 1
w_1 = W.pop(0)

for w in W:
    if (w_1 + 4) < w:
        w_1 = w
        count += 1

print count
