#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[(n - d + i) % n];
    }
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}
