#!/bin/python

dollars = 100000
t = int(raw_input())

for _ in xrange(t):
    rates = map(float, raw_input().split())
    final_rate = rates[0] * rates[1] * rates[2]
    final_dollars = int(dollars/final_rate - dollars)
    if final_dollars < 0:
        final_dollars = 0
    print final_dollars
