#!/bin/python

def count_chars(s):
    map_chars = {}
    for i in xrange(len(s)):
        c = s[i]
        if c not in map_chars:
            map_chars[c] = 0
        map_chars[c] += 1
    return map_chars

def count_reps(map_chars):
    map_count = {}
    for c in (map_chars):
        n = map_chars[c]
        if n not in map_count:
            map_count[n] = 0
        map_count[n] += 1
    return map_count

def test_counts(map_count):
    keys = map_count.keys()
    if len(keys) > 2:
        return "NO"
    elif len(keys) <= 1:
        return "YES"
    elif 1 in map_count and map_count[1] == 1:
        return "YES"
    elif abs(keys[0] - keys[1]) > 1:
        return "NO"
    elif keys[0] > keys[1] and map_count[keys[0]] == 1:
        return "YES"
    elif keys[1] > keys[0] and map_count[keys[1]] == 1:
        return "YES"
    else:
        return "NO"

s = raw_input()
map_chars = count_chars(s)
map_count = count_reps(map_chars)

print test_counts(map_count)
