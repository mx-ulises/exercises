#!/bin/python

input_string = """11
middle-Outz
2
""".splitlines()

n = int(input_string[0])
original = input_string[1]
k = int(input_string[2])

encrypted = ""

def get_crypt_char(c):
    if 'a' <= c <= 'z':
        value = (ord(c) + k - ord('a')) % 26
        return chr(value + ord('a'))
    elif 'A' <= c <= 'Z':
        value = (ord(c) + k - ord('A')) % 26
        return chr(value + ord('A'))
    else:
        return c

for c in original:
    encrypted += get_crypt_char(c)

print encrypted
