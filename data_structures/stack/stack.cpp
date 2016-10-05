#include <exception>
using namespace std;

class StackException: public exception {

    virtual const char* what() const throw() {
        return "Stack exception";
    }

};

template <class T> class Stack {

    private:
        int size = 0;
        int length = 1;
        T *container;

        void resize_container(){
            if (this->size == this->length) {
                T *new_container = new T[this->length * 2];
                for (int i = 0; i < this->length; i++) {
                    new_container[i] = this->container[i];
                }
                this->container = new_container;
                this->length = this->length * 2;
                cout << "[INFO] Resize, new length: " << this->length << endl;
            }
        }

    public:

        Stack<T>() {
            this->container = new T[this->length];
        }

        bool empty() {
            return this->size == 0;
        }

        T top() {
            if (this->size == 0) {
                throw StackException();
            }
            return this->container[this->size - 1];
        }

        T pop() {
            T value = this->top();
            //delete &(this->container[this->size - 1]);
            this->size--;
            return value;
        }

        void push(T item) {
            this->resize_container();
            this->container[this->size] = item;
            this->size++;
        }
};

