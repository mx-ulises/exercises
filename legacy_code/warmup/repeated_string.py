#!/bin/python

s = raw_input()
n = long(raw_input())

count = s.count('a') * (n / len(s))
m = n % len(s)
count += s[:m].count('a')
print count
