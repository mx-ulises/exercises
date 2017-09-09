#!/bin/python

def get_pair(C, m, n):
    n_map = {}
    for i in xrange(n):
        c = C[i]
        d = m - c
        if d in n_map:
            return "{0} {1}".format(n_map[d], i + 1)
        n_map[c] = i + 1

t = int(raw_input())
for _ in xrange(t):
    m = int(raw_input())
    n = int(raw_input())
    C = map(int, raw_input().split())
    print get_pair(C, m, n)
