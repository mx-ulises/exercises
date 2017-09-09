#include <iostream>
#include <vector>

using namespace std;

int binary_search_rotated(int x, vector<int> A) {
    int max = A.size() - 1;
    int min = 0;
    while (min <= max) {
        int mid = (min + max) / 2;
        cout << "   " << mid << ": " << A[mid] << endl;
        if (x == A[mid])
            return mid;
        if (A[mid] <= A[max]) {
            if (A[mid] <= x && x <= A[max])
                min = mid + 1;
            else
                max = mid - 1;
        } else {
            if (A[min] <= x && x <= A[mid])
                max = mid - 1;
            else
                min = mid + 1;
        }
    }
    return -1;
}

void print_vector(vector<int> A) {
    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test(int x, vector<int> A) {
    cout << "==================================" << endl;
    cout << "x = " << x << " in pos " << binary_search_rotated(x, A) << endl;
}

int main() {
    vector<int> A;
    A.push_back(5);
    A.push_back(6);
    A.push_back(7);
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    print_vector(A);
    test(1, A);
    test(6, A);
    test(2, A);
    test(4, A);
    return 0;
}
