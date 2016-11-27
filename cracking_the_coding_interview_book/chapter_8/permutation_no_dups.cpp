#include <iostream>
#include <vector>

using namespace std;

vector<char> get__permutation(vector<char> permutation, char a, int k) {
    vector<char> new_permutation;
    int j = 0;
    for (int i = 0; i <= permutation.size(); i++) {
        if (k == i) {
            new_permutation.push_back(a);
        } else {
            new_permutation.push_back(permutation[j]);
            j++;
        }
    }
    return new_permutation;
}

vector<vector<char>>* get_permutations(vector<vector<char>>* current_permutations, char a) {
    vector<vector<char>>* new_permutations = new vector<vector<char>>();
    for (int i = 0; i < current_permutations->size(); i++) {
        vector<char> current_permutation = (*current_permutations)[i];
        for (int j = 0; j <= current_permutation.size(); j++) {
            vector<char> new_permutation = get__permutation(current_permutation, a, j);
            new_permutations->push_back(new_permutation);
        }
    }
    delete current_permutations;
    return new_permutations;
}

vector<vector<char>>* get_permutations(vector<char>* A) {
    vector<char> empty_set;
    vector<vector<char>>* current_permutations = new vector<vector<char>>();
    current_permutations->push_back(empty_set);
    for (int i = 0; i < A->size(); i++) {
        current_permutations = get_permutations(current_permutations, (*A)[i]);
    }
    return current_permutations;
}

void print_permutation(vector<char> permutation) {
    for(int i = 0; i < permutation.size(); i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;
}

void test(vector<char>* A) {
    vector<vector<char>>* permutations = get_permutations(A);
    for (int i = 0; i < permutations->size(); i++) {
        print_permutation((*permutations)[i]);
    }
}

int main() {
    vector<char> A;
    A.push_back('a');
    A.push_back('b');
    A.push_back('c');
    //A.push_back('d');
    test(&A);
}
