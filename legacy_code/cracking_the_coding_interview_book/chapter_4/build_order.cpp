#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <set>

using namespace std;

class Node {
    public:
        int data;
        vector<Node*> children;

        Node (int data) {
            this->data = data;
        }

        void add_adjacent(Node* node) {
            children.push_back(node);
        }
};

class Graph {
    public:
        map<int, Node*> nodes;

        void insert_node(int data) {
            if (nodes.find(data) == nodes.end()) {
                Node* node = new Node(data);
                nodes[data] = node;
            }
        }

        void add_edge(int node_1, int node_2) {
            nodes[node_1]->add_adjacent(nodes[node_2]);
        }

};

void dfs(Node* s, set<Node*>* visited, stack<Node*>* inverse_order) {
    if (visited->find(s) != visited->end())
        return;
    visited->insert(s);
    for (int i = 0; i < s->children.size(); i++) {
        Node* t = s->children[i];
        dfs(t, visited, inverse_order);
    }
    inverse_order->push(s);
}

vector<Node*>* get_topo_order(Graph* g) {
    set<Node*> visited;
    stack<Node*> inverse_order;
    for (int i = 0; i < g->nodes.size(); i++) {
        Node* s = g->nodes[i];
        dfs(s, &visited, &inverse_order);
    }

    vector<Node*>* topo_order = new vector<Node*>();
    while(!inverse_order.empty()) {
        topo_order->push_back(inverse_order.top());
        inverse_order.pop();
    }
    return topo_order;
}

void test(Graph* g) {
    vector<Node*>* topo_order = get_topo_order(g);
    for (int i = 0; i < topo_order->size(); i++) {
        cout << (*topo_order)[i]->data << " ";
    }
    cout << endl;
}

int main() {
    Graph* g = new Graph();
    for (int i = 0; i < 12; i++) {
        g->insert_node(i);
    }
    g->add_edge(0, 2);
    g->add_edge(1, 3);
    g->add_edge(1, 8);
    g->add_edge(1, 2);
    g->add_edge(2, 9);
    g->add_edge(3, 11);
    g->add_edge(4, 10);
    g->add_edge(5, 6);
    g->add_edge(6, 3);
    g->add_edge(7, 6);
    g->add_edge(7, 1);
    g->add_edge(8, 9);

    test(g);
    return 0;
}
