#!/bin/python
class MultiStack(object):

    def __init__(self, stacks, size):
        self.heads = [-1 for _ in xrange(stacks)]
        self.a = [None for _ in xrange(size)]
        self.top = 0


    def push(self, stack, value):
        if self.top < len(self.a):
            prev = self.heads[stack]
            self.a[self.top] = (prev, value)
            self.heads[stack] = self.top
            self.top = self.get_next_empty()
        else:
            raise Exception("Full array")


    def get_next_empty(self):
        next_free = len(self.a)
        for i in xrange(self.top, len(self.a)):
            if not self.a[i]:
                next_free = i
                break
        return next_free


    def pop(self, stack):
        if self.heads[stack] >= 0:
            i = self.heads[stack]
            prev, value = self.a[i]
            self.a[i] = None
            new_top = self.heads[stack]
            self.heads[stack] = prev
            if new_top < self.top:
                self.top = new_top
            return value
        raise Exception("Empty stack")
