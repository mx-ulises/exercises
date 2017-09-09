#!/bin/python
n = int(raw_input())
coins = map(int, raw_input().split())
l, r = map(int, raw_input().split())

diff_coins = {}
for c in coins:
    if c not in diff_coins:
        diff_coins[c] = 0
    diff_coins[c] += 1

coins = diff_coins.keys()
coins.sort()

counts = [1] + [0] * r
for c in coins:
    for i in range(len(counts)):
        if c + i <= r:
            counts[i + c] += (counts[i] * diff_coins[c])

value = 0
for i in xrange(l, r + 1):
    value += counts[i]

print value % (pow(10, 9) + 7)
