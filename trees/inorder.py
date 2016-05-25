"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.data (the value of the node)
"""

def in_order(node):
    if not node: return ""
    else: return in_order(node.left) + "{0} ".format(node.data) + in_order(node.right)

def inOrder(root):
    print in_order(root)
