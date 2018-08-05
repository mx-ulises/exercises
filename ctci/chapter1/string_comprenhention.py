#!/bin/python

def string_compression_algorithm(s):
    if s == "":
        return ""
    s_out = []
    c_current = s[0]
    c_count = 1
    for i in xrange(1, len(s)):
        c = s[i]
        if c_current == c:
            c_count += 1
        else:
            if c_count < 2:
                s_out.append(c_current)
            else:
                c_compression = "{0}{1}".format(c_current, c_count)
                s_out.append(c_compression)
            c_count = 1
            c_current = c
    if c_count < 2:
        s_out.append(c_current)
    else:
        c_compression = "{0}{1}".format(c_current, c_count)
        s_out.append(c_compression)
    s_out = "".join(s_out)
    return s_out


def test(s):
    print "======================================"
    print "Current: '{0}'".format(s)
    print "Result:  '{0}'".format(string_compression_algorithm(s))


test("aaaab")
test("abc")
test("a")
test("")
test("aaaaaaaaaabbbbbbbbbb")
test("aabbccdd")
