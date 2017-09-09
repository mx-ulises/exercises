#!/bin/python

def FindMergeNode(headA, headB):
    A_s = []
    B_s = []
    node = headA
    while node:
        A_s.append(node)
        node = node.next
    node = headB
    while node:
        B_s.append(node)
        node = node.next
    prev = A_s[-1]
    while A_s[-1] == B_s[-1]:
        prev = A_s[-1]
        A_s.pop()
        B_s.pop()
    return prev.data
