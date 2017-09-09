#!/bin/python

from random import randrange

H_2 = {}

def fit(a, b):
    if a[0] > b[0] and a[1] > b[1] and a[2] > b[2]:
        return True
    return False

def box(n):
    return (randrange(1, n), randrange(1, n), randrange(1, n))

def get_max(H, k):
    if k in H_2:
        return H_2[k]
    h = k[0]
    H_2[k] = h
    for b in H[k]:
        H_2[k] = max(H_2[k], h + get_max(H, b))
    return H_2[k]

def get_relations(B):
    H = {}
    for k in B:
        H[k] = []
        for b in B:
            if fit(k, b):
                H[k].append(b)
    return H

def get_max_highest(B):
    H = get_relations(B)
    for k in H:
        H_2[k] = get_max(H, k)
    maximal = 0
    max_k = None
    for k in H_2:
        maximal = max(maximal, H_2[k])
        if maximal == H_2[k]:
            max_k = k
    print "{0}: {1}".format(max_k, H[max_k])
    return maximal


B = []
n = 15

for i in xrange(n):
    B.append(box(10))
    print B[-1]

print get_max_highest(B)
