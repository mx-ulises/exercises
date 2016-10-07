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

bool has_cycle_2(Node* head) {
    if (head == NULL) return false;
    Node* fast = head->next;
    Node* slow = head;
    while (fast != NULL && fast->next != NULL) {
        if (fast == slow) return true;
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}
