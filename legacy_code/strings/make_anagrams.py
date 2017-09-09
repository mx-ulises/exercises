#!/bin/python

input_str = """cde
abc
""".splitlines()

def get_word_count(w):
    w_count = {chr(x): 0 for x in range(ord('a'), ord('z') + 1)}
    for c in w:
        w_count[c] += 1
    return w_count

w1_count = get_word_count(input_str.pop(0))
w2_count = get_word_count(input_str.pop(0))

total = 0
for c in w1_count:
    total += abs(w1_count[c] - w2_count[c])

print total
