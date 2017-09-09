#!/bin/python

class DisjointSet(object):
    def __init__(self, n):
        self.parent = [x for x in range(n)]
        self.rank = [0 for x in range(n)]

    def find(self, x):
        if(self.parent[x]!=x):
            self.parent[x]=self.find(self.parent[x])
        return self.parent[x]

    def union(self, x, y):
        x_root = self.find(x)
        y_root = self.find(y)
        if(x_root == y_root):
            return
        if self.rank[x_root] < self.rank[y_root]:
            self.parent[x_root] = y_root
        elif self.rank[x_root] > self.rank[y_root]:
            self.parent[y_root] = x_root
        else:
            self.parent[y_root] = x_root
            self.rank[x_root] += 1


def equiation_check(equities, inequities):
    terms = set()
    for a, b in equities:
        terms.add(a)
        terms.add(b)
    for a, b in inequities:
        terms.add(a)
        terms.add(b)
    terms = list(terms)
    n = len(terms)
    terms = {terms[i]: i for i in xrange(n)}
    dj_set = DisjointSet(n)
    for a, b in equities:
        dj_set.union(terms[a], terms[b])
    for a, b in inequities:
        if dj_set.find(terms[a]) == dj_set.find(terms[b]):
            return False
    return True

equities = []
inequities = [('a', 'b')]
print equiation_check(equities, inequities)

equities = [('a', 'b'), ('c', 'b'), ('y', 'z')]
inequities = [('z', 'b'), ('y', 'a')]
print equiation_check(equities, inequities)

equities = [('a', 'b'), ('c', 'b'), ('y', 'z')]
inequities = [('z', 'b'), ('b', 'a')]
print equiation_check(equities, inequities)
