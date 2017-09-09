#!/bin/python

n = int(raw_input())
s = map(int, raw_input().split())
d, m = map(int, raw_input().split())

count = 0
if m <= n:
    current_d = sum(s[0:m])
    if current_d == d:
        count += 1

for i in xrange(m, n):
    current_d = current_d - s[i - m] + s[i]
    if current_d == d:
        count += 1

print count
