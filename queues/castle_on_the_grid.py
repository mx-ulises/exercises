n = 3
grid_text = """.X.
.X.
...""".split()
a, b, c, d = 0, 0, 0, 2

grid = [[True for __ in range(n)] for _ in range(n)]

for x in range(n):
    row = grid_text[x]
    for y in range(n):
        if row[y] == "X":
            grid[x][y] = False

closed = {}
queue = [(a, b, 0)]

while queue:
    x, y, dist = queue.pop(0)
    if (x, y) == (c, d):
        print dist
        break
    if (x, y) in closed:
        continue
    for i in range(x + 1, n):
        if not grid[i][y]:
            break
        queue += [(i, y, dist + 1)]
    for i in reversed(range(0, x)):
        if not grid[i][y]:
            break
        queue += [(i, y, dist + 1)]
    for i in range(y + 1, n):
        if not grid[x][i]:
            break
        queue += [(x, i, dist + 1)]
    for i in reversed(range(0, y)):
        if not grid[x][i]:
            break
        queue += [(x, i, dist + 1)]
    closed[(x, y)] = dist

