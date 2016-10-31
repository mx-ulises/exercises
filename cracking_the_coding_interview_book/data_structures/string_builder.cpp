#include <exception>
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
            char* char_buffer = new char[n];
            int position = 0;
            for (int i = 0; i < strings.size(); i++) {
                for(int j = 0; j < strings[i].size(); j++) {
                    char_buffer[position] = strings[i].at(j);
                    position++;
                }
            }
            string out_string(char_buffer);
            return out_string;
        }
};

int main() {
    StringBuilder sb;
    sb.insert("hola-");
    sb.insert("mundo-");
    cout << "'" << sb.get_string() << "'" << endl;
    sb.insert("loco-");
    cout << "'" << sb.get_string() << "'" << endl;
    sb.insert("");
    cout << "'" << sb.get_string() << "'" << endl;
}
