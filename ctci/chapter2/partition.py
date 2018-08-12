#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def partition(head, x):
    left = None
    right = None
    current = head
    while current != None:
        next = current.next
        if current.value < x:
            current.next = left
            left = current
        else:
            current.next = right
            right = current
        current = next
    if left == None:
        return right
    left_last = get_last(left)
    left_last.next = right
    return left


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


def test(head, x):
    print "=================================="
    print_list(head)
    print "Partition over: {0}".format(x)
    head = partition(head, x)
    print_list(head)

A = [3, 5, 8, 5, 10, 2, 1]
head = create_linked_list(A)
test(head, 5)

A = [3, 5, 8, 5, 10, 2, 1]
head = create_linked_list(A)
test(head, 3)

A = [3, 5, 8, 5, 10, 2, 1]
head = create_linked_list(A)
test(head, 0)

A = [3, 5, 8, 5, 10, 2, 1]
head = create_linked_list(A)
test(head, 100)
