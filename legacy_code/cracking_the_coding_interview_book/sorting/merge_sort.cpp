#include <iostream>
#include <stdlib.h>

using namespace std;

void merge(int* A, int start, int mid, int end) {
    int size = end - start + 1;
    int* helper = new int[size];
    int i = start;
    int j = mid + 1;
    for (int index = 0; index < size; index++) {
        if (mid < i) {
            helper[index] = A[j];
            j++;
        } else if (end < j) {
            helper[index] = A[i];
            i++;
        } else if (A[i] < A[j]) {
            helper[index] = A[i];
            i++;
        } else {
            helper[index] = A[j];
            j++;
        }
    }
    for (int index = 0; index < size; index++) {
        A[start + index] = helper[index];
    }
    delete helper;
}

void merge_sort(int* A, int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        merge_sort(A, start, mid);
        merge_sort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

void merge_sort(int* A, int n) {
    merge_sort(A, 0, n - 1);
}

void print_array(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test(int* A, int n) {
    print_array(A, n);
    merge_sort(A, n);
    print_array(A, n);
}

int main() {
    int n = 15;
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
    test(A, n);
    return 0;
}
