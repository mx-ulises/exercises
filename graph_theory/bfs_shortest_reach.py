#!/bin/python

def bfs(G, s):
    O = [(s, 0)]
    C = {}
    while O:
        x, d = O.pop(0)
        if x in C:
            continue
        for y in G[x]:
            O.append((y, d + 6))
        C[x] = d
    return C

T = int(raw_input())

for _ in xrange(T):
    n, m = map(int, raw_input().split())
    G = {i + 1: [] for i in xrange(n)}
    for _ in xrange(m):
        x, y = map(int, raw_input().split())
        G[x].append(y)
        G[y].append(x)
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
