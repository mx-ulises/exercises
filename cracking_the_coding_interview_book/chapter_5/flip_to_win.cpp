#include <iostream>
#include <algorithm>

using namespace std;

int flip_to_win(int n) {
    int prev = 0;
    int streak = 1;
    int curr = 0;
    while (n != 0) {
        if (n % 2 == 0) {
            streak = max(streak, prev + curr + 1);
            prev = curr;
            curr = 0;
        } else {
            curr++;
        }
        n = n / 2;
    }
    streak = max(streak, prev + curr + 1);
    return streak;
}

void test(int n, int expected) {
    cout << "Flip to win = " << flip_to_win(n) << " expected " << expected << endl;
}

int main() {
    test(0b00011111101111000111010, 11);
    test(0, 1);
    test(0b0001111, 5);
    test(0b0001111001111, 5);
    test(0b0001111011111, 10);
    return 0;
}
