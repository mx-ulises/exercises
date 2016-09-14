#include <iostream>

using namespace std;

void update(int *a, int *b) {
    int aux = *a + *b;
    *b = abs(*a - *b);
    *a = aux;
}

int main() {
    int a, b;
    cin >> a >> b;
    update(&a, &b);
    cout << a << endl << b << endl;
    return 0;
}
