#!/bin/python

def print_matrix(A):
    for r in A:
        print "".join(r)

def all_bombs(r, c):
    return [["O"] * c for _ in xrange(r)]

def step(A, r, c):
    B = all_bombs(r, c)
    for i in xrange(r):
        for j in xrange(c):
            if A[i][j] == "O":
                B[i][j] = "."
                if 0 < i: B[i - 1][j] = "."
                if i < r - 1: B[i + 1][j] = "."
                if 0 < j: B[i][j - 1] = "."
                if j < c - 1: B[i][j + 1] = "."
    return B

r, c, t = map(int, raw_input().split())

A = [list(raw_input()) for _ in xrange(r)]
A_1 = step(A, r, c)
A_3 = step(A_1, r, c)

if t == 0 or t == 1:
    print_matrix(A)
elif t % 2 == 0:
    print_matrix(all_bombs(r, c))
elif t % 4 == 3:
    print_matrix(A_1)
else:
    print_matrix(A_3)
