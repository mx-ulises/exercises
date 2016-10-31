#include <exception>
#include <iostream>

using namespace std;

class ResizableArray {
    private:
        int size = 8;
        int last = 0;
        int* container;

        void get_space() {
            if (last == size) {
                int* new_container = new int[size * 2];
                for (int i = 0; i < size; i++) {
                    new_container[i] = container[i];
                }
                delete container;
                container = new_container;
                size = size * 2;
            }
        }

    public:

        ResizableArray() {
            container = new int[size];
        }

        bool empty() {
            if (last == 0) return true;
            return false;
        }

        void insert(int data) {
            get_space();
            container[last] = data;
            last++;
        }

        int get(int index) {
            if (index < 0 || last <= index)
                throw;
            return container[index];
        }

        void set(int index, int data) {
            if (index < 0 || last <= index)
                throw;
            container[index] = data;
        }

        int* get_array() {
            int* A = new int[last];
            for (int i = 0; i < last; i++) {
                A[i] = container[i];
            }
            return A;
        }

        int get_size() {
            return last;
        }
};

void print_array(ResizableArray* A) {
    int* arr = A->get_array();
    int n = A->get_size();
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    ResizableArray A;
    A.insert(1);
    print_array(&A);
    for (int i = 0; i < 8; i++) {
        A.insert(i);
    }
    print_array(&A);
    for (int i = 0; i < 27; i++) {
        A.insert(i);
    }
    print_array(&A);
    for (int i = 0; i < 27; i++) {
        A.set(i, 100);
    }
    print_array(&A);
}
