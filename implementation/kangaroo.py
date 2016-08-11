#!/bin/python
x_1, v_1, x_2, v_2 = map(int, raw_input().split())

if x_1 == x_2:
    print "YES"
elif v_1 == v_2:
    print "NO"
else:
    j = (x_1 - x_2) / (v_2 - v_1)
    k = (x_1 - x_2) % (v_2 - v_1)
    if j >= 0 and k == 0:
        print "YES"
    else:
        print "NO"
