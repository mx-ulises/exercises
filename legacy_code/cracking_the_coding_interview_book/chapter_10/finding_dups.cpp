#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

void print_dups(vector<int> buffer, int offset) {
    for (int i = 0; i < buffer.size(); i++) {
        if (buffer[i] < 2) continue;
        int num = i + 1 + offset;
        for (int j = 1; j < buffer[i]; j++) {
            cout << num << " ";
        }
        cout << endl;
    }
}

void print_duplicates(vector<int> A) {
    int buffer_size = 4000;
    vector<int> buffer(buffer_size);
    int max_n = 32000;
    int iterations = (max_n / buffer_size);
    for (int minimal = 0; minimal < max_n; minimal = minimal + buffer_size) {
        int maximal = minimal + buffer_size;
        for (int i = 0; i < A.size(); i++) {
            if (minimal < A[i] && A[i] <= maximal)
                buffer[A[i] - minimal - 1]++;
        }
        print_dups(buffer, minimal);
        buffer = vector<int>(buffer_size);
    }
}

int main() {
    vector<int> A;
    for (unsigned int i = 0; i < 40000; i++) {
        int n = rand() % 32000 + 1;
        A.push_back(n);
    }
    print_duplicates(A);
    return 0;
}
