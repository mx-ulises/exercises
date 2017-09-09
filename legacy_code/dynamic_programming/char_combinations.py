#!/bin/python

from sets import Set

VALID_NUMS = {str(i + 1): chr(97 + i) for i in xrange(26)}

def get_char(n_1, n_2 = ""):
    num = n_1 + n_2
    if num in VALID_NUMS:
        return VALID_NUMS[num]
    return None


# Get all combinations
def get_char_comb(num):
    num = list(num)
    c = get_char(num[0])
    prefix = [c]
    prev_prefix = [""]
    for i in xrange(1, len(num)):
        c = get_char(num[i])
        new_prefix = []
        for w in prefix:
            new_prefix.append(w + c)
        c = get_char(num[i - 1], num[i])
        if c:
            for w in prev_prefix:
                new_prefix.append(w + c)
        prev_prefix = prefix
        prefix = new_prefix
    return prefix

def get_comb(num):
    if num <= 0:
        return []
    return get_char_comb(str(num))


# Just get the num of combinations
def get_char_comb_2(num):
    num = list(num)
    c = get_char(num[0])
    prefix = 1
    prev_prefix = 1
    for i in xrange(1, len(num)):
        c = get_char(num[i])
        new_prefix = prefix
        c = get_char(num[i - 1], num[i])
        if c:
            new_prefix += prev_prefix
        prev_prefix = prefix
        prefix = new_prefix
    return prefix

def get_comb_2(num):
    if num <= 0:
        return []
    return get_char_comb_2(str(num))
