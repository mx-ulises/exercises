#include <iostream>
#include <bitset>

#define EVEN 0xAAAAAAAA
#define ODD  0x55555555

using namespace std;

int pairwise_swap(int n) {
    int n_even = (n & EVEN) >> 1;
    int n_odd = (n & ODD) << 1;
    return (n_even | n_odd);
}


void test(int n) {
    int m = pairwise_swap(n);
    cout << "original: " << bitset<32>(n) << endl;
    cout << "swapped:  " << bitset<32>(m) << endl << endl;
}

int main() {
    test(0b111010101011100);
    test(0b000000000000000);
    test(EVEN);
    test(ODD);
    return 0;
}
