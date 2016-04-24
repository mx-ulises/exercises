def result_test_case(original_grid):
    original_grid = original_grid.splitlines()
    n_rows = len(original_grid)
    ordered_grid = []
    for i in range(n_rows):
        row = []
        row[:0] = original_grid[i]
        row.sort()
        ordered_grid += [row]
    for i in range(1, n_rows):
        for j in range(n_rows):
            if ordered_grid[i - 1][j] > ordered_grid[i][j]:
                return "NO"
    return "YES"


original_grid = """ebacz
fghij
zlmkn
trpqs
xywuv
"""

print result_test_case(original_grid)

