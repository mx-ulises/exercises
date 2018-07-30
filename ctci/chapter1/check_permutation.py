#!/bin/python

def check_permutation_no_mem(s_1, s_2):
    if (len(s_1) != len(s_2)):
        return False
    s_1_list = list(s_1)
    s_2_list = list(s_2)
    s_1_list.sort()
    s_2_list.sort()
    for i in xrange(len(s_1)):
        if s_1_list[i] != s_2_list[i]:
            return False
    return True


def check_permutation_mem(s_1, s_2):
    if (len(s_1) != len(s_2)):
        return False
    char_map = {}
    for c in s_1:
        if c not in char_map:
            char_map[c] = 0
        char_map[c] += 1
    for c in s_2:
        if c not in char_map:
            return False
        if char_map[c] == 0:
            return False
        char_map[c] -= 1
    return True


def test(s_1, s_2):
    print "====================================================="
    print "String 1: '{0}'".format(s_1)
    print "String 2: '{0}'".format(s_2)
    print "Test with no memory: {0}".format(check_permutation_no_mem(s_1, s_2))
    print "Test with memory: {0}".format(check_permutation_mem(s_1, s_2))


# Positive Scenarios
test("hola", "hola")
test("hola", "halo")
test("asdfzxcv", "zxcvasdf")
test("", "")

# Negative Scenarios
test("hola", "holo")
test("hol", "hola")
test("hola", "hol")
test("", "hola")
