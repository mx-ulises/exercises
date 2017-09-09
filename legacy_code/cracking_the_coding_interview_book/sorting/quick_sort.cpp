#include <iostream>
#include <stdlib.h>

using namespace std;

void swap(int* A, int left, int right) {
    int aux = A[left];
    A[left] = A[right];
    A[right] = aux;
}

int partition(int* A, int left, int right) {
    int mid = (left + right) / 2;
    int pivot = A[mid];
    while (left <= right) {
        while (A[left] < pivot)
            left++;
        while (pivot < A[right])
            right--;
        if (left <= right) {
            swap(A, left, right);
            left++;
            right--;
        }
    }
    return left;
}

void quick_sort(int* A, int left, int right) {
    int index = partition(A, left, right);
    if (left < (index - 1))
        quick_sort(A, left, index - 1);
    if (index < right)
        quick_sort(A, index, right);
}

void quick_sort(int* A, int n) {
    quick_sort(A, 0, n - 1);
}

void print_array(int* A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void test(int* A, int n) {
    print_array(A, n);
    quick_sort(A, n);
    print_array(A, n);
}

int main() {
    int n = 5;
    int* A = new int[n];
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
    }
    test(A, n);
    return 0;
}
