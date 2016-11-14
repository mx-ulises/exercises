#include <iostream>
#include "common_bm.cpp"

using namespace std;

int conversion(int n, int m) {
    int delta = n ^ m;
    int count = 0;
    while (delta != 0) {
        if (get_bit(delta, 0))
            count++;
        delta = lsr(delta, 1);
    }
    return count;
}

void test(int n, int m) {
    cout << "n: '" << n << "'" << endl;
    cout << "m: '" << m << "'" << endl;
    cout << "delta: '" << conversion(n, m) << "'" << endl;
    cout << "========================================" << endl;
}

int main() {
    test(16, 15);
    test(3, 2);
    test(-1, 0);
    test(-1, 2147483647);
    return 0;
}
