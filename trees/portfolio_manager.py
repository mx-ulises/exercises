#!/bin/python

# Constant Definitions
INPUT_FILE = open('input_1.txt', 'r')
MAX_CHILDS = xrange(2)

# Tree class with needed methods
class Tree():
    def __init__(self, value):
        self.value = value
        self.childs = []

    def get_max(self, best_invest):
        if self.value == "#":
            return (0, 0)
        else:
            with_self = int(self.value)
            with_no_self = 0
            for child in self.childs:
                with_no_child, with_child = best_invest[child]
                with_no_self += max(with_no_child, with_child)
                with_self += with_no_child
            return (with_no_self, with_self)

# Read input file
_ = INPUT_FILE.readline()
A = INPUT_FILE.readline().split()

# Initioal processing
a_i = 1
n = len(A)
root = Tree(A[0])
T = [root]

# Create the Tree
for t_i in xrange(n):
    node = T[t_i]
    if node.value != "#":
        for _ in MAX_CHILDS:
            if a_i < n:
                new_value = A[a_i]
                a_i += 1
                child = Tree(new_value)
                node.childs.append(child)
                T.append(child)
            else:
                break

# Calculate best invest in bottom-up fashion
best_invest = {}
for i in xrange(n):
    node = T[n - 1 - i]
    best_invest[node] = node.get_max(best_invest)

# Print best invest
print max(best_invest[root])
