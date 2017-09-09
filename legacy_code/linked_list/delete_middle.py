#!/bin/python
import random
from linked_list import create_list, print_list, print_separator, N

def get_random_middle(root, n):
    if n <= 2:
        return None
    m = random.randint(0, n - 3)
    node = root.next
    for _ in xrange(m):
        node = node.next
    return node

def delete_middle(node):
    node.value = node.next.value
    node.next = node.next.next


print "DELETE MIDDLE"
root = create_list(N)
print print_list(root)
node = get_random_middle(root, N)
print node.value
delete_middle(node)
print print_list(root)
print_separator()
