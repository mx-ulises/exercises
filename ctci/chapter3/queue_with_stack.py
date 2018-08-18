#!/bin/python

class QueueStack:
    def __init__(self):
        self.head = []
        self.tail = []


    def enqueue(self, x):
        print "Enqueue: {0}".format(x)
        self.tail.append(x)


    def dequeue(self):
        if self.head == []:
            self.move()
        x = self.head.pop()
        print "Dequeue: {0}".format(x)
        return x


    def move(self):
        while 0 < len(self.tail):
            x = self.tail.pop()
            self.head.append(x)


q = QueueStack()
q.enqueue(1)
q.enqueue(2)
q.dequeue()
q.enqueue(3)
q.enqueue(4)
q.enqueue(5)
q.dequeue()
q.dequeue()
q.dequeue()
q.dequeue()
