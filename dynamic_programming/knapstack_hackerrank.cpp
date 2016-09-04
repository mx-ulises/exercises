#include <set>
#include <iostream>
#include <algorithm>

using namespace std;

int get_nearest(set<int> A, int k) {
    set<int> exist;
    exist.insert(0);
    int maximal = 0;
    for (int i = 1; i <= k; i++) {
        for (set<int>::iterator a = A.begin(); a != A.end(); ++a) {
           int y = i - *a;
            if (exist.find(y) != exist.end()) {
                exist.insert(i);
                maximal = i;
                break;
            }
        }
    }
    return maximal;
}


int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        set<int> A;
        for (int j = 0; j < n; j++) {
            int a;
            cin >> a;
            if (a <= k) {
                A.insert(a);
            }
        }
        cout << get_nearest(A, k) << endl;
    }
    return 0;
}
