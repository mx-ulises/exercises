#!/bin/python

# ConstantList class
class ConstantList:
    def __init__(self, n):
        self.list = [None] * n

    def insert(self, element):
        x, data = element
        self.list[x] = data

    def delete(self, element):
        x, _ = element
        self.list[x] = None

    def search(self, element):
        x, _ = element
        return x, self.list[x]

    def size(self):
        return len(self.list)


def print_list(constant_list):
    n = constant_list.size()
    for i in xrange(n):
        _, data = constant_list.search((i, None))
        if data:
            print data

# Test Function
def add_and_print(constant_list, x):
    data = str(x) * 5
    print "Adding {0} at element {1}".format(data, x)
    element = x, data
    constant_list.insert(element)
    print_list(constant_list)
    print "========================================"

# Test cases
constant_list = ConstantList(10)
add_and_print(constant_list, 3)
add_and_print(constant_list, 9)
add_and_print(constant_list, 1)
add_and_print(constant_list, 2)
add_and_print(constant_list, 3)
add_and_print(constant_list, 8)
add_and_print(constant_list, 5)
