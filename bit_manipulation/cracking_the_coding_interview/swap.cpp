#include <iostream>

using namespace std;

int swap(int *a, int *b) {
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void print_swap(int a, int b) {
    cout << "swap(" << a << ", " << b << ") = ";
    swap(&a, &b);
    cout << "(" << a << ", " << b << ")" << endl;
}

int main(){
    print_swap(5, 10);
    print_swap(5, -1);
    print_swap(10, -200);
    print_swap(-5, -1);
    return 0;
}
