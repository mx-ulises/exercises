#include <set>
#include <iostream>

using namespace std;

void get_zeros(int** M, int n, int m, set<int>* zero_rows, set<int>* zero_cols) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (M[i][j] == 0) {
                zero_rows->insert(i);
                zero_cols->insert(j);
            }
        }
    }
}

void set_zero_rows(int** M, int m, set<int>* zero_rows) {
    for (set<int>::iterator it = zero_rows->begin(); it != zero_rows->end(); it++) {
        for (int i = 0; i < m; i++) {
            M[*it][i] = 0;
        }
    }
}

void set_zero_cols(int** M, int n, set<int>* zero_cols) {
    for (set<int>::iterator it = zero_cols->begin(); it != zero_cols->end(); it++) {
        for (int i = 0; i < n; i++) {
            M[i][*it] = 0;
        }
    }
}

void zero_matrix(int** M, int n, int m) {
    set<int> zero_rows;
    set<int> zero_cols;
    get_zeros(M, n, m, &zero_rows, &zero_cols);
    set_zero_rows(M, m, &zero_rows);
    set_zero_cols(M, n, &zero_cols);
}

void print_matrix(int** M, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << M[i][j] << "\t";
        }
        cout << endl;
    }
}

int main() {
    int n = 4;
    int** M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[n];
        for (int j = 0; j < n; j++) {
            M[i][j] = i * n + j;
        }
    }
    M[2][2] = 0;
    print_matrix(M, n, n);
    zero_matrix(M, n, n);
    cout << endl;
    print_matrix(M, n, n);
    return 0;
}
