#!/bin/python

def check_palindrome_permutation(s):
    char_count = {}
    for c in s:
        if c not in char_count:
            char_count[c] = 0
        char_count[c] += 1
    acceptable_odd = 1
    for c in char_count:
        if char_count[c] % 2 == 1:
            acceptable_odd -= 1
    if acceptable_odd < 0:
        return False
    return True

def test(s):
    print "========================================"
    print "Test string: '{0}'".format(s)
    print "Result: {0}".format(check_palindrome_permutation(s))



# Positive
test("tacacot")
test("")
test("o")
test("ooo")
test("anitalavalatina")
test("tacocat")
test("aabb")

# Negative
test("aaab")
test("taco cat")
test("abcde")
test("123")
test("tacocat1")
