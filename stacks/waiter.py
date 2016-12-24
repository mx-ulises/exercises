#!/bin/python

def get_primes(n):
    primes = []
    is_prime = [True] * n
    for i in xrange(2, n):
        if is_prime[i]:
            primes.append(i)
            k = 2
            c = i * k
            while c < n:
                is_prime[c] = False
                k += 1
                c = i * k
    return primes

primes = get_primes(10000)

def print_stack(S):
    while S:
        print S.pop()

_, q = map(int, raw_input().split())
A = map(int, raw_input().split())

for i in xrange(q):
    A_i = []
    B = []
    while A:
        a = A.pop()
        if (a % primes[i]) == 0:
            B.append(a)
        else:
            A_i.append(a)
    print_stack(B)
    A = A_i

print_stack(A)
