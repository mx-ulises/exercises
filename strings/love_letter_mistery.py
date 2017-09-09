#!/bin/python

def get_reductions(s):
    n = len(s)
    count = 0
    for i in xrange(n / 2):
        count += abs(ord(s[i]) - ord(s[n - i - 1]))
    return count

q = int(raw_input())

for _ in xrange(q):
    s = raw_input()
    print get_reductions(s)
