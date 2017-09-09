#!/bin/python

def get_max_stack(elements):
    x = elements.pop()
    s = [x]
    s_max = [x]
    while elements:
        x = elements.pop()
        if x >= s_max[-1]:
            s_max.append(x)
        s.append(x)
    return (s, s_max)

t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    elements = map(int, raw_input().split())
    s, s_max = get_max_stack(elements)
    profit = 0
    count = 0
    cum = 0
    while s:
        x = s.pop()
        if x == s_max[-1]:
            s_max.pop()
            profit += (x * count - cum)
            count = cum = 0
        else:
            count += 1
            cum += x
    print profit
