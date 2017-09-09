#include <iostream>

using namespace std;

class MinHeap {
    private:
        int capacity = 16;
        int size = 0;
        int* items;

    int left_child_index(int index) {
        return (2 * index + 1);
    }

    int right_child_index(int index) {
        return (2 * index + 2);
    }

    int parent_index(int index) {
        return ((index - 1) / 2);
    }

    bool has_left_child(int index) {
        return (left_child_index(index) < size);
    }

    bool has_right_child(int index) {
        return (right_child_index(index) < size);
    }

    bool has_parent(int index) {
        return (0 <= parent_index(index));
    }

    int left_child(int index) {
        if (has_left_child(index)) return items[left_child_index(index)];
        return -1;
    }

    int right_child(int index) {
        if (has_right_child(index)) return items[right_child_index(index)];
        return -1;
    }

    int parent(int index) {
        if (has_parent(index)) return items[parent_index(index)];
        return -1;
    }

    void swap(int i, int j) {
        int aux = items[i];
        items[i] = items[j];
        items[j] = aux;
    }

    void ensure_cap() {
        if (size == capacity) {
            capacity = capacity * 2;
            int* aux_items = new int[capacity];
            for (int i = 0; i < size; i++) {
                aux_items[i] = items[i];
            }
            delete items;
            items = aux_items;
        }
    }

    int get_smaller_child_index(int index) {
        int smaller_child_index = left_child_index(index);
        if (has_right_child(index) && right_child(index) < left_child(index)) {
            smaller_child_index = right_child_index(index);
        }
        return smaller_child_index;
    }

    void heapify_down() {
        int index = 0;
        while (has_left_child(index)) {
            int smaller_child_index = get_smaller_child_index(index);
            if (items[index] < items[smaller_child_index]) {
                break;
            }
            swap(index, smaller_child_index);
            index = smaller_child_index;
        }
    }

    void heapify_up() {
        int index = size - 1;
        while (has_parent(index), items[index] < parent(index)) {
            swap(index, parent_index(index));
            index = parent_index(index);
        }
    }

    public:
        MinHeap() {
            items = new int[capacity];
        }

        int top() {
            if (size > 0) return items[0];
            return -1;
        }

        int pop() {
            if (size > 0) {
                int value = items[0];
                items[0] = items[size - 1];
                size--;
                heapify_down();
                return value;
            }
            return -1;
        }

        void push(int value) {
            ensure_cap();
            items[size] = value;
            size++;
            heapify_up();
        }

        int get_size() {
            return size;
        }
};

int main(){
    MinHeap h;
    h.push(10);
    h.push(50);
    h.push(1);
    h.push(3);
    h.push(12);
    h.push(17);
    h.push(22);
    while(0 < h.get_size()) {
        cout << h.pop() << " ";
    }
    cout << endl;
    return 0;
}
