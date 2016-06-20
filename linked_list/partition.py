#!/bin/python
from linked_list import create_list, print_list, print_separator, N

def update_list(head, tail, node):
    if not head:
        head = node
        tail = node
    else:
        tail.next = node
        tail = tail.next
    return (head, tail)

def partition(root, x):
    head = head_tail = tail = tail_tail = None
    node = root
    while node:
        if node.value < x:
            head, head_tail = update_list(head, head_tail, node)
        else:
            tail, tail_tail = update_list(tail, tail_tail, node)
        node = node.next
    # Remove tail cycle
    if tail: tail_tail.next = None

    # Merge head and tail
    if head: head_tail.next = tail
    else: head = tail

    # Exist
    return head

print "PARTITION"
x = 50
root = create_list(N)
print print_list(root)
root = partition(root, x)
print print_list(root)
print_separator()
