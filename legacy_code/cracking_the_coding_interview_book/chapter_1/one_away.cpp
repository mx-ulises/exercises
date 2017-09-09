#include <cmath>
#include <iostream>

using namespace std;

bool one_away(string s_1, string s_2) {
    int delta = abs(s_1.size() - s_2.size());
    if (delta >= 2) return false;
    if (s_1.size() < s_2.size()) {
        string s_aux = s_1;
        s_1 = s_2;
        s_2 = s_aux;
    }
    int i = 0;
    int j = 0;
    bool is_one_away = false;
    while (j < s_2.size()) {
        if (s_1.at(i) != s_2.at(j)) {
            if (is_one_away) return false;
            is_one_away = true;
            if (s_1.size() > s_2.size()) {
                i++;
                continue;
            }
        }
        i++;
        j++;
    }
    return true;
}

void test_function(string s_1, string s_2) {
    cout << "s_1: '" << s_1 << "'" << endl;
    cout << "s_2: '" << s_2 << "'" << endl;
    cout << "one_away: '" << one_away(s_1, s_2) << "'" << endl << endl;
}

int main() {
    test_function("abcd", "abcd");
    test_function("abcde", "abcd");
    test_function("abcd", "abcde");
    test_function("abcde", "axcd");
    test_function("axxd", "abcd");
    test_function("", "");
    test_function("", "a");
    return 0;
}
