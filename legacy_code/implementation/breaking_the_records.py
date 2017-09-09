#!/bin/python

n = int(raw_input())
s = map(int, raw_input().split())

maximal = s[0]
minimal = s[0]

increase_count = 0
decrease_count = 0

for i in xrange(1, n):
    if maximal < s[i]:
        increase_count += 1
        maximal = s[i]
    if s[i] < minimal:
        decrease_count += 1
        minimal = s[i]

print "{0} {1}".format(increase_count, decrease_count)
