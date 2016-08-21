#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int a;
    long b;
    long long c;
    char d;
    float e;
    double f;
    cin >> a;
    cout << a << endl;
    cin >> b;
    cout << b << endl;
    cin >> c;
    cout << c << endl;
    cin >> d;
    cout << d << endl;
    cin >> e;
    cout << fixed << setprecision(3) << e << endl;
    cin >> f;
    cout << fixed << setprecision(9) << f << endl;
    return 0;
}
