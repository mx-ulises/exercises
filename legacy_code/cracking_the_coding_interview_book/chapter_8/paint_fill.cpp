#include <queue>
#include <utility>
#include <set>
#include <iostream>

using namespace std;

// Check if valid position in dimensions and in color
bool valid(pair<int, int> position, int n, int m, int** image, int color) {
    if (position.first < 0 || n <= position.first)
        return false;
    if (position.second < 0 || m <= position.second)
        return false;
    if (image[position.first][position.second] != color)
        return false;
    return true;
}

void paint_fill(int** image, int n, int m, int x, int y, int color) {
    // Get color of initial cell and initialize arrays
    int original_color = image[x][y];
    queue<pair<int, int>> Open;
    set<pair<int, int>> Closed;
    Open.push(pair<int, int>(x, y));

    // Check until no new positions to check
    while(!Open.empty()) {
        pair<int, int> current = Open.front();
        Open.pop();

        // Verify position already checked
        if (Closed.find(current) != Closed.end())
            continue;

        // Verify if it is a valid position
        if (valid(current, n, m, image, original_color)) {
            // If valid position, set new color and mark as checked
            int x_1 = current.first;
            int y_1 = current.second;
            image[x_1][y_1] = color;
            Closed.insert(current);
            // Add adjacent positions
            Open.push(pair<int, int>(x_1 + 1, y_1));
            Open.push(pair<int, int>(x_1 - 1, y_1));
            Open.push(pair<int, int>(x_1, y_1 + 1));
            Open.push(pair<int, int>(x_1, y_1 - 1));
        }
    }
}

void print_matrix(int** A, int n, int m) {
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << A[i][j];
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n = 4;
    int m = 4;
    int** A = new int* [n];
    for(int i = 0; i < n; i++) {
        A[i] = new int [m];
        for (int j = 0; j < m; j++) {
            A[i][j] = 0;
        }
    }
    A[1][1] = 1;
    print_matrix(A, n, m);
    paint_fill(A, n, m, 2, 1, 3);
    print_matrix(A, n, m);
    return 0;
}
