template <class T> class Node {
    public:
        T data;
        Node<T>* succesor;

        Node(T data) {
            this->data = data;
            this->succesor = NULL;
        }

};

template <class T> class LinkedList {
    private:
        Node<T>* last;

    public:
        LinkedList() {
            this->last = NULL;
        }

        bool is_empty() {
            bool out = false;
            if (this->last == NULL) {
                out = true;
            }
            return out;
        }

        void insert(T data) {
            Node<T> element = new Node<T>(data);
            element->succesor = this->last;
            this->last = element;
        }

        void remove() {
            this->last = this->last->succesor;
        }

        T front() {
            return this->last->data;
        }

};
