#include <vector>
#include <map>
#include <iostream>

using namespace std;

map<int, int>* count_color(vector<int>* C) {
    map<int, int>* C_count = new map<int, int>();
    for (int i = 0; i < C->size(); i++) {
        int c = (*C)[i];
        (*C_count)[c]++;
    }
    return C_count;
}

int count_pairs(map<int, int>* C_count) {
    int pairs = 0;
    for (map<int, int>::iterator it = C_count->begin(); it != C_count->end(); it++) {
        pairs += it->second / 2;
    }
    return pairs;
}

int main(){
    int n;
    cin >> n;
    vector<int> C(n);
    for (int i = 0; i < n; i++){
       cin >> C[i];
    }
    map<int, int>* C_count = count_color(&C);
    cout << count_pairs(C_count) << endl;
    return 0;
}
