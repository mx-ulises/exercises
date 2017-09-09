#include <vector>
#include <iostream>

using namespace std;

int get_lonely(vector<int> numbers) {
    int lonely = 0;
    for (int i = 0; i < numbers.size(); i++) {
        lonely = lonely ^ numbers[i];
    }
    return lonely;
}

int main() {
    int k;
    cin >> k;
    vector<int> numbers(k);
    for (int i = 0; i < numbers.size(); i++) {
       cin >> numbers[i];
    }
    cout << get_lonely(numbers) << endl;
    return 0;
}
