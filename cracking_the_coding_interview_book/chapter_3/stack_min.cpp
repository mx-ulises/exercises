#include <stack>
#include <iostream>

using namespace std;

class StackMin {
    private:
        stack<int> regular;
        stack<int> minimal;

    public:
        void push(int data) {
            regular.push(data);
            if (minimal.empty() || data <= minimal.top()) {
                minimal.push(data);
            }
        }

        void pop() {
            int data = regular.top();
            if (data == minimal.top()) {
                minimal.pop();
            }
            regular.pop();
        }

        int top() {
            return regular.top();
        }

        int min() {
            return minimal.top();
        }
};

void test (int* A, int n) {
    StackMin sm;
    for (int i = 0; i < n; i++) {
        cout << "Insert: " << A[i] << endl;
        sm.push(A[i]);
        cout << "Top: " << sm.top() << ", Min: " << sm.min() << endl;
    }

    for (int i = 0; i < n - 1; i++) {
        cout << "Pop " << endl;
        sm.pop();
        cout << "Top: " << sm.top() << ", Min: " << sm.min() << endl;
    }
    cout << endl;
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
