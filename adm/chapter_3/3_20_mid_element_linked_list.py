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
    head = LinkedList(0)
    node = head
    for i in xrange(1, n):
        node.next = LinkedList(i)
        node = node.next
    return head

# Algorithm
def mid_element_linked_list(head):
    curr = head
    runner = head
    while runner != None and runner.next != None:
        curr = curr.next
        runner = runner.next.next
    return curr
    
# Test utility
def test(n):
    print "==============================================="
    head = create_list(n)
    mid = mid_element_linked_list(head)
    print "Size: {0}".format(n)
    if mid:
        print "Mid: {0}".format(mid.data)

# Test cases
test(0)
test(1)
test(2)
test(3)
test(2)
test(5)
test(10)
