#!/bin/python

def stack_sort(stack):
    stack = list(stack)
    stack_sorted = []
    while stack:
        n = len(stack)
        max_element = stack.pop()
        while stack:
            element = stack.pop()
            if element <= max_element:
                stack_sorted.append(element)
            else:
                stack_sorted.append(max_element)
                max_element = element
        for _ in xrange(n - 1):
            stack.append(stack_sorted.pop())
        stack_sorted.append(max_element)
    return stack_sorted
