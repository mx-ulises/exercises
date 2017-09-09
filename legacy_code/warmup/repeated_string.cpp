#include <iostream>

using namespace std;

long count_a(string s, long n) {
	long count = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            count++;
        }
    }
    return count;
}

int main(){
    string s;
    long n, count = 0;
    cin >> s;
    cin >> n;
    count = count_a(s, s.length()) * (n / s.length());
    count = count + count_a(s, n % s.length());
    cout << count << endl;
    return 0;
}
