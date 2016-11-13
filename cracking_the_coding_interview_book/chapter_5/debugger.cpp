#include <iostream>

using namespace std;

void check_is_power_of_two(int n) {
    bool is_power = (n & (n - 1));
    if (is_power == 0)
        cout << "Number '" << n << "' is power of two (or 0)" << endl;
    else
        cout << "Number '" << n << "' is NOT power of two (or 0)" << endl;
}

int main() {
    cout << "Positive test cases" << endl;
    check_is_power_of_two(0);
    check_is_power_of_two(1);
    check_is_power_of_two(2);
    check_is_power_of_two(8);
    check_is_power_of_two(64);
    cout << "Negative test cases" << endl;
    check_is_power_of_two(10);
    check_is_power_of_two(5);
    check_is_power_of_two(27);
    check_is_power_of_two(66);
    check_is_power_of_two(128 + 256);
}
