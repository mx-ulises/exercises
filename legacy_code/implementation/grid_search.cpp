#include <iostream>
#include <vector>

using namespace std;

bool check_pattern(vector<string> G, int g_i, int g_j, vector<string> P, int p_r, int p_c) {
    for (int i = 0; i < p_r; i++) {
        for (int j = 0; j < p_c; j++) {
            if (G[g_i + i][g_j + j] != P[i][j]) {
                return false;
            }
        }
    }
    return true;
}

string exist_pattern(vector<string> G, int g_r, int g_c, vector<string> P, int p_r, int p_c) {
    for (int i = 0; i < (g_r - p_r + 1); i++) {
        for (int j = 0; j < (g_c - p_c + 1); j++) {
            if (check_pattern(G, i, j, P, p_r, p_c)) {
                return "YES";
            }
        }
    }
    return "NO";
}

int main() {
    int T;
    cin >> T;
    for(int j = 0; j < T; j++){
        int R;
        int C;
        cin >> R >> C;
        vector<string> G(R);
        for(int i = 0; i < R; i++){
           cin >> G[i];
        }
        int r;
        int c;
        cin >> r >> c;
        vector<string> P(r);
        for(int i = 0; i < r; i++){
           cin >> P[i];
        }
        cout << exist_pattern(G, R, C, P, r, c) << endl;
    }
    return 0;
}
