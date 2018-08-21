#!/bin/python

def sort_queue(q):
    aux = []
    while 0 < len(q):
        minimal = q.pop()
        while 0 < len(q):
            x = q.pop()
            if minimal < x:
                aux.append(x)
            else:
                aux.append(minimal)
                minimal = x
        minimal_count = 1
        while 0 < len(aux) and minimal <= aux[-1]:
            x = aux.pop()
            if x == minimal:
                minimal_count += 1
            else:
                q.append(x)
        for _ in xrange(minimal_count):
            aux.append(minimal)
    return aux


def test(q):
    print "{0}".format(q)
    q = sort_queue(q)
    print "{0}".format(q)
    print "======================================"


q = [7, 8, 10, 1, 3, 7, 10, 23, 2, 6]
test(q)
test([])
test([1, 2, 3, 4, 5])
test([5, 4, 3, 2, 1])
test([1, 2, 1, 2, 1, 2])
test([1, 1, 1, 1, 1, 1])
