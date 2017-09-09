#!/bin/python

n, k = map(int, raw_input().split())
S = map(int, list(raw_input()))

T = [S[0]]

for i in xrange(1, min(n, k)):
    T.append(S[i - 1] ^ S[i])

for i in xrange(k, n):
    T.append(S[i - 1] ^ S[i] ^ T[i - k])

print "".join(map(str, T))
