#!/bin/python

from heapq import heappush, heappop

t = int(raw_input())
mayores = [1000000]
menores = [0]

for i in xrange(t):
    n = i + 1
    item = int(raw_input())
    if (n % 2) == 1:
        if item > mayores[0]:
            heappush(mayores, item)
            print "{0:.1f}".format(mayores[0])
        else:
            heappush(menores, -item)
            heappush(mayores, -heappop(menores))
            print "{0:.1f}".format(mayores[0])
    else:
        heappush(mayores, item)
        if len(mayores) > len(menores):
            heappush(menores, -heappop(mayores))
        elif len(menores) > len(mayores):
            heappush(mayores, -heappop(menores))
        print "{0:.1f}".format(float(mayores[0] - menores[0]) / float(2))
