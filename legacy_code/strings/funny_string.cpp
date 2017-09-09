#include <iostream>
#include <algorithm>

using namespace std;

bool is_funny(string s) {
    for (int i = 1; i < s.size(); i++) {
        int d_1 = abs(s.at(i) - s.at(i - 1));
        int d_2 = abs(s.at(s.size() - i) - s.at(s.size() - i - 1));
        if (d_1 != d_2) return false;
    }
    return true;
}

int main() {
    int n ;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (is_funny(s)) cout << "Funny" << endl;
        else cout << "Not Funny" << endl;
    }
    return 0;
}
