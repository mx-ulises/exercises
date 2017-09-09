#include <set>
#include <iostream>

using namespace std;

string check_word(string a, string b) {
    set<char> letters;
    for (int i = 0; i < a.length(); i++) {
        letters.insert(a.at(i));
    }
    for (int i = 0; i < b.length(); i++) {
        if (letters.find(b.at(i)) != letters.end()) {
            return "YES";
        }
    }
    return "NO";
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a, b;
        cin >> a >> b;
        cout << check_word(a, b) << endl;
    }
    return 0;
}
