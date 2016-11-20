#include <set>
#include <vector>
#include <iostream>

using namespace std;

int coin_change(set<int> coins, int n) {
    vector<int> ways(n + 1);
    ways[0] = 1;
    for (set<int>::iterator c_p = coins.begin(); c_p != coins.end(); c_p++) {
        int c = (*c_p);
        int i = 0;
        while (i <= (n - c)) {
            ways[i + c] += ways[i];
            i++;
        }
    }
    return ways[n];
}

void test(set<int> coins, int n) {
    int ways = coin_change(coins, n);
    cout << "Ways to form " << n << " is " << ways << endl;
}

int main() {
    set<int> coins;
    coins.insert(2);
    coins.insert(4);
    coins.insert(6);
    test(coins, 5);
    return 0;
}
