#!/bin/python

_ = raw_input()

MAX_NUM = 100

nums = map(int, raw_input().split())
nums_count = [0] * MAX_NUM
for x in nums:
    nums_count[x] += 1

nums = []
for x in xrange(MAX_NUM):
    for _ in xrange(nums_count[x]):
        nums.append(x)

print " ".join(map(str, nums))
