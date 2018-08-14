#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def get_mid(head):
    runner = head
    current = head
    while runner != None and runner.next != None:
        runner = runner.next.next
        current = current.next
    return current


def reverse(head):
    prev = None
    current = head
    while current != None:
        aux = current.next
        current.next = prev
        prev = current
        current = aux
    return prev


def is_palindrome(head):
    mid = get_mid(head)
    mid = reverse(mid)
    current_head = head
    current_mid = mid
    while current_mid != None:
        if current_mid.value != current_head.value:
            return False
        current_mid = current_mid.next
        current_head = current_head.next
    reverse(mid)
    return True


def print_list(head):
    current = head
    while current != None:
        print "{0}".format(current.value)
        current = current.next


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


def test(head):
    print "=================================="
    print_list(head)
    print "Is palindrome: {0}".format(is_palindrome(head))


head = create_linked_list([1, 2, 3, 2, 1])
test(head)
head = create_linked_list([1, 2, 2, 1])
test(head)
head = create_linked_list([1, 2, 3, 4, 2, 1])
test(head)
head = create_linked_list([1, 2, 3, 3, 1])
test(head)
head = create_linked_list([1])
test(head)
test(None)
