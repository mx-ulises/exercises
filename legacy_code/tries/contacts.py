#!/bin/python
class Trie:
    def __init__(self):
        self.chars = {"count": 0}

    def add(self, word):
        current = self.chars
        for c in word:
            if c not in current:
                current[c] = {"count": 0}
            current = current[c]
        count = 0
        if "*" not in current:
            current["*"] = None
            current["count"] += 1
            count = 1
        current = self.chars
        for c in word:
            current["count"] += count
            current = current[c]

    def find(self, word):
        valid = True
        current = self.chars
        for c in word:
            if c not in current:
                valid = False
                break
            current = current[c]
        if valid:
            return current["count"]
        else:
            return 0

trie = Trie()

q = int(raw_input())
for _ in xrange(q):
    op, word = raw_input().split()
    if op == "add":
        trie.add(word)
    if op == "find":
        print trie.find(word)
