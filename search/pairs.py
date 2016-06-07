#!/bin/python

n, k = map(int, raw_input().split())
A = map(int, raw_input().split())

numbers = {}
pairs = 0

for a in A:
    numbers[a] = a + k

for a in numbers:
    if numbers[a] in numbers:
        pairs += 1

print pairs

