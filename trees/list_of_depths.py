#!/bin/python

class LinkedList(object):
    def __init__(self, data):
        self.data = data
        self.next = None


def append(linked_list, node):
    new_linked_list = LinkedList(node)
    if linked_list:
        new_linked_list.next = linked_list
        return new_linked_list.next
    else:
        return new_linked_list


def list_of_depths(root):
    depth = {}
    Open = [(root, 0)]
    while Open:
        node, d = Open.pop()
        if d not in depth:
            depth[d] = None
        depth[d] = append(depth[d], node)
        if node.rigth:
            Open.append((node.rigth, d + 1))
        if node.left:
            Open.append((node.left, d + 1))
    return depth
