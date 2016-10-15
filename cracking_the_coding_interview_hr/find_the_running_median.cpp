#include <queue>
#include <iostream>
#include <iomanip>

using namespace std;

class MedianTracker {
    private:
        int median;
        bool single_median = false;
        priority_queue<int> maximals, minimals;

    public:
        void insert(int item) {
            if (single_median) {
                if (median < item) {
                    minimals.push(median);
                    maximals.push(-item);
                } else {
                    minimals.push(item);
                    maximals.push(-median);
                }
                single_median = false;
            } else {
                if (!minimals.empty() && item < minimals.top()) {
                    minimals.push(item);
                    median = minimals.top();
                    minimals.pop();
                } else if (!minimals.empty() && -maximals.top() < item) {
                    maximals.push(-item);
                    median = -maximals.top();
                    maximals.pop();
                } else {
                    median = item;
                }
                single_median = true;
            }
        }

        float get_median() {
            if (single_median) return median;
            return float(minimals.top() - maximals.top()) / 2.0;
        }
};


int main(){
    int n;
    cin >> n;
    MedianTracker mt;
    for(int i = 0; i < n; i++){
        int item;
        cin >> item;
        mt.insert(item);
        cout << fixed << setprecision(1) << mt.get_median() << endl;
    }
    return 0;
}
