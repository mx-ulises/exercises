#include <iostream>
#include <vector>
#include <utility>
#include <map>

using namespace std;

vector<string>* get_parens(int open, int closed, map<pair<int, int>, vector<string>*>* visited);

void test_and_add(char prefix, int open, int closed, map<pair<int, int>, vector<string>*>* visited, vector<string>* parens) {
    vector<string>* aux = get_parens(open, closed, visited);
    for (int i = 0; i < aux->size(); i++)
        parens->push_back(prefix + (*aux)[i]);
}

vector<string>* get_parens(int open, int closed, map<pair<int, int>, vector<string>*>* visited) {
    pair<int, int> p(open, closed);
    if (visited->find(p) != visited->end())
        return (*visited)[p];
    vector<string>* parens = new vector<string>();
    if (0 < open)
        test_and_add('(', open - 1, closed, visited, parens);
    if (open < closed)
        test_and_add(')', open, closed - 1, visited, parens);
    (*visited)[p] = parens;
    return parens;
}

vector<string>* get_parens(int n) {
    map<pair<int, int>, vector<string>*>* visited = new map<pair<int, int>, vector<string>*>();
    pair<int, int> p(0, 0);
    (*visited)[p] = new vector<string>();
    (*visited)[p]->push_back("");
    vector<string>* parens = get_parens(n, n, visited);
    return parens;
}

int main() {
    int n = 3;
    vector<string>* parens = get_parens(n);
    for (int i = 0; i < parens->size(); i++) {
        cout << (*parens)[i] << endl;
    }
    cout << endl;
}
