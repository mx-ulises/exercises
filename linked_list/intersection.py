#!/bin/python
from linked_list import create_list, print_list, print_separator, N, get_random_middle, get_last, visit_list

def get_instersection(root_1, root_2):
    visit_list(root_1)
    node = root_2
    while node and not node.visited:
        node.visited
        node = node.next
    return node

print "LOOP DETECTION"
root_1 = create_list(N)
root_2 = create_list(N)
random_node = get_random_middle(root_1, N)
last_node_2 = get_last(root_2)
last_node_2.next = random_node
print print_list(root_1)
print print_list(root_2)
intersect = get_instersection(root_1, root_2)
if intersect:
    print intersect.value
else:
    print "None"
print_separator()
