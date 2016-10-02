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
        int lenght = 16;
        T container[lenght];

        void resize_container(){
            if (this->size == this->lenght) {
                T new_container[lenght * 2];
                for (int i = 0; i < this->lenght; i++) {
                    new_container[i] = this->container[i];
                }
                this->container = new_container;
                this->lenght = this->lenght * 2;
            }
        }


    public:
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
            this->resize_container();
            this->container[this->size] = item;
            this->size++;
        }

};
