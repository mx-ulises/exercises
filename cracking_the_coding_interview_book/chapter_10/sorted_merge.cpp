#include <iostream>

using namespace std;

void merge_sorted(int* A, int n, int* B, int m) {
    int l = n - m;
    for (int i = 0; i < l; i++) {
        int current_i =  l - i - 1;
        int new_i = n - i - 1;
        A[new_i] = A[current_i];
    }
    int i = 0;
    int j = 0;
    int k = m;
    while (i < n) {
        if (j == m) {
            A[i] = A[k];
            k++;
        } else if (k == n) {
            A[i] = B[j];
            j++;
        } else if (A[k] < B[j]) {
            A[i] = A[k];
            k++;
        } else {
            A[i] = B[j];
            j++;
        }
        i++;
    }
}

void print_array(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test(int* A, int n, int* B, int m) {
    cout << "Array A:" << endl;
    print_array(A, n);
    cout << "Array B:" << endl;
    print_array(B, m);
    merge_sorted(A, n, B, m);
    cout << "Array sorted:" << endl;
    print_array(A, n);
}

int main() {
    int A[] = {1, 4, 6, 0, 0, 0, 0};
    int n = 7;
    int B[] = {2, 3, 8, 9};
    int m = 4;
    test(A, n, B, m);
    return 0;
}
