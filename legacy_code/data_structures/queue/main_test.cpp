#include <iostream>
#include "queue.cpp"

using namespace std;

int main() {
    Queue<int> q = Queue<int>();
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(4);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    return 0;
}
