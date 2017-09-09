#include <set>
#include <vector>
#include <iostream>

using namespace std;

int count_ways(set<int> steps, int n) {
    vector<int> ways(n + 1);
    ways[0] = 1;
    for (int i = 0; i < n; i++) {
        set<int>::iterator sp = steps.begin();
        while (sp != steps.end()) {
            int s = (*sp);
            if (i <= n - s) {
                ways[i + s] += ways[i];
            }
            sp++;
        }
    }
    return ways[n];
}

void test(set<int> steps, int n) {
    cout << "Ways to arrive n = " << n << " are " << count_ways(steps, n) << endl;
}

int main() {
    set<int> steps;
    steps.insert(1);
    steps.insert(2);
    steps.insert(3);
    test(steps, 3);
}
