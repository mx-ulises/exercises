from operator import xor

R = 15
L = 10

numbers = range(L, R + 1)
and_mask = reduce(lambda x, y: x & y, numbers)
or_mask = reduce(lambda x, y: x | y, numbers)

print xor(and_mask, or_mask)
