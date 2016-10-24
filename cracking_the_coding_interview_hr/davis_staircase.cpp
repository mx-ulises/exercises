#include <vector>
#include <iostream>

using namespace std;

int count_ways(vector<int>* ways, int n) {
    if (n < 0) return 0;
    if ((*ways)[n] > 0) return (*ways)[n];
    (*ways)[n] = count_ways(ways, n - 1) + count_ways(ways, n - 2) + count_ways(ways, n - 3);
    return (*ways)[n];
}

int count_ways(int n) {
    vector<int> ways(n + 1);
    ways[0] = 1;
    return count_ways(&ways, n);
}

int main(){
    int s;
    cin >> s;
    for(int i = 0; i < s; i++){
        int n;
        cin >> n;
        cout << count_ways(n) << endl;
    }
    return 0;
}
