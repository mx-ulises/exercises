#!/bin/python

def is_balanced(s):
    queue = []
    for c in s:
        if c == '(':
            queue.append(c)
        elif c == ')':
            if len(queue):
                queue.pop()
            else:
                return False
        else:
            return False
    if len(queue):
        return False
    return True

def test(s):
    print "Test case '{0}' is balanced: '{1}'".format(s, is_balanced(s))

test("")
test("()")
test("(((")
test("(())()")
test(")(")
test("((()())())")
test("(((B)(X))(A))")
