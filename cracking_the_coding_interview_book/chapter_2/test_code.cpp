#include <iostream>
#include "LinkedList.cpp"

using namespace std;

int find(LinkedList* ll, int n) {
    cout << "Looking for element: " << n << endl;
    if (ll->search(n) != NULL) {
        cout << "Element found" << endl;
    } else {
        cout << "Element not found" << endl;
    }
}

int main() {
    LinkedList ll;
    int n = 8;
    for (int i = 0; i < n; i++) {
        ll.insert(n - i);
    }
    ll.print();
    find(&ll, 8);
    find(&ll, 10);
}
