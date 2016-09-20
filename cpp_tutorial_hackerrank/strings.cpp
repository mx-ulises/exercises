#include <iostream>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    char aux;
    cin >> s1 >> s2;

    cout << s1.size() << " " << s2.size() << endl;
    cout << s1 + s2 << endl;
    aux = s1[0];
    s1[0] = s2[0];
    s2[0] = aux;
    cout << s1 << " " << s2 << endl;

    return 0;
}
