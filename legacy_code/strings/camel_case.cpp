#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 1;
    for (char& c : s) {
        if ('A' <= c && c <= 'Z') {
            count ++;
        }
    }
    cout << count << endl;
    return 0;
}
