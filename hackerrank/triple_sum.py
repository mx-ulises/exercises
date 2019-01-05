#!/bin/python

_ = raw_input()

A = map(int, raw_input().split())
A = list(set(A))
A.sort()

B = map(int, raw_input().split())
B = list(set(B))
B.sort()

C = map(int, raw_input().split())
C = list(set(C))
C.sort()

triplet_count = 0
A_i = 0
C_i = 0

for q in B:
    while A_i < len(A) and A[A_i] <= q:
        A_i += 1
    while C_i < len(C) and C[C_i] <= q:
        C_i += 1
    if 0 < A_i and A[A_i - 1] <= q and 0 < C_i and C[C_i -1] <= q:
        triplet_count += (C_i * A_i)

print triplet_count
