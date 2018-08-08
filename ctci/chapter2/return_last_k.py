#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def last_k(head, k):
    current = head
    n = 0
    while current != None:
        n += 1
        current = current.next
    current = head
    l = n - k
    if l < 0:
        return None
    while l:
        current = current.next
        l -= 1
    return current


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


def test(head, k):
    print "=================================="
    print "Before"
    print_list(head)
    print "Last '{1}': '{0}'".format(last_k(head, k).value, k)


head = create_linked_list([1, 2, 3, 4, 5, 6])
test(head, 1)
head = create_linked_list([1, 2, 3, 4, 5, 6])
test(head, 3)
head = create_linked_list([1, 2, 3, 4, 5, 6])
test(head, 6)
