#!/bin/python

from heapq import heappush, heappop

def count_A(A):
    B = {}
    for i in xrange(1, len(A)):
        a = A[i]
        if a not in B:
            B[a] = 0
        B[a] += 1
    return B


def get_min_team(A):
    min_val = 100000
    keys = A.keys()
    keys.sort()
    teams = {}
    for key in keys:
        teams[key] = []
        for _ in xrange(A[key]):
            if (key - 1) not in teams or not teams[key - 1]:
                heappush(teams[key], 1)
            else:
                heappush(teams[key], heappop(teams[key - 1]) + 1)
    for key in keys:
        if teams[key]:
            min_val = min(min_val, teams[key][0])
    return min_val


t = int(raw_input())

for _ in xrange(t):
    A = map(int, raw_input().split())
    B = count_A(A)
    if A[0] == 0:
        print 0
    else:
        print get_min_team(B)
