#include <utility>
#include <iostream>
#include <vector>

using namespace std;

int get_start_r(vector<vector<int>> A, int x, int c, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x == A[mid][c]) return mid;
        if (x < A[mid][c]) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}

int get_end_r(vector<vector<int>> A, int x, int c, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x == A[mid][c]) return mid;
        if (x < A[mid][c]) end = mid - 1;
        else start = mid + 1;
    }
    return end;
}

int get_start_c(vector<vector<int>> A, int x, int r, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x == A[r][mid]) return mid;
        if (x < A[r][mid]) end = mid - 1;
        else start = mid + 1;
    }
    return start;
}

int get_end_c(vector<vector<int>> A, int x, int r, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        if (x == A[r][mid]) return mid;
        if (x < A[r][mid]) end = mid - 1;
        else start = mid + 1;
    }
    return end;
}

pair<int, int> search(vector<vector<int>> A, int x) {
    int start_r = 0;
    int start_c = 0;
    int end_r = A.size() - 1;
    int end_c = A[0].size() - 1;
    while (start_r <= end_r && start_c <= end_c) {
        if (A[start_r][start_c] == x)
            return pair<int, int>(start_r, start_c);
        if (A[start_r][end_c] == x)
            return pair<int, int>(start_r, end_c);
        if (A[end_r][start_c] == x)
            return pair<int, int>(end_r, start_c);
        if (A[end_r][end_c] == x)
            return pair<int, int>(end_r, end_c);
        int new_start_r = get_start_r(A, x, end_c, start_r, end_r);
        int new_start_c = get_start_c(A, x, end_r, start_c, end_c);
        int new_end_r = get_end_r(A, x, start_c, start_r, end_r);
        int new_end_c = get_end_c(A, x, start_r, start_c, end_c);
        start_r = new_start_r;
        start_c = new_start_c;
        end_r = new_end_r;
        end_c = new_end_c;
    }
    if (A[start_r][start_c] == x)
        return pair<int, int>(start_r, start_c);
    return pair<int, int>(-1, -1);
}

void test(vector<vector<int>> A, int x) {
    cout << "Looking for " << x << endl;
    pair<int, int> p = search(A, x);
    cout << p.first << ", " << p.second << endl << endl;
}

int main() {
    vector<vector<int>> A(5, vector<int>(5));
    A[0][0] = 1;
    A[0][1] = 2;
    A[0][2] = 3;
    A[0][3] = 4;
    A[0][4] = 5;

    A[1][0] = 2;
    A[1][1] = 3;
    A[1][2] = 4;
    A[1][3] = 5;
    A[1][4] = 10;

    A[2][0] = 3;
    A[2][1] = 4;
    A[2][2] = 8;
    A[2][3] = 9;
    A[2][4] = 11;

    A[3][0] = 4;
    A[3][1] = 5;
    A[3][2] = 9;
    A[3][3] = 10;
    A[3][4] = 12;

    A[4][0] = 5;
    A[4][1] = 6;
    A[4][2] = 10;
    A[4][3] = 11;
    A[4][4] = 13;

    test(A, 6);
    test(A, 7);
    test(A, 8);
    return 0;
}
