#!/bin/python

def print_combs(coins, max_num):
    checker = [False] * (max_num + 1)
    checker[coins[0]] = True
    checker[coins[1]] = True
    checker[coins[2]] = True
    for n in xrange(max_num + 1):
        if checker[n]:
            print n
            if (n + coins[0]) <= max_num:
                checker[n + coins[0]] = True
            if (n + coins[1]) <= max_num:
                checker[n + coins[1]] = True
            if (n + coins[2]) <= max_num:
                checker[n + coins[2]] = True

coins = [10, 15, 55]
max_num = 1000

print_combs(coins, max_num)
