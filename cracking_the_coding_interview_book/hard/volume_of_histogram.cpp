#include <iostream>
#include <vector>

using namespace std;

int volume(vector<int> A) {
    int n = A.size();
    int left = 0;
    int right = A.size() - 1;
    int maximal = 0;
    int total = 0;
    while (n) {
        int new_max = min(A[left], A[right]);
        if (maximal < new_max) {
            total += ((new_max - maximal) * n);
            maximal = new_max;
        }
        if (new_max == A[left]) left++;
        else right--;
        n--;
    }
    for (int i = 0; i < A.size(); i++) {
        total -= A[i];
    }
    return total;
}

int main() {
    vector<int> A;
    A.push_back(0);
    A.push_back(1);
    A.push_back(3);
    A.push_back(4);
    cout << volume(A) << endl;
    A.push_back(0);
    A.push_back(0);
    A.push_back(6);
    cout << volume(A) << endl;
    A.push_back(0);
    A.push_back(0);
    A.push_back(3);
    cout << volume(A) << endl;
    A.push_back(0);
    A.push_back(5);
    cout << volume(A) << endl;
    A.push_back(0);
    A.push_back(1);
    cout << volume(A) << endl;
    A.push_back(0);
    A.push_back(0);
    A.push_back(0);
    cout << volume(A) << endl;
    return 0;
}
