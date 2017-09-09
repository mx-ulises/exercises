#include <stack>
#include <iostream>

using namespace std;

class StackQueue {
    private:
        stack<int> enq;
        stack<int> deq;

        void fill_deq(){
            if (deq.empty()) {
                while (!enq.empty()) {
                    deq.push(enq.top());
                    enq.pop();
                }
            }
        }

    public:
        void enqueue(int data) {
            enq.push(data);
        }

        void dequeue() {
            fill_deq();
            deq.pop();
        }

        int front() {
            fill_deq();
            return deq.top();
        }
};

void test(int* A, int n) {
    StackQueue sq;
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
        sq.enqueue(A[i]);
    }
    cout << endl;
    for (int i = 0; i < n; i++) {
        cout << sq.front() << " ";
        sq.dequeue();
    }
    cout << endl << endl;
}

int main() {
    int A[] = {1, 2, 3, 1, 2, 3};
    test(A, 6);
    int B[] = {5, 4, 3, 4, 3, 2, 1, 5};
    test(B, 8);
    int C[] = {1, 1, 1, 1};
    test(C, 4);
    int D[] = {4, 3, 2, 1};
    test(D, 4);
}
