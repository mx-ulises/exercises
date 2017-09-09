#include <iostream>

using namespace std;

class ThreeStack {
    private:
        int single_cap;
        int* pointers;
        int* buffer;

        void move_value(int* new_buffer, int new_single_cap, int stack_index, int i) {
            int j = new_single_cap * stack_index + i;
            int k = single_cap * stack_index + i;
            new_buffer[j] = buffer[k];
        }

        void ensure_cap(int p) {
            if (p == single_cap) {
                int new_single_cap = single_cap * 2;
                int* new_buffer = new int[new_single_cap * 3];
                for (int i = 0; i < single_cap; i++) {
                    move_value(new_buffer, new_single_cap, 0, i);
                    move_value(new_buffer, new_single_cap, 1, i);
                    move_value(new_buffer, new_single_cap, 2, i);
                }
                buffer = new_buffer;
                single_cap = new_single_cap;
            }
        }

        int get_index(int stack_index) {
            int p = pointers[stack_index];
            return stack_index * single_cap + p;
        }

        void set_value(int stack_index, int value) {
            int i = get_index(stack_index);
            buffer[i] = value;
        }

    public:
        ThreeStack() {
            single_cap = 2;
            pointers = new int[3];
            for (int i = 0; i < 3; i++) {
                pointers[i] = 0;
            }
            buffer = new int[3 * single_cap];
        }

        void push(int stack_index, int value) {
            int i = pointers[stack_index];
            ensure_cap(pointers[stack_index]);
            set_value(stack_index, value);
            pointers[stack_index]++;
        }

        void pop(int stack_index) {
            if (pointers[stack_index] < 1)
                return;
            pointers[stack_index]--;
        }

        int top(int stack_index) {
            if (pointers[stack_index] < 1)
                return -1;
            return buffer[get_index(stack_index) - 1];
        }

        void print() {
            for (int i = 0; i < 3; i++) {
                cout << "Stack " << i << ": ";
                for (int j = 0; j < pointers[i]; j++) {
                    int k = i * single_cap + j;
                    cout << buffer[k] << " ";
                }
                cout << endl;
            }
        }
};

void print_line() {
    cout << "===================================================" << endl << endl;
}

int main() {
    ThreeStack s = ThreeStack();
    s.push(0, 1);
    s.push(0, 2);
    s.push(1, 3);
    s.print();
    print_line();
    s.push(0, 4);
    s.push(0, 5);
    s.push(1, 6);
    s.push(2, 7);
    s.print();
    print_line();
    s.pop(0);
    s.print();
    print_line();
    s.pop(1);
    s.pop(2);
    s.print();
    print_line();
    return 0;
}
