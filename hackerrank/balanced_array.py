#!/bin/python

def balanced_array(A):
    pre = 0
    post = sum(A)
    for a in A:
        post -= a
        if pre == post:
            return True
        pre += a
    return False

T = int(raw_input())

for _ in xrange(T):
    _ = int(raw_input())
    A = map(int, raw_input().split())
    if balanced_array(A):
        print "YES"
    else:
        print "NO"
