#!/bin/python
from linked_list import create_list, print_list, print_separator, N, get_random_middle, get_last

def detect_loop(root):
    node = root
    prev = None
    while not node.visited:
        node.visited = True
        prev = node
        node = node.next
    return prev

print "LOOP DETECTION"
root = create_list(N)
random_node = get_random_middle(root, N)
last_node = get_last(root)
last_node.next = random_node
last_loop_node = detect_loop(root)
print "Last Loop Node: {0}".format(last_loop_node.value)
print "First Loop Node: {0}".format(last_loop_node.next.value)
print "Rand Node: {0}".format(random_node.value)
last_node.next = None
print print_list(root)
print_separator()
