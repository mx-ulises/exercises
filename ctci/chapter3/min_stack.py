#!/bin/python

class MinStack:
    def __init__(self):
        self.main_stack = []
        self.min_stack = []


    def peak(self):
        return self.main_stack[-1]


    def min(self):
        return self.min_stack[-1]


    def pop(self):
        if self.min() == self.peak():
            self.min_stack.pop()
        return self.main_stack.pop()


    def push(self, x):
        if self.min_stack == [] or x <= self.min():
            self.min_stack.append(x)
        self.main_stack.append(x)


    def print_stacks(self):
        print "Main Stack: {0}".format(self.main_stack)
        print "Min Stack: {0}".format(self.min_stack)
        print "=========================================="


s = MinStack()
s.push(10)
s.print_stacks()
s.push(11)
s.print_stacks()
s.push(7)
s.print_stacks()
s.push(7)
s.print_stacks()
s.push(13)
s.print_stacks()
s.push(2)
s.print_stacks()
s.push(1)
s.print_stacks()

s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
s.push(3)
s.print_stacks()
s.push(3)
s.print_stacks()
s.push(3)
s.print_stacks()
s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
s.pop()
s.print_stacks()
