#!/bin/python

n = int(raw_input())
L = map(int, raw_input().split())

L.sort()
found = False
for i in xrange(n - 2):
    j = n - 3 - i
    if L[j + 2] < L[j + 1] + L[j]:
        print "{0} {1} {2}".format(L[j], L[j + 1], L[j + 2])
        found = True
        break

if not found:
    print "-1"
