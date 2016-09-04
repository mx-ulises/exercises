#include <iostream>

using namespace std;

float find_sqrt(float n){
	float left, right, x, n_new;
	left = 0;
	right = n;
	x = (left + right) / 2;
	n_new = x * x;
	while (n_new != n) {
		if (n_new < n) {
			left = x;
		} else {
			right = x;
		}
		x = (left + right) / 2;
		n_new = x * x;
	}
	return x;
}

int main() {
	float n = 259.321;
    cout << find_sqrt(259.321) << endl;
    return 0;
}
