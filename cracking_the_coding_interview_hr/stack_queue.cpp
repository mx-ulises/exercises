#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    private:
        stack<int> s_1;
        stack<int> s_2;

        void transfere() {
            while (!s_2.empty()) {
                s_1.push(s_2.top());
                s_2.pop();
            }
        }

    public:
        void push(int data) {
            s_2.push(data);
        }

        void pop() {
            if (s_1.empty()) {
                transfere();
            }
            s_1.pop();
        }

        int front() {
            if (s_1.empty()) {
                transfere();
            }
            return s_1.top();
        }
};

int main() {
    MyQueue q;
    int t, type, data;
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> type;
        if (type == 1) {
            cin >> data;
            q.push(data);
        } else if (type == 2) {
            q.pop();
        } else {
            cout << q.front() << endl;
        }
    }
    return 0;
}
