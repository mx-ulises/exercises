#include <vector>
#include <iostream>

using namespace std;

long long make_change(int n, vector<int> coins) {
    vector<long long> combs(n + 1);
    combs[0] = 1;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = 0; j <= n - coins[i]; j++) {
            combs[j + coins[i]] += combs[j];
        }
    }
    return combs[n];
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> coins(m);
    for(int i = 0; i < m; i++){
       cin >> coins[i];
    }
    cout << make_change(n, coins) << endl;
    return 0;
}
