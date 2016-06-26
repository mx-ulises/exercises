#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())
numbers = {}
i = 0
min_val = 10000

for a in A:
    if a not in numbers:
        numbers[a] = []
    numbers[a].append(i)
    i += 1

for a in numbers:
    indexes = numbers[a]
    for i in xrange(1, len(indexes)):
        min_val = min(min_val, indexes[i] - indexes[i - 1])

if min_val == 10000:
    min_val = -1
print min_val
