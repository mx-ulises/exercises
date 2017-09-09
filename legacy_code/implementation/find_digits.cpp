#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n, count;
        string s;
        count = 0;
        cin >> n;
        s = to_string(n);
        for (int j = 0; j < s.length(); j++) {
            int c = s.at(j) - '0';
            if (c > 0 && n % c == 0) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
