#include <map>
#include <iostream>

using namespace std;

int main(){
    int n, m;
    cin >> n;
    cin >> m;
    map<string, int> magazine;
    while (n > 0) {
        string word;
        cin >> word;
        if (magazine.find(word) == magazine.end()) {
            magazine[word] = 0;
        }
        magazine[word]++;
        n--;
    }
    bool result = true;
    while (m > 0) {
        string word;
        cin >> word;
        if (magazine.find(word) == magazine.end() || magazine[word] == 0) {
            result = false;
            break;
        }
        magazine[word]--;
        m--;
    }
    if (result) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
