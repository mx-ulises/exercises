#include <iostream>
#include <bitset>
#include <math.h>

#include "common_bm.cpp"

using namespace std;

int next_num(int n) {
    int upper_bound = ((int)(log2(n))) + 1;
    int i = 0;
    int one_count = 0;
    while (i <= upper_bound) {
        if (get_bit(n, i) == true && get_bit(n, i + 1) == false) {
            n = set_bit(n, i + 1);
            n = clear_bit(n, i);
            break;
        }
        if (get_bit(n, i)) {
            n = clear_bit(n, i);
            one_count++;
        }
        i++;
    }
    for (int j = 0; j < one_count; j++) {
        n = set_bit(n, j);
    }
    return n;
}

int prev_num(int n) {
    int upper_bound = ((int)(log2(n))) + 1;
    int i = 0;
    int one_count = 0;
    while (i <= upper_bound) {
        if (get_bit(n, i) == false && get_bit(n, i + 1) == true) {
            n = set_bit(n, i);
            n = clear_bit(n, i + 1);
            break;
        }
        if (get_bit(n, i)) {
            n = clear_bit(n, i);
            one_count++;
        }
        i++;
    }
    for (int j = 0; j < one_count; j++) {
        n = set_bit(n, i - j - 1);
    }
    return n;
}

void test(int n) {
    cout << "previous: " << bitset<32>(prev_num(n)) << " " << prev_num(n) << endl;
    cout << "original: " << bitset<32>(n) << " " << n << endl;
    cout << "next:     " << bitset<32>(next_num(n)) << " " << next_num(n) << endl << endl;
}

int main() {
    test(0b01);
    test(0b11101);
    test(0b011);
    test(0b11110);
    test(0b1110110000);
    return 0;
}
