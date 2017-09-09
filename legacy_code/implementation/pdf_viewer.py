#!/bin/python

H = map(int, raw_input().split())
word = raw_input()
max_h = 0

for c in word:
    i = ord(c) - ord('a')
    max_h = max(max_h, H[i])

print (max_h * len(word))
