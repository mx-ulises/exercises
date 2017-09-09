#!/bin/python

from trees.preorder import pre_order

def check_subtree(root_1, root_2):
    node = root_2
    while node:
        if node == root_1:
            return True
        node = node.parent
    return False


def check_subtree_2(root_1, root_2):
    Open = [root_1]
    while Open:
        node = Open.pop(0)
        if node == root_2:
            return True
        if node.right:
            Open.append(node.right)
        if node.left:
            Open.append(node.left)
    return False


def check_subtree_3(root_1, root_2):
    str_1 = pre_order(root_1)
    str_2 = pre_order(root_2)
    return str_2 in str_1
