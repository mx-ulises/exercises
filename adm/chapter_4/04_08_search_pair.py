#!/bin/python

def search_pair(X, x):
    X.sort()
    l = 0
    r = len(X) - 1
    while l < r:
        y = X[l] + X[r]
        if y < x:
            l += 1
        elif x < y:
            r -= 1
        else:
            return (X[l], X[r])
    return None

def test(X, x):
    print "Find match: {0}".format(x)
    print X
    print "Pair found is {0}".format(search_pair(X, x))
    print "============================================="

X= [8, 1, 2, 14, 24]
test(X, 1)
test(X, 10)
test(X, 9)
test(X, 16)
test(X, 22)
test(X, 17)
