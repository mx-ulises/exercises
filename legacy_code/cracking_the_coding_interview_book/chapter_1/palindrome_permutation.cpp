#include <map>
#include <iostream>

using namespace std;

map<char,int>* get_char_count(string* s) {
    map<char,int>* char_count = new map<char,int>();
    for (int i = 0; i < s->size(); i++) {
        (*char_count)[s->at(i)]++;
    }
    return char_count;
}

bool check_palindrome_permutation(string s) {
    map<char,int>* char_count = get_char_count(&s);
    int odd_ocurrence = false;
    for(map<char,int>::iterator it = char_count->begin(); it != char_count->end(); it++) {
        if (it->second % 2) {
            if (odd_ocurrence) return false;
            odd_ocurrence = true;
        }
    }
    return true;
}

void test_code(string s) {
    cout << "'" << s << "': " << check_palindrome_permutation(s) << endl;
}

int main() {
    test_code("");
    test_code("a");
    test_code("aab");
    test_code("aaab");
    test_code("abcde");
    test_code("abcdabcd");
    test_code("axxxxxa");
}
