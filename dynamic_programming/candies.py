#!/bin/python
n = int(raw_input())
i_max = 0
prev = int(raw_input())
prev_c = 1

candies = 1
local_max = 1
local_max_2 = 0

for i in xrange(1, n):
    curr = int(raw_input())
    if curr > prev:
        i_max = i
        prev_c += 1
        candies += prev_c
        local_max = prev_c
        local_max_2 = 0
    elif curr < prev:
        prev_c = 1
        candies += 1 + (i - i_max)
        local_max_2 += 1
        if local_max > local_max_2:
            candies -= 1
        else:
            local_max += 1
    else:
        prev_c = 1
        i_max = i
        candies += 1
        local_max = 1
        local_max_2 = 0
    prev = curr

print candies
