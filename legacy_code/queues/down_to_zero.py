#!/bin/python
from math import sqrt

Q = int(raw_input())
A = [int(raw_input()) for _ in xrange(Q)]

for a in A:
    C = {}
    O = [(a, 0)]
    i = 0
    while i < len(O):
        x, d = O[i]
        i += 1
        if x == 0:
            C[x] = d
            break
        if x in C:
            continue
        min_factors = range(2, int(sqrt(x)) + 1)
        min_factors.reverse()
        new_elements = [(x / j, d + 1) for j in min_factors if not x % j]
        O.extend(new_elements)
        O.append((x - 1, d + 1))
        C[x] = d
    print C[0]
