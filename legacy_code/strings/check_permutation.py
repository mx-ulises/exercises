#!/bin/python

"""
Cracking the Coding Interview

Arrays and Strings

Check Permutation: Given two strings, write a method to decide if one is a
permutation of the other.
"""

def get_char_count(s):
    char_count = {}
    for i in xrange(len(s)):
        c = s[i]
        if c not in char_count:
            char_count[c] = 0
        char_count[c] += 1
    return char_count

def check_permutation(s_1, s_2):
    char_count_1 = get_char_count(s_1)
    char_count_2 = get_char_count(s_2)
    if char_count_1 == char_count_2:
        return True
    return False

# Postivie
print check_permutation("abcd", "bcad")
print check_permutation("", "")
print check_permutation("aabb", "bbaa")

#negtive
print check_permutation("abcd", "bcadx")
print check_permutation("aaaa", "aaab")
