#!/bin/python

def insert_num(n, m, i, j):
    clear_mask = 1
    for _ in xrange(j - i):
        clear_mask = (clear_mask << 1) + 1
    clear_mask = clear_mask << i
    n = n & ~clear_mask
    m = m << i
    return n | m
