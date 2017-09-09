#!/bin/python

def get_index(A, x, high):
    low = 0
    while low < high:
        mid = (low + high) / 2
        if A[mid] < x: low = mid + 1
        elif A[mid] > x: high = mid
        else: return mid
    return low

n = int(raw_input())
A = map(int, raw_input().split())
A.sort()

q = int(raw_input())
X = map(int, raw_input().split())

B = [0]
for i in xrange(n):
    B.append(B[i] + A[i])

cum = 0
for i in xrange(q):
    x = X[i]
    X[i] += cum
    cum += x

for x in X:
    i = get_index(A, -x, n)
    neg_part = B[i] + (x * i)
    pos_part = B[n] - B[i] + (x * (n - i))
    print (abs(neg_part) + abs(pos_part))
