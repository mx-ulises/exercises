// Reverse sentence words (ADM-3.26)

#include <exception>
#include <stack>
#include <iostream>

using namespace std;

class StringBuilderReverse {
    private:
    stack<string> strings;
    int n;

    public:
        void insert(string s){
            n += s.size();
            strings.push(s);
        }

        int size() {
            return n;
        }

        string get_string() {
            char* char_buffer = new char[size() + 1];
            int position = 0;
            while (0 < strings.size()) {
                string s = strings.top();
                strings.pop();
                for(int i = 0; i < s.size(); i++) {
                    char_buffer[position] = s.at(i);
                    position++;
                }
            }
            char_buffer[size()] = '\0';
            string out_string(char_buffer);
            n = 0;
            return out_string;
        }
};

void test(string s) {
    StringBuilderReverse* sb = new StringBuilderReverse();
    string sub_s = "";
    for (int i = 0; i < s.size(); i++) {
        char c = s.at(i);
        if (c == ' ') {
            sb->insert(sub_s);
            sb->insert(" ");
            sub_s = "";
        } else {
            sub_s += c;
        }
    }
    sb->insert(sub_s);
    cout << "Before: '" << s << "'" << endl;
    cout << "After   '" << sb->get_string() << "'" << endl << endl;
}

int main() {
    test("Hola mundo loco");
    test("Hola     mundo   loco");
    test("hola");
    test("hola mundo ");
    test(" hola mundo ");
}
