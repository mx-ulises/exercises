#!/bin/python

def test(s):
    n = len(s)
    for i in xrange(1, n / 2 + 1):
        x = int(s[0:i])
        t = str(x)
        while len(t) < n:
            x += 1
            t = t + str(x)
        if t == s:
            return "YES {0}".format(int(s[0:i]))
    return "NO"

q = int(raw_input())
for _ in xrange(q):
    s = raw_input()
    print test(s)
