#!/bin/python

def is_contained(magazine, word):
    magazine_count = {}
    for c in magazine:
        if c not in magazine_count:
            magazine_count[c] = 0
        magazine_count[c] += 1
    for c in word:
        if c not in magazine_count:
            return False
        if magazine_count[c] == 0:
            return False
        magazine_count[c] -= 1
    return True

def test(magazine, word):
    print "Magazine: '{0}'".format(magazine)
    print "Word: '{0}'".format(word)
    print "Is contained: {0}".format(is_contained(magazine, word))
    print ""

test("hello world", "hello")
test("hello world", "hellow")
test("hello world", "hellox")
test("hello world", "hello world 2")
