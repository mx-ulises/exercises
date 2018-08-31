#!/bin/python

import random

class BinarySearchTree:
    def __init__(self, x):
        self.value = x
        self.parent = None
        self.left = None
        self.right = None


    def add(self, x):
        if x < self.value:
            if self.left == None:
                self.left = BinarySearchTree(x)
                self.left.parent = self
            else:
                self.left.add(x)
        elif self.value < x:
            if self.right == None:
                self.right = BinarySearchTree(x)
                self.right.parent = self
            else:
                self.right.add(x)


    def print_tree(self, padding = 0):
        padding_string = "".join([" "] * padding)
        print "{0}{1}".format(padding_string, self.value)
        if self.left != None:
            self.left.print_tree(padding + 1)
        if self.right != None:
            self.right.print_tree(padding + 1)


    def get(self, x):
        if self.value == x:
            return self
        if x < self.value and self.left != None:
            return self.left.get(x)
        if self.value < x and self.right != None:
            return self.right.get(x)
        return None


    def min(self):
        if self.left == None:
            return self
        return self.left.min()


    def max(self):
        if self.right == None:
            return self
        return self.right.max()


def succesor(node):
    if node.right != None:
        return node.right.min()
    current = node
    while current.parent != None:
        if current.parent.left == current:
            return current.parent
        current = current.parent
    if current.parent == None:
        return None


def test(root, x):
    special_node = root.get(x)
    print "=================="
    succesor_node = succesor(special_node)
    if succesor_node != None:
        print "{0} -> {1}".format(x, succesor_node.value)
    else:
        print "{0} -> {1}".format(x, None)


N = 15
root_x = [random.randint(1, 100) for _ in xrange(N)]
root = BinarySearchTree(root_x[0])
for i in xrange(1, N):
    x = root_x[i]
    root.add(x)

root_x.sort()
print root_x
print "===================================="
root.print_tree()
for x in root_x:
    test(root, x)
