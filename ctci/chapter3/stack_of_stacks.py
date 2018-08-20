#!/bin/python

class StackOfStacks:
    def __init__(self, size):
        self.stacks = []
        self.size = size


    def push(self, x):
        if self.stacks == []:
            self.stacks.append([])
        if len(self.stacks[-1]) == self.size:
            self.stacks.append([])
        self.stacks[-1].append(x)


    def pop(self):
        while self.stacks[-1] == []:
            self.stacks.pop()
        x = self.stacks[-1].pop()
        return x


    def pop_at(self, i):
        while self.stacks[i] == []:
            self.stacks.pop(i)
        x = self.stacks[i].pop()
        return x


    def print_stacks(self):
        print "=================================="
        for s in self.stacks:
            print "{0}".format(s)


s = StackOfStacks(5)

for i in xrange(26):
    s.push(i)

s.print_stacks()
print "====================================="
for _ in xrange(10):
    print s.pop()

s.print_stacks()

print "'===================================="
for i in xrange(4):
    print s.pop_at(i)

s.print_stacks()

print "'===================================="
for _ in xrange(4):
    print s.pop_at(1)

s.print_stacks()

print "'===================================="
for _ in xrange(5):
    print s.pop()

s.print_stacks()
