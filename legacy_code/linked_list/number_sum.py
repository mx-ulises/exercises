#!/bin/python
from linked_list import create_list_2, print_list

def get_num_tail(root):
    node = root
    num_str = []
    while node:
        num_str.append(str(node.value))
        node = node.next
    num_str.reverse()
    if not num_str:
        num_str = ["0"]
    return int("".join(num_str))

def sum_lists_tail(root_1, root_2):
    num_1 = get_num_tail(root_1)
    num_2 = get_num_tail(root_2)
    num_3 = list(str(num_1 + num_2))
    num_3.reverse()
    return create_list_2(num_3)

def get_num_head(root):
    node = root
    num_str = []
    while node:
        num_str.append(str(node.value))
        node = node.next
    if not num_str:
        num_str = ["0"]
    return int("".join(num_str))

def sum_lists_head(root_1, root_2):
    num_1 = get_num_head(root_1)
    num_2 = get_num_head(root_2)
    num_3 = list(str(num_1 + num_2))
    return create_list_2(num_3)

root_1 = create_list_2(list(str(716)))
root_2 = create_list_2(list(str(592)))
print print_list(root_1)
print print_list(root_2)
print print_list(sum_lists_tail(root_1, root_2))

print ""

root_1 = create_list_2(list(str(617)))
root_2 = create_list_2(list(str(295)))
print print_list(root_1)
print print_list(root_2)
print print_list(sum_lists_head(root_1, root_2))
