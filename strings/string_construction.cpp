#include <set>
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        set<char> count;
        for (int j = 0; j < s.length(); j++) {
            count.insert(s.at(j));
        }
        cout << count.size() << endl;
    }
    return 0;
}
