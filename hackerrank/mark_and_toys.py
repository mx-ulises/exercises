#!/bin/python

n, k = map(int, raw_input().split())
prices = map(int, raw_input().split())

prices.sort()
spent = 0
i = 0

while spent < k and i < n:
    spent += prices[i]
    i += 1

print (i - 1)
