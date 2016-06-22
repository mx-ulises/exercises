#!/bin/python

def check_palindrome(s):
    n = len(s)
    for i in xrange(n / 2):
        if s[i] != s[n - 1 - i]:
            return False
    return True

t = int(raw_input())
for _ in xrange(t):
    s = raw_input()
    if check_palindrome(s):
        print "-1"
        continue
    n = len(s)
    for i in xrange(n / 2):
        j = n - 1 - i
        if s[i] != s[j]:
            if check_palindrome(s[:i] + s[i + 1:]):
                print i
            elif check_palindrome(s[:j] + s[j + 1:]):
                print j
            else:
                print "-1"
            break
