#!/bin/python
input_lines = """3
10 2 5
12 4 4
6 2 2
""".splitlines()

T = int(input_lines[0])
for i in xrange(T):
    N, C, M = map(int, input_lines[i + 1].split())
    chocolates = N / C
    W = chocolates
    while W >= M:
        new_chocolates = W / M
        W = new_chocolates + W % M
        chocolates += new_chocolates
    print chocolates
