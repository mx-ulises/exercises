#!/bin/python
from linked_list import create_list, print_list, print_separator, N

def delete_dups_buffer(root):
    if not root:
        return None
    node = root.next
    prev = root
    unique_nodes = {root.value: True}
    while node:
        if node.value not in unique_nodes:
            unique_nodes[node.value] = True
            prev = node
        else:
            prev.next = node.next
        node = node.next
    return root

def delete_dups_no_buffer(root):
    node = root
    while node:
        node_1 = node.next
        prev = node
        while node_1:
            if node.value == node_1.value:
                prev.next = node_1.next
            else:
                prev = node_1
            node_1 = node_1.next
        node = node.next
    return root

print "REMOVE DUPS"
print_separator()

print "With Buffer"
root = create_list(N)
print print_list(root)
root = delete_dups_buffer(root)
print print_list(root)
print_separator()

print "With No Buffer"
root = create_list(N)
print print_list(root)
root = delete_dups_no_buffer(root)
print print_list(root)
print_separator()
