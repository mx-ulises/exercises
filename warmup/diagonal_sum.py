#!/bin/python

input_lines = """3
11 2 4
4 5 6
10 8 -12
""".splitlines()

n = int(input_lines[0])

diag_1 = 0
diag_2 = 0

for i in xrange(n):
    row = [int(x) for x in input_lines[i + 1].split(' ')]
    diag_1 += row[i]
    diag_2 += row[n - i - 1]

print abs(diag_1 - diag_2)
