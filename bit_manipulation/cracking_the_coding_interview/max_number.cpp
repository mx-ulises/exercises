#include <iostream>
#include <math.h>
#include <limits>
#include "bit_man_lib.cpp"

using namespace std;

int max(int a, int b){
    int k = is_negative(a - b);
    return (b * k) - (a * (k - 1));
}

void print_max(int a, int b) {
    cout << "max(" << a << ", " << b << ") = " << max(a, b) << endl;
}

int main(){
    print_max(5, 10);
    print_max(5, -1);
    print_max(10, -200);
    print_max(-5, -1);
    return 0;
}
