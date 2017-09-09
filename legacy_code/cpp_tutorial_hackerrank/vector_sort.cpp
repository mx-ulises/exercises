#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    int n;
    vector<int> A;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        A.push_back(a);
    }
    sort(A.begin(), A.end());
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    return 0;
}
