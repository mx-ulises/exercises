#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<long>* get_mandragoras(int n) {
    vector<long>* M = new vector<long>(n);
    for (int i = 0; i < n; i++) {
        cin >> (*M)[i];
    }
    return M;
}

vector<long>* get_mandragoras_sum(int n, vector<long>* M) {
    vector<long>* M_sum = new vector<long>(n + 1);
    (*M_sum)[0] = 0;
    for (int i = 0; i < n; i++) {
        (*M_sum)[i + 1] = (*M_sum)[i] + (*M)[i];
    }
    return M_sum;
}

long get_max_xp() {
    int n;
    cin >> n;
    vector<long>* M = get_mandragoras(n);
    sort(M->begin(), M->end());
    vector<long>* M_sum = get_mandragoras_sum(n, M);
    long P = 0;
    for (int i = 0; i < (n + 1); i++) {
        long S = i + 1;
        long H = (*M_sum)[n] - (*M_sum)[i];
        P = max(P, S * H);
    }
    delete M;
    delete M_sum;
    return P;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cout << get_max_xp() << endl;
    }
    return 0;
}
