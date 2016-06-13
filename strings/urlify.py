#!/bin/python

s = "Mr John Smith    "
print "'{0}'".format(s)

s = list(s)
n_r = 13
n = len(s)
j = 0

for i in xrange(n_r):
    c = s[n_r - 1 - i]
    if c == " ":
        s[n - 1 - j] = "0"
        s[n - 2 - j] = "2"
        j += 2
        c = "%"
    s[n - 1 - j] = c
    j += 1

print "'{0}'".format("".join(s))
