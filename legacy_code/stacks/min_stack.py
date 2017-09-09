#!/bin/python
class MinStack(object):

    def __init__(self):
        self.stack = []
        self.min_stack = []


    def top(self):
        if self.stack:
            return self.stack[-1]
        else:
            raise Exception("Empty stack")


    def min(self):
        if self.min_stack:
            return self.min_stack[-1]
        else:
            raise Exception("Empty stack")


    def push(self, value):
        self.stack.append(value)
        if not self.min_stack or value <= self.min_stack[-1]:
            self.min_stack.append(value)


    def pop(self):
        value = self.stack.pop()
        if value <= self.min_stack[-1]:
            self.min_stack.pop()
