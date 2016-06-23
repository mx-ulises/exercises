#!/bin/python
from linked_list import LinkedList, print_list, print_separator

def create_list(array_list):
    root = None
    node = root
    for a in array_list:
        if node:
            node.add(a)
            node = node.next
        else:
            root = LinkedList(a)
            node = root
    return root

def check_palindrome(root):
    if root:
        return root.palindrome([])
    else:
        return True

print "LIST PALINDROME"
print_separator()

root = create_list([1, 2, 3, 2, 1])
print print_list(root)
print check_palindrome(root)
print_separator()

root = create_list([1, 2, 3, 2])
print print_list(root)
print check_palindrome(root)
print_separator()

root = create_list([])
print print_list(root)
print check_palindrome(root)
print_separator()
