#!/bin/python

input_str = """2 5
1 0 5
1 1 7
1 0 3
2 1 0
2 1 1
""".splitlines()

N, Q = map(int, input_str[0].split())

lastAns = 0

seqList = [[] for _ in xrange(N)]

for i in xrange(Q):
    q, x, y = map(int, input_str[i + 1].split())
    index = ((x ^ lastAns) % N)
    if q == 1:
        seqList[index] += [y]
    if q == 2:
        lastAns = seqList[index][y % len(seqList[index])]
        print lastAns
