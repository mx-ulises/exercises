#include <set>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Node {
    public:
        int value;
        int i;
        int j;

        Node(int value, int i, int j) {
            this->value = value;
            this->i = i;
            this->j = j;
        }
};

void push_valid(int i, int j, vector<vector<Node*>>* plane, vector<Node*>* N) {
    int n = (*plane).size();
    int m = (*plane)[0].size();
    if (0 <= i && i < n && 0 <= j && j < m) N->push_back((*plane)[i][j]);
}

vector<Node*>* get_neighboors(Node* x, vector<vector<Node*>>* plane) {
    int n = (*plane).size();
    int m = (*plane)[0].size();
    vector<Node*>* N = new vector<Node*>();
    int i = x->i;
    int j = x->j;
    push_valid(i - 1, j - 1, plane, N);
    push_valid(i - 1, j, plane, N);
    push_valid(i - 1, j + 1, plane, N);
    push_valid(i, j - 1, plane, N);
    push_valid(i, j + 1, plane, N);
    push_valid(i + 1, j - 1, plane, N);
    push_valid(i + 1, j, plane, N);
    push_valid(i + 1, j + 1, plane, N);
    return N;
}

int dfs(Node* root, set<Node*>* visited, vector<vector<Node*>>* plane) {
    int n = (*plane).size();
    int m = (*plane)[0].size();
    visited->insert(root);
    if (root->value == 0) return 0;
    stack<Node*> Open;
    Open.push(root);
    int count = 0;
    while (!Open.empty()) {
        Node* x = Open.top();
        Open.pop();
        vector<Node*>* N = get_neighboors(x, plane);
        for (int i = 0; i < N->size(); i++) {
            Node* y = (*N)[i];
            if (visited->find(y) == visited->end() && y->value == 1) {
                Open.push(y);
            }
            visited->insert(y);
        }
        count++;
    }
    return count;
}

int get_max(vector<vector<Node*>>* plane) {
    int n = (*plane).size();
    int m = (*plane)[0].size();
    int maximal = 0;
    set<Node*> visited;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Node* x = (*plane)[i][j];
            if (visited.find(x) != visited.end()) continue;
            maximal = max(maximal, dfs(x, &visited, plane));
        }
    }
    return maximal;
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<Node*>> plane(n, vector<Node*>(m));
    for(int i = 0; i < n; i++){
       for (int j = 0; j < m; j++){
           int value = 0;
           cin >> value;
           plane[i][j] = new Node(value, i, j);
       }
    }
    cout << get_max(&plane) << endl;
    return 0;
}
