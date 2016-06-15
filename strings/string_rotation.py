#!/bin/python

def is_rotation(s_1, s_2):
    n = len(s_1)
    if n != len(s_2):
        return False
    suffix = ""
    prefix = ""
    j = 0
    for i in xrange(n):
        if s_1[j] == s_2[i]:
            prefix += s_2[i]
            j += 1
        else:
            suffix += prefix
            j = 0
            prefix = ""
            if s_1[j] == s_2[i]:
                prefix += s_2[i]
                j += 1
            else:
                suffix += s_2[i]
    s_test = prefix + suffix
    return s_1 == s_test

print "\n Positive"
print is_rotation("", "")
print is_rotation("abc", "abc")
print is_rotation("bca", "abc")
print is_rotation("abcdeab", "cdeabab")

print "\n Negative"
print is_rotation("cba", "abc")
print is_rotation("xxx", "xx")
print is_rotation("xxx", "xxy")
