#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int get_glass(vector<vector<int>> A, int i, int j) {
    int sum = A[i][j] + A[i][j + 1] + A[i][j + 2];
    sum += A[i + 1][j + 1];
    sum += A[i + 2][j] + A[i + 2][j + 1] + A[i + 2][j + 2];
    return sum;

}

int main(){
    vector<vector<int>> A(6, vector<int>(6));
    int max_glass = -81;
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            max_glass = max(max_glass, get_glass(A, i, j));
        }
    }
    cout << max_glass << endl;
    return 0;
}
