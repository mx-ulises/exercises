#include <iostream>
#include "stack.cpp"

using namespace std;

int main() {
    Stack<int> s = Stack<int>();
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    s.push(4);
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
