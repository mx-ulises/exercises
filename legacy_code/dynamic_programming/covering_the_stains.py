#!/bin/python
from sets import Set
from math import factorial

def nCr(n, r):
    if r > n or 0 > r or 0 > n: return 0
    return factorial(n) / factorial(r) / factorial(n - r)

def get_brute_combs(S, n, k):
    brute_combs = 0
    for s in S:
        brute_combs += nCr(n - len(s), k - len(s))
    return brute_combs

def get_combs(S, n, k):
    a, b, c, d = S
    combs = get_brute_combs(S, n, k)
    S = [a | b, a | c, a | d, b | c, b | d, c | d]
    combs -= get_brute_combs(S, n, k)
    S = [a | b | c, a | b | d, a | c | d, b | c | d]
    combs += get_brute_combs(S, n, k)
    S = [a | b | c | d]
    combs -= get_brute_combs(S, n, k)
    return combs

def get_borders(n, k):
    borders = []
    x_stain = {}
    y_stain = {}
    # Fill borders
    for i in xrange(n):
        x, y = map(int, raw_input().split())
        if x not in x_stain: x_stain[x] = []
        x_stain[x].append(i + 1)
        if y not in y_stain: y_stain[y] = []
        y_stain[y].append(i + 1)
    # Add borders
    borders.append(Set(x_stain[max(x_stain)]))
    borders.append(Set(x_stain[min(x_stain)]))
    borders.append(Set(y_stain[max(y_stain)]))
    borders.append(Set(y_stain[min(y_stain)]))
    # Return borders
    return borders

n, k = map(int, raw_input().split())
borders = get_borders(n, k)
print get_combs(borders, n, k) % 1000000007
