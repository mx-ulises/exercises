#include <iostream>
#include <vector>

using namespace std;

int get_left_index(vector<string>* A, int i) {
    while (i < A->size() && (*A)[i] == "") {
        i++;
    }
    return i;
}

int get_right_index(vector<string>* A, int i) {
    while (0 <= i && (*A)[i] == "") {
        i--;
    }
    return i;
}

int sparse_search(vector<string>* A, string x) {
    int left = get_left_index(A, 0);
    int right = get_right_index(A, A->size() - 1);
    while (left <= right) {
        int mid = get_left_index(A, (left + right) / 2);
        if (x == (*A)[mid])
            return mid;
        if (x < (*A)[mid])
            right = get_right_index(A, mid - 1);
        else
            left = get_left_index(A, mid + 1);
    }
    return -1;
}

void test(vector<string>* A, string x) {
    cout << "Position of '" << x << "' is " << sparse_search(A, x) << endl;
}

int main() {
    vector<string> A;
    A.push_back("at");
    A.push_back("");
    A.push_back("");
    A.push_back("");
    A.push_back("ball");
    A.push_back("");
    A.push_back("");
    A.push_back("car");
    A.push_back("");
    A.push_back("");
    A.push_back("dad");
    A.push_back("");
    A.push_back("");
    test(&A, "ball");
    test(&A, "a");
    test(&A, "at");
    test(&A, "dad");
    return 0;
}
