#!/bin/python

def string_rotation(s_1, s_2):
    if len(s_1) != len(s_2):
        return False
    s_full = "{0}{1}".format(s_2, s_2)
    return (s_1 in s_full)


def test(s_1, s_2):
    print "========================================="
    print "Original String: '{0}'".format(s_1)
    print "Rotated String: '{0}'".format(s_2)
    print "Is rotation: '{0}'".format(string_rotation(s_1, s_2))

# Positive
test("waterbottle", "bottlewater")
test("aaaaaa", "aaaaaa")
test("baaaaaa", "aaaaaab")
test("", "")

# Nrgative
test("waterbottle", "bottlowater")
test("waterbottle", "bottlwater")
test("waterbottle", "waterwaterb")
test("", "asdas")
test("xasd", "")
