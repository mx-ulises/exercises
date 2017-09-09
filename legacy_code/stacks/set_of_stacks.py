#!/bin/python

class SetOfStacks(object):

    def __init__(self, size):
        self.size = size
        self.stacks = []


    def push(self, value):
        if not self.stacks:
            self.stacks.append([])
        if len(self.stacks[-1]) == self.size:
            self.stacks.append([])
        self.stacks[-1].append(value)


    def pop(self):
        while self.stacks and not self.stacks[-1]:
            self.stacks.pop()
        if not self.stacks:
            raise Exception("Empty Stack")
        return self.stacks[-1].pop()


    def pop_at(self, index):
        if index < 0 or len(self.stacks) <= index:
            raise Exception("Invalid index")
        elif not self.stacks[index]:
            raise Exception("Empty Stack")
        else:
            return self.stacks[index].pop()
