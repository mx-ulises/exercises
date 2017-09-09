#include <math.h>
#include <iostream>

using namespace std;

bool is_prime(int x) {
    if (x <= 1) return false;
    int x_sqrt = sqrt(x);
    for (int d = 2; d <= x_sqrt; d++) {
        if (x % d == 0) return false;
    }
    return true;
}

int main(){
    int p;
    cin >> p;
    for(int i = 0; i < p; i++){
        int x;
        cin >> x;
        if (is_prime(x)) cout << "Prime" << endl;
        else cout << "Not prime" << endl;
    }
    return 0;
}
