#!/bin/python

# Linked List class
class LinkedList:
    def __init__(self, data):
        self.data = data
        self.next = None


def has_cycle(head):
    runner = head
    current = head
    while runner != None and runner.next != None:
        runner = runner.next.next
        if runner == current:
            print "Cycle found at {0}".format(runner.data)
            return True
        current = current.next
    return False

# Utility functions
def create_list(n, cycle = None):
    if n == 0:
        return None
    head = LinkedList(1)
    node = head
    cycle_node = None
    if cycle == 1:
        cycle_node = node
    for i in xrange(2, n + 1):
        node.next = LinkedList(i)
        node = node.next
        if i == cycle:
            cycle_node = node
    node.next = cycle_node
    return head



def test(n, cycle = None):
    head = create_list(n, cycle)
    print has_cycle(head)
    print "=============================="

test(10, None)
test(10, 10)
test(10, 1)
test(10, 5)
test(0, None)

