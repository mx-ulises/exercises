#!/bin/python

def reduce_str(s):
    t = []
    for c in s:
        if not t or t[-1] != c:
            t.append(c)
        else:
            t.pop()
    return "".join(t)

s = raw_input()
t = reduce_str(s)

if t == "":
    t = "Empty String"

print t
