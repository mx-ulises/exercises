#include <vector>
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

string print_binary(double n) {
    if (n >= 1 || n <= 0)
        return "ERROR";
    StringBuilder sb;
    sb.insert(".");
    while (n > 0) {
        if (sb.size() >= 32)
            return "ERROR";
        double r = n * 2;
        if (r >= 1) {
            sb.insert("1");
            n = r - 1;
        } else {
            sb.insert("0");
            n = r;
        }
    }
    return sb.get_string();
}

void test(double n) {
    cout << "n: " << n << endl;
    cout << "binary: " << print_binary(n) << endl << endl;
}

int main() {
    test(0.008);
    test(0.5);
    test(0.25);
    test(0.75);
    test(0.0625);
    test(0.5625);
    return 0;
}
