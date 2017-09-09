#!/bin/python
from sets import Set

n, m = map(int, raw_input().split())
C = map(int, raw_input().split())

values = list(C)
all_vertex = range(n)
N = [Set(all_vertex) for _ in xrange(n)]

for i in xrange(n):
    N[i].discard(i)

for _ in xrange(m):
    x, y = map(int, raw_input().split())
    x, y = x - 1, y - 1
    N[x].discard(y)
    N[y].discard(x)

CLIQUES = Set([])

def BronKerbosch1(R, P, X):
    global CLIQUES
    if not P and not X:
        CLIQUES.add(R)
    while P:
        v = P.pop()
        P.add(v)
        BronKerbosch1(R | Set([v]), P & N[v], X & N[v])
        P.discard(v)
        X.add(v)

BronKerbosch1(Set([]), Set(all_vertex), Set([]))

def count_zeros(A):
    count = 0
    for x in A:
        if x == 0:
            count += 1
    return count

max_num = 0
max_arrays = Set([])

for q in CLIQUES:
    numbers = [C[i] for i in q]
    candidate = sum(numbers)
    if candidate > max_num:
        max_num = candidate
        max_arrays = Set([])
        max_arrays.add(q)
    elif candidate == max_num:
        max_arrays.add(q)

zero_set = Set([])
for i in xrange(n):
    if C[i] == 0:
        zero_set.add(i)

for i in zero_set:
    cliques = Set(max_arrays)
    for q in cliques:
        R = q - Set([i])
        max_arrays.add(R)

ways_2 = len(max_arrays)

print "{0} {1}".format(max_num, ways_2)
