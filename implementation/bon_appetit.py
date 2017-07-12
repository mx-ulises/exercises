#!/bin/python

n, k = map(int, raw_input().split())
c = map(int, raw_input().split())
b_charged = int(raw_input())

b_actual = (sum(c) - c[k]) / 2
b_diff = b_charged - b_actual
if b_diff == 0:
    print "Bon Appetit"
else:
    print b_diff
