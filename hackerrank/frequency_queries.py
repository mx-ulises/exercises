#!/bin/python

count_int = {0: 0}
int_count = {}

q = int(raw_input())

for _ in xrange(q):
    op, x = map(int, raw_input().split())
    if op == 1:
        if x not in int_count:
            int_count[x] = 0
            count_int[0] += 1
        int_count[x] += 1
        c = int_count[x]
        count_int[c - 1] -= 1
        if c not in count_int:
            count_int[c] = 0
        count_int[c] += 1
    if op == 2 and x in int_count and 0 < int_count[x]:
        int_count[x] -= 1
        c = int_count[x]
        count_int[c] += 1
        count_int[c + 1] -= 1
    if op == 3:
        if x in count_int and 0 < count_int[x]:
            print 1
        else:
            print 0
