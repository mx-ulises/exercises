#include <iostream>
#include <bitset>

using namespace std;

int clear(int n, int i, int j) {
    int mask = (-1 << (j - i + 1));
    mask = (~mask) << i;
    return n & ~mask;
}

int insertion(int n, int m, int i, int j) {
    int new_n = clear(n, i, j);
    new_n += (m << i);
    return new_n;
}

void test(int n, int m, int i, int j) {
    cout << "N: " << bitset<32>(n) << endl;
    cout << "M: " << bitset<32>(m) << endl;
    cout << "i: " << i << ", j: " << j << endl;
    cout << "R: "<< bitset<32>(insertion(n, m, i, j)) << endl << endl;
}

int main() {
    test(-1, 0b0011100, 3, 10);
    return 0;
}
