#!/bin/python

n = int(raw_input())
numbers_a = raw_input().split()
numbers_b = raw_input().split()

counter = 0
map_nums = {}
for num in numbers_a:
    if num not in map_nums:
        map_nums[num] = 0
    map_nums[num] += 1

for num in numbers_b:
    if num in map_nums and map_nums[num] > 0:
        counter += 1
        map_nums[num] -= 1

if counter == n:
    counter -= 1
else:
    counter += 1

print counter
