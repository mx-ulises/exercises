#!/bin/python

s = raw_input()
s_count = {}

for c in s:
    if c not in s_count:
        s_count[c] = 0
    s_count[c] += 1

odd_count = 0
for c in s_count:
    if (s_count[c] % 2) == 1:
        odd_count += 1

if 1 < odd_count:
    print "NO"
else:
    print "YES"
