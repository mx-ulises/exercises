#include <string>
#include <iostream>

using namespace std;

int get_space_count(char* s, int len) {
    int space_count = 0;
    for (int i = 0; i < len; i++) {
        if (s[i] == ' ')
            space_count++;
    }
    return space_count;
}

void put_space(char* s, int p) {
    s[p] = '%';
    s[p + 1] = '2';
    s[p + 2] = '0';
}

void urlify(char* s, int original_len) {
    int space_count = get_space_count(s, original_len);
    int new_len = original_len + space_count * 2;
    int p = new_len - 1;
    for (int i = 0; i < original_len; i++) {
        int j = original_len - i - 1;
        if (s[j] == ' ') {
            p -= 2;
            put_space(s, p);
        } else {
            s[p] = s[j];
        }
        p--;
    }
}

int main() {
    char s[] = "ho la mundo    ";
    int l = 11;
    cout << s << " " << endl;
    urlify(s, l);
    cout << s << " " << endl;
    return 0;
}
