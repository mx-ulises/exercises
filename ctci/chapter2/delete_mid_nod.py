#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def delete_mid_node(x):
    if x.next == None:
        return
    x.value = x.next.value
    x.next = x.next.next


def create_linked_list(A):
    if A == []:
        return None
    x = A.pop(0)
    head = Node(x)
    current = head
    while A:
        x = A.pop(0)
        current.next = Node(x)
        current = current.next
    return head


def print_list(head):
    current = head
    while current != None:
        print "{0}".format(current.value)
        current = current.next


def get_node(head, x):
    current = head
    i = 0
    while i < x:
        current = current.next
        i += 1
    return current


def test(n, x):
    print "========================================="
    head = create_linked_list(range(n))
    print_list(head)
    print "Delete node '{0}'".format(x)
    delete_mid_node(get_node(head, x))
    print_list(head)


test(10, 3)
test(3, 1)
test(3, 2)
