#!/bin/python

from heapq import heappush, heappop

h = []
n = int(raw_input())
pares = [map(int, raw_input().split()) for _ in xrange(n)]
pares = sorted(pares, key=lambda x: x[0])

w = 0

while pares:
    t_i, l_i = pares.pop(0)
    heappush(h, (l_i, (t_i, l_i)))
    x_i = t_i

    while pares and pares[0][0] <= x_i:
        t_i, l_i = pares.pop(0)
        heappush(h, (l_i, (t_i, l_i)))

    while h:
        t_i, l_i = heappop(h)[1]
        d_i = x_i + l_i
        w_i = d_i - t_i
        w += w_i
        x_i = d_i
        while pares and pares[0][0] <= x_i:
            t_i, l_i = pares.pop(0)
            heappush(h, (l_i, (t_i, l_i)))

print (w / n)

