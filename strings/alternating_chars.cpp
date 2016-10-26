#include <iostream>

using namespace std;

int count_repeat(string s) {
    if (s.length() == 0) return 0;
    char current = s.at(0);
    int repeat = 0;
    for (int i = 1; i < s.length(); i++) {
        char new_char = s.at(i);
        if (current == new_char) repeat++;
        current = new_char;
    }
    return repeat;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string s;
        cin >> s;
        cout << count_repeat(s) << endl;
    }
    return 0;
}
