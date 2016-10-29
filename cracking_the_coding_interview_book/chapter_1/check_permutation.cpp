#include <map>
#include <iostream>

using namespace std;

map<char, int>* get_char_count(string* s) {
    map<char, int>* char_count = new map<char, int>();
    for (int i = 0; i < s->size(); i++) {
        char c = s->at(i);
        (*char_count)[c]++;
    }
    return char_count;
}

bool check_permutation(map<char, int>* char_count, string* s) {
    for (int i = 0; i < s->size(); i++) {
        char c = s->at(i);
        (*char_count)[c]--;
        if ((*char_count)[c] < 0)
            return false;
    }
    return true;
}

bool check_permutation(string s_1, string s_2) {
    if (s_1.size() != s_2.size())
        return false;
    map<char, int>* char_count = get_char_count(&s_1);
    bool result = check_permutation(char_count, &s_2);
    delete char_count;
    return result;
}

int main() {
    string s_1 = "";
    string s_2 = "";
    cout << "'" << s_1 << "' y '" << s_2 << "': " <<  check_permutation(s_1, s_2) << endl;
    s_1 = "abcd";
    s_2 = "abcd";
    cout << "'" << s_1 << "' y '" << s_2 << "': " <<  check_permutation(s_1, s_2) << endl;
    s_1 = "abcd";
    s_2 = "dcba";
    cout << "'" << s_1 << "' y '" << s_2 << "': " <<  check_permutation(s_1, s_2) << endl;
    s_1 = "aaa";
    s_2 = "aa";
    cout << "'" << s_1 << "' y '" << s_2 << "': " <<  check_permutation(s_1, s_2) << endl;
    s_1 = "bbb";
    s_2 = "bbbb";
    cout << "'" << s_1 << "' y '" << s_2 << "': " <<  check_permutation(s_1, s_2) << endl;
    return 0;
}
