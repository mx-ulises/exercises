#!/bin/python
from linked_list import create_list_2

def is_palindrome(root):
    node = root
    s = []
    while node:
        s.append(node.value)
        node = node.next
    node = root
    while node:
        value = s.pop()
        if value != node.value:
            return False
        node = node.next
    return True

print is_palindrome(create_list_2(["a"]))
print is_palindrome(create_list_2([]))
print is_palindrome(create_list_2(["a", "b", "c", "b", "a"]))
print is_palindrome(create_list_2(["a", "b", "c", "b", "a", "d"]))
print is_palindrome(create_list_2(["d", "a", "b", "c", "b", "a"]))
