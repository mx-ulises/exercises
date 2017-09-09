#!/bin/python

from sets import Set

n = int(raw_input())
W = map(int, raw_input().split())

total = sum(W)
min_diff = total

A = [Set([]) for _ in xrange(n)]
for _ in xrange(n - 1):
    x, y = map(int, raw_input().split())
    x, y = x - 1, y - 1
    A[x].add(y)
    A[y].add(x)

Open = [x for x in xrange(n) if len(A[x]) == 1]
while Open:
    x = Open.pop()
    min_diff = min(min_diff, abs(total - 2 * W[x]))
    for y in A[x]:
        A[y].remove(x)
        if len(A[y]) == 1:
            Open.append(y)
        W[y] += W[x]

print min_diff
