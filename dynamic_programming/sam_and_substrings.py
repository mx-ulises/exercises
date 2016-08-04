#!/bin/python

mod_num = 1000000007

NUMBER = raw_input()
n = len(NUMBER)
cum = 0
freq = 1
for i in xrange(n):
    j = n - i
    digit = int(NUMBER[j - 1])
    digit_sum = digit * freq * j
    cum = (cum + digit_sum) % mod_num
    freq = (freq * 10 + 1) % mod_num

print cum
