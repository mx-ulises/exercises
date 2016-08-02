#!/bin/python

class QueueStack(object):

    def __init__(self):
        self.newest = []
        self.oldest = []

    def enqueue(self, data):
        self.newest.append(data)


    def _prepare_oldest(self):
        if not self.oldest:
            while self.newest:
                self.oldest.append(self.newest.pop())


    def dequeue(self):
        self._prepare_oldest()
        if self.oldest:
            return self.oldest.pop()
        raise Exception("Empty queue")


    def front(self):
        self._prepare_oldest()
        if self.oldest:
            return self.oldest[-1]
        raise Exception("Empty queue")


t = int(raw_input())
queue = QueueStack()

for _ in xrange(t):
    query = map(int, raw_input().split())
    if query[0] == 1:
        queue.enqueue(query[1])
    if query[0] == 2:
        queue.dequeue()
    if query[0] == 3:
        print queue.front()
