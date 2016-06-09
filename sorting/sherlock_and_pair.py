#!/bin/python

t = int(raw_input())

for _ in xrange(t):
    _ = int(raw_input())
    A = map(int, raw_input().split())
    num_map = {}
    for a in A:
        if a not in num_map:
            num_map[a] = 0
        num_map[a] += 1
    pair_count = 0
    for a in num_map:
        m = num_map[a]
        pair_count += (m * (m - 1))
    print pair_count
