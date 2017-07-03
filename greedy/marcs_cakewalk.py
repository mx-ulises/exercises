#!/bin/python

n = int(raw_input())
c = map(int, raw_input().split())

c.sort()
c.reverse()
j = 1

miles = 0
for c_i in c:
    miles += c_i * j
    j *= 2

print miles
