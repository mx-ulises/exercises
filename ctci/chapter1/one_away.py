#!/bin/python

def one_away(s_1, s_2):
    s_count = {}
    for c in s_1:
        if c not in s_count:
            s_count[c] = 0
        s_count[c] += 1
    for c in s_2:
        if c not in s_count:
            s_count[c] = 0
        s_count[c] -= 1
    diff = sum([abs(v) for v in s_count.values()])
    if len(s_1) == len(s_2) and abs(diff) == 2:
        return True
    if abs(diff) <= 1:
        return True
    return False


def test(s_1, s_2):
    print "========================================="
    print "String 1: '{0}'".format(s_1)
    print "String 2: '{0}'".format(s_2)
    print "Diff: {0}".format(one_away(s_1, s_2))


test("hola", "hol")
test("hol", "hola")
test("hola", "hola")
test("hola", "holo")
test("", "")

test("hala", "holo")
test("hola", "ho")
test("yyyy", "xxxx")
