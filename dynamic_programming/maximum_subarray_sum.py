#!/bin/python

t = int(raw_input())
for _ in xrange(t):
    n = int(raw_input())
    A = map(int, raw_input().split())

    # Buffers
    c_max = l_max = 0
    nc_max = 0

    # non-empty subarray validation
    all_negatives = True

    for a in A:
        l_max = max(0, l_max + a)
        c_max = max(c_max, l_max)
        if a > 0:
            all_negatives = False
            nc_max += a

    if all_negatives:
        c_max = nc_max = max(A)

    print "{0} {1}".format(c_max, nc_max)
