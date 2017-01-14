#!/bin/python

from heapq import heappush, heappop, heapify

p, n = map(int, raw_input().split())
jobs = map(int, raw_input().split())

processors = [i for i in xrange(p)]
heapify(processors)

wip = []

time = 0
i = 0

while i < len(jobs):
    while processors and i < len(jobs):
        p = heappop(processors)
        print "{0} {1}".format(p, time)
        item = (time + jobs[i], p)
        heappush(wip, item)
        i += 1
    time, p = heappop(wip)
    heappush(processors, p)
    while wip and wip[0][0] == time:
        time, p = heappop(wip)
        heappush(processors, p)
