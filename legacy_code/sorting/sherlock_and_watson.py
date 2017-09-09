#!/bin/python
n, k, q = map(int, raw_input().split())
A = map(int, raw_input().split())

for _ in xrange(q):
    i = int(raw_input())
    print A[(i - k) % n]
