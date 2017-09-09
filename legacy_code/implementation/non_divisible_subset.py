#!/bin/python

n, k = map(int, raw_input().split())
A = [int(a) % k for a in raw_input().split()]

B = {i: 0 for i in xrange(k)}

for a in A:
    B[a] += 1

total = 0
for i in xrange(1, k / 2):
    total += max(B[i], B[k - i])

if k % 2:
    if k > 1:
        total += max(B[k / 2], B[k / 2 + 1])
elif B[k / 2]:
    total += 1

if B[0]:
    total += 1

print total
