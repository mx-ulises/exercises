#!/bin/python
from math import log
NAMES = ["Louise", "Richard"]

T = int(raw_input())
for _ in xrange(T):
    n = list("{0:b}".format(int(raw_input())))
    turn = 0
    for d in n:
        if d == "1":
            turn += 1
    i = 0
    while n[-1 - i] != "1":
        turn += 1
        i += 1
    turn = turn % 2
    print NAMES[turn]
