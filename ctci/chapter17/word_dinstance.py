#!/bin/python

from pprint import pprint

text = "hola mundo loco el mundo esta muy cabron y bien pinche loco y maniaco"

def get_word_positions(text):
    word_positions = {}
    words = text.split()
    for i in xrange(len(words)):
        word = words[i]
        if word not in word_positions:
            word_positions[word] = []
        word_positions[word].append(i)
    return word_positions

def word_dinstance(word_positions, word_1, word_2):
    positions_1 = word_positions[word_1]
    positions_2 = word_positions[word_2]
    minimal_distance = abs(positions_1[0] - positions_2[0])
    i = 0
    j = 0
    while i < len(positions_1) and j < len(positions_2):
        distance = abs(positions_1[i] - positions_2[j])
        minimal_distance = min(minimal_distance, distance)
        if positions_1[i] < positions_2[j]:
            i += 1
        else:
            j += 1
    return minimal_distance

word_positions = get_word_positions(text)
pprint(word_positions)
print word_dinstance(word_positions, "loco", "y")
