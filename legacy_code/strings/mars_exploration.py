#!/bin/python

def test_char(c, a):
    if c != a:
        return 1
    return 0

s = raw_input().strip()
count = 0
for i in xrange(len(s) / 3):
    count += test_char(s[i * 3 + 0], "S")
    count += test_char(s[i * 3 + 1], "O")
    count += test_char(s[i * 3 + 2], "S")
print count
