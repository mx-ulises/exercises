#!/bin/python

class Tree:
    def __init__(self, data):
        self.data = data
        self.right = None
        self.left = None

def equal_trees(a, b):
    if a == None and b == None:
        return True
    if a == None and b != None:
        print "[Error] Unbalanced tree"
        return False
    if a != None and b == None:
        print "[Error] Unbalanced tree"
        return False
    if a.data != b.data:
        print "[Error] Different values"
        return False
    if not equal_trees(a.left, b.left):
        return False
    if not equal_trees(a.right, b.right):
        return False
    return True

def test(a, b, expected):
    result = equal_trees(a, b)
    print "Result: {0}, expected: {1}".format(result, expected)
    print "Test Passed: {0}".format(result == expected)
    print "==================================================="

a, b = None, None
test(a, b, True)

a = Tree(1)
test(a, b, False)
a.right = Tree(2)
a.left = Tree(3)

b = Tree(1)
test(a, b, False)
b.right = Tree(2)
test(a, b, False)
b.left = Tree(3)
test(a, b, True)

b.left = Tree(4)
test(a, b, False)

