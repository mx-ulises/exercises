#!/bin/python

from heapq import heappop, heappush

def bfs(G, s):
    O = [(0, s)]
    C = {}
    while O:
        d, x = heappop(O)
        if x in C:
            continue
        for pair in G[x]:
            y, e = pair
            heappush(O, (d + e, y))
        C[x] = d
    return C

T = int(raw_input())

for _ in xrange(T):
    n, m = map(int, raw_input().split())
    G = {i + 1: [] for i in xrange(n)}
    for _ in xrange(m):
        x, y, d = map(int, raw_input().split())
        G[x].append((y, d))
        G[y].append((x, d))
    G = {key: set(G[key]) for key in G}
    s = int(raw_input())
    closed = bfs(G, s)
    out_str = ""
    for i in xrange(1, n + 1):
        if i == s:
            continue
        elif i not in closed:
            out_str += "-1 "
        else:
            out_str += "{0} ".format(closed[i])
    print out_str
