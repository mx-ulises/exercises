#!/bin/python

n = int(raw_input())

rock = raw_input()
gem_elements = set(list(rock))

for _ in xrange(1, n):
    rock = raw_input()
    rock_elements = set(list(rock))
    gem_elements = gem_elements & rock_elements

print len(gem_elements)
