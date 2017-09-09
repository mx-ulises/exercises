#include <iostream>

using namespace std;

int max_of_four(int a, int b, int c, int d) {
    int ans = a;
    if (ans < b) ans = b;
    if (ans < c) ans = c;
    if (ans < d) ans = d;
    return ans;
}

int main() {
    int a, b, c, d, ans;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    ans = max_of_four(a, b, c, d);
    cout << ans;
    return 0;
}
