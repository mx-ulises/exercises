#include <vector>
#include <iostream>

using namespace std;

class Matrix {
    public:
        vector<vector<int>> a;

        Matrix operator + (const Matrix& Y) {
            Matrix X = *this;
            Matrix result;
            for (int i = 0; i < X.a.size(); i++) {
                vector<int> b;
                for (int j = 0; j < X.a[i].size(); j++) {
                    int num = X.a[i][j] + Y.a[i][j];
                    b.push_back(num);
                }
                result.a.push_back(b);
            }
            return result;
        }
};

int main () {
    int T;
    cin >> T;
    for(int t = 0; t < T; t++) {
        Matrix X, Y, result;
        int n,m;
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for(int j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            X.a.push_back(b);
        }
        for(int i = 0; i < n; i++) {
            vector<int> b;
            int num;
            for(int j = 0; j < m; j++) {
                cin >> num;
                b.push_back(num);
            }
            Y.a.push_back(b);
        }
        result = X + Y;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                cout << result.a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
