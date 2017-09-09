#!/bin/python

def string_compression(s):
    if not s:
        return s

    s_out = ""
    c = s[0]
    r = 1

    for i in xrange(len(s) - 1):
        if s[i + 1] != c:
            s_out += "{0}{1}".format(c, r)
            c = s[i + 1]
            r = 0
        r += 1

    s_out += "{0}{1}".format(c, r)

    if len(s) > len(s_out):
        return s_out
    return s

print string_compression("a")
print string_compression("aaaaaaaabbc")
print string_compression("")
print string_compression("aaabbb")
print string_compression("abcd")
