#!/bin/python

def reverse_words(s):
    n = len(s)
    s_arr = list(s)
    s_aux = [' '] * (n + 1)
    s_inv = [' '] * n
    for i in xrange(n):
        s_aux[i] = s_arr[n - 1 - i]
    j = 0
    for i in xrange(n + 1):
        if s_aux[i] == ' ':
            for k in xrange(j, i):
                l = i - (k - j) - 1 
                s_inv[k] = s_aux[l]
            j = i + 1
    return "".join(s_inv)

print reverse_words("hello world")
print reverse_words("mi nombre es Ulises")


    
