#include <iostream>
#include <vector>
#include <queue>
#include <util>

using namespace std;

int dijkstra(vector<Node*>* G, int initial, int target) {
    // get the nodes from the graph
    Node* root = G[initial];
    Node* sink = G[target];

    // Initialize Open and closed list
    pair<int, Node*> s_0(0, root);
    priority_queue<pair<int, Node*>> Open;
    set<Node*> Closed;
    Open.push(s_0);

    // Iterate until impossible to find
    while (!Open.empty()) {
        // Get first pair distance, node
        pair<int, Node*> s = Open.top();
        Open.pop();
        Node* x = s.second;
        int d = s.first * -1;

        // Check if found and return current distance if so
        if (x == sink) return d;

        // Check if node in close, and skip if so
        if (Closed.find(x) != Closed.end()) continue;

        // Add Children
        for (int i = 0; i < x->children.size(); i++) {
            pair<Node*, int> child = x->children[i];
            Node* y = child.first;
            int d_1 = child.second;
            pair<int, Node*> s_1((d + d_1) * -1, y);
            Open.push(s_1);
        }

        // Closing the node
        Closed.insert(x);
    }

    // Unable to find, return -1
    return -1;
}
