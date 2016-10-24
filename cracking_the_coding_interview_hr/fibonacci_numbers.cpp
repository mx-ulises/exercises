#include <vector>
#include <iostream>

using namespace std;

long fib(vector<long>* fib_table, int n) {
    if (n == 0 || (*fib_table)[n] > 0) return (*fib_table)[n];
    (*fib_table)[n] = fib(fib_table, n - 1) + fib(fib_table, n - 2);
    return (*fib_table)[n];
}

long fib(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    vector<long> fib_table(n + 1);
    fib_table[0] = 0;
    fib_table[1] = 1;
    return fib(&fib_table, n);
}

long fib_2(int n) {
    long fib_1 = 0;
    long fib_2 = 1;
    for (int i = 2; i <= n; i++) {
        long new_fib = fib_1 + fib_2;
        fib_1 = fib_2;
        fib_2 = new_fib;
    }
    return fib_2;
}

int main() {
    int n;
    cin >> n;
    cout << fib(n);
    return 0;
}
