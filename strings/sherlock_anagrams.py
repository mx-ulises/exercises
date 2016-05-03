#!/bin/python

input_str = """5
ifailuhkqq
hucpoltgty
ovarjsnrbf
pvmupwjjjf
iwwhrlkpek
""".splitlines()

def get_combs(n):
    return (n + 1) * n / 2

n = int(input_str.pop(0))
for _ in range(n):
    w = input_str.pop(0)
    m = len(w)
    a_count = {}
    for i in range(m):
        for j in range(m - i):
            w1 = w[i:i + j + 1]
            w1_array = [x for x in w1]
            w1_array.sort()
            anagram = "".join(w1_array)
            if anagram not in a_count:
                a_count[anagram] = 0
            a_count[anagram] += 1
    total = 0
    for anagram in a_count:
        if a_count[anagram] > 1:
            total += get_combs(a_count[anagram] - 1)
    print total
