#!/bin/python

def validate_bst(root):
    if not root:
        return True
    left = True
    if root.left:
        left = (root.left.data <= root.data) and validate_bst(root.left)
    right = True
    if root.right:
        right = (root.right.data > root.data) and validate_bst(root.right)
    return (left and right)
