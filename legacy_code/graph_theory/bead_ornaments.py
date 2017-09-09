#!/bin/python
from operator import mul

def product(l):
    return reduce(mul, l)

for _ in xrange(int(raw_input())):
    N = int(raw_input())
    B = map(int, raw_input().split())
    color_orn = product([pow(b, b - 2) for b in B])
    tree_comb = product(B) * pow(sum(B), N - 2)
    print int(color_orn * tree_comb % 1000000007)
