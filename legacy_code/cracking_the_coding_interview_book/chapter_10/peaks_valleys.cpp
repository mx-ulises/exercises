#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> peaks_valleys(vector<int> A) {
    sort(A.begin(), A.end());
    vector<int> B;
    for (int i = 0; i < (A.size() / 2); i++) {
        B.push_back(A[A.size() - 1 - i]);
        B.push_back(A[i]);
    }
    if ((A.size() % 2) == 1) {
        B.push_back(A[A.size() / 2]);
    }
    return B;
}

void print_vector(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
    vector<int> A;
    A.push_back(10);
    A.push_back(12);
    A.push_back(2);
    A.push_back(3);
    A.push_back(15);
    A.push_back(22);
    A.push_back(7);
    A.push_back(13);
    A.push_back(5);
    print_vector(A);
    A = peaks_valleys(A);
    print_vector(A);
    return 0;
}
