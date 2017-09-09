"""
Node is defined as
self.left (the left child of the node)
self.right (the right child of the node)
self.data (the value of the node)
"""
def pre_order(node):
    if not node: return ""
    else: return "{0} ".format(node.data) + pre_order(node.left) + pre_order(node.right)

def preOrder(root):
    print pre_order(root)
