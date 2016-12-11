#include <map>
#include <set>
#include <iostream>

using namespace std;

bool valid_position(map<int, int>* positions, int row, int k, set<int>* diag_asc, set<int>* diag_desc) {
    if (positions->find(row) != positions->end()) return false;
    if (diag_asc->find(row + k) != diag_asc->end()) return false;
    if (diag_desc->find(row - k) != diag_desc->end()) return false;
    return true;
}

bool queens_problem(map<int, int>* positions, int k, int n, set<int>* diag_asc, set<int>* diag_desc) {
    if (k == n) return true;
    for (int row = 0; row < n; row++) {
        if (valid_position(positions, row, k, diag_asc, diag_desc)) {
            diag_asc->insert(row + k);
            diag_desc->insert(row - k);
            (*positions)[row] = k;
            if (queens_problem(positions, k + 1, n, diag_asc, diag_desc)) {
                return true;
            }
            diag_asc->erase(row + k);
            diag_desc->erase(row - k);
            positions->erase(row);
        }
    }
    return false;
}

bool test(int n) {
    map<int, int> positions;
    set<int> diag_asc;
    set<int> diag_desc;
    bool result = queens_problem(&positions, 0, n, &diag_asc, &diag_desc);
    for (map<int, int>::iterator it = positions.begin(); it != positions.end(); it++) {
        cout << it->first << ": " << it->second << endl;
    }
    return result;
}

int main() {
    test(8);
}
