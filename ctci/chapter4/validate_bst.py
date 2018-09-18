#!/bin/python

class Tree:
    def __init__(self, x):
        self.value = x
        self.parent = None
        self.left = None
        self.right = None

    def print_tree(self, padding = 0):
        padding_string = "".join([" "] * padding)
        print "{0}{1}".format(padding_string, self.value)
        if self.left != None:
            self.left.print_tree(padding + 1)
        if self.right != None:
            self.right.print_tree(padding + 1)

def is_bst(root, minimal = 0, maximal = 100):
    # Base case (empty tree)
    if root == None:
        return True

    # Validate current node
    if root.value <= minimal:
        return False
    if maximal <= root.value:
        return False

    # Validate left
    if not is_bst(root.left, minimal=minimal, maximal=root.value):
        return False

    # Validate right
    if not is_bst(root.right, minimal=root.value, maximal=maximal):
        return False

    return True

def test(root):
    print "============================================"
    root.print_tree()
    print "Result: {0}".format(is_bst(root))


root = Tree(5)
test(root)

root.left = Tree(2)
root.right = Tree(8)
test(root)

root.right = None
test(root)

root.right = Tree(8)
root.right.left = Tree(7)
test(root)

root.right = Tree(8)
root.right.left = Tree(3)
test(root)
