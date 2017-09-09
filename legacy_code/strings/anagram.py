#!/bin/python

def modify_count(count, a, value):
    if a not in count:
        count[a] = 0
    count[a] += value
    return count

def get_changes(s):
    n = len(s)
    if (n % 2) == 1:
        return "-1"
    count = {}
    for i in xrange(n / 2):
        count = modify_count(count, s[i], 1)
        count = modify_count(count, s[n - 1 - i], -1)
    c = sum([count[k] for k in count if count[k] > 0])
    return c

t = int(raw_input())
for _ in xrange(t):
    s = raw_input()
    print get_changes(s)
