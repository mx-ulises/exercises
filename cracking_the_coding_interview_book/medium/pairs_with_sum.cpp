#include <iostream>
#include <vector>
#include <map>

using namespace std;

void print_pairs(vector<int>* A, int x) {
    map<int, int> count;
    for (int i = 0; i < A->size(); i++) {
        int a = (*A)[i];
        int b = x - a;
        if (count.find(b) != count.end()) {
            for (int j = 0; j < count[b]; j++) {
                cout << "(" << b << ", " << a << ")" << endl;
            }
        }
        count[a]++;
    }
}

void test(vector<int>* A, int x) {
    print_pairs(A, x);
    cout << endl;
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    A.push_back(5);
    A.push_back(6);
    A.push_back(7);
    A.push_back(8);
    test(&A, 9);
    A.push_back(1);
    test(&A, 9);
    A.push_back(8);
    test(&A, 9);
    return 0;
}
