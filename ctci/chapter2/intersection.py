#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def intersecting_node(x_head, y_head):
    if x_head == None or y_head == None:
        return False
    x_last = get_last(x_head)
    y_last = get_last(y_head)
    return x_last == y_last


def get_last(head):
    last = head
    while last.next != None:
        last = last.next
    return last

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


def test(x_head, y_head):
    print "=================================="
    print_list(x_head)
    print_list(y_head)
    print "Intersecting: {0}".format(intersecting_node(x_head, y_head))

x_head = create_linked_list(range(5))
y_head = create_linked_list(range(4))
test(x_head, y_head)

test(x_head, None)
test(None, y_head)

x_last = get_last(x_head)
x_last.next = y_head
test(x_head, y_head)

x_head = create_linked_list(range(5))
y_head = create_linked_list(range(5))
z_head = create_linked_list(range(3))
x_last = get_last(x_head)
y_last = get_last(y_head)
x_last.next = z_head
y_last.next = z_head

test(x_head, y_head)
