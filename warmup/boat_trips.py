#!/bin/python

_, c, m = map(int, raw_input().split())
P = map(int, raw_input().split())
max_cap = c * m

all_trips = True
for p in P:
    if max_cap < p:
        all_trips = False

if all_trips:
    print "Yes"
else:
    print "No"
