#!/bin/python

# Linked List class
class LinkedList:
    def __init__(self, data):
        self.data = data
        self.next = None

# Utility functions
def create_list(n):
    if n == 0:
        return None
    head = LinkedList(1)
    node = head
    for i in xrange(2, n + 1):
        node.next = LinkedList(i)
        node = node.next
    return head

def print_list(head):
    node = head
    while node != None:
        print node.data
        node = node.next

# Algorithm
def reverse_linked_list(head):
    # Base case, no list
    if head == None:
        return None

    # Define arrays
    prev = None
    curr = head
    next = curr.next
    while curr != None:
        next = curr.next
        curr.next = prev
        prev = curr
        curr = next
        
    return prev
    
# Test utility
def test(n):
    print "==============================================="
    head = create_list(n)
    head = reverse_linked_list(head)
    print_list(head)

# Test cases
test(0)
test(1)
test(2)
test(5)
test(10)
