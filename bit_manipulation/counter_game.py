#!/bin/python
def check_bit(n, i):
    mask = 1 << i
    return (n & mask) >> i

NAMES = ["Louise", "Richard"]

T = int(raw_input())

for _ in xrange(T):
    n = int(raw_input())
    turn = 0
    while not check_bit(n, 0):
        turn += 1
        n = n >> 1
    while n > 0:
        if check_bit(n, 0):
            turn += 1
        n = n >> 1
    print NAMES[turn % 2]
