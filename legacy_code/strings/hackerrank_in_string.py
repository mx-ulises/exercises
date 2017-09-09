#!/bin/python

def test_hacker_rank(s):
    t = "hackerrank"
    t_i = 0
    for s_i in xrange(len(s)):
        if t[t_i] == s[s_i]:
            t_i += 1
        if t_i == len(t):
            return True
    return False

q = int(raw_input())
for _ in xrange(q):
    s = raw_input()
    if test_hacker_rank(s):
        print "YES"
    else:
        print "NO"
