#!/bin/python

class Node(object):
    def __init__(self, data):
        self.data = data
        self.succesors = []
        self.visited = False

    def add(self, node):
        self.succesors.append(node)


def dfs(root):
    Open = [root]
    while Open:
        node = Open.pop()
        if not node.visited:
            node.visited = True
            Open.extend(node.succesors)


def clear(node):
    Open = [node]
    while Open:
        node = Open.pop()
        if node.visited:
            node.visited = False
            Open.extend(node.succesors)


def is_connected(a, b):
    print "testing '{0}' and '{1}'".format(a.data, b.data)
    clear(a)
    clear(b)
    dfs(a)
    return b.visited


a = Node("a")
b = Node("b")
c = Node("c")
d = Node("d")

a.add(b)
a.add(c)
b.add(d)
c.add(d)
d.add(a)

print is_connected(a, b)
print is_connected(a, d)
print is_connected(d, a)

e = Node("e")
f = Node("f")
g = Node("g")

e.add(f)
f.add(g)
g.add(f)

print is_connected(e, g)
print is_connected(g, e)

h = Node("h")
i = Node("i")
j = Node("j")

h.add(i)
h.add(j)

print is_connected(h, i)
print is_connected(i, j)
