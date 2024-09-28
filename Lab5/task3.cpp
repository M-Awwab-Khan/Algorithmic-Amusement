#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Awwab_Lab5{
    public:
    vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> merged;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); ++i) {
            vector<int> interval = intervals[i];
            if (interval[0] <= prev[1]) {
                prev[1] = max(prev[1], interval[1]);
            } else {
                merged.push_back(prev);
                prev = interval;
            }
        }

        merged.push_back(prev);
        return merged;
    }
};

int main() {

    Awwab_Lab5 lab;

    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> merged = lab.mergeIntervals(intervals);
    for (auto& interval: merged) {
        cout << "(" << interval[0] << ", " << interval[1] << ")" << " ";
    }

    return 0;
}