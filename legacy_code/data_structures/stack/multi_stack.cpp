#include <exception>
#include <utility>
#include <iostream>

using namespace std;

class StackException: public exception {

    virtual const char* what() const throw() {
        return "Stack exception";
    }

};

template <class T> class MultiStack {
    private:
        pair<int, T*>* A[100];
        int push_pointer = 0;
        int p[3] = {-1, -1, -1};

        bool available_spot(int i) {
            if (this->p[i] + 1 < 100 && this->A[this->p[i] + 1] == NULL) {
                return true;
            }
            return false;
        }

        bool check_valid_stack(int i) {
            if (0 <= i && i < 3) {
                return true;
            }
            return false;
        }

        void update_push_pointer() {
            if (this->available_spot(0)) {
                this->push_pointer = p[0] + 1;
            } else if (this->available_spot(1)) {
                this->push_pointer = p[1] + 1;
            } else if (this->available_spot(2)){
                this->push_pointer = p[2] + 1;
            } else {
                this->push_pointer = 100;
            }
        }

    public:
        void push(int stack_index, T* data) {
            if (this->check_valid_stack(stack_index) && !this->full()) {
                pair<int, T*>* item = new pair<int, T*>(this->p[stack_index], data);
                this->A[this->push_pointer] = item;
                this->p[stack_index] = this->push_pointer;
                this->update_push_pointer();
            }
        }

        T* pop(int stack_index) {
            if (this->check_valid_stack(stack_index) && !this->empty()) {
                pair<int, T*>* item = this->A[this->p[stack_index]];
                this->A[this->p[stack_index]] = NULL;
                this->p[stack_index] = item->first;
                T* data = item->second;
                delete item;
                this->update_push_pointer();
                return data;
            } else {
                return NULL;
            }
        }

        bool full() {
            if (this->push_pointer == 100) {
                return true;
            }
            return false;
        }

        bool empty() {
            for (int i = 0; i < 3; i++) {
                if (this->p[0] != -1) {
                    return false;
                }
            }
            return true;
        }

        void print_stack() {
            cout << "Push Pointer: " << this->push_pointer << endl;
            cout << "Stack pointers: ";
            for (int i = 0; i < 3; i++) {
                cout << "p[" << i << "]: " << this->p[i] << "    ";
            }
            cout << endl << endl;
        }
};

void push_print(MultiStack<int>* ms, int i, int* data) {
    cout << "PUSH value in stack " << i << " is: "<< *data << endl;
    ms->push(i, data);
    ms->print_stack();
}

void pop_print(MultiStack<int>* ms, int i) {
    int* data = ms->pop(i);
    if (data == NULL) {
        cout << "POP value in stack " << i << " is: NULL" << endl;
    } else {
        cout << "POP value in stack " << i << " is: " << *data << endl;
    }
    ms->print_stack();
}

int main() {
    MultiStack<int> ms = MultiStack<int>();
    ms.print_stack();
    int x = 1;
    int y = 2;
    int z = 3;
    push_print(&ms, 1, &x);
    push_print(&ms, 2, &y);
    push_print(&ms, 0, &z);
    pop_print(&ms, 0);
    pop_print(&ms, 0);
    return 0;
}
