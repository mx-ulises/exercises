#include <iostream>

using namespace std;

int multiply_handler(int minimal, int maximal) {
    if (minimal == 0)
        return 0;
    if (minimal == 1)
        return maximal;
    int new_minimal = minimal >> 1;
    int current_sum = multiply_handler(new_minimal, maximal);
    current_sum += current_sum;
    if (minimal != (new_minimal << 1))
        current_sum += maximal;
    return current_sum;
}

int multiply(int a, int b) {
    int maximal;
    int minimal;
    if (a < b) {
        minimal = a;
        maximal = b;
    } else {
        minimal = b;
        maximal = a;
    }
    return multiply_handler(minimal, maximal);
}

void test(int a, int b) {
    cout << a << " x " << b << " = " << multiply(a, b) << endl;
}

int main() {
    test(10, 20);
    test(7, 2);
    test(0, 5);
    test(5, 0);
    test(100, 25);
}
