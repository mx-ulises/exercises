#!/bin/python

def get_num_trees(n):
    num_trees = [0] * (n + 1)
    num_trees[0] = 1
    for i in xrange(1, n + 1):
        current_tree = 0
        for j in xrange(i):
            current_tree += num_trees[j] * num_trees[i - j - 1]
        num_trees[i] = current_tree
    return num_trees[n]

print get_num_trees(3)
print get_num_trees(4)
print get_num_trees(5)
