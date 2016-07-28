#!/bin/python

def get_cost(M, N):
    cost = 0
    for i in xrange(3):
        for j in xrange(3):
            #print M[i][j]
            #print N[i][j]
            cost += abs(M[i][j] - N[i][j])
    return cost

def rotate(M):
    aux = M[1][0]
    M[1][0] = M[2][0]
    M[2][0] = M[2][1]
    M[2][1] = M[2][2]
    M[2][2] = M[1][2]
    M[1][2] = M[0][2]
    M[0][2] = M[0][1]
    M[0][1] = M[0][0]
    M[0][0] = aux
    return M

S = [map(int, raw_input().split()) for _ in xrange(3)]
cost = 100000

MAGICAL = [[4, 9, 2],
           [3, 5, 7],
           [8, 1, 6]]

for _ in xrange(8):
    cost = min(cost, get_cost(MAGICAL, S))
    MAGICAL = rotate(MAGICAL)
    MAGICAL = rotate(MAGICAL)

MAGICAL = [[8, 1, 6],
           [3, 5, 7],
           [4, 9, 2]]

for _ in xrange(8):
    cost = min(cost, get_cost(MAGICAL, S))
    MAGICAL = rotate(MAGICAL)
    MAGICAL = rotate(MAGICAL)

print cost
