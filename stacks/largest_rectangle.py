#!/bin/python

def process(x, S):
    c = 0
    maximum = 0
    h = S[-1]
    while S and x < S[-1]:
        y = S.pop()
        if h > y:
            maximum = max(maximum, h * c)
            h = y
        c += 1
    maximum = max(maximum, h * c)
    for _ in xrange(c):
        S.append(x)
    return maximum, S

n = int(raw_input())
numbers = map(int, raw_input().split())

numbers.append(0)
S = [numbers.pop(0)]
max_a = 0

for x in numbers:
    if x < S[-1]:
        max_b, S = process(x, S)
        max_a = max(max_a, max_b)
    S.append(x)

print max_a
