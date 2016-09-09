#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m, max_element;
    cin >> n >> m;
    vector<int> c(m);
    for (int i = 0; i < m; i++) {
       cin >> c[i];
    }
    sort(c.begin(), c.end());
    max_element = max(c[0], n - 1 - c[m - 1]);
    for (int i = 0; i < m - 1; i++) {
        max_element = max(max_element, (c[i + 1] - c[i]) / 2);
    }
    cout << max_element << endl;
    return 0;
}
