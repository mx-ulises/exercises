#include <utility>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

bool is_valid_position(vector<vector<int>>* grid, int n, int m, int x, int y) {
    if (n == x)
        return false;
    if (m == y)
        return false;
    if ((*grid)[x][y] == 1)
        return false;
    return true;
}

stack<pair<int, int>>* get_path(vector<vector<int>>* grid, int x, int y) {
    stack<pair<int, int>>* path;
    pair<int, int> s(x, y);
    int n = grid->size();
    int m = (*grid)[0].size();
    if (!is_valid_position(grid, n, m, x, y))
        return NULL;
    if (x == (n - 1) && y == (m - 1)) {
        path = new stack<pair<int, int>>();
        path->push(s);
        return path;
    }
    path = get_path(grid, x + 1, y);
    if (path != NULL) {
        path->push(s);
        return path;
    }
    path = get_path(grid, x, y + 1);
    if (path != NULL) {
        path->push(s);
        return path;
    }
    return NULL;
}

void test(vector<vector<int>>* grid) {
    stack<pair<int, int>>* path = get_path(grid, 0, 0);
    if (path == NULL) {
        cout << "No Path" << endl;
    } else {
        while (!path->empty()) {
            pair<int, int> s = path->top();
            path->pop();
            cout << "(" << s.first << ", " << s.second << ") ";
            (*grid)[s.first][s.second] = 8;
        }
        cout << endl << endl;
    }
}

void print_grid(vector<vector<int>> grid) {
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            cout << grid[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    vector<vector<int>> grid(5, vector<int>(5));
    grid[1][0] = 1;
    grid[1][1] = 1;
    grid[1][2] = 1;
    grid[2][3] = 1;
    print_grid(grid);
    test(&grid);
    print_grid(grid);
    return 0;
}
