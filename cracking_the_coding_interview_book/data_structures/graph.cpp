#include <vector>
#include <map>
#include <stack>
#include <iostream>
#include <set>
#include <queue>
#include <utility>

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

void print_line() {
    cout << "===========================================" << endl;
}

void print_node(Node* node, int d) {
    for (int i = 0; i < d; i++) {
        cout << " ";
    }
    cout << node->data << endl;
}

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

void dfs(Graph* g, int value) {
    cout << "DFS starting from " << value << endl;
    Node* node = g->nodes[value];
    pair<Node*, int> s_0(node, 0);
    stack<pair<Node*, int>> open;
    set<Node*> closed;
    open.push(s_0);
    while (!open.empty()) {
        pair<Node*, int> x = open.top();
        open.pop();
        node = x.first;
        if (closed.find(node) != closed.end())
            continue;
        for (int i = 0; i < node->adjacent.size(); i++) {
            Node* node_1 = node->adjacent[i];
            pair<Node*, int> y(node_1,  x.second + 1);
            open.push(y);
        }
        print_node(node, x.second);
        closed.insert(node);
    }
    print_line();
}

void bfs(Graph* g, int value) {
    cout << "BFS starting from " << value << endl;
    Node* node = g->nodes[value];
    pair<Node*, int> s_0(node, 0);
    queue<pair<Node*, int>> open;
    set<Node*> closed;
    open.push(s_0);
    while (!open.empty()) {
        pair<Node*, int> x = open.front();
        open.pop();
        node = x.first;
        if (closed.find(node) != closed.end())
                    continue;
        for (int i = 0; i < node->adjacent.size(); i++) {
            Node* node_1 = node->adjacent[i];
            pair<Node*, int> y(node_1, x.second + 1);
            open.push(y);
        }
        print_node(node, x.second);
        closed.insert(node);
    }
    print_line();
}

int main() {
    Graph* g = new Graph();
    for (int i = 0; i < 6; i++) {
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
    g->add_edge(4, 5);
    print_nodes(g);
    print_line();
    dfs(g, 0);
    dfs(g, 2);
    dfs(g, 1);
    print_line();
    bfs(g, 0);
    bfs(g, 2);
    bfs(g, 1);
    return 0;
}
