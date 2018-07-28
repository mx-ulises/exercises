#!/bin/python

from heapq import heappush, heappop


def merge_sorted_lists(lists):
    l_out = []
    minimals = []
    k = len(lists)
    for i in xrange(k):
        item = (lists[i].pop(0), i)
        heappush(minimals, item)
    while minimals:
        x, i = heappop(minimals)
        l_out.append(x)
        if lists[i]:
            item = (lists[i].pop(0), i)
            heappush(minimals, item)    
    return l_out

def test(lists):
    for l in lists:
        print l
    print sum([len(l) for l in lists])
    l_out = merge_sorted_lists(lists)
    print len(l_out)
    print l_out
    print "==========================================================="


test([range(1, 10), range(3, 12), range(4, 7)])
test([range(8, 10), range(2, 5), range(14, 27)])
test([range(11, 19), range(3, 5), range(4, 7)])
test([range(1, 10), range(3, 19), range(11, 17)])
