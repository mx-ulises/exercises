#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int maximal_sum(vector<vector<int>> A, int n) {
    int m = n * 2;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int k = m - i - 1;
            int l = m - j - 1;
            int maximal = max(A[i][j], A[k][j]);
            maximal = max(maximal, A[i][l]);
            maximal = max(maximal, A[k][l]);
            sum += maximal;
        }
    }
    return sum;
}

vector<vector<int>> create_matrix(int n) {
    vector<vector<int>> A(n * 2, vector<int>(n * 2));
    for (int i = 0; i < (n * 2); i++) {
        for (int j = 0; j < (n * 2); j++) {
            cin >> A[i][j];
        }
    }
    return A;
}

int main() {
    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int n;
        cin >> n;
        cout << maximal_sum(create_matrix(n), n) << endl;
    }
    return 0;
}
