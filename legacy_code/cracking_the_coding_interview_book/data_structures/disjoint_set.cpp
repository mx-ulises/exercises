#include <iostream>
#include <vector>
#include <map>

using namespace std;

class DisjointSet {
    private:
        vector<int> parent;
        vector<int> rank;

    public:
        DisjointSet(int n) {
            parent = vector<int>(n);
            rank = vector<int>(n);
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        void merge(int x, int y) {
            int x_root = find(x);
            int y_root = find(y);
            if (x_root != y_root) {
                if (rank[x_root] < rank[y_root]) {
                    parent[x_root] = y_root;
                } else if (rank[y_root] < rank[x_root]) {
                    parent[y_root] = x_root;
                } else {
                    parent[y_root] = x_root;
                    rank[x_root]++;
                }
            }
        }
};

int main() {
    int n = 10;
    DisjointSet dj_set = DisjointSet(n);
    map<int, int> hm;
    dj_set.merge(1, 2);
    dj_set.merge(3, 2);
    dj_set.merge(7, 1);
    dj_set.merge(5, 4);
    dj_set.merge(6, 9);
    for (int i = 0; i < n; i++) {
        int root = dj_set.find(i);
        hm[root]++;
    }
    for (map<int, int>::iterator it = hm.begin(); it != hm.end(); it++) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
