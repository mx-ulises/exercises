#!/bin/python

from heapq import heappush, heappop

class MedianTracker:

    def __init__(self):
        self.smallers = []
        self.biggers = []

    def push(self, a):
        if 0 < len(self.smallers) and a < -self.smallers[0]:
            heappush(self.smallers, -a)
        else:
            heappush(self.biggers, a)
        if len(self.smallers) < len(self.biggers):
            b = heappop(self.biggers)
            heappush(self.smallers, -b)
        elif len(self.biggers) < len(self.smallers):
            b = -heappop(self.smallers)
            heappush(self.biggers, b)

    def median(self):
        if len(self.smallers) < len(self.biggers):
            return self.biggers[0]
        elif len(self.biggers) < len(self.smallers):
            return -self.smallers[0]
        else:
            return (self.biggers[0] - self.smallers[0]) / 2.0
