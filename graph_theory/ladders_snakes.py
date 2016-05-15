#!/bin/python
from heapq import heappush, heappop

def get_min_path(ladders, snakes):
    open_l = [(0, 1)]
    closed = []
    while open_l:
        s = heappop(open_l)
        if s[1] == 100: return s[0]
        if s[1] in closed: continue
        S = [(s[0] + 1, s[1] + i) for i in range(1, 7)]
        for s_i in S:
            if s_i[1] in ladders:
                s_i_new = (s_i[0], ladders[s_i[1]])
                heappush(open_l, s_i_new)
            elif s_i[1] in snakes:
                s_i_new = (s_i[0], snakes[s_i[1]])
                heappush(open_l, s_i_new)
            elif s_i[1] > 100:
                s_i_new = (s_i[0], s[1])
                heappush(open_l, s_i_new)
            else:
                heappush(open_l, s_i)
        closed.append(s[1])
    return -1


t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    ladders = {x: y for (x, y) in [map(int, raw_input().split()) for _ in range(n)]}
    m = int(raw_input())
    snakes = {x: y for (x, y) in [map(int, raw_input().split()) for _ in range(m)]}
    print get_min_path(ladders, snakes)
