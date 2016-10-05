#include <iostream>
#include "resizable_array.cpp"

using namespace std;

void print_array(ResizableArray<int> *A) {
    cout << "Current size: " << A->get_size() << endl;
    for (int i = 0; i < A->get_size(); i++) {
        cout << A->get(i) << " ";
    }
    cout << endl;
}

int main() {
    ResizableArray<int> A = ResizableArray<int>();
    A.insert(1);
    A.insert(2);
    A.insert(3);
    A.insert(4);
    A.insert(5);
    print_array(&A);
    A.insert(7);
    A.insert(8);
    A.insert(9);
    A.set(1, 100);
    print_array(&A);
    A.insert(10);
    A.insert(13);
    A.insert(12);
    print_array(&A);
    return 0;
}
