#include <iostream>

using namespace std;

void swap(int** M, int a, int b, int i) {
    int aux = M[a][a + i];
    M[a][a + i] = M[b - i][a];
    M[b - i][a] = M[b][b - i];
    M[b][b - i] = M[a + i][b];
    M[a + i][b] = aux;
}

void rotate_matrix(int** M, int n) {
    for (int k = 0; k < (n / 2); k++) {
        for (int i = k; i < (n - k - 1); i++) {
            swap(M, k, n - 1 - k, i);
        }
    }
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
    int n = 5;
    int** M = new int*[n];
    for (int i = 0; i < n; i++) {
        M[i] = new int[n];
        for (int j = 0; j < n; j++) {
            M[i][j] = i * n + j;
        }
    }
    print_matrix(M, n, n);
    rotate_matrix(M,  n);
    cout << endl;
    print_matrix(M, n, n);
    return 0;
}
