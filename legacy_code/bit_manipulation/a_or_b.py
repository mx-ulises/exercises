#!/bin/python

def normalize_size(A, n):
    A_str = get_str(A)
    while len(A_str) < n:
        A_str = "0" + A_str
    return list(A_str)

def get_str(A):
    return "{0:b}".format(A)

t = int(raw_input())
for _ in xrange(t):
    k = int(raw_input())
    a, b, c = [int(raw_input(), 16) for _ in xrange(3)]
    n = max(len(get_str(a)), len(get_str(b)), len(get_str(c)))
    d = (a | b) ^ c
    A = normalize_size(a, n)
    B = normalize_size(b, n)
    C = normalize_size(c, n)
    D = normalize_size(d, n)

    for i in xrange(n):
        if D[i] == "1":
            if C[i] == "0":
                if A[i] == "1":
                    k -= 1
                    A[i] = "0"
                if B[i] == "1":
                    k -= 1
                    B[i] = "0"
            if C[i] == "1":
                k -= 1
                B[i] = "1"

    for i in xrange(n):
        if D[i] == "0" and C[i] == "1" and A[i] == "1":
            if k > 0 and B[i] == "1":
                A[i] = "0"
                k -= 1
            elif k > 1 and B[i] == "0":
                A[i] = "0"
                B[i] = "1"
                k -= 2

    if k < 0:
        print "-1"
    else:
        print "{0:x}".format(int("".join(A), 2)).upper()
        print "{0:x}".format(int("".join(B), 2)).upper()
