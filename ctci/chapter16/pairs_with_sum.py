#!/bin/python

def pairs_with_sum(A, k):
    pairs = []
    visited = {}
    for a in A:
        j = k - a
        if j in visited:
            pairs.extend([(j, a) for _ in xrange(visited[j])])
        if a not in visited:
            visited[a] = 0
        visited[a] += 1
    return pairs


def test(A, k):
    print "================================"
    print pairs_with_sum(A, k)


A = [1, 2, 3, 4, 5, 6, 7, 0, 1, 1, 1, 6]
k = 7
test(A, k)
test(A, 10)
test([], k)
test(A, 1000)
