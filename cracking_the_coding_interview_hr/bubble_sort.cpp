#include <vector>
#include <iostream>

using namespace std;

void swap(vector<int>* A, int i, int j) {
    int aux =  A->at(i);
    A->at(i) = A->at(j);
    A->at(j) = aux;
}

int bubble_sort(vector<int>* A, int n) {
    int swaps = 0;
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        int first_sorted = 0;
        for (int i = first_sorted; i < n - 1; i++) {
            if (A->at(i + 1) < A->at(i)) {
                swap(A, i, i + 1);
                swaps++;
                sorted = false;
            }
        }
        first_sorted++;
    }
    return swaps;
}


int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
       cin >> A[i];
    }
    int swaps = bubble_sort(&A, n);
    cout << "Array is sorted in " << swaps << " swaps." << endl;
    cout << "First Element: " << A[0] << endl;
    cout << "Last Element: " << A[n - 1] << endl;
    return 0;
}
