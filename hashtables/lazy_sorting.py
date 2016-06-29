#!/bin/python
from math import factorial

n = int(raw_input())
A = map(int, raw_input().split())

nums = {}
permutations = factorial(n)

for a in A:
    if a not in nums:
        nums[a] = 0
    nums[a] += 1

valid_permutations = 1
for a in nums:
    valid_permutations *= factorial(nums[a])

success_rate = float(valid_permutations) / float(permutations)
value = success_rate * pow((1 / success_rate), 2)
print "{0:.6f}".format(round(value, 6))
