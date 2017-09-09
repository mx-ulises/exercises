#include <iostream>
#include <math.h>

using namespace std;

int main(){
    long long n, a, t, x;
    cin >> n;
    a = floor(log2(floor((n - 1) / 3) + 1));
    x = 3 * exp2(a);
    t = x - 2;
    cout << (x - n + t);
    return 0;
}
