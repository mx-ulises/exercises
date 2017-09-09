#!/bin/python

def get_ops(n):
    m = n % 5
    min_ops = (n / 5) + (m / 2) + (m % 2)
    return min_ops

def get_ops_array(A):
    a_min = min(A)
    B = [a - a_min for a in A if a > a_min]
    sum_b = sum([get_ops(b) for b in B])
    sum_b_1 = sum([get_ops(b + 1) for b in B]) + 1
    sum_b_2 = sum([get_ops(b + 2) for b in B]) + 1
    sum_b_5 = sum([get_ops(b + 5) for b in B]) + 1
    return min(sum_b, sum_b_1, sum_b_2, sum_b_5)

t = int(raw_input())
for _ in xrange(t):
    _ = raw_input()
    A = map(int, raw_input().split())
    print get_ops_array(A)
