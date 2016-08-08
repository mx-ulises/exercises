#!/bin/python

L = {0: [[]]}

def add_value(x, p):
    if x not in L:
        L[x] = []
    L[x].append(p)

def get_paths(root, prefixes):
    add_value(root.data, [root.data])
    prefixes_2 = [[root.data]]
    for p in prefixes:
        p_1 = list(p).append(root.data)
        x = sum(p_1)
        add_value(x, p_1)
        prefixes_2.append(p_1)
    if root.left:
        get_paths(root.left, prefixes_2)
    if root.right:
        get_paths(root.right, prefixes_2)

def get_paths_k(root, k):
    return get_paths(root, [])[k]
