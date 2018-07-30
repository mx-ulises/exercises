#!/bin/python

def put_space(s, m):
    s[m] = '0'
    s[m - 1] = '2'
    s[m - 2] = '%'
    return s


def urlify(s, n):
    m = len(s) - 1
    for i in xrange(n):
        j = n - i - 1
        if s[j] == ' ':
            s = put_space(s, m)
            m -= 3
        else:
            s[m] = s[j]
            m -= 1
    return s


def count_spaces(s):
    total = 0
    for c in s:
        if c == ' ':
            total += 1
    return total

def test(s):
    print "=========================="
    n = len(s)
    print "test string: '{0}', lenght: '{1}'".format(s, n)
    s_list = list(s)
    s_list.extend([' '] * (2 * count_spaces(s)))
    s_result = ''.join(urlify(s_list, n))
    print "result: '{0}', len {1}".format(s_result, len(s_result))


test("mr john smith")
test("mr john smith ")
test("    ")
