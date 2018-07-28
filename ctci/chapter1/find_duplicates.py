#!/bin/python

def find_duplicates_mem(s):
    character_buffer = {}
    for c in s:
        if c in character_buffer:
            print "Character '{0}' is in string more than once".format(c)
            return False
        character_buffer[c] = True
    print "No repeated characters"
    return True


def find_duplicates_no_mem(s):
    s_list = list(s)
    s_list.sort()
    n = len(s_list)
    for i in xrange(1, n):
        if s_list[i - 1] == s_list[i]:
            print "Character '{0}' is in string more than once".format(s_list[i])
            return False
    print "No repeated characters"
    return True

def test_case(s):
    print "======================================"
    print "Testing string '{0}'".format(s)
    result = find_duplicates_mem(s)
    print "Test with memory: '{0}'".format(result)
    result = find_duplicates_no_mem(s)
    print "Test with no memory: '{0}'".format(result)
    

test_case("abcdefg")
test_case("")
test_case("a")
test_case("zyxw")
test_case("aA")
test_case("hola munde")

test_case("aaaaaaaaa")
test_case("hola mundo")
test_case("abbbb")
test_case("abghjyeb")
