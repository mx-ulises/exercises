#!/bin/python

input_string = """5
ab
bb
hefg
dhck
dkhc
""".splitlines()

def get_next(word):
    n = len(word)
    for i in range(n):
        suffix = word[n - i:]
        c = word[n - i - 1]
        suffix_swift_chars = []
        for c_i in suffix:
            if c_i > c: suffix_swift_chars += [c_i]
        if suffix_swift_chars:
            c_min = min(suffix_swift_chars)
            new_suffix = list(suffix) + [c]
            new_suffix.remove(c_min)
            new_suffix.sort()
            return word[:n - i - 1] + c_min + "".join(new_suffix)
    return "no answer"

T = int(input_string[0])
words = [input_string[i + 1] for i in range(T)]

for word in words:
    print get_next(word)
