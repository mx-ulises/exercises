#include <iostream>

using namespace std;

string nums [9] = {"one", "two", "three", "four", "five", "six", "seven",
                   "eight", "nine"};
string type [2] = {"even", "odd"};

int main() {
    int a, b;
    cin >> a;
    cin >> b;
    for (a; a <= b; a++) {
        if (a < 10) cout << nums[a - 1] << endl;
        else cout << type[a % 2] << endl;
    }
    return 0;
}
