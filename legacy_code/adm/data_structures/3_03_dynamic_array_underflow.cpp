// Dynamic Array with Underflow (ADM-3.3)

#include <vector>
#include <iostream>

using namespace std;

class DynamicArray {
    private:
        int capacity;
        int size;
        int* A;

        int* copy_array(int* A, int new_capacity, int max_index){
            cout << "Resize" << endl;
            int* B = new int[new_capacity];
            for (int i = 0; i < max_index; i++) {
                B[i] = A[i];
            }
            return B;
        }

        void increase_capacity() {
            if (size == capacity) {
                int new_capacity = capacity * 2;
                A = copy_array(A, new_capacity, size);
                capacity = new_capacity;
            }
        }

        void reduce_capacity() {
            if (size < capacity / 4) {
                int new_capacity = capacity / 2;
                A = copy_array(A, new_capacity, size);
                capacity = new_capacity;
            }
        }

    public:
        DynamicArray(void) {
            capacity = 2;
            A = new int[2];
            size = 0;
        }

        void add(int a) {
            A[size] = a;
            size++;
            increase_capacity();
        }

        void remove() {
            size--;
            reduce_capacity();
        }

        int get(int i) {
            return A[i];
        }

        int get_capacity() {
            return capacity;
        }

        int get_size() {
            return size;
        }
};

void print_array(DynamicArray* A) {
    cout << "Capacity: " << A->get_capacity() << endl;
    for (int i = 0; i < A->get_size(); i++) {
        cout << A->get(i) << " ";
    }
    cout << endl << endl;
}

void add(DynamicArray* A, int a) {
    A->add(a);
    print_array(A);
}

void remove(DynamicArray* A) {
    A->remove();
    print_array(A);
}

int main() {
    DynamicArray* A = new DynamicArray();
    add(A, 1);
    add(A, 2);
    add(A, 3);
    add(A, 4);
    add(A, 5);
    add(A, 6);
    add(A, 7);
    add(A, 8);
    add(A, 9);
    add(A, 10);
    remove(A);
    remove(A);
    remove(A);
    remove(A);
    remove(A);
    remove(A);
    remove(A);
    remove(A);
    remove(A);
    remove(A);
    return 0;
}
