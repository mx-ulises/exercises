#!/bin/python
class Trie:

    def __init__(self):
        self.chars = {}

    def add(self, word):
        current = self.chars
        is_prefix = True
        for c in word:
            if c not in current:
                current[c] = {}
                is_prefix = False
            if "*" in current:
                return False
            current = current[c]
        if "*" not in current:
            current["*"] = None
            if is_prefix:
                return False
            else:
                return True
        else:
            return False

trie = Trie()

q = int(raw_input())
good = True
word = ""
for _ in xrange(q):
    word = raw_input()
    if not trie.add(word):
        good = False
        break

if good:
    print "GOOD SET"
else:
    print "BAD SET"
    print word
