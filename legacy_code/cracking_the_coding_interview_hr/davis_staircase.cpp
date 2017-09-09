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

int count_ways_2(int n) {
    int s_1 = 0;
    int s_2 = 0;
    int s_3 = 1;
    for (int i = 0; i < n; i++) {
        int new_s = s_3 + s_2 + s_1;
        s_1 = s_2;
        s_2 = s_3;
        s_3 = new_s;
    }
    return s_3;
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
