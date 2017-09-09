#!/bin/python

def is_balanced(node):
    if not node:
        return (True, 0)
    else:
        balanced_1, h_1 = is_balanced(node.right)
        balanced_2, h_2 = is_balanced(node.left)
        balanced = balanced_1 & balanced_2 & (abs(h_1 - h_2) <= 1)
        return (balanced, max(h_1, h_2) + 1)
