#include <iostream>
#include <vector>

using namespace std;

int element_at(vector<int> A, int i) {
    if (i < A.size()) return A[i];
    return -1;
}

int bs_modified(vector<int> A, int x, int start, int end) {
    while (start <= end) {
        int mid = (start + end) / 2;
        int m = element_at(A, mid);
        if (m == x) return mid;
        if (m == -1 || x < m)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int no_size_search(vector<int> A, int x) {
    int start = 0;
    int growth = 1;
    int end = 0;
    while (element_at(A, end) != -1 && element_at(A, end) < x) {
        start = end;
        end += growth;
        growth *= 2;
    }
    return bs_modified(A, x, start, end);
}

void test(vector<int> A, int x) {
    cout << "Element " << x << " at position " << no_size_search(A, x) << endl;
}

int main() {
    vector<int> A;
    for (int i = 1; i < 18; i++) {
        A.push_back(i);
    }
    test(A, 17);
    test(A, 0);
    test(A, 18);
    test(A, 1);
    test(A, 5);
    test(A, 8);
}
