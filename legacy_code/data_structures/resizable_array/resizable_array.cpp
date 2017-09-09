#include <exception>
using namespace std;

class OutOfBoundException: public exception {

    virtual const char* what() const throw() {
        return "Out of bound exception";
    }

};

template <class T> class ResizableArray {

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

        ResizableArray<T>() {
            this->container = new T[this->length];
        }

        int get_size() {
            return this->size;
        }


        void set(int index, T item) {
            if (index < 0 && this->size <= index) {
                throw OutOfBoundException();
            }
            this->container[index] = item;
        }


        T get(int index) {
            if (index < 0 && this->size <= index) {
                throw OutOfBoundException();
            }
            return this->container[index];
        }


        void insert(T item) {
            cout << "[INFO] Inserting: " << item << endl;
            this->resize_container();
            this->container[this->size] = item;
            this->size++;
        }

};
