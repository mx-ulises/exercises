#!/bin/python

def is_child(p, x):
    return (x == p.right or x == p.left)

def common_ancestor(p, x, y):
    if not p:
        return (None, False, False)
    if is_child(p, x):
        x_found = True
    if is_child(p, y):
        y_found = True
    rr = common_ancestor(p.right, x, y)
    if rr[1] and rr[2]:
        return rr
    lr = common_ancestor(p.left, x, y)
    if lr[1] and lr[2]:
        return lr
    x_found = x_found | lr[1] | rr[1]
    y_found = y_found | lr[2] | rr[2]
    if x_found or y_found:
        return (p, x_found, y_found)
