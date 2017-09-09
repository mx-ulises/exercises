#!/bin/python

def get_char_map(s):
    char_map = {chr(i): 0 for i in xrange(ord('a'), ord('z') + 1)}
    for i in xrange(len(s)):
        c = s[i]
        char_map[c] += 1
    return char_map

def check_one_way(s_1, s_2):
    n_1 = len(s_1)
    n_2 = len(s_2)
    delta = abs(n_1 - n_2)
    if delta > 2:
        return False
    delta = 2 - delta

    char_map_1 = get_char_map(s_1)
    char_map_2 = get_char_map(s_2)

    for c in char_map_1:
        delta -= abs(char_map_1[c] - char_map_2[c])

    if delta < 0:
        return False
    return True

print check_one_way("", "")
print check_one_way("pale", "pale")
print check_one_way("bale", "pale")
print check_one_way("pales", "pale")
print check_one_way("bales", "pale")
print check_one_way("xxxx", "yyyy")
print check_one_way("xxxx", "yy")
