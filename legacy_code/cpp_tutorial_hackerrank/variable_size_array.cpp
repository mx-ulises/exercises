#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    int **A = new int* [n];
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        int *B = new int[m];
        for (int j = 0; j < m; j++) {
            cin >> B[j];
        }
        *(A + i) = B;
    }
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        cout << A[a][b] << endl;
    }
	return 0;
}
