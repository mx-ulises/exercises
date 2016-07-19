#!/bin/python

class QueueStack(object):

    def __init__(self):
        self.enq = []
        self.deq = []

    def enqueue(self, value):
        while self.deq:
            self.enq.append(self.deq.pop())
        self.enq.append(value)


    def dequeue(self):
        while self.enq:
            self.deq.append(self.enq.pop())
        if self.deq:
            return self.deq.pop()
        raise Exception("Empty queue")
