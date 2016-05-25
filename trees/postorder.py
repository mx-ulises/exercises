"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.data (the value of the node)
"""

def post_order(node):
    if not node: return ""
    else: return post_order(node.left) + post_order(node.right) + "{0} ".format(node.data)

def postOrder(root):
    print post_order(root)
