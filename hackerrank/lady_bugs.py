#!/bin/python

def already_happy(n, lady_bugs):
    for i in xrange(n):
        lady_bug = lady_bugs[i]
        if lady_bug == "_":
            continue
        if 0 < i and lady_bugs[i] == lady_bugs[i - 1]:
            continue
        if  i < (n - 1) and lady_bugs[i] == lady_bugs[i + 1]:
            continue
        return False
    return True

def is_happy(n, lady_bugs):
    if already_happy(n, lady_bugs):
        return True
    lady_bug_count = {}
    for lady_bug in lady_bugs:
        if lady_bug not in lady_bug_count:
            lady_bug_count[lady_bug] = 0
        lady_bug_count[lady_bug] += 1
    if "_" not in lady_bug_count:
        return False
    for lady_bug in lady_bug_count:
        if lady_bug_count[lady_bug] == 1 and lady_bug != "_":
            return False
    return True

g = int(raw_input())

for _ in xrange(g):
    n = int(raw_input())
    lady_bugs = list(raw_input())
    if is_happy(n, lady_bugs):
        print "YES"
    else:
        print "NO"
