#!/bin/python

from heapq import heappush, heappop

p, n = map(int, raw_input().split())
jobs = map(int, raw_input().split())
wip = []

time = 0
i = 0

def push_item(pid, start_time, duration, wip):
    print "{0} {1}".format(pid, start_time)
    finish_time = start_time + duration
    item = (finish_time, pid)
    heappush(wip, item)

while i < p and i < n:
    push_item(i, time, jobs[i], wip)
    i += 1

while i < n:
    time, pid = heappop(wip)
    push_item(pid, time, jobs[i], wip)
    i += 1
