#!/bin/python

s = "taoc catx"

def get_char_count(s):
    char_count = {}
    for i in xrange(len(s)):
        c = s[i]
        if c not in char_count:
            char_count[c] = 0
        char_count[c] += 1
    return char_count

s = "".join(s.split())
max_errors = len(s) % 2
char_count = get_char_count(s)

for c in char_count:
    max_errors -= char_count[c] % 2

if max_errors < 0:
    print "False"
else:
    print "True"
