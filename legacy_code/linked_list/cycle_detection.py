#!/bin/python

from sets import Set

def has_cycle(head):
    visited = Set()
    node = head
    cycle = False
    while node:
        if node in visited:
            cycle = True
            break
        visited.add(node)
        node = node.next
    return cycle
