#!/bin/python

import random

def get_random(node):
    if node.n == 1:
        return node
    else:
        x = random.randint(1, node.n)
        if x == 1:
            return node
        elif 1 < x <= (node.right.n + 1):
            return get_random(node.right)
        else:
            return get_random(node.left)
