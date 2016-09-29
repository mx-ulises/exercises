#include <iostream>
#include <vector>

using namespace std;

vector<int> rotate(vector<int> original, int d) {
    int n = original.size();
    int offset = n + d;
    vector<int> rotated;
    for (int i = 0; i < n; i++) {
        rotated.push_back(original[(offset + i) % n]);
    }
    return rotated;
}

int main(){
    int n, d;
    cin >> n >> d;
    vector<int> original;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        original.push_back(a);
    }
    vector<int> rotated = rotate(original, d);
    for (int i = 0; i < n; i++) {
        cout << rotated[i] << " ";
    }
    return 0;
}
