#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def remove_dup(head):
    if head == None:
        return None
    dup_list = {head.value: True}
    current = head.next
    current_no_dup = head
    while current != None:
        if current.value not in dup_list:
            dup_list[current.value] = True
            current_no_dup.next = current
            current_no_dup = current_no_dup.next
        current = current.next
    current_no_dup.next = None
    return head


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


def test(head):
    print "=================================="
    print "Before"
    print_list(head)
    print "----------------------------------"
    print "After"
    head = remove_dup(head)
    print_list(head)


head = create_linked_list([1, 2, 3, 4, 5, 6])
test(head)
head = create_linked_list([1, 1, 1, 2, 3, 3, 4, 5, 6, 7])
test(head)
head = create_linked_list([1, 2, 3, 4, 5, 6, 1, 1, 1, 2, 2, 3, 5, 7])
test(head)
head = create_linked_list([])
test(head)
head = create_linked_list([1])
test(head)
head = create_linked_list([1, 1, 1])
test(head)
