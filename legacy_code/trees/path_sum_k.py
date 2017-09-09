#!/bin/python

def path_sum(root, k):
    count = 0
    q = [(root, [root.data])]
    while q:
        node, values = q.pop()
        for value in values:
            if value == k:
                count += 1
        if node.right:
            values_right = [node.right.data + value for value in values]
            values_right.append(node.right)
            q.append((node.right, values_right))
        if node.left:
            values_left = [node.left.data + value for value in values]
            values_left.append(node.left)
            q.append((node.left, values_left))
    return count
