#include <iostream>

using namespace std;

void fruit_print(int p, int n, int s, int t) {
    int d, count = 0;
    for (int i = 0; i < n; i++){
        cin >> d;
        if (s <= (d + p) && (d + p) <= t)
            count++;
    }
    cout << count << endl;
}

int main(){
    int s, t;
    cin >> s >> t;
    int a, b;
    cin >> a >> b;
    int m, n;
    cin >> m >> n;
    fruit_print(a, m, s, t);
    fruit_print(b, n, s, t);
    return 0;
}
