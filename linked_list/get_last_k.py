#!/bin/python
from linked_list import create_list, print_list, print_separator, N

def get_last_k(root, k):
    n = 0
    node = root
    while node:
        node = node.next
        n += 1
    node = root
    for _ in xrange(n - k):
        node = node.next
    return node

print "GET LAST K"
root = create_list(N)
print print_list(root)
print get_last_k(root, 1).value
print get_last_k(root, 2).value
print get_last_k(root, 3).value
print_separator()
