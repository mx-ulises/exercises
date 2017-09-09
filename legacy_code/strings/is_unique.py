#!/bin/python

"""
Cracking the Coding Interview

Arrays and Strings

Is Unique: Implement an algorithm to determine if a string has all unique
characters. What if you cannot use additional data structures?
"""

def unique_hash(s):
    chars_map = {}
    for i in xrange(len(s)):
        if s[i] in chars_map:
            return False
        chars_map[s[i]] = True
    return True

def unique_array(s):
    char_array = [False for _ in xrange(128)]
    for i in xrange(len(s)):
        key = ord(s[i])
        if char_array[key]:
            return False
        char_array[key] = True
    return True

# Positive
print unique_hash("abc")
print unique_hash("a")
print unique_hash("az")
print unique_hash("abcdefghijklmnopqrstuvwxyz")
print unique_hash("")

# Negative
print unique_hash("aa")
print unique_hash("aza")
print unique_hash("azz")
print unique_hash("abcdefghijklmnopqrstuvwxyza")
