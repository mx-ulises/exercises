#!/bin/python

N = 3

class TripleStack:
    def __init__(self, n):
        self.stack_size = 8
        self.stack_count = n
        self.stack = [None] * (self.stack_size * self.stack_count)
        self.pointers = [0] * self.stack_count


    def extend(self):
        new_stack = [None] * (self.stack_size * self.stack_count * 2)
        for i in xrange(self.stack_count):
            for j in xrange(self.stack_size):
                index_old = i * self.stack_size + j
                index_new = i * self.stack_size * 2 + j
                new_stack[index_new] = self.stack[index_old]
        self.stack_size = self.stack_size * 2
        self.stack = new_stack


    def push(self, stack_index, x):
        if self.pointers[stack_index] == self.stack_size:
            self.extend()
        index = self.stack_size * stack_index + self.pointers[stack_index]
        self.stack[index] = x
        self.pointers[stack_index] += 1


    def pop(self, stack_index):
        if self.pointers[stack_index] == 0:
            return None
        index = self.stack_size * stack_index + self.pointers[stack_index] - 1
        x = self.stack[index]
        self.stack[index] = None
        self.pointers[stack_index] -= 1
        return x


    def print_stacks(self):
        print "=============================================="
        stacks = [[] for _ in xrange(self.stack_count)]
        for i in xrange(self.stack_count):
            for j in xrange(self.stack_size):
                index = i * self.stack_size + j
                stacks[i].append(self.stack[index])
        for stack in stacks:
            print stack

stack = TripleStack(3)
for i in xrange(3):
    stack.push(0, i)
for i in xrange(14):
    stack.push(1, i)
for i in xrange(5):
    stack.push(2, i)

stack.pop(1)
stack.pop(2)
stack.pop(1)
stack.pop(0)

stack.print_stacks()
