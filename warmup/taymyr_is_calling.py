#!/bin/python

n, m, z = map(int, raw_input().split())

a, b = max(n, m), min(n, m)
counter = a
count = 0
while counter <= z:
    if counter % b == 0:
        count += 1
    counter += a

print count
