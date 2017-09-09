#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

class StringBuilder {
    private:
        vector<string> strings;

    public:
        void insert(string s){
            strings.push_back(s);
        }

        int size() {
            int n = 0;
            for (int i = 0; i < strings.size(); i++) {
                n += strings[i].size();
            }
            return n;
        }

        string get_string() {
            int n = size();
            char* char_buffer = new char[n + 1];
            int position = 0;
            for (int i = 0; i < strings.size(); i++) {
                for(int j = 0; j < strings[i].size(); j++) {
                    char_buffer[position] = strings[i].at(j);
                    position++;
                }
            }
            char_buffer[n] = '\0';
            string out_string(char_buffer);
            return out_string;
        }
};

void append(StringBuilder* sb, char c, int count) {
    stringstream ss;
    string s;
    ss << c << count;
    ss >> s;
    sb->insert(s);
}

string compression(string s) {
    if (s.size() == 0)
        return s;
    StringBuilder sb;
    char current = s.at(0);
    int count = 1;
    for (int i = 0; i < s.size(); i++) {
        if (current != s.at(i)) {
            append(&sb, current, count);
            count = 0;
        }
        current = s.at(i);
        count++;
    }
    append(&sb, current, count);
    string s_2 = sb.get_string();
    if (s_2.size() < s.size())
        return s_2;
    return s;
}

void test(string s) {
    cout << "Testing:\t'" << s << "'" << endl;
    string s_2 = compression(s);
    cout << "Result: \t'" << s_2 << "'" << endl;
    cout << endl;
}

int main() {
    test("");
    test("abcd");
    test("aabcd");
    test("aaaaaabcd");
    test("aaaaaabcdeeeefg");
    test("aaabbbcccddd");
    return 0;
}
