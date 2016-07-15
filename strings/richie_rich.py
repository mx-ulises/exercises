#!/bin/python
from sets import Set

n, k = map(int, raw_input().split())
number = map(int, list(raw_input()))

changed = Set([])

for i in xrange(n / 2):
    j = n - i - 1
    a, b = number[i], number[j]
    if a < b:
        number[i] = b
        changed.add(i)
    if b < a:
        number[j] = a
        changed.add(j)
    if a != b:
        k -= 1

for i in xrange(n / 2):
    j = n - i - 1
    if number[i] < 9:
        if (i in changed or j in changed) and k >= 1:
            number[i] = number[j] = 9
            k -= 1
        elif k >= 2:
            number[i] = number[j] = 9
            k -= 2

if k > 0 and number[n / 2] < 9:
    number[n / 2] = 9

number = "".join(map(str, number))
if k < 0:
    number = "-1"

print number
