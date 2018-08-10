#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def get_num(head):
    current = head
    num = 0
    i = 1
    while current != None:
        num = num + (current.value * i)
        i = i * 10
        current = current.next
    return num


def sum_lists(x_head, y_head):
    x = get_num(x_head)
    y = get_num(y_head)
    z = x + y
    n = z % 10
    z_head = Node(n)
    current = z_head
    z = z / 10
    while 0 < z:
        n = z % 10
        z = z / 10
        current.next = Node(n)
        current = current.next
    return z_head

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


def test(x, y):
    print "========================================="
    print "x: {0}".format(x)
    X = [int(c) for c in str(x)]
    X.reverse()
    x_head = create_linked_list(X)
    print_list(x_head)
    print "y: {0}".format(y)
    Y = [int(c) for c in str(y)]
    Y.reverse()
    y_head = create_linked_list(Y)
    print_list(y_head)
    z_head = sum_lists(x_head, y_head)
    print "z: {0}".format(get_num(z_head))
    print_list(z_head)

test(617, 295)
