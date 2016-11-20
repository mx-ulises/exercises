#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> A, int a) {
    int max_index = A.size() - 1;
    int min_index = 0;
    while (min_index <= max_index) {
        int mid_index = (max_index + min_index) / 2;
        if (A[mid_index] == a) {
            return mid_index;
        } else if (a < A[mid_index]) {
            max_index = mid_index - 1;
        } else {
            min_index = mid_index + 1;
        }
    }
    return -1;
}

void print_array(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test(vector<int> A, int a) {
    cout << "Value '" << a << "' at index " <<  binary_search(A, a) << endl;
}

int main() {
    vector<int> A;
    A.push_back(1);
    A.push_back(3);
    A.push_back(5);
    A.push_back(7);
    A.push_back(9);
    A.push_back(11);
    A.push_back(13);
    A.push_back(15);
    print_array(A);
    test(A, 1);
    test(A, 3);
    test(A, 5);
    test(A, 7);
    test(A, 9);
    test(A, 11);
    test(A, 13);
    test(A, 15);
    test(A, 2);
    test(A, 0);
    test(A, 16);
}
