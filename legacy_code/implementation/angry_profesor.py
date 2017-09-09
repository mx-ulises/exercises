#!/bin/python

def students_on_time(A):
    return len([a for a in A if a <= 0])

t = int(raw_input())
for _ in xrange(t):
    _, k = map(int, raw_input().split())
    A = map(int, raw_input().split())
    if students_on_time(A) < k:
        print "YES"
    else:
        print "NO"
