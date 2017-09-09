#!/bin/python

s = raw_input()

uniform = {}
c = ord(s[0]) - ord('a') + 1
l = 1
for i in xrange(1, len(s)):
    d = ord(s[i]) - ord('a') + 1
    if d == c:
        l += 1
    else:
        if c not in uniform or uniform[c] < l:
            uniform[c] = l
        c = d
        l = 1

if c not in uniform or uniform[c] < l:
    uniform[c] = l

n = int(raw_input())
characters = uniform.keys()
characters.sort()

for _ in xrange(n):
    x = int(raw_input())
    out = "No"
    for c in characters:
        if x % c == 0 and (x / c) <= uniform[c]:
            out = "Yes"
    print out
