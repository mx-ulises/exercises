#include <vector>
#include <iostream>

using namespace std;

vector<int> merge_sorted(vector<int> A, vector<int> B) {
    vector<int> C(A.size() + B.size());
    int i = 0;
    int j = 0;
    int k = 0;
    while (i < A.size() || j < B.size()) {
        if (i == A.size()) {
            C[k] = B[j];
            j++;
        } else if (j == B.size()) {
            C[k] = A[i];
            i++;
        } else if (A[i] < B[j]) {
            C[k] = A[i];
            i++;
        } else {
            C[k] = B[j];
            j++;
        }
        k++;
    }
    return C;
}

void print_vector(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test(vector<int> A, vector<int> B) {
    vector<int> C = merge_sorted(A, B);
    print_vector(A);
    print_vector(B);
    print_vector(C);
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    A.push_back(7);
    vector<int> B;
    B.push_back(2);
    B.push_back(2);
    B.push_back(6);
    B.push_back(7);
    test(A, B);
    return 0;
}
