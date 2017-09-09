#!/bin/python

class Tree(object):

    def __init__(self, data, depth):
        self.data = data
        self.left = None
        self.right = None
        self.depth = depth

    def add(self, data):
        if data < self.data:
            if self.left:
                self.left.add(data)
            else:
                self.left = Tree(data, self.depth + 1)
        else:
            if self.right:
                self.right.add(data)
            else:
                self.right = Tree(data, self.depth + 1)

def balanced_tree(A):
    tree = None
    s = (0, len(A) - 1)
    queue = [s]
    counter = 0
    while queue:
        counter += 1
        i, j = queue.pop(0)
        k = (i + j) / 2
        a = A[k]
        if i < k:
            s_1 = (i, k - 1)
            queue.append(s_1)
        if k < j:
            s_2 = (k + 1, j)
            queue.append(s_2)
        if tree:
            tree.add(a)
        else:
            tree = Tree(a, 0)

balanced_tree(range(4))
