#!/bin/python

n = int(raw_input())
s = raw_input()

def get_spss(i, n, s):
    j = 1
    c = -1
    while 0 <= (i - j) and (i + j) < n:
        if c == -1:
            c = s[i - j]
        if s[i - j] != c or c != s[i + j]:
            break
        j += 1
    c = s[i]
    k = 0
    while 0 <= (i - (2 * k + 1)):
        if s[i - (2 * k)] != c or s[i - (2 * k + 1)] != c:
            break
        k += 1
    return j + k

spss_count = 0

for i in xrange(n):
    spss_count += get_spss(i, n, s)

print spss_count
