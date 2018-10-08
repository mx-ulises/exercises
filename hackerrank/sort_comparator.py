#!/bin/python

n = int(raw_input())
data = {}
for _ in xrange(n):
    name, score = raw_input().split()
    score = int(score)
    if score not in data:
        data[score] = []
    data[score].append(name)

scores = data.keys()
scores.sort()
scores.reverse()

for score in scores:
    data[score].sort()
    for name in data[score]:
        print "{0} {1}".format(name, score)
