#!/bin/python

n = float(6)
A = map(float, "-4 3 -9 0 4 1".split())

p_count, n_count, z_count = float(0), float(0), float(0)

for a in A:
    if a > 0: p_count += 1
    elif a < 0: n_count += 1
    else: z_count += 1

p_count, n_count, z_count = p_count / n, n_count / n, z_count / n
print "{0:.6f}".format(p_count)
print "{0:.6f}".format(n_count)
print "{0:.6f}".format(z_count)
