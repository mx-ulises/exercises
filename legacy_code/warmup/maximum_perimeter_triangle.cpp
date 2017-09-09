#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void get_best(vector<int> *L) {
    sort(L->begin(), L->end());
    for (int i = 0; i < L->size() - 2; i++) {
        int j = L->size() - 3 - i;
        if (L->at(j + 2) < L->at(j + 1) + L->at(j)) {
            cout << L->at(j) << " " << L->at(j + 1) << " " << L->at(j + 2) << endl;
            return;
        }
    }
    cout << "-1" << endl;
}

int main() {
    int n;
    vector<int> L;
    cin >> n;
    while (n) {
        int l;
        cin >> l;
        L.push_back(l);
        n--;
    }
    get_best(&L);
    return 0;
}
