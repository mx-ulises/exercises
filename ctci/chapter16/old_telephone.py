#!/bin/python

number_to_char = {}
number_to_char['0'] = []
number_to_char['1'] = []
number_to_char['2'] = ['a', 'b', 'c']
number_to_char['3'] = ['d', 'e', 'f']
number_to_char['4'] = ['g', 'h', 'i']
number_to_char['5'] = ['j', 'k', 'l']
number_to_char['6'] = ['m', 'n', 'o']
number_to_char['7'] = ['p', 'q', 'r', 's']
number_to_char['8'] = ['t', 'u', 'v']
number_to_char['9'] = ['w', 'x', 'y', 'z']

words = ['tree', 'used', 'uref', 'aaa', 'aaaa', 'bbb']


def get_char_to_number(number_to_char):
    char_to_number = {}
    for d in number_to_char:
        for c in number_to_char[d]:
            char_to_number[c] = d
    return char_to_number


def get_number_to_word(words, char_to_number):
    number_to_word = {}
    for word in words:
        number = []
        for c in word:
            d = char_to_number[c]
            number.append(d)
        number = int(''.join(number))
        if number not in number_to_word:
            number_to_word[number] = []
        number_to_word[number].append(word)
    return number_to_word


def query_number_to_word(number, number_to_word):
    if number in number_to_word:
        return number_to_word[number]
    return []


char_to_number = get_char_to_number(number_to_char)
number_to_word = get_number_to_word(words, char_to_number)

print query_number_to_word(8733, number_to_word)
print query_number_to_word(1, number_to_word)
print query_number_to_word(222, number_to_word)
print query_number_to_word(2222, number_to_word)
