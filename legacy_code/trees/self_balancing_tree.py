#!/bin/python

class Tree(object):
    def __init__(self, data):
        self.data = data
        self.h = 0
        self.left = None
        self.right = None


def get_h(root):
    if root:
        return root.h
    return -1


def calculate_h(root):
    return max(get_h(root.left), get_h(root.right)) + 1


def calculate_bf(root):
    return get_h(root.left) - get_h(root.right)


def right_rotation(root):
    aux = root.right
    root.right = aux.left
    aux.left = root
    calculate_h(root)
    calculate_h(aux)
    return aux


def left_rotation(root):
    aux = root.left
    root.left = aux.right
    aux.right = root
    calculate_h(root)
    calculate_h(aux)
    return aux


def balance_tree(root):
    bf = calculate_bf(root)
    if (bf == 2):
        bf_1 = calculate_bf(root.left)
        if bf_1 == -1:
            root.left = right_rotation(root.left)
        root = left_rotation(root)
    if (bf == -2):
        bf_1 = calculate_bf(root.right)
        if bf_1 == 1:
            root.right = left_rotation(root.right)
        root = right_rotation(root)
    return root


def insert(root, data):
    if not root:
        return Tree(data)
    if data < root.data:
        root.left = insert(root.left, data)
    if root.data < data:
        root.right = insert(root.right, data)
    root.h = calculate_h(root)
    root = balance_tree(root)
    return root


def print_tree(root, span=0):
    if not root:
        return None
    s_span = ""
    for _ in xrange(span):
        s_span += " "
    print s_span + str(root.data)
    print_tree(root.left, span + 1)
    print_tree(root.right, span + 1)


def test_case(elements):
    root = None
    for data in elements:
        root = insert(root, data)
    print_tree(root)
    print "==========================="


test_case([4, 3, 5])
test_case([5, 3, 4])
test_case([5, 4, 3])
test_case([3, 5, 4])
test_case([3, 4, 5])
