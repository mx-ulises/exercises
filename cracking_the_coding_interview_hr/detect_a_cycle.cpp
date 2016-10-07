#include <set>

using namespace std;

bool has_cycle(Node* head) {
    set<Node*> s;
    Node* current = head;
    while (current != NULL) {
        if (s.find(current) != s.end()) return true;
        s.insert(current);
        current = current->next;
    }
    return false;
}
