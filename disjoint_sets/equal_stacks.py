#!/bin/python

from sets import Set

_ = raw_input()
A_1 = map(int, raw_input().split())
A_1.reverse()
A_2 = map(int, raw_input().split())
A_2.reverse()
A_3 = map(int, raw_input().split())
A_3.reverse()

S_1 = Set([0])
S_2 = Set([0])
S_3 = Set([0])

cum = 0
for a in A_1:
    cum += a
    S_1.add(cum)

cum = 0
for a in A_2:
    cum += a
    S_2.add(cum)

cum = 0
for a in A_3:
    cum += a
    S_3.add(cum)

print max(S_1 & S_2 & S_3)
