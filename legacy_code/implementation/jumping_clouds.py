#!/bin/python

n = int(raw_input())
A = map(int, raw_input().split())

jumps = 0
i = 0

while i < n - 1:
    if i + 2 >= n or A[i + 2] == 1:
        i += 1
    else:
        i += 2
    jumps += 1

print jumps
