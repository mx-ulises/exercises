#!/bin/python

def get_left(node):
    while node.left:
        node = node.left
    return node

def get_suc(node):
    if node.right:
        return get_left(node.right)
    while node.parent:
        if node.parent.left == node:
            return node.parent
        node = node.parent
    return None
