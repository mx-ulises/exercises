#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    unsigned long n, m;
    cin >> n >> m;
    vector<unsigned long long> A(n);
    for (unsigned long long i = 0; i < m; i++) {
        unsigned long long a, b, k;
        cin >> a >> b >> k;
        A[a - 1] += k;
        if (b < n) {
            A[b] -= k;
        }
    }
    unsigned long long max_value = 0;
    unsigned long long current_counter = 0;
    for (unsigned long long i = 0; i < n; i++) {
        current_counter += A[i];
        max_value = max(max_value, current_counter);
    }
    cout << max_value;
    return 0;
}
