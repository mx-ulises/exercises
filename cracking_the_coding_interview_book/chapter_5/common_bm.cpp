#include <iostream>

using namespace std;

bool get_bit(int n, int i) {
    int mask = (1 << i);
    return ((n & mask) != 0);
}

int set_bit(int n, int i) {
    int mask = (1 << i);
    return (n | mask);
}

int clear_bit(int n, int i) {
    int mask = ~(1 << i);
    return (n & mask);
}

int clear_bits_i_to_ms(int n, int i) {
    int mask = (1 << i) - 1;
    return (n & mask);
}

int clear_bits_0_to_i(int n, int i) {
    int mask = (-1 << (i + 1));
    return (n & mask);
}

int get_bits_i_to_j(int n, int i, int j) {
    int mask = (1 << j) - 1;
    mask = clear_bits_0_to_i(mask, i - 1);
    return (n & mask);
}

int update_bit(int n, int i, int val) {
    int value = val ? 1 : 0;
    int mask = ~(1 << i);
    return ((n & mask) | (value << i));
}
