#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        vector<Node*> adjacent;

        Node (int data) {
            this->data = data;
        }

        void add_adjacent(Node* node) {
            adjacent.push_back(node);
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

void print_node(Node* node) {
    cout << "DATA: " << node->data << endl;
    for (int i = 0; i < node->adjacent.size(); i++) {
        cout << "    " << node->adjacent[i]->data << endl;
    }
    cout << endl;
}

void print_nodes(Graph* g) {
    for (map<int, Node*>::iterator it = g->nodes.begin(); it != g->nodes.end(); it++) {
        cout << "printing node" << endl;
        print_node(it->second);
    }
}

int main() {
    Graph* g = new Graph();
    for (int i = 0; i < 5; i++) {
        g->insert_node(i);
    }
    g->add_edge(0, 1);
    g->add_edge(0, 2);
    g->add_edge(0, 3);
    g->add_edge(0, 4);
    g->add_edge(1, 0);
    g->add_edge(1, 4);
    g->add_edge(2, 2);
    g->add_edge(3, 4);
    g->add_edge(4, 1);

    print_nodes(g);
    return 0;
}
