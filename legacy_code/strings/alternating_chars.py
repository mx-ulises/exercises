#!/bin/python

def count_repeat(s):
    if len(s) == 0:
        return 0
    current = s[0]
    repeat = 0
    for i in xrange(1, len(s)):
        if current == s[i]:
            repeat += 1
        current = s[i]
    return repeat

t = int(raw_input())
for _ in xrange(t):
    s = raw_input()
    print count_repeat(s)
