#!/bin/python

_, _ = map(int, raw_input().split())
m = raw_input().split()
n = raw_input().split()
m_frequencies = {}

for w in m:
    if w not in m_frequencies:
        m_frequencies[w] = 0
    m_frequencies[w] += 1

s_output = "Yes"
for w in n:
    if w not in m_frequencies:
        s_output = "No"
    else:
        m_frequencies[w] -= 1
        if m_frequencies[w] < 0:
            s_output = "No"

print s_output
