#include <iostream>

using namespace std;

string nums [9] = {"one", "two", "three", "four", "five", "six", "seven",
                   "eight", "nine"};

int main() {
    int n;
    cin >> n;
    if (n < 10) cout << nums[n - 1] << endl;
    else cout << "Greater than 9" << endl;
    return 0;
}
