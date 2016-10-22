#include <iostream>
#include <map>

using namespace std;

void test_trip() {
    int n, m;
    cin >> m >> n;
    map<int, int> icecream;
    bool found = false;
    for (int i = 0; i < n; i++) {
        int c, c_2;
        cin >> c;
        c_2 = m - c;
        if (!found && icecream.find(c_2) != icecream.end()) {
            cout << icecream[c_2] << " " << i + 1 << endl;
            found = true;
        }
        icecream[c] = i + 1;
    }
}

int main() {
    int t, n, m;
    cin >> t;
    for(int i = 0; i < t; i++) {
        test_trip();
    }
    return 0;
}
