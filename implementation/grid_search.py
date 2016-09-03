#!/bin/python

T = int(raw_input())

def check_pattern(G, g_i, g_j, P, p_r, p_c):
    for i in xrange(p_r):
        for j in xrange(p_c):
            if G[g_i + i][g_j + j] != P[i][j]:
                return False
    return True


def exist_pattern(G, g_r, g_c, P, p_r, p_c):
    for i in xrange(g_r - p_r + 1):
        for j in xrange(g_c - p_c + 1):
            if check_pattern(G, i, j, P, p_r, p_c):
                return "YES"
    return "NO"


for _ in xrange(T):
    R, C = map(int, raw_input().split())
    G = [list(raw_input()) for _ in xrange(R)]
    r, c = map(int, raw_input().split())
    P = [list(raw_input()) for _ in xrange(r)]
    print exist_pattern(G, R, C, P, r, c)
