#!/bin/python

n = int(raw_input())

for _ in xrange(n):
    word = raw_input()
    if len(word) <= 10:
        print word
    else:
        print "{0}{1}{2}".format(word[0], len(word) - 2, word[-1])
