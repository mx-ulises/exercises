#!/bin/python

def build_order(projects, dependencies):
    succesors = {a: [] for a in projects}
    inner = {a: 0 for a in projects}
    for (a, b) in dependencies:
        succesors[a].append(b)
        inner[b] += 1

    Open = []
    for a in projects:
        if inner[a] == 0:
            Open.append(a)

    Closed = []
    while Open:
        a = Open.pop()
        for b in succesors[a]:
            inner[b] -= 1
            if inner[b] == 0:
                Open.append(b)
        Closed.append(a)

    if len(Closed) == len(projects):
        return Closed
    else:
        return None
