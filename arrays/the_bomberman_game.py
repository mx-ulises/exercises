#!/bin/python
def print_grid(grid):
    for r in grid:
        print ''.join(r)

def full_grid(r, c):
    grid = [["O"] * c for _ in xrange(r)]
    print_grid(grid)

def after_bombs(grid):
    alt_grid = [["O"] * c for _ in xrange(r)]
    for i in xrange(r):
        for j in xrange(c):
            if grid[i][j] == "O":
                alt_grid[i][j] = "."
                if i > 0:
                    alt_grid[i - 1][j] = "."
                if i < r - 1:
                    alt_grid[i + 1][j] = "."
                if j > 0:
                    alt_grid[i][j - 1] = "."
                if j < c - 1:
                    alt_grid[i][j + 1] = "."
    return alt_grid

r, c, n = map(int, raw_input().split())
grid = []
for _ in xrange(r):
    grid.append(list(raw_input()))

alt_grid = after_bombs(grid)
alt_grid_2 = after_bombs(alt_grid)

if n % 2 == 0:
    full_grid(r, c)
elif n == 1:
    print_grid(grid)
elif (n - 1) % 4 == 0:
    print_grid(alt_grid_2)
else:
    print_grid(alt_grid)
