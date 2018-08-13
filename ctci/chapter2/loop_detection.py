#!/bin/python

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None


def has_loop(head):
    if head == None:
        return False
    current = head
    runner = head.next
    while runner != None and runner.next != None:
        if runner == current:
            return True
        runner = runner.next.next
        current = current.next
    return False


def get_last(head):
    last = head
    while last.next != None:
        last = last.next
    return last


def get_ith(head, i):
    current = head
    while 0 < i:
        current = current.next
        i -= 1
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


def test(head):
    print "=================================="
    print "Has loop: {0}".format(has_loop(head))

head = create_linked_list(range(10))
test(head)

tail = get_last(head)
tail.next = get_ith(head, 0)
test(head)
tail.next = get_ith(head, 1)
test(head)

head = create_linked_list(range(9))
test(head)

head = create_linked_list(range(1))
test(head)
head.next = head
test(head)

head = create_linked_list(range(2))
test(head)

head = None
test(head)
