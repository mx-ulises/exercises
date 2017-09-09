#include <queue>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

class Node {
    public:
        bool visited;
        vector<Node*> neighboors;
        int dist;

        Node() {
            visited = false;
            dist = -1;
            neighboors = vector<Node*>();
        }
};

vector<Node*> * get_nodes(int n) {
    vector<Node*> * G = new vector<Node*>();
    for (int i = 0; i < n; i++) {
        Node* n = new Node();
        G->push_back(n);
    }
    return G;
}

void set_neighboors(vector<Node*>* G, int m) {
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        (*G)[x - 1]->neighboors.push_back((*G)[y - 1]);
        (*G)[y - 1]->neighboors.push_back((*G)[x - 1]);
    }
}

void print_dist(vector<Node*>* G) {
    for (int i = 0; i < G->size(); i++) {
        int dist = (*G)[i]->dist;
        if (dist != 0) cout << dist << " ";
    }
    cout << endl;
}

void bfs(Node* root) {
    queue<Node*> Open;
    Open.push(root);
    set<Node*> Closed;
    root->dist = 0;
    root->visited = true;
    while (!Open.empty()) {
        Node* x = Open.front();
        Open.pop();
        if (Closed.find(x) != Closed.end()) continue;
        for (int i = 0; i < x->neighboors.size(); i++) {
            Node* y = x->neighboors[i];
            if (!y->visited) {
                y->dist = x->dist + 6;
                y->visited = true;
                Open.push(y);
            }
        }
        Closed.insert(x);
    }
}

int main()  {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m, root;
        cin >> n >> m;
        vector<Node*>* G = get_nodes(n);
        set_neighboors(G, m);
        cin >> root;
        bfs((*G)[root - 1]);
        print_dist(G);
    }
}
