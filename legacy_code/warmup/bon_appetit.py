#!/bin/python

n, k = map(int, raw_input().split())
A = map(int, raw_input().split())
c = int(raw_input())
a = (sum(A) - A[k]) / 2

if a == c:
    print "Bon Appetit"
else:
    print (c - a)
