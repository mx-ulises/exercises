#!/bin/python

_ = raw_input()
A = map(int, raw_input().split())
_ = raw_input()
B = map(int, raw_input().split())

numbers = {}

for n in B:
    if n not in numbers:
        numbers[n] = 0
    numbers[n] += 1

for n in A:
    numbers[n] -= 1

missing = []
for n in numbers:
    if numbers[n]:
        missing.append(n)

missing.sort()

print " ".join(map(str, missing))
