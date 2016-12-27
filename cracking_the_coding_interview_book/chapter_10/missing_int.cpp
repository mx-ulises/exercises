#include <stdlib.h>
#include <stdint.h>
#include <iostream>

using namespace std;

int main() {
    unsigned int max_value = 1024;
    unsigned int bucket_num = (max_value / 8);
    unsigned char bit_set[bucket_num];
    // Clear array
    for (unsigned int i = 0; i < bucket_num; i++) {
        cout << i << endl;
        bit_set[i] = 0;
    }
    // Add numbers
    for (unsigned int i = 2; i < max_value; i++) {
        unsigned int n = rand() % 1024;
        bit_set[n / 8] = bit_set[n / 8] | (1 << (n % 8));
    }
    // Get missing nums
    for (unsigned int i = 0; i < bucket_num; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            if ((bit_set[i] & (1 << j)) == 0) {
                unsigned int n = i * 8 + j;
                cout << "Missing num: " << n << endl;
            }
        }
    }
    return 0;
}
