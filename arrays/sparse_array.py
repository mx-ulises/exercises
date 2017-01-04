#!/bin/python

n = int(raw_input())
words = {}

for _ in xrange(n):
    s = raw_input()
    if s not in words:
        words[s] = 0
    words[s] += 1

q = int(raw_input())

for _ in xrange(q):
    s = raw_input()
    if s in words:
        print words[s]
    else:
        print "0"
