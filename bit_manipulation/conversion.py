#!/bin/python

def conversion(a, b):
    c = a ^ b
    count = 0
    while c:
        if c & 1:
            count += 1
        c = c >> 1
    return count

print conversion(0x0011, 0x1100)
print conversion(0x0011, 0x1111)
print conversion(0x1111, 0x0000)
print conversion(0x1011, 0x1101)
print conversion(0x11, 0x1100)
