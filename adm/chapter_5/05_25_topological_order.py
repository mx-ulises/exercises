#!/bin/python

def get_hated_rel(hr, n):
    hated_rel = {i: [] for i in xrange(n)}
    for i, j in hr:
        hated_rel[j].append(i)
    return hated_rel


def update_order(x, hr, order, procesed):
    if not procesed[x]:
        for y in hr[x]:
            update_order(y, hr, order, procesed)
        procesed[x] = True
        order.append(x)

def get_order(hr, n):
    hated_rel = get_hated_rel(hr, n)
    order = []
    procesed = {i: False for i in xrange(n)}
    for i in xrange(n):
        update_order(i, hated_rel, order, procesed)
    return order

hr = []
hr.append((1, 5))
hr.append((1, 3))
hr.append((2, 1))
hr.append((2, 4))
hr.append((5, 3))
hr.append((8, 7))

print get_order(hr, 9)
