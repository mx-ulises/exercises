#!/bin/python

def is_pair(a):
    if (a % 2) == 0:
        return True
    return False


def separate(A):
    print A
    i = 0
    j = len(A) - 1
    while i < j:
        if is_pair(A[i]) and is_pair(A[j]):
            i += 1
        elif is_pair(A[i]) and not is_pair(A[j]):
            i += 1
            j -= 1
        elif not is_pair(A[i]) and is_pair(A[j]):
            A[i], A[j] = A[j], A[i]
            i += 1
            j -= 1
        else:
            j -= 1
    return A

print separate([9, 8, 7, 6, 5, 4, 3, 2, 1])
print ""
print separate([1, 1, 1, 3, 4, 5, 6, 9, 9, 9])
